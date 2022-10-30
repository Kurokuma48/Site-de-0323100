#include <bits/stdc++.h>

using namespace std;

struct vertice{
    int ID, pai = 0;
    pair<double, double> posicao;
    unordered_map<int, double> adj;
};

typedef vertice* semaforo;
typedef pair<double, semaforo> grafo;
class Rede{
    private:
        unordered_map<int, semaforo> semaforos;
        double h(int ID1, int ID2){
            semaforo primeiro = semaforos[ID1];
            semaforo segundo = semaforos[ID2];
            float dx = (primeiro->posicao.first - segundo->posicao.first);
            float dy = (primeiro->posicao.second - segundo->posicao.second);
            return sqrt(dx * dx + dy * dy);
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
        void getMenorCaminho (int ID1, int ID2){
            //Confere se ambos os semaforos existem
            if(semaforos.find(ID1) == semaforos.end()) throw new invalid_argument("ID1 n enocntrado no A*");
            if(semaforos.find(ID2) == semaforos.end()) throw new invalid_argument("ID2 n encontrado no A*");

            semaforo inicio = semaforos[ID1]; inicio->pai = 0;
            semaforo final = semaforos[ID2];

            grafo primeiro;
            primeiro.second = inicio;
            primeiro.first = h(ID1, ID2);

            priority_queue <grafo, vector<grafo>, greater<grafo>> minHeap;
            minHeap.push(primeiro);

            
            grafo proximo =  minHeap.top();
            minHeap.pop();

            while(!minHeap.empty() && proximo.second != final){
                for(auto itr = proximo.second->adj.begin(); itr != proximo.second->adj.end(); itr++){
                    semaforo novo = semaforos[itr->first];
                    novo->pai = proximo.second->ID;
                    minHeap.push(make_pair(h(novo->ID, proximo.second->ID) + (*proximo.second->adj.find(novo->ID)).second, novo));
                }
                grafo proximo =  minHeap.top();
                minHeap.pop();
            }

            if(minHeap.empty()) cout << "Nao ha caminho" << endl;
            else{
                semaforo caminho = proximo.second;
                int pai = caminho->pai;
                while(pai != 0){
                    cout << pai << endl;
                    caminho = semaforos[pai];
                    pai = caminho->pai;
                }
            }
        }
};