#include<stdio.h>
#include<stdlib.h>
int sub_string(char *source, int from, int n, char *target);

int main()
{
    char source[100];
    int from,n;
    printf("Enter any string: ");
    fgets(source,100,stdin);
    
    int len=0;      //calculate length of source string
    for(int i=0;source[i]!='\n';i++)
        len++;
        
    printf("Enter from index(count from 0): ");
    scanf("%d",&from);
    
    printf("Enter number of characters: ");
    scanf("%d",&n);
    
    if(from<0||from>len)
    {
        printf("Starting index is invalid.");
        return 0;
    }
    if(n<=0||n+from-1>len)
    {
        printf("Invalid Number of characters");
        return 0;
    }
    
    char* target = (char*) malloc((n+1)*sizeof(char));
    sub_string(source,from,n,target);
    printf("Substring is: %s",target);
    return 0;
}

int sub_string(char *source, int from, int n, char *target)
{
    int i;
    for(i=0;i<n;i++)
    {
        target[i]=source[from+i];
    }
    target[i]='\0';
    return 0;
}
