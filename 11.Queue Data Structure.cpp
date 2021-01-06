#include<iostream>
#include<algorithm>
#include<queue>
#include<stdio.h>
#include<conio.h>
#include<string.h>

using namespace std;

#define MAX_ELEMENTS 50
#define TRUE 1
#define FALSE 0

typedef struct queueElement
{
    int data;
    struct queueElement* next;
} cqueue;


void addElement(int data,cqueue** frontElement,cqueue** rearElement)
{
    cqueue* tempElement;
    tempElement = (cqueue*)malloc(sizeof(cqueue));
    tempElement->data = data;
    tempElement->next = NULL;

    if(NULL  == (*frontElement))
    {
        (*frontElement) = tempElement;
        (*rearElement) = tempElement;
    }
    else
    {
        (*rearElement)->next = tempElement;
        *rearElement = tempElement;
    }
}

int deleteElement(cqueue** frontElement)
{
    cqueue* tempElement;
    int data;

    if(NULL != (*frontElement))
    {
        data = (*frontElement)->data;
        tempElement = (*frontElement);
        (*frontElement) = (*frontElement)->next;
        free(tempElement);
    }
    return data;
}

void displaycQueue(cqueue* frontElement)
{
    printf("\n\nFront");
    while(NULL != frontElement)
    {
        printf(" %d ",(*frontElement).data);
        frontElement = (*frontElement).next;
    }
    printf("REAR\n\n");
}

int main()
{
    char menuItem;

    int data = 0,
        flag = TRUE;

    cqueue *frontElement = NULL,
            *rearElement = NULL;

    system("cls");

    do
    {
        printf("\nQueue Example");
        printf("\n  1)Insert");
        printf("\n  2)Delete");
        printf("\n  3)Exit");
        printf("\nEnter your Choice(I, D or X) : ");

        menuItem = getch();

        switch(menuItem)
        {
        case 'i':
        case 'I':
            printf("\n\nEnter new Element : ");
            scanf("%d",&data);

            addElement(data,&frontElement,&rearElement);

            printf("\nAfter Adding %d,",data);
            break;

        case 'd':
        case 'D':
            if(NULL != frontElement)
            {
                data = deleteElement(&frontElement);
                printf("\n\nAfter deleting %d,",data);
            }
            break;
        case 'x':
        case 'X':
            flag = FALSE;
            break;
        default:
            break;
        }

        if(NULL == frontElement)
        {
            printf("\n\nThe Queue is empty");
        }
        else
        {
            printf("The Queue Becomes....");
            displaycQueue(frontElement);
        }
    }
    while(TRUE == flag);


    while(NULL != frontElement)
    {
        rearElement = frontElement->next;
        free(frontElement);
        frontElement = rearElement;
    }

    putchar('\n');
    getch();
    return 0;

}

