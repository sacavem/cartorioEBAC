#include <stdio.h> // Biblioteca de Comunicação com o Usuário
#include <stdlib.h> // Biblioteca de Alocação de espaço de memória
#include <locale.h> // Biblioteca de Alocação de Texto por Região
#include <string.h> // Biblioteca responsável por cuidar das strings

int main()
{
	int opcao=0;
	int x=1;
	
	for(x=1;x=1;)
	{
		
		system("cls"); // Responsável por limpar a tela
	
		setlocale(LC_ALL, "Portuguese"); // Definição de Linguagem
	
		printf("\tCartório da EBAC\n\n"); // Inicio do Menu
		printf("Escolha a opção desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n"); 
		printf("Opção: "); // Fim do Menu
	
		scanf("%d", &opcao); // Armazenando a Escolha do Usuário
	
		system("cls");
		
		switch(opcao) // Início da Seleção do Menu
		{
			case 1:
				registro(); // Chamada de Funções 
				break;
				
			case 2:
				consulta(); 
				break;
			
			case 3:
				deletar();
				break;
				
			default: // Fim da seleção
				printf("Essa opção não está disponível\n"); 
				system("pause");
				break;
		}

 	}  
}

int registro() // Função responsável por cadastrar o usuário no sistema
{
	setlocale(LC_ALL, "Portuguese");
	// inicio da criação de variáveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	// final da criação de variáveis/string
	printf("Digite o CPF a ser Cadastrado: "); // registrando as informações do usuário
	scanf("%s", cpf); // %s refere=se a string
	
	strcpy(arquivo, cpf); // Responsável por copiar os valores das strings
	
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

int consulta() // Função responsável por cosultar as informações do usuário
{
	setlocale(LC_ALL, "Portuguese");
	// inicio da criação de variáveis/string
	char cpf[40];
	char conteudo[200];
	// final da criação de variáveis/string
	printf("Digite o CPF a ser consultado: "); // cosultando as informações do usuário
	scanf("%s",cpf); // %s refere=se a string
	
	FILE *file;
	file = fopen(cpf, "r"); // lê o arquivo
	
	if(file == NULL)
	{
		printf("Arquivo não Localizado, Tente Novamente");
	}
	
	while(fgets(conteudo, 200, file) != NULL) 
	{
		printf("\nEssas são as Informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
}

int deletar() // Função responsável por deletar as informações do usuário
{
	setlocale(LC_ALL, "Portuguese");
	// inicio da criação de variáveis/string
	char cpf[40]; 
	// final da criação de variáveis/string
	printf("Digite o CPF do usuário a ser deletado: "); // deletando as informações do usuário
	scanf("%s", cpf); // %s refere=se a string 
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf, "r"); // lê o arquivo
	
	if(file == NULL)
	{
		printf("O usuário não se encontra no sistema!.\n");
		system ("pause");
	}
	
	
}

