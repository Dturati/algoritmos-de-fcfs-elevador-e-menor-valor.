//Protótipos
#include <vector>

class Cilindros{

private:
std::vector<int> cilindros;

public:
//construtor
Cilindros();

//Leitura dos valores do cilindro
void leituraCilindros(int quantidade);

std::vector<int> getCilindros();

//Algoritmo FCFS
void algoritimoFCFS(std::vector<int> v, int cabeca, int seek);

//Algoritmo do mais proximo
void algoritimoProximo(std::vector<int> v, int cabeca, int seek);

//Algoritmo do elevador pra cima
void algoritimoElevadorPracima(std::vector<int> v, int cabeca, int seek);

//Algoritmo do elevador pra baixo
void algoritimoElevadorPrabaixo(std::vector<int> v, int cabeca, int seek);

//Destrutor
~Cilindros();


};