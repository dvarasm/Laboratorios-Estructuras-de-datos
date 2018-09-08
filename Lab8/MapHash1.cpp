#include "MapHash1.h"
#include <string>
#include <cstdlib>
#include <iostream>

using namespace std;

MapHash1::MapHash1(){
	for(int i=0; i<100;i++){
		map[i]=0;	
	}
	count=0;
}

bool MapHash1::empty(){
	if(count==0)return true;
	else return false;
}
int MapHash1::size(){
	return count;
}
void MapHash1::insert(string k,int v){
if(count!=100){
	int suma=0;
	int key;
	key= (int)k[0]%100;
	if(map[key]==0){
		map[key]=v;
		s[key]=k;
		count++;
	}
	else{
		for(int i=key;;i++){
			if(i>=100 && map[i-100]==0){
				map[i-100]=v;
				s[i-100]=k;
				count++;
				break;
			}
			if(i<=100 && map[i]==0) {
				map[i]=v;
				s[i]=k;
				count++;
				break;
			}
		}
	}
}

else cout<<"Tabla LLena!!!"<<endl;
}
int MapHash1::at(string k){
if(count!=0){
	for(int i=0;i<100;i++){
		if(s[i].compare(k)==0){
			int key;
			key= (int)k[0]%100;
			for(int i=key;;i++){
				if(i>=100 && s[i-100].compare(k)==0){
					return map[i-100];
				}
				if(i<=100 && s[i].compare(k)==0) {
					return map[i];
				}
			}
		}else cout << "Key no Existe"<< endl;
	}
}
else cout<<"Tabla vacia!!!"<<endl;
}

void MapHash1::erase(string k){
if(count!=0){
	for(int i=0;i<100;i++){
		if(s[i].compare(k)==0){
			int suma=0;
			int key;
			key= k[0]%100;
			for(int i=key;;i++){
				if(i>100 && s[i-100].compare(k)==0){
					map[i-100]=0;
					count--;
					break;
				}
				else if(s[i].compare(k)==0) {
					map[i]=0;
					count--;
					break;
				}
			}
		}else cout << "Key no ingresada!!"<< endl;
	}
}
else cout<<"Tabla Vacia!!!"<<endl;
}
