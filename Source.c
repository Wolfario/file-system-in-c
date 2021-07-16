#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	char str[80];
	scanf("%79s", str);
	char *token;

	token = strtok(str, " ");

	if (!token[1]) // Дописать принятие хелп функции
	{
		switch (token[0])
		{
		case 'a':
			printf("%s", "Add Function");
			break;
		case 'r':
			printf("%s", "Read Function");
			break;
		case 'd':
			printf("%s", "Delete Function");
			break;
		case 'h':
			printf("%s", "Help Function");
			break;
		default:
			printf("%s", "Fatal Error");
			break;
		}
	}
	else
		printf("%s", "Fatal Error");
	
	return 0;
}