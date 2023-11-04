#include<stdio.h>
struct name{
	char name[20];
	int age;

};

int main(){
	struct name s[3];
	for(int i = 0; i < 3;i++){
		scanf("%s",s[i].name);
		scanf("%D",&s[i].age);
	}
	for(int i = 0; i < 3;i++){
		if(s[i].age > 18){
			printf("%s is 18",s[i].name);
		}else{
			printf("%s no 18",s[i].name);
		}
	}
}
