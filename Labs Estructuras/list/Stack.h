#ifndef __STACK_h
#define __STACK_h

#include "LinkedList.h"
#include "Lista.h"

using namespace std;

class Stack{
	private:
		LinkedList *ll;

	public:
		Stack();
		void push(int n);
		void pop();
		int top();
		int size();
		bool isEmpty();
};
#endif
