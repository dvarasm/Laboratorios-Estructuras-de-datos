#ifndef __ARRAYLIST_h
#define __ARRAYLIST_h
#include <iostream>
#include <cstdlib>
#include "Lista.h"

using namespace std;

class ArrayList:public Lista {
    
	private:
	        int *array;
	        int num;
	        int index;
		int element;
        
	public:
		ArrayList(); 
		~ArrayList();
		void push_back(int a);
		int at(int a);
		int size();
};
#endif
