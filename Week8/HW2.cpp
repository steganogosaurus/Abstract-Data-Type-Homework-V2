#include <iostream>
/*
Adjacency List & Matrix Data
1 3
4
2 4 5
1
3
5
*/
using namespace std;
struct record{
	int value;
	struct record *next;
};
struct head_end{
	struct record *head;
	struct record *end;
};
struct record *adjList[6];
int adjMatrix[6][6];
int showmenu(){
	int select;
	cout << "===========MENU==========" << endl;
	cout << "1)Input adjacency list" << endl;
	cout << "2)Input adjacency matrix" << endl;
	cout << "3)Show self loop from adjacency list" << endl;
	cout << "4)Exit" << endl;
	cout << "Please choose > ";
	cin >> select;
	return select;
}
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
		while(p){
			cout << p->value << " ";
			p = p->next;
		}
	}
}
void adjacency_list(){
	struct record *head = NULL ,*end = NULL;
	struct head_end box;
	for(int i = 0 ; i < 6 ;i++){
		adjList[i] = NULL;
	}
	for(int i = 0;i<6;i++){
		int data = 0;
		cout << "Enter #"<< i << " : ";
		while(data != -1){
			cin >> data;
			if(data < 0){
				break;
			}
			box = insertList(head,end,data);
			head = box.head;
			end = box.end;
		}
		adjList[i] = head;
		head = NULL;
		end = NULL;
	}
	cout << endl << "ADJACENCY LIST" <<endl;
	for(int i = 0;i<6;i++){
		cout << "#"<< i << " : ";
		printList(adjList[i]);
		cout << endl;
	}
}
void adjacency_matrix(){
	for(int i = 0;i < 6;i++){
		for(int j = 0;j < 6;j++){
			adjMatrix[i][j] = 0;
		}
	}
	for(int i = 0;i < 6;i++){
		int data = 0;
		cout << "Enter #"<< i << " : ";
		while(data != -1){
			cin >> data;
			if(data < 0){
				break;
			}
			adjMatrix[i][data] = 1;
		}
	}
	cout << endl << "ADJACENCY Matrix" << endl;
	cout << "---------------------------" << endl;
	for(int i = 0;i < 6;i++){
		for(int j = 0;j < 6;j++){
			cout << adjMatrix[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}
void selfloop(){
	cout << "Selfloop: ";
	for(int i = 0;i < 6;i++){
		struct record *p = adjList[i];
		while(p){
			if(p->value == i)
				cout << p->value << " ";
			p = p->next;
		}
	}
	cout << endl;
}
int main(){
	while(true){
		switch(showmenu()){
			case 1:
				adjacency_list();
				break;
			case 2:
				adjacency_matrix();
				break;
			case 3:
				selfloop();
				break;
			case 4:
				cout << "Bye!";
				return 0;
				break;
			default:
				cout << "Invalid Number!";
				break;
		}
	}
	return 0;
}
