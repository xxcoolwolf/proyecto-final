#ifndef MODIFICAR_SERVICIOS_CLIENTES_C
#define MODIFICAR_SERVICIOS_CLIENTES_C

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"../estructuras.h"
#include"../prototipos.h"

 void modificar_servicios_clientes(int id) {

    FILE *apuntador_contratos,*apuntador_servicios;
    int opcion,id_desactivar,centinela_descontar = 0,total_descontar = 0,dni,total_pagar = 0;
    do {
        printf("1. Agregar servicio/s\n");
        printf("2. Desactivar servicio\n");
        printf("0. Finalizar\n");
        scanf("%d",&opcion);
        //teabajamos segun la opcion seleccionada
        if(opcion == 1) {
            printf("Ingrese el DNI del cliente\n");
            scanf("%d",&dni);
            seleccionar_servicio(&total_pagar,dni);
             /////////////////////////////////////////////////////
                        //Aca traemos el monto total a pagar
                        FILE *ap_contratos;
                        if((ap_contratos = fopen("clientes/contratos.dat","r+b")) != NULL) {
                            contratos e_contratos;
                            fread(&e_contratos,sizeof(contratos),1,ap_contratos);
                            while(!feof(ap_contratos)) {
                                //buscamos al cliente
                                if(e_contratos.dni == dni) {
                                    e_contratos.total = e_contratos.total + total_pagar;    
                                    //obtenemos la ubicacion en la que estamos
                                    int posicion_contratos = ftell(ap_contratos)-sizeof(contratos);
                                    //nos posicionamos para realizar la modificacion
                                    fseek(ap_contratos,posicion_contratos,SEEK_SET);
                                    //guardamos los datos
                                    fwrite(&e_contratos,sizeof(contratos),1,ap_contratos);
                                    break;
                                }
                                //volvemos a avanzar para evitar el bucle
                                fread(&e_contratos,sizeof(contratos),1,ap_contratos);
                            }
                            //cerramos el archivo
                            fclose(ap_contratos);
                        }
                        else
                            printf("Error de apertura contratos.dat\n");
                        /////////////////////////////////////////////////////

        }
        if(opcion == 2) {
            if((apuntador_contratos = fopen("clientes/contratos.dat","rb")) != NULL) {
                contratos listar_contratos;
                //esta funcion es solo para buscar el dni, para luego poder buscar los servicios con dicho dni, y cambiarle el estatus;
                fread(&listar_contratos,sizeof(contratos),1,apuntador_contratos);
                while(!feof(apuntador_contratos)) {
                    //aca encontramos el dni de la persona
                    if(listar_contratos.id == id) {
//--------------------------------- LISTAR SERVICIO --------------------------------- //
                    if((apuntador_servicios = fopen("clientes/servicios_clientes.dat","rb")) != NULL) {
                        //preparamos la estructura
                        servicios_clientes listar_servicios;
                        fread(&listar_servicios,sizeof(servicios_clientes),1,apuntador_servicios);
                        //listamos los servicios de la persona
                        while(!feof(apuntador_servicios)) {
                            if(listar_servicios.dni == listar_contratos.dni) {
                                //imprimimos los servicios que dispone
                                printf("%-10d | %-20s | %-10d | %d/%d/%-5d | %.2f\n",listar_servicios.id_servicio,listar_servicios.nombre_servicio,listar_servicios.estado_servicio,listar_servicios.fecha_alta.day,listar_servicios.fecha_alta.mont,listar_servicios.fecha_alta.year,listar_servicios.precio);
                            }
                            //volvemos a buscar para evitar bucle
                            fread(&listar_servicios,sizeof(servicios_clientes),1,apuntador_servicios);
                        }
                        //cerramos el archivo servicios_clientes.dat
                        fclose(apuntador_servicios);
                    }
                    else
                        printf("Error apertura servicios_clientes.dat");
//--------------------------------- LISTAR SERVICIO --------------------------------- //


//--------------------------------- MODIFICAR SERVICIO --------------------------------- //
                    printf("Ingrese el id del servicio a desactivar \n");
                    scanf("%d",&id_desactivar);
                    int posicion;
                    if((apuntador_servicios = fopen("clientes/servicios_clientes.dat","r+b")) != NULL) {
                        //preparamos la estructura
                        servicios_clientes modificar_servicios;
                        //cargamos el archivo en la estructura
                        rewind(apuntador_servicios);
                        fread(&modificar_servicios,sizeof(servicios_clientes),1,apuntador_servicios);
                        while(!feof(apuntador_servicios)) {
                            if(modificar_servicios.dni == listar_contratos.dni && modificar_servicios.id_servicio == id_desactivar) {
                                //cambiamos el estatus del servicio a 0
                                modificar_servicios.estado_servicio = 0;
                                total_descontar = modificar_servicios.precio;
                                printf("TOTAL DESCONTAR %d\n",total_descontar);
                                system("pause");
                                centinela_descontar = 1;
                                //obtenemos la posicion en la que estamos
                                posicion = ftell(apuntador_servicios) - sizeof(servicios_clientes);
                                //ahora nos movemos hacia esa posicion desde el inicio
                                fseek(apuntador_servicios,posicion,SEEK_SET);
                                //y escribimos los cambios
                                fwrite(&modificar_servicios,sizeof(servicios_clientes),1,apuntador_servicios);
                                printf("Se desactivo correctamente el producto \n");
                                system("pause");
                                //lo mandamos al final
                                fseek(apuntador_servicios,sizeof(servicios_clientes),SEEK_SET);
                                break;
                            }
                            //leemos para evitar bucle
                            // printf("1BUENAAAAAAAAAAAAAAAAAAAAAAAAAAS\n");
                            fread(&modificar_servicios,sizeof(servicios_clientes),1,apuntador_servicios);
                        }
                        //cerramos el archivo servicios_clientes.dat
                        // printf("2BUENAAAAAAAAAAAAAAAAAAAAAAAAAAS\n");
                        fclose(apuntador_servicios);
                    }
                    else
                        printf("Error apertura servicios_clientes.dat\n");

//--------------------------------- MODIFICAR SERVICIO --------------------------------- //

                    }
                    //volvemos a buscar para evitar bucle
                    fread(&listar_contratos,sizeof(contratos),1,apuntador_contratos);
                }

                //cerramos el archivo contratos.dat
                fclose(apuntador_contratos);
            }
            else
                printf("Error apaertura contratos.dar\n");
            //fin apartura archivo
        }//fin if == 2

        //--------------------------------- REALIZAR DESCUENTO --------------------------------- //
        if(centinela_descontar == 1) {
            centinela_descontar = 0;
            FILE *apuntador_modificador;
            if((apuntador_modificador = fopen("clientes/contratos.dat","r+b")) != NULL) {
                    contratos listar_contratos;
                    int posicion_contrato;
                    //esta funcion es solo para buscar el dni, para luego poder buscar los servicios con dicho dni, y cambiarle el estatus;
                    fread(&listar_contratos,sizeof(contratos),1,apuntador_modificador);
                    while(!feof(apuntador_modificador)) {
                        //aca encontramos el dni de la persona
                        if(listar_contratos.id == id) {
                            int verificador_total = listar_contratos.total - total_descontar;
                                if(verificador_total < 0) {
                                    listar_contratos.total = 0;
                                }
                                else{
                                    listar_contratos.total = listar_contratos.total - total_descontar;
                                }
                                
                                //obtenemos la posicion en la que estamos
                                posicion_contrato = ftell(apuntador_modificador) - sizeof(contratos);
                                //ahora nos movemos hacia esa posicion desde el inicio
                                fseek(apuntador_modificador,posicion_contrato,SEEK_SET);
                                //y escribimos los cambios
                                fwrite(&listar_contratos,sizeof(contratos),1,apuntador_modificador);
                                printf("Se desconto correctamente del total \n");
                                system("pause");
                                //lo mandamos al final
                                fseek(apuntador_modificador,sizeof(contratos),SEEK_END);
                        }    
                        //volvemos a leer para evitar bucle infinito    
                        fread(&listar_contratos,sizeof(contratos),1,apuntador_modificador);
                    }
                //cerramos el archivo
                fclose(apuntador_modificador);
            }
            else
                printf("Error apertura contratos.dat\n");
        }
        printf("Estoy fuera de todo");

//-FIN--------------------------- REALIZAR DESCUENTO ------------------------------FIN- //


    } while(opcion!=0);

    system("pause2");
}

#endif //MODIFICAR_SERVICIOS_CLIENTES_C