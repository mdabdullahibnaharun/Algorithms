#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<conio.h>
#include<string.h>

using namespace std;

/*recursive TowerOfHanoi function*/
void TowerOfHanoi(int disks,char* source_stand,char* temp_stand,char* final_stand)
{
    if(disks != 0)
    {
        /*call recursively*/
        TowerOfHanoi(disks-1,source_stand,final_stand,temp_stand);
        printf("\n Move Disk #%2d from %-12s to %s",disks,source_stand,final_stand);
        /*call recursively*/
        TowerOfHanoi(disks-1,temp_stand,source_stand,final_stand);
    }
}

int main()
{
    int disks;
    char* tower1 = "Left Tower";
    char* tower2 = "Mid Tower";
    char* tower3 = "Right Tower";

    system("cls");

    /*get the disks*/
    printf("\nHow many disks : ");
    scanf("%d",&disks);


    /*now creating the tower*/
    printf("\nTower of Hanoi [%d disks]...\n",disks);
    TowerOfHanoi(disks,tower1,tower2,tower3);

    getch();
    return 0;

}
