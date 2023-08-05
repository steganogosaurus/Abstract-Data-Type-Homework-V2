//Name : Wiritipon Thapkhan
//ID : 6530300503
 
#include <iostream>
using namespace std;
struct Node{
	char value;
	struct Node *Next;
};
typedef struct Node *Stack;
int openSize = 0, closeSize = 0;

bool IsEmpty(Stack S);
bool IsMatch(char open, char close);
char Top(Stack S);
char reverseSymbol(char parenthesis);
void BalancingSymbolCheck(Stack S,Stack s1);
void swapStack(Stack current,Stack newStack,bool check);
void Push(char symbol,Stack S);
void Pop(Stack S);
Stack CreateStack();

int main(){
	char parenthesis;
	Stack openBracket = CreateStack();
	Stack closeBracket = CreateStack();
	cout << "Input: ";
	do{
		cin >> parenthesis;
		if(parenthesis == '.'){
			break;
		}
		else{
			(parenthesis == '{') ? (Push(parenthesis,openBracket),openSize++): 
			(parenthesis == '[') ? (Push(parenthesis,openBracket),openSize++):
			(parenthesis == '(') ? (Push(parenthesis,openBracket),openSize++):
			(parenthesis == '<') ? (Push(parenthesis,openBracket),openSize++): (Push(parenthesis,closeBracket),closeSize++); 			
		}	
	}while(true);
	BalancingSymbolCheck(openBracket,closeBracket);
	return 0;
}
void swapStack(Stack current,Stack newStack,bool check){ 
	if(check){
		while(!IsEmpty(current)){
			Push(reverseSymbol(current->Next->value),newStack);
			Pop(current);
		}
	}else{
		while(!IsEmpty(current)){
			Push(current->Next->value,newStack);
			Pop(current);
		}
	}
}
void BalancingSymbolCheck(Stack S,Stack s1){
	Stack s2 = CreateStack();
	int i = 0,Loop;
	swapStack(S,s2,false);
	(openSize > closeSize) ? Loop = openSize : Loop = closeSize;	
	while(i < Loop){
		if(IsEmpty(s1)){
			swapStack(s2,S,true);
		}else if (IsEmpty(s2)){
			swapStack(s1,S,true);
		}else{
			if(IsMatch(s2->Next->value,s1->Next->value)){
				Pop(s1);
				Pop(s2);	
			}else{
				(openSize > closeSize) ? (Push(reverseSymbol(s2->Next->value),S),Pop(s2),openSize--) : (Push(reverseSymbol(s1->Next->value),S),Pop(s1),closeSize--);
				//This Line is used to check the size of Data in the stack and then push it to Stack S , Pop , size--
			}
		}	
		i++;
	}
	if(IsEmpty(S)){
		cout << "Complete!";
	}else{
		cout << "Expected ";
		while(!IsEmpty(S)){
			cout << Top(S) << " ";
			Pop(S);
		}	
	}
}
bool IsMatch(char open, char close){
    return (open == '{' && close == '}') || (open == '(' && close == ')') || (open == '[' && close == ']') || (open == '<' && close == '>');
}
bool IsEmpty(Stack S){
	return S->Next == NULL;
}
char Top(Stack S){
	if(!IsEmpty(S))
		return S->Next->value;
	else
		cout << "Stack Empty!";
}
char reverseSymbol(char parenthesis){
	char rev;
	(parenthesis == '{') ? rev = '}': 
	(parenthesis == '[') ? rev = ']':
	(parenthesis == '(') ? rev = ')':
	(parenthesis == '<') ? rev = '>':
	(parenthesis == '}') ? rev ='{': 
	(parenthesis == ']') ? rev ='[':
	(parenthesis == ')') ? rev ='(':
	(parenthesis == '>') ? rev ='<': rev = '0';	
	return rev;
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
