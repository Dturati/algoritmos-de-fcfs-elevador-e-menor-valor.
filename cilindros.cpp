#include "cilindros.h"
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <numeric>
#include <algorithm>

//Construtor
Cilindros::Cilindros(){
	std::cout<<"Inicio"<<std::endl;
}

//leitura dos numeros do cilindro
void Cilindros::leituraCilindros(int quantidade){
	int n = 0;
	int valor;
	std::cout<<"Digite os valores dos cilindros:"<<std::endl;

	while(n<quantidade){
		std::cin>>valor;
		cilindros.push_back(valor);
		n++;
		std::cout<<"Digite os valores dos cilindros:"<<std::endl;
	}

}

std::vector<int> Cilindros::getCilindros(){
	return this->cilindros;	
}



void Cilindros::algoritimoFCFS(std::vector<int> v, int cabeca, int seek){
	//std::cout<<"Calculando com algoritmo FCFS"<<std::endl;
	int cont = 0;
	int tempo = seek;
	std::vector<int> distancia;


	//Verifica se o elemento já existe no vetor
	//Se existir remove
	std::vector<int>::iterator p;	
	p = std::find(v.begin(), v.end(), cabeca);
	if(p[0]){
		v.erase(p);
	}


	while(cont <=v.size() -1){

		//Primeira posicao
		if(cont == 0){
			distancia.push_back(abs(cabeca - v[0]));
			cont++;
		}else{
			distancia.push_back(abs(v[cont] - v[cont-1]));
			cont++;
		}
	}

	for(int i =0; i<distancia.size();i++){
		std::cout<<distancia[i]<<std::endl;
	}

	std::cout<<"O resultado é:"<<std::endl;
	std::cout<<std::accumulate(distancia.begin(),distancia.end(), 0)*(tempo)<<std::endl;
	v.clear();

}


//Algoritmo mais proximo
void Cilindros::algoritimoProximo(std::vector<int> v, int cabeca, int seek){
		//std::cout<<"Calculando o algoritmo do mais próximo"<<std::endl;
		std::vector<int> soma;
		std::sort(v.begin(), v.end());
		int pos  = 0;
		int menor = 0;
		int tamanho = 0;
		int tempo = seek;


		//Verifica se o elemento já existe no vetor
		//Se existir remove
		std::vector<int>::iterator p;	
		p = std::find(v.begin(), v.end(), cabeca);
		if(p[0]){
			v.erase(p);
		}

		
		//se a cabeça for o maior cilindro
		//ele se torna o algoritimo FCFS ao contrário
		if( cabeca > v[v.size()-1] ){
			//Ordena ao contrario
			std::reverse(v.begin(), v.end());

			this->algoritimoFCFS(v,cabeca,seek);
			return;
		}
		

		std::cout<<"Vetores"<<std::endl;
		for(int i = 0; i< v.size();i++){
			//std::cout<<v[i]<<std::endl;
		}
		tamanho = v.size();


		while(tamanho > 0){
			
			menor = abs(cabeca - v[0]);
	
			for(int i = 1; i < v.size(); i++){

				if(abs(cabeca - v[i]) < menor){
					menor = abs(cabeca - v[i]);
					pos = i;
				}else{
					pos = 0;
				}

				if(abs(cabeca - v[i+1]) >= menor){
					soma.push_back(menor);
					std::vector<int>::iterator p;
					p = std::find(v.begin(), v.end(), v[pos]);
					cabeca = v[pos];
					//std::cout<<"cabeca:"<<cabeca<<std::endl;
					if(p[0]){
						v.erase(p);
					}
					tamanho -= 1 ;
					break;
				}

			}
			
			if(v.size() == 1){
				menor = abs(cabeca - v[0]);
				soma.push_back(menor);
				tamanho = 0;
			}

		}

	std::cout<<"Somas"<<std::endl;
	for(int i = 0; i< soma.size();i++){
		std::cout<<soma[i]<<std::endl;
	}

	std::cout<<std::accumulate(soma.begin(),soma.end(), 0)*(tempo)<<std::endl;
	v.clear();
}


//Algoritmo do elevador
void Cilindros::algoritimoElevadorPracima(std::vector<int> v, int cabeca, int seek){
	//std::cout<<"Calculando com algoritmo Do elevador"<<std::endl;
	std::sort(v.begin(), v.end());
	int posicao = 0;
	int posicaoFinal = 0;
	std::vector<int>::iterator p;
	std::vector<int> soma;
	int tempo = seek;

	p = std::find(v.begin(), v.end(), cabeca);
	if(p[0]){
		v.erase(p);
	}
	

	//se a cabeça for o maior cilindro
	//ele se torna o algoritimo FCFS ao contrário
	if( cabeca > v[v.size()-1] ){
		//Ordena ao contrario
		std::reverse(v.begin(), v.end());

		this->algoritimoFCFS(v,cabeca,seek);
		return;
	}

	//Vetor ordenado
	for(int i = 0; i< v.size();i++){
		std::cout<<v[i]<<std::endl;
	}

	for(int i = 0; i< v.size();i++){
		if(v[i] > cabeca ){
			posicao = i;
			break;
		}
	}

	//percore e guarda no vetor soma apartir da posição do maior cilindo que a cabeça
	for(int i = posicao; i<v.size(); i++){

		if(cabeca != 0){
			soma.push_back(abs(cabeca - v[i]));
			cabeca = 0;
		}else{
			soma.push_back(abs(v[i] - v[i-1]));
		}

	}

	posicaoFinal = v.size()-1;


	//Segunda parte do vetor com o valores menores
	while(posicao != 0){
		if(posicaoFinal != 0){
			soma.push_back(abs(v[posicaoFinal] - v[posicao - 1] ));
			posicaoFinal = 0;
			posicao--;
		}else{
			soma.push_back(abs(v[posicao] - v[posicao-1] ));
			posicao--;
		}
		
	}

	//Somas
	std::cout<<"Somas"<<std::endl;
	for(int i = 0; i< v.size();i++){
		std::cout<<soma[i]<<std::endl;
	}

	std::cout<<std::accumulate(soma.begin(),soma.end(), 0)*(tempo)<<std::endl;
	v.clear();
}



//Algoritmo do elevador
void Cilindros::algoritimoElevadorPrabaixo(std::vector<int> v, int cabeca, int seek){
	std::cout<<"Descendo"<<std::endl;
	std::sort(v.begin(), v.end());
	std::reverse(v.begin(), v.end());
	int posicao = 0;
	int posicaoFinal = 0;
	std::vector<int>::iterator p;
	std::vector<int> soma;
	int tempo = seek;

	p = std::find(v.begin(), v.end(), cabeca);
	if(p[0]){
		v.erase(p);
	}
	

	//se a cabeça for o maior cilindro
	//ele se torna o algoritimo FCFS ao contrário
	
	if( cabeca > v[0] ){
		//Ordena ao contrario
		//std::reverse(v.begin(), v.end());
		this->algoritimoFCFS(v,cabeca,seek);
		return;
	}
	

	//Vetor ordenado
	for(int i = 0; i< v.size();i++){
		std::cout<<v[i]<<std::endl;
	}

	for(int i = 0; i< v.size();i++){
		if(v[i] < cabeca ){
			posicao = i;
			break;
		}
	}

	//std::cout<<"Posicao"<<std::endl;
	//std::cout<<v[posicao]<<std::endl;
	//percore e guarda no vetor soma apartir da posição do maior cilindo que a cabeça
	for(int i = posicao; i<v.size(); i++){

		if(cabeca != 0){
			soma.push_back(abs(cabeca - v[i]));
			cabeca = 0;
		}else{
			soma.push_back(abs(v[i] - v[i-1]));
		}

	}

	posicaoFinal = v.size()-1;


	//Segunda parte do vetor com o valores menores
	while(posicao != 0){
		if(posicaoFinal != 0){
			soma.push_back(abs(v[posicaoFinal] - v[posicao - 1] ));
			posicaoFinal = 0;
			posicao--;
		}else{
			soma.push_back(abs(v[posicao] - v[posicao-1] ));
			posicao--;
		}
		
	}

	//Somas
	std::cout<<"Somas"<<std::endl;
	for(int i = 0; i< v.size();i++){
		std::cout<<soma[i]<<std::endl;
	}

	std::cout<<std::accumulate(soma.begin(),soma.end(), 0)*(tempo)<<std::endl;
	v.clear();
}

//Destrutor
Cilindros::~Cilindros(){
	std::cout<<"Fim"<<std::endl;
}