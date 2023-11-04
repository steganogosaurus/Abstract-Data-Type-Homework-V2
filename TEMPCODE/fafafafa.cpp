#include <iostream>
using namespace std;
int rev(int x){
	if(x == 0){
		return 0;
	}else{
		x--;
		return rev(x+1);
	}
}
int main(){
	cout << rev(5);
	return 0;
}
