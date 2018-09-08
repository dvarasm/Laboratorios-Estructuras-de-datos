#include <unordered_map>
#include <cstdio>
#include <iomanip> 
#include <ctime>
#include <cstdlib>
#include <map>
using namespace std;

int main(){
	srand(time(NULL));
	map<int,int> ma;
	unordered_map<int,int> uno_ma;
	

	clock_t start = clock();
	for(int i= 0; i<10000;i++){
		ma.insert(pair<int,int>(rand()%10000,i));
	
	}
	float s = ((double)clock() - start) / CLOCKS_PER_SEC;
	printf("Tiempo transcurrido para insertar en Map (STL): %f\n",s);
	
	
	int k=0;
	start = clock();
	for(int i= 0; i<10000;i++){
		uno_ma.insert(pair<int,int>(rand()%10000,i));
	}
	float s1 = ((double)clock() - start) / CLOCKS_PER_SEC;
	printf("Tiempo transcurrido para insertar en Unordered Map (STL):  %f\n", s1);

	return 0;
}
