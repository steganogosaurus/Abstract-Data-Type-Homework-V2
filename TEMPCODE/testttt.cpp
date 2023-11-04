#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

int main()
{
    int n;
    cin >> n;

    int a;
    cin >> a;

    char in1;
    cin >> in1;

    a= a+1;
   
    for(int i=1 ; i<=n ; i++){
        for(int z=0 ; z<a ; z++){
            cout << " " ;
        }
            for(int j=0 ; j<i ; j++){
                cout << in1;
            }
            cout << endl;
            a++;
    }


    // Write an answer using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;
}
