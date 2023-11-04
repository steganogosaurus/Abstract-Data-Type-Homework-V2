#include <iostream>
#include <cmath>
using namespace std;
int main(){
	int inputNumber,flag = 0;
	cout << "input: ";
	cin >> inputNumber; 
	if(inputNumber < 2){
		cout << "Not prime" ;
	}else{
	for(int i = 2;i <= sqrt(inputNumber);i++){
		if(inputNumber % i == 0){
			cout << "Not prime" ;
			flag = 1;
		}
	}
	if(flag == 0){
		cout << "Prime" ;
	}	
	}
	
	return 0;
}
