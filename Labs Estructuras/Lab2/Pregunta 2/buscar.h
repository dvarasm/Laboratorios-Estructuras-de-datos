#include<vector>
using namespace std;
class buscar {
	private: 
		vector<int> vec;
		int count;
	public:
		buscar();
		void llenar(int n);
		int ite(int n,int m);
		int rec(int n,int m,int x);
};

