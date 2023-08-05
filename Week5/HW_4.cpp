#include <iostream>
#include <string>
using namespace std;
struct Node{
	char value;
	struct Node *Next;
};
typedef struct Node *Stack;
string str = "";
bool check = false;

char Top(Stack S);
int showmenu();
int checkOperator(char symbol);
bool IsEmpty(Stack S);
bool matchParenthesis(char symbol);
void symbolPostfix(char symbol,Stack S);
void normalPostfix(Stack S);
void advancePostfix(Stack S);
void Push(int data,Stack S);
void Pop(Stack S);
Stack CreateStack();

bool IsEmpty(Stack S){
	return S->Next == NULL;
}
bool matchParenthesis(char symbol){
	return symbol == ')';
}
int checkOperator(char symbol){
	switch(symbol){
		case '+':
		case '-':
			return 1;
			break;
		case '*':
		case '/':
			return 2;
			break;
		case '(':
			return 0;
			break;
	}
}
char Top(Stack S){
	if(!IsEmpty(S))
		return S->Next->value;
	else
		cout << "Stack Empty!";
}

int showmenu(){
	int select;
	cout << "=======MENU======" << endl;
	cout << "1.Infix" << endl;
	cout << "2.Infix ()" << endl;
	cout << "Please choose > ";
	cin >> select;
	return select;
}
void symbolPostfix(char symbol,Stack S){
	if(IsEmpty(S)){
		Push(symbol,S);
	}else{
		if(checkOperator(symbol) >= checkOperator(Top(S))){
			Push(symbol,S);
		}else if(checkOperator(symbol) == 0){
			check = true;
			Push(symbol,S);
		}else if(matchParenthesis(symbol)){
			while(Top(S) != '('){
				if(Top(S) == '('){
					Pop(S);
					break;
				}else{
					str += Top(S);
					str += " ";
					Pop(S);
				}
			}
		}else{
			while(!IsEmpty(S)){
				if(Top(S) == '('){
					if(check != true){
						Pop(S);
					}
					break;
				}else if (Top(S) == ')'){
					Pop(S);
				}else{
					str += Top(S);
					str += " ";
					Pop(S);
				}
			}
			Push(symbol,S);
		}
	}
}
void normalPostfix(Stack S){
	check = false;
	char data[40];
	str.clear();
	cout << "Infix: ";
	do{
		cin >> data;
		if(data[0] == '.'){
			if(!IsEmpty(S)){
				while(!IsEmpty(S)){
					str += Top(S);
					str += " ";
					Pop(S);
				}
				cout << "Postfix: " << str;
			}
			break;
		}else{
			if(isdigit(data[0])){
			    str += data;
				str += " ";
        	}else{
        		symbolPostfix(data[0],S);
			}
		}
	}while(data[0]!='.');
	cout << endl;
}
void advancePostfix(Stack S){
	check = false;
	char data[40];
	str.clear();
	cout << "Infix: ";
    do{
		cin >> data;
		if(data[0] == '.'){
			if(!IsEmpty(S)){
				while(!IsEmpty(S)){
					if(Top(S) == '('){
						Pop(S);
					}else{
						str += Top(S);
						str += " ";
						Pop(S);	
					}
				}
				cout << "Postfix: " << str;
			}
			break;
		}else{
			if(isdigit(data[0])){
			    str += data;
				str += " ";
        	}else{
        		symbolPostfix(data[0],S);
			}
		}
	}while(data[0]!='.');
	cout << endl;
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
	while(true){
		Stack S = CreateStack();
		switch(showmenu()){
			case 1:
				normalPostfix(S);
				break;
			case 2:
				advancePostfix(S);
				break;
			default:
				cout << "Please select 1 or 2 !!" << endl;
				break;
		}
	}
	return 0;
}
