#include <iostream>
#include "competition.h"

using namespace std;

int main()
{
	// ### Inscrições ###

	printLineOf('*', 40);

	cout << "Programming competition\n";
	cout << '\n';

	short cptQty;
	cout << "How many competitors there are? ";
	cin >> cptQty;

	short qstQty;
	cout << "How many questions there are? ";
	cin >> qstQty;

	cout << '\n';
	printLineOf('*', 40);

	// Vetor dinâmico de participantes
	Competitor* competitors = new Competitor[cptQty];

	// Vetor de questões contém uma de cada questão para cada participante.
	short arrLen = cptQty * qstQty;
	Question* questions = new Question[arrLen];

	// Laço para preencher o vetor de participantes de acordo com o input do usuário.
	for (size_t i = 0; i < cptQty; i++)
	{
		printLineOf('-', 11);

		cout << "Competitor: ";
		// Em todas as situações que este cin.getline é chamado, há um '\n' no buffer que deve ser removido antes de ser executado.
		cin.ignore(1);
		cin.getline(competitors[i].name, 20);

		printLineOf('-', 11);

		// Associa ao participante um ponteiro correspondente ao início da sua parte no vetor de questões.
		competitors[i].questions = &questions[i * qstQty];

		// Laço para pedir o input de todas as questões do participante.
		for (size_t j = 0; j < qstQty; j++)
		{
			cout << "Question " << letter(j) << '\n';
			fillQuestion(&competitors[i].questions[j]);
		}

		printLineOf('-', 11);
		cout << '\n';
	}

	// ### Resumo por Participante ###

	printLineOf('*', 40);

	printLineOf('-', 20);
	cout << "Competitor's Summary\n";
	printLineOf('-', 20);

	// Percorre o vetor de participantes e exibe o resumo de cada um.
	for (size_t i = 0; i < cptQty; i++)
	{
		cout << competitors[i].name << ":\n";

		printCompetitorSummary(competitors[i].questions, qstQty);
	}

	printLineOf('-', 20);
	cout << '\n';

	// ### Resumo por Questão ###

	printLineOf('-', 18);
	cout << "Question's Summary\n";
	printLineOf('-', 18);

	// Executa o laço para cada questão.
	for (size_t i = 0; i < qstQty; i++)
	{
		cout << "Question " << letter(i) << ":\n";

		// Executa para cada competidor.
		for (size_t j = 0; j < cptQty; j++)
		{
			cout << '\t' << competitors[j].name;
			printQuestionSummary(&competitors[j].questions[i]);
		}
	}

	printLineOf('-', 18);

	// Libera a memória associada ao vetor de participantes.
	delete[] competitors;

	// ### Estatísticas ###

	printLineOf('-', 10);
	cout << "Statistics\n";
	printLineOf('-', 10);

	// Executa para cada questão.
	for (size_t i = 0; i < qstQty; i++)
	{
		// Obtém a média dos valores por questão de todos os participantes.
		Average qst = getQuestionStatistics(questions, arrLen, i, qstQty);
		cout << "Question " << letter(i) << ":  " << qst;
	}
	// Obtém a média de todas as questões de todos os participantes.
	Average qst = getQuestionStatistics(questions, arrLen, 0, 1);
	cout << "Competition: " << qst;

	printLineOf('-', 18);

	// Libera a memória associada ao vetor de todas as questões.
	delete[] questions;

	cout << '\n';
	printLineOf('*', 40);

	return 0;
}
