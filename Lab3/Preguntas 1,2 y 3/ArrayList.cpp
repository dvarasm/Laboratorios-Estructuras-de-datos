#include <iostream>
#include <cstdlib>
#include "ArrayList.h"

using namespace std;

ArrayList::ArrayList(){
        num=10;
        array = (int *)malloc( num*sizeof(int) );
        index=0;
	element=0;
}

void ArrayList::push_back(int n){
    array[index]=n;
    index++;
    element++;
    if(index >= num-1){
        int tmp=num;
        num = tmp*2;
        array = (int *)realloc(array,num*sizeof(int));
    }
}

int ArrayList::at(int n){
    return array[n];
}

int ArrayList::size(){
    return element;
}

ArrayList::~ArrayList(){
	free(array);
}
