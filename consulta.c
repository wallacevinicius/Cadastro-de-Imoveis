#include <stdio.h>
#include <string.h>
#include "cadastro.h" /* Biblioteca criada para cadastrar as informacoes de casa, apartamento ou terreno */
#include "consulta.h" /* Biblioteca criada para mostar as informações cadastradas pelo usuário */
#include "clear.h" /* Biblioteca criada para a função Clear, para apagar o que tiver escrito no terminal ou cmd */

/* Funçao para Consulta por tipo de Imovel*/
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
	/* Escolha do tipo de transação que pode ser ser realizada */
	if(imovel.transacao == 1){
		printf("\tImóvel disponivel para ALUGUEL\n");
	}else if(imovel.transacao == 2){
		printf("\tImóvel disponivel para VENDA\n");
	}
	printf("\tTítulo do Imóvel: %s", imovel.titulo);
	printf("\tEndereço: %s", imovel.rua);
	printf("\tNúmero: %d\n", imovel.numero);
	printf("\tCidade: %s", imovel.cidade);
	printf("\tBairro: %s", imovel.bairro);
	printf("\tCEP: %s",imovel.cep);
	printf("\tPreço: R$ %.2lf\n", imovel.valor);
}

/* Funçao para Consulta de Todos os Imóveis */
void TodosImoveis(tImovel imovel, FILE *arquivo){
	int count = 0;
	while(fread(&imovel, sizeof(tImovel), 1, arquivo)){
		Consulta(imovel, arquivo);
		printf("\t----------------------------------------------------------------------------------\n\n");
		puts("");
		count++;
	}

	if(count > 1){
		printf("\n\n\tForam encontrados %d resultados\n", count);
	}else if(count == 1){
		printf("\n\n\tFoi encontrado 1 resultado!\n");
	}else if(count == 0){
		printf("\n\n\tNão foi encontrado nenhum resultado!\n");
	}
}

/* Funçao para Consulta de Todos os Imóveis por Descrição */
void TodosImoveisDesc(tImovel imovel, FILE *arquivo){
	int count = 0;
	while(fread(&imovel, sizeof(tImovel), 1, arquivo)){
		Consulta(imovel, arquivo);
		switch(imovel.tipo){
			case 1:
				DescricaoCasa(imovel, arquivo); // Passando os parâmetros para a função DescricaoCasa
				break;
			case 2:
				DescricaoApartamento(imovel, arquivo); // Passando os parâmetros para a função DescricaoApartamento
				break;
			case 3:
				DescricaoTerreno(imovel, arquivo); // Passando os parâmetros para a função DescricaoTerreno
				break;
		}
		puts("");
		count++; // Contador pra indicar o número de imóveis encontrados
	}

	if(count > 1){
		printf("\n\n\tForam encontrados %d resultados\n", count);
	}else if(count == 1){
		printf("\n\n\tFoi encontrado 1 resultado!\n");
	}else if(count == 0){
		printf("\n\n\tNão foi encontrado nenhum resultado!\n");
	}
}

/* Funçao para Consultar informações de Casa */
void ConsultaCasa(tImovel imovel, FILE *arquivo){
	printf("\n\t----------------------------------------------------------------------------------\n");
	printf("\t|\t\t\t\t\tCasa \t\t\t\t\t |\n");
	printf("\t----------------------------------------------------------------------------------\n");
	printf("\tTítulo do Imóvel: %s", imovel.titulo);
	printf("\tEndereço: %s", imovel.rua);
	printf("\tNúmero: %d\n", imovel.numero);
	printf("\tCidade: %s", imovel.cidade);
	printf("\tBairro: %s", imovel.bairro);
	printf("\tCEP: %s",imovel.cep);
	printf("\tPreço: R$ %.2lf\n", imovel.valor);
}

/* Funçao para Consultar informações de Apartamento */
void ConsultaAp(tImovel imovel, FILE *arquivo){
	printf("\n\t----------------------------------------------------------------------------------\n");
	printf("\t|\t\t\t\t     Apartamento \t\t\t\t |\n");
	printf("\t----------------------------------------------------------------------------------\n");
	printf("\tTítulo do Imóvel: %s", imovel.titulo);
	printf("\tEndereço: %s", imovel.rua);
	printf("\tNúmero: %d\n", imovel.numero);
	printf("\tCidade: %s", imovel.cidade);
	printf("\tBairro: %s", imovel.bairro);
	printf("\tCEP: %s",imovel.cep);
	printf("\tPreço: R$ %.2lf\n", imovel.valor);
}

/* Funçao para Consultar informações de Terreno */
void ConsultaTer(tImovel imovel, FILE *arquivo){
	printf("\n\t----------------------------------------------------------------------------------\n");
	printf("\t|\t\t\t\t       Terreno \t\t\t\t\t |\n");
	printf("\t----------------------------------------------------------------------------------\n");
	printf("\tTítulo do Imóvel: %s", imovel.titulo);
	printf("\tEndereço: %s", imovel.rua);
	printf("\tNúmero: %d\n", imovel.numero);
	printf("\tCidade: %s", imovel.cidade);
	printf("\tBairro: %s", imovel.bairro);
	printf("\tCEP: %s",imovel.cep);
	printf("\tPreço: R$ %.2lf\n", imovel.valor);
}

