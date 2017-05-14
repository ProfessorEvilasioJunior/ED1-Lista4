#include <iostream>

using namespace std;

int t;
const int ct = 1e9;

struct cliente
{
	string nome, cpf;
};

cliente* criar()
{
	cliente *fila;
	fila = (cliente*)(malloc(ct));
	return fila;
}

void inserir(cliente *fila, cliente c)
{	
	fila[t] = c;
	t++;
}

string remover(cliente *fila)
{
	t--;
	
	string temp = fila[0].cpf;
	for(int i = 0; i < t; i++)
		fila[i] = fila[i+1];
	
	return temp;
}

void deletar(cliente *fila)
{
	free(fila);
}

int main()
{
	//criar a fila e dois clientes
	cliente *fila = criar();
	cliente c1,c2;
	c1.nome = "a", c1.cpf = "123";
	c2.nome = "b", c2.cpf = "456";
	
	//checar se os cpfs do clinte c1 e do primeiro elemento inserido na fila sao iguais
	cout << c1.cpf << '\n';
	inserir(fila, c1);
	cout << fila[0].cpf << '\n';
	
	//inserir o segundo elemento na fila e imprimir o elemento do topo
	inserir(fila, c2);
	cout << fila[1].cpf << '\n';
	
	//remover os dois elementos da fila
	cout << remover(fila) << '\n';
	cout << remover(fila) << '\n';
	
	//apagando a fila
	deletar(fila);
	
	return 0;
}
