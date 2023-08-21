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
    cout << "2)Print"<< endl;
    cout << "3)Find min"<< endl;
    cout << "4)Exit"<< endl;
    cout << "Please choose > ";
    cin >> select;
    return select;
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
void printPreorder(struct node *tree){
    if(tree == NULL){
        return;
    }else{
        cout << tree->value << " ";
        printPreorder(tree->left);
        printPreorder(tree->right);
    }
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

int main() {
    struct node *tree = NULL;
    struct node *min;
    int data;
    while(true){
        switch(showmenu()){
            case 1:
                cout << "Enter: ";
                cin >> data;
                tree = insert(tree,data);
                cout << "Success!"<<endl;
                break;
            case 2:
                cout << "Preorder: ";
                printPreorder(tree);
                cout << endl << endl << "Inorder: ";
                printInorder(tree);
                cout << endl << endl << "Postorder: ";
                printPostorder(tree);
                cout << endl;
                break;
            case 3:
                 min = find_min(tree);
                 cout << "Min = " << min->value << endl;
                break;
            case 4:
                return 0;
                cout << "Bye!";
                break;
            default:
                cout << "please Select 1-4!"<<endl;
                break;
        }
    }
    return 0;
}
