#ifndef RESTAURANTE_H
#define RESTAURANTE_H

#include <stdio.h>
#include <stdlib.h>

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
}           t_garcon;

#endif