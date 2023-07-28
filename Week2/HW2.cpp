#include <iostream>
using namespace std;
struct record{
	int value;
	struct record *next;
};
int showmenu(){
	int select;
	cout << "========MENU========" << endl;
	cout << "1)Insert" << endl;
	cout << "2)Print All data" << endl;
	cout << "3)Print first and last" << endl;
	cout << "4)Exit" << endl;
	cout << "Please choose >";
	cin >> select;
	return select;
}
void printData(struct record *head,int select){
	if(head == NULL){
		cout << "Empty list!";
	}else{
		struct record *p = head;
		while (p){
			if(select == 0){
				cout << p->value << " ";
			}else if(select == 1 && p->next == NULL){	
					cout << p->value;
			}
			p = p->next;
		}
		cout << endl;
	}
}
struct record *insert(struct record *head,int data){
	struct record *node,*p;
	if(head == NULL){
		head = new struct record;
		head->value = data;
		head->next = NULL;
	}else{
		node = new struct record;
		node->value = data;
		if(data < head->value){
			node -> next = head;
			head = node;
		}else{
			p = head;
			while (p->next != NULL){
				 if(data < p->next->value){
				 	node -> next = p-> next;
				 	p->next = node;
				 	break;
				 }else{
				 	p = p->next;
				 }
			}
			if(p->next == NULL){
				node->next = NULL;
				p->next = node;
			}
		}
	}
	cout << "Success!" << endl  << "List = ";
	return head;
}
int main(){
	struct record *head = NULL;
	while(true){
		switch(showmenu()){
			case 1:
				int val;
				cout << "Insert: ";
				cin >> val;
				head = insert(head,val);
				printData(head,0);
				break;
			case 2:
				cout << "List : ";
				printData(head,0);
				break;
			case 3:
				cout << "First: " << head->value << endl;
				cout << "Last: ";
				printData(head,1);
				break;
			case 4:
				return 0;
				break;
			default:
				cout << "Please Choose 1-4!";
				break;					
		}
	}
	return 0;
}
