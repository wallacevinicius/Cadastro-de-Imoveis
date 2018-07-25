#ifndef CONSULTA_H
#define CONSULTA_H
#define Qt 60
#include "cadastro.h"

int MenuConsulta();
void TodosImoveis(tImovel imovel, FILE *arquivo);
void TodosImoveisDesc(tImovel imovel, FILE *arquivo);
void DescricaoCasa(tImovel imovel, FILE *arquivo);
void DescricaoApartamento(tImovel imovel, FILE *arquivo);
void DescricaoTerreno(tImovel imovel, FILE *arquivo);
void ConsultaVendaTipo(tImovel imovel, FILE *arquivo);
void ConsultaAluguelTipo(tImovel imovel, FILE *arquivo);
void ConsultaVendaBairro(tImovel imovel, FILE *arquivo);
void ConsultaAluguelBairro(tImovel imovel, FILE *arquivo);
void TodosCidade(tImovel imovel, FILE *arquivo);

#endif