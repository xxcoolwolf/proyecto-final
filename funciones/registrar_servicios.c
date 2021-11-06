#ifndef REGISTRAR_SERVICIOS_C
#define REGISTRAR_SERVICIOS_C

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"../estructuras.h"
#include"../prototipos.h"

//creamos los servicios en un struct
/*
by Sciangula Hugo v1 26/10/21
detalles: se va crear en un struct servicios de forma ilimitada, con un id, y un nombre y un precio, que luego van a poder ser modificados.
*/
void registrar_servicios() {
    FILE *archivo;
    if((archivo = fopen("servicios/servicios.dat","ab")) != NULL) {
        servicios carga_servicios;
        int id = 0;
        char nombre_archivo[30] = {"servicios/id_servicios.dat"};
        //llamamos ala funcion creacion de id
        generador_id(&id,nombre_archivo);
        //guardamos el valor de id
        carga_servicios.id = id;
        //solicitamos el tipo de servicio
        printf("Ingrese como entero el identificador del tipo de servicio\n");
        scanf("%d",&carga_servicios.tipo);
        //solicitamos un nombre al servicio
        printf("Ingrese el nombre del servicio: ");
        scanf("%s",carga_servicios.nombre);
        //solicitamos el precio del servicio
        printf("Ingrese el precio del servicio $");
        scanf("%f",&carga_servicios.precio);
        fwrite(&carga_servicios,sizeof(servicios),1,archivo);
        //cerramos el archivo
        fclose(archivo);
    }
    else
        printf("Error\n");
}

#endif //REGISTRAR_SERVICIOS_C