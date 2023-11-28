#include "restaurante.h"

t_garcon *inserirGarcon(t_garcon *garcon, int tamGarcon)
{
    if (tamGarcon < 5)
    {
        printf("Digite o nome do garcon: \n");
        scanf(" %50[^\n]", garcon[tamGarcon].nome);
        printf("Digite o codigo do garcon: \n");
        scanf(" %10[^\n]", garcon[tamGarcon].codigo);
    }
    else
    {
        garcon = realloc(garcon, sizeof(t_garcon) * (tamGarcon + 1));
        if (garcon == NULL)
        {
            printf("Erro ao alocar memoria.\n");
            exit(1);
        }
        printf("Digite o nome do garcon: \n");
        scanf(" %50[^\n]", garcon[tamGarcon].nome);
        printf("Digite o codigo do garcon: \n");
        scanf(" %10[^\n]", garcon[tamGarcon].codigo);
    }
    return (garcon);
}

t_garcon *removerGarcon(t_garcon *garcon, char *codigoGarcon, int tamGarcon)
{
    int pos = -1;
    int i = 0;
    if (tamGarcon == 0)
    {
        printf("Não há garcons cadastrados.\n");
        return (0);
    }
    else
    {
        for (i = 0; i < tamGarcon; i++)
        {
            if (strcmp(garcon[i].codigo, codigoGarcon) == 0)
            {
                pos = i;
                break;
            }
        }
        if (pos == -1)
        {
            printf("garcon não encontrado.\n");
            return (0);
        }
        else
        {
            for (i = pos; i < tamGarcon - 1; i++)
            {
                strcpy(garcon[i].nome, garcon[i + 1].nome);
                strcpy(garcon[i].codigo, garcon[i + 1].codigo);
            }
            garcon = realloc(garcon, sizeof(t_garcon) * (tamGarcon - 1));
            if (garcon == NULL)
            {
                printf("Erro ao alocar memoria.\n");
                exit(1);
            }
            return (garcon);
        }
    }
}

void modificarGarcon(t_garcon *garcon, int tamGarcon, char *codigoGarcon, int opcao)
{
    int pos = -1;
    int i = 0;
    if (tamGarcon == 0)
    {
        printf("Não há garcons cadastrados.\n");
        return;
    }
    else
    {
        for (i = 0; i < tamGarcon; i++)
        {
            if (strcmp(garcon[i].codigo, codigoGarcon) == 0)
            {
                pos = i;
                break;
            }
        }
        if (pos == -1)
        {
            printf("garcon não encontrado.\n");
            return;
        }
        else
        {
            if (opcao == 3)
            {
                printf("Digite o novo nome do garcon: \n");
                scanf(" %50[^\n]", garcon[pos].nome);
            }
            else if (opcao == 4)
            {
                printf("Digite o novo codigo do garcon: \n");
                scanf(" %10[^\n]", garcon[pos].codigo);
            }
            else if (opcao == 5)
            {
                printf("Digite o novo nome do garcon: \n");
                scanf(" %50[^\n]", garcon[pos].nome);
                printf("Digite o novo codigo do garcon: \n");
                scanf(" %10[^\n]", garcon[pos].codigo);
            }
        }
    }

}

void listarGarcon(t_garcon *garcon, int tamGarcon)
{
    if (tamGarcon == 0)
    {
        printf("Não há garcons cadastrados.\n");
        return;
    }
    else
    {
        for (int i = 0; i < tamGarcon; i++)
        {
            printf("Nome: %s\n", garcon[i].nome);
            printf("Codigo: %s\n", garcon[i].codigo);
        }
    }
}

void salvarGarcon(t_garcon *garcon, int tamGarcon)
{
    FILE *arqGarcon = fopen("garcon.bin", "wb");
    if (arqGarcon == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        exit(1);
    }
    for (int i = 0; i < tamGarcon; i++)
    {
        fwrite(&garcon[i], sizeof(t_garcon), 1, arqGarcon);
    }
    fclose(arqGarcon);
}