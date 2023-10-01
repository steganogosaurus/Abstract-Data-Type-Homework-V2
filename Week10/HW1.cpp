#include<iostream>
#include<sstream>
using namespace std;
int length,heapsize = 0;
int A[30];
int showmenu(){
	int select;
	cout << "==========MENU=========" << endl;
	cout << "1) Insert data to array" << endl;
	cout << "2) Build Heap " << endl;
	cout << "3) Heap Sort " << endl;
	cout << "4) Heap insert " << endl;
	cout << "5) Priority Queue " << endl;
	cout << "6) Extract Max " << endl;
	cout << "Please choose > ";
	cin >> select;
	return select;
}
int parents(int i){
	return i/2;
}
int left(int i){
	return 2*i;
}
int right(int i){
	return 2*i+1;
}
void Heapify(int A[],int i){
	int largest;
	int l = left(i);
	int r = right(i);
	if(l <= heapsize && A[l] > A[i]){
		largest = l;
	}else{
		largest = i;
	}
	if(r <= heapsize && A[r] > A[largest]){
		largest = r;
	}
	if(largest != i){
		swap(A[i],A[largest]);
		Heapify(A,largest);
	}
}
void Build_Heap(int A[]){
	length = heapsize; 
	for(int i = length/2;i>=1;i--){
		Heapify(A,i);
	}
}
void Heapsort(int A[]){
	Build_Heap(A);
	int heaplength = heapsize;
	for(int i = heapsize;i>=2;i--){
		swap(A[1],A[i]);
		heapsize = heapsize-1;
		Heapify(A,1);
	}
	heapsize = heaplength;
}
void Heap_Insert(int A[],int key){
	heapsize = heapsize+1;
	int i = heapsize;
	cout << "Array: ";
	A[heapsize] = key;
	for(int i = 1;i<=heapsize;i++){
		cout << A[i] << " ";
	}
	while(i>1&&A[parents(i)]<key){
		A[i] = A[parents(i)];
		i = parents(i);
		A[i] = key;
	}
}
int Heap_Exact_Max(int A[]){
	int max;
	if(heapsize < 1){
		cout << "Heap underflow";
		return 0;
	}
	max = A[1];
	A[1] = A[heapsize];
	heapsize = heapsize-1;
	Heapify(A,1);
	return max;
}
void insertArray(){
	int value,index = 1;
	string data;
	string str = "";
	cout << "input: ";
	cin.ignore();
	getline(cin,data);
	int strSize = data.size();
	for(int i = 0 ;i < strSize;i++){
		if(data[i]==' '){
			stringstream container(str);
			container >> A[index++];
			++heapsize;
			str = "";
		}else{
			str += data[i];
		}
		if(i == strSize-1){
			stringstream container(str);
			container >> A[index++];
			heapsize++;
			str = "";
		}
	}
}
//Test case : 4 1 3 2 16 9 10 14 8 7
int main(){
	int data,i = 0;
	while(true){
		switch(showmenu()){
			case 1:
				insertArray();
				break;
			case 2:
				Build_Heap(A);
				cout << "Heap: ";
				for(int i = 1 ; i <= heapsize;i++){
					cout << A[i] << " ";
				}
				cout << endl;
				break;
			case 3:
				Heapsort(A);
				cout << "Heap Sort: ";
				for(int i = 1 ; i <= heapsize;i++){
					cout << A[i] << " ";
				}
				cout << endl;
				break;
			case 4:
				int key;
				cout << "Insert: ";
				cin >> key;
				Heap_Insert(A,key);
				cout << endl << "Heap: ";
				for(int i = 1 ; i <= heapsize;i++){
					cout << A[i] << " ";
				}
				cout << endl;
				break;
			case 5:
				cout << "Priority Queue Heap: ";
				for(int i = 1 ; i <= heapsize;i++){
					cout << A[i] << " ";
				}
				cout << endl;
				break;
			case 6:
				cout << "Max = " << Heap_Exact_Max(A)<<endl;
				cout << "Heap: ";
				for(int i = 1 ; i <= heapsize;i++){
					cout << A[i] << " ";
				}
				cout << endl;
				break;
		}
	}
	return 0;
}
