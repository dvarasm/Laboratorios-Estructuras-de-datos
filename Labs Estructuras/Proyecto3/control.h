#include <fstream>
#include "grafo.h"
#include <string>
#include <cstdlib>
#include <vector>
#include <utility>


using namespace std;

struct data{
	string label;
	int ID;
	int friends;
	int followers;
	int tweets;
};

class control{
	private:
		grafo *G;
		pair<int,int> ari[3309];
		struct data datos[308];
		FILE *file;
		FILE *file1;
		int num_nodos;
		int num_aristas;
	public:
		control();
		void mostrar();
		void generar_grafo();
		void leer_archivo(string,string);
		void analisis();
		void nodo_aislado();
		void adyacencia();
};
