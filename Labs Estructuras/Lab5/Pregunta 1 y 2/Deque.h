#include "DequeADT.h"
#include <stdlib.h>

using namespace std;

class Deque: public DequeADT{
	private:
		struct nodo{
       			int n;
       			struct nodo *sgte;
			struct nodo *ante;
		};
		typedef struct nodo *Que;
		Que q1;
		int count;

	public:
		Deque();
		bool empty();
		int size();
		int front();
		int back();
		void push_front(int);
		void push_back(int);
		void pop_front();
		void pop_back();


};
