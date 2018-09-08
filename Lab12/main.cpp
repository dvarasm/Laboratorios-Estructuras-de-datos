#include <iostream>
#include <algorithm>
#include <vector>
#include <ctime>
#include <cstdio>

using namespace std;

int num[10000];

void generarRandom(int size){
	for(int i=0;i<size;i++) num[i]=i;
    	random_shuffle(num,num+size);
}

int main(){
	srand(time(NULL));
	int tam =10000;
	generarRandom(tam);
	int num2[10000];
	for(int i=0;i<tam;i++)num2[i]=num[i];
	clock_t start = clock();
	sort(num,num+tam);
	printf("Tiempo para ordenar con sort:  %f\n", ((double)clock() - start) / CLOCKS_PER_SEC);
	start = clock();
	stable_sort(num2,num2+tam);
	printf("Tiempo para ordenar con stable_sort:  %f\n", ((double)clock() - start) / CLOCKS_PER_SEC);

return 0;
}
