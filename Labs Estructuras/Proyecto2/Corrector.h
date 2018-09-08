#ifndef __CORRECTOR_H
#define __CORRECTOR_H
#include "Trie.h"
#include "filtro.h"
#include "CorrectorOrtografico.h"
#include <string>
#include <vector>
using namespace std;

class Corrector:public CorrectorOrtografico{
	private:
		vector<string> nt;
		Trie *t;
		filtro *f;
	public:

		Corrector();
		int size_pa_malas();
		vector <string> pa_malas();
		vector<string> sug(int);
		string mayu_min(string);
		string sololetras(string);
		string sin_tildes(string);
		void add_dic(vector<string>);
		void exis_dic(vector<string>);
		

};

#endif
