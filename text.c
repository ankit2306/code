#include<stdio.h>

int findStringLength(char* a);
char* findStringReverse(char* a);
char* concatenateStrings(char* a, char* b);
int compareStrings(char* a, char* b);

int main()
{
    
}

int findStringLength(char* a)
{
    int size=0;
    while(a[size]!='\0' && a[size]!='\n')
    {
        size++;
    }
    return size;
}

char* findStringReverse(char* a)
{
    int i=0,j=findStringLength(a)-1;
    while(i<j)
    {
        char c=a[i];
        a[i]=a[j];
        a[j]=c;
    }
    return a;
}

char* concatenateStrings(char* a, char* b)
{
    int i=findStringLength(a),j=0;
    while(b[j]!='\0' || b[j]!='\n')
    {
        a[i]=b[j];
        i++;
        j++;
    }
    a[i]='\0';
    return a;
}

int compareStrings(char* a, char* b)
{
    int i=0;
    while(a[i]!='\0' && b[i]!='\0')
    {
        
    }
}