#include <bits/stdc++.h>

using namespace std;

struct vertice{
    int ID, pai = 0;
    double distAbs = 0;
    pair<double, double> posicao;
    unordered_map<int, double> adj;
};

typedef vertice* semaforo;
typedef tuple<double, semaforo, int> grafo;
class Rede{
    private:
        unordered_map<int, semaforo> semaforos;
        double h(int ID1, int ID2){
            return 0;
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
        void adicionarRua(int ID1, int ID2, double dist){
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
            if(ID1 == ID2) {cout << ID1; return;}

            //Seta todos os pais para zero
            for(auto itr = semaforos.begin(); itr != semaforos.end(); itr++){
                itr->second->pai = 0;
                semaforos[itr->first]->distAbs = INT_MAX;
            }
            
            //Recorda o ponto inicial e o final
            semaforo inicio = semaforos[ID1]; inicio->pai = 0; inicio->distAbs = 0.0;
            semaforo final = semaforos[ID2];
            grafo primeiro = make_tuple(h(ID1, ID2), inicio, ID1);

            //Cira o minHeap do algoritmo
            priority_queue <grafo, vector<grafo>, greater<grafo>> minHeap;
            minHeap.push(primeiro);
            
            grafo novo = minHeap.top();

            //Coloca na fila os vertices até ver todos ou chegar no ultimo
            while(!minHeap.empty() && get<1>(novo)->ID != final->ID){
                minHeap.pop();
                for(auto itr = get<1>(novo)->adj.begin(); itr != get<1>(novo)->adj.end(); itr++){
                    if(semaforos[itr->first]->pai == 0){
                        semaforo proximo = semaforos[itr->first];
                        if(proximo->distAbs > get<1>(novo)->distAbs + itr->second) proximo->distAbs = get<1>(novo)->distAbs + itr->second;
//cout <<proximo->ID << " " << proximo->distAbs << endl;
                        minHeap.push(make_tuple(h(proximo->ID, final->ID) + proximo->distAbs, proximo, get<1>(novo)->ID));
                    }
                }
                //Garante que nenhum vertice ja visto não será estragado
                while(get<1>(minHeap.top())->pai != 0 && !minHeap.empty()){
                    minHeap.pop();
                }
                //Se o ainda tem coisa no heap atualiza o novo
                if(!minHeap.empty()){
                    novo =  minHeap.top();
                    get<1>(novo)->pai = get<2>(novo);    
                }
                
            }
            //Arruma o primeiro
            inicio->pai = 0;

            //Imprime o resultado
            if(minHeap.empty()) cout << "Nao ha caminho";
            else{
                stack<int> pilha;
                pilha.push(final->ID);
                semaforo caminho = get<1>(novo);
                int pai = caminho->pai;
                while(pai != 0){
                    pilha.push(pai);
                    caminho = semaforos[pai];
                    pai = caminho->pai;
                }                
                ofstream output;
                output.open("caminho.csv");
                output << pilha.top();
                pilha.pop();
                while(!pilha.empty()){
                    output << "," << pilha.top(); 
                    pilha.pop();
                }
            }
        }
};
