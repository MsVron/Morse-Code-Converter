#include <stdio.h>
#include <string.h>
#include <ctype.h>

void textToMorse(char *str);
void morseToText(char *str);
int isMorse(char *str);

const char *morseTable[36] = {
	".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---",
	"-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-",
	"..-", "...-", ".--", "-..-", "-.--", "--..",
	"-----", ".----", "..---", "...--", "....-", ".....",
	"-....", "--...", "---..", "----."
};

int main()
{
	char inputStr[100];

	printf("Enter a string (text or Morse code): ");
	fgets(inputStr, sizeof(inputStr), stdin);
	inputStr[strcspn(inputStr, "\n")] = 0;

	if (isMorse(inputStr))
		morseToText(inputStr);
	else
		textToMorse(inputStr);

	return 0;
}

int isMorse(char *str)
{
	for (int i = 0; str[i]; i++)
	{
		if (!strchr(".- ", str[i]))
			return 0;
	}
	return 1;
}

void textToMorse(char *str)
{
	int i, j;

	for (i = 0; str[i]; i++)
	{
		if (isalpha(str[i]))
			str[i] = toupper(str[i]);

		if ((str[i] < 'A' || str[i] > 'Z') && (str[i] < '0' || str[i] > '9'))
			continue;

		if (isalpha(str[i]))
			j = str[i] - 'A';
		else
			j = str[i] - '0' + 26;

		printf("%s ", morseTable[j]);
	}
	printf("\n");
}


void morseToText(char *str)
{
	char *token = strtok(str, " ");
	while (token != NULL)
	{
		for (int i = 0; i < 36; i++)
		{
			if (strcmp(token, morseTable[i]) == 0)
			{
				if (i < 26)
					printf("%c", 'A' + i);
				else
					printf("%c", '0' + i - 26);
				break;
			}
		}
		token = strtok(NULL, " ");
	}
	printf("\n");
}
