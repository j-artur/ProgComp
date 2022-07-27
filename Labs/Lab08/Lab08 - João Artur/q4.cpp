int main()
{
	/* Quais das operações abaixo vão ter problemas de precisão? */

	//a)
	float a = 3.78575f * 8.129338f;
	// Essa sim. Os dois números já têm o máximo de dígitos significativos, a multiplicação vai extrapolar esse máximo.

	//b)
	float b = 3e30f + 2e15f;
	// Essa sim. Seria preciso 15 dígitos significativos para representar o resultado.

	//c)
	float c = 20518.56f * 2.0f;
	// Essa sim. O primeiro número já ultrapassa o máximo de dígitos significativos para garantia de precisão.

	//d)
	float d = 3.14159f + 1.45f;
	// Essa não. O número de dígitos significativos permanece 6 após a soma.

	//e)
	float e = 2.0f * 1e30f;
	// Essa não, o valor 1e30f tem precisão de 1 dígito e continua com o mesmo após ser dobrado.
}