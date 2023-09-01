#include <iostream>
using namespace std;
struct node{
    int value;
    int height;
    struct node *left;
    struct node *right;
};
int showmenu(){
    int select;
    cout << "========MENU======"<< endl;
    cout << "1)Insert"<< endl;
    cout << "2)Print Inorder"<< endl;
    cout << "3)Exit"<< endl;
    cout << "Please choose > ";
    cin >> select;
    return select;
}
int fheight(struct node *P){
	if(P == NULL){
		return -1;
	}else{
		return P->height;
	}
}
struct node *find_min(struct node *tree){
    if(tree == NULL){
        return NULL;
    }else{
        if(tree->left == NULL){
            return tree;
        }else{
            return (find_min(tree->left));
        }
    }
}
struct node *find_max(struct node *tree){
    if(tree == NULL){
        return NULL;
    }else{
        if(tree->right == NULL){
            return tree;
        }else{
            return (find_max(tree->right));
        }
    }
}
struct node *insert(struct node *tree,int x){
    if(tree == NULL){
        tree = new struct node;
        tree->value  = x;
        tree->left = tree->right = NULL;
        tree->height = 0;
    }else{
        if(x < tree->value){
            tree->left = insert(tree->left,x);
            if(fheight(tree->left)-fheight(tree->right) == 2){
            	cout << "You have to rotate trees!" << endl;
            	return NULL;
			}
        }else if(x > tree->value){
            tree->right = insert(tree->right,x);
            if(fheight(tree->right)-fheight(tree->left) == 2){
            	cout << "You have to rotate trees!" << endl;
            	return NULL;
			}
        }
    }
    tree->height = max(fheight(tree->left),fheight(tree->right)) +1;
    return tree;
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
int main() {
    struct node *tree = NULL;
    int data;
    while(true){
        switch(showmenu()){
            case 1:
                cout << "Enter: ";
                cin >> data;
                tree = insert(tree,data);
                if(tree != NULL){
                	cout << "Success!"<<endl;
				}else{
					return 0;
				}
                break;
            case 2:
                cout << "Inorder: ";
                printInorder(tree);
                cout << endl;
                break;
            case 3:
            	cout << "Bye!";
            	return 0;
                break;
            default:
                cout << "please Select 1-6!"<<endl;
                break;
        }
    }
    return 0;
}
