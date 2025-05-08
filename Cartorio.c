#include <stdio.h> // biblioteca de comunicação com o usuário
#include <stdlib.h> // biblioteca de alocação de espaço em memória
#include <locale.h> // biblioteca de alocação de texto por região
#include <string.h> // biblioteca responsável por cuidar das strings

int registro() //funcao para registro dos usuarios no sistema
{
//inixio criacao de variáveis,string
    char arquivo[40];
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];
    
    printf("Digite o CPF a ser cadastrado: ");  //Coletando inormação do usuário
    scanf("%s", cpf); // "%s refere-se às strings
    
    strcpy(arquivo, cpf);  // reponsável por copiar os valores das strings
    
    FILE *file;   // cria o arquivo 
    file = fopen(arquivo, "w");
    fprintf(file,cpf);   //salva o valor da variavel 
    fclose(file);    // fecha o arquivo
    
    file = fopen(arquivo, "a");
    fprintf(file,",");
    fclose(file);
    
    printf("Digite o nome a ser cadastrado: ");
    scanf("%s", nome);
    
    file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);    
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);

	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
    fprintf(file,",");
    fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
		
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese");
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("O arquivo não foi localizado.\n");
	}
		
    while(fgets(conteudo, 200, file) != NULL)    // enquanto estiver escrevendo na string conteudo até 200 valores que estao dentro do aqruivo
    {
    	printf("\nEssas são as informações do usuário: ");
    	printf("%s", conteudo);
    	printf("\n\n");
    	
	}
			
	system("pause");

			
}  

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usuário a ser Deletado");   
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;                //busca o arquivo com as infos
	file = fopen(cpf, "r");   //abre o arquivo, "r" faz ler o cpf
	
	if (file == NULL)
	{
		printf("O usuário não se encontra no sistema! \n");
		system("pause");  //pause da tempo pro usuário ler	
	}
	
	
}
  
  

int main()
{
	int opcao=0;  // criamos a variavel (apenas um = quer dizer atribuiçao de um valor)
	int laco=1;
	
	for(laco=1;laco=1;)
{

    system("cls"); // responsável por limpar a tela
    
	setlocale(LC_ALL, "Portuguese"); // definimos que podemos utilizar acentos (em teoria)
	
	printf("### Cartório da EBAC ###\n\n");
	printf("Escolha a opção desejada do menu:\n\n");
	printf("\t1 - Registrar nomes\n");               // menu pro usuario 
	printf("\t2 - Consultar nomes\n");
	printf("\t3 - Deletar nomes\n\n");
	printf("opção: ");
	
	scanf("%d" , &opcao); // armazenar na variavel opçao o valor que o usuario digitar

	system("cls"); // sistema ira deletar todas as msgs que haviam antes
	
	switch(opcao) 
{
		
	 case 1:
	 registro();
	 break;
		
	 case 2:
	 consulta();
	 break;
		
	 case 3:
	 deletar();
	 break;
		
	 default:
	 printf("você escolheu uma opção invalida. Tente os números 1, 2 ou 3!\n");
	 system("pause");	
	 break; 
		
          } //fim da seleção
			
		

	}
	
	
}



