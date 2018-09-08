#include "trie.h"
#include <iostream>
#include <string>
using namespace std;

int main(){
	string s;
	trie t = trie();
	cin >> s;
	t.insert(s);
	//if(t.search(s) == true)cout << "Buena jere" <<endl;

return 0;
}
