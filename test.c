#include<stdio.h>
int main()
{
    float marks=0.0;
    int num,turn=0;
    do{
        ++turn;
        scanf("%d",&num);
        if(num>0)
        {
            if(num%2==0)
                marks+=1.0;
            else
                marks-=0.5;
        }
    }while(num>0&&marks<5.0);
    if(turn==1)
        printf("Your Turn gets over");
    else
        printf("Your score is %0.1f",marks);
        
    return 0;
}