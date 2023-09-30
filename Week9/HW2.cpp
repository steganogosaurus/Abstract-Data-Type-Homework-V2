#include <iostream>
#include <algorithm>
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
int vertex_source;
int fMax;
int StronglyTree = 0;
int DFS_Tree = 1;
int time = 0,timeT = 0;
int pass[8],passT[8];
int d[8],dT[8];
int f[8],fT[8],FinishButMaxtoMin[8];
int pred[8],predT[8];
struct record *adjList[8];
struct record *adjListButTranspose[8];
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
void print_array(int arr[]){
	for(int i  = 0 ; i < 8 ;i++){
		cout << arr[i] << " ";
	}
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
void TransposeGraph(){	
	struct head_end box;
	struct record *head = NULL ,*end = NULL;
	int k = 0;
	for(int i = 0 ; i < 8 ;i++){
		adjListButTranspose[i] = NULL;
	}
	for(int i = 0 ;i < 8 ;i++){
		for(int j = 0;j < 8;j++){
			struct record *p = adjList[j]; 
			while(p != NULL){
				if(p->value == i){
					box = insert(head,end,j);
					head = box.head;
					end = box.end;
				}
				p = p->next;
			}
		}
		adjListButTranspose[i] = head;
		head = NULL;
		end = NULL;
	}
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
void DepthFirstSearch_Visit_Transpose(int uT){
	struct record *node;
	int vT;
	passT[uT] = 1;
	dT[uT] = ++timeT;
	node = adjListButTranspose[uT];
	while(node != NULL){
		vT = node->value;
		if(passT[vT] == 0){
			predT[vT] = uT;
			DepthFirstSearch_Visit_Transpose(vT);
		}
		node = node->next;
	}
	passT[uT] = 1;
	fT[uT] = ++timeT;
}
void DepthFirstSearch_Transpose(int uT){
	DepthFirstSearch_Visit_Transpose(uT);
}
void prepareData(){
	int initialvalue,dynamicInitial;
	for(int i = 0 ; i < 8;i++){
		if(predT[i] == -1){
			cout << "(" << i;
			initialvalue = fT[i]; 
			predT[i] = -2;
			break;
		}
	}
	dynamicInitial = initialvalue-1;
	for(int j = 0 ;j < 8;j++){
		if(fT[j] == dynamicInitial && predT[j] != -1){
			if(fT[j] == dynamicInitial && dT[j] == dynamicInitial-1){
				cout << "(" << j << " " << j << ")";
				dynamicInitial=dynamicInitial-2;
				break;
			}
			cout << "(" << j;
			dynamicInitial--;
		}
	}
	for(int j = 0 ;j < 8;j++){
		if(dT[j] == dynamicInitial && predT[j] != -1){
			if(predT[j] == -1 && dT[j] == dynamicInitial && fT[j] == initialvalue){
				cout <<j << ")";
				break;
			}else{
				cout<<j << ")";
				dynamicInitial--;
			}			
		}
	}	
}
void printTreeDFSFormat(){
	int tree = 1;
	for(int i = 0;i < 8 ; i++){
		if(predT[i] == -1){
			++StronglyTree;
		}
	}
	for(int i = 0;i <=StronglyTree ; i++){
		for(int j = 0;j<8;j++){
			if(predT[j] == -1){
				cout << tree++;
				prepareData();
				cout << endl;
			}
		}
	}
}
void DecompStronglyConnected(){
	for(int i = 0;i < 8;i++){
		passT[i] = 0;
		predT[i] = dT[i] = fT[i] = -1;
	}
	for(int i = 0;i < 8 ; i++){
		FinishButMaxtoMin[i] = f[i]; 
	}
	int size = sizeof(FinishButMaxtoMin) / sizeof(FinishButMaxtoMin[0]);
	sort(FinishButMaxtoMin, FinishButMaxtoMin + size,greater<int>());
	cout << endl;
	for(int u = 0;u < 8;u++){
		for(int i = 0; i < 8;i++){
			if(FinishButMaxtoMin[u] == f[i] && passT[i] == 0){
				DepthFirstSearch_Transpose(i);
				break;
			}
		}
	}
	printTreeDFSFormat();
}
int showmenu(){
	int select;
	cout << "==========MENU=========" << endl;
	cout << "1) Insert Graph" << endl;
	cout << "2) DFS " << endl;
	cout << "3) Transpose graph " << endl;
	cout << "4) Decompose strongly connected graph " << endl;
	cout << "5) Exit " << endl;
	cout << "Please choose > ";
	cin >> select;
	return select;
}
int main(){
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
				cout << endl << "Adjacency list " <<endl;
				for(int i = 0;i<8;i++){
					cout << i << " : ";
					printList(adjList[i]);
					cout << endl;
				}
				TransposeGraph();
				cout << endl << "Adajacency list transpose  " <<endl;
				for(int i = 0;i<8;i++){
					cout << i << " : ";
					printList(adjListButTranspose[i]);
					cout << endl;
				}
				break;
			case 4:
				DecompStronglyConnected();
				break;
			case 5:
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
