#include "restaurante.h"

float procurarPreco(t_menu *menu, int tamMenu, char *codigoProduto)
{
    for(int i = 0; i < tamMenu; i++) 
    {
        if(strcmp(menu[i].codigo, codigoProduto) == 0) 
            return (menu[i].preco);
    }
    return (-1);
}

t_pedidos *procurarPedido(t_pedidos *pedidos, char *codigoProduto) 
{
    t_pedidos *aux = pedidos;
    while(aux != NULL) 
    {
        if(strcmp(aux->codigoPedido, codigoProduto) == 0) 
            return (aux);
        aux = aux->prox;
    }
    return (NULL);
}


void fazerPedido(t_mesas *mesas, int numMesa, t_menu *menu, int tamMenu, char *codigoProduto, int quantidade) 
{
    t_mesas *mesa = procurarMesa(mesas, numMesa);
    if(mesa != NULL) 
    {
        float preco = procurarPreco(menu, tamMenu, codigoProduto);
        if(preco != -1) 
        {
            t_pedidos *pedidoExistente = procurarPedido(mesa->pedidos, codigoProduto);
            if(pedidoExistente != NULL) 
            {
                pedidoExistente->qtd += quantidade;
                mesa->total += preco * quantidade;
            } 
            else 
            {
                t_pedidos *novoPedido = (t_pedidos *) malloc(sizeof(t_pedidos));
                strcpy(novoPedido->codigoPedido, codigoProduto);
                novoPedido->qtd = quantidade;
                novoPedido->prox = NULL;
                
                if(mesa->pedidos == NULL) 
                    mesa->pedidos = novoPedido; 
                else 
                {
                    t_pedidos *aux = mesa->pedidos;
                    while(aux->prox != NULL) 
                        aux = aux->prox;
                    aux->prox = novoPedido;
                }
                mesa->total += preco * quantidade;
            }
        } 
        else
            printf("Produto não encontrado.\n");
    }
    else 
        printf("Mesa não encontrada.\n");
}

char *procurarGarcon(t_garcon *garcons, int tamGarcons, char *codigoGarcon)
{
    for(int i = 0; i < tamGarcons; i++)
    {
        if(strcmp(garcons[i].codigo, codigoGarcon) == 0)
            return (garcons[i].nome);
    }
    return (NULL);
}

char *procurarNomeProduto(t_menu *menu, int tamMenu, char *codigoProduto)
{
    for(int i = 0; i < tamMenu; i++)
    {
        if(strcmp(menu[i].codigo, codigoProduto) == 0)
            return (menu[i].nome);
    }
    return (NULL);
}

void fecharConta(t_mesas **mesas, int numMesa, t_garcon *garcons, int tamGarcons, t_menu *menu, int tamMenu)
{
    t_mesas *mesa = procurarMesa(*mesas, numMesa);
    if(mesa != NULL) 
    {
        char *nomeGarcon = procurarGarcon(garcons, tamGarcons, mesa->codigoGarcon);
        printf("Nota Fiscal:\n");
        printf("Mesa: %d\n", numMesa);
        printf("Garcon: %s\n", nomeGarcon);
        printf("Consumo:\n");
        t_pedidos *pedido = mesa->pedidos;
        while(pedido != NULL)
        {
            char *nomeProduto = procurarNomeProduto(menu, tamMenu, pedido->codigoPedido);
            printf("Produto: %s, Quantidade: %d\n", nomeProduto, pedido->qtd);
            pedido = pedido->prox;
        }
        printf("Total: %.2f\n", mesa->total);
        removerMesa(mesas, numMesa);
    }
    else
        printf("Mesa não encontrada.\n");
}
