#ifndef MAYOR_CONTRATACION_C
#define MAYOR_CONTRATACION_C

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"../estructuras.h"
#include"../prototipos.h"


void mayor_contratacion(){
    system("cls");
    int max=-1,id_max,cont,id_servicio;
    char nombre_servicio[50]="",nombre_max[50]="";
    FILE *arch_servicios,*servicios_contratados;
    if((arch_servicios=fopen("servicios/servicios.dat","rb"))!=NULL){
        servicios seleccion_servicio;

        fread(&seleccion_servicio,sizeof(seleccion_servicio),1,arch_servicios);
        while(!feof(arch_servicios)){

            cont=0;

            if((servicios_contratados=fopen("clientes/servicios_clientes.dat","rb"))){
                servicios_clientes mayor_servicio;
                fread(&mayor_servicio,sizeof(mayor_servicio),1,servicios_contratados);
                while(!feof(servicios_contratados)){
                    // printf("servicios = %s , serv_regist = %s\n",seleccion_servicio.nombre,mayor_servicio.nombre_servicio);
                    if(strcmp(seleccion_servicio.nombre,mayor_servicio.nombre_servicio)==0){
                        cont++;
                        // printf("%s %d\n---------------------------------------------------------\n",seleccion_servicio.nombre,cont);
                        id_servicio=seleccion_servicio.id;
                        strcpy(nombre_servicio,seleccion_servicio.nombre);
                    }



                    fread(&mayor_servicio,sizeof(mayor_servicio),1,servicios_contratados);
                }
                if(cont>max){
                    max=cont;
                    id_max=id_servicio;
                    strcpy(nombre_max,nombre_servicio);

                }
                
                
                fclose(servicios_contratados);
            }else{
                printf("Error servicios_contratados\n");
            }




            fread(&seleccion_servicio,sizeof(seleccion_servicio),1,arch_servicios);
        }



        fclose(arch_servicios);
    }else{
        printf("Error servicios\n");
    }

    printf("SERVICIO MAS CONTRATADO\n");
    printf("Nombre: %s\n",nombre_max);
    printf("ID: %d\n",id_max);
    printf("Cantidad de veces contratado: %d\n",max);
    system("pause");

}

#endif