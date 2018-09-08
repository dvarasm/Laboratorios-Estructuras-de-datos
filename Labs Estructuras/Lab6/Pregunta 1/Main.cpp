#include "heap.h"
#include <iostream>

int main(){

	heap h=heap();

	for(int i=0;i<10;i++)h.insert(i);
	cout << "D;"<<endl;
	for(int i=0;i<10;i++){
		h.size();
		h.removeMin();
	}
return 0;
}

