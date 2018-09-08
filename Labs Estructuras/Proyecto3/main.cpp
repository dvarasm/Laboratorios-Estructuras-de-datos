#include "control.h"
#include <iostream>
#include <string>

using namespace std;

int main(){
	control C = control();
	string nodos ="Nodes.csv";
	string aristas ="Edge.csv";
	C.leer_archivo(nodos,aristas);
	C.generar_grafo();
	int eleccion;
	cout << endl;
	cout <<"Analisis al Grafo de mi cuenta de Twitter (varas_ssr)" <<endl;
	cout << endl;
	cout<<"Escoja una alternativa "<<endl;
	cout<<"0: Estadisticas"<<endl<<"1: Nodos Aislados"<<endl<<"2: Adyacencia"<<endl<<"3: Salir"<<endl;
	while(cin>>eleccion){
		if(eleccion==3) break;
		else if(eleccion==0) C.analisis();
		else if(eleccion==1) C.nodo_aislado();
		else if(eleccion==2) C.adyacencia();
		else {
			cout<<"Escoja una alternativa correcta."<<endl;
		}
		cout << endl;
		cout <<"Analisis al Grafo de mi cuenta de Twitter (varas_ssr)" <<endl;
		cout << endl;
		cout<<"Escoja una alternativa "<<endl;
		cout<<"0: Estadisticas"<<endl<<"1: Nodos Aislados"<<endl<<"2: Adyacencia"<<endl<<"3: Salir"<<endl;
	}
return 0;
}
