#include <iostream>
#include <cstdio>
#include "funciones.h"

using namespace std;

int main() {
	funciones f = funciones();
	int n;
	printf("Numero:\n");
	scanf("%d",&n);
	printf("Ejecuciones de Funcion Recursiva: %d\n",f.rec(n));
	printf("Ejecuciones de Funcion Iterativa: %d\n",f.ite(n));
}
