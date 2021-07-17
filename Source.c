#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <conio.h>


int program_status = 1;

void read_data()
{
	FILE* fin;
	int a = 0;

	fin = fopen("storage.txt", "r");
	fscanf(fin, "%d", &a);
	printf("%d", a);
	fclose(fin);
}

void help()
{
	system("cls");

	printf("\033[0;31m");
	printf("LOGO: \n");
	printf("\033[0m");
	printf("%s", "Command list:\n a - The command to add an item to the repository\n d - The command to delete an item from the repository\n r - The command for reading an item from the repository\n");
}

void menu()
{
	char str[80];
	const char space_check[4] = " ";
	scanf("%79s", str);

	char help_checker[5] = "help";
	int help_checker_ind = strcmp(str, help_checker);

	char exit_checker[5] = "exit";
	int exit_checker_ind = strcmp(str, exit_checker);

	if (!str[1] || help_checker_ind == 0 || exit_checker_ind == 0)
	{
		switch (str[0])
		{
		case 'a':
			printf("%s", "Add Function");
			break;
		case 'r':
			system("cls");
			read_data();
			break;
		case 'd':
			printf("%s", "Delete Function");
			break;
		case 'h':
			if (help_checker_ind == 0)
			{
				help();
				break;
			}
			else
			{
				system("cls");
				printf("\033[0;31m");
				printf("LOGO: ");
				printf("\033[0m");
				printf("%s", "Fatal Error\n");
				break;
			}

		case 'e':
			if (exit_checker_ind == 0)
			{
				program_status = 0;
				break;
			}
			else
			{
				system("cls");
				printf("\033[0;31m");
				printf("LOGO: ");
				printf("\033[0m");
				printf("%s", "*Fatal Error");
				break;
			}
		default:
			system("cls");
			printf("\033[0;31m");
			printf("LOGO: ");
			printf("\033[0m");
			printf("%s", "Fatal Error\n");
			break;
		}
	}
	else
	{
		system("cls");
		printf("\033[0;31m");
		printf("LOGO: ");
		printf("\033[0m");
		printf("%s", "Fatal Error\n");
	}
		
}

int main()
{
	setlocale(LC_ALL, "Russian");

	while (program_status == 1)
	{
		menu();
	}
	
	return 0;
}