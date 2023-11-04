#include <iostream>
using namespace std;
int time=0,pass[8],d[8],f[8],pred[8];
void menu(){
	cout<<"==========MENU=========="<<endl;
	cout<<"1) Insert Graph"<<endl; //insert adj list
	cout<<"2) DFS"<<endl;
	cout<<"3) Transpose graph"<<endl;
	cout<<"4) Decompose strongly connected graph"<<endl;
	cout<<"5) Exit"<<endl;
	cout<<"Please choose > ";
};
struct node{
	int value;
	struct node *next;	
};

struct node *A[8],*T[8];
int source=-1;
struct node *insert(struct node *head,int data){
	if(head == NULL){
		head = new struct node;
		head->value = data;
		head->next = NULL;
	}else{
		struct node *p=head, *vertex;
		vertex = new struct node;
		vertex->value = data;
		vertex->next = NULL;
		while(p->next != NULL){
			p = p->next;
		}
		if(p->next == NULL){
			p->next = vertex;
		}
	}
	return head;
}

void insertGraph(){
	int data;
	for(int index=0;index<8;index++){
		A[index] = NULL;
		T[index] = NULL;
	}
	for(int vertex=0;vertex<8;vertex++){
		cout<<"#"<<vertex<<" : ";
		cin>>data;
		while(data != -1){
			A[vertex]=insert(A[vertex],data);
			cin>>data;
		}
	}
	cout<<endl;
}

void DFS_Visit(int u){
	struct node *v=A[u];
	pass[u]=1;
	d[u]=++time;
	while(v != NULL){
		if(pass[v->value] == 0){
			pred[v->value] = u;
			DFS_Visit(v->value);
		}
		v=v->next;
	}
	pass[u]=1;
	f[u]=++time;
}

void DFS(struct node *A[]){
	time=0;
	cout<<"Input source vertex : ";
	cin>>source;
	for(int u=0;u<8;u++){
		pass[u]=0;
		d[u]=-1;
		f[u]=-1;
		pred[u]=-1;
	}
	for(int u=source;u<8;u++){
		if(pass[u]==0){
			DFS_Visit(u);
		}
	}
	int Trees=0;
	for(int index=0;index<8;index++){
		if(pred[index] == -1){
			++Trees;
		}
	}
	cout<<"Trees = "<<Trees<<endl;
	cout<<"--------------------"<<endl;
	cout<<"d :";
	for(int index=0;index<8;index++){
		cout<<" "<<d[index];
	}
	cout<<endl;
	cout<<"f :";
	for(int index=0;index<8;index++){
		cout<<" "<<f[index];
	}
	cout<<endl;
	cout<<"pred :";
	for(int index=0;index<8;index++){
		cout<<" "<<pred[index];
	}
	cout<<endl<<endl;
}

void Transposegraph(){
	for(int index=0;index<8;index++){
		struct node *p=A[index];
		while(p != NULL){
			T[p->value]=insert(T[p->value],index);
			p=p->next;
		}
	}
	cout<<"Adjacency list"<<endl;
	for(int index=0;index<8;index++){
		cout<<index<<" :";
		struct node *p=A[index];
		while(p != NULL){
			cout<<" "<<p->value;
			p=p->next;
		}
		cout<<endl;
	}
	cout<<"Adjacency list transpose"<<endl;
	for(int index=0;index<8;index++){
		cout<<index<<" :";
		struct node *p=T[index];
		while(p != NULL){
			cout<<" "<<p->value;
			p=p->next;
		}
		cout<<endl;
	}
	cout<<endl;
}

void DES_Visit(int u){
	struct node *v=T[u];
	pass[u]=1;
	d[u]=++time;
	while(v != NULL){
		if(pass[v->value] == 0){
			pred[v->value] = u;
			DES_Visit(v->value);
		}
		v=v->next;
	}
	pass[u]=1;
	f[u]=++time;
}

void printGroup(){
	
}

void DES(struct node *T[]){
	time=0;
	for(int u=0;u<8;u++){
		pass[u]=0;
		d[u]=-1;
		f[u]=-1;
		pred[u]=-1;
	}
	for(int u=source;u<8;u++){
		if(pass[u]==0){
			DES_Visit(u);
		}
	}

	int Trees=0;
	for(int index=0;index<8;index++){
		if(pred[index] == -1){
			//pred[index] = index;
			++Trees;
		}
	}
/*
	cout<<"Trees = "<<Trees<<endl;
	cout<<"--------------------"<<endl;
	cout<<"index :";
	for(int index=0;index<8;index++){
		cout<<" "<<index;
	}
	cout<<endl;
	cout<<"d :";
	for(int index=0;index<8;index++){
		cout<<" "<<d[index];
	}
	cout<<endl;
	cout<<"f :";
	for(int index=0;index<8;index++){
		cout<<" "<<f[index];
	}
	cout<<endl;
	cout<<"pred :";
	for(int index=0;index<8;index++){
		cout<<" "<<pred[index];
	}
	cout<<endl<<endl;
*/
	for(int group=1;group<=Trees;group++){
		cout<<group;

		cout<<endl;
	}
	
}
				/*
				1
				1 -1
				2 4 5 -1
				3 6 -1
				2 7 -1
				0 5 -1
				6 -1
				5 7 -1
				7 -1
				*/
void DecomposeStronglyConnectedGraph(struct node *T[]){
	if(source != -1 && T[0] != NULL){
		DES(T);	
	}
}
int main(){
	int choose;
	while(true){
		menu();
		cin>>choose;
		switch(choose){
			case 1:
				insertGraph();
				break;
			case 2:
				DFS(A);
				break;
			case 3:
				Transposegraph();
				break;
			case 4:
				DecomposeStronglyConnectedGraph(T);
				break;
			case 5:
				exit(0);
				break;
			default:
				cout<<"Not Choice!!"<<endl<<endl;
				break;
		}
	}
	return 0;
}
