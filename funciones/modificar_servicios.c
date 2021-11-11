#ifndef MODIFICAR_SERVICIOS_C
#define MODIFICAR_SERVICIOS_C

#include<stdio.h>
#include<stdlib.h>
#include"../estructuras.h"
#include"../prototipos.h"


void modificar_servicios() {
    system("cls");
    int id_servicio,seleccion;
    printf("Ingrese el id del servicio a modificar: ");scanf("%d",&id_servicio);
    FILE *archivo_servicios;
    if((archivo_servicios=fopen("servicios/servicios.dat","r+b"))!=NULL){
        servicios e_servicio;
        fread(&e_servicio,sizeof(e_servicio),1,archivo_servicios);
        while(!feof(archivo_servicios)){
            if(id_servicio==e_servicio.id){
                do{
                    system("cls");
                    printf("CAMBIO PROPIEDADES DEL SERVICIO %d\n",id_servicio);
                    printf("1. Cambiar tipo\n");
                    printf("2. Cambiar nombre\n");
                    printf("3. Cambiar precio\n");
                    printf("4. Atras\n");
                    scanf("%d",&seleccion);
                }while(seleccion<1 || seleccion>4);
                switch(seleccion){
                    case 1:
                        printf("Ingresar el nuevo tipo del servicio: ");scanf("%d",&e_servicio.tipo);
                        printf("tipo = %d\n",e_servicio.tipo);
                    break;
                    case 2:
                        fflush(stdin);
                        printf("Ingresar el nuevo nombre del servicio: ");gets(e_servicio.nombre);
                        puts(e_servicio.nombre);
                    break;
                    case 3:
                        printf("Ingresar el nuevo precio del servicio: $");scanf("%f",&e_servicio.precio);
                        printf("precio = %d\n",e_servicio.precio);
                    break;
                }
                fseek(archivo_servicios,sizeof(e_servicio)*(-1),SEEK_CUR);
                fwrite(&e_servicio,sizeof(e_servicio),1,archivo_servicios);
                if(seleccion!=4){
                    printf("El servicio se ha modificado correctamente.");
                    system("pause");
                }
                fseek(archivo_servicios,sizeof(e_servicio),SEEK_END);
            }
            fread(&e_servicio,sizeof(e_servicio),1,archivo_servicios);
        }
    }else{
        printf("Error modificar servicios\n");
    }
}

#endif //MODIFICAR_SERVICIOS_C