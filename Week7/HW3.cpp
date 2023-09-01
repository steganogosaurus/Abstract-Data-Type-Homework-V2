#include <iostream>
#include <cstdlib>

using namespace std;
struct node{
	string value;
	struct node *left;
	struct node *right;
};
struct record{
	struct node *treenode;
	struct record *next;
};
struct record *CreateStack(){
	struct record *S;
	S = new struct record;
	S->next = NULL;
	if(S == NULL){
		cout << "Out of Space!";
	}
	return S;
}
struct record *S = CreateStack();
bool IsEmpty(struct record *S){
	return S->next == NULL;
}
int showmenu(){
	int select;
	cout << "=========MENU========" << endl;
	cout << "1. Input postorder"<< endl;
	cout << "2. Print Expression tree"<< endl;
	cout << "3. Exit"<<endl;
	cout << "Please choose> ";
	cin >> select;
	return select;
}
void printInorder(struct node *tree){
    if(tree == NULL){
        return;
    }else{
        printInorder(tree->left);
        cout << tree->value << " ";
        printInorder(tree->right);
    }
}
void printPostorder(struct node *tree){
    if(tree == NULL){
        return;
    }else{
        printPostorder(tree->left);
        printPostorder(tree->right);
        cout << tree->value << " ";
    }
}
void Push(struct node *data,struct record *S){
	struct record *TmpCell;
	TmpCell = new struct record;
	if(TmpCell == NULL){
		cout << "Out of space!!";
	}else{
		TmpCell->treenode = data;
		TmpCell->next = S->next;
		S->next = TmpCell;
	}
}
void Pop(struct record *S){
	struct record *FirstCell;
	if(IsEmpty(S)){
		cout << "Empty Stack!";
	}else{
		FirstCell = S->next;
		S->next = S->next->next;
		delete FirstCell;
	}
}
void createnode(string data){
	struct node *nodetree = NULL;
	nodetree = new struct node;
	nodetree->value = data;
	nodetree->left = nodetree->right = NULL;
	Push(nodetree,S);
}
struct node *insert(struct node *tree,string data){
    if(tree == NULL){
        tree = new struct node;
        tree->value  = data;
        tree->right = S->next->treenode;
        Pop(S);
		tree->left = S->next->treenode;
		Pop(S);
    }else if (data == "+" || data == "-" || data == "*" || data == "/"){
  		tree = new struct node;
  		tree->value = data;
    	tree->right = S->next->treenode;
    	Pop(S);
		tree->left = S->next->treenode;
    	Pop(S);
    }
    return tree;
}
int main(){
	struct node *tree = NULL;
	char data[30];
	char number;
	while(true){
		switch(showmenu()){
			case 1:
				cout << "Input: ";
				while(true){
					cin >> data;
					if(data[0] == '.'){
						break;
					}
					if(data[0]>='0'&& data[0]<='9'){
						createnode(data);
					}else{
						tree = insert(tree,data);
						Push(tree,S);
					}
				}
				break;
			case 2:
				cout << "Inorder: ";
				printInorder(S->next->treenode);
				cout << endl << "Postorder: ";
				printPostorder(S->next->treenode);
				cout << endl;
				break;
			case 3:
				cout << "Bye!";
				return 0;
				break;
			default:
				cout << "Please select 1-3!";
				break;
			} 
		}
	return 0;
}
