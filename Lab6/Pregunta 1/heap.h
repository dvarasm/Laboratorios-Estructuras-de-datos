#include "ADTheap.h"

using namespace std;

class heap:public ADTheap{
	private:
		int *h;
		int index;
		int count;
		int num;
	public:
		heap();
		~heap();
		bool empty();
		int size();
		int min();
		void insert(int);
		void removeMin();
};
