#include "grafo.h"
#include <iostream>

using namespace std;

int main(){
	grafo* g = new grafo(); 
	
	int ca_nodo,ca_arista;
	int nodoi,nodof;

	cin >> ca_nodo;
	cin >> ca_arista;
	
	for(int i =1; i<= ca_nodo; i++){
		g->insertar_nodo(i);
	}

	for(int i=0; i < ca_arista;i++){
		cin >> nodoi >> nodof;
		g->insertar_arista(nodoi,nodof);	
	}
	g->mostrar_grafo();
	g->bfs(1,7);
	g->dfs(1);
	
return 0;
}
