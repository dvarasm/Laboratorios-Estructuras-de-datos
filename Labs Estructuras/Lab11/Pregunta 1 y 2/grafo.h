#include <vector>

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
		vector<int> adybfs[500],adydfs[500];
		bool visitadobfs[500],visitadodfs[500];
		void databfs();
		void datadfs();
		
		
	public:
		grafo();
		void mostrar_grafo();
		void insertar_nodo(int);
		void insertar_arista(int,int);
		void bfs(int,int);
		void dfs(int);

};
