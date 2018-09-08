#include "PriorityQueueADT.h"

using namespace std;

class PQUnsorted:public PriorityQueueADT{
	private:
		int *a;
		int count;
		int index;
		int num;
	public:
		PQUnsorted();
		~PQUnsorted();
		bool empty() = 0;
		int size() = 0;
		int top() = 0;
		void push(int) = 0;
		void pop() = 0;

};
