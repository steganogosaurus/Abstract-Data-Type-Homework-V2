#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;
struct record{
	long long id;
	string name;
};
struct SeparateChaining{
	struct record *data;
	struct SeparateChaining *next;
};
struct LinearProbling{
	struct record *data;
};
struct QuardraticProbling{
	struct record *data;
};
struct DoubleHashing{
	struct record *data;
};
int showmenu(){
	int select;
	cout << "===========MENU=========="<<endl;
	cout << "1. Separate Chaining "<<endl;
	cout << "2. Linear Probling  "<<endl;
	cout << "3. Quardratic Probling "<<endl;
	cout << "4. Double Hashing  "<<endl;
	cout << "5. Exit  "<<endl;
	cout << "Please choose > ";
	cin >> select;
	return select;
}
int standardFunction(long long key,int tablesize){
	return key%tablesize;
}
struct SeparateChaining *insertSepChaining(struct SeparateChaining *head,struct record *stu){
	if(head == NULL){
		head = new struct SeparateChaining;
		head->data = stu;
		head->next = NULL;
	}else{
		struct SeparateChaining *node,*p = head;
		node = new struct SeparateChaining;
		while(p->next != NULL){
			p = p->next;
		}
		node->data = stu;
		node->next = NULL;
		p->next = node;	
	}
	return head;
}
void SeparateChaining(int tablesize){
	string data;
	struct SeparateChaining *arrstu[tablesize];
	for(int i = 0 ; i < tablesize ;i++){
		arrstu[i] = NULL;
	}
	ifstream ReadFile("ADT.txt");
	while(!ReadFile.eof()){
		struct record *stu = new struct record;
		ReadFile >> data;
		stringstream ss(data);
		ss >> stu->id;
		ReadFile >> data;
		stu->name = data;
		int index = standardFunction(stu->id,tablesize);
		arrstu[index] = insertSepChaining(arrstu[index],stu);
	}
	cout << "Index id"<<endl <<endl;
	for(int i = 0 ;i < tablesize;i++){
		struct SeparateChaining *p = arrstu[i];
		cout << i << "     ";
		while(p){
			cout << p->data->id << " " << p->data->name << endl;
			p = p->next;
			cout << "      ";
		}
		cout <<endl;
	}
	ReadFile.close();
}
void LinearProbling(int tablesize){
	string data;
	struct LinearProbling *arrLinearstu[tablesize];
	for(int i = 0 ; i < tablesize ;i++){
		arrLinearstu[i] = NULL;
	}
	ifstream ReadFile("ADT.txt");
	while(!ReadFile.eof()){
		struct record *stu = new struct record;
		ReadFile >> data;
		stringstream ss(data);
		ss >> stu->id;
		ReadFile >> data;
		stu->name = data;
		int index = standardFunction(stu->id,tablesize);
		int f = 1;
		while(arrLinearstu[index] != NULL){
			index = (standardFunction(stu->id,tablesize) + (f)) % tablesize;
			if(++f > 100){
				cout << "Error, can not insert data!";
				break;
			}
		}
		(arrLinearstu[index] == NULL)? (arrLinearstu[index] = new struct LinearProbling , arrLinearstu[index]->data = stu) : '\0'; //add data to index
	}
	cout << "Index id"<<endl <<endl;
	for(int i = 0 ;i < tablesize;i++){
		cout << i << "     ";
		if(arrLinearstu[i] == NULL){
			cout << endl;
			continue;
		}
		struct LinearProbling *p = arrLinearstu[i];
		cout << p->data->id << " " << p->data->name << endl;
		cout << "      ";
		cout <<endl;
	}
}
void QuardraticProbling(int tablesize){
	string data;
	struct QuardraticProbling *arrQuardraticstu[tablesize];
	for(int i = 0 ; i < tablesize ;i++){
		arrQuardraticstu[i] = NULL;
	}
	ifstream ReadFile("ADT.txt");
	while(!ReadFile.eof()){
		struct record *stu = new struct record;
		ReadFile >> data;
		stringstream ss(data);
		ss >> stu->id;
		ReadFile >> data;
		stu->name = data;
		int index = standardFunction(stu->id,tablesize);
		int f = 1;
		while(arrQuardraticstu[index] != NULL){
			index = (standardFunction(stu->id,tablesize) + (f*f)) % tablesize;
			if(++f > 100){
				cout << "Error, can not insert data!"<<endl << endl;
				break;
			}
		}
		(arrQuardraticstu[index] == NULL)?(arrQuardraticstu[index] = new struct QuardraticProbling , arrQuardraticstu[index]->data = stu) : '\0'; //add data to index
	}
	cout << "Index id"<<endl <<endl;
	for(int i = 0 ;i < tablesize;i++){
		cout << i << "     ";
		if(arrQuardraticstu[i] == NULL){
			cout << endl;
			continue;
		}
		struct QuardraticProbling *p = arrQuardraticstu[i];
		cout << p->data->id << " " << p->data->name << endl;
		cout << "      ";
		cout <<endl;
	}
}
void DoubleHashing(int tablesize){
	string data;
	struct DoubleHashing *arrDoubleHashingstu[tablesize];
	for(int i = 0 ; i < tablesize ;i++){
		arrDoubleHashingstu[i] = NULL;
	}
	ifstream ReadFile("ADT.txt");
	while(!ReadFile.eof()){
		struct record *stu = new struct record;
		ReadFile >> data;
		stringstream ss(data);
		ss >> stu->id;
		ReadFile >> data;
		stu->name = data;
		int index = standardFunction(stu->id,tablesize);
		int f = 1;
		while(arrDoubleHashingstu[index] != NULL){
			index = (standardFunction(stu->id,tablesize) + f*(7-(stu->id%7))) % tablesize;
			if(++f > 100){
				cout << "Error, can not insert data!"<<endl << endl;
				break;
			}
		}
		(arrDoubleHashingstu[index] == NULL)?(arrDoubleHashingstu[index] = new struct DoubleHashing , arrDoubleHashingstu[index]->data = stu) : '\0'; //add data to index
	}
	cout << "Index id"<<endl <<endl;
	for(int i = 0 ;i < tablesize;i++){
		cout << i << "     ";
		if(arrDoubleHashingstu[i] == NULL){
			cout << endl;
			continue;
		}
		struct DoubleHashing *p = arrDoubleHashingstu[i];
		cout << p->data->id << " " << p->data->name << endl;
		cout << "      ";
		cout <<endl;
	}
}
int main(){
	int tablesize = 5;
	while(true){
		switch(showmenu()){
			case 1:
				SeparateChaining(tablesize);
				break;
			case 2:
				LinearProbling(tablesize);
				break;
			case 3:
				QuardraticProbling(tablesize);
				break;
			case 4:
				DoubleHashing(tablesize);
				break;
			case 5:
				cout << "Bye!";
				return 0;
				break;
			default:
				cout << "u have to choose 1 - 5!";
				break;
		}
	}
	return 0;
}
