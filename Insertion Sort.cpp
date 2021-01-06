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
    int i = 0,
    j = 0 ,
    k = 0,
    element = 0,
    array[MAX_ELEMENTS],
    totalElements = MAX_ELEMENTS;

    system("cls");

    printf("\nEnter an element[-1 for exit] : ");
    scanf("%d",&element);

    /*following code implements insertion sort*/
    while((element!=-1))
    {
        k = i - 1;
        while((element < array[k]) && (k >= 0))
        {
            array[k+1] = array[k];
            --k;
        }

        array[k+1] =  element;

        printf("After inserting %d, array becomes:\n\n",element);

        for(j = 0 ; j <= i ;j++)
        {
            printf("%3d",array[j]);
        }

        printf("\n\nEnter another element[-1 for exit]: ");
        scanf("%d",&element);
        ++i;
    }

    printf("\n The final sorted array is :\n");
    for(j = 0 ; j<i ; j++)
    {
        printf("%4d",array[j]);
    }

    putchar('\n');

    getch();
    return 0;

}
