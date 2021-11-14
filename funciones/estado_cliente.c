#ifndef ESTADO_CLIENTE_C
#define ESTADO_CLIENTE_C

#include<stdio.h>
#include<stdlib.h>
#include"../estructuras.h"
#include"../prototipos.h"


void estado_clientes(){ 
    /*
    system("cls");
    int id_cliente,dni_encontrado,seleccion=0;
    printf("Ingresar el ID del cliente: ");scanf("%d",&id_cliente);

    FILE *busqueda_dni;
    if((busqueda_dni=fopen("clientes/clientes.dat","rb"))!=NULL){
        clientes busqueda_cliente;
        fread(&busqueda_cliente,sizeof(busqueda_cliente),1,busqueda_dni);
        while(!feof(busqueda_dni)){
            
            if(id_cliente == busqueda_cliente.id){
                dni_encontrado = busqueda_cliente.dni;  
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
            
            if(dni_encontrado == c_modificado.dni){
                printf("1. Dar de Alta\n");
                printf("2. Dar de Baja\n");
                printf("0. Atras\n");
                scanf("%d",&seleccion);
                if(seleccion == 1){
                    if(c_modificado.estado_cliente==1){
                        printf("Error: El cliente ya ha sido dado de alta anteriormente.\n");
                    }else{
                        c_modificado.estado_cliente=1;
                        printf("El cliente ha sido dado de alta exitosamente.\n");
                        fseek(archivo_contrato,sizeof(c_modificado)*(-1),SEEK_CUR);
                        fwrite(&c_modificado,sizeof(c_modificado),1,archivo_contrato);
                        fseek(archivo_contrato,sizeof(c_modificado),SEEK_END);
                        
                    }
                }else if(seleccion == 2){
                    if(c_modificado.estado_cliente == 0){
                        printf("Error: El cliente ya ha sido dado de baja anteriormente.\n");
                    }else{
                        c_modificado.estado_cliente = 0;



                            FILE *desactivar_servicios;
                                int finalizar=0;
                            if((desactivar_servicios=fopen("clientes/servicios_clientes.dat","r+b"))!=NULL){
                                servicios_clientes borrar_servicio;
                                while(finalizar == 0){
                                    rewind(desactivar_servicios);
                                    fread(&borrar_servicio,sizeof(borrar_servicio),1,desactivar_servicios);
                                    while(!feof(desactivar_servicios)){
                                        finalizar=1;
                                        printf("Finaliza = 1\n");
                                        
                                        if(borrar_servicio.dni == dni_encontrado && borrar_servicio.estado_servicio==1){
                                            printf("Nombre = %s\n",borrar_servicio.nombre_servicio);
                                            borrar_servicio.estado_servicio=0;
                                            //como el servicio está desactivado, ha que descontar el precio al total
                                            FILE *b_servicio;
                                            if((b_servicio=fopen("servicios/servicios.dat","rb"))!=NULL){

                                                servicios busqueda_servicio;
                                                fread(&busqueda_servicio,sizeof(busqueda_servicio),1,b_servicio);
                                                while(!feof(b_servicio)){

                                                    if(busqueda_servicio.id == borrar_servicio.id_servicio){
                                                        c_modificado.total=c_modificado.total-busqueda_servicio.precio;
                                                    }

                                                    fread(&busqueda_servicio,sizeof(busqueda_servicio),1,b_servicio);
                                                }

                                                fclose(b_servicio);
                                            }


                                            finalizar=0;
                                            printf("Finaliza = 0\n");
                                            fseek(desactivar_servicios,sizeof(borrar_servicio)*(-1),SEEK_CUR);
                                            fwrite(&borrar_servicio,sizeof(borrar_servicio),1,desactivar_servicios);
                                            fseek(desactivar_servicios,sizeof(borrar_servicio),SEEK_END);
                                        }
                                        
                                        printf("HOLLLAAAAAAAA\n");
                                        fread(&borrar_servicio,sizeof(borrar_servicio),1,desactivar_servicios);	
                                    }
                                    printf("Fuera while2\n");
                                    system("pause");
                                }
                                
                                
                                fclose(desactivar_servicios);
                            }




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
    */
}

#endif //ESTADO_CLIENTE_C