#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "cadastro.h"
#include "consulta.h"

void Consulta(tImovel imovel, FILE *arquivo){
	if(imovel.tipo == 1){
		printf("\n\t----------------------------------------------------------------------------------\n");
		printf("\t|\t\t\t\t\tCasa \t\t\t\t\t |\n");
		printf("\t----------------------------------------------------------------------------------\n");
	}else if(imovel.tipo == 2){
		printf("\n\t----------------------------------------------------------------------------------\n");
		printf("\t|\t\t\t\t     Apartamento \t\t\t\t |\n");
		printf("\t----------------------------------------------------------------------------------\n");
	}else if(imovel.tipo == 3){
		printf("\n\t----------------------------------------------------------------------------------\n");
		printf("\t|\t\t\t\t       Terreno \t\t\t\t\t |\n");
		printf("\t----------------------------------------------------------------------------------\n");
	}
	if(imovel.transacao == 1){
		printf("\tImóvel disponivel para ALUGUEL\n");
	}else if(imovel.transacao == 2){
		printf("\tImóvel disponivel para VENDA\n");
	}
	printf("\t----------------------------------------------------------------------------------\n");
	printf("\tEndereço: %s", imovel.rua);
	printf("\t----------------------------------------------------------------------------------\n");
	printf("\tNúmero: %d\n", imovel.numero);
	printf("\t----------------------------------------------------------------------------------\n");
	printf("\tCidade: %s", imovel.cidade);
	printf("\t----------------------------------------------------------------------------------\n");
	printf("\tBairro: %s", imovel.bairro);
	printf("\t----------------------------------------------------------------------------------\n");
	printf("\tCEP: %s",imovel.cep);
	printf("\t----------------------------------------------------------------------------------\n");
	printf("\tPreço: R$ %.2lf\n", imovel.valor);
}

void TodosImoveis(tImovel imovel, FILE *arquivo){
	while(fread(&imovel, sizeof(tImovel), 1, arquivo)){
		Consulta(imovel, arquivo);
		puts("");
	}
}

void TodosImoveisDesc(tImovel imovel, FILE *arquivo){
	while(fread(&imovel, sizeof(tImovel), 1, arquivo)){
		Consulta(imovel, arquivo);
		switch(imovel.tipo){
			case 1:
				DescricaoCasa(imovel, arquivo);
				break;
			case 2:
				DescricaoApartamento(imovel, arquivo);
				break;
			case 3:
				DescricaoTerreno(imovel, arquivo);
				break;
		}
		puts("");
	}
}

void ConsultaCasa(tImovel imovel, FILE *arquivo){
	printf("\n\t----------------------------------------------------------------------------------\n");
	printf("\t|\t\t\t\t\tCasa \t\t\t\t\t |\n");
	printf("\t----------------------------------------------------------------------------------\n");
	printf("\tEndereço: %s", imovel.rua);
	printf("\t----------------------------------------------------------------------------------\n");
	printf("\tNúmero: %d\n", imovel.numero);
	printf("\t----------------------------------------------------------------------------------\n");
	printf("\tCidade: %s", imovel.cidade);
	printf("\t----------------------------------------------------------------------------------\n");
	printf("\tBairro: %s", imovel.bairro);
	printf("\t----------------------------------------------------------------------------------\n");
	printf("\tCEP: %s",imovel.cep);
	printf("\t----------------------------------------------------------------------------------\n");
	printf("\tPreço: R$ %.2lf\n", imovel.valor);
}

void ConsultaAp(tImovel imovel, FILE *arquivo){
	printf("\n\t----------------------------------------------------------------------------------\n");
	printf("\t|\t\t\t\t     Apartamento \t\t\t\t |\n");
	printf("\t----------------------------------------------------------------------------------\n");
	printf("\tEndereço: %s", imovel.rua);
	printf("\t----------------------------------------------------------------------------------\n");
	printf("\tNúmero: %d\n", imovel.numero);
	printf("\t----------------------------------------------------------------------------------\n");
	printf("\tCidade: %s", imovel.cidade);
	printf("\t----------------------------------------------------------------------------------\n");
	printf("\tBairro: %s", imovel.bairro);
	printf("\t----------------------------------------------------------------------------------\n");
	printf("\tCEP: %s",imovel.cep);
	printf("\t----------------------------------------------------------------------------------\n");
	printf("\tPreço: R$ %.2lf\n", imovel.valor);
}

void ConsultaTer(tImovel imovel, FILE *arquivo){
	printf("\n\t----------------------------------------------------------------------------------\n");
	printf("\t|\t\t\t\t       Terreno \t\t\t\t\t |\n");
	printf("\t----------------------------------------------------------------------------------\n");
	printf("\tEndereço: %s", imovel.rua);
	printf("\t----------------------------------------------------------------------------------\n");
	printf("\tNúmero: %d\n", imovel.numero);
	printf("\t----------------------------------------------------------------------------------\n");
	printf("\tCidade: %s", imovel.cidade);
	printf("\t----------------------------------------------------------------------------------\n");
	printf("\tBairro: %s", imovel.bairro);
	printf("\t----------------------------------------------------------------------------------\n");
	printf("\tCEP: %s",imovel.cep);
	printf("\t----------------------------------------------------------------------------------\n");
	printf("\tPreço: R$ %.2lf\n", imovel.valor);
}

