#include <iostream>
using namespace std;
int main(){
	struct record{
		int value;
		struct record *next;
	};
	struct record *p;
	p = new struct record;
	cout << "Enter: ";
	cin >> p->value;
	cout << "Value = " << p->value;
	return 0;
}
