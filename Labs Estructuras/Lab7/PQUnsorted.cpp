#include"PQUnsorted.h"
#include <iostream>
#include <cstdlib>

using namespace std;

PQUnsorted::PQUnsorted(){
	num =10;
	a = (int *)malloc(num*sizeof(int));
	index=0;
	count=0;
}

bool PQUnsorted::empty(){
	if(count==0)return true;
	else return false;
}
int PQUnsorted::size(){
	return count;
}
int PQUnsorted::top(){
	return a[0];
}
void PQUnsorted::push(int n){
	if(index >= num-1){
        	int tmp = num;
        	num = tmp*2;
        	a = (int *)realloc(a,num*sizeof(int));
	}
	a[index]=n;
	index++;
	count++;
}
void PQUnsorted::pop(){
	if(count!=0){
		
	}
}

PQUnsorted::~PQUnsorted(){
	free(a);
}

