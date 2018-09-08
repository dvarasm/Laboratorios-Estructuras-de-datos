#include <iostream>
#include <map>
#include <unordered_map>
#include <cstdio>
#include <iomanip> 
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;

typedef unsigned int uint;

std::string randomString(uint maxLength = 15, std::string charIndex = "abcdefghijklmnaoqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"){ 
    uint length = rand() % maxLength + 1; 

    uint indexesOfRandomChars[15]; 
    for (uint i = 0; i < length; ++i) 
        indexesOfRandomChars[i] = rand() % charIndex.length();

    std::string randomString = ""; 
    for (uint i = 0; i < length; ++i)
    {
        randomString += charIndex[indexesOfRandomChars[i]];
    } 
    return randomString;
}

int main(){
	srand(time(NULL));
	map<string,int> ma;
	unordered_map<string,int> uno_ma;
	
	clock_t start = clock();
	for(int i= 0; i<1000;i++){
		ma.insert(pair<string,int>(randomString(),i));	
	}
	float s = ((double)clock() - start) / CLOCKS_PER_SEC;
	printf("Tiempo transcurrido para insertar en Map (STL): %f\n",s);
	
	
	start = clock();
	for(int i= 0; i<1000;i++){
		uno_ma.insert(pair<string,int>(randomString(),i));	
	}
	float s1 = ((double)clock() - start) / CLOCKS_PER_SEC;
	printf("Tiempo transcurrido para insertar en Unordered Map (STL):  %f\n", s1);

	return 0;
}