void DescricaoCasa(tImovel imovel, FILE *arquivo){
	printf("\t----------------------------------------------------------------------------------\n");
	printf("\tNúmero de Quartos: %d\n", imovel.casa.quartos);
	printf("\t----------------------------------------------------------------------------------\n");
	printf("\tNúmero de Andares: %d\n", imovel.casa.andares);
	printf("\t----------------------------------------------------------------------------------\n");
	printf("\tÁrea do Terreno: %.2lfm\n", imovel.casa.areaTer);
	printf("\t----------------------------------------------------------------------------------\n");
	printf("\tÀrea Construida: %.2lfm\n", imovel.casa.areaConst);
}

void DescricaoApartamento(tImovel imovel, FILE *arquivo){
	printf("\t----------------------------------------------------------------------------------\n");
	printf("\tPreço do Condomínio: %.2lf\n", imovel.ap.condominio);
	printf("\t----------------------------------------------------------------------------------\n");
	printf("\tNúmero de Quartos: %d\n", imovel.ap.quartos);
	printf("\t----------------------------------------------------------------------------------\n");
	printf("\tAndar do Apartamento: %d\n", imovel.ap.andar);
	printf("\t----------------------------------------------------------------------------------\n");
	printf("\tNúmero de Garagens: %d\n", imovel.ap.garagens);
	printf("\t----------------------------------------------------------------------------------\n");
	printf("\tPosição do Apartamento: %s", imovel.ap.posicao);
	printf("\t----------------------------------------------------------------------------------\n");
	printf("\tÁrea do Apartamento: %.2lfm\n", imovel.ap.area);
}

void DescricaoTerreno(tImovel imovel, FILE *arquivo){
	printf("\t----------------------------------------------------------------------------------\n");
	printf("\tÁrea do Terreno: %.2lfm\n", imovel.ter.area);
}

void ConsultaAluguelTipo(tImovel imovel, FILE *arquivo){
	system("cls");
	system("clear");
	int tipoImovel, count = 0;
	printf("\n\t----------------------------------------------------------------------------------\n");
	printf("\t|\t     Imóveis a ALUGUEL por TIPO (Casa, Apartamento, Terreno) \t\t |\n");
	printf("\t----------------------------------------------------------------------------------\n");
	printf("\t|\t1. Casa\t\t\t\t\t\t\t\t\t |\n");
	printf("\t|\t2. Apartamento\t\t\t\t\t\t\t\t |\n");
	printf("\t|\t3. Terreno\t\t\t\t\t\t\t\t |\n");
	printf("\t----------------------------------------------------------------------------------\n");
	printf("\tDigite sua opção: ");
	scanf("%d", &tipoImovel);
	while(fread(&imovel, sizeof(tImovel), 1, arquivo)){
		if(imovel.tipo == tipoImovel && imovel.transacao == 1){
			if(imovel.tipo == 1){
				ConsultaCasa(imovel,arquivo);
				DescricaoCasa(imovel, arquivo);
			}else if(imovel.tipo == 2){
				ConsultaAp(imovel, arquivo);
				DescricaoApartamento(imovel, arquivo);
			}else if(imovel.tipo == 3){
				ConsultaTer(imovel, arquivo);
				DescricaoApartamento(imovel, arquivo);
			}

			count++;
		}

		if(feof(arquivo)) break;
	}

	if(count > 1){
		printf("\n\n\tForam encontrados %d resultados\n", count);
	}else if(count == 1){
		printf("\n\n\tFoi encontrado 1 resultado!\n");
	}else if(count == 0){
		printf("\n\n\tNão foi encontrado nenhum resultado!\n");
	}
}

void ConsultaVendaTipo(tImovel imovel, FILE *arquivo){
	system("cls");
	system("clear");
	int tipoImovel, count;
	printf("\n\t----------------------------------------------------------------------------------\n");
	printf("\t|\t     Imóveis a VENDA por TIPO (Casa, Apartamento, Terreno) \t\t |\n");
	printf("\t----------------------------------------------------------------------------------\n");
	printf("\t|\t1. Casa\t\t\t\t\t\t\t\t\t |\n");
	printf("\t|\t2. Apartamento\t\t\t\t\t\t\t\t |\n");
	printf("\t|\t2. Terreno\t\t\t\t\t\t\t\t |\n");
	printf("\t----------------------------------------------------------------------------------\n");
	printf("\tDigite sua opção: ");
	scanf("%d", &tipoImovel);
	while(fread(&imovel, sizeof(tImovel), 1, arquivo)){
		if(imovel.tipo == tipoImovel && imovel.transacao == 2){
			if(imovel.tipo == 1){
				ConsultaCasa(imovel,arquivo);
				DescricaoCasa(imovel, arquivo);
			}else if(imovel.tipo == 2){
				ConsultaAp(imovel, arquivo);
				DescricaoApartamento(imovel, arquivo);
			}else if(imovel.tipo == 3){
				ConsultaTer(imovel, arquivo);
				DescricaoApartamento(imovel, arquivo);
			}

			count++;
		}

		if(feof(arquivo)) break;
	}

	if(count > 1){
		printf("\n\n\tForam encontrados %d resultados\n", count);
	}else if(count == 1){
		printf("\n\n\tFoi encontrado 1 resultado!\n");
	}else if(count == 0){
		printf("\n\n\tNão foi encontrado nenhum resultado!\n");
	}
}

