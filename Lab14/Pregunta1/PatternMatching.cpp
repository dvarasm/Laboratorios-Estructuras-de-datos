#include "PatternMatching.h"
#include <string>
#include <algorithm>

using namespace std;

PatternMatching::PatternMatching(){

}

int PatternMatching::Fuerza_Bruta(string texto, string patron){
	int n = texto.size();
	int m = patron.size();

	for(int i=0; n - m; i++){
		int j = 0;
		while (j < m && texto.at(i + j) == patron.at(j)){
			j = j + 1;
			if  (j == m) return  i;
		}
	}
	return  -1;
}

int* PatternMatching::Failure_Function(string patron){
	int m = patron.size();
	int *F=(int*)malloc(m*sizeof(int));
	F[0]=0;
	int i = 1;
	int j = 0;
	while (i < m){
		if (patron.at(i) == patron.at(j)){
			F[i] = j + 1;
			i = i + 1;
			j = j + 1;
		}
		else if  (j > 0) j = F[j - 1];
		else{
			F[i] = 0; 
			i = i + 1;
		}
	}
	return F;
}

int PatternMatching::Boyer_Moore(string texto, string patron){
	int n = texto.size();
	int m = patron.size();
	
	int *L = Failure_Function(patron);

	int i = m - 1;
	int j = m - 1;
	while(i < n - 1){
		if (texto.at(i) == patron.at(j)){
			if(j == 0)return  i;
			else{
				i = i - 1;
				j = j - 1;
			}
		}
		else{
			int l = L[texto.at(i)];
			int tmp = min(j,1+l);
			i = i + m - tmp;
			j = m - 1;
		}
	}
	return  -1;
}
