#include <stdio.h>
int main(){
	int one,two,three;
	printf("Enter three integer numbers: ");
	scanf("%d %d %d",&one,&two,&three);
		if(one < two){
			one = two;
		}
		if (one < three){
			one = three;
		}
	printf("The maximum number is %d.",one);
	return 0;
}
