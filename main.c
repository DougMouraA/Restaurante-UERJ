#include "restaurante.h"


int main()
{
    t_menu *menu = malloc(sizeof(t_menu) * 15);
    t_garcon *garcons = malloc(sizeof(t_garcon) * 5);
    FILE *arqMenu = fopen("menu.bin", "rb");
    FILE *arqGarcons = fopen("garcon.bin", "rb");
    fread(menu, sizeof(t_menu), 15, arqMenu);
    fread(garcons, sizeof(t_garcon), 5, arqGarcons);
    fclose(arqMenu);
    fclose(arqGarcons);

    int tamMenu = 15;
    int tamGarcons = 5;
    int numeroMesa = 0;
    int opcao = 0;
    int quantidade = 0;
    t_mesas *mesas = NULL;
    // t_pedidos *pedidos = NULL;
    char codigoGarcon[10];
    char codigoProduto[10];
    char codigoMenu[10];

    while(1)
    {
        printf("1. Reservar mesa: \n");
        printf("2. Fazer pedido: \n");
        printf("3. Fechar conta: \n");
        printf("4. Modificar dados dos garçons: \n");
        printf("5. Modificar dados dos Menus: \n");
        printf("6. Sair: \n");
        scanf("%d", &opcao);
        switch(opcao)
        {
            case 1:
                printf("Digite o numero da mesa: \n");
                scanf("%d", &numeroMesa);
                if (procurarMesa(mesas, numeroMesa) != NULL)
                {
                    printf("Mesa já reservada.\n");
                    break;
                }
                printf("Digite o codigo do garcon: \n");
                scanf(" %10[^\n]", codigoGarcon);
                criarMesa(&mesas, numeroMesa, codigoGarcon, menu, tamMenu);
                break;
            case 2:
                printf("Digite o numero da mesa: \n");
                scanf("%d", &numeroMesa);
                if (procurarMesa(mesas, numeroMesa) == NULL)
                {
                    printf("Mesa não encontrada.\n");
                    break;
                }
                printf("Digite o codigo do prato ou da bebida: \n");
                scanf(" %10[^\n]", codigoProduto);
                printf("Digite a quantidade: \n");
                scanf("%d", &quantidade);
                fazerPedido(mesas, numeroMesa, menu, tamMenu, codigoProduto, quantidade);
                break;
            case 3:
                printf("Digite o numero da mesa: \n");
                scanf("%d", &numeroMesa);
                fecharConta(&mesas, numeroMesa, garcons, tamGarcons, menu, tamMenu);
                break;
            case 4:
                int opcao2 = 0;
                printf("1. Adicionar um novo garcon: \n");
                printf("2. Remover um garcon: \n");
                printf("3. Alterar somente o nome do garcon: \n");
                printf("4. Alterar somente o codigo do garcon: \n");
                printf("5. Alterar todas as inforamcoes do garcon: \n");
                printf("6. Listar os garcons: \n");
                printf("7. Voltar ao menu principal: \n");
                scanf("%d", &opcao2);
                switch (opcao2)
                {
                    case 1:
                        garcons = inserirGarcon(garcons, tamGarcons);
                        salvarGarcon(garcons, tamGarcons);
                        tamGarcons++;
                        break;
                    case 2:
                        printf("Digite o codigo do garcon: \n");
                        scanf(" %10[^\n]", codigoGarcon);
                        garcons = removerGarcon(garcons, codigoGarcon, tamGarcons);
                        salvarGarcon(garcons, tamGarcons);
                        tamGarcons--;
                        break;
                    case 3:
                        printf("Digite o codigo do garcon: \n");
                        scanf(" %10[^\n]", codigoGarcon);
                        modificarGarcon(garcons, tamGarcons, codigoGarcon, 3);
                        salvarGarcon(garcons, tamGarcons);
                        break;
                    case 4:
                        printf("Digite o codigo do garcon: \n");
                        scanf(" %10[^\n]", codigoGarcon);
                        modificarGarcon(garcons, tamGarcons, codigoGarcon, 4);
                        salvarGarcon(garcons, tamGarcons);                      
                        break;
                    case 5:
                        printf("Digite o codigo do garcon: \n");
                        scanf(" %10[^\n]", codigoGarcon);
                        modificarGarcon(garcons, tamGarcons, codigoGarcon, 5);
                        salvarGarcon(garcons, tamGarcons);                   
                        break;
                    case 6:
                        listarGarcon(garcons, tamGarcons);
                        break;
                    case 7:
                        break;
                    default:
                        printf("Opcao invalida.\n");
                        break;
                }
                break;
            case 5:
                int opcao3 = 0;
                printf("1. Adicionar um novo produto: \n");
                printf("2. Remover um produto: \n");
                printf("3. Alterar somente o nome do produto: \n");
                printf("4. Alterar somente o codigo do produto: \n");
                printf("5. Alterar somente o preco do produto: \n");
                printf("6. Alterar todas as inforamcoes do produto: \n");
                printf("7. Listar os produtos: \n");
                printf("8. Voltar ao menu principal: \n");
                scanf("%d", &opcao3);
                switch (opcao3)
                {
                    case 1:
                        menu = inserirMenu(menu, tamMenu);
                        salvarMenu(menu, tamMenu);
                        tamMenu++;
                        break;
                    case 2:
                        printf("Digite o codigo do prato ou bebida: \n");
                        scanf(" %10[^\n]", codigoMenu);
                        menu = removerMenu(menu, codigoMenu, tamMenu);
                        salvarMenu(menu, tamMenu);                
                        break;
                    case 3:
                        printf("Digite o codigo do prato ou bebida: \n");
                        scanf(" %10[^\n]", codigoProduto);
                        modificarMenu(menu, tamMenu, codigoProduto, 3);
                        salvarMenu(menu, tamMenu);
                        tamMenu--;
                        break;
                    case 4:
                        printf("Digite o codigo do produto: \n");
                        scanf(" %10[^\n]", codigoProduto);
                        modificarMenu(menu, tamMenu, codigoProduto, 4);
                        salvarMenu(menu, tamMenu);                    
                        break;
                    case 5:
                        printf("Digite o codigo do produto: \n");
                        scanf(" %10[^\n]", codigoProduto);
                        modificarMenu(menu, tamMenu, codigoProduto, 5);
                        salvarMenu(menu, tamMenu);                    
                        break;
                    case 6:
                        printf("Digite o codigo do produto: \n");
                        scanf(" %10[^\n]", codigoProduto);
                        modificarMenu(menu, tamMenu, codigoProduto, 6);
                        salvarMenu(menu, tamMenu);                       
                        break;
                    case 7:
                        listarMenu(menu, tamMenu);
                        break;
                    case 8:
                        break;
                    default:
                        printf("Opcao invalida.\n");
                        break;
                }
                break;
            case 6:
                return (0);
            default:
                printf("Opcao invalida.\n");
                break;
        }
    }
    return (0);
}