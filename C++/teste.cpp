#include<bits/stdc++.h>
#include"Grafo.h"

using namespace std;

int main(){
    Rede teste;
    try{
        teste.adicionarSemaforo(1, 0.0, 0.0);
        teste.adicionarSemaforo(2, 0.0, 0.0);
        teste.adicionarSemaforo(3, 0.0, 0.0);
        teste.adicionarSemaforo(4, 0.0, 0.0);
        teste.adicionarSemaforo(5, 0.0, 0.0);
        teste.adiconarRua(1, 2, 6.0);
        teste.adiconarRua(1, 5, 3.0);
        teste.adiconarRua(2, 5, 1.0);
        teste.adiconarRua(2, 3, 3.0);
        teste.adiconarRua(3, 4, 5.0);
        teste.adiconarRua(5, 3, 7.0);
        teste.adiconarRua(5, 2, 2.0);
        teste.getMenorCaminho(2, 3);
    }
    catch(invalid_argument* e){
        cout << e->what() << endl;
        delete e;
        return 0;
    }

    return 0;
    
}