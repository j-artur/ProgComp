#include <iostream>
#include <iomanip>
#include "competition.h"

using namespace std;

// Função para imprimir uma linha.
void printLineOf(char ch, short qty)
{
	for (size_t i = 0; i < qty; i++)
		cout << ch;

	cout << '\n';
}

// Retorna uma letra maiúscula convertendo um valor inteiro para um caractere da tabela ASCII. (0 => A, 1 => B, 2 => C etc.)
char letter(size_t n) { return char(n + 65); }

// Permite a entrada de dados para um registro Time pelo cin.
ostream& operator<<(ostream& os, Time& time)
{
	// setw(2) e setfill('0') completam um número com zeros à esquerda para ficar no formato de 2 caracteres.
	os << setw(2) << setfill('0') << time.hour;
	os << ':';
	os << setw(2) << setfill('0') << time.minute;

	return os;
}

// Permite a exibição de um registro Time pelo cout.
istream& operator>>(istream& is, Time& time)
{
	is >> time.hour;
	// Ignora o ':' inserido.
	is.ignore(1);
	is >> time.minute;

	return is;
}

// Permite a subtração de registros Time retornado um valor inteiro correspondente à diferença em minutos.
int operator-(Time finish, Time start)
{
	// Diferença das horas.
	short tempH = finish.hour - start.hour;
	// Diferença dos minutos.
	short tempM = finish.minute - start.minute;
	// Converte as horas e soma aos minutos.
	tempM += tempH * 60;

	return tempM;
}

// Exibe no cout o resumo das questões por competidor.
void printCompetitorSummary(Question* questions, short qty)
{
	for (size_t i = 0; i < qty; i++)
	{
		cout << '\t' << letter(i);

		printQuestionSummary(&questions[i]);
	}
}

// Exibe no cout o resumo de uma questão relacionada a o nome de um competidor.
void printQuestionSummary(Question* q)
{
	cout << " (" << q->difficulty << ") ";
	cout << q->start << " to " << q->finish;
	cout << " (" << q->finish - q->start << " min" << ")\n";
}

// Obtém a média das questões de acordo com os parâmetros fornecidos.
Average getQuestionStatistics(Question* questions, short len, size_t initIdx, short step)
{
	// Inicializa a média com os valores zerados.
	Average avg = { 0, 0 };

	// Contador para guardar a quantidade de questões consideradas.
	size_t count = 0;
	for (size_t i = initIdx; i < len; i += step)
	{
		// Soma todos os valores ao valor na média.
		avg.difficulty += questions[i].difficulty;
		avg.time += questions[i].finish - questions[i].start;
		count++;
	}

	// Divide o total pela quantidade de valores.
	avg.difficulty /= count;
	avg.time /= count;

	return avg;
}

//  Permite usar o cout para exibir uma média.
ostream& operator<<(ostream& os, Average& avg)
{
	os.setf(ios::fixed, ios::floatfield); os.precision(2);

	os << "Difficulty(" << avg.difficulty << ") - " << "Time(" << avg.time << " minutes)\n";

	return os;
}

// Preenche os valores de uma questão.
void fillQuestion(Question* question)
{
	cout << "\tDifficulty: ";
	cin >> question->difficulty;

	cout << "\tStart: ";
	cin >> question->start;

	cout << "\tFinish: ";
	cin >> question->finish;
}
