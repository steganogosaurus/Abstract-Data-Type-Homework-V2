#include <iostream>
using namespace std;
void showMenu(){
	cout << "===========================" << endl;
	cout << "           MENU" << endl;
	cout << "===========================" << endl;
	cout << "1. Print from front" << endl;
	cout << "2. Print from back" << endl;
	cout << "3. Match data base" << endl;
	cout << "Please choose > ";
}
void printFromFront(char a[][5]){                           
	string str = "";
	for(int i=0;i<5;i++){
		for(int j=0;j<5;j++){
			for(int k=j;k<5;k++){
				str += a[i][k];
				cout << str << " ";
			}	 
			str.clear();
		}	
		cout << endl;		
	}	
}
void printFromBack(char a[][5]){
	string str = "";
	for(int i=0;i<=4;i++){
		for(int j=4;j>=0;j--){
			for(int k=j;k>=0;k--){
				str += a[i][k];
				cout << str << " ";
			}	 
			str.clear();
		}	
		cout << endl;		
	}
}
void matchDatabase(string* db,char a[][5]){
	string str = "";
	int found = 0;
	for(int i=0;i<5;i++){
		for(int j=0;j<5;j++){
			for(int k=j;k<5;k++){
				str += a[i][k];
				cout << str << " ";
				for(int l = 0;l<14;l++){
					if(str == db[l]){
						found++;
						cout << "Found " << found;
						*(db + l) = "";
					}
				}	
				cout << endl;
			}	 
			str.clear();	
		}	
	}
	for(int i=0;i<=4;i++){
		for(int j=4;j>=0;j--){
			for(int k=j;k>=0;k--){
				str += a[i][k];
				cout << str << " ";
				for(int l = 0;l<14;l++){
					if(str == db[l]){
						found++;
						cout << "Found " << found;
						*(db + l) = "";
					}
				}
				cout << endl;
			}	 
			str.clear();
		}		
	}
	cout << endl << "Total =  " << found << endl;	
}
int main(){
	int select; 
	char a[5][5]={ 
	{'S','T','L','Y','R'}, 
	{'T','H','E','M','E'}, 
	{'A','N','A','G','O'}, 
	{'R','O','P','E','S'},
	{'K','T','T','U','C'}};
	string db[14] ={"STLY", "THEME", "THE" , "THEM" , "HE" , "ME" , "AN" , "GO", "AGO", "ROPE", "OPE", "OGA", "CUT", "OR"};
	while(true){
		showMenu();
		cin >> select;
		switch(select){
			case 1:
				 printFromFront(a);
				break;
			case 2:
				printFromBack(a);
				break;
			case 3:
				matchDatabase(db,a);
				break;
			default:
				break;
		}
	}
	return 0;
}
