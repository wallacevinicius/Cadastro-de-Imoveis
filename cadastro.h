#ifndef CADASTRO_H
#define CADASTRO_H
#define Qt 60

typedef struct{
	int andar;
	double area;
	int quartos;
	int garagens;
	char posicao[Qt];
	double condominio;
}tApartamento;

typedef struct{
	int quartos;
	double areaTer;
	double areaConst;
	int andares;
}tCasa;

typedef struct{
	double area;
}tTerreno;

typedef struct{
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

void CadastroImoveis(tImovel imovel, FILE *arquivo);
void StringMaiusculo(char frase[], size_t tamanho);

#endif