#include<stdio.h>
#include<stdlib.h>

int tower_of_Hanoi(int num, char src, char aux, char dest);

int main()
{
    int disk_num; //number of disk

    system("cls"); //use "clear" if "cls" isn't detected

    printf("Enter the number of disks: ");
    scanf("%d", &disk_num);

    //initializing tower names:
    printf("Name of the tower - \nA(Source tower) \nB(Auxiliary tower) \nC(Destination tower) \n\n");

    printf("In order to move the %d Disks from 'A' to 'C', follow the given steps:\n\n", disk_num);

    tower_of_Hanoi(disk_num , 'A', 'B', 'C');

    return 0;
}

int tower_of_Hanoi(int num, char src, char aux, char dest)
{

    if(num==0)
    {
        return 0;
    }
    
    tower_of_Hanoi(num-1, src, aux, dest);
    printf("Move Disk-%d from Tower-%c to Tower-%c\n", num, src, dest);
    tower_of_Hanoi(num-1,aux,src,dest);

}