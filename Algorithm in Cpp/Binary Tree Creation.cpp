#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>

using namespace std;

#define TRUE 1
#define FALSE 0

typedef struct TREE
{
    int data;
    struct TREE* leftChild;
    struct TREE* rightChild;
} TREE;

TREE* creatLeaf(int nData,TREE* ptrTree)
{
    /*if tree is NULL, create parent node*/
    if(NULL ==  ptrTree)
    {
        ptrTree = (TREE*)malloc(sizeof(TREE));
        ptrTree->data = nData;
        ptrTree->leftChild = ptrTree->rightChild = NULL;
        return ptrTree;
    }
    /*tree is not null, then following code will work*/
    if(nData < ptrTree->data)
    {
        ptrTree->leftChild = creatLeaf(nData, ptrTree->leftChild);
    }
    else if(nData > ptrTree->data)
    {
        ptrTree->rightChild = creatLeaf(nData,ptrTree->rightChild);
    }

    return ptrTree;
}

void displayTree(int height, TREE* tree)
{
    int i = 0;
    if(NULL != tree)
    {
        /*first recursively display the right side then left side */
        displayTree(height + 1, tree->rightChild);
        printf("\n  ");

        for(i = 0 ; i < height; i++)
            printf("   ");

        printf(" %d ",tree->data);
        displayTree(height+1, tree->leftChild);
    }
}

int main()
{
    int nData = 0 ;
    TREE* tree = NULL;
    system("cls");

    while(1)
    {
        printf("\n\nEnter an element [-1 for exit] : ");
        scanf("%d",&nData);

        if(-1 == nData)
            break;

        tree = creatLeaf(nData,tree);
        printf("\n\nAfter Adding %d, The Tree becomes : \n",nData);
        displayTree(1,tree);
    }
    return 0;
}
