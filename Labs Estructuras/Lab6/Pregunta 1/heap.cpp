#include "heap.h"
#include <iostream>
#include <cstdlib>

using namespace std;

heap::heap(){
	num =10;
	h= (int *)malloc(num*sizeof(int));
	index=1;
	count=0;
}

bool heap:: empty(){
	if(count==0)return true;
	else return false;
}

int heap::size(){
	for(int i=1;i<=count;i++)cout << h[i]<<endl;
	return count;
}

int heap::min(){
	if(count!=0)return h[1];
}

void heap::insert(int n){
	if(index >= num-1){
        	int tmp = num;
        	num = tmp*2;
        	h = (int *)realloc(h,num*sizeof(int));
	}
	h[index]=n;
	//UpHeap
	int tmp = index;
	while(tmp > 1 && h[tmp]< h[tmp/2]){ 
		swap(h[tmp], h[tmp/2]);
		tmp =tmp/2;
	}		
    	index++;
	count++;
}

void heap::removeMin(){
	if(count>1){
		//cout << "min: "<<h[1]<<" count: "<<h[count]<<endl;
		swap(h[1],h[count]);
		count--;
		index--;
		//DownHeap
		int first = 1;
		int hijo = 2;
		while(hijo < count){
			if(hijo < count && h[hijo] > h[hijo + 1])hijo++;
			if(h[first] > h[hijo]){
				swap(h[first],h[hijo]);
				first = hijo;
				hijo = 2 * hijo;
			}
			else
				hijo = count;
		}
	}
	else{ 
		if(count!=0){
			count--;
			index--;
		}
	}
	
}

heap::~heap(){
	free(h);
}
