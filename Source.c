#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	char str[80];
	scanf("%79s", str);
	char *token;

	token = strtok(str, " ");

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
	default:
		printf("%s", "Fatal Error");
		break;
	}

	return 0;
}