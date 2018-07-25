#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "cadastro.h"

void StringMaiusculo(char frase[], size_t tamanho){
	int i;

	for(i = 0; i < tamanho-1; i++){
		frase[i] = toupper(frase[i]);
	}
}

void CadastroImoveis(tImovel imovel, FILE *arquivo){
	printf("\t----------------------------------------------------------------------------------\n");
	printf("\t\t\t\t\t Informações do Imóvel\n");
	printf("\t----------------------------------------------------------------------------------\n");
	//Rua
	printf("\tDigite a rua do imóvel: ");
	getchar();
	fgets(imovel.rua, Qt, stdin);
	StringMaiusculo(imovel.rua, strlen(imovel.rua));
	//Numero
	printf("\tDigite o número do imóvel: ");
	scanf("%d%*c", &imovel.numero);
	//Cidade
	printf("\tDigite a cidade do imóvel: ");
	fgets(imovel.cidade, Qt, stdin);
	StringMaiusculo(imovel.cidade, strlen(imovel.cidade));
	//Bairro
	printf("\tDigite o bairro do imóvel: ");
	fgets(imovel.bairro, Qt, stdin);
	StringMaiusculo(imovel.bairro, strlen(imovel.bairro));
	//CEP
	printf("\tDigite o CEP do imóvel: ");
	fgets(imovel.cep, Qt, stdin);
	StringMaiusculo(imovel.cep, strlen(imovel.cep));
	system("cls");
    	system("clear");

	printf("\n\t----------------------------------------------------------------------------------\n");
	printf("\t|\t\t\t\tTipo da Transação\t\t\t\t |\n");
	printf("\t----------------------------------------------------------------------------------\n");
	printf("\t|\t1. Aluguel\t\t\t\t\t\t\t\t |\n");
	printf("\t|\t2. Venda\t\t\t\t\t\t\t\t |\n");
	printf("\t----------------------------------------------------------------------------------\n");
	printf("\tDigite sua opção: ");
	scanf("%d%*c", &imovel.transacao);
	//Preço
	printf("\tPreço do imóvel: ");
	scanf("%lf%*c", &imovel.valor);
	system("cls");
    	system("clear");

    	printf("\n\t----------------------------------------------------------------------------------\n");
	printf("\t|\t\t\t\t\tTipo do Imóvel\t\t\t\t |\n");
	printf("\t----------------------------------------------------------------------------------\n");
	printf("\t|\t1. Casa\t\t\t\t\t\t\t\t\t |\n");
	printf("\t|\t2. Apartamento\t\t\t\t\t\t\t\t |\n");
	printf("\t|\t3. Terreno\t\t\t\t\t\t\t\t |\n");
	printf("\t----------------------------------------------------------------------------------\n");
	printf("\tDigite sua opção: ");
	scanf("%d", &imovel.tipo);
	system("cls");
    	system("clear");

	switch(imovel.tipo){
		case 1:
			printf("\n\t----------------------------------------------------------------------------------\n");
			printf("\t|\t\t\t\tCadastro de Casa \t\t\t\t |\n");
			printf("\t----------------------------------------------------------------------------------\n");
			printf("\tDigite a quantidade de quartos: ");
			scanf("%d", &imovel.casa.quartos);
			printf("\tDigite a quantidade de andares: ");
			scanf("%d", &imovel.casa.andares);
			printf("\tDigite a área do terreno: ");
			scanf("%lf", &imovel.casa.areaTer);
			printf("\tDigite a área do terreno utilizada: ");
			scanf("%lf", &imovel.casa.areaConst);
			break;
		case 2:
			printf("\n\t----------------------------------------------------------------------------------\n");
			printf("\t|\t\t\t\tCadastro de Apartamento \t\t\t |\n");
			printf("\t----------------------------------------------------------------------------------\n");
			printf("\tDigite o andar do apartamento: ");
			scanf("%d", &imovel.ap.andar);
			printf("\tDigite a quantidade de quartos: ");
			scanf("%d", &imovel.ap.quartos);
			printf("\tDigite a quantidade de garagens: ");
			scanf("%d", &imovel.ap.garagens);
			printf("\tDigite o valor do condomínio: ");
			scanf("%lf", &imovel.ap.condominio);
			printf("\tDigite a área do apartamento: ");
			scanf("%lf", &imovel.ap.area);
			printf("\tDigite a posição do apartamento: ");
			getchar();
			fgets(imovel.ap.posicao, Qt, stdin);
			StringMaiusculo(imovel.ap.posicao, strlen(imovel.ap.posicao));
			break;
		case 3:
			printf("\n\t----------------------------------------------------------------------------------\n");
			printf("\t|\t\t\t\tCadastro de Terreno \t\t\t\t |\n");
			printf("\t----------------------------------------------------------------------------------\n");
			printf("\tDigite a área do terreno: ");
			scanf("%lf", &imovel.ter.area);
			break;
		default:
			printf("Escolha inválida!\n");
	}

	puts("\tCadastro efetuado com sucesso!");

	fwrite(&imovel, sizeof(imovel), 1, arquivo);
}