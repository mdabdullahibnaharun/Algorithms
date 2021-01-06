#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<conio.h>
#include<string.h>

using namespace std;

#define MAX_ELEMENTS 50
#define TRUE 1
#define FALSE 0

void mergeSort(int array[],int minElement,int maxElement);
void sortUtil(int array[],int size,int topElement,int botElement);

int main()
{
    int i = 0,
        totalelements = 0,
        array[MAX_ELEMENTS];

    system("cls");

    printf("\nHow many elements : " );
    scanf("%d",&totalelements);

    printf("\nEnter %d elements : \n",totalelements);
    for(i = 0 ; i < totalelements ; ++i)
    {
        printf("  Element #%d : ",i+1);
        scanf("%d",&array[i]);
    }

    i = 0;
    /*call mergeSort() to sort array*/
    mergeSort(array,i,totalelements - 1);

    printf("\nAfter Sorting : \n");
    for(i = 0 ; i < totalelements ; ++i)
    {
        printf("%3d",array[i]);
    }

    putchar('\n');
    getch();
    return 0;

}

/**
Function : mergeSort()
This function will be called recursively to sort the given array.

Note:
Since the function is calling recursively , First half sorted first, then it works for the second half
**/

void mergeSort(int array[MAX_ELEMENTS],int minElement,int maxElement)
{
    int half;
    if(minElement != maxElement)
    {
        half = (minElement+maxElement)/2;

        /*call mergeSort() recursively for the first half*/
        mergeSort(array,minElement,half);

        /*call mergeSort() recursively for the second half*/
        mergeSort(array,half+1,maxElement);

        sortUtil(array,half,minElement,maxElement);
    }
}

/**
Function : sortUtil()
This function will be called by mergeSort() to sort the given array
**/

void sortUtil(int array[MAX_ELEMENTS],int size,int topElement,int botElement)
{
    int i =0,
        tempSize = size+1,
        lowerBound = topElement,
        upperBound = topElement,
        tempArray[MAX_ELEMENTS];


    while((lowerBound <= size) && (tempSize <= botElement))
    {
        if(array[lowerBound] <= array[tempSize])
        {
            tempArray[upperBound] = array[lowerBound];
            lowerBound += 1 ;
        }
        else
        {
            tempArray[upperBound] = array[tempSize];
            tempSize += 1 ;
        }
        upperBound += 1;
    }

    if(lowerBound <= size)
    {
        for( ; lowerBound <= size ; lowerBound++)
        {
            tempArray[upperBound] = array[lowerBound];
            upperBound += 1;
        }
    }
    else
    {
        for( ; tempSize <= botElement ; tempSize++)
        {
            tempArray[upperBound] = array[tempSize];
            upperBound += 1;
        }
    }

    for( i = topElement ; i<= botElement ; i++)
    {
        array[i] = tempArray[i];
    }

    return;

}
