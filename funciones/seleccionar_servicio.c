#ifndef SELECCIONAR_SERVICIO
#define SELECCIONAR_SERVICIO

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"../estructuras.h"
#include"../prototipos.h"

//seleccionar servicios
/*
by Sciangula Hugo v1 26/10/21
detalles: 
*/
void seleccionar_servicio(int *total_pagar,int dni) {
    FILE *archivo;
    int tipo_seleccionado,servicio_seleccionado;
    servicios carga_servicios;
    //abrimos el archivo servicios.dat
    if((archivo = fopen("servicios/servicios.dat","rb")) != NULL) {
        //lo realizamos con un do por el hecho de que se requiere seleccionar varios tipos de servicios
        do
        {   
            //listamos los servicios
            listar_servicios();
            //luego de listar todos los servicios con el tipo, le consultamos que servicio quiere agregar 
            printf("ID del servicio o 0 (Salir)\n");
            scanf("%d",&servicio_seleccionado);
            //guardamos el servicio en un txt
            if(servicio_seleccionado != 0) {
                //volvemos el apuntador al inicio, para que vuelva a recorrer los servicios
                rewind(archivo);
                //leemos del archivo el struct
                fread(&carga_servicios,sizeof(servicios),1,archivo);
                while(!feof(archivo)) {
                    //los clasificamos segun el tipo de servicio
                    if(servicio_seleccionado == carga_servicios.id) {
                        printf("Seleccionaste el servicio %s\n",carga_servicios.nombre);
                        FILE *archivo_servicios;
                        servicios_clientes guardar_servicios;
                        //leemos un texto y lo guardamos en un archivo
                        if((archivo_servicios = fopen("clientes/servicios_clientes.dat","ab"))!=NULL) {
                            //obtenemos el nombre
                            strcpy(guardar_servicios.nombre_servicio,carga_servicios.nombre);
                            //obtenemos el id del cliente
                            guardar_servicios.dni = dni;
                            guardar_servicios.id_servicio = carga_servicios.id;
                            guardar_servicios.estado_servicio = 1;
                            fwrite(&guardar_servicios,sizeof(servicios_clientes),1,archivo_servicios);
                            //fprintf(archivo_tx,"%s",carga_servicios.nombre);
                            fclose(archivo_servicios); 
                        }
                        //aca le asignamos el total que tendria que pagar el cliente
                        *total_pagar = *total_pagar + carga_servicios.precio;
                        /*
                        typedef struct {
                            //lo vamos a identificar por un id
                            int id,id_servicio,estado_servicio,fecha;
                            char nombre_servicio[30];
                        } servicios_clientes;
                        */
                    }
                    //volvemos a leer para movernos y chequear los demas servicios
                    fread(&carga_servicios,sizeof(servicios),1,archivo);
                }
            }
        } while(servicio_seleccionado != 0);
        //cerrar el archivo
        fclose(archivo);
    }
    else
        printf("Error\n");
    //pausamos pantalla
    system("pause");
}

#endif //SELECCIONAR_SERVICIO