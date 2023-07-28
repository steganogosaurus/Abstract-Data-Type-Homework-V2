#include <iostream>
using namespace std;
int main(){
	int arr[10];
	int length,value;
	cout << "Enter: ";
	for(int i = 0 ; i < 5;i++){
		cin >> arr[i];
		length++;
	}
	cout << endl << "(index)|";
	for(int i = 0 ;i < length;i++){
		cout << i << " ";
		if(i == length-1){
			cout << endl << "-------|-----------" << endl;
			cout << "(value)|";
			for(int j = 0 ;j < length;j++){
				cout << arr[j] << " ";
			}
		}
	}
	cout << endl << endl << "Enter value: ";
	cin >> value;
	for(int i = 0;i < length;i++){
		if(value < arr[i]){
			cout << endl << "Index = " << i;
			break;
		}
	}
	if(value > arr[length - 1]){
		cout << endl << "No number";
	}	
	return 0;
}
