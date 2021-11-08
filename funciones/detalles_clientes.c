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
    FILE *archivo;
    if((archivo = fopen("clientes/clientes.dat","rb")) != NULL) {
        //limpiamos la pantalla
        system("cls");
        printf("DETALLES DEL CLIENTE\n\n");
        clientes datos_clientes;
        //veo si no esta vacio el archivo
        fread(&datos_clientes,sizeof(clientes),1,archivo);
        while(!feof(archivo)) {
            //lo buscamos por id
            if(id == datos_clientes.id) {
                printf("ID Cliente: %d\n",datos_clientes.id);
                printf("Nombre: %s\n",datos_clientes.nombre);
                printf("DNI: %d\n",datos_clientes.dni);
                printf("Email: %s\n",datos_clientes.email);
                printf("Numero Telefonico: %lld\n\n",datos_clientes.numero);
                
//--------------------------------- DETALLES DE CONTRATO ---------------------------------A //

                printf("ESTADO DE LA CUENTA\n\n");
                //abrimos el archivo para detallar el estado de la cuenta (lo obtenemos de contrato.dat)
                FILE *archivo_contrato;
                float total_pagar,descuento;
                if((archivo_contrato = fopen("clientes/contratos.dat","rb")) != NULL) {
                    contratos listar_contrato;
                    //lo leemos en nuestra estructura
                    fread(&listar_contrato,sizeof(contratos),1,archivo_contrato);
                    //buscamos el contrato por su id
                    while(!feof(archivo_contrato)) {
                        if(datos_clientes.id == listar_contrato.id) {
                            //mostramos los detalles de la factura
                            printf("Fecha de inicio contrato: %d/%d/%d\n",listar_contrato.fecha_firma.day,listar_contrato.fecha_firma.mont,listar_contrato.fecha_firma.year);
                            printf("Fecha de fin contrato: %d/%d/%d\n",listar_contrato.fecha_fin.day,listar_contrato.fecha_fin.mont,listar_contrato.fecha_fin.year);
                            //-------------------- Obtenemos el descuento y el total
                            total_pagar = listar_contrato.total;
                            descuento = listar_contrato.descuento;
                            //-------------------- Imprimimos los detalles de las facturas
                            if(listar_contrato.estado_cliente == 0) {
                                printf("Fecha de baja: %d/%d/%d\n",listar_contrato.fecha_baja.day,listar_contrato.fecha_baja.mont,listar_contrato.fecha_baja.year);
                            }
                            printf("Factura a pagar: %d/%d/%d\n",listar_contrato.fecha_factura.day,listar_contrato.fecha_factura.mont,listar_contrato.fecha_factura.year);
                            printf("Estado Cliente: %d\n",listar_contrato.estado_cliente);
                            printf("Estado Factura: %d\n",listar_contrato.estado_factura);
                            printf("Estado Renovacion: %d\n\n",listar_contrato.estado_renovacion);
                        }
                        //leemos nuevamente para movernos
                        fread(&listar_contrato,sizeof(contratos),1,archivo_contrato);    
                    }
                //cerramos el archivo
                fclose(archivo_contrato);
                }   
                else
                    printf("Error en la apertura de contratos.dat\n");  

//-FIN--------------------------- DETALLES DE CONTRATO ------------------------------FIN- //

                printf("SERVICIO/S DEL CLIENTE\n\n");
                //abrimos el archivo "servicios_clientes.dat"y buscamos los servicios que tiene
                FILE *archivo_servicios;
                if((archivo_servicios = fopen("clientes/servicios_clientes.dat","rb")) != NULL) {
                    servicios_clientes datos_servicios_clientes;
                    //leo para ver los servicios del cliente
                    fread(&datos_servicios_clientes,sizeof(servicios_clientes),1,archivo_servicios);
                    while(!feof(archivo_servicios)) {
                        if(datos_clientes.dni == datos_servicios_clientes.dni) {
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
                    fclose(archivo_servicios);
                    printf("\n");
                    //------------------------ Mostramos el total a pagar
                    printf("MONTOS\n\n");
                    printf("Total = $%.2f\n",total_pagar);
                    printf("Descuento = $%.2f\n",descuento);
                    printf("Total a pagar = $%.2f\n",total_pagar-descuento);
                }
                else
                    printf("Error\n");
            }
            //volvemos a hacer la lectura del siguiente elemento
            fread(&datos_clientes,sizeof(clientes),1,archivo);
        }
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