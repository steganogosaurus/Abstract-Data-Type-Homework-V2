#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

int main()
{
    int n;
    char pi[20] = "314159265";
    char num[20];
    scanf("%d", &n);
    for(int i = 0 ; i < n;i++){
    	char c = pi[i];
    	strcpy(num,c);
    }
    printf("%s",num);

    return 0;
}
