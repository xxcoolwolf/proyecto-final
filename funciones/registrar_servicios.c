#ifndef REGISTRAR_SERVICIOS_C
#define REGISTRAR_SERVICIOS_C

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"../estructuras.h"
#include"../prototipos.h"

//creamos los servicios en un struct

void registrar_servicios() {
        int centinela_carga_servicio=0;
            //solicitamos el tipo de servicio
        servicios carga_servicios;
        printf("Ingrese como entero el identificador del tipo de servicio\n");
        scanf("%d",&carga_servicios.tipo);
        //solicitamos un nombre al servicio
        printf("Ingrese el nombre del servicio: ");
        scanf("%s",carga_servicios.nombre);
    printf("1HOLAAAAAA\n");
    FILE *archivo;
    if((archivo = fopen("servicios/servicios.dat","a+b")) != NULL) {
        servicios busqueda_servicio;
        fread(&busqueda_servicio,sizeof(busqueda_servicio),1,archivo);
        while(!feof(archivo)){
            if(strcmp(carga_servicios.nombre,busqueda_servicio.nombre)==0){
                printf("2HOLAAAAAA\n");
                printf("No se puede cargar el servicio con el nombre \"%s\" porque ya se encuentra activo.");
                centinela_carga_servicio=1;
                system("pause");
            }
            printf("3HOLAAAAAA\n");
            fread(&busqueda_servicio,sizeof(busqueda_servicio),1,archivo);
        }
        fclose(archivo);
    }

    if((archivo = fopen("servicios/servicios.dat","ab")) != NULL) {
        if(centinela_carga_servicio==0){
            int id = 0;
            char nombre_archivo[30] = {"servicios/id_servicios.dat"};
            //solicitamos el precio del servicio
            printf("Ingrese el precio del servicio $");
            scanf("%f",&carga_servicios.precio);
            //llamamos ala funcion creacion de id
            generador_id(&id,nombre_archivo);
            //guardamos el valor de id
            carga_servicios.id = id;
            fwrite(&carga_servicios,sizeof(servicios),1,archivo);
            printf("El servicio se ha registrado exitosamente.\n");
            system("pause");    
        }
        fclose(archivo);
    }

    else
        printf("Error\n");
}

#endif //REGISTRAR_SERVICIOS_C