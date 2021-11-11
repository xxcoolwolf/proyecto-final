#ifndef GENERADOR_TXT_C
#define GENERADOR_TXT_C

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"../estructuras.h"
#include"../prototipos.h"

// void carga_acta()
// {
//     FILE *p;
//     char nomb_acta[40], num_acta[21];
//     strcpy(nomb_acta, "acta");
//     sprintf(num_acta, "%ld", acta.numActa);
//     strcat(nomb_acta, num_acta);
//     strcat(nomb_acta, "_");
//     strcat(nomb_acta, acta.patente);
//     strcat(nomb_acta, ".txt");
//     if ((p = fopen(nomb_acta, "wt")) != NULL)
//     {
//         fprintf(p, "Nro acta: %ld\nFECHA: %d/%d/%d - HORA: %d:%d\n\nVEHICULO:\n\t- Propietario: %s\n\t- Patente: %s\n\t- Marca: %s\n\t- Modelo: %s\n\t- Tipo de vehiculo: %s\n\nTIPO INF: %s\n\nOBSERVACIONES / DESCRIPCION / MEDIDAS PREVENTIVAS / TESTIGOS:\n%s\n\nAGENTE:\n\t- Legajo: %ld\n\t- Nombre inspector: %s", acta.numActa, acta.fecha_Acta.day, acta.fecha_Acta.mon, acta.fecha_Acta.year, acta.fecha_Acta.hour, acta.fecha_Acta.min, acta.propietario, acta.patente, acta.marca, acta.modelo, acta.tipo_vehiculo, acta.tipo_infraccion, acta.observacion, acta.legajoinsp, acta.nombre_agente);
//         fclose(p);
//     }
//     else
//         printf("No fue posible realizar el acta.\n");
// }

void generador_txt(int id_persona)
{
    FILE *p;
    
    char nombre_contrato[40], numero_id[21];
    strcpy(nombre_contrato, "clientes/contratos_txt/contrato_");
    sprintf(numero_id, "%d",id_persona);
    strcat(nombre_contrato, numero_id);
    strcat(nombre_contrato, ".txt");
    printf("TXT: %s------------------------------------\n",nombre_contrato);
    system("pause");


    FILE *archivo_contrato;
    if((archivo_contrato=fopen("clientes/contratos.dat","rb"))!=NULL){
        // printf ("HOOOLIIIIIIIIIIIIIISSSSSSSSSS\n");
        contratos busqueda_contrato;

        fread(&busqueda_contrato,sizeof(busqueda_contrato),1,archivo_contrato);
        while(!feof(archivo_contrato)){
            // printf("2HOOOLIIIIIIIIIIIIIISSSSSSSSSS\n");
            if(id_persona==busqueda_contrato.id){
                if ((p = fopen(nombre_contrato,"wt")) != NULL){
                    // printf("3HOOOLIIIIIIIIIIIIIISSSSSSSSSS\n");
                    fprintf(p,"ID = %d\nID Contrato = %d\nFecha Firma = %d/%d/%d\nFecha Fin = %d/%d/%d\nTotal = %.2f\nDescuento = %.2f\nEstado Cliente = %d",id_persona,busqueda_contrato.id_contrato,busqueda_contrato.fecha_firma.day,busqueda_contrato.fecha_firma.mont,busqueda_contrato.fecha_firma.year,busqueda_contrato.fecha_fin.day,busqueda_contrato.fecha_fin.mont,busqueda_contrato.fecha_fin.year,busqueda_contrato.total,busqueda_contrato.descuento,busqueda_contrato.estado_cliente);
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