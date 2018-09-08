#include "filtro.h"
#include "Trie.h"
#include <cmath>
using namespace std;
filtro::filtro(){

}


void filtro::dfs2(int cursize, string word, Nodo* nodo, vector<string>& result){
  if(nodo->isWord){
    result.push_back(word);
  }
  for(int i = 0; i < 26; i++){
    if(nodo->nodes[i] != NULL){
      dfs2(cursize+1, word + (char)(i + 'a'), nodo->nodes[i], result);
    }
  }
}

void filtro::dfs(int reqsize, int cursize, string word, Nodo* nodo, Trie* result){
  if(fabs(cursize-reqsize) <= 2 && nodo -> isWord){
    result->insert(word);
  }
  for(int i = 0; i < 26; i++){
    if(nodo->nodes[i] != NULL){
      dfs(reqsize, cursize+1, word + (char)('a'+i), nodo->nodes[i], result);
    }
  }
}

Trie* filtro::filtro1(Trie* t, string word){
  Trie* trie = new Trie();
  dfs(word.length(), 0, "", t->getRaiz(), trie);
  return trie;
}

Trie* filtro::filtro2(Trie* t, string word){
  Trie* result = new Trie();
  Nodo* aux = t->getRaiz();
  for(int i = 0; i < word.length(); i++){
    int pos = word[i] - 'a';
    if(aux->nodes[pos] != NULL){
      aux = aux->nodes[pos];
      if(i == word.length() -1){
	vector<string> sufijos = t->toTrie(aux)->toVector();
	for(int j = 0; j < sufijos.size(); j++){
	  result->insert(word + sufijos[j]);
	}
      }
    }
    else
      break;
  }
 
  for(int i = 3; i < word.length() ; i++){
    string str = word.substr(0, i);
    if(t->search(str))
      result->insert(str);
  }
  return result;
}

Trie* filtro::filtro3(Trie* t, string word){
  Trie* result = new Trie();
  vector<string> words = t->toVector();
  for(int i = 0; i < words.size(); i++){
    string temp = words[i];
    int count = 0;
    for(int j = 0; j < min(word.length(), temp.length()); j++){
      if(temp[j] != word[j]){
	count++;
	if(count > 2)
	  break;
      }
    }
    if(count <= 2){
      result->insert(temp);
    }
  }
  return result;
}
