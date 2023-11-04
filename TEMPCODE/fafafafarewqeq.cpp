#include <iostream>
#include <sstream>
using namespace std;

void menu(){
	cout<<"==========MENU=========="<<endl;
	cout<<"1) Insert data to array"<<endl;
	cout<<"2) Build Heap"<<endl;
	cout<<"3) Heap Sort"<<endl;
	cout<<"4) Heap insert"<<endl;
	cout<<"5) Priority Queue"<<endl;
	cout<<"6) Extract Max"<<endl;
	cout<<"7) Exit"<<endl;
	cout<<"Please choose > ";
}
int A[30],length,heapsize;

void insertDataToArray(){
	int index=1,len;
	heapsize = 0;
	length = sizeof(A)/sizeof(A[0]);
	string value, temp;
	cout<<"input : ";
	cin.ignore();
	getline(cin,value);
	len = value.size();
	for(int format=0;format<len;format++){
		if(value[format] == ' '){
			stringstream container(temp);
			container >> A[index++];
			temp="";
		}else{
			temp+=value[format];
		}
		if(format == len-1){
			stringstream container(temp);
			container >> A[index++];
			temp="";
		}
	}
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

void Heapify(int A[], int i){
	int l=left(i);
	int r=right(i);
	int largest = i;
	if(l <= heapsize && A[l] > A[i]){
		largest = l;
	}
	if(r <= heapsize && A[r] > A[largest]){
		largest = r;
	}
	if(largest != i){
		swap(A[i],A[largest]);
		Heapify(A,largest);
	}
}

void buildHeap(int A[]){
	for(int i=length/2;i>0;i--){
		Heapify(A,i);
	}
}

void Heapsort(int A[]){
	buildHeap(A);
	int tempheapsize=heapsize;
	for(int i=heapsize;i>1;i--){
		swap(A[1],A[i]);
		heapsize-=1;
		Heapify(A,1);
	}
	heapsize=tempheapsize;
}

void HeapInsert(int A[]){
	buildHeap(A);
	if(heapsize+1 >= length){
		cout<<"Index out of range!!"<<endl;
	}else{
		++heapsize;
		int key,i=heapsize;
		cout<<"Insert : ";
		cin>>key;
		A[heapsize] = key;
		cout<<"Array :";
		for(int index=1;index<=heapsize;index++){
			cout<<" "<<A[index];
		}
		while(i>1&&A[parents(i)]<key){
			A[i] = A[parents(i)];
			i = parents(i);
			A[i] = key;
		}	
	}
}

void ExtractMax(int A[]){
	int max;
	if(heapsize<1){
		cout<<"Heap underflow"<<endl;
	}else{
		max=A[1];
		A[1] = A[heapsize];
		heapsize-=1;
		Heapify(A,1);
		cout<<"Max = "<<max<<endl;
	}
}
int main(){
	int choose;
	while(true){
		menu();
		cin>>choose;
		switch(choose){
			case 1:
				insertDataToArray(); //4 1 3 2 16 9 10 14 8 7
				cout<<endl;
				break;
			case 2:
				buildHeap(A);
				cout<<"Heap :";
				for(int index=1;index<=heapsize;index++){
					cout<<" "<<A[index];
				}
				cout<<endl<<endl;
				break;
			case 3:
				Heapsort(A);
				cout<<"Heap Sort :";
				for(int index=1;index<=heapsize;index++){
					cout<<" "<<A[index];
				}
				cout<<endl<<endl;
				break;
			case 4:
				HeapInsert(A);
				cout<<endl<<endl;
				break;
			case 5:
				cout<<"Heap :";
				for(int index=1;index<=heapsize;index++){
					cout<<" "<<A[index];
				}
				cout<<endl<<endl;
				break;
			case 6:
				ExtractMax(A);
				cout<<"Heap :";
				for(int index=1;index<=heapsize;index++){
					cout<<" "<<A[index];
				}
				cout<<endl<<endl;
				break;
			case 7:
				exit(0);
				break;
			default:
				cout<<"Not Choice!!"<<endl<<endl;
				break;
		}
	}
	return 0;
}
