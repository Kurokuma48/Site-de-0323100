#include <bits/stdc++.h>

using namespace std;

struct vertice{
    int ID, pai = 0;
    double distAbs = 0;
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
            if (!semaforos.empty() && semaforos.find(ID) != semaforos.end()) 
                throw new invalid_argument("semaforo ja adicionado");

            semaforo proximo = new vertice();
            proximo->ID = ID; proximo->posicao.first = x; proximo->posicao.second = y;
            semaforos[ID] = proximo;
        }
    //Adiciona uma rua na rede usando o ID de dois semaforos e o comprimento da rua
        void adiconarRua(int ID1, int ID2, double dist){
            //Confere se ambos os semaforos existem
            if(semaforos.find(ID1) == semaforos.end()) throw new invalid_argument("ID1 n enocntrado em addRua");
            if(semaforos.find(ID2) == semaforos.end()) throw new invalid_argument("ID2 n encontrado em addRua");

            semaforos[ID1]->adj[ID2] = dist;
        }
    //Retorna o tamanho da rua entre dois smaforos
        double getTamanhoDaRua(int ID1, int ID2){
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

            for(auto itr = semaforos.begin(); itr != semaforos.end(); itr++){
                itr->second->pai = 0;
            }
            semaforo inicio = semaforos[ID1]; inicio->pai = 0; inicio->distAbs = 0.0;
            semaforo final = semaforos[ID2];
            grafo primeiro = make_pair(h(ID1, ID2), inicio);

            priority_queue <grafo, vector<grafo>, greater<grafo>> minHeap;
            minHeap.push(primeiro);
            
            grafo novo = minHeap.top();

            while(!minHeap.empty() && novo.second->ID != final->ID){
                minHeap.pop();
                for(auto itr = novo.second->adj.begin(); itr != novo.second->adj.end(); itr++){
                    if(semaforos[itr->first]->pai == 0){
                        semaforo proximo = semaforos[itr->first];
                        proximo->pai = novo.second->ID;
                        proximo->distAbs = novo.second->distAbs + itr->second;
                        minHeap.push(make_pair(h(proximo->ID, final->ID) + proximo->distAbs, proximo));
                    }
                }
                novo =  minHeap.top();
            }

            if(minHeap.empty()) cout << "Nao ha caminho" << endl;
            else{
                semaforo caminho = novo.second;
                int pai = caminho->pai;
                while(pai != 0){
                    cout << pai << endl;
                    caminho = semaforos[pai];
                    pai = caminho->pai;
                }
            }
        }
};