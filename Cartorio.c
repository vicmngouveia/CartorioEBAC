#include <stdio.h> // biblioteca de comunica��o com o usu�rio
#include <stdlib.h> // biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> // biblioteca de aloca��o de texto por regi�o
#include <string.h> // biblioteca respons�vel por cuidar das strings

int registro() //funcao para registro dos usuarios no sistema
{
//inixio criacao de vari�veis,string
    char arquivo[40];
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];
    
    printf("Digite o CPF a ser cadastrado: ");  //Coletando inorma��o do usu�rio
    scanf("%s", cpf); // "%s refere-se �s strings
    
    strcpy(arquivo, cpf);  // repons�vel por copiar os valores das strings
    
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
		printf("O arquivo n�o foi localizado.\n");
	}
		
    while(fgets(conteudo, 200, file) != NULL)    // enquanto estiver escrevendo na string conteudo at� 200 valores que estao dentro do aqruivo
    {
    	printf("\nEssas s�o as informa��es do usu�rio: ");
    	printf("%s", conteudo);
    	printf("\n\n");
    	
	}
			
	system("pause");

			
}  

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usu�rio a ser Deletado");   
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;                //busca o arquivo com as infos
	file = fopen(cpf, "r");   //abre o arquivo, "r" faz ler o cpf
	
	if (file == NULL)
	{
		printf("O usu�rio n�o se encontra no sistema! \n");
		system("pause");  //pause da tempo pro usu�rio ler	
	}
	
	
}
  
  

int main()
{
	int opcao=0;  // criamos a variavel (apenas um = quer dizer atribui�ao de um valor)
	int laco=1;
	
	for(laco=1;laco=1;)
{

    system("cls"); // respons�vel por limpar a tela
    
	setlocale(LC_ALL, "Portuguese"); // definimos que podemos utilizar acentos (em teoria)
	
	printf("### Cart�rio da EBAC ###\n\n");
	printf("Escolha a op��o desejada do menu:\n\n");
	printf("\t1 - Registrar nomes\n");               // menu pro usuario 
	printf("\t2 - Consultar nomes\n");
	printf("\t3 - Deletar nomes\n\n");
	printf("op��o: ");
	
	scanf("%d" , &opcao); // armazenar na variavel op�ao o valor que o usuario digitar

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
	 printf("voc� escolheu uma op��o invalida. Tente os n�meros 1, 2 ou 3!\n");
	 system("pause");	
	 break; 
		
          } //fim da sele��o
			
		

	}
	
	
}