/* Funçao para Consultar informações de Casa */
void DescricaoCasa(tImovel imovel, FILE *arquivo){
	printf("\tNúmero de Quartos: %d\n", imovel.casa.quartos);
	printf("\tNúmero de Andares: %d\n", imovel.casa.andares);
	printf("\tÁrea do Terreno: %.2lfm\n", imovel.casa.areaTer);
	printf("\tÀrea Construida: %.2lfm\n", imovel.casa.areaConst);
	printf("\t----------------------------------------------------------------------------------\n\n");
}

void DescricaoApartamento(tImovel imovel, FILE *arquivo){
	printf("\tPreço do Condomínio: %.2lf\n", imovel.ap.condominio);
	printf("\tNúmero de Quartos: %d\n", imovel.ap.quartos);
	printf("\tAndar do Apartamento: %d\n", imovel.ap.andar);
	printf("\tNúmero de Garagens: %d\n", imovel.ap.garagens);
	printf("\tPosição do Apartamento: %s", imovel.ap.posicao);
	printf("\tÁrea do Apartamento: %.2lfm\n", imovel.ap.area);
	printf("\t----------------------------------------------------------------------------------\n\n");
}

void DescricaoTerreno(tImovel imovel, FILE *arquivo){
	printf("\tÁrea do Terreno: %.2lfm\n", imovel.ter.area);
	printf("\t----------------------------------------------------------------------------------\n\n");
}

/* Funçao para Consulta de Aluguel por tipo de Imóvel */
void ConsultaAluguelTipo(tImovel imovel, FILE *arquivo){
	Clear();
	int tipoImovel, count = 0;
	printf("\n\t----------------------------------------------------------------------------------\n");
	printf("\t|\t     Imóveis a ALUGUEL por TIPO (Casa, Apartamento, Terreno) \t\t |\n");
	printf("\t----------------------------------------------------------------------------------\n");
	printf("\n");
	printf("\t\t[1] Casa\n");
	printf("\t\t[2] Apartamento\n");
	printf("\t\t[3] Terreno\n");
	printf("\n");
	printf("\t----------------------------------------------------------------------------------\n");
	printf("\tDigite sua opção: ");
	scanf("%d", &tipoImovel);
	while(fread(&imovel, sizeof(tImovel), 1, arquivo)){
		if(imovel.tipo == tipoImovel && imovel.transacao == 1){
			switch(imovel.tipo){
				case 1:
					ConsultaCasa(imovel, arquivo); // Passando os parâmetros para a função ConsultaCasa
					DescricaoCasa(imovel, arquivo); // Passando os parâmetros para a função DescricaoCasa
					break;
				case 2:
					ConsultaAp(imovel, arquivo); // Passando os parâmetros para a função ConsultaAp
					DescricaoApartamento(imovel, arquivo); // Passando os parâmetros para a função DescricaoApartamento
					break;
				case 3:
					ConsultaTer(imovel, arquivo); // Passando os parâmetros para a função ConsultaTer
					DescricaoTerreno(imovel, arquivo); // Passando os parâmetros para a função DescricaoTerreno
					break;
			}

			count++; // Contador para informar o numero de imóveis para Aluguel
		}

		if(feof(arquivo)) break; // retorna Não zero se o arquivo chegou ao EOF, caso contrário retorna a zero
	}

	if(count > 1){
		printf("\n\n\tForam encontrados %d resultados\n", count);
	}else if(count == 1){
		printf("\n\n\tFoi encontrado 1 resultado!\n");
	}else if(count == 0){
		printf("\n\n\tNão foi encontrado nenhum resultado!\n");
	}
}

/* Funçao para Consulta de Venda por tipo de Imóvel */
void ConsultaVendaTipo(tImovel imovel, FILE *arquivo){
	Clear();
	int tipoImovel, count = 0;
	printf("\n\t----------------------------------------------------------------------------------\n");
	printf("\t|\t     Imóveis a VENDA por TIPO (Casa, Apartamento, Terreno) \t\t |\n");
	printf("\t----------------------------------------------------------------------------------\n");
	printf("\n");
	printf("\t\t[1] Casa\n");
	printf("\t\t[2] Apartamento\n");
	printf("\t\t[3] Terreno\n");
	printf("\n");
	printf("\t----------------------------------------------------------------------------------\n");
	printf("\tDigite sua opção: ");
	scanf("%d", &tipoImovel);
	while(fread(&imovel, sizeof(tImovel), 1, arquivo)){
		if(imovel.tipo == tipoImovel && imovel.transacao == 2){
			switch(imovel.tipo){
				case 1:
					ConsultaCasa(imovel, arquivo); // Passando os parâmetros para a função ConsultaCasa
					DescricaoCasa(imovel, arquivo); // Passando os parâmetros para a função DescricaoCasa
					break;
				case 2:
					ConsultaAp(imovel, arquivo); // Passando os parâmetros para a função ConsultaAp
					DescricaoApartamento(imovel, arquivo); // Passando os parâmetros para a função DescricaoAp
					break;
				case 3:
					ConsultaTer(imovel, arquivo); // Passando os parâmetros para a função ConsultaTer
					DescricaoTerreno(imovel, arquivo); // Passando os parâmetros para a função DescricaoTerreno
					break;
			}
			count++; // Contador para informar o numero de imóveis para Venda
		}

		if(feof(arquivo)) break; // retorna Não zero se o arquivo chegou ao EOF, caso contrário retorna a zero
	}

	if(count > 1){
		printf("\n\n\tForam encontrados %d resultados\n", count);
	}else if(count == 1){
		printf("\n\n\tFoi encontrado 1 resultado!\n");
	}else if(count == 0){
		printf("\n\n\tNão foi encontrado nenhum resultado!\n");
	}
}

