#include <iostream>
#include "Control.h"

using namespace std;

int main(int argc, char *argv[]){
	
	
	Control co = Control();

	string dic = argv[1];
	string tex = argv [2];
	string correc = argv[3];
	
	co.leer_dic(dic);
	co.leer_arr(tex);
	co.leer_vac(correc);
	co.cerrar_archivo();
	
	return 0;
}
