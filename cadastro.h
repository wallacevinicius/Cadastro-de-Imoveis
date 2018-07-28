#ifndef CADASTRO_H /* Diretiva que executar� o c�digo se a biblioteca CADASTRO_H N�o tiver sido definida */
#define CADASTRO_H
#define Qt 60

/* Estrutura para informa��es da Casa */
typedef struct{
	int andar;
	double area;
	int quartos;
	int garagens;
	char posicao[Qt];
	double condominio;
}tApartamento;

/* Estrutura para informa��es do Apartamento */
typedef struct{
	int quartos;
	double areaTer;
	double areaConst;
	int andares;
}tCasa;

/* Estrutura para informa��es do Terreno */
typedef struct{
	double area;
}tTerreno;

/* Estrutura para informa��es dos Imoveis*/
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

void CadastroImoveis(tImovel imovel, FILE *arquivo); // Chamada da Fun��o Cadastro para preenchimento dos campos da estrutura
void StringMaiusculo(char frase[], size_t tamanho); // Chamada da Fun��o criada para deixar todas as strings com letras maiusculas

#endif /* Encerrando Diretiva CADASTRO_H */
