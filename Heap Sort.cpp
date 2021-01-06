#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<conio.h>
#include<string.h>

using namespace std;

#define MAX_ELEMENTS 50
#define TRUE 1
#define FALSE 0

void heapSort(int array[],int n);
void heapCreation(int array[],int n);

int main()
{
    int i = 0,
    totalElements = 0,
    array[MAX_ELEMENTS];

    system("cls");

    printf("\nHow many elements : ");
    scanf("%d",&totalElements);

    /*populate a dummy array on which heap sort will apply*/
    for( i = 1 ; i <= totalElements ; ++i)
    {
        printf("  Element#%2d: ",i);
        scanf("%d",&array[i]);
    }

    /*now send the array to heap sort */
    heapSort(array,totalElements);

    printf("\nAfter sorting :\n\n");
    for( i = 1 ; i<= totalElements ; ++i)
    {
        printf("%3d",array[i]);
    }

    putchar('\n');
    return 0;
}

void heapSort(int array[MAX_ELEMENTS],int nElements)
{
    int i = 0 ,
    j = 0 ,
    k = 0 ,
    tempElement = 0 ,
    sortElement = 0 ;

    /*call heapCreation() to heapify*/
    heapCreation(array,nElements);

    for( k = nElements ; k>=2 ; --k)
    {
        i = 1;
        j = 2;

        tempElement = array[1];
        array[1] = array[k];
        array[k] = tempElement;

        sortElement = array[1];

        if((j+1) < k)
        {
            if(array[j+1] > array[j])
            {
                j+=1;
            }
        }
        while((j<=(k-1)) && (array[j] > sortElement))
        {
            array[i] = array[j];
            i = j;
            j = 2*i;

            if((j+1) < k)
            {
                if(array[j+i] > array[j])
                {
                    j += 1;
                }
                else if( j > nElements)
                {
                    j = nElements;
                }
            }
            array[i] = sortElement;
        }
    }
}

void heapCreation(int array[MAX_ELEMENTS],int nElements)
{
    int i = 0,
    j = 0,
    k = 0,
    tempElement = 0;

    for(k = 2 ; k <= nElements ; ++k)
    {
        i = k;
        tempElement = array[k];
        j = (int)(i/2);

        while( (i>1) && (tempElement > array[j]))
        {
            array[i] = array[j];
            i = j ;
            j = (int)(i/2);
            if(j<1)
            {
                j = 1;
            }
        }
        array[i] = tempElement;
    }

}
