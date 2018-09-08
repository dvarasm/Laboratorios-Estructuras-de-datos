#include "MapHash.h"
#include <string>
#include <cstdlib>
#include <iostream>

using namespace std;

MapHash::MapHash(){
	for(int i=0; i<100;i++){
		map[i]=0;	
	}
	count=0;
}

bool MapHash::empty(){
	if(count==0)return true;
	else return false;
}
int MapHash::size(){
	return count;
}
void MapHash::insert(string k,int v){
if(count!=100){
	int suma=0;
	int key;
	for(int i=0; i<k.size(); i++){
		suma = suma+(int)k[i];
	}
	key= suma%100;
	cout << key <<endl;
	if(map[key]==0){
		map[key]=v;
		s[key]=k;
		count++;
	}
	
	else{
		int i=key+1;
		while(1){
			if(i<=100 && map[i]==0) {
				map[i]=v;
				s[i]=k;
				count++;
				break;
			}
			if(i>=100 && map[i-100]==0){
				int j = i-100;
				map[j]=v;
				s[j]=k;
				count++;
				break;
			}
			i++;
		}
	}
}

else cout<<"Tabla LLena!!!"<<endl;
}
int MapHash::at(string k){
if(count!=0){
	for(int i=0;i<100;i++){
		if(s[i].compare(k)==0){
			int suma=0;
			int key;
			for(int i=0; i<k.size(); i++){
				suma = suma+(int)k[i];
			}
			key= suma%100;
			for(int i=key;;i++){
				if(i>=100 && s[i-100].compare(k)==0){
					return map[i-100];
				}
				if(i<=100 && s[i].compare(k)==0) {
					return map[i];
				}
			}
		}cout << "Key no Existe"<< endl;
	}
}
else cout<<"Tabla Vacia!!!"<<endl;
}
void MapHash::erase(string k){
if(count!=0){
	for(int i=0;i<100;i++){
		if(s[i].compare(k)==0){
			int suma=0;
			int key;
			int tmp=0;
			for(int i=0; i<k.size(); i++){
				suma = suma+(int)k[i];
			}
			key= suma%100;
			for(int i=key;;i++){
				if(i>=100 && s[i-100].compare(k)==0){
					map[i-100]=0;
					count--;
					break;
				}
				if(i<=100 && s[i].compare(k)==0) {
					map[i]=0;
					count--;
					break;
				}
			}
		}
		else cout << "Key no Existe" << endl;
	}	
}
else cout<<"Tabla Vacia!!!"<<endl;
}
