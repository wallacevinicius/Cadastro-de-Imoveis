#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menu.h"
#include "cadastro.h"
#include "clear.h"

int Menu(){
	int opcao;
	printf("\n\n\t--------------------------------- Menu Principal ---------------------------------\n");
	printf("\n");
	printf("\t\t[1] Cadastrar Imóvel \t\t\t\t\t\t\t \n");
	printf("\t\t[2] Consultar Imóvel \t\t\t\t\t\t\t \n");
	printf("\t\t[0] Encerrar Programa \t\t\t\t\t\t\t \n");
	printf("\n");
	printf("\t----------------------------------------------------------------------------------\n");
	printf("\tDigite sua opção: ");
	scanf("%d", &opcao);

	return opcao;
}

int MenuConsulta(){
	Clear();
	int opcao;
	printf("\n\n\t--------------------------------- Menu Consulta ----------------------------------\n");
	printf("\n");
	printf("\t\t[1] Todos os Imóveis\n");
	printf("\t\t[2] Todos os Imóveis com Descrição \n");
	printf("\t\t[3] Imóveis para VENDA por TIPO (Casa, Apartamento, Terreno)\n");
	printf("\t\t[4] Imóveis para ALUGUEL por TIPO (Casa, Apartamento, Terreno)\n");
	printf("\t\t[5] Imóveis para VENDA por BAIRRO\n");
	printf("\t\t[6] Imóveis para ALUGUEL por BAIRRO\n");
	printf("\t\t[7] Todos os Imóveis por CIDADE\n");
	printf("\n");
	printf("\t----------------------------------------------------------------------------------\n");
	printf("\tDigite sua opção: ");
	scanf("%d", &opcao);

	return opcao;
}