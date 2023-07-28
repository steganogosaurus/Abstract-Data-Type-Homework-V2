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
	cout << "2) Print min to max / max to min"<<endl;
	cout << "3) Exit"<<endl;
	cout << "Please choose > ";
	cin >> select;
	return select;
}
void printData(struct record *hnt,int select){
		struct record *p = hnt;
		if(hnt == NULL){
			cout << "Empty List!";
		}else{
			if(select == 0){
				while (p){
					cout << p->value << " ";
					p = p->next;
				}
				cout << endl;
			}else if(select == 1){
				while (p){
					cout << p->value << " ";
					p = p->prev;
				}
				cout << endl;
			}	
		}	
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
				printData(head,0);
				break;
			case 2:
				cout << "Min to max: ";
				printData(head,0);
				cout << endl << "Max to min: ";
				printData(tail,1);
				break;
			case 3:
				return 0;
				break;
		}
	}
	return 0;
}
