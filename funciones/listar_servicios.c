#ifndef LISTAR_SERVICIOS_C
#define LISTAR_SERVICIOS_C

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"../estructuras.h"
#include"../prototipos.h"

//Listar Servicios
/*
by Sciangula Hugo v1 28/10/21
detalles: vamos a listar los servicios disponibles en el archivo 
*/
void listar_servicios(int menu) {
    FILE *archivo;
    int tipo_seleccionado,continuar;
    servicios carga_servicios;
    if((archivo = fopen("servicios/servicios.dat","rb")) != NULL) {
        do
        {   
            system("cls");
            rewind(archivo);
            printf("1. Plus TV\n");
            printf("2. Planes Internet\n");
            scanf("%d",&tipo_seleccionado);
            system("cls");
            //leemos del archivo el struct
            fread(&carga_servicios,sizeof(servicios),1,archivo);
            while(!feof(archivo)) {
                //los clasificamos segun el tipo de servicio
                if(tipo_seleccionado == carga_servicios.tipo) {
                    printf("%-4d | %-20s | %-10.2f\n",carga_servicios.id,carga_servicios.nombre,carga_servicios.precio);
                }
                //volvemos a leer para movernos y chequear los demas servicios
                fread(&carga_servicios,sizeof(servicios),1,archivo);
            }
            //volvemos a imprimir
            if(menu == 1) {
                printf("1 (Ver Tipos) 0 (Ok)\n");
                scanf("%d",&continuar);
            }
            else
                continuar = 0;
            
        } while(continuar != 0);    
    }
    else {
        printf("Error\n");
        system("pause"); 
    }
}

#endif //LISTAR_SERVICIOS_C