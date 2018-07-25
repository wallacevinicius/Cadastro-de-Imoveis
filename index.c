#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include "menu.h"
#include "cadastro.h"
#include "consulta.h"

int main(int argc, char const *argv[])
{
	setlocale(LC_ALL, "Portuguese");

	FILE *arquivo;
	arquivo = fopen("imobiliaria.dat", "a+b");
	if(!arquivo){
		printf("Erro ao abrir o arquivo\n");
	}
	
	int opcao, consulta;
	tImovel imovel;

	while(1){
		opcao = Menu();

		if(opcao == 0)
			break;

		switch(opcao){
			case 1:
				system("cls");
				system("clear");
				CadastroImoveis(imovel, arquivo);
				break;
			case 2:
				system("cls");
				system("clear");
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

	}

	fclose(arquivo);

	return 0;
}