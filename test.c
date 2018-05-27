#include<stdio.h>
int main(){
    int n,i=0;
     first:
    printf("Enter no of projects :");
    scanf("%d",&n);
    if(n<=10){
    int marks[n];
    float sum=0.0f;
    printf("\nEnter the marks:");
    for(i=0;i<n;i++){
    scanf("%d",&marks[i]);
    sum=sum+marks[i];
    }
    float result=sum/n;
    if(result>=80.00)
    {printf("\nThe average score is %.2f",result);
     printf("\nYou are eligible for project.");
    }
    else {
    printf("\nThe average score is %.2f\nTry again.",result);
    goto first;
    }
    }else{
        printf("\nNo of projects exceed the limit.");
    }
    
    return 0;
}