#ifndef __CONTROL_H
#define __CONTROL_H

#include "Corrector.h"
#include <string>
#include <cstdlib>
#include <vector>

using namespace std;

class Control{
	private:
		string nom_dic;
		string nom_tex;
		vector<string> dic;
		vector<string> arr;
		Corrector co;
		FILE *file;
		FILE *file1;
	public:
		Control();
		void cerrar_archivo();
		void leer_dic(string);
		void leer_arr(string);
		void leer_vac(string);

};
#endif
