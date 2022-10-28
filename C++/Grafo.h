#include <bits/stdc++.h>

using namespace std;

struct vertice{
    int ID;
    pair<double, double> posicao;
    unordered_map<int, double> adj;
};
struct caminho{
    int ID;
    caminho* pai;
};

typedef vertice* semaforo;

class Rede{
    private:
        unordered_map<int, semaforo> semaforos;
        double h(double x, double y){
            return sqrt(x*x + y*y);
        }
    public:
    //Adicona um semaforo na rede usando seu ID
        void adicionarSemaforo(int ID, double x, double y){
            //Confere se o semáforo ja existe
            if (semaforos.find(ID) == semaforos.end()) throw new invalid_argument("semaforo ja adicionado");

            semaforo novo = new vertice();
            novo->ID = ID; novo->posicao.first = x; novo->posicao.second = y;
            semaforos[ID] = novo;
        }
    //Adiciona uma rua na rede usando o ID de dois semaforos e o comprimento da rua
        void adiconarRua(int ID1, int ID2, double dist){
            //Confere se ambos os semaforos existem
            if(semaforos.find(ID1) == semaforos.end()) throw new invalid_argument("ID1 n enocntrado em addRua");
            if(semaforos.find(ID2) == semaforos.end()) throw new invalid_argument("ID2 n encontrado em addRua");

            semaforos[ID1]->adj[ID2] = dist;
        }
    //Retorna o tamanho da rua entre dois smaforos
        int getTamanhoDaRua(int ID1, int ID2){
            //Confere se os semaforos e a rua existem
            if(semaforos.find(ID1) == semaforos.end()) throw new invalid_argument("ID1 n enocntrado emm getRua");
            if(semaforos.find(ID2) == semaforos.end()) throw new invalid_argument("ID2 n encontrado em getRua");
            if(semaforos[ID1]->adj.find(ID2) == semaforos[ID1]->adj.end()) throw new invalid_argument("rua inexistente");

            return semaforos[ID1]->adj[ID2];
        }
    //Executa o algoritmo A* para encontrar o menor caminho entre dois pontos de um grafo
        caminho* getMenorCaminho (int ID1, int ID2){
            //Confere se ambos os semaforos existem
            if(semaforos.find(ID1) == semaforos.end()) throw new invalid_argument("ID1 n enocntrado no A*");
            if(semaforos.find(ID2) == semaforos.end()) throw new invalid_argument("ID2 n encontrado no A*");

            semaforo inicio = semaforos[ID1];

        }
};