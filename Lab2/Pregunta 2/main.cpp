#include <iostream>
#include <cstdio>
#include "buscar.h"
#include <vector>
#include <algorithm>

using namespace std;

int main(){

buscar b = buscar();
int n,m;
printf("Ingrese Tamano del Vector:\n");
scanf("%d",&n);
printf("Ingrese %d Numeros al Vector:\n",n);
b.llenar(n);
printf("Numero a buscar:\n");
scanf("%d",&m);
printf("Ejecuciones de Funcion Recursiva: %d\n",b.rec(0,n-1,m));
printf("Ejecuciones de Funcion Iterativa: %d\n",b.ite(n,m));
return 0;
}
