#include "restaurante.h"

t_menu *inserirMenu(t_menu *menu, int tamMenu)
{
    if (tamMenu < 15)
    {
        printf("Digite o codigo do prato ou bebida: \n");
        scanf(" %50[^\n]", menu[tamMenu].codigo);
        printf("Digite o nome do prato ou bebida: \n");
        scanf(" %10[^\n]", menu[tamMenu].nome);
        printf("Digite o preco do prato ou bebida: \n");
        scanf("%f", &menu[tamMenu].preco);
    }
    else
    {
        menu = realloc(menu, sizeof(t_menu) * (tamMenu + 1));
        if (menu == NULL)
        {
            printf("Erro ao alocar memoria.\n");
            exit(1);
        }
        printf("Digite o codigo do prato ou bebida: \n");
        scanf(" %50[^\n]", menu[tamMenu].codigo);
        printf("Digite o nome do prato ou bebida: \n");
        scanf(" %10[^\n]", menu[tamMenu].nome);
        printf("Digite o preco do prato ou bebida: \n");
        scanf("%f", &menu[tamMenu].preco);
    }
    return (menu);
}

t_menu *removerMenu(t_menu *menu, char *codigo, int tamMenu)
{
    int pos = -1;
    int i = 0;
    if (tamMenu == 0)
    {
        printf("Não há pratos ou bebidas cadastrados.\n");
        return (0);
    }
    else
    {
        for (i = 0; i < tamMenu; i++)
        {
            if (strcmp(menu[i].codigo, codigo) == 0)
            {
                pos = i;
                break;
            }
        }
        if (pos == -1)
        {
            printf("pratos ou bebidas não encontrado.\n");
            return (0);
        }
        else
        {
            for (i = pos; i < tamMenu - 1; i++)
            {
                strcpy(menu[i].codigo, menu[i + 1].codigo);
                strcpy(menu[i].nome, menu[i + 1].nome);
                menu[i].preco = menu[i + 1].preco;
            }
            menu = realloc(menu, sizeof(t_menu) * (tamMenu - 1));
            if (menu == NULL)
            {
                printf("Erro ao alocar memoria.\n");
                exit(1);
            }
            return (menu);
        }
    }
}

void modificarMenu(t_menu *menu, int tamMenu, char *codigo, int opcao)
{
    int pos = -1;
    int i = 0;
    if (tamMenu == 0)
    {
        printf("Não há pratos ou bebidas cadastrados.\n");
        return;
    }
    else
    {
        for (i = 0; i < tamMenu; i++)
        {
            if (strcmp(menu[i].codigo, codigo) == 0)
            {
                pos = i;
                break;
            }
        }
        if (pos == -1)
        {
            printf("pratos ou bebidas não encontrado.\n");
            return;
        }
        else
        {
            if (opcao == 3)
            {
                printf("Digite o novo codigo do pratos ou bebidas: \n");
                scanf(" %50[^\n]", menu[pos].codigo);
            }
            else if (opcao == 4)
            {
                printf("Digite o novo nome do pratos ou bebidas: \n");
                scanf(" %10[^\n]", menu[pos].nome);
            }
            else if (opcao == 5)
            {
                printf("Digite o novo preco do pratos ou bebidas: \n");
                scanf("%f", &menu[pos].preco);
            }
            else if (opcao == 6)
            {
                printf("Digite o novo codigo do pratos ou bebidas: \n");
                scanf(" %50[^\n]", menu[pos].codigo);
                printf("Digite o novo nome do pratos ou bebidas: \n");
                scanf(" %10[^\n]", menu[pos].nome);
                printf("Digite o novo preco do pratos ou bebidas: \n");
                scanf("%f", &menu[pos].preco);
            }
        }
    }

}

void listarMenu(t_menu *menu, int tamMenu)
{
    if (tamMenu == 0)
    {
        printf("Não há menus cadastrados.\n");
        return;
    }
    else
    {
        for (int i = 0; i < tamMenu; i++)
        {
            printf("Codigo: %s\n", menu[i].codigo);
            printf("Nome: %s\n", menu[i].nome);
            printf("Preco: %.2f\n", menu[i].preco);
        }
    }
}

void salvarMenu(t_menu *menu, int tamMenu)
{
    FILE *arqMenu = fopen("menu.bin", "wb");
    if (arqMenu == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        exit(1);
    }
    for (int i = 0; i < tamMenu; i++)
    {
        fwrite(&menu[i], sizeof(t_menu), 1, arqMenu);
    }
    fclose(arqMenu);
}