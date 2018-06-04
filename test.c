#include<stdio.h>

int main()
{
    int a[3],b[3],as=0,bs=0;
    printf("Enter Jack's Score: ");
    for(int i=0;i<3;i++)
    {
        scanf("%d",&a[i]);
        if(a[i]<=0)
        {
            printf("Invalid Score");
            return 0;
        }
    }
    printf("Enter Jill's Score: ");
    for(int i=0;i<3;i++)
    {
        scanf("%d",&b[i]);
        if(b[i]<=0)
        {
            printf("Invalid Score");
            return 0;
        }
    }
    
    for(int i=0;i<3;i++)
    {
        if(a[i]>b[i])  
            as++;
        else if(a[i]<b[i])
            bs++;
        else
            continue;
    }
    
    if(a==0&&b==0)
        printf("No Comparison points for Jack and Jil");
    else
        printf("Comparison points for Jack and Jill is %d %d respectively",as,bs);
    return 0;
}