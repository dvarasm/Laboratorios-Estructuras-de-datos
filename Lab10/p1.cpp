#include <iostream>
#include <map>
#include <unordered_map>
#include <cstdio>
#include <iomanip> 
using namespace std;

int main(){
	map<char,int> ma;
	unordered_map<char,int> uno_ma;
	
	int j=0;
	clock_t start = clock();
	for(char i= 'z'; i>='a';i--){
		ma.insert(pair<char,int>(i,j));
		j++;	
	}
	float s = ((double)clock() - start) / CLOCKS_PER_SEC;
	printf("Tiempo transcurrido para insertar en Map (STL): %f\n",s);
	
	
	int k=0;
	start = clock();
	for(char i= 'z'; i>='a';i--){
		uno_ma.insert(pair<char,int>(i,k));
		k++;	
	}
	float s1 = ((double)clock() - start) / CLOCKS_PER_SEC;
	printf("Tiempo transcurrido para insertar en Unordered Map (STL):  %f\n", s1);

	start = clock();
	ma.at('n');
	printf("Tiempo transcurrido para buscar en Map (STL):  %f\n", ((double)clock() - start) / CLOCKS_PER_SEC);

	start = clock();	
	uno_ma.at('n');
	printf("Tiempo transcurrido para buscar en Unordered Map (STL):  %f\n", ((double)clock() - start) / CLOCKS_PER_SEC);
	return 0;
}
