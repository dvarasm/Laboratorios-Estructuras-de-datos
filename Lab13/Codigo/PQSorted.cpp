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
	int j,tmp;
        for (int i = 1; i < index; i++) {
                j = i;
                while (j > 0 && a[j - 1] > a[j]) {
                        tmp = a[j];
                        a[j] = a[j - 1];
                        a[j - 1] = tmp;
                        j--;
                }
        }
	index++;
	count++;
}
void PQSorted::pop(){
	int *tmp=(int*)malloc(index*sizeof(int));
	for(int i=0;i<index;i++)tmp[i]=a[i];
	int j=1;
	for(int i=0;i<index-1;i++){
		a[0]=tmp[j];
		j++;
	} 
	free(tmp);
	index--;
	count--;
}

PQSorted::~PQSorted(){
	free(a);
}
