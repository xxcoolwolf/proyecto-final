#ifndef LISTAR_CONTRATOS_DE_CLIENTE_C
#define LISTAR_CONTRATOS_DE_CLIENTE_C

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"../estructuras.h"
#include"../prototipos.h"

void listar_contratos_de_cliente(int id_cliente) {
    FILE *ap_contratos;
    if((ap_contratos = fopen("clientes/contratos.dat","rb")) != NULL) {
        contratos e_contratos; //e_ de estructura_
        fread(&e_contratos,sizeof(contratos),1,ap_contratos);
        while(!feof(ap_contratos)) {
            if(id_cliente == e_contratos.id && e_contratos.estado_contrato == 1) {
                printf("%-5d | %d/%d/%-10d | %d/%d/%-10d | $%-5.2f | %-5d\n",e_contratos.id_contrato,e_contratos.fecha_firma.day,e_contratos.fecha_firma.mont,e_contratos.fecha_firma.year,e_contratos.fecha_fin.day,e_contratos.fecha_fin.mont,e_contratos.fecha_fin.year,e_contratos.total-e_contratos.descuento,e_contratos.estado_factura);
            }
            //volvemos a leer para evitar bucle
            fread(&e_contratos,sizeof(contratos),1,ap_contratos);
        }
        //cerramos el archivo
        fclose(ap_contratos);
    }
    else
        printf("Error en la apertura de contratos.dat\n");
    system("pause");
}

#endif //LISTAR_CONTRATOS_DE_CLIENTE_C