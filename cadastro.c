#include <stdio.h>
#include <string.h>
#include <ctype.h>     /* Biblioteca para manipulação de caracteres */
#include "cadastro.h"  /* Biblioteca criada para cadastrar as informacoes de casa, apartamento ou terreno */
#include "clear.h"     /* Biblioteca criada para executar a função Clear, para apagar o que tiver escrito no terminal ou cmd */


/* Funcao criada para deixar todas as strings com letras maiusculas
para quando for consultar o imovel, as informacoes serem compativeis. */
void StringMaiusculo(char frase[], size_t tamanho){
	int i;

	for(i = 0; i < tamanho-1; i++){
		frase[i] = toupper(frase[i]);
	}
}

void CadastroImoveis(tImovel imovel, FILE *arquivo){
	int lastID;
	Clear();
	printf("\t----------------------------------------------------------------------------------\n");
	printf("\t\t\t\t\t Informações do Imóvel\n");
	printf("\t----------------------------------------------------------------------------------\n");
	//Lendo o endereco do imovel

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
	Clear();

    //Lendo qual é o status do imovel, se esta para venda ou para aluguel
	printf("\n\t----------------------------------------------------------------------------------\n");
	printf("\t|\t\t\t\tTipo da Transação\t\t\t\t |\n");
	printf("\t----------------------------------------------------------------------------------\n");
	printf("\n");
	printf("\t\t[1] Aluguel\n");
	printf("\t\t[2] Venda\n");
	printf("\n");
	printf("\t----------------------------------------------------------------------------------\n");
	printf("\tDigite sua opção: ");
	scanf("%d%*c", &imovel.transacao);
	//Preço
	if(imovel.transacao == 1){
		printf("\tPreço do alugel: ");
		scanf("%lf%*c", &imovel.valor);
	}else if(imovel.transacao == 2){
		printf("\tPreço da venda: ");
		scanf("%lf%*c", &imovel.valor);
	}
	Clear();

    //Lendo qual é o tipo do imovel
    printf("\n\t----------------------------------------------------------------------------------\n");
	printf("\t|\t\t\t\t\tTipo do Imóvel\t\t\t\t |\n");
	printf("\t----------------------------------------------------------------------------------\n");
	printf("\n");
	printf("\t\t[1] Casa\n");
	printf("\t\t[2] Apartamento\n");
	printf("\t\t[3] Terreno\n");
	printf("\n");
	printf("\t----------------------------------------------------------------------------------\n");
	printf("\tDigite sua opção: ");
	scanf("%d", &imovel.tipo);
	Clear();

	switch(imovel.tipo){
		case 1:
		    //Lendo informaçõess da Casa
			printf("\n\t----------------------------------------------------------------------------------\n");
			printf("\t|\t\t\t\tCadastro de Casa \t\t\t\t |\n");
			printf("\t----------------------------------------------------------------------------------\n");
			printf("\tDigite o título da Casa: ");
			getchar();
			fgets(imovel.titulo, Qt, stdin);
			StringMaiusculo(imovel.titulo, strlen(imovel.titulo));
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
		    //Lendo informaçõess do Aparatamento
			printf("\n\t----------------------------------------------------------------------------------\n");
			printf("\t|\t\t\t\tCadastro de Apartamento \t\t\t |\n");
			printf("\t----------------------------------------------------------------------------------\n");
			printf("\tDigite o título do Apartamento: ");
			getchar();
			fgets(imovel.titulo, Qt, stdin);
			StringMaiusculo(imovel.titulo, strlen(imovel.titulo));
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
		    //Lendo informaçõess do Terreno
			printf("\n\t----------------------------------------------------------------------------------\n");
			printf("\t|\t\t\t\tCadastro de Terreno \t\t\t\t |\n");
			printf("\t----------------------------------------------------------------------------------\n");
			printf("\tDigite o título do Terreno: ");
			getchar();
			fgets(imovel.titulo, Qt, stdin);
			StringMaiusculo(imovel.titulo, strlen(imovel.titulo));
			printf("\tDigite a área do terreno: ");
			scanf("%lf", &imovel.ter.area);
			break;
		default:
			printf("Escolha inválida!\n");
	}

	printf("\n\n\t\aCadastro efetuado com sucesso!");

	fwrite(&imovel, sizeof(imovel), 1, arquivo);
}