/* Funçao para Consulta de Aluguel por Bairro */
void ConsultaAluguelBairro(tImovel imovel, FILE *arquivo){
	Clear();
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
/*
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
*/
            switch(imovel.tipo){
                case 1:
                    ConsultaCasa(imovel, arquivo); // Passando os parâmetros para a função ConsultaCasa
                    DescricaoCasa(imovel, arquivo); // Passando os parâmetros para a função DescricaoCasa
                    break;
                case 2:
                    ConsultaAp(imovel, arquivo); // Passando os parâmetros para a função DescricaoAp
                    DescricaoApartamento(imovel, arquivo); // Passando os parâmetros para a função DescricaoApartamento
                    break;
                case 3:
                    ConsultaTer(imovel, arquivo); // Passando os parâmetros para a função DescricaoTer
                    DescricaoTerreno(imovel, arquivo); // Passando os parâmetros para a função DescricaoTerreno
                    break;
			}

			count++; // Contador para informar o numero de imóveis para Aluguel por Bairro
		}

		if(feof(arquivo)) break; // retorna Não zero se o arquivo chegou ao EOF, caso contrário retorna a zero
	}

	if(count > 1){
		printf("\n\n\tForam encontrados %d resultados\n", count);
	}else if(count == 1){
		printf("\n\n\tFoi encontrado 1 resultado!\n");
	}else if(count == 0){
		printf("\n\n\tNão foi encontrado nenhum resultado!\n");
	}
}

/* Funçao para Consulta de Venda por Bairro */
void ConsultaVendaBairro(tImovel imovel, FILE *arquivo){
	Clear();
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
/*
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
*/
            switch(imovel.tipo){
                case 1:
                    ConsultaCasa(imovel, arquivo); // Passando os parâmetros para a função ConsultaCasa
                    DescricaoCasa(imovel, arquivo); // Passando os parâmetros para a função DescricaoCasa
                    break;
                case 2:
                    ConsultaAp(imovel, arquivo); // Passando os parâmetros para a função ConsultaAp
                    DescricaoApartamento(imovel, arquivo); // Passando os parâmetros para a função DescricaoApartamento
                    break;
                case 3:
                    ConsultaTer(imovel, arquivo); // Passando os parâmetros para a função ConsultaTer
                    DescricaoTerreno(imovel, arquivo); // Passando os parâmetros para a função DescricaoTerreno
                    break;
			}

			count++; // Contador para informar o numero de imóveis para Venda por Bairro
		}

		if(feof(arquivo)) break; // retorna Não zero se o arquivo chegou ao EOF, caso contrário retorna a zero
	}

	if(count > 1){
		printf("\n\n\tForam encontrados %d resultados\n", count);
	}else if(count == 1){
		printf("\n\n\tFoi encontrado 1 resultado!\n");
	}else if(count == 0){
		printf("\n\n\tNão foi encontrado nenhum resultado!\n");
	}
}

/* Funçao para Consulta de Todos imóveis por Cidade*/
void TodosCidade(tImovel imovel, FILE *arquivo){
	Clear();
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
/*
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
*/
            switch(imovel.tipo){
                case 1:
                    ConsultaCasa(imovel, arquivo); // Passando os parâmetros para a função ConsultaCasa
                    DescricaoCasa(imovel, arquivo); // Passando os parâmetros para a função DescricaoCasa
                    break;
                case 2:
                    ConsultaAp(imovel, arquivo); // Passando os parâmetros para a função ConsultaAp
                    DescricaoApartamento(imovel, arquivo); // Passando os parâmetros para a função DescricaoApartamento
                    break;
                case 3:
                    ConsultaTer(imovel, arquivo); // Passando os parâmetros para a função ConsultaTer
                    DescricaoTerreno(imovel, arquivo); // Passando os parâmetros para a função DescricaoTerreno
                    break;
			}

			count++; // Contador para informar o numero de todos imóveis por cidade
		}

		if(feof(arquivo)) break; // retorna Não zero se o arquivo chegou ao EOF, caso contrário retorna a zero
	}

	if(count > 1){
		printf("\n\n\tForam encontrados %d resultados\n", count);
	}else if(count == 1){
		printf("\n\n\tFoi encontrado 1 resultado!\n");
	}else if(count == 0){
		printf("\n\n\tNão foi encontrado nenhum resultado!\n");
	}
}
