int main()
{
	int x;

	x = 1;

	int y = 1;

	/*
	*
	* Q:  Qual é a diferença entre as instruções de inicialização a seguir?
	* R:  Observando pelo depurador, a variável y inicia com valor 1, enquanto a variável x inicia com lixo na memória, e depois é atribuido o valor 1.
	*
	* Q: Existe alguma razão para preferir uma opção sobre a outra?
	* R: Por motivos de segurança para evitar bugs, é melhor iniciar com valor atribuído
	*
	* Q: O resultado delas depende de onde elas estão dentro do código?
	* R: Sim, variáveis locais inicializam com valor padrão 0, enquanto variáveis globais inicializam com lixo na memória.
	*
	*/
}