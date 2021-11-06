#ifndef DETALLES_CLIENTES_C
#define DETALLES_CLIENTES_C

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"../estructuras.h"
#include"../prototipos.h"

void detalles_cliente(int id,int volver) {
    FILE *archivo;
    if((archivo = fopen("clientes/clientes.dat","rb")) != NULL) {
        //limpiamos la pantalla
        system("cls");
        printf("DETALLES DEL CLIENTE\n");
        clientes datos_clientes;
        //veo si no esta vacio el archivo
        fread(&datos_clientes,sizeof(clientes),1,archivo);
        while(!feof(archivo)) {
            //lo buscamos por id
            if(id == datos_clientes.id) {
                printf("ID: %d\n",datos_clientes.id);
                printf("Nombre: %s\n",datos_clientes.nombre);
                printf("DNI: %d\n",datos_clientes.dni);
                printf("Email: %s\n\n",datos_clientes.email);
                printf("ESTADO DE LA CUENTA\n");
                printf("Fecha de Alta: %d\n",datos_clientes.fecha_alta);
                printf("Fecha de Baja: %d\n",datos_clientes.fecha_baja);
                printf("Estado Cliente: %d\n",datos_clientes.estado_cliente);
                printf("Estado Factura: %d\n\n",datos_clientes.estado_factura);
                printf("SERVICIO DEL CLIENTE\n\n");
                //abrimos el archivo "servicios_clientes.dat"y buscamos los servicios que tiene
                FILE *archivo_servicios;
                if((archivo_servicios = fopen("clientes/servicios_clientes.dat","rb")) != NULL) {
                    servicios_clientes datos_servicios_clientes;
                    //leo para ver los servicios del cliente
                    fread(&datos_servicios_clientes,sizeof(servicios_clientes),1,archivo_servicios);
                    while(!feof(archivo_servicios)) {
                        if(datos_clientes.dni == datos_servicios_clientes.dni) {
                            printf("%-10d | %-20s | %-10d\n",datos_servicios_clientes.id_servicio,datos_servicios_clientes.nombre_servicio,datos_servicios_clientes.estado_servicio);
                            //lo mandamos al final
                            fseek(archivo,sizeof(clientes),SEEK_END);
                            fseek(archivo_servicios,sizeof(servicios_clientes),SEEK_END);
                        }
                        //volvemos a hacer la lectura del siguiente elemento
                        fread(&datos_servicios_clientes,sizeof(servicios_clientes),1,archivo_servicios);
                    }
                    //cerramos el archivo
                    fclose(archivo_servicios);
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