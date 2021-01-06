#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>

using namespace std;

#define TRUE 1
#define FALSE 0
#define MAX_VERTEX 20
#define INFINITY 9999

int main()
{
    int i = 0,
        j = 0,
        k = 0,
        vertices = 0,
        pathTemp = 0,
        path[MAX_VERTEX][MAX_VERTEX],
        adjacency[MAX_VERTEX][MAX_VERTEX];

    system("CLS");

    printf("\nHow many VERTICES in the graph : ");
    scanf("%d",&vertices);

    printf("\nEnter weight of EDGEs : \n\n");
    for(i = 1; i < vertices+1 ; ++i)
    {
        for(j = 1 ; j < vertices+1 ; ++j )\
        {
            printf("  Weight of EDEGE from VERTEX %d to %d : ",i,j);
            scanf("%d",&adjacency[i][j]);
        }
        printf("\n");
    }

    /*print the matrix*/
    printf("\nThe Given weighted adjacency matrix is : \n");
    for(i = 1 ; i < vertices+1 ; ++i)
    {
        for(j = 1 ; j < vertices+1 ; ++j)
        {
            printf("%5d",adjacency[i][j]);
        }
        printf("\n");
    }

    /*now create weighted path matrix by using the Warshals algorithm*/
    for(i = 1 ; i < vertices+1 ; ++i)
    {
        for(j = 1 ; j < vertices+1 ; ++j)
        {
            path[i][j] = adjacency[i][j] ? adjacency[i][j] : INFINITY;
        }
    }

    for(k = 1 ; k < vertices+1 ; ++k)
    {
        for(i = 1 ; i < vertices+1 ; ++i)
        {
            for(j = 1 ; j < vertices+1 ; ++j)
            {
                pathTemp = (path[i][j] < (path[i][k] + path[k][j]));
                path[i][j] = pathTemp ? path[i][j] : (path[i][k]+path[k][j]);
            }
        }
    }

    /*now printing the path matrix*/
    printf("\n\nThe shortest PATH matrix is : \n");
    for(i = 1 ; i < vertices+1 ; ++i)
    {
        for(j = 1 ; j < vertices+1 ; ++j)
        {
            printf("%5d",path[i][j]);
        }
        printf("\n");
    }



    getch();
    return 0;
}
