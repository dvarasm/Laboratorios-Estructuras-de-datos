#include <iostream>
#include <cstdlib>
#include <stack>
#include "Fila.h"
using namespace std;

class Queue:public Fila {
    
	private:
        	stack <int> s1;
		stack <int> s2;
	public:
		Queue(); 
		bool empty();
		int size();
		int front();
		int back();
		void push(int);
		void pop();
		void swap(Fila *q);		
};
	
