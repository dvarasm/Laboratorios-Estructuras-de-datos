#ifndef __CORRECTORORTOGRAFICO_H
#define __CORRECTORORTOGRAFICO_H
#include <string>
#include <vector>

using namespace std;

class CorrectorOrtografico{
	public:
		virtual string mayu_min(string)=0;
		virtual string sololetras(string)=0;
		virtual string sin_tildes(string)=0;
		virtual void add_dic(vector<string>)=0;
		virtual void exis_dic(vector<string>)=0;

};
#endif
