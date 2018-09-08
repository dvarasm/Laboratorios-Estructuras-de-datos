

using namespace std;

class ADTheap{
	public:
		virtual bool empty() = 0;
		virtual int size() = 0;
		virtual int min() = 0;
		virtual void insert(int) = 0;
		virtual void removeMin() = 0;


};
