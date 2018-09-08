#include <iostream>
#include "trie.h"
#include <cstdlib>
#include <string>
#include <cstdio>
using namespace std;

trie::trie(){
	
	numeroPalabras=0;
	cabeza=NULL;	
}


void trie::insert(string palabra){
	Nodo *nodoAux=new Nodo();
	nodoAux=cabeza;
	nodoAux->numeroPalabras++;
	for(int i=0;i<palabra.length();i++){
		int letra=(int)palabra[i]-(int)'a';
		if(nodoAux->palabra[letra]==NULL){
			nodoAux->palabra[letra]=new Nodo();
		}
		nodoAux->palabra[letra]->numeroPalabras++;
		nodoAux=nodoAux->palabra[letra];
	}
	nodoAux->esHoja=true;
}

bool trie::search(string palabra){
	nodo *nodoAux=new nodo();
	nodoAux=cabeza;
	for(int i=0;i<palabra.length();i++){
		if(nodoAux->palabra[((int)palabra[i]-(int)'a')]==NULL){
			return false;
		}
	nodoAux=nodoAux->palabra[((int)palabra[i]-(int)'a')];
	}
	return nodoAux->esHoja;
}

