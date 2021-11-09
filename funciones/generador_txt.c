#ifndef GENERADOR_TXT
#define GENERADOR_TXT

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"../estructuras.h"
#include"../prototipos.h"

void generador_txt(char *nombre, contratos *carga_contrato){
    FILE *archivo_contratos;
    if((archivo_contratos=fopen(nombre,"w"))!=NULL){
        
        // fprintf();

        fclose(archivo_contratos);
    }
}

#endif