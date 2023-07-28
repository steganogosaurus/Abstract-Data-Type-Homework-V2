#include <iostream>
using namespace std;
int fibonacci(int term){
   int x1 = 0,x2 = 1,sum;
   	for(int i = 2; i<= term;i++){
   		sum = x1 + x2;
   		x1 = x2;
   		x2 = sum;
	   }
   return sum; 
}
int main(){
	int term;
	cout << "Enter: ";
	cin >> term;
	if(term > 15){
   	cout << "Error,more than 15";
   }else{
   	cout << "Fibonacci of " << term << " = " << fibonacci(term);
   }
	return 0;
}
