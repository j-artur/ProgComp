enum trave { LEsq, LDir, CantoEsq, CantoDir, Centro };

union jogador
{
	char nome[25];
	int numero;
};

struct gol
{
	jogador jog; // numero ou vetor de 25 char
	float x, y, z; // posição da bola nas coordenadas
	trave local; // onde a bola entrou
	float velo; // velocidade da bola
	float acel; // aceleração da bola
};

gol estatistica[10]; // estatísticas para até 10 gols

/*
*
i) estatistica						gol[10]
j) estatistica[4]					gol
k) estatistica[1].jog				jogador
l) estatistica->jog.numero			int
m) (estatistica + 9)->local			trave
n) estatistica[2].velo				float
o) (estatistica + 1)->jog.nome[0]	char[25]
p) estatistica[6].acel				float
*
*/