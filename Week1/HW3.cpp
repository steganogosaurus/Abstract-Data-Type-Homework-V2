#include <iostream>
using namespace std;
int main(){
	int i,j,k,rows; 
	char a[5][5]={ 
	{'S','T','L','Y','R'}, 
	{'T','H','E','M','E'}, 
	{'A','N','A','G','O'}, 
	{'R','O','P','E','S'},
	{'K','T','T','U','C'}};
	cout << "Input: ";
	cin >> rows;
		for(int j = 0 ; j < 5;j++){
			for(int k = 0;k <= j ;k++){
				cout << a[rows-1][k];
			}
			cout << " ";
		}
}
