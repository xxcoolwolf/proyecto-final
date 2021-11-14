#ifndef ESTADO_CLIENTE_C
#define ESTADO_CLIENTE_C

#include<stdio.h>
#include<stdlib.h>
#include"../estructuras.h"
#include"../prototipos.h"


void estado_clientes(){ 
    
    system("cls");
    int id_cliente,dni_encontrado,seleccion=0,eleccion_contrato;
    printf("Ingresar el ID del cliente: ");scanf("%d",&id_cliente);
    // listar_contratos_de_cliente(id_cliente);//-----------------------------
    // printf("Ingresar id del contrato deseado: ");scanf("%d",eleccion_contrato);//-----------------------------
    


    FILE *archivo_contrato;
    if((archivo_contrato=fopen("clientes/clientes.dat","r+b"))!=NULL){
        clientes c_modificado;
        fread(&c_modificado,sizeof(c_modificado),1,archivo_contrato);
        while(!feof(archivo_contrato)){
            
            if(id_cliente == c_modificado.id){
                printf("1. Dar de Baja Cliente\n");
                printf("2. Dar de Baja Contrato\n");
                printf("0. Atras\n");
                scanf("%d",&seleccion);

                if(seleccion == 1){
                    if( c_modificado.estado_cliente == 0){
                        printf("Error: El cliente ya ha sido dado de baja anteriormente.\n");
                    }else{
                        c_modificado.estado_cliente = 0;
                        //dar de baja todos los contratos
                        FILE *modificar_contrato;
                        if((modificar_contrato=fopen("clientes/contratos.dat","r+b"))!=NULL){
                            int finalizar=0;
                            contratos borrar_contrato;
                            while(finalizar==0){
                                rewind(modificar_contrato);
                                fread(&borrar_contrato,sizeof(borrar_contrato),1,modificar_contrato);
                                while(!feof(modificar_contrato)){
                                    finalizar=1;
                                    if(borrar_contrato.id==id_cliente && borrar_contrato.estado_contrato==1){
                                        borrar_contrato.estado_contrato=0;
                                        finalizar=0;
                                        fseek(modificar_contrato,sizeof(borrar_contrato)*(-1),SEEK_CUR);
                                        fwrite(&borrar_contrato,sizeof(borrar_contrato),1,modificar_contrato);
                                        fseek(modificar_contrato,sizeof(borrar_contrato),SEEK_END);
                                    }

                                    fread(&borrar_contrato,sizeof(borrar_contrato),1,modificar_contrato);
                                }

                            }
                            fclose(modificar_contrato);
                        }


                        //fin dar de baja todos los contratos
                        printf("El cliente ha sido dado de baja exitosamente.\n");
                        fseek(archivo_contrato,sizeof(c_modificado)*(-1),SEEK_CUR);
                        fwrite(&c_modificado,sizeof(c_modificado),1,archivo_contrato);
                        fseek(archivo_contrato,sizeof(c_modificado),SEEK_END);
                    }
                }else if(seleccion == 2){
                    listar_contratos_de_cliente(id_cliente);//-----------------------------
                    printf("Ingresar id del contrato deseado: ");scanf("%d",&eleccion_contrato);//-----------------------------
                    FILE *eliminar_contrato;
                    printf("1HOLLAAAAAAA\n");
                    if((eliminar_contrato=fopen("clientes/contratos.dat","r+b"))!=NULL){
                        contratos eliminar_c;
                        printf("2HOLLAAAAAAA\n");
                        fread(&eliminar_c,sizeof(eliminar_c),1,eliminar_contrato);
                        while(!feof(eliminar_contrato)){
                            printf("3HOLLAAAAAAA\n");
                            if(eliminar_c.estado_contrato==1 && eleccion_contrato==eliminar_c.id_contrato){
                                printf("4HOLLAAAAAAA\n");
                                eliminar_c.estado_contrato=0;
                                fseek(eliminar_contrato,sizeof(eliminar_c)*(-1),SEEK_CUR);
                                fwrite(&eliminar_c,sizeof(eliminar_c),1,eliminar_contrato);
                                fseek(eliminar_contrato,sizeof(eliminar_c),SEEK_END);
                            }
                            fread(&eliminar_c,sizeof(eliminar_c),1,eliminar_contrato);
                        }
                        fclose(eliminar_contrato);
                        printf("5HOLLAAAAAAA\n");
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