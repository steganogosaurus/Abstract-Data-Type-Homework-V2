#include <stdio.h>
#include <string.h>
int main(){
	char str[10];
	printf("Enter your password: ");
	scanf("%s",str);
	if(strcmp(str,"Bourne007") == 0){
		printf("\nAccess Granted!\n");
		printf("Welcom to MI6.");
	}else{
		printf("\nAccess Denied!\n");
		printf("Program terminated.");
	}
	return 0;
}
