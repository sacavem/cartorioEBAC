#include <stdio.h> // Biblioteca de Comunica��o com o Usu�rio
#include <stdlib.h> // Biblioteca de Aloca��o de espa�o de mem�ria
#include <locale.h> // Biblioteca de Aloca��o de Texto por Regi�o
#include <string.h> // Biblioteca respons�vel por cuidar das strings

int main()
{
	int opcao=0;
	int x=1;
	
	for(x=1;x=1;)
	{
		
		system("cls"); // Respons�vel por limpar a tela
	
		setlocale(LC_ALL, "Portuguese"); // Defini��o de Linguagem
	
		printf("\tCart�rio da EBAC\n\n"); // Inicio do Menu
		printf("Escolha a op��o desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n"); 
		printf("Op��o: "); // Fim do Menu
	
		scanf("%d", &opcao); // Armazenando a Escolha do Usu�rio
	
		system("cls");
		
		switch(opcao) // In�cio da Sele��o do Menu
		{
			case 1:
				registro(); // Chamada de Fun��es 
				break;
				
			case 2:
				consulta(); 
				break;
			
			case 3:
				deletar();
				break;
				
			default: // Fim da sele��o
				printf("Essa op��o n�o est� dispon�vel\n"); 
				system("pause");
				break;
		}

 	}  
}

int registro() // Fun��o respons�vel por cadastrar o usu�rio no sistema
{
	setlocale(LC_ALL, "Portuguese");
	// inicio da cria��o de vari�veis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	// final da cria��o de vari�veis/string
	printf("Digite o CPF a ser Cadastrado: "); // registrando as informa��es do usu�rio
	scanf("%s", cpf); // %s refere=se a string
	
	strcpy(arquivo, cpf); // Respons�vel por copiar os valores das strings
	
	FILE *file; // cria o arquivo
	file = fopen(arquivo, "w"); // cria o arquivo
	fprintf(file, cpf); // salvo o valor da variavel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o nome a ser Cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file, nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o sobrenome a ser Cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite seu Cargo a ser Cadastrado: ");
	scanf("%s", cargo);
 
	file = fopen(arquivo,"a");
	fprintf(file, cargo);
	fclose(file);
	
	system("pause");
}

int consulta() // Fun��o respons�vel por cosultar as informa��es do usu�rio
{
	setlocale(LC_ALL, "Portuguese");
	// inicio da cria��o de vari�veis/string
	char cpf[40];
	char conteudo[200];
	// final da cria��o de vari�veis/string
	printf("Digite o CPF a ser consultado: "); // cosultando as informa��es do usu�rio
	scanf("%s",cpf); // %s refere=se a string
	
	FILE *file;
	file = fopen(cpf, "r"); // l� o arquivo
	
	if(file == NULL)
	{
		printf("Arquivo n�o Localizado, Tente Novamente");
	}
	
	while(fgets(conteudo, 200, file) != NULL) 
	{
		printf("\nEssas s�o as Informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
}

int deletar() // Fun��o respons�vel por deletar as informa��es do usu�rio
{
	setlocale(LC_ALL, "Portuguese");
	// inicio da cria��o de vari�veis/string
	char cpf[40]; 
	// final da cria��o de vari�veis/string
	printf("Digite o CPF do usu�rio a ser deletado: "); // deletando as informa��es do usu�rio
	scanf("%s", cpf); // %s refere=se a string 
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf, "r"); // l� o arquivo
	
	if(file == NULL)
	{
		printf("O usu�rio n�o se encontra no sistema!.\n");
		system ("pause");
	}
	
	
}

