#include<stdio.h>

int main() {
    int a,b,c,i,j;
    printf("enter the number");
    scanf("%d",&a);
    for ( i = 2; i < a; i++)
    {
        for ( j = 2; j < i; j++)
        {
            if (i%j==0)
            {
                printf("%d,",i);
            }
            
        }
        
    }
    
    return 0;
}