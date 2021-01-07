#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
#include<conio.h>

using namespace std;

#define TRUE 1
#define FALSE 0
#define INFINITY INT_MAX
#define MAX_VERTEX 10
#define BLACK 1
#define GRAY 2

typedef struct VERTEXINFO
{
    int predecessor;
    int distance;
    int mark;
} VERTEXINFO;

int findShortestPath(int adjacency[MAX_VERTEX][MAX_VERTEX],
                     int vertices,
                     int source,
                     int destination,
                     int shortestPath[MAX_VERTEX],
                     int *distance)
{
    VERTEXINFO pathInfo[MAX_VERTEX];
    int i = 0,
        nodes = 0,
        sourceNode = 0,
        minDistance = 0,
        tempPath[MAX_VERTEX];

    /*set initial distance to zero*/
    * distance = 0;

    /*set initially INFINITY to all vertices*/
    for(i = 1 ; i < vertices+1 ; i++)
    {
        pathInfo[i].predecessor = 0;
        pathInfo[i].distance = INFINITY;
        pathInfo[i].mark = GRAY;
    }

    /* initialize source vertex */
    pathInfo[source].predecessor = 0;
    pathInfo[source].distance = 0;
    pathInfo[source].mark = BLACK;

    /*find the path from source to destination vertex*/
    sourceNode = source;

    do  /*until destination vertex is not found*/
    {
        for(i = 1 ; i < vertices+1 ; i++)
        {
            /*check whether it id direct path or not */
            if((adjacency[sourceNode][i] > 0) && (pathInfo[i].mark == GRAY))
            {
                if((pathInfo[sourceNode].distance + adjacency[sourceNode][i]) < pathInfo[i].distance)
                {
                    pathInfo[i].predecessor = sourceNode;
                    pathInfo[i].distance = pathInfo[sourceNode].distance + adjacency[sourceNode][i];
                }
            }
        }

        minDistance = INFINITY;
        sourceNode = 0;

        /* find vertices for minimum cost */
        for(i = 1 ; i < vertices+1 ; i++)
        {
            if((pathInfo[i].mark == GRAY) && (pathInfo[i].distance < minDistance))
            {
                minDistance = pathInfo[i].distance;
                sourceNode = i;
            }
        }

        /* check whether source or destination vertices are not isolated */
        if(sourceNode == 0)
        {
            return 0;
        }
        pathInfo[sourceNode].mark = BLACK;

    }
    while(sourceNode != destination);

    /* save the shorthest path */
    sourceNode = destination;

    do
    {
        nodes += 1;
        tempPath[nodes] = sourceNode;
        sourceNode = pathInfo[sourceNode].predecessor;
    }
    while(sourceNode != 0);

    for(i = 1 ; i < nodes+1 ; i++)
    {
        shortestPath[i] = tempPath[nodes - i + 1];
    }

    for(i = 1 ; i < nodes ; i++)
    {
        *distance += adjacency[shortestPath[i]][shortestPath[i+1]];
    }

                  return nodes;
}


int main()
{

    int i = 0,
    j = 0,
    n = 0,
    to = 0,
    from = 0,
    nodes = 0,
    length = 0,
    shortestPath[MAX_VERTEX],
    adjacent[MAX_VERTEX][MAX_VERTEX];


    system("CLS");

    printf("\nHow many vertices in the graph : ");
    scanf("%d",&n);

    /* fill the matrix */
    for(i = 1 ; i < n+1 ; i++)
    {
        printf("\n");
        for(j = 1 ; j < n+1 ; j++)
        {
            printf("    Weight of EDGE from %d to %d is : ",i,j);
            scanf("%d",&adjacent[i][j]);
        }
    }

    printf("\n\nFind Shortest Path: \n");
    printf("        From : ");
    scanf("%d",&from);
    printf("        To : ");
    scanf("%d",&to);

    nodes = findShortestPath(adjacent,n,from,to,shortestPath,&length);

    /* print the shortest path */
    if(length)
    {
        printf("\nThe Shortest path is : \n");
        printf("    Go From VERTEX %d ",shortestPath[1]);
        for(i = 2 ; i < nodes+1 ; i++)
        {
            printf(" to %d ",shortestPath[i]);
        }
        printf("\n\nMinimum Distance : %d\n ",length);
    }
    else
    {
        printf("\n\nNo Path is Available\n");
    }

    getch();
    return 0;
}
