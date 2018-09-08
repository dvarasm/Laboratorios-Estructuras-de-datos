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

}

PQSorted::~PQSorted(){
	free(a);
}
