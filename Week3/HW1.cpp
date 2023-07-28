#include <iostream>
using namespace std;
int count;
struct record{
	int value;
	struct record *next;
};
void printData(struct record *head,int select){  //print AllData in LinkedList,MaxtoMin,MintoMax,OddNode
	if(head == NULL){
		cout << "Empty list!"<<endl;
	}else if(select == 0){
		struct record *p = head;
		while (p){
			cout << p->value << " ";
			p = p->next;
		}
		cout << endl;
	}else if(select == 1){
		int i = count-1;
		while (i>=0){
			int j = 0;
			struct record *p = head;
			while(j <= i){
				if(j == i){
					cout << p->value << " ";
				}
				p = p->next;
				j++;
			}
			i--;
		}
	}else if(select == 2){
		int check = 1;
		struct record *p = head;
		while (p){
			if(check%2!=0){
				cout << p->value << " ";	
			}
			check++;
			p = p->next;
		}
	}
	cout << endl;
}
struct record *insert(struct record *head,int data){
	struct record *node,*p;
	if(head == NULL){		//case no Data in LinkedList
		head = new struct record;
		head->value = data;
		head->next = NULL;
		count++;
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
		count++;
	}
	cout << "Success!" << endl;
	return head;
}
struct record *deleteData(struct record *head,int data){
	struct record *node,*tmpfree;
	node = head;
	if(data == head->value){ 
		count--;
        tmpfree = node;
        node = node->next;
    	delete tmpfree;
	}else{
		while(node){
			if(data == node->next->value){
				tmpfree = node ->next;
				node->next = node->next->next;
				delete tmpfree;
				break;
			}else if(data == node->next->value && node->next->next == NULL){
				tmpfree = node->next;
				node->next = node->next->next;
				delete tmpfree;
				break;
			}else{
				node = node->next;
			}
		}
		count--;	
	}
	cout << "Success!" << endl;
	return node;
}
int showmenu(){
	int select;
	cout << "========MENU=======" << endl;
	cout << "1) Insert" << endl;
	cout << "2) Delete" << endl;
	cout << "3) Print min to max / max to min" << endl;
	cout << "4) Count node" << endl;
	cout << "5) Print only odd node" << endl;
	cout << "6) Exit" << endl;
	cout << "Please choose > ";
	cin >> select;
	return select;
}
int main(){
	struct record *head = NULL;
	while(true){
		int value;
		switch(showmenu()){
			case 1:
				cout << "Insert: ";
				cin >> value;
				head = insert(head,value);
				break;
			case 2:
				cout << "Delete: ";
				cin >> value;
				if(value == head->value){
					head = deleteData(head,value);
				}else{
					deleteData(head,value);
				}
				break;
			case 3:
				cout << "Min to max: ";
				printData(head,0);
				cout << "Max to min: " ;
				printData(head,1);
				break;
			case 4:
				cout << "Number of node = " << count << endl;
				break;
			case 5:
				cout << "Odd node = ";
				printData(head,2);
				break;
			case 6:
				return 0;
				break;
			default:
				break;
		}
	}
	return 0;
}
