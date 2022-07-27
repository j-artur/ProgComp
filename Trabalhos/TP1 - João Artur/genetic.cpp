// Biblioteca que permite a exibição de dados no terminal.
#include <iostream>
// Biblioteca que permite o uso do tipo string.
#include <string>
// Biblioteca de funções binárias necessárias para fazer operações com bits.
#include "binary.h"

bool evaluate(unsigned short solution)
{
	using namespace std;

	// Vetores de peso e preço correspondentes a posição de cada bit.
	const unsigned short WEIGHTS[16] = { 12, 3, 5, 4, 9, 1, 2, 3, 4, 1, 2, 4, 5, 2, 4, 1 };
	const unsigned short VALUES[16] = { 4, 4, 8, 10, 15, 3, 1, 1, 2, 10, 20, 15, 10, 3, 4, 12 };

	// Iniciar peso e valor da mochila em 0.
	unsigned short weight = 0;
	unsigned short value = 0;

	// Testar todos os bits da solução e calcular peso e valor da mochila.
	for (size_t i = 0; i < 16; i++)
	{
		// A indexação dos bits é da direita para a esquerda, então usei (o último índice possível menos o iterador) para posição.
		if (testBit(solution, 15 - i))
		{
			// Quando o teste é positivo, adicione à mochila o peso e o valor correspondente.
			weight += WEIGHTS[i];
			value += VALUES[i];
		}
	}

	// Separador a ser usado entre os valores apresentados.
	const string SEPARATOR = " - ";

	// Exibe o inteiro a ser avaliado.
	cout << right; cout.width(5); cout << solution;

	cout << SEPARATOR;

	// Exibe o valor total da mochila, com texto alinhado à esquerda.
	cout << '$';
	cout << left; cout.width(3); cout << value;

	cout << SEPARATOR;

	// Exibe o peso total da mochila, com texto alinhado à direita.
	cout << right; cout.width(2); cout << weight;
	cout << "Kg";

	cout << SEPARATOR;

	// Se o peso extrapolou, a mochila não suporta, então retorne falso.
	if (weight > 20)
		return false;

	// A palavra-chave "else" nesse caso é desnecessária, pois caso caia na condição acima, a função retorna e sua execução para.
	// Ou seja, as linhas abaixo da condicional só serão executadas caso dê falso.
	return true;

	// A função main que será a responsável por exibir o resultado final do teste.
}

// Função de cruzamento de ponto único: recebe 2 inteiros e junta uma parte de cada um para formar um novo.
unsigned short singlePointCrossing(unsigned short solution1, unsigned short solution2)
{
	// Cria uma nova solução com a "maior metade" da primeira e a "menor metade" da segunda.
	unsigned short newSolution = highBits(solution1) + lowBits(solution2);

	return newSolution;
}

// Função de cruzamento aritmético: cria uma nova solução apenas com os bits 1 que se repetem nos dois inteiros.
unsigned short arithmeticCrossing(unsigned short solution1, unsigned short solution2)
{
	unsigned short newSolution = bitwiseAND(solution1, solution2);

	return newSolution;
}

// Função de mutação simples: inverte um bit numa posição específica.
unsigned short simpleMutation(unsigned short solution)
{
	unsigned short newSolution;

	// Posição do bit a ser mutado.
	const char position = 9;

	// Se o bit estiver ligado, desligue; Se estiver desligado, ligue.
	if (testBit(solution, position))
		newSolution = turnOffBit(solution, position);
	else
		newSolution = turnOnBit(solution, position);

	return newSolution;
}

// Função de mutação dupla: inverte dois bits em duas posições específicas.
unsigned short doubleMutation(unsigned short solution)
{
	unsigned short newSolution;

	// Posições dos dois bits a serem mutados.
	const char pos1 = 3;
	const char pos2 = 12;

	if (testBit(solution, pos1))
		newSolution = turnOffBit(solution, pos1);
	else
		newSolution = turnOnBit(solution, pos1);

	// Repete a mesma ação, usando o valor da solução já alterada pela condicional anterior.
	if (testBit(newSolution, pos2))
		newSolution = turnOffBit(newSolution, pos2);
	else
		newSolution = turnOnBit(newSolution, pos2);

	return newSolution;
}
