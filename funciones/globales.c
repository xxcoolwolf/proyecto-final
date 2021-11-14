#ifndef GLOBALES
#define GLOBALES

#include<stdio.h>
#include<stdlib.h>
#include"../estructuras.h"
#include"../prototipos.h"

//IMPORTANTE: Luego de utilizar la global, resetearlo a 0.
int id_cliente_global = 0,id_cliente_contrato_global = 0,centinela_global = 0,centinela_modificador_global = 0;
long int dni_cliente_global = 0;

void reseteo_globales() {
    //funcion simple para resetear las globales una vez utilizada
    id_cliente_global = 0;
    id_cliente_contrato_global = 0;
    centinela_global = 0;
    centinela_modificador_global = 0;
    dni_cliente_global = 0;
}
 
#endif //GLOBALES