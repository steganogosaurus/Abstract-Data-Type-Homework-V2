#include <iostream>
#include <time.h>
#include <cstdlib>
#include <queue>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;
//Function
int showmenu();
void createDataFile(int size);
int *readData(int arr[],int size);
void SelectionSort(int size);
void BubbleSort(int size);
void InsertionSort(int size);
void ShellSort(int size);
void merge(int a[],int lpos,int rpos,int rightend);
void MergeSort(int a[],int left,int right);
int partition(int arr[], int low, int high);
void QuickSort(int a[],int low, int high);
void RadixSort(int size);
void heapify(int a[], int N, int i);
void HeapSort(int N);

int showmenu(){
	int select;
	cout << "=========Menu======== " << endl;
	cout << "1) Create data file " << endl;
	cout << "2) Selection Sort" << endl;
	cout << "3) Bubble Sort " << endl;
	cout << "4) Insertion Sort " << endl;
	cout << "5) Shell Sort" << endl;
	cout << "6) Merge Sort" << endl;
	cout << "7) Quick Sort" << endl;
	cout << "8) Radix Sort" << endl;
	cout << "9) Heap Sort" << endl;
	cout << "10) Exit" << endl;
	cout << "Please choose > ";
	cin >> select;
	return select;
}
void createDataFile(int size){
	srand(time(0));
	ofstream datafile("data.txt");
	for (int i = 0; i < size; i++)
		datafile << rand()%10000 << "\n";
	datafile.close();
}
int *readData(int arr[],int size){
	string data;
	try{
		ifstream ReadFile("data.txt");
		for(int i = 0;i < size;i++){
			getline(ReadFile,data);
			stringstream ss(data);
			ss >> arr[i];
			ss.clear();
		}
		ReadFile.close();
	}catch(exception const& e){
		cout << "There was an error: " << e.what() << endl;
	}
	return arr;
}
void SelectionSort(int size){
	//Read Data From "data.txt"
	int *a = new int[size];
	a = readData(a,size);
	//Start SelectionSort
	int min;
	for(int i = 0 ; i < size;i++){
		min = i;
		for(int j = i ;  j < size;j++ ){
			if(a[min] > a[j]){
				min = j;
			}
		}
		swap(a[i],a[min]);
	}
	//End Sort
	//Write SortData to File
	ofstream file("selectionsort.txt");
	for (int i = 0; i < size; i++)
		file << a[i] << "\n";
	file.close();
}
void BubbleSort(int size){
	//Read Data From "data.txt"
	int *a = new int[size];
	a = readData(a,size);
	//Start BubbleSort
	for(int i = 1;i <= size;i++){
		for(int j = size-1 ; j >= i;j--){
			if(a[j] < a[j-1]){
				swap(a[j],a[j-1]);
			}
		}
	}
	//End Sort
	//Write SortData to File
	ofstream file("bubblesort.txt");
	for (int i = 0; i < size; i++)
		file << a[i] << "\n";
	file.close();
}
void InsertionSort(int size){
	//Read Data From "data.txt"
	int *a = new int[size];
	a = readData(a,size);
	//Start InsertionSort
	int j,p,tmp;
	for(p = 1;p < size;p++){
		tmp = a[p];
		for(j=p;j>0&&a[j-1] > tmp;j--){
			a[j] = a[j-1];
		}
		a[j] = tmp;
	}
	//End Sort
	//Write SortData to File
	ofstream file("insertionsort.txt");
	for (int i = 0; i < size; i++)
		file << a[i] << "\n";
	file.close();
}
void ShellSort(int size){
	//Read Data From "data.txt"
	int *a = new int[size];
	a = readData(a,size);
	//Start ShellSort
	for (int gap = size / 2; gap > 0; gap /= 2) {
        // insertion sort 
        for (int i = gap; i < size; i++) {
            int temp = a[i];
            int j;
            for (j = i; j >= gap && a[j - gap] > temp; j -= gap) {
                a[j] = a[j - gap];
            }
            a[j] = temp;
        }
        //End insertion sort 
    }
    //End Sort
    //Write SortData to File
	ofstream file("shellsort.txt");
	for (int i = 0; i < size; i++)
		file << a[i] << "\n";
	file.close();
}
void merge(int a[],int lpos,int rpos,int rightend){
	int i,leftend,numelements,tmppos;
	int tmparr[rightend+1];
	leftend = rpos - 1;
	tmppos = lpos;
	numelements = rightend-lpos+1;
	while(lpos <= leftend && rpos <= rightend){
		(a[lpos] <= a[rpos])? tmparr[tmppos++] = a[lpos++] : tmparr[tmppos++] = a[rpos++];
	}
	while(lpos <= leftend){
		tmparr[tmppos++] = a[lpos++];
	}
	while(rpos <= rightend){
		tmparr[tmppos++] = a[rpos++];
	}
	for(i = 0; i < numelements;i++,rightend--){
		a[rightend] = tmparr[rightend];
	}
}
void MergeSort(int a[],int left,int right){
	int size = right+1;
	//Start MergeSort
	int center;
	if(left < right){
		center = (left+right)/2;
		MergeSort(a,left,center);
		MergeSort(a,center+1,right);
		merge(a,left,center+1,right);
	}
	//End Sort
	//Write SortData to File
	ofstream file("mergesort.txt");
	for (int i = 0; i < size; i++)
		file << a[i] << "\n";
	file.close();
}
int partition(int arr[], int low, int high){
    int pivot = arr[high]; 
    int i = (low - 1);     
    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot){
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}
void QuickSort(int a[],int low, int high){
	int size = high+1;
	//Start QuickSort
	if (low < high) {
        int pivotIndex = partition(a, low, high);
        QuickSort(a, low, pivotIndex - 1);
        QuickSort(a, pivotIndex + 1, high);
    }
    //End Sort
    //Write SortData to File
	ofstream file("quicksort.txt");
	for (int i = 0; i < size; i++)
		file << a[i] << "\n";
	file.close();
}
void RadixSort(int size){
	//Read Data From "data.txt"
	int *a = new int[size];
	a = readData(a,size);
	//Find Loop Length
	int max = a[0], timesSorted=0;
	for(int i=1;i<size;i++){
		if(max < a[i]){
			max = a[i];
		}
	}
	while(max != 0){
		++timesSorted;
		max/=10;
	}
	//Start Radix Sort
	queue<int> head[10];
	int mod=10,div=1;
	for(int index=0;index<timesSorted;index++){
		int headIndex=0;
		for(int j=0;j<size;j++){
			head[a[j]%mod/div].push(a[j]);
		}
		for(int k=0;k<size;k++){
			while(head[headIndex].empty()){
				++headIndex;
			}
			a[k] = head[headIndex].front();
			head[headIndex].pop();
		}
		mod*=10;
		div*=10;
	}
	//End RadixSort
	//Write SortData to File
	ofstream file("radixsort.txt");
	for (int i = 0; i < size; i++)
		file << a[i] << "\n";
	file.close();
}
void heapify(int a[], int N, int i){
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < N && a[l] > a[largest])
        largest = l;
    if (r < N && a[r] > a[largest])
        largest = r;
    if (largest != i) {
        swap(a[i], a[largest]);
        heapify(a, N, largest);
    }
}
void HeapSort(int N){
	//Read Data From "data.txt"
	int *a = new int[N];
	a = readData(a,N);
    // Build heap
    for (int i = N / 2 - 1; i >= 0; i--)
        heapify(a, N, i);
    //Start Heapsort
    for (int i = N - 1; i > 0; i--) {
        swap(a[0], a[i]);
        heapify(a, i, 0);
    }
    //End Sort
    //Write SortData to File
	ofstream file("heapsort.txt");
	for (int i = 0; i < N; i++)
		file << a[i] << "\n";
	file.close();
}
int main(){
	int *a;
	int *a1;
	int size = 2000000;
	while(true){
		switch(showmenu()){
			case 1:
				createDataFile(size);
				break;
			case 2:
				SelectionSort(size);
				break;
			case 3:
				BubbleSort(size);
				break;
			case 4:;
				InsertionSort(size);
				break;
			case 5:
				ShellSort(size);
				break;
			case 6:
				//Read Data From "data.txt"
				a = new int[size];
				a = readData(a,size);
				MergeSort(a,0,size-1);
				break;
			case 7:
				//Read Data From "data.txt"
				a1 = new int[size];
				a1 = readData(a1,size);
				QuickSort(a1,0, size-1);
				break;
			case 8:
				RadixSort(size);
				break;
			case 9:
				HeapSort(size);
				break;
			case 10:
				cout << "Bye!";
				return 0;
				break;
			default:
				cout << "u have to choose 1-10!";
				break;
		}
	}
	return 0;
}
