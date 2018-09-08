#include "PQHeap.h"
#include <iostream>
#include <cstdlib>

using namespace std;

PQHeap::PQHeap(){
	num =10;
	a= (int *)malloc(num*sizeof(int));
	index=1;
	count=0;
}

bool PQHeap::empty(){
	if(count==0)return true;
	else return false;
}
int PQHeap::size(){
	return count;
}
int PQHeap::top(){
	if(count!=0)return a[1];
}
void PQHeap::push(int n){
	if(index >= num-1){
        	int tmp = num;
        	num = tmp*2;
        	a = (int *)realloc(a,num*sizeof(int));
	}
	a[index]=n;
	//UpHeap
	int tmp = index;
	while(tmp > 1 && a[tmp]< a[tmp/2]){ 
		swap(a[tmp], a[tmp/2]);
		tmp =tmp/2;
	}		
    	index++;
	count++;
}
void PQHeap::pop(){
	swap(a[1],a[count]);
		count--;
		index--;
		//DownHeap
		int first = 1;
		int hijo = 2;
		while(hijo < count){
			if(hijo < count && a[hijo] > a[hijo + 1])hijo++;
			if(a[first] > a[hijo]){
				swap(a[first],a[hijo]);
				first = hijo;
				hijo = 2 * hijo;
			}
			else
				hijo = count;
		}
}

PQHeap::~PQHeap(){
	free(a);
}
