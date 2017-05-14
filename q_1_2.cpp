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
	cliente *lista;
	lista = (cliente*)(malloc(ct));
	return lista;
}

void inserir(cliente *lista,cliente c ,int p)
{
	cliente temp;
	for(; p <= t; p++)
	{
		temp = lista[p];
		lista[p] = c;
		c = temp;
	}
	
	t++;
}

string remover(cliente *lista, int p)
{
	string temp = lista[p].cpf;
	for(int i = p; i < t; i++)
		lista[p] = lista[p+1];
		
	t--;
	
	return temp;
}

int posicao(cliente *lista, cliente c)
{
	for(int i = 0; i < t; i++)
		if(lista[i].cpf == c.cpf)
			return i;
			
	return -1;
}

void deletar(cliente *lista)
{
	free(lista);
}

int main()
{
	//criar a lista e dois clientes
	cliente *lista = criar();
	cliente c1,c2;
	c1.nome = "a", c1.cpf = "123";
	c2.nome = "b", c2.cpf = "456";
	
	//checar se os cpfs do clinte c1 e do primeiro elemento inserido na lista sao iguais
	cout << c1.cpf << '\n';
	inserir(lista, c1, 0);
	cout << lista[0].cpf << '\n';
	
	//checar a posicao do cliente c1 na lista
	cout << (posicao(lista, c1)) << '\n';
	
	//inserir o segundo elemento na lista e chcar a nova posicao dos clientes c1 e c2
	inserir(lista, c2, 0);
	cout << (posicao(lista, c1)) << '\n';
	cout << (posicao(lista, c2)) << '\n';
	
	//remover o cliente na posicao 0 e checar a nova posicao de c1
	cout << (remover(lista, 0)) << '\n';
	cout << (posicao(lista, c1)) << '\n';
	
	//apagando a lista
	deletar(lista);
		
	return 0;
}
