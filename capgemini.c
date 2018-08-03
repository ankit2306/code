#include<stdio.h>
#include<string.h>
#define CONT_SIZE 5
char CD[CONT_SIZE][10]={""};
int top=-1;

int main()
{
    int choice;
    do
    {
        printf("1.Insert a CD in the container\n");
        printf("2.Delete a CD from the container\n");
        printf("3.Display CD container\n");
        printf("4.Exit\n");
        printf("Enter your choice:");
        scanf("%d",&choice);
        getchar();
        switch(choice)
        {
            case 1:
            {
                if(top==CONT_SIZE-1)
                {
                    printf("Currently the container is full\n");
                }
                else
                {
                    printf("Enter the CD No to be added to the container: ");
                    fgets(CD[++top],sizeof(CD[top]),stdin);
                }
                break;
            }
            case 2:
            {
                if(top==-1)
                {
                    printf("The container is empty\n");
                }
                else
                {
                    printf("The CD deleted from the container %s",CD[top]);
                    top--;
                }
                break;
            }
            case 3:
            {
                if(top==-1)
                {
                    printf("The container is empty\n");
                }
                else
                {
                    printf("The CDs in the container:\n");
                    for(int i=top;i>=0;i--)
                    {
                        printf("%s\n",CD[i]);
                    }
                }
                break;
            }
            case 4:
            default:
            {
                return 0;
            }
        }
    } while(1);
    return 0;
}