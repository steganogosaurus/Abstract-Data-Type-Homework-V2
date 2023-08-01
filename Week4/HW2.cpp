#include <iostream>
using namespace std;
struct record{
	int value;
	struct record *next;
	struct record *prev;
};
struct head_n_tail{
	struct record *head;
	struct record *tail;
};
int showmenu(){
	int select;
	cout << "========MENU======="<<endl;
	cout << "1) Insert"<<endl;
	cout << "2) Delete"<<endl;
	cout << "3) Print"<<endl;
	cout << "4) Exit"<<endl;
	cout << "Please choose > ";
	cin >> select;
	return select;
}
void printData(struct record *hnt){
	struct record *p = hnt;
	if(hnt == NULL){
		cout << "Empty List!";
	}else{
		while (p){
			cout << p->value << " ";
			p = p->next;
		}
		cout << endl;
	}	
} 
struct head_n_tail deleteData(struct record *head,struct record *tail,int data){
	struct head_n_tail box;
	struct record *p,*tmpfree;
	if(data == head->value){
		tmpfree = head;
		head = head->next;
		head->prev = NULL;
		delete tmpfree;
		box.head = head;
	}else if (data == tail->value){
		tmpfree = tail;
		tail = tail->prev;
		tail->next = NULL;
		delete tmpfree;
		box.tail = tail;
	}else{
		p = head;
		while(p){
			if(data == p->next->value){
				tmpfree = p->next;
				p->next->next->prev = p;
				p->next = p->next->next;
				delete tmpfree;
				break;
			}
			p = p->next;
		}
	}
	cout << "Success!" << endl;
	return box;
}
struct head_n_tail insert(struct record *head,struct record *tail,int data){
	struct head_n_tail box;
	struct record *node,*p;
	if(head == NULL && tail == NULL){
		head = new struct record;
		head->value = data;
		head->next = NULL;
		head->prev = NULL;
		tail = head;
		box.head=head;
        box.tail=tail;
	}else{
		node = new struct record;
		node->value = data;
		if(data < head->value){
			node -> prev = NULL;
			node ->next = head;
			head ->prev = node;
			head = node;
			box.head=head;
        		box.tail=tail;
		}else{
			p = head;
			while (p->next != NULL){
				 if(data < p->next->value){
				 	p->next->prev = node;
				 	node->next = p->next;
				 	node->prev = p;
				 	p->next = node;
				 	box.head=head;
        				box.tail=tail;
				 	break;
				 }else{
				 	p = p->next; 
				 }
			}
			if(p->next == NULL){
				node->next = NULL;
				node->prev = p;
				p->next = node;
				tail = node;
				box.head=head;
        			box.tail=tail;
			}
		}
	}
	cout << "Success!" << endl;
	return box;
}
int main(){
	struct record *head = NULL;
	struct record *tail = NULL;
	struct head_n_tail box;
	int data;
	while(true){
		switch(showmenu()){
			case 1:
				cout << "insert : ";
				cin >> data;
				box = insert(head,tail,data);
				head = box.head;
				tail = box.tail;
				cout << "List = ";
				printData(head);
				break;
			case 2:
				cout << "Delete: ";
				cin >> data;
				box = deleteData(head,tail,data);
				head = box.head;
				tail = box.tail;
				break;
			case 3:
				cout << "List: ";
				printData(head);
				break;
			case 4:
				cout << "Bye!";
				return 0;
				break;
			default:
				cout << "Please choose 1-4!!";
				break;
		}
	}
	return 0;
}
