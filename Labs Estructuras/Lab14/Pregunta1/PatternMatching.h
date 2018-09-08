#include <string>

using namespace std;

class PatternMatching{
	private:
		int* Failure_Function(string);
	public:
		PatternMatching();
		int Fuerza_Bruta(string, string);
		int Boyer_Moore(string, string);
};
