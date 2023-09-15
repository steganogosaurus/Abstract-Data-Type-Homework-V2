#include <iostream>
using namespace std;
struct record{
	int value;
	struct record *next;
};
struct head_end{
	struct record *head;
	struct record *end;
};
struct head_end insertList(struct record *head,struct record *end,int data){
	struct head_end box;
	struct record *node;
	if(head == NULL && end == NULL){
		head = new struct record;
		head->value = data;
		head->next = NULL;
		end = head;
	}else{
		node = new struct record;
		node->value = data;
		node->next = NULL;
		end->next = node;
		end = node;
	}
	box.head = head;
	box.end = end;
	return box;
}
void printList(struct record *head){
	struct record *p = head;
	if(head == NULL){
		cout << "Empty List!" << endl; 
	}else{
		cout << "List : ";
		while(p){
			cout << p->value << " ";
			p = p->next;
		}
	}
}
int main(){
	struct head_end box;
	struct record *head = NULL ,*end = NULL;
	int data;
	cout << "Input : ";
	while(true){
		cin >> data;
		if(data <= 0){
			break;
		}
		box = insertList(head,end,data);
		head = box.head;
		end = box.end;
	}
	printList(head);
	return 0;
}
