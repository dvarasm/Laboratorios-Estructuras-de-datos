#include "MapHash.h"
#include <string>
#include <cstdlib>
#include <iostream>

using namespace std;

MapHash::MapHash(){
	tam=13;
	count=0;
	map =new pair <string,int>[tam];
	for(int i=0; i<tam;i++){
		map[i]=make_pair("",0);	
	}
}

int MapHash::Hash2(string k){
	int suma=0;
	int key,z=33;
	for(int i=0; i<k.size();i++){
		suma = suma + ((int)k[i])*(z^i);
	}
	key= suma%tam;
	return key;
}
int MapHash::Hash1(string k){
	int suma=0;
	int key;
	for(int i=0; i<k.size(); i++){
		suma = suma+(int)k[i];
	}
	key= suma%tam;
	return key;
}

bool MapHash::empty(){
	if(count==0)return true;
	else return false;
}
int MapHash::size(){
	return count;
}
void MapHash::insert(string k,int v){
	if(count<tam ){
		int key,tmp=0;
		key = Hash1(k);
		for(int i=0; i<tam ;i++){
			if(map[i].first.compare(k)==0){
				tmp++;
				break;
			}		
		}
		if(tmp==0){
			if(map[key].first =="" && map[key].second == 0){
				map[key]=make_pair(k,v);
				count++;
			}
			else {		
				key = Hash2(k);
				if(map[key].first =="" && map[key].second == 0){
					map[key]=make_pair(k,v);
					count++;
				}
				else {
					int i=key+1;
					while(1){
						if(i<tam && map[i].first =="" && map[i].second == 0) {
							map[i]=make_pair(k,v);
							count++;
							break;
						}
						if(i>=tam && map[i-tam].first =="" && map[i-tam].second == 0){
							map[i-tam]=make_pair(k,v);
							count++;
							break;
						}
						i++;
					}
				}	
			}
		}
	}	
	else {
		pair <string,int> tmp[tam];
		for(int i=0; i<tam;i++){
			tmp[i]=map[i];
		}
		int m = tam;
		tam = (2*tam)-1;
		map =new pair <string,int>[tam];
		for(int i=0; i<tam;i++){
			map[i]=make_pair("",0);	
		}
		int key,j=0;
		while(j<m){		
			key = Hash1(tmp[j].first);
			if(map[key].first =="" && map[key].second == 0){
				map[key]=make_pair(tmp[j].first,tmp[j].second);
				j++;
			}	
			else{
				int i=key+1;
				while(1){
					if(i<m && map[i].first =="" && map[i].second == 0) {
						map[i]=make_pair(tmp[j].first,tmp[j].second);
						j++;
						break;
					}
					if(i>=m && map[i-m].first =="" && map[i-m].second == 0){
						map[i-m]=make_pair(tmp[j].first,tmp[j].second);
						j++;
						break;
					}
					i++;
				}
			}
		}
		insert(k,v);
	}
}

int MapHash::at(string k){
if(count!=0){
	for(int i=0;i<tam;i++){
		if(map[i].first.compare(k)==0){
			return map[i].second;
		}
	}
	cout << "Key no Existe"<< endl;
}
else cout<<"Tabla Vacia!!!"<<endl;
}
void MapHash::erase(string k){
	if(count!=0){
		for(int i=0;i<tam;i++){
			if(map[i].first.compare(k)==0){
				map[i]=make_pair("",0);
				count--;
				break;
			}
		}
		cout << "Key no Existe" << endl;
	}	
	else cout<<"Tabla Vacia!!!"<<endl;
}
