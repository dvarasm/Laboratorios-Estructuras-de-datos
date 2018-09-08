#ifndef __LINKEDLIST_h
#define __LINKEDLIST_h

#include "Lista.h"
#include <iostream>

using namespace std;

class LinkedList:public Lista {
	private:
		struct nodo{
       			int n;
       			struct nodo *sgte;
		};
		typedef struct nodo *Llista;
		Llista list, head;
		int element;
	public:
		LinkedList(); 
		void pop_front();
		bool isEmpty();
		void push_back(int a);
		void push_front(int a);
		int at(int a);
		int size();
};
#endif
