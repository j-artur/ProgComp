// Biblioteca que permite a exibição de dados no terminal, além do uso do tipo string.
#include <iostream>
// Biblioteca que permite o uso do tipo string.
#include <string>
// Biblioteca que contém os algoritmos genéticos usados na manipulação das soluções.
#include "genetic.h"

/*
* Ao longo do programa, defini algumas variáveis com a palavra chave const
* (para guardar valores que devem permanecer o mesmo durante toda a execução).
* Essa palavra-chave garante que o valor dessa variável não possa ser alterado em nenhum momento.
* Em outras palavras, é uma variável somente-leitura (readonly).
* Qualquer tentativa de alterar o valor de uma const resulta em erro no compilador.
*/

int main()
{
	using namespace std;

	/* Display de cores no terminal.
	* "\033[32": verde
	* "\033[31": vermelho
	* "\033[m": volta à cor padrão
	*/
	const string YES = "\033[32mOK\033[m";
	const string NO = "\033[31mX\033[m";

	// Linha horizontal para separar blocos de informações.
	const string SEPARATOR = "-------------------------\n";

	// Vetor de 6 valores iniciais a serem preenchidos pelo usuário.
	unsigned short solutions[6];
	// Vetor de 4 valores que serão gerados a partir de operações genéticas nos valores iniciais.
	unsigned short newSolutions[4];

	cout << "Insert 6 initial solutions (numbers must be between 0 and 65535):\n";

	// Loop é executado 6 vezes, recebendo um input do usuário para cada espaço no vetor de soluções iniciais.
	for (size_t i = 0; i < 6; i++)
		cin >> solutions[i];

	cout << SEPARATOR;

	// Aplicando os operadores genéticos da forma como foi requisitada no trabalho,
	// atribuindo cada resultado a um espaço no vetor de novas soluções.
	newSolutions[0] = singlePointCrossing(solutions[0], solutions[1]);
	newSolutions[1] = arithmeticCrossing(solutions[2], solutions[3]);
	newSolutions[2] = simpleMutation(solutions[4]);
	newSolutions[3] = doubleMutation(solutions[5]);

	cout << "Result of the Evaluations\n";

	cout << SEPARATOR;

	// Loop percorrendo o vetor de soluções iniciais, executando a função de avaliação e exibindo o resultado de cada uma.
	for (size_t i = 0; i < 6; i++)
		cout << (evaluate(solutions[i]) ? YES : NO) << '\n';
	/* Optei por utilizar um operador ternário no lugar de um "if else".
	* (expressao ? primeiroValor : segundoValor)
	* O operador ternário avalia uma expressão, retorna o primeiro valor caso a expressão seja verdadeira, ou o segundo caso seja falsa.
	*/

	cout << SEPARATOR;

	// Loop avaliando cada nova solução no outro vetor, exibindo o resultado.
	for (size_t i = 0; i < 4; i++)
		cout << (evaluate(newSolutions[i]) ? YES : NO) << '\n';
}
