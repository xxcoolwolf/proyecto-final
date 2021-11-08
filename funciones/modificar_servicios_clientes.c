#ifndef MODIFICAR_SERVICIOS_CLIENTES_C
#define MODIFICAR_SERVICIOS_CLIENTES_C

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"../estructuras.h"
#include"../prototipos.h"
/*
by hugo
*/
 void modificar_servicios_clientes(int id) {

    FILE *busqueda_dni,*d_servicio;
    int opcion,dni;
    do{
        printf("1. Aniadir servicio\n");
        printf("2. Desactivar servicio\n");
        printf("3. Finalizar\n");
        scanf("%d",&opcion);
        switch(opcion){
            case 1:
                printf("asfdkiufsdahksdfjksdfjklasdf\n");
            break;
            case 2:
                if((busqueda_dni=fopen("clientes/clientes.dat","rb"))!=NULL){
                    clientes busqueda_cliente;
                    rewind(busqueda_dni);
                    fread(&busqueda_cliente,sizeof(busqueda_cliente),1,busqueda_dni);
                    while(!feof(busqueda_dni)){

                        if(id==busqueda_cliente.id){
                            dni=busqueda_cliente.dni;
                        }

                        fread(&busqueda_cliente,sizeof(busqueda_cliente),1,busqueda_dni);
                    }
                    fclose(busqueda_dni);
                }else
                    printf("Error clientes/clientes.dat\n");

                if((d_servicio=fopen("clientes/servicios_clientes.dat","a+b"))!=NULL){
                    servicios_clientes des_servicio;
                    //mostrar servicios
                    rewind(d_servicio);
                    fread(&des_servicio,sizeof(des_servicio),1,d_servicio);
                    while(!feof(d_servicio)){
                        if(dni==des_servicio.dni){
                            printf("id = %d / %s / estado = %d\n",des_servicio.id_servicio,des_servicio.nombre_servicio,des_servicio.estado_servicio);
                        }
                        fread(&des_servicio,sizeof(des_servicio),1,d_servicio);
                    }
                    int eleccion,pos;
                    printf("Seleccionar id: ");scanf("%d",&eleccion);

                    //desactivar
                    rewind(d_servicio);
                    fread(&des_servicio,sizeof(des_servicio),1,d_servicio);
                    while(!feof(d_servicio)){

                        if(eleccion==des_servicio.id_servicio){
                            des_servicio.estado_servicio=0;
                            //descontar al total

                            pos = ftell(d_servicio)-sizeof(des_servicio);
                            fseek(d_servicio,pos,SEEK_SET);
                            fwrite(&des_servicio,sizeof(des_servicio),1,d_servicio);
                            fseek(d_servicio,sizeof(des_servicio),SEEK_END);
                        }

                        fread(&des_servicio,sizeof(des_servicio),1,d_servicio);
                    }



                    fclose(d_servicio);
                }else
                    printf("Error servicios/servicios_clientes.dat\n");

            break;
        }

    }while(opcion!=0);

    
}

#endif