#include <iostream>
using namespace std;
struct Node{
	int value;
	struct Node *Next;
};
typedef struct Node *Stack;

Stack CreateStack(){
	Stack S;
	S = new struct Node;
	S->Next = NULL;
	if(S == NULL){
		cout << "Out of Space!";
	}
	return S;
}
bool IsEmpty(Stack S){
	return S->Next == NULL;
}
void Push(int X,Stack S){
	Stack TmpCell;
	TmpCell = new struct Node;
	if(TmpCell == NULL){
		cout << "Out of space!!";
	}else{
		TmpCell->value = X;
		TmpCell->Next = S->Next;
		S->Next = TmpCell;
	}
	cout << "Success!" <<endl;
}
void Pop(Stack S){
	Stack FirstCell;
	if(IsEmpty(S)){
		cout << "Stack Empty!!";
	}else{
		FirstCell = S->Next;
		S->Next = S->Next->Next;
		delete FirstCell;
		cout << "Success!" <<endl;
	}
	
}
int Top(Stack S){
	if(!IsEmpty(S)){
		return S->Next->value;
	}else{
		cout << "Stack Empty!" << endl;
	}
}
int showmenu(){
	int select;
	cout << "=======MENU=======" << endl;
	cout << "1)Push" << endl;
	cout << "2)Pop" << endl;
	cout << "3)Top" << endl;
	cout << "4)Exit" << endl;
	cout << "Please choose > " ;
	cin >> select;
	return select;
} 
int main(){
	int data;
	Stack S = CreateStack();
	while(true){
		switch(showmenu()){
			case 1:
				cout << "Push: ";
				cin >> data;
				Push(data,S);
				break;
			case 2:
				if(IsEmpty(S)){
					Top(S);
				}else{
				cout << "Pop: " << Top(S) << endl;
				Pop(S);	
				}
				break;
			case 3:
				cout << "Top: " << Top(S) << endl;
				break;
			case 4:
				cout << "Bye!";
				return 0;
				break;
			default:
				break;
		}
	}
	return 0;
}
