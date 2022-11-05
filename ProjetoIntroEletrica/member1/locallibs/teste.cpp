#include<bits/stdc++.h>
#include"Grafo.h"

using namespace std;


extern "C" {

void tracarRota(int loc0){
    Rede CUASO;
    try{
	 CUASO.adicionarSemaforo(1 , 0.0, 0.0);
	 CUASO.adicionarSemaforo(2 , 0.0, 0.0);
	 CUASO.adicionarSemaforo(3 , 0.0, 0.0);
	 CUASO.adicionarSemaforo(4 , 0.0, 0.0);
	 CUASO.adicionarSemaforo(5 , 0.0, 0.0);
	 CUASO.adicionarSemaforo(6 , 0.0, 0.0);
	 CUASO.adicionarSemaforo(7 , 0.0, 0.0);
	 CUASO.adicionarSemaforo(8 , 0.0, 0.0);
	 CUASO.adicionarSemaforo(9 , 0.0, 0.0);
	 CUASO.adicionarSemaforo(10 , 0.0, 0.0);
	 CUASO.adicionarSemaforo(11 , 0.0, 0.0);
	 CUASO.adicionarSemaforo(12 , 0.0, 0.0);
	 CUASO.adicionarSemaforo(13 , 0.0, 0.0);
	 CUASO.adicionarSemaforo(14 , 0.0, 0.0);
	 CUASO.adicionarSemaforo(15 , 0.0, 0.0);
	 CUASO.adicionarSemaforo(16 , 0.0, 0.0);
	 CUASO.adicionarSemaforo(17 , 0.0, 0.0);
	 CUASO.adicionarSemaforo(18 , 0.0, 0.0);
	 CUASO.adicionarSemaforo(19 , 0.0, 0.0);
	 CUASO.adicionarSemaforo(20 , 0.0, 0.0);
	 CUASO.adicionarSemaforo(21 , 0.0, 0.0);
	 CUASO.adicionarSemaforo(22 , 0.0, 0.0);
	 CUASO.adicionarSemaforo(23 , 0.0, 0.0);
	 CUASO.adicionarSemaforo(24 , 0.0, 0.0);
	 CUASO.adicionarSemaforo(25 , 0.0, 0.0);
	 CUASO.adicionarSemaforo(26 , 0.0, 0.0);
	 CUASO.adicionarSemaforo(27 , 0.0, 0.0);
	 CUASO.adicionarSemaforo(28 , 0.0, 0.0);
	 CUASO.adicionarSemaforo(29 , 0.0, 0.0);
	 CUASO.adicionarSemaforo(30 , 0.0, 0.0);
	 CUASO.adicionarSemaforo(31 , 0.0, 0.0);
	 CUASO.adicionarSemaforo(32 , 0.0, 0.0);
	 CUASO.adicionarSemaforo(33 , 0.0, 0.0);
	 CUASO.adicionarSemaforo(34 , 0.0, 0.0);

//   teste.adiconarRua(1, 2, 5.0);

	CUASO.adicionarRua(1, 2, 460.0);
	CUASO.adicionarRua(2, 1, 460.0);

	CUASO.adicionarRua(2, 3, 325.0);
	CUASO.adicionarRua(3, 2, 325.0);

	CUASO.adicionarRua(3, 4, 500.0);
	CUASO.adicionarRua(4, 3, 500.0);

	CUASO.adicionarRua(4, 5, 900.0);
	CUASO.adicionarRua(5, 4, 900.0);

	CUASO.adicionarRua(5, 6, 350.0);
	CUASO.adicionarRua(6, 5, 350.0);

	CUASO.adicionarRua(6, 7, 350.0);
	CUASO.adicionarRua(7, 6, 350.0);

	CUASO.adicionarRua(7, 8, 200.0);
	CUASO.adicionarRua(8, 7, 200.0);

	CUASO.adicionarRua(8, 9, 380.0);
	CUASO.adicionarRua(9, 8, 380.0);

	CUASO.adicionarRua(9, 10, 90.0);
	CUASO.adicionarRua(10, 9, 90.0);

	CUASO.adicionarRua(10, 11, 400.0);
	CUASO.adicionarRua(11, 10, 400.0);

	CUASO.adicionarRua(11, 12, 230.0);
	CUASO.adicionarRua(12, 11, 230.0);

	CUASO.adicionarRua(12, 13, 240.0);
	CUASO.adicionarRua(13, 12, 240.0);

	CUASO.adicionarRua(13, 14, 705.0);
	CUASO.adicionarRua(14, 13, 705.0);

	CUASO.adicionarRua(14, 15, 90.0);
	CUASO.adicionarRua(15, 14, 90.0);

	CUASO.adicionarRua(15, 16, 195.0);
	CUASO.adicionarRua(16, 15, 195.0);

	CUASO.adicionarRua(16, 17, 850.0);
	CUASO.adicionarRua(17, 16, 850.0);

	CUASO.adicionarRua(17, 18, 76.0);
	CUASO.adicionarRua(18, 17, 76.0);

	CUASO.adicionarRua(18, 19, 450.0);
	CUASO.adicionarRua(19, 18, 450.0);

	CUASO.adicionarRua(19, 20, 135.0);
	CUASO.adicionarRua(20, 19, 135.0);

	CUASO.adicionarRua(20, 21, 112.0);
	CUASO.adicionarRua(21, 20, 112.0);

	CUASO.adicionarRua(21, 22, 145.0);
	CUASO.adicionarRua(22, 21, 145.0);

	CUASO.adicionarRua(22, 23, 135.0);
	CUASO.adicionarRua(23, 22, 135.0);

	CUASO.adicionarRua(23, 24, 400.0);
	CUASO.adicionarRua(24, 23, 400.0);

	CUASO.adicionarRua(24, 1, 650.0);
	CUASO.adicionarRua(1, 24, 650.0);

	CUASO.adicionarRua(23, 25, 251.0);
	CUASO.adicionarRua(25, 23, 251.0);

	CUASO.adicionarRua(25, 26, 145.0);
	CUASO.adicionarRua(26, 25, 145.0);

	CUASO.adicionarRua(26, 27, 150.0);
	CUASO.adicionarRua(27, 26, 150.0);

	CUASO.adicionarRua(27, 28, 145.0);
	CUASO.adicionarRua(28, 27, 145.0);

	CUASO.adicionarRua(28, 29, 250.0);
	CUASO.adicionarRua(29, 28, 250.0);

	CUASO.adicionarRua(29, 30, 320.0);
	CUASO.adicionarRua(30, 29, 320.0);

	CUASO.adicionarRua(30, 31, 150.0);
	CUASO.adicionarRua(31, 30, 150.0);


	CUASO.adicionarRua(31, 10, 84.0);
	CUASO.adicionarRua(10, 31, 84.0);


	CUASO.adicionarRua(6, 32, 300.0);
	CUASO.adicionarRua(32, 6, 300.0);

	CUASO.adicionarRua(32, 28, 300.0);
	CUASO.adicionarRua(28, 32, 300.0);


	CUASO.adicionarRua(18, 33, 560.0);
	CUASO.adicionarRua(33, 18, 560.0);

	CUASO.adicionarRua(33, 34, 560.0);
	CUASO.adicionarRua(34, 33, 560.0);

	CUASO.adicionarRua(34, 11, 584.0);
	CUASO.adicionarRua(11, 34, 584.0);

	CUASO.adicionarRua(34, 30, 325.0);
	CUASO.adicionarRua(30, 34, 325.0);


        CUASO.getMenorCaminho(loc0, 14);
    }
    catch(invalid_argument* e){
        cout << e->what() << endl;
        delete e;
        return;
    }

    return;
    
}

}
