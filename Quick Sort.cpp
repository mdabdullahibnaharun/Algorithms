#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<conio.h>
#include<string.h>

using namespace std;

#define MAX_ELEMENTS 50
#define TRUE 1
#define FALSE 0

void quickSort(int array[],int leftElements,int rightElements);

int main()
{
    int i = 0,
    left = 0,
    right = 0,
    totalElements = 0,
    array[MAX_ELEMENTS];

    system("cls");

    printf("\nHow many elements : ");
    scanf("%d",&totalElements);

    printf("\nEnter %d elements : \n",totalElements);
    for(i = 0 ; i < totalElements ; ++i)
    {
        printf(" Element #%d : ",i+1);
        scanf("%d",&array[i]);
    }

    /*call quickSort() to sort array*/
    left = 0;
    right = totalElements-1;
    quickSort(array,left,right);

    printf("\nAfter Sorting : \n");
    for(i=0 ; i<totalElements ; i++)
    {
        printf("%3d",array[i]);
    }


    putchar('\n');
    getch();
    return 0;

}

void quickSort(int array[MAX_ELEMENTS],int leftElements,int rightElements)
{
    int i = 0,
    j = 0,
    flag = FALSE,
    partition = 0,
    tempElement = 0;

    if(rightElements >  leftElements)
    {
        i = leftElements;
        j = rightElements;
        partition = array[leftElements];
        flag = FALSE;

        while(!flag)
        {
            do{
                ++i;
            }while((array[i] <= partition) && (i<=rightElements));

            while( (array[j] >= partition) && (j>leftElements))
            {
                --j;
            }
            if(j<i)
            {
                flag = TRUE;
            }
            else
            {
                tempElement = array[i];
                array[i] = array[j];
                array[j] = tempElement;
            }
        }
        tempElement = array[leftElements];
        array[leftElements] = array[j];
        array[j] = tempElement;

        /*call recursively*/
        quickSort(array,leftElements,j-1);
        quickSort(array,i,rightElements);
    }

    return;
}