void ConsultaAluguelBairro(tImovel imovel, FILE *arquivo){
	system("cls");
	system("clear");
	int count = 0, tipo;
	char bairro[Qt];
	printf("\n\t----------------------------------------------------------------------------------\n");
	printf("\t|\t\t\t     Imóveis a ALUGUEL por BAIRRO \t\t\t |\n");
	printf("\t----------------------------------------------------------------------------------\n");
	printf("\tDigite o bairro: ");
	getchar();
	fgets(bairro, Qt, stdin);
	StringMaiusculo(bairro, strlen(bairro));
	while(fread(&imovel, sizeof(tImovel), 1, arquivo)){
		if(!strcmp(imovel.bairro, bairro) && imovel.transacao == 1){
			if(imovel.tipo == 1){
				ConsultaCasa(imovel,arquivo);
				DescricaoCasa(imovel, arquivo);
			}else if(imovel.tipo == 2){
				ConsultaAp(imovel, arquivo);
				DescricaoApartamento(imovel, arquivo);
			}else if(imovel.tipo == 3){
				ConsultaTer(imovel, arquivo);
				DescricaoApartamento(imovel, arquivo);
			}

			count++;
		}

		if(feof(arquivo)) break;
	}

	if(count > 1){
		printf("\n\n\tForam encontrados %d resultados\n", count);
	}else if(count == 1){
		printf("\n\n\tFoi encontrado 1 resultado!\n");
	}else if(count == 0){
		printf("\n\n\tNão foi encontrado nenhum resultado!\n");
	}
}

void ConsultaVendaBairro(tImovel imovel, FILE *arquivo){
	system("cls");
	system("clear");
	int count = 0, tipo;
	char bairro[Qt];
	printf("\n\t----------------------------------------------------------------------------------\n");
	printf("\t|\t\t\t     Imóveis a VENDA por BAIRRO \t\t\t |\n");
	printf("\t----------------------------------------------------------------------------------\n");
	printf("\tDigite o bairro: ");
	getchar();
	fgets(bairro, Qt, stdin);
	StringMaiusculo(bairro, strlen(bairro));
	while(fread(&imovel, sizeof(tImovel), 1, arquivo)){
		if(!strcmp(imovel.bairro, bairro) && imovel.transacao == 2){
			if(imovel.tipo == 1){
				ConsultaCasa(imovel,arquivo);
				DescricaoCasa(imovel, arquivo);
			}else if(imovel.tipo == 2){
				ConsultaAp(imovel, arquivo);
				DescricaoApartamento(imovel, arquivo);
			}else if(imovel.tipo == 3){
				ConsultaTer(imovel, arquivo);
				DescricaoApartamento(imovel, arquivo);
			}

			count++;
		}

		if(feof(arquivo)) break;
	}

	if(count > 1){
		printf("\n\n\tForam encontrados %d resultados\n", count);
	}else if(count == 1){
		printf("\n\n\tFoi encontrado 1 resultado!\n");
	}else if(count == 0){
		printf("\n\n\tNão foi encontrado nenhum resultado!\n");
	}
}

void TodosCidade(tImovel imovel, FILE *arquivo){
	system("cls");
	system("clear");
	int count = 0, tipo;
	char cidade[Qt];
	printf("\n\t----------------------------------------------------------------------------------\n");
	printf("\t|\t\t\t     Imóveis disponíveis por CIDADE \t\t\t |\n");
	printf("\t----------------------------------------------------------------------------------\n");
	printf("\tDigite a cidade: ");
	getchar();
	fgets(cidade, Qt, stdin);
	StringMaiusculo(cidade, strlen(cidade));
	while(fread(&imovel, sizeof(tImovel), 1, arquivo)){
		if(!strcmp(imovel.cidade, cidade)){
			if(imovel.tipo == 1){
				ConsultaCasa(imovel,arquivo);
				DescricaoCasa(imovel, arquivo);
			}else if(imovel.tipo == 2){
				ConsultaAp(imovel, arquivo);
				DescricaoApartamento(imovel, arquivo);
			}else if(imovel.tipo == 3){
				ConsultaTer(imovel, arquivo);
				DescricaoApartamento(imovel, arquivo);
			}

			count++;
		}

		if(feof(arquivo)) break;
	}

	if(count > 1){
		printf("\n\n\tForam encontrados %d resultados\n", count);
	}else if(count == 1){
		printf("\n\n\tFoi encontrado 1 resultado!\n");
	}else if(count == 0){
		printf("\n\n\tNão foi encontrado nenhum resultado!\n");
	}
}