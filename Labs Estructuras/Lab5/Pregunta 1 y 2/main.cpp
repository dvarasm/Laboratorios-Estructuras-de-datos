#include <iostream>
#include <cstdio>
#include <deque>
#include "DequeADT.h"
#include "Deque.h"

int main(){

	Deque D = Deque();
	deque<int> De;
	
	int n;
	printf("Ingrese tamano de la Deque:\n");
	scanf("%d",&n);

	clock_t start = clock();
 	for(int i=0;i<n/2;i++) De.push_front(rand()%100);
	printf("Tiempo transcurrido para insertar al principio en Deque (STL):  %f\n", ((double)clock() - start) / CLOCKS_PER_SEC);
  
 	start = clock();
	for(int i=0;i<n/2;i++) D.push_front(rand()%100);
	printf("Tiempo transcurrido para insertar al principio en Deque (implementado): %f\n\n", ((double)clock() - start) / CLOCKS_PER_SEC);

	start = clock();
 	for(int i=0;i<n/2;i++) De.push_back(rand()%100);
	printf("Tiempo transcurrido para insertar al final en Deque (STL):  %f\n", ((double)clock() - start) / CLOCKS_PER_SEC);
  
 	start = clock();
	for(int i=0;i<n/2;i++) D.push_back(rand()%100);
	printf("Tiempo transcurrido para insertar al final en Deque (implementado): %f\n\n", ((double)clock() - start) / CLOCKS_PER_SEC);

	start = clock();
	De.size();
	printf("Tiempo transcurrido para obtener el tamano en Deque (STL): %f\n", ((double)clock() - start) / CLOCKS_PER_SEC);

	start = clock();
	D.size();
	printf("Tiempo transcurrido para obtener el tamano en Deque (implementado): %f\n\n", ((double)clock() - start) / CLOCKS_PER_SEC);
	
	start = clock();
	De.front();
	printf("Tiempo transcurrido para obtener el 1er elemento en Deque (STL): %f\n", ((double)clock() - start) / CLOCKS_PER_SEC);

	start = clock();
	D.front();
	printf("Tiempo transcurrido para obtener el 1er elemento en Deque (implementado): %f\n\n", ((double)clock() - start) / CLOCKS_PER_SEC);
	
	start = clock();
	De.back();
	printf("Tiempo transcurrido para obtener el ultimo elemento en Deque (STL): %f\n", ((double)clock() - start) / CLOCKS_PER_SEC);

	start = clock();
	D.back();
	printf("Tiempo transcurrido para obtener el ultimo elemento en Deque (implementado): %f\n\n", ((double)clock() - start) / CLOCKS_PER_SEC);

	start = clock();
	De.empty();
	printf("Tiempo transcurrido para saber si esta vacio en Deque (STL): %f\n", ((double)clock() - start) / CLOCKS_PER_SEC);

	start = clock();
	D.empty();
	printf("Tiempo transcurrido para saber si esta vacio en Deque (implementado): %f\n\n", ((double)clock() - start) / CLOCKS_PER_SEC);

	start = clock();
	De.pop_front();
  	printf("Tiempo transcurrido para eliminar 1er elemento en Deque (STL):  %f\n", ((double)clock() - start) / CLOCKS_PER_SEC);

	start = clock();
	D.pop_front();
  	printf("Tiempo transcurrido para eliminar 1er elemento en Deque (implementado):  %f\n\n", ((double)clock() - start) / CLOCKS_PER_SEC);
	
	start = clock();
	De.pop_back();
  	printf("Tiempo transcurrido para eliminar ultimo elemento en Deque (STL):  %f\n", ((double)clock() - start) / CLOCKS_PER_SEC);

	start = clock();
	D.pop_back();
  	printf("Tiempo transcurrido para eliminar ultimo elemento en Deque (implementado):  %f\n", ((double)clock() - start) / CLOCKS_PER_SEC);

return 0;
}
