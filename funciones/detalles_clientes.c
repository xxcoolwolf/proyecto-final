#ifndef DETALLES_CLIENTES_C
#define DETALLES_CLIENTES_C

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"../estructuras.h"
#include"../prototipos.h"

/*
by Sciangula Hugo v1 7/11/21 
detalles: con las nuevas estructuas se va a proceder a solo hacer la lectura de los archivos binarios, y mostrar todos los detalles del cliente
*/

void detalles_cliente(int id,int volver) {
    int id_contrato;
    FILE *archivo;
    if((archivo = fopen("clientes/clientes.dat","rb")) != NULL) {
        //limpiamos la pantalla
        system("cls");
        printf("DETALLES DEL CLIENTE\n");
        clientes datos_clientes;
        //veo si no esta vacio el archivo
        fread(&datos_clientes,sizeof(clientes),1,archivo);
        while(!feof(archivo)) {//Inicio while1
            //lo buscamos por id
            if(id == datos_clientes.id) {
                    printf("ID Cliente: %d\n",datos_clientes.id);
                    printf("Nombre: %s\n",datos_clientes.nombre);
                    printf("DNI: %d\n",datos_clientes.dni);
                    printf("Email: %s\n",datos_clientes.email);
                    printf("Numero Telefonico: %lld\n\n",datos_clientes.numero);


                printf("CONTRATOS DE LA CUENTA\n");
                ///////////////////////////////////////// LISTAR CONTRATOS
                listar_contratos_de_cliente(id);
                //FIN//////////////////////////////////// LISTAR CONTRATOS
                printf("Indique el id del contrato\n");
                scanf("%d",&id_contrato);
                
//--------------------------------- DETALLES DE CONTRATO ---------------------------------A //

                printf("ESTADO DEL CONTRATO\n");
                //abrimos el archivo para detallar  el estado de la cuenta (lo obtenemos de contrato.dat)
                FILE *archivo_contrato;
                float total_pagar,descuento;
                if((archivo_contrato = fopen("clientes/contratos.dat","r+b")) != NULL) {
                    contratos listar_contrato;
                    
                    //lo leemos en nuestra estructura
                    fread(&listar_contrato,sizeof(contratos),1,archivo_contrato);
                    //buscamos el contrato por su id
                    while(!feof(archivo_contrato)) {
                        if(datos_clientes.id == listar_contrato.id && listar_contrato.id_contrato == id_contrato) {
                            // printf("datos_clientes.id = %d y listar_contrato.id = %d\n",datos_clientes.id,listar_contrato.id);
                            //mostramos los detalles de la factura
                            printf("Fecha de inicio contrato: %d/%d/%d\n",listar_contrato.fecha_firma.day,listar_contrato.fecha_firma.mont,listar_contrato.fecha_firma.year);
                            printf("Fecha de fin contrato: %d/%d/%d\n",listar_contrato.fecha_fin.day,listar_contrato.fecha_fin.mont,listar_contrato.fecha_fin.year);
                            //-------------------- Obtenemos el descuento y el total

                            total_pagar = listar_contrato.total;
                            //descuentos(listar_contrato.dni);
                            // printf("descuento = %f\n",listar_contrato.descuento);
                            listar_contrato.descuento=realizar_descuento(total_pagar);
                            descuento = listar_contrato.descuento;
                            // printf("2descuento = %f\n",descuento);
                            // printf("2DDDDDDDDDDDDDDDDDDDDDDD\n");

                            //-------------------- Imprimimos los detalles de las facturas
                            if(datos_clientes.estado_cliente == 0) {
                                printf("Fecha de baja: %d/%d/%d\n",listar_contrato.fecha_baja.day,listar_contrato.fecha_baja.mont,listar_contrato.fecha_baja.year);
                            }
                            printf("Factura a pagar: %d/%d/%d\n",listar_contrato.fecha_factura.day,listar_contrato.fecha_factura.mont,listar_contrato.fecha_factura.year);
                            printf("Estado Cliente: %d\n",datos_clientes.estado_cliente);
                            printf("Estado Factura: %d\n",listar_contrato.estado_factura);
                            printf("Estado Renovacion: %d\n\n",listar_contrato.estado_renovacion);
                            fseek(archivo_contrato,sizeof(listar_contrato)*(-1),SEEK_CUR);
                            fwrite(&listar_contrato,sizeof(listar_contrato),1,archivo_contrato);
                            fseek(archivo_contrato,sizeof(listar_contrato),SEEK_END);
                        }
                        // printf("2DDDDDDDDDDDDDDDDDDDDDDD\n");
                        //leemos nuevamente para movernos
                        fread(&listar_contrato,sizeof(contratos),1,archivo_contrato);    
                    }
                //cerramos el archivo
                fclose(archivo_contrato);
                }   
                else
                    printf("Error en la apertura de contratos.dat\n");  

//-FIN--------------------------- DETALLES DE CONTRATO ------------------------------FIN- //
//////////////// DETALLES DEL SERVICIO
                printf("SERVICIO/S DEL CONTRATO\n\n");
                //abrimos el archivo "servicios_clientes.dat"y buscamos los servicios que tiene
                FILE *archivo_servicios;
                if((archivo_servicios = fopen("clientes/servicios_clientes.dat","rb")) != NULL) {
                    servicios_clientes datos_servicios_clientes;
                    //leo para ver los servicios del cliente
                    fread(&datos_servicios_clientes,sizeof(servicios_clientes),1,archivo_servicios);
                    while(!feof(archivo_servicios)) {
                        if(datos_clientes.dni == datos_servicios_clientes.dni && id_contrato == datos_servicios_clientes.id_contrato) {
                            printf("%-10d | %-20s | %-10d | %d/%d/%d\n",datos_servicios_clientes.id_servicio,datos_servicios_clientes.nombre_servicio,datos_servicios_clientes.estado_servicio,datos_servicios_clientes.fecha_alta.day,datos_servicios_clientes.fecha_alta.mont,datos_servicios_clientes.fecha_alta.year);
                            //lo mandamos al final
                            //--------------- ERROR, no hay que mandarlo al final, porque tiene que listar todos los servicios que encuente, nose quien escribio esto!
                            //fseek(archivo,sizeof(clientes),SEEK_END);
                            //fseek(archivo_servicios,sizeof(servicios_clientes),SEEK_END);
                        }
                        //volvemos a hacer la lectura del siguiente elemento
                        fread(&datos_servicios_clientes,sizeof(servicios_clientes),1,archivo_servicios);
                    }
                    //cerramos el archivo
                    // printf("4descuento = %d\n",descuento);
                    fclose(archivo_servicios);
                    printf("\n");
                    //------------------------ Mostramos el total a pagar
                    printf("MONTOS\n\n");
                    printf("Total = $%.2f\n",total_pagar);
                    // printf("2descuento = %d\n",descuento);
                    
                    printf("Descuento = $%.2f\n",descuento);
                    printf("Total a pagar = $%.2f\n",total_pagar-descuento);
                }
                else
                    printf("Error\n");
                //Movemos al final del archivo clientes
                fseek(archivo,sizeof(clientes),SEEK_END);
            }
            //volvemos a hacer la lectura del siguiente elemento
            fread(&datos_clientes,sizeof(clientes),1,archivo);
        }//Fin while1
        //pausamos pantalla
        system("pause");
        if(volver == 1) {
            //volvemos al listado de clientes
            listar_clientes();
        }
        //cerramos el archivo
        fclose(archivo);
    }
    else
        printf("Error\n");
}

#endif //DETALLES_CLIENTES_C