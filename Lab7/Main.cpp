#include "PQHeap.h"
#include "PQSorted.h"
#include "PQUnsorted.h"
#include <iostream>
#include <vector>
#include <cstdio>
#include <cstdlib>


using namespace std;

void heapify(vector<int> arr, int n, int i){
    int largest = i;
    int l = 2*i + 1;  
    int r = 2*i + 2;  
 
    if (l < n && arr[l] > arr[largest])largest = l;
    if (r < n && arr[r] > arr[largest])largest = r;
    if (largest != i){
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(vector<int> arr){
	int n =arr.size();
	for (int i = n / 2 - 1; i >= 0; i--){
		heapify(arr, n, i);
	}
	for (int i=n-1; i>=0; i--){
		swap(arr[0], arr[i]);
		heapify(arr, i, 0);
	}
}

void insertion_sort (vector<int> arr){
	int length = arr.size();
	int j, temp;	
	for (int i = 0; i < length; i++){
		j = i;
		
		while (j > 0 && arr[j] < arr[j-1]){
			  temp = arr.at(j);
			  arr[j] = arr[j-1];
			  arr.at(j-1) = temp;
			  j--;
			  }
		}
}

void selectionSort(vector<int> arr) {
	int n = arr.size();
	int i, j, minIndex, tmp;    
	for (i = 0; i < n - 1; i++) {
		minIndex = i;
		for (j = i + 1; j < n; j++)
			if (arr[j] < arr[minIndex])
				minIndex = j;
			if (minIndex != i) {
				tmp = arr.at(i);
				arr[i] = arr[minIndex];
				arr.at(minIndex) = tmp;
			}
	}
}

int main(){
	int n,r;
	srand(time(NULL));
	cout<< "Ingrese Tamano del vector"<<endl;
	cin >> n;
	vector <int> num;
	for(int i=0; i<n; i++){
		r = rand()%100;
		num.push_back(r);
	}
	clock_t start = clock();
	heapSort(num);
	printf("Tiempo HeapSort:  %f\n", ((double)clock() - start) / CLOCKS_PER_SEC);
	start = clock();
	insertion_sort(num);
	printf("Tiempo InsertionSort:  %f\n", ((double)clock() - start) / CLOCKS_PER_SEC);
	start = clock();
	selectionSort(num);
	printf("Tiempo SelectionSort:  %f\n", ((double)clock() - start) / CLOCKS_PER_SEC);

return 0;
}
