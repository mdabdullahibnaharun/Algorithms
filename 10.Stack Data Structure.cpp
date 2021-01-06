#include<iostream>
#include<algorithm>
#include<stack>
#include<stdio.h>
#include<conio.h>
#include<string.h>

using namespace std;

#define MAX_ELEMENTS 50
#define TRUE 1
#define FALSE 0

typedef struct cstackElement
{
    int data;
    struct cstackElement* next;
} cstack;

int menu()
{
    int menuItem;

    do
    {
        printf("\n\nSelect stack Operation:\n\n");
        printf("    1)Push Element\n");
        printf("    2)Pop Element\n");
        printf("    3)Exit\n");

        printf("\nYour Choice : ");
        menuItem = getch();

        if(menuItem < '1' || menuItem > '3')
        {
            printf("\nInvalid Choice! !! !!!\n");
        }
    }
    while(menuItem < '1' || menuItem > '3');

    return menuItem;
}

/*function to display stack element*/
void displaycStack(cstack* element)
{
    if(NULL != element)
    {
        printf("\n %d ",element->data);
        displaycStack(element->next);
    }
}

/*push element in the stack*/
cstack* pushElement(cstack* firstElement)
{
    int tempData;
    cstack* tempElement;

    printf("\n\nData for new Element : ");
    scanf("%d",&tempData);

    tempElement = (cstack*)malloc(sizeof (cstack));

    tempElement->data =  tempData;
    tempElement->next = firstElement;
    firstElement = tempElement;

    return firstElement;
}

/*pop element from list*/
cstack* popElement(cstack* firstElement)
{
    int tempData;
    cstack* tempElement;

    if(NULL == firstElement)
    {
        printf("\n stack is empty\n");
    }
    else
    {
        tempData = firstElement->data;

        printf("\nPopped element : %d,",tempData);

        tempElement = firstElement->next;
        free(firstElement);

        firstElement = tempElement;
        if(NULL == firstElement)
        {
            printf("\nNow the stack is empty\n");
        }
        else
        {
            printf("\nAfter pop-ing : \n");
            displaycStack(firstElement);
        }
    }
    return firstElement;
}


int main()
{
    int menuItem;
    cstack* startElement = NULL;

    system("cls");

    do
    {
        menuItem = menu();

        switch(menuItem)
        {
        case '1':
            startElement = pushElement(startElement);
            system("cls");
            printf("\nAfter pushing %d stack becomes...\n",startElement->data);

            displaycStack(startElement);
            break;
        case '2':
            system("cls");
            startElement =  popElement(startElement);
            break;
        default:
            break;
        }
    }
    while( '3' != menuItem);
    putchar('\n');

    return 0;
}
