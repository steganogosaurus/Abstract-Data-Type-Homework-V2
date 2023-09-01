#include <iostream>
using namespace std;
struct node{
    int value;
    struct node *left;
    struct node *right;
};
int showmenu(){
    int select;
    cout << "========MENU======"<< endl;
    cout << "1)Insert"<< endl;
    cout << "2)Print Inorder, print leave node, print nonleave node"<< endl;
    cout << "3)Delete"<< endl;
    cout << "4)Find"<< endl;
    cout << "5)Exit"<< endl;
    cout << "Please choose > ";
    cin >> select;
    return select;
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
    }else{
        if(x < tree->value){
            tree->left = insert(tree->left,x);
        }else if(x > tree->value){
            tree->right = insert(tree->right,x);
        }
    }
    return tree;
}
struct node *dTree(struct node *tree,int x){
	struct node *tmpcell,*child;
	if(tree == NULL){
		cout << ("No data!\n");
	}else{
		if(x < tree->value){
			tree->left = dTree(tree->left,x);
		}else{
			if(x > tree->value){
				tree->right = dTree(tree->right,x);
			}else{
				if(tree->left != NULL && tree->right != NULL){
					tmpcell = find_min(tree->right);
					tree->value = tmpcell->value;
					tree->right = dTree(tree->right,tree->value);
				}else{
					tmpcell = tree;
					if(tree->left == NULL)
						child = tree->right;
					if(tree->right == NULL)
						child = tree->left;
					delete tmpcell;
					return child;
				}
			}	
		}
	}
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
void printLeavesNode(struct node *tree){
	if(tree == NULL){
        return;
    }else{
        printLeavesNode(tree->left);
        if(tree->left == NULL && tree->right == NULL){
        	cout << tree->value << " ";
		}
        printLeavesNode(tree->right);
    }
}
void printNonLeavesNode(struct node *tree){
	if(tree == NULL){
        return;
    }else{
        printNonLeavesNode(tree->left);
        if(tree->left != NULL && tree->right != NULL){
        	cout << tree->value << " ";
		}
        printNonLeavesNode(tree->right);
    }
}
void BinarySearchTree(struct node *tree,int data){
	if(tree == NULL){
		cout << "Not found!" <<endl;;
		return;
	}else{
		if(data == tree->value){
			cout << "Found!" <<endl;
			return;
		}else{
			if(data < tree->value){
				BinarySearchTree(tree->left,data);
			}if(data > tree->value){
				BinarySearchTree(tree->right,data);
			}
		}
	}
}
int main() {
    struct node *tree = NULL;
    int data;
    while(true){
        switch(showmenu()){
            case 1:
                cout << "Insert: ";
                cin >> data;
                tree = insert(tree,data);
                cout << "Success!"<<endl;
                break;
            case 2:
                cout << "Inorder: ";
                printInorder(tree);
                cout << endl << "Leave: ";
                printLeavesNode(tree);
                cout << endl << "Nonleave: ";
                printNonLeavesNode(tree);
                cout << endl;
                break;
            case 3:
                cout << "Delete: ";
                cin >> data;
                tree = dTree(tree,data);
                cout << "Success!"<<endl;
                break;
            case 4:
               	cout << "Search: ";
               	cin >> data;
               	BinarySearchTree(tree,data);
                break;
            case 5:
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
