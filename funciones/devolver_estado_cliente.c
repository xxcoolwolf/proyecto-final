#ifndef DEVOLVER_ESTADO_CLIENTE_C
#define DEVOLVER_ESTADO_CLIENTE_C

#include<stdio.h>
#include<stdlib.h>
#include"../estructuras.h"
#include"../prototipos.h"

void devolver_estado_cliente(int id_cliente,int *estado_cliente) {
    FILE *ap_cliente;
    if((ap_cliente=fopen("clientes/clientes.dat","rb"))!=NULL){
        clientes e_cliente;
        fread(&e_cliente,sizeof(e_cliente),1,ap_cliente);
        while(!feof(ap_cliente)){
            
            if(id_cliente == e_cliente.id){
                *estado_cliente = e_cliente.estado_cliente;
                fseek(ap_cliente,sizeof(e_cliente),SEEK_END);
            }
            fread(&e_cliente,sizeof(clientes),1,ap_cliente);
        }
        fclose(ap_cliente);
    }
}

#endif //DEVOLVER_ESTADO_CLIENTE_C