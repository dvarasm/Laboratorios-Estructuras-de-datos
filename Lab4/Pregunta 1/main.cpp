#include <iostream>
#include <cstdio>
#include <queue>
#include "Fila.h"
#include "Queue.h"

using namespace std;

int main() {
	
	Fila *q1 = new Queue();
	Fila *q3 = new Queue(); 
	queue<int> q2,q4;
	int n;
	printf("Ingrese tamano del Queue:\n");
	scanf("%d",&n);
	int m=(n-1);
	for(int i=0;i<m;i++){
		q3->push(rand()%100);
		q4.push(rand()%100);
	}
	
	clock_t start = clock();
 	for(int i=0;i<n;i++) q2.push(rand()%100);
	printf("Tiempo transcurrido para insertar en Queue (STL):  %f\n", ((double)clock() - start) / CLOCKS_PER_SEC);
  
 	start = clock();
	for(int i=0;i<n;i++) q1->push(rand()%100);
	printf("Tiempo transcurrido para insertar en Queue (implementado): %f\n\n", ((double)clock() - start) / CLOCKS_PER_SEC);

	start = clock();
	q2.size();
	printf("Tiempo transcurrido para obtener el tamano en Queue (STL): %f\n", ((double)clock() - start) / CLOCKS_PER_SEC);

	start = clock();
	q1->size();
	printf("Tiempo transcurrido para obtener el tamano en Queue (implementado): %f\n\n", ((double)clock() - start) / CLOCKS_PER_SEC);
	
	start = clock();
	q2.front();
	printf("Tiempo transcurrido para obtener el 1er elemento en Queue (STL): %f\n", ((double)clock() - start) / CLOCKS_PER_SEC);

	start = clock();
	q1->front();
	printf("Tiempo transcurrido para obtener el 1er elemento en Queue (implementado): %f\n\n", ((double)clock() - start) / CLOCKS_PER_SEC);
	
	start = clock();
	q2.back();
	printf("Tiempo transcurrido para obtener el ultimo elemento en Queue (STL): %f\n", ((double)clock() - start) / CLOCKS_PER_SEC);

	start = clock();
	q1->back();
	printf("Tiempo transcurrido para obtener el ultimo elemento en Queue (implementado): %f\n\n", ((double)clock() - start) / CLOCKS_PER_SEC);

	start = clock();
	q2.empty();
	printf("Tiempo transcurrido para saber si esta vacio en Queue (STL): %f\n", ((double)clock() - start) / CLOCKS_PER_SEC);

	start = clock();
	q1->empty();
	printf("Tiempo transcurrido para saber si esta vacio en Queue (implementado): %f\n\n", ((double)clock() - start) / CLOCKS_PER_SEC);

	start = clock();
	swap(q2,q4);
	printf("Tiempo transcurrido para hacer swap en Queue (STL): %f\n", ((double)clock() - start) / CLOCKS_PER_SEC);
	

	start = clock();
	q1->swap(q3);
	printf("Tiempo transcurrido para hacer swap en Queue (implementado): %f\n\n", ((double)clock() - start) / CLOCKS_PER_SEC);

	start = clock();
	while(1){
		if(q2.empty()==1)break;
		q2.pop();
	}
  	printf("Tiempo transcurrido para eliminar en Queue (STL):  %f\n", ((double)clock() - start) / CLOCKS_PER_SEC);

	start = clock();
	while(1){
		if(q1->empty()==1)break;
		q1->pop();
	}
  	printf("Tiempo transcurrido para eliminar en Queue (implementado):  %f\n", ((double)clock() - start) / CLOCKS_PER_SEC);
	

	
return 0;
}
