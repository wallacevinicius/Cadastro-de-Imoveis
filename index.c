/*
	-------------------------------------------------------------------------------------
	|		CADASTRO DE IMÓVEIS EM C		|
	|							|
	| * Primeiro projeto do Laboratório de Programação I 	|
	| * Desenvolvido por Wallace, Rebeca e Jósion 		|
	-------------------------------------------------------------------------------------
	
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include "menu.h"
#include "cadastro.h"
#include "consulta.h"
#include "clear.h"

int main(int argc, char const *argv[])
{
	setlocale(LC_ALL, "Portuguese");

	//Abertura do arquivo
	FILE *arquivo;
	arquivo = fopen("imobiliaria.dat", "a+b");
	if(!arquivo){
		printf("Erro ao abrir o arquivo\n");
	}
	
	int opcao = 1, consulta, clear = 0;
	tImovel imovel;

	while(opcao){
		//Limpa a tela apenas uma vez quando o programa é executado
		if(!clear)
			Clear();

		clear++;

		opcao = Menu();

		if(opcao == 0)
			break;

		//Menu de opções
		switch(opcao){
			case 1:
				CadastroImoveis(imovel, arquivo);
				break;
			case 2:
				consulta = MenuConsulta();
				switch(consulta){
					case 1:
						TodosImoveis(imovel, arquivo);
						break;
					case 2:
						TodosImoveisDesc(imovel, arquivo);
						break;
					case 3:
						ConsultaVendaTipo(imovel, arquivo);
						break;
					case 4:
						ConsultaAluguelTipo(imovel, arquivo);
						break;
					case 5:
						ConsultaVendaBairro(imovel, arquivo);
						break;
					case 6:
						ConsultaAluguelBairro(imovel, arquivo);
						break;
					case 7:
						TodosCidade(imovel, arquivo);
						break;
				}
		}
		printf("\n\n\t---------------------------- O que deseja fazer agora? ---------------------------\n");
		printf("\n");
		printf("\t\t[1] Voltar ao Menu\n");
		printf("\t\t[0] Encerrar Programa\n");
		printf("\n");
		printf("\t----------------------------------------------------------------------------------\n");
		printf("\tDigite sua opção: ");
		scanf("%d", &opcao);
		Clear();

		fseek(arquivo, 0 ,SEEK_SET);

	}

	//Encerramento do arquivo
	fclose(arquivo);

	return 0;
}