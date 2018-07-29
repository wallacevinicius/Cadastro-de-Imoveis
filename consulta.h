#ifndef CONSULTA_H /* Diretiva que executar� o c�digo se a biblioteca CADASTRO_H N�o tiver sido definida */
#define CONSULTA_H
#define Qt 60
#include "cadastro.h" /* Biblioteca criada por nos para cadastrar as informacoes de casa, apartamento ou terreno */

int MenuConsulta(); //Chamando a fun��o de Menu de Consulta
void TodosImoveis(tImovel imovel, FILE *arquivo); //Fun��o que Mostra todos os imoveis
void TodosImoveisDesc(tImovel imovel, FILE *arquivo); //Fun��o que Mostra todos os imoveis por descricao
void DescricaoCasa(tImovel imovel, FILE *arquivo); //Fun��o que Mostra todos os imoveis do tipo casa e suas descricoes
void DescricaoApartamento(tImovel imovel, FILE *arquivo); //Fun��o que Mostra todos os imoveis do tipo apto e suas descricoes
void DescricaoTerreno(tImovel imovel, FILE *arquivo); //Fun��o que Mostra todos os imoveis do tipo terreno e suas descricoes
void ConsultaVendaTipo(tImovel imovel, FILE *arquivo); //Fun��o que Mostra todos os imoveis por tipo que estao a venda
void ConsultaAluguelTipo(tImovel imovel, FILE *arquivo); // Fun��o que Mostra todos os imoveis por tipo que estao disponiveis para aluguel
void ConsultaVendaBairro(tImovel imovel, FILE *arquivo);//Fun��o que Mostra todos os imoveis por bairro que estao disponiveis para venda
void ConsultaAluguelBairro(tImovel imovel, FILE *arquivo);//Fun��o que Mostra todos os imoveis por tipo que estao disponiveis para aluguel
void TodosCidade(tImovel imovel, FILE *arquivo);//Fun��o que Mostra todos os imoveis disponiveis por cidade

#endif /* Encerrando Diretiva CONSULTA_H */
