#include "ADTMap.h"
#include <string>

using namespace std;

class MapHash: public ADTMap{
	private:
		int map[100];
		string s[100];
		int count;
	public:
		MapHash();
		bool empty();
		int size();
		void insert(string,int);
		int at(string);
		void erase(string);
};
