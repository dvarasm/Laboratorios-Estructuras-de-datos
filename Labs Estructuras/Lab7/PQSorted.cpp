#include "PQSorted.h"
#include <iostream>
#include <cstdlib>

using namespace std;

PQSorted::PQSorted(){
	num =10;
	a = (int *)malloc(num*sizeof(int));
	index=0;
	count=0;
}

bool PQSorted::empty(){
	if(count==0)return true;
	else return false;
}
int PQSorted::size(){
	return count;
}
int PQSorted::top(){
	return a[0];
}
void PQSorted::push(int n){
	if(index >= num-1){
        	int tmp = num;
        	num = tmp*2;
        	a = (int *)realloc(a,num*sizeof(int));
	}
	a[index]=n;
	index++;
	count++;
}
void PQSorted::pop(){
	int menor = a[0];
	int pos_menor; 
	for (int i=1;i<index;i++) { 
		if (a[i] < menor){ 
			menor = a[i]; 
			pos_menor = i; 
		} 
	}
	int tmp[index];
	for(int i=0;i<index;i++)tmp[i]=a[i];
	int j=0;
	for(int i=0;i<index-1;i++){
		if(i!=pos_menor){
			a[j]=tmp[j];
			j++;
		}
	} 
	index--;
	count--;
}

PQSorted::~PQSorted(){
	free(a);
}
