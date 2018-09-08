#include "PatternMatching.h"
#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

int main(){

PatternMatching pm = PatternMatching();

string texto = "abacaabadcabacabaabb";
string patron = "abacab";

cout <<"Texto: "<< texto << endl;
cout <<"Patron: "<< patron<<endl;

clock_t start = clock();
cout <<"Primer Match FB: "<< pm.Fuerza_Bruta(texto,patron) << endl;
printf("Tiempo Fuerza Bruta:  %f\n", ((double)clock() - start) / CLOCKS_PER_SEC);
start = clock();
cout <<"Primer Match BM: "<<pm.Boyer_Moore(texto,patron) << endl;
printf("Tiempo Boyer Moore:  %f\n", ((double)clock() - start) / CLOCKS_PER_SEC);

return 0;
}
