#ifndef __MAPADT_H
#define __MAPADT_H

#include <string>

using namespace std;

class MapADT{
	public:
		virtual bool empty() = 0;
		virtual int size() = 0;
		virtual void insert(string,int) = 0;
		virtual int at(string) = 0;
		virtual void erase(string) = 0;
};
#endif
