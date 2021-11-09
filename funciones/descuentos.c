#ifndef DESCUENTOS_C
#define DESCUENTOS_C

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"../estructuras.h"
#include"../prototipos.h"

void descuentos(int dni){
    FILE *archivo_contratos;
    int posicion;
    if((archivo_contratos = fopen("clientes/contratos.dat","a+b")) != NULL) {
        //definimos a la estructura de contratos
        contratos carga_contratos;
        // printf("Descuentos dni = %d-----------------------------------------------------\n",dni);
        rewind(archivo_contratos);
        fread(&carga_contratos,sizeof(carga_contratos),1,archivo_contratos);
        while(!feof(archivo_contratos)){
            printf("Descuentos carga_contratos.dni = %d-----------------------------------------------------\n",carga_contratos.dni);
            if(dni==carga_contratos.dni){
                // printf("1HHHHHHHHHHHHHHHHHHHHHH\n");
                
                if(carga_contratos.total >= 3000 && carga_contratos.total <= 4000) {
                    //descuento del 20%
                    carga_contratos.descuento = carga_contratos.total * 0.2;
                } 
                else 
                {
                    if(carga_contratos.total >= 4001 && carga_contratos.total <= 6000) {
                        //decuento del 25%
                        carga_contratos.descuento = carga_contratos.total * 0.25;
                    }
                    else
                    {
                        if(carga_contratos.total > 6000) {
                            //descuento del 30%
                            carga_contratos.descuento = carga_contratos.total * 0.3;
                        }else{
                            carga_contratos.descuento = 0;
                        }
                    }
                }
                printf("carga_contratos.descuento = %f\n",carga_contratos.descuento);
                posicion=ftell(archivo_contratos)-sizeof(carga_contratos);
                fseek(archivo_contratos,sizeof(carga_contratos),SEEK_SET);
                fwrite(&carga_contratos,sizeof(carga_contratos),1,archivo_contratos);
                fseek(archivo_contratos,sizeof(carga_contratos),SEEK_END);

            }
// printf("2HHHHHHHHHHHHHHHHHHHHHH\n");
system("pause");
            fread(&carga_contratos,sizeof(carga_contratos),1,archivo_contratos);
        }
        // printf("3HHHHHHHHHHHHHHHHHHHHHH\n");
        fclose(archivo_contratos);
    }
}


#endif