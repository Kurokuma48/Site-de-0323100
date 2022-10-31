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
        teste.adicionarSemaforo(6, 0.0, 0.0);
        teste.adicionarSemaforo(7, 0.0, 0.0);
        teste.adicionarSemaforo(8, 0.0, 0.0);
        teste.adicionarSemaforo(9, 0.0, 0.0);
        teste.adicionarSemaforo(10, 0.0, 0.0);
        teste.adiconarRua(1, 2, 5.0);
        teste.adiconarRua(1, 4, 10.0);
        teste.adiconarRua(2, 10, 3.0);
        teste.adiconarRua(2, 5, 1.0);
        teste.adiconarRua(2, 1, 4.0);
        teste.adiconarRua(3, 4, 7.0);
        teste.adiconarRua(3, 10, 10.0);
        teste.adiconarRua(4, 2, 12.0);
        teste.adiconarRua(4, 1, 9.0);
        teste.adiconarRua(5, 6, 5.0);
        teste.adiconarRua(5, 7, 7.0);
        teste.adiconarRua(6, 7, 8.0);
        teste.adiconarRua(6, 4, 2.0);
        teste.adiconarRua(6, 9, 2.0);
        teste.adiconarRua(6, 10, 2.0);
        teste.adiconarRua(7, 2, 7.0);
        teste.adiconarRua(7, 8, 2.0);
        teste.adiconarRua(7, 5, 5.0);
        teste.adiconarRua(8, 6, 3.0);
        teste.adiconarRua(8, 7, 1.0);
        teste.adiconarRua(8, 9, 2.0);
        teste.adiconarRua(9, 10, 4.0);
        teste.adiconarRua(10, 2, 3.0);
        teste.adiconarRua(10, 6, 3.0);

        teste.getMenorCaminho(3, 7);
    }
    catch(invalid_argument* e){
        cout << e->what() << endl;
        delete e;
        return 0;
    }

    return 0;
    
}