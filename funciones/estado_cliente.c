#ifndef ESTADO_CLIENTE_C
#define ESTADO_CLIENTE_C

#include<stdio.h>
#include<stdlib.h>
#include"../estructuras.h"
#include"../prototipos.h"


void estado_cliente(){
    int id_cliente,dni_encontrado,seleccion=0;
    printf("Ingresar el ID del cliente: ");scanf("%d",&id_cliente);

    FILE *busqueda_dni;
    if((busqueda_dni=fopen("clientes/clientes.dat","rb"))!=NULL){
        clientes busqueda_cliente;
        fread(&busqueda_cliente,sizeof(busqueda_cliente),1,busqueda_dni);
        while(!feof(busqueda_dni)){
            
            if(id_cliente==busqueda_cliente.id){
                dni_encontrado=busqueda_cliente.dni;
            }
            fread(&busqueda_cliente,sizeof(busqueda_cliente),1,busqueda_dni);
        }
        fclose(busqueda_dni);
    }


    FILE *archivo_contrato;
    if((archivo_contrato=fopen("clientes/contratos.dat","r+b"))!=NULL){
        contratos c_modificado;
        fread(&c_modificado,sizeof(c_modificado),1,archivo_contrato);
        while(!feof(archivo_contrato)){
            
            if(dni_encontrado==c_modificado.dni){
                printf("1. Dar de Alta\n");
                printf("2. Dar de Baja\n");
                printf("3. Atras\n");
                scanf("%d",&seleccion);
                if(seleccion==1){
                    if(c_modificado.estado_cliente==1){
                        printf("Error: El cliente ya ha sido dado de alta anteriormente.\n");
                    }else{
                        c_modificado.estado_cliente=1;
                        printf("El cliente ha sido dado de alta exitosamente.\n");
                        fseek(archivo_contrato,sizeof(c_modificado)*(-1),SEEK_CUR);
                        fwrite(&c_modificado,sizeof(c_modificado),1,archivo_contrato);
                        fseek(archivo_contrato,sizeof(c_modificado),SEEK_END);
                        
                    }
                }else if(seleccion==2){
                    if(c_modificado.estado_cliente==0){
                        printf("Error: El cliente ya ha sido dado de baja anteriormente.\n");
                    }else{
                        c_modificado.estado_cliente=0;
                        printf("El cliente ha sido dado de baja exitosamente.\n");
                        fseek(archivo_contrato,sizeof(c_modificado)*(-1),SEEK_CUR);
                        fwrite(&c_modificado,sizeof(c_modificado),1,archivo_contrato);
                        fseek(archivo_contrato,sizeof(c_modificado),SEEK_END);
                    }
                }
            }

            fread(&c_modificado,sizeof(c_modificado),1,archivo_contrato);
        }
        if(seleccion==0){
            printf("No se ha encontrado cliente con id %d\n",id_cliente);
        }
        fclose(archivo_contrato);
        system("pause");
    }
}

#endif //ESTADO_CLIENTE_C