#ifndef RESTAURANTE_H
#define RESTAURANTE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct pedidos
{
    char codigoPedido[10];
    int qtd;
    struct pedidos *prox;
}               t_pedidos;

typedef struct mesas
{
    int numero;
    char codigoGarcon[10];
    float total;
    struct mesas *prox;
    struct mesas *ant;
    t_pedidos *pedidos;
}               t_mesas;

typedef struct menu
{
    char codigo[10];
    char nome[50];
    float preco;
}               t_menu;

typedef struct garcon
{
    char nome[50];
    char codigo[10];
}               t_garcon;

t_mesas *procurarMesa(t_mesas *mesas, int numero);
t_mesas *criarMesa(t_mesas **mesas, int numero, char *codigoGarcon, t_menu *menu, int tamMenu);
void fazerPedido(t_mesas *mesas, int numMesa, t_menu *menu, int tamMenu, char *codigoProduto, int quantidade);
t_pedidos *procurarPedido(t_pedidos *pedidos, char *codigoProduto);
float procurarPreco(t_menu *menu, int tamMenu, char *codigoProduto);
void fecharConta(t_mesas **mesas, int numMesa, t_garcon *garcons, int tamGarcons, t_menu *menu, int tamMenu);
void removerMesa(t_mesas **mesas, int numMesa);
t_garcon *inserirGarcon(t_garcon *garcon, int tamGarcon);
t_garcon *removerGarcon(t_garcon *garcon, char *codigoGarcon, int tamGarcon);
void modificarGarcon(t_garcon *garcon, int tamGarcon, char *codigoGarcon, int opcao);
void listarGarcon(t_garcon *garcon, int tamGarcon);
void salvarGarcon(t_garcon *garcon, int tamGarcon);
t_menu *inserirMenu(t_menu *menu, int tamMenu);
t_menu *removerMenu(t_menu *menu, char *codigo, int tamMenu);
void modificarMenu(t_menu *menu, int tamMenu, char *codigo, int opcao);
void listarMenu(t_menu *menu, int tamMenu);
void salvarMenu(t_menu *menu, int tamMenu);
#endif