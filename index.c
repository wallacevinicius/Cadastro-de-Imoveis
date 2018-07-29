#include <stdio.h>
#include <stdlib.h>
#include <locale.h> /* Incluindo a biblioteca para a acentuação */
#include <string.h>
#include "menu.h" /* Biblioteca criada para a função Menu, para exibir as respectivas opções do programa */
#include "cadastro.h" /* Diretiva que executará o código se a biblioteca CADASTRO_H Não tiver sido definida */
#include "consulta.h" /* Biblioteca criada para mostar as informações cadastradas pelo usuário */
#include "clear.h" /* Biblioteca criada para a função Clear, para apagar o que tiver escrito no terminal ou cmd */

/* Acesso a linha de comando*/
int main(int argc, char const *argv[]){
	setlocale(LC_ALL, "Portuguese");

	FILE *arquivo;
	arquivo = fopen("database.dat", "a+b");
	if(!arquivo){
		printf("Erro ao abrir o arquivo\n");
	}

	int opcao = 1, consulta;
	int clear = FALSE;
	
	tImovel imovel;

	while(opcao){
		if(!clear){
			Clear();
			clear = TRUE;
		}
		opcao = Menu(); // Chamada da Função Menu

		if(opcao == 0)
			break;

		switch(opcao){
			case 1:
				CadastroImoveis(imovel, arquivo); // Passando os parâmetros para a função CasdastroImoveis
				break;
			case 2:
				consulta = MenuConsulta(); // Chamada de Função MenuConsulta
				switch(consulta){
					case 1:
						TodosImoveis(imovel, arquivo); // Passando os parâmetros para a função TodosImoveis
						break;
					case 2:
						TodosImoveisDesc(imovel, arquivo); // Passando os parâmetros para a função TodosImoveisDesc
						break;
					case 3:
						ConsultaVendaTipo(imovel, arquivo); // Passando os parâmetros para a função ConsultaVendaTipo
						break;
					case 4:
						ConsultaAluguelTipo(imovel, arquivo); // Passando os parâmetros para a função ConsultaAluguelTipo
						break;
					case 5:
						ConsultaVendaBairro(imovel, arquivo); // Passando os parâmetros para a função ConsultaVendaBairro
						break;
					case 6:
						ConsultaAluguelBairro(imovel, arquivo); // Passando os parâmetros para a função ConsultaAluguelBairro
						break;
					case 7:
						TodosCidade(imovel, arquivo); // Passando os parâmetros para a função TodosCidade
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

		fseek(arquivo, 0 ,SEEK_SET); //faz procuras e acessos randomicos em arquivos
	}

	fclose(arquivo);

	return 0;
}
