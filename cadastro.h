#ifndef CADASTRO_H /* Diretiva que executará o código se a biblioteca CADASTRO_H Não tiver sido definida */
#define CADASTRO_H
#define Qt 60

/* Estrutura para informações da Casa */
typedef struct{
	int andar;
	double area;
	int quartos;
	int garagens;
	char posicao[Qt];
	double condominio;
}tApartamento;

/* Estrutura para informações do Apartamento */
typedef struct{
	int quartos;
	double areaTer;
	double areaConst;
	int andares;
}tCasa;

/* Estrutura para informações do Terreno */
typedef struct{
	double area;
}tTerreno;

/* Estrutura para informações dos Imoveis*/
typedef struct{
	char titulo[Qt];
	char rua[Qt];
	int numero;
	char bairro[Qt];
	char cep[Qt];
	char cidade[Qt];
	int transacao;
	int tipo;
	double valor;
	tApartamento ap;
	tCasa casa;
	tTerreno ter;
}tImovel;

void CadastroImoveis(tImovel imovel, FILE *arquivo); // Chamada da Função Cadastro para preenchimento dos campos da estrutura
void StringMaiusculo(char frase[], size_t tamanho); // Chamada da Função criada para deixar todas as strings com letras maiusculas

#endif /* Encerrando Diretiva CADASTRO_H */
