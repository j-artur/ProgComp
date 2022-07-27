#include <iostream>

using namespace std;

int main()
{
	const size_t wordsQty = 4;
	const size_t wordLen = 20;

	char words[wordsQty][wordLen];

	cout << "Insert " << wordsQty << " words:\n";
	for (size_t i = 0; i < wordsQty; i++)
		cin >> words[i];

	short allWordsLen = 0;

	for (size_t i = 0; i < wordsQty; i++)
		allWordsLen += strlen(words[i]);

	char* allWords = new char[allWordsLen];

	size_t counter = 0;
	for (size_t i = 0; i < wordsQty; i++)
		for (size_t j = 0; i < wordLen; j++)
		{
			if (!words[i][j])
			{
				allWords[counter] = (i == wordsQty - 1 ? '\0' : ' ');
				counter++;
				break;
			}

			allWords[counter] = words[i][j];
			counter++;
		}

	cout << "Concatenating the words you get:\n";
	cout << allWords;

	delete[] allWords;

	return 0;
}
