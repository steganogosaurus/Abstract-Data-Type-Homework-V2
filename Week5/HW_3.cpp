#include <iostream>
#include <cstdlib>  
using namespace std;
struct Node{
	int value;
	struct Node *Next;
};
typedef struct Node *Stack;

bool IsEmpty(Stack S);
int Top(Stack S);
void Push(int data,Stack S);
void Pop(Stack S);
Stack CreateStack();

bool IsEmpty(Stack S){
	return S->Next == NULL;
}
int Top(Stack S){
	if(!IsEmpty(S))
		return S->Next->value;
	else
		cout << "Stack Empty!";
}

int dataSummation(Stack S){
	int sum = 0;
	while(!IsEmpty(S)){
		sum += Top(S);
		Pop(S);
	}
	return sum;
}

void Push(int data,Stack S){
	Stack TmpCell;
	TmpCell = new struct Node;
	if(TmpCell == NULL){
		cout << "Out of space!!";
	}else{
		TmpCell->value = data;
		TmpCell->Next = S->Next;
		S->Next = TmpCell;
	}
}
void Pop(Stack S){
	Stack FirstCell;
	if(IsEmpty(S)){
		cout << "Empty Stack!";
	}else{
		FirstCell = S->Next;
		S->Next = S->Next->Next;
		delete FirstCell;
	}
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
int main(){
	Stack stackData = CreateStack();
    char data[30];   
    cout << "input: ";
    while(data[0]!='.'){    
		cin >> data;
		if(data[0] == '.'){
			break;
		}else{
			if(data[0]>='0'&& data[0]<='9')  {
				cout << data << "  digit" <<endl;
            	Push(atoi(data),stackData);       
        	}else{
        		cout << data << "  symbol" <<endl;
			}
		}
	}
	cout << "Output = "<< dataSummation(stackData);
}


