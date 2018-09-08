#include <vector>
#include <utility>

using namespace std;

struct nodo{
            int ID;
            struct nodo *sgte;
            struct arista *ady;
            };
struct arista{
              struct nodo *destino;
              struct arista *sgte;
              };

class grafo{
	private:
		typedef struct nodo *Tnodo;
		typedef struct arista *Tarista;
		Tnodo p;
		bool first;
	public:
		grafo();
		int grado_salida(int);
		int grado_entrada(int);
		vector<int> mostrar_grafo(int);
		void insertar_nodo(int);
		void insertar_arista(int,int);
};
