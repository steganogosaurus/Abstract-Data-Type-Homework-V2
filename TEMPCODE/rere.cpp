#include <stdio.h>
#include <string.h>
void Ex_1(){
	char t[30];
	printf("Input the String : ");
	scanf("%s",t);
	int length = strlen(t);
	for(int i = 0 ; i < length;i++){
		printf("%c ",t[i]);
	}
}
void Ex_2(){
	int vowel=0;
	int cons=0;
	int nullchar=0;
	char t[30];
	printf("Input the String : ");
	fgets(t,30,stdin);
	int length = strlen(t);
	for(int i = 0 ; i < length-1;i++){
		if(t[i] == ' '){
			continue;
		}
		if(t[i] == 'a' || t[i] == 'A' || t[i] == 'e' || t[i] == 'E' || t[i] == 'i' || t[i] == 'I' || t[i] == 'o' || t[i] == 'O' || t[i] == 'u' || t[i] == 'U'){
			vowel+= 1;
		}else{
			cons+= 1;
		}
	}
	printf("The total number of vowel in the string is : %d \n",vowel);
	printf("The total number of consonant in the string is : %d",cons);
}
void Ex_3(){
	char t[30];
	int start,len;
	printf("Input the String : ");
	fgets(t,30,stdin);
	printf("Input the position to start extraction : ");
	scanf("%d",&start);
	printf("Input the length of substring : ");
	scanf("%d",&len);
	for(int i = start-1;i<start+len;i++){
		printf("%c",t[i]);
	}
}
void Ex_4(){
	
}
int main(){
	return 0;
}
