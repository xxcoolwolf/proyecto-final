#ifndef PUESTO_C
#define PUESTO_C

#include<stdio.h>
#include<stdlib.h>
#include"../estructuras.h"
#include"../prototipos.h"

void puesto(int *puesto){
    do{
        printf("1 - Administrador\n");
        printf("2 - Operario\n");
        scanf("%d",puesto);
    }while(*puesto<1 || *puesto>2);
}


#endif //PUESTO_C