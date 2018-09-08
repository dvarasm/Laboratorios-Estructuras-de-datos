#include "Lista.h"
#include <iostream>
#include <stdlib.h>

using namespace std;

class LinkedList:public Lista {
	private:
		struct nodo{
       			int n;
       			struct nodo *sgte;
		};
		typedef struct nodo *Llista;
		Llista list;
		int element;
	public:
		LinkedList(); 
		void push_back(int a);
		int at(int a);
		int size();
};
