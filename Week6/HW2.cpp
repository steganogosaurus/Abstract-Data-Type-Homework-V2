#include <iostream>
using namespace std;
struct record{
	int value;
	struct record *next;
};
struct frontback{
	struct record *front;
	struct record *back;
};
struct frontback enqueue (struct record *front,struct record *back,int data){
	struct record *node,*p;
	struct frontback box;
	if(front == NULL && back == NULL){
		front = new struct record;
		front->value = data;
		front->next = NULL;
		back = front;
	}else{
		node = new struct record;
		node->value = data;
		node->next = front;
		back->next = node;
		back = node;
	}
	box.front = front;
	box.back = back;
	return box;
}
struct frontback dequeue(struct record *front,struct record *back){
	struct record *temp;
	struct frontback box;
	if(front == NULL){
		cout << "Empty! Cant Dequeue"<<endl;
	}else{
		temp = front;
		front = front->next;
		back->next = front;
		if(front == NULL){
			box.front = NULL;
			box.back = NULL;
			return box;
		}
		delete temp;
	}
	box.front = front;
	box.back = back;
	return box;
}
int josephus(int m,int n ,struct frontback box){
	int count_m = 0 , count_del = 0;
	struct record *front = NULL,*back = NULL;
	front = box.front;
	back = box.back;
	while(count_del != n-1){
		if(count_m == m){
			count_del++;
			box = dequeue(front,back);
			front = box.front;
			back = box.back;
			count_m = 0;
		}else{
			count_m++;
			front = front->next;
			back = back->next;
		}
	}
	return front->value;
}
int main(){
	int m,n;
	struct record *front = NULL,*back = NULL;
	struct frontback box;
	cout << "Input M: ";
	cin >> m;
	cout << "Input N: ";
	cin >> n;
	for(int i = 1;i<=n;i++){
		box = enqueue(front,back,i);
		front = box.front;
		back = box.back;
	}
	cout << "Winner is : " << josephus(m,n,box);
	return 0;
}
