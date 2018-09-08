#include "MapADT.h"
#include <string>
#include <utility>
using namespace std;

class MapHash: public MapADT{
	private:
		pair <string,int>* map;
		int count;
		int tam;
		int Hash1(string);
		int Hash2(string);
	public:
		MapHash();
		bool empty();
		int size();
		void insert(string,int);
		int at(string);
		void erase(string);
};
