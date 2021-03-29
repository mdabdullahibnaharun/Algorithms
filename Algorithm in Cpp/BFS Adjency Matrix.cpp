#include <iostream>
#include <algorithm>
#include <string>
#include <stdbool.h>
#include <cstdio>
#include <iterator>
#include <vector>
#include <map>
#include <set>

using namespace std;

//https://pastebin.com/as9stxFM

///BFS
void init(int ar[10][10])
{
    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j<10; j++)
        {
            ar[i][j] = 0;
        }
    }
}

void takeinp(int ar[10][10], int ver)
{
    for(int i = 0; i < ver; i++)
    {
        for(int j = 0; j<ver; j++)
        {
            scanf("%d", &ar[i][j]);
        }
    }
}

void outp(int ar[10][10], int ver)
{
    for(int i = 0; i < ver; i++)
    {
        for(int j = 0; j<ver; j++)
        {
            printf("%d\t", ar[i][j]);
        }
        printf("\n");
    }
}

void BFS(int ar[][10], int startpoint, int vertex)
{
    int visit[vertex] = {0}, nextvisit[100];
    int front = 0, rear = 0;
    nextvisit[front++] = startpoint - 1;

    while(front > rear)
    {
        int curvertex = nextvisit[rear];
        visit[curvertex] = 1;
        for(int i = 0; i < vertex; i++)
        {
            if(ar[curvertex][i] == 1 && visit[i] == 0)
            {
                nextvisit[front++]  = i ;
            }
        }
        if(vertex > rear)
            printf("%d\t", nextvisit[rear] +1);
        rear++;
    }


}


int main() {

    int admat[10][10];
    init(admat);

    int vertex;
    scanf("%d", &vertex);

    takeinp(admat, vertex);

    int startpoint;
    scanf("%d", &startpoint);

    BFS(admat, startpoint, vertex);

    outp(admat, vertex);
	return 0;
}
