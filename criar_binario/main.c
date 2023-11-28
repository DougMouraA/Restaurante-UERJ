#include "restaurante.h"

#define MAX_MENU 15
#define MAX_GARCON 5

int main() 
{
    t_menu menu[15];
    t_garcon garcon[5];
    FILE *arquivoMenu = fopen("menu.bin", "wb");
    FILE *arquivoGarcon = fopen("garcon.bin", "wb");

    if (arquivoMenu == NULL) {
        printf("Não foi possível abrir o arquivo.\n");
        return 1;
    }

    if (arquivoGarcon == NULL) {
        printf("Não foi possível abrir o arquivo.\n");
        return 1;
    }

    printf("Digite o Menu:\n");
    for (int i = 0; i < 15; i++) {
        printf("Digite o código do prato ou bebida: ");
        scanf(" %10[^\n]", menu[i].codigo);
        printf("Digite o nome do prato ou bebida: ");
        scanf(" %50[^\n]", menu[i].nome);
        printf("Digite o preço do prato ou bebida: ");
        scanf("%f", &menu[i].preco);
        fwrite(&menu[i], sizeof(t_menu), 1, arquivoMenu);
    }

    printf("Digite os Garçons:\n");
    for (int i = 0; i < 5; i++) {
        printf("Digite o nome do garçom: ");
        scanf(" %50[^\n]", garcon[i].nome);
        printf("Digite o código do garçom: ");
        scanf(" %10[^\n]", garcon[i].codigo);
        fwrite(&garcon[i], sizeof(t_garcon), 1, arquivoGarcon);
    }

    fclose(arquivoMenu);
    fclose(arquivoGarcon);
}