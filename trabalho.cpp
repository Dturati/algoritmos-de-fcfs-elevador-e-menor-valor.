#include <iostream>
#include <cstdio>
#include <cstdlib>
#include "cilindros.h"

int main(){
	int estado = 10;
	int quantidade;
	int seek = 0 ;
	Cilindros *nc = new Cilindros();

	//Recebe resultado com valores dos cilindros
	std::vector<int> cilindros;
	int cabeca;

	while(estado != 0){
		std::cout<<"Digite 0 para sair, 1 para valores do cilindro, 2 para algoritimo de FCSC, 3 para elevador, 4 para menor:";
		std::cin>>estado;

		//Le os valores para os cilindros
		if(estado == 1){
				std::cout<<"Digite a quantidade de cilindros:";
				std::cin>>quantidade;
				nc->leituraCilindros(quantidade);
		}
		
		//busca o cilindro
		if(estado == 2){
				cilindros = nc->getCilindros();
				std::cout<<"Posicao inicial da cabeça:";
				std::cin>>cabeca;
				std::cout<<"Tempo de Seek"<<std::endl;
				std::cin>>seek;
				nc->algoritimoFCFS(cilindros,cabeca, seek);
		}

		//Algoritmo do elevador
		if(estado == 3){
			int inicio = 0;
			cilindros = nc->getCilindros();
			std::cout<<"Posicao inicial da cabeça:";
			std::cin>>cabeca;
			std::cout<<"Tempo de Seek"<<std::endl;
			std::cin>>seek;

			std::cout<<"Sobe ou desce? 1 sobe, 2 desce:"<<std::endl;
			std::cin>>inicio;
			if(inicio == 1){
				nc->algoritimoElevadorPracima(cilindros,cabeca,seek);
			}

			if(inicio == 2){
				nc->algoritimoElevadorPrabaixo(cilindros,cabeca,seek);
			}

			
		}

		//Algorimo proximo
		if(estado == 4){
			cilindros = nc->getCilindros();
			std::cout<<"Posicao inicial da cabeça:";
			std::cin>>cabeca;
			std::cout<<"Tempo de Seek"<<std::endl;
			std::cin>>seek;
			nc->algoritimoProximo(cilindros,cabeca, seek);
		}

	

	}

	delete nc;
	return 0;
}