#include "PriorityQueueADT.h"

using namespace std;

class PQSorted:public PriorityQueueADT{
	private:
		int *a;
		int count;
		int index;
		int num;	
	public:
		PQSorted();
		~PQSorted();
		bool empty();
		int size();
		int top();
		void push(int);
		void pop();

};
