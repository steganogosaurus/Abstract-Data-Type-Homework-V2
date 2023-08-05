//Name : Wiritipon Thapkhan
//ID : 6530300503

#include <iostream>
using namespace std;
struct Node{
	char value;
	struct Node *Next;
};
typedef struct Node *Stack;

void ParenthesisCheck(Stack S);
void Push(char symbol,Stack S);
void Pop(Stack S);
char Top(Stack S);
bool IsEmpty(Stack S);
Stack CreateStack();

int main(){
	Stack S = CreateStack();
	char parenthesis;
	cout << "Input: ";
	do{
		cin >> parenthesis;
		if(parenthesis == '.')
			break;
		else
			Push(parenthesis,S);
	}while(true);
	ParenthesisCheck(S);
	return 0;
}
void ParenthesisCheck(Stack S){
	Stack symbolStack = CreateStack();
	int check = 0;
	while(!IsEmpty(S)){
		char parenthesis = Top(S);
		switch(parenthesis){
			case '{':
			case '[':
			case '(':
			case '<':
				check++;
				Push(parenthesis,symbolStack);
				break;
		}
		Pop(S);
	}
	while(!IsEmpty(symbolStack)){
		cout << Top(symbolStack) << endl;
		Pop(symbolStack);
	}
	cout << "Open = " << check;
}
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
void Push(char symbol,Stack S){
	Stack TmpCell;
	TmpCell = new struct Node;
	if(TmpCell == NULL){
		cout << "Out of space!!";
	}else{
		TmpCell->value = symbol;
		TmpCell->Next = S->Next;
		S->Next = TmpCell;
	}
}
void Pop(Stack S){
	Stack FirstCell;
	if(IsEmpty(S)){
		cout << "Stack Empty!!";
	}else{
		FirstCell = S->Next;
		S->Next = S->Next->Next;
		delete FirstCell;
	}
	
}
char Top(Stack S){
	if(!IsEmpty(S)){
		return S->Next->value;
	}else{
		cout << "Stack Empty!" << endl;
	}
}
