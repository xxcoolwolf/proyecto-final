#ifndef GENERADOR_TXT_C
#define GENERADOR_TXT_C

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"../estructuras.h"
#include"../prototipos.h"
#include"globales.c"

void generador_txt(int id_persona)
{
    FILE *p;
    char nombre_contrato[40], numero_id[21];
    strcpy(nombre_contrato, "clientes/contratos_txt/contrato_");
    sprintf(numero_id, "%d",id_cliente_contrato_global);
    strcat(nombre_contrato, numero_id);
    strcat(nombre_contrato, ".txt");
    printf("Nombre Archivo: %s\n",nombre_contrato);
    system("pause");


    FILE *archivo_contrato;
    if((archivo_contrato = fopen("clientes/contratos.dat","rb"))!=NULL){
        // printf ("HOOOLIIIIIIIIIIIIIISSSSSSSSSS\n");
        contratos busqueda_contrato;

        fread(&busqueda_contrato,sizeof(busqueda_contrato),1,archivo_contrato);
        while(!feof(archivo_contrato)){
            // printf("2HOOOLIIIIIIIIIIIIIISSSSSSSSSS\n");
            if(id_persona == busqueda_contrato.id){
                if ((p = fopen(nombre_contrato,"wt")) != NULL){
                    int estado_cliente;
                    devolver_estado_cliente(busqueda_contrato.id,&estado_cliente);
                    // printf("3HOOOLIIIIIIIIIIIIIISSSSSSSSSS\n");
                    fprintf(p,"ID = %d\nID Contrato = %d\nFecha Firma = %d/%d/%d\nFecha Fin = %d/%d/%d\nTotal = %.2f\nDescuento = %.2f\nEstado Cliente = %d",id_persona,busqueda_contrato.id_contrato,busqueda_contrato.fecha_firma.day,busqueda_contrato.fecha_firma.mont,busqueda_contrato.fecha_firma.year,busqueda_contrato.fecha_fin.day,busqueda_contrato.fecha_fin.mont,busqueda_contrato.fecha_fin.year,busqueda_contrato.total,busqueda_contrato.descuento,estado_cliente);
                    fclose(p);
                    // printf("4HOOOLIIIIIIIIIIIIIISSSSSSSSSS\n");
                }else
                    printf("No fue posible realizar la generacion del txt.\n");
                    // printf("4.1HOOOLIIIIIIIIIIIIIISSSSSSSSSS\n");
            }


            fread(&busqueda_contrato,sizeof(busqueda_contrato),1,archivo_contrato);
        }
        // printf("5HOOOLIIIIIIIIIIIIIISSSSSSSSSS\n");
        fclose(archivo_contrato);
        system("pause");
    }
}


#endif