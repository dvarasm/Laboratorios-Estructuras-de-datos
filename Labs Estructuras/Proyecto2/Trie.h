#ifndef __TRIE_H
#define __TRIE_H

#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>


using namespace std;

typedef struct Nodo{
  bool isWord;
  struct Nodo* nodes[26];
}Nodo;

class Trie{
	private:
		void dfs(int , string , Nodo* , vector<string>& );
		Nodo* raiz;
	public:
		Trie();
		bool search(string);
		void insert(string);
		vector<string> toVector();
		Trie* toTrie(Nodo*);
		Nodo* getRaiz();

};
#endif
