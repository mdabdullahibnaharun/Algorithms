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
        low=0,
        mid=0,
        high=0,
        found=TRUE,
        keyElement=0,
        totalElements=0,
        array[MAX_ELEMENTS];

    system("cls");
    printf("\nHow many elements: ");
    scanf("%d",&totalElements);

    /*populate a dummy array on which Binary search will apply*/
    for(i = 0 ; i < totalElements ; i++)
    {
        printf(" Element #%2d: ",i+1);
        scanf("%d",&array[i]);
    }

    printf("\nElement to be searched: ");
    scanf("%d",&keyElement);

    /*use binary search*/
    low = 0;
    high = totalElements - 1;
    found = FALSE;

    while(low <= high)
    {
        mid = (low+high)/2;
        if(keyElement < array[mid]) /* search in lower half*/
        {
            high = mid - 1;
        }
        else
        {
            if(keyElement > array[mid]) /*search in upper half */
            {
                low = mid + 1;
            }
            else
            {
                if(keyElement == array[mid])
                {
                    printf("\n %d is found at %d.\n",keyElement,mid+1);
                    found = TRUE;
                    break;
                }
            }
        }
    }

    if(FALSE == found)
    {
        printf("\n %d is not in the list.\n",keyElement);
    }

    getch();
    return 0;

}
