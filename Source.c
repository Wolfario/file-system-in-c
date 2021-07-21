#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <conio.h>


int program_status = 1;

void print_logo()
{
	printf("\033[0;31m");
	printf("LOGO: ");
	printf("\033[0m");
}

void add_data()
{
	FILE* fin;
	int checker = 2;
	char buffer[1024];
	char* token;
	const char determinant_list[3] = ";~";
	char potentional_name[100];
	char potentional_value[100];

	if ((fin = fopen("storage.txt", "r")) == NULL)
	{
		print_logo();
		printf("Не удалось открыть файл\n");
	}
	else
	{
		fgets(buffer, 1023, fin);

		token = strtok(buffer, determinant_list);
		printf("Please enter the name of your item: ");
		scanf("%99s", potentional_name);
		while (token != NULL && checker != 0)
		{
			if (checker % 2 == 0 && checker != -1)
			{
				if (strcmp(potentional_name, token) == 0)
				{
					system("cls");
					print_logo();
					printf("An item with this name already exists, please name it differently.\n");
					checker = -1;
				}
			}

			token = strtok(NULL, determinant_list);
			checker++;
		}

		fclose(fin);

		if (checker != 0)
		{
			if ((fin = fopen("storage.txt", "a+")) == NULL)
			{
				print_logo();
				printf("Не удалось открыть файл\n");
			}
			else
			{
				printf("\n");
				printf("Please enter the value of your item: ");
				scanf("%99s", potentional_value);
				printf("\n");
				fprintf(fin, "%s~%s;", potentional_name, potentional_value);
			}
			
			fclose(fin);
			system("cls");
		}
		else
		{
			add_data();
		}
	}
}

void read_data()
{
	FILE* fin;
	int checker = 2;
	char str[80];
	char buffer[1024];
	char* token;
	const char determinant_list[3] = ";~";

	if ((fin = fopen("storage.txt", "r")) == NULL)
	{
		print_logo();
		printf("Не удалось открыть файл\n");
	}
	else 
	{
		printf("\033[0;31m");
		printf("%s", "List of items. You need to enter the name of one of the proposed items:\n");
		printf("\033[0m");		

		fgets(buffer, 1023, fin);
	
		token = strtok(buffer, determinant_list);
		while (token != NULL)
		{
			if ((checker % 2) == 0)
			{
				printf("%s\n", token);
			}
			
			token = strtok(NULL, determinant_list);
			checker++;
		}
		
		fclose(fin);
		if ((fin = fopen("storage.txt", "r")) == NULL)
		{
			print_logo();
			printf("Не удалось открыть файл\n");
		}
		
		checker = 2;
		fgets(buffer, 1023, fin);
		token = strtok(buffer, determinant_list);
		scanf("%79s", str);

		while (token != NULL && checker != 0)
		{
			if ((checker % 2) == 0)
			{
				if (strcmp(str, token) == 0)
				{
					system("cls");
					printf("Name: %s\n", token);
					token = strtok(NULL, determinant_list);
					printf("Value: %s\n", token);
					checker = -1;
				}
					
			}

			token = strtok(NULL, determinant_list);
			++checker;	
		}

		fclose(fin);

		if (checker != 0)
		{
			system("cls");
			printf("\033[0;31m");
			printf("%s", "An invalid item name was entered. Try again:\n");
			printf("\033[0m");
			read_data();
		}	
	}

}

void help()
{
	system("cls");

	print_logo();
	printf("%s", "\nCommand list:\n a - The command to add an item to the repository\n d - The command to delete an item from the repository\n r - The command for reading an item from the repository\n");
}

void menu()
{
	char str[80];
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
			add_data();
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
				print_logo();
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
				print_logo();
				printf("%s", "*Fatal Error");
				break;
			}
		default:
			system("cls");
			print_logo();
			printf("%s", "Fatal Error\n");
			break;
		}
	}
	else
	{
		system("cls");
		print_logo();
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