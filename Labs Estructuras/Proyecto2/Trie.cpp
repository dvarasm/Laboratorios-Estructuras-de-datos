#include <iostream>
#include "Trie.h"
#include <string>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

Trie::Trie(){
  raiz = new Nodo();
  raiz->isWord = false;
}

void Trie::dfs(int cursize, string word, Nodo* nodo, vector<string>& result){
  if(nodo->isWord){
    result.push_back(word);
  }
  for(int i = 0; i < 26; i++){
    if(nodo->nodes[i] != NULL){
      dfs(cursize+1, word + (char)(i + 'a'), nodo->nodes[i], result);
    }
  }
}

void Trie::insert(string str){
  Nodo* aux = raiz;
  for(int i = 0; i < str.length(); i++){
    int pos = str[i] - 'a';
    if(aux->nodes[pos] == NULL){
      aux->nodes[pos] = new Nodo();
      aux->nodes[pos]->isWord = false;
    }
    aux = aux->nodes[pos];
  }
  aux->isWord = true;
  
}

bool Trie::search(string word){
  Nodo* aux = raiz;
  for(int i = 0; i < word.length(); i++){
    int pos = word[i] - 'a';
    if(aux->nodes[pos] == NULL){
      return false;
    }
    aux = aux->nodes[pos];
  }
  if(aux->isWord){
    return true;
  }
  return false;
}

Nodo* Trie::getRaiz(){
	return raiz;
}

vector<string> Trie::toVector(){
  vector<string> words;
  dfs(0, "", raiz, words);
  return words;
}

Trie* Trie::toTrie(Nodo* node){
  Trie* trie = new Trie();
  trie->raiz = node;
  return trie;
}
