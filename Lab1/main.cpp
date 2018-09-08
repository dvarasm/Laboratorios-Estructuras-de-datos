#include <iostream>
#include "sumar.h"
#include <cstdio>

using namespace std;

int main() {
	int tam;
	
	printf("Tamano del Arreglo\n");
	scanf("%d",&tam);
	int Array[tam];
	printf("Ingrese el arreglo de %d numeros:",tam);

	for(int i=0;i<tam;i++){
		scanf("%d",&Array[i]);
	}
	sumar su(tam);
	su.secuencial(Array);
	su.atras(Array);	

	return 0;
}

sumar::sumar(int tam){	
	max=tam;
}
void sumar::secuencial(int Array[]) {
	int suma=0;
	clock_t start = clock();	
	for (int i=0;i<max;i++){
		suma=suma+Array[i];
	}
	printf("Tiempo transcurrido para suma secuencial: %f\n", ((double)clock() - start) / CLOCKS_PER_SEC);
	printf("suma secuencial: %d\n",suma);
}

void sumar::atras(int Array[]) {
	int suma=0;
	clock_t start = clock();	
	while(max--){
		suma=suma+Array[max];
	}
	printf("Tiempo transcurrido para suma desde atras: %f\n", ((double)clock() - start) / CLOCKS_PER_SEC);
	printf("suma desde atras: %d\n",suma);
}
