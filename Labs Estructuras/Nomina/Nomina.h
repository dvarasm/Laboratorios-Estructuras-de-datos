#include "ADTList.h"
#include <cstdlib>
#include <string>
#include <vector>


using namespace std;

class Nomina:public ADTList{
	private:
		struct Jugador{
			char nombre[20];
			char apellido[20];
			int celular;
			char pos[20];
			int goles;
		};
		
		int num_ju;
	public:
		Nomina(int);
		~Nomina();
		void Add();
		void Delete();
		void Data();

};
