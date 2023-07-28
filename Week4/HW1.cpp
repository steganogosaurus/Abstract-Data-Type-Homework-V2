#include <iostream>
using namespace std;
int P_1 = 0,P_2 = 0;
struct record {
	int value;
	int pow;
	struct record *next;
};
void pol_assemble(struct record *head){
	if(head->pow == 0)
		cout << head->value;
	else if(head->pow == 1)
		cout << head->value << "x";
	else
		cout << head->value << "x^"<<head->pow;
	if(head->next == NULL)
		cout << "";
	else
		cout << " + ";
}
void addingPolynomials(struct record *head_1,struct record *head_2){
	int i = 0,count;
	struct record *p_1 = head_1;
	struct record *p_2 = head_2;
	if(P_1 > P_2)
		count = P_1;
	else
		count = P_2;
	while(i < count){
		if(p_2 == NULL && p_1 != NULL ){
			pol_assemble(p_1);
			p_1 = p_1->next;
		}else if(p_1 == NULL && p_2 != NULL ){
			pol_assemble(p_2);
			p_2 = p_2->next;
		}else{
			if(p_1->pow != p_2->pow){
				if(p_1->pow > p_2->pow){
					pol_assemble(p_1);
					p_1 = p_1->next;
				}else{
					pol_assemble(p_2);
					p_2 = p_2->next;
				}
				count++;
			}else{
				cout << p_1->value + p_2->value << "x^" << p_1->pow;
				cout << " + ";
				p_1 = p_1->next;
				p_2 = p_2->next;
			}	
		}
		i++;
	}
}
struct record *insert(struct record *head,int data,int pow){
	struct record *node,*p;
	if(head == NULL){		
		head = new struct record;
		head->value = data;
		head->pow = pow;
		head->next = NULL;
	}else{
		node = new struct record;
		node->value = data;
		node->pow = pow;
		p = head;
		while(p->next != NULL)
			p = p->next;
		if(p->next == NULL){
			node->next = NULL;
			p->next = node;
		}
	}
	return head;
}
int main(){
	int data,pow;
	struct record *head_1 = NULL;
	struct record *head_2 = NULL;
	cout << "Input P1 : ";
	do{
		cin >> data;
		if (data < 0)
			break;
		cin >> pow;
		P_1++;
		head_1 = insert(head_1,data,pow);
	}while(data >= 0);
	cout << "Input P2 : ";
	do{
		cin >> data;
		if (data < 0)
			break;
		cin >> pow;
		P_2++;
		head_2 = insert(head_2,data,pow);
	}while(data >= 0);
	addingPolynomials(head_1,head_2);
    return 0;
}
