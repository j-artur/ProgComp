/*
* Parâmetros que indicam posições de bits são armazenados em tipo char.
* Já que seus valores devem estar sempre entre 0 e 15,
* estou usando o mínimo de memória necessária para armazenar esse tipo de dado.
*/

// Função para criar uma máscara de 16 bits com 1 na posição indicada pelo argumento recebido.
unsigned short createMask(char n)
{
	// Cria uma máscara = 0b0000000000000001 e arrasta o 1 "n" casas à esquerda.
	unsigned short mask = 1 << n;

	return mask;
}

// Função para operação AND entre cada bit de 2 inteiros.
unsigned short bitwiseAND(unsigned short integer1, unsigned short integer2)
{
	return integer1 & integer2;
}

// Função para operação OR entre cada bit de 2 inteiros.
unsigned short bitwiseOR(unsigned short integer1, unsigned short integer2)
{
	return integer1 | integer2;
}

// Função para testar se o bit na posição indicada é 0 ou 1.
bool testBit(unsigned short integer, char position)
{
	unsigned short mask = createMask(position);

	/* (0 AND x) = 0; (1 AND x) = x;
	* Ou seja, invocar a operação AND entre um inteiro e a máscara retorna um valor completamente zerado,
	* exceto na posição onde há um 1 na máscara,
	* que pode ser 0 ou 1 dependendo do bit correspondente no inteiro.
	*
	* Qualquer número diferente de 0 é considerado verdadeiro quando convertido para booleano (o retorno da função é booleano).
	* Ou seja, a função retorna true ou false se o bit estiver ligado ou desligado, respectivamente. */
	return bitwiseAND(integer, mask);
}

// Função para ligar um bit na posição indicada.
unsigned short turnOnBit(unsigned short integer, char position)
{
	unsigned short mask = createMask(position);

	// O operador OR "copia" os bits do valor inteiro (x OR 0 = x) e transforma em 1 onde há um 1 na máscara (x OR 1 = 1).
	unsigned short newInteger = bitwiseOR(integer, mask);

	return newInteger;
}

// Função para desligar um bit na posição indicada.
unsigned short turnOffBit(unsigned short integer, char position)
{
	// Cria uma máscara inversa (vários bits 1 e um bit 0) usando o operador bitwise NOT (~).
	unsigned short mask = ~createMask(position);

	// O operador AND "copia" os bits do valor inteiro (x AND 1 = x) e transforma em 0 onde há um 0 na máscara (x AND 0 = 0).
	unsigned short newInteger = bitwiseAND(integer, mask);

	return newInteger;
}

// Função que retorna os bits de baixa ordem de um inteiro transformando os de alta ordem em 0.
unsigned short lowBits(unsigned short integer)
{
	// Arrasta os bits 8 casas para a esquerda, depois arrasta de volta 8 casas à direita, deixando um rastro de zeros à esquerda.
	unsigned short newInteger = integer << 8;
	newInteger = newInteger >> 8;
	/* EXEMPLO:
	*
	* Entrada:	11011011.00100100
	*					 <<<<<<<<
	* 1ª fase:	00100100.00000000
	*			>>>>>>>>
	* Saída:	00000000.00100100
	*/

	return newInteger;
}

// Função que retorna os bits de alta ordem de um inteiro transformando os de baixa ordem em 0.
unsigned short highBits(unsigned short integer)
{
	// Arrasta os bits 8 casas para a direita, depois arrasta de volta 8 casas à esquerda, deixando um rastro de zeros à direita.
	unsigned short newInteger = integer >> 8;
	newInteger = newInteger << 8;
	/* EXEMPLO:
	*
	* Entrada:	11011011.00100100
	*			>>>>>>>>
	* 1ª fase:	00000000.11011011
	*					 <<<<<<<<
	* Saída:	11011011.00000000
	*/

	return newInteger;
}
