#ifndef __FILTRO_H
#define __FILTRO_H

#include "Trie.h"

class filtro{
public:
	filtro();
	void dfs(int, int,string, Nodo*,Trie*);
	void dfs2(int, string, Nodo*, vector<string>&);
	Trie* filtro1(Trie*, string);
	Trie* filtro2(Trie*, string);
	Trie* filtro3(Trie*, string);
};

#endif
