#include <iostream>
using namespace std;
/*	
	1 -1
	2 4 5 -1
	3 6 -1
	2 7 -1
	0 5 -1
	6 -1
	5 7 -1
	7 -1
*/
struct record{
	int value;
	struct record *next;
};
struct head_end{
	struct record *head;
	struct record *end;
};
int DFS_Tree = 1;
int time = 0;
int pass[8];
int d[8];
int f[8];
int pred[8];
struct record *adjList[8];
struct head_end insert(struct record *head,struct record *end,int data){
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
void adjacency_list(){
	struct record *head = NULL ,*end = NULL;
	struct head_end box;
	for(int i = 0 ; i < 8 ;i++){
		adjList[i] = NULL;
	}
	for(int i = 0;i<8;i++){
		int data = 0;
		cout << "#"<< i << " : ";
		while(data != -1){
			cin >> data;
			if(data < 0){
				break;
			}
			box = insert(head,end,data);
			head = box.head;
			end = box.end;
		}
		adjList[i] = head;
		head = NULL;
		end = NULL;
	}
}
void DepthFirstSearch_Visit(int u){
	struct record *node;
	int v;
	pass[u] = 1;
	d[u] = ++time;
	node = adjList[u];
	while(node != NULL){
		v = node->value;
		if(pass[v] == 0){
			pred[v] = u;
			DepthFirstSearch_Visit(v);
		}
		node = node->next;
	}
	pass[u] = 1;
	f[u] = ++time;
}
void DepthFirstSearch(int u){
	DepthFirstSearch_Visit(u);
	for(int u = 0;u < 8;u++){
		if(pass[u] == 0){
			DFS_Tree++;
			DepthFirstSearch(u);
		}
	}
}
int showmenu(){
	int select;
	cout << "==========MENU=========" << endl;
	cout << "1) Insert Graph" << endl;
	cout << "2) DFS " << endl;
	cout << "3) Exit " << endl;
	cout << "Please choose > ";
	cin >> select;
	return select;
}
void print_array(int arr[]){
	for(int i  = 0 ; i < 8 ;i++){
		cout << arr[i] << " ";
	}
}
int main(){
	int vertex_source;
	while(true){
		switch(showmenu()){
			case 1:
				adjacency_list();
				break;
			case 2:
				for(int i = 0;i < 8;i++){
					pass[i] = 0;
					pred[i] = d[i] = f[i] = -1;
				}
				cout << "Input source vertex: ";
				cin >> vertex_source;
				DepthFirstSearch(vertex_source);
				cout << "Tree = " << DFS_Tree << endl;
				cout << "d: ";
				print_array(d);
				cout << endl << "f: ";
				print_array(f);
				cout << endl << "pred: ";
				print_array(pred);
				cout << endl;
				break;
			case 3:
				cout << "Bye!";
				return 0;
				break;
			default:
				cout << "u have to choose 1 - 3!!";
				break;
		}
	}
	return 0;
}
