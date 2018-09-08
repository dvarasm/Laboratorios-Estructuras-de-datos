#ifndef __TRIE_H
#define __TRIE_H

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
using namespace std;

	typedef struct nodo{		
		bool esHoja;
		int numeroPalabras;
		struct nodo* palabra[27];
		}Nodo;
		

class trie{

	private:
		Nodo *cabeza; 
		int numeroPalabras;
	public:
		trie();
		void insert(string);
		bool search(string);
};
#endif
