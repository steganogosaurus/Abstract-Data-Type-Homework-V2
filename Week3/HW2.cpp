#include <iostream>
using namespace std;
struct record {
	char value;
	struct record *next;
};
int showmenu(){
	int select;
	cout << "========MENU=======" << endl;
	cout << "1)Insert" << endl;
	cout << "2)Odd,even" << endl;
	cout << "3)Decode " << endl;
	cout << "4)Exit" << endl;
	cout << "Please choose > ";
	cin >> select;
	return select;
}
void printData(struct record *head){
	if(head == NULL){
		cout << "Empty list!";
	}else{
		struct record *p = head->next;
		while (p){
			cout << p->value;
			p = p->next;
		}
	}
	cout << endl;
} 
void printDecode(struct record *head,int val){
	int check = val;
	if(head == NULL){
		cout << "Empty list!";
	}else{
		struct record *p = head;
		while (p){
			if(check%2 == 0){
				cout << p->value;
			}
			p = p->next;
			check++;
		}
	}
	cout << endl;
} 
struct record *insert(struct record *head,char data){
	struct record *node,*p;
	if(head == NULL){		//case no Data in LinkedList
		head = new struct record;
		head->value = data;
		head->next = NULL;
	}else{
		node = new struct record;
		node->value = data;
		p = head;
		while(p->next != NULL){
			p = p->next;
		}
		if(p->next == NULL){
			node->next = NULL;
			p->next = node;
		}
	}
	return head;
}
int main(){
	struct record *head = NULL;
	while(true){
		switch(showmenu()){
			case 1:
				char c;
				cout << "Enter Code :";
				do {
					c = getchar();
					if (c == '.')
						break;
					else
						head = insert(head,c);
				}while (c != '.');
				cout << "List : ";
				printData(head);
				break;
			case 2:
				cout << "Odd node = ";
				printDecode(head,1);
				cout << "Even node = ";
				printDecode(head,2);
				break;
			case 3:
				cout << "Decode : ";
				printDecode(head,1);
				break;
			case 4:
				return 0;
				break;
		}
	}
	return 0;
}
