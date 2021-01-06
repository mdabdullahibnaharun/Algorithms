#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>

using namespace std;

#define TRUE 1
#define FALSE 0
#define MAX_NODE 50

typedef struct TREE
{
    int data;
    struct TREE* leftChild;
    struct TREE* rightChild;
} TREE;

TREE* createTree(int* ptrData,int mini,int maximum)
{
    int midElement;
    TREE* shadowTree;

    midElement = (int)(mini + maximum)/2;

    shadowTree = (TREE*)malloc(sizeof(TREE));
    shadowTree->data = ptrData[midElement];

    if(mini >= maximum)
    {
        shadowTree->leftChild = NULL;
        shadowTree->rightChild = NULL;
        return shadowTree;
    }

    if(mini <= midElement - 1)
    {
        shadowTree->leftChild = createTree(ptrData,mini,midElement-1);
    }
    else
    {
        shadowTree->leftChild = NULL;
    }

    if(midElement + 1 <= maximum)
    {
        shadowTree->rightChild = createTree(ptrData,midElement+1,maximum);
    }
    else
    {
        shadowTree->rightChild =NULL;
    }
    return shadowTree;
}

void preOrderTraversal(TREE* ptrTree)
{
    if(NULL != ptrTree)
    {
        printf("%d ",ptrTree->data);
        preOrderTraversal(ptrTree->leftChild);
        preOrderTraversal(ptrTree->rightChild);
    }
}

void inOrderTraversal(TREE* ptrTree)
{
    if(NULL != ptrTree)
    {
        inOrderTraversal(ptrTree->leftChild);
        printf("%d ",ptrTree->data);
        inOrderTraversal(ptrTree->rightChild);
    }
}

void postOrderTraversal(TREE* ptrTree)
{
    if(NULL != ptrTree)
    {
        postOrderTraversal(ptrTree->leftChild);
        postOrderTraversal(ptrTree->rightChild);
        printf("%d ",ptrTree->data);
    }
}

void displayTree(TREE* ptrTree,int height)
{
    int i;
    if(NULL != ptrTree)
    {
        displayTree(ptrTree->rightChild,height+1);
        printf("\n ");

        for(i = 0 ; i < height ; i++)
            printf("    ");

        printf("%d ",ptrTree->data);
        displayTree(ptrTree->leftChild,height+1);
    }
}


int main()

{
    TREE* tree;

    int i = 0,
        n = 0,
        array[28];

    system("CLS");

    printf("\nTotal Elements [max 25]? : ");
    scanf("%d",&n);

    printf("\nEnter %d Elements in Ascending order...\n",n);
    for(i = 0 ; i  < n ; i++)
    {
        printf("\n Element# [%2d] : ",i,i+1);
        scanf("%d",&array[i]);
    }

    tree = createTree(array,0,n-1);

    system("CLS");

    printf("\nThe TREE is :");
    displayTree(tree,1);

    printf("\n\nOutput of : " );
    printf("\n In Order Traversal: \n");
    inOrderTraversal(tree);

    printf("\n\nOutput of : " );
    printf("\n Pre Order Traversal: \n");
    preOrderTraversal(tree);

    printf("\n\nOutput of : " );
    printf("\n Post Order Traversal: \n");
    postOrderTraversal(tree);

    putchar('\n');
    getch();
    return 0;
}
