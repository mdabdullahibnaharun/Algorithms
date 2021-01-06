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


int main()
{
    int i = 0,
        j = 0,
        k = 0,
        vertices = 0,
        path[MAX_VERTEX][MAX_VERTEX],
        adjacency[MAX_VERTEX][MAX_VERTEX];

    system("CLS");

    printf("\nHow many VERTICES in the graph : ");
    scanf("%d",&vertices);

    printf("\nEnter EDGE information : \n\n");
    for(i = 1 ; i < vertices+1 ; ++i)
    {
        for(j = 1 ; j < vertices+1 ; ++j)
        {
            printf("    Edge from Vertex %d to %d : ",i,j);
            scanf("%d",&adjacency[i][j]);
        }
        printf("\n");
    }


    /*print the matrix*/
    printf("\n\nThe Given Adjacency Matrix is :\n");
    for(i = 1 ; i < vertices+1 ; ++i)
    {
        for(j = 1 ; j < vertices+1 ; ++j)
        {
            printf("%5d",adjacency[i][j]);
        }
        printf("\n");
    }

    /*now creating path matrix by using the Warshals algorithms*/
    for(i = 1 ; i < vertices+1 ; ++i)
    {
        for(j = 1 ; j < vertices+1 ; ++j)
        {
            path[i][j] = adjacency[i][j] ? 1 : 0;
        }
    }

    for(k = 1 ; k < vertices+1 ; ++k)
    {
        for(i = 1 ; i < vertices+1 ; ++i)
        {
            for(j = 1 ; j < vertices+1 ; ++j)
            {
                path[i][j] = (path[i][j] | (path[i][k] & path[k][j]));
            }
        }
    }

    /*now printing the path matrix*/
    printf("\n\nThe PATH matrix is :\n\n");
    for(i = 1 ; i < vertices+1; ++i)
    {
        for(j = 1 ; j < vertices+1 ; ++j)
        {
            printf("%5d",path[i][j]);
        }
        printf("\n");
    }

    putchar('\n');
    getch();
    return 0;
}
