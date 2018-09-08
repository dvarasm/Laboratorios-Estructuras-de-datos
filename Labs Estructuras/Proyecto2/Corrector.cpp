#include "Corrector.h"
#include "Trie.h"
#include "filtro.h"
#include <iostream>
#include <locale> //variable locale y tolower (transforma mayuscula en minuscula) 
#include <string>
#include <vector>

using namespace std;

Corrector::Corrector (){ 
	t = new Trie();
	f = new filtro();
}

void Corrector::add_dic(vector<string> palabras){
	for(int i=0; i<palabras.size();i++){	
		t->insert(palabras[i]);
	}

}

void Corrector::exis_dic(vector<string> tex){
	for(int i=0; i<tex.size();i++){			
		if(t->search(tex[i])==false)nt.push_back(tex[i]);
	}
}

int Corrector::size_pa_malas(){
	return nt.size();
}
vector <string> Corrector::pa_malas(){
	return nt; 
} 

vector<string> Corrector::sug(int index){
	vector<string> co;
	if(size_pa_malas() > index){
		Trie* trie = f->filtro1(t, nt[index]);
		trie = f->filtro2(trie, nt[index]);
		trie = f->filtro3(trie, nt[index]);
		co = trie->toVector();
	
	}
	return co;
}

string Corrector::mayu_min(string str){
	locale loc;
	for (int i=0; i<str.length(); i++){
		str[i]=tolower(str[i],loc);
	}
	return str;
}
string Corrector::sin_tildes(string str){
	string aux = "";
	for(int i = 0; i < str.length(); i++){
		if(str[i] == -61){
			switch(str[i+1]){
				case -111:
					aux+= "N";
					break;
				case -79:
					aux+= "n";
					break;
				case -95:
					aux += "a";
					break;
				case -87:
					aux += "e";
					break;
				case -83:
					aux += "i";
					break;
				case -77:
					aux += "o";
					break;
				case -70:
					aux += "u";
					break;
				case -127:
					aux += "A";
					break;
				case -119:
					aux += "E";
					break;
				case -115:
					aux += "I";
					break;
				case -109:
					aux += "O";
					break;
				case -102:
					aux += "U";
					break;
			}
			i++;
		}
		else{
			aux += str[i];
		}
	}
	return aux;
}

string Corrector::sololetras(string str) {
	string ret ="";
	for(int i=0; i<str.length(); i++) {
		char letra = str[i];
		if( ((int)letra >=97 && (int)letra <=122) || ( letra==' ') || ((int)letra >=65 && (int)letra <=90) )ret+=letra;
	}
	return ret;
} 


