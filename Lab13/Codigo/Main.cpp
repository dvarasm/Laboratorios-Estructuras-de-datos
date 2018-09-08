#include "PQHeap.h"
#include "PQSorted.h"
#include "QuickSort.h"
#include <iostream>
#include <vector>
#include <cstdio>
#include <cstdlib>

using namespace std;

int main(){
	
	PQHeap *h = new PQHeap();
	PQSorted *s = new PQSorted();
	QuickSort *q = new QuickSort();
	
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
	for(int i=0; i<n; i++){
		s->push(num.at(i));
	}
	printf("Tiempo PQSorted:  %f\n", ((double)clock() - start) / CLOCKS_PER_SEC);
	start = clock();
	for(int i=0; i<n; i++){
		h->push(num.at(i));
	}
	printf("Tiempo PQHeap:  %f\n", ((double)clock() - start) / CLOCKS_PER_SEC);
	start = clock();
	for(int i=0; i<n; i++){
		q->quickSort(num,0,num.size()-1);
	}
	printf("Tiempo QuickSort:  %f\n", ((double)clock() - start) / CLOCKS_PER_SEC);

return 0;
}
