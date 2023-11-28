#include "restaurante.h"

t_mesas *procurarMesa(t_mesas *mesas, int numero) 
{
    t_mesas *aux = mesas;
    while (aux != NULL) 
    {
        if (aux->numero == numero) 
        {
            return (aux);
        }
        aux = aux->prox;
    }
    return (NULL);
}

t_mesas *criarMesa(t_mesas **mesas, int numero, char *codigoGarcon, t_menu *menu, int tamMenu) 
{
    t_mesas *nova = (t_mesas *) malloc(sizeof (t_mesas));
    nova->numero = numero;
    nova->total = 0;
    strcpy(nova->codigoGarcon, codigoGarcon);
    nova->prox = NULL;
    nova->ant = NULL;

    if (*mesas == NULL) 
    {
        *mesas = nova;
    } 
    else 
    {
        t_mesas *aux = *mesas;
        while (aux->prox != NULL) 
        {
            aux = aux->prox;
        }
        aux->prox = nova;
        nova->ant = aux;
    }
    return *mesas;
}

void removerMesa(t_mesas **mesas, int numMesa)
{
    t_mesas *anterior = NULL;
    t_mesas *atual = *mesas;
    t_mesas *proximo = NULL;
    t_mesas *aux = *mesas;

    atual = procurarMesa(*mesas, numMesa);
    if(atual == NULL) 
    {
        printf("Mesa não encontrada.\n");
        return;
    }
    while (aux != NULL) 
    {
        if (aux->numero == numMesa) 
        {
            anterior = aux->ant;
            proximo = aux->prox;
            if (anterior)
                anterior->prox = proximo;
            if (proximo)
                proximo->ant = anterior;
            break;
        }
        aux = aux->prox;
    }
    t_pedidos *pedido = atual->pedidos;
    while(pedido != NULL)
    {
        t_pedidos *proximoPedido = pedido->prox;
        free(pedido);
        pedido = proximoPedido;
    }
    free(atual);
}