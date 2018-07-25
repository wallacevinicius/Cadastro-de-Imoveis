#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menu.h"
#include "cadastro.h"

int Menu(){
	int opcao;
	printf("\n\n\t--------------------------------- Menu Principal ---------------------------------\n");
	printf("\t|\t\t\t\t\t\t\t\t\t\t |\n");
	printf("\t|\t1. Cadastrar Imóvel \t\t\t\t\t\t\t |\n");
	printf("\t|\t2. Consultar Imóvel \t\t\t\t\t\t\t |\n");
	printf("\t|\t0. Encerrar Programa \t\t\t\t\t\t\t |\n");
	printf("\t|\t\t\t\t\t\t\t\t\t\t |\n");
	printf("\t----------------------------------------------------------------------------------\n");
	printf("\tDigite sua opção: ");
	scanf("%d", &opcao);

	return opcao;
}

int MenuConsulta(){
	int opcao;
	printf("\n\n\t--------------------------------- Menu Consulta ----------------------------------\n");
	printf("\t|\t\t\t\t\t\t\t\t\t\t |\n");
	printf("\t|\t1. Todos os Imóveis \t\t\t\t\t\t\t |\n");
	printf("\t|\t2. Todos os Imóveis com Descrição \t\t\t\t\t |\n");
	printf("\t|\t3. Imóveis para VENDA por TIPO (Casa, Apartamento, Terreno) \t\t |\n");
	printf("\t|\t4. Imóveis para ALUGUEL por TIPO (Casa, Apartamento, Terreno) \t\t |\n");
	printf("\t|\t5. Imóveis para VENDA por BAIRRO \t\t\t\t\t |\n");
	printf("\t|\t6. Imóveis para ALUGUEL por BAIRRO \t\t\t\t\t |\n");
	printf("\t|\t7. Todos os Imóveis por CIDADE \t\t\t\t\t\t |\n");
	printf("\t|\t\t\t\t\t\t\t\t\t\t |\n");
	printf("\t----------------------------------------------------------------------------------\n");
	printf("\tDigite sua opção: ");
	scanf("%d", &opcao);

	return opcao;
}