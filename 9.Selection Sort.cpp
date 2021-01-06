#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<conio.h>
#include<string.h>

using namespace std;

#define MAX_ELEMENTS 50
#define TRUE 1
#define FALSE 0

int main()
{
    int i=0,
        j=0,
        k=0,
        scan=0,
        minvalue=0,
        totalElements=0,
        array[MAX_ELEMENTS];

    system("cls");

    printf("\nHow many elements : ");
    scanf("%d",&totalElements);

    printf("\nEnter %d elements : \n",totalElements);
    for(i = 0 ; i<totalElements ; ++i)
    {
        printf(" Element #%d : ",i+1);
        scanf("%d",&array[i]);
    }

    /*implementation of selection sort*/

    for(scan = 0 ; scan < totalElements-1 ; scan++)
    {
        minvalue = scan;
        for(j = scan + 1 ; j < totalElements ; j++)
        {
            if(array[minvalue] > array[j])
            {
                minvalue = j;
            }
        }

        if(minvalue != scan)
        {
            k = array[scan];
            array[scan] = array[minvalue];
            array[minvalue] = k;
        }
    }

    printf("\nAfter Sorting : \n");
    for(i = 0 ; i < totalElements ; i++)
    {
        printf("%3d",array[i]);
    }

    putchar('\n');
    getch();
    return 0;

}
