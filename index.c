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

	FILE *arquivo;
	arquivo = fopen("imobiliaria.dat", "a+b");
	if(!arquivo){
		printf("Erro ao abrir o arquivo\n");
	}
	
	int opcao = 1, consulta;
	tImovel imovel;

	while(opcao){
		opcao = Menu();

		if(opcao == 0)
			break;

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

	fclose(arquivo);

	return 0;
}