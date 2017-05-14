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
	cliente *pilha;
	pilha = (cliente*)(malloc(ct));
	return pilha;
}

void inserir(cliente *pilha, cliente c)
{
	pilha[t] = c;
	t++;
}

string remover(cliente *pilha)
{
	t--;
	return pilha[t].cpf;
}

void deletar(cliente *pilha)
{
	free(pilha);
}

int main()
{
	//criar a pilha e dois clientes
	cliente *pilha = criar();
	cliente c1,c2;
	c1.nome = "a", c1.cpf = "123";
	c2.nome = "b", c2.cpf = "456";
	
	//checar se os cpfs do clinte c1 e do primeiro elemento inserido na pilha sao iguais
	cout << c1.cpf << '\n';
	inserir(pilha, c1);
	cout << pilha[0].cpf << '\n';
	
	//inserir o segundo elemento na pilha e imprimir o elemento do topo
	inserir(pilha, c2);
	cout << pilha[1].cpf << '\n';
	
	//remover os dois elementos da pilha
	cout << remover(pilha) << '\n';
	cout << remover(pilha) << '\n';
	
	
	//apagando a pilha
	deletar(pilha);
	
	return 0;
}
