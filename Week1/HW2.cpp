#include <iostream>
using namespace std;
int arr[10];
int move = 0,length = 0;                                                                                                                                                                                                                                                                                                                                                                                                                                     
void showMenu(){
	cout << "========MENU======"<< endl << endl;
	cout << "   1) Insert the first value"<< endl;
	cout << "   2) Insert front"<< endl;
	cout << "   3) Insert last"<< endl;
	cout << "   4) Insert middle"<< endl;
	cout << "   5) Exit"<< endl << endl;
	cout << "Please choose > ";	
}
void moveIndex(int index){
	move = 0;
	for(int i = length-1;i >= index ;i--){
		if(i == 9){
			arr[i-1] = arr[i];
			move++;	
			i--;
		}
		move++;
		arr[i+1] = arr[i];	
	}
}

void printArray(int index){
	for(int i = index;i < length;i++){
		cout << arr[i] << " ";
	}
	cout << endl;
}
void insertFirst(){
	length++;
	cout << endl << "Enter data: ";
	cin >> arr[0];
	cout << endl << "Data in list = ";
	printArray(0);
	cout << endl;
}
void insertFront(){
	length++;
	cout << endl << "Enter data: ";
	moveIndex(0);
	cin >> arr[0];
	cout << endl << "Move = " << (move - 1) << " Position" << endl;
	cout << endl << "Data move = ";
	printArray(1);
	cout << endl << "Data in list = "; 
	printArray(0);
	cout << endl;
}
void insertLast(){
	length++;
	cout << endl << "Enter data: ";
	cin >> arr[length-1];
	cout << endl << "Data in list = "; 
	printArray(0);
	cout << endl;
}
void insertMiddle(){
	length++;
	cout << endl << "Enter data: ";
	moveIndex((length/2));
	cin >> arr[(length/2)];
	cout << endl << "Move = " << (move - 1) << " Position" << endl;
	cout << endl << "Data move = ";
	printArray((length/2) + 1);
	cout << endl << "Data in list = "; 
	printArray(0);
	cout << endl;
}
int main(){
	int select,exit;
	while(true){
		showMenu();
		cin >> select;
		switch(select){
			case 1:
				insertFirst(); 
				break;
			case 2:
				insertFront();
				break;
			case 3:
				insertLast();
				break;
			case 4:
				insertMiddle();
				break;
			case 5:
				cout << endl << "Output = Bye";
				return 0;
				break;
			default:
				cout <<"Please Choose 1-5 in Menu!";
				break;
		}
	}
	return 0;
}
