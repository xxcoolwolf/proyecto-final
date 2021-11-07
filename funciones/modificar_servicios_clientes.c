#ifndef MODIFICAR_SERVICIOS_CLIENTES_C
#define MODIFICAR_SERVICIOS_CLIENTES_C

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"../estructuras.h"
#include"../prototipos.h"
/*
by hugo
*/
 void modificar_servicios_clientes(int id) {

    FILE *archivo,*busqueda;

    if((archivo=fopen("servicios/modificar_servicios.dat","r+b"))!=NULL){
        int opcion,dni;
        servicios_clientes cambio_servicio;
        clientes busqueda_clietes;

        do{
            //si el ID EXISTE, entonces va a mostrar un menu en donde el cliente pueda elegir el dato que quiera modificar
            printf("1-Añadir servicio \n");
            printf("2-Desactivar servicio del cliente \n");  
            printf("3-finalizar\n"); 
            printf("Ingrese la opcion que desee: \n");
            //ingresa la opcion que desee
            scanf("%d",&opcion);
            switch(opcion) {
                case 1:

                break;
                case 2:

                    if((busqueda=fopen("clientes/clientes.dat","r+b"))!=NULL){
                        fread(&busqueda_clietes,sizeof(busqueda_clietes),1,archivo);
                        while(!feof(busqueda)){
                            
                            //acá me quedé
                            //hay que buscar el dni del cliente con el id, y luego buscar servicio para desactivarlo
                            if(id==busqueda_clietes.id){
                                dni=busqueda_clietes.dni;
                            }
                            fread(&busqueda_clietes,sizeof(busqueda_clietes),1,archivo);
                        }
                        fclose(busqueda);
                    }
                    fread(&cambio_servicio,sizeof(servicios_clientes),1,archivo);
                    while(!feof(archivo)){

                        if(dni==cambio_servicio.dni){
                            printf("id = %d / nombre = %s\n",cambio_servicio.id_servicio,cambio_servicio.nombre_servicio);
                        }

                        fread(&cambio_servicio,sizeof(servicios_clientes),1,archivo);
                    }
                break;
            }
        printf("Estoy dentro opcion %d\n",opcion);


    //ERROR CRITICO FATAL DE BUCLE MEGA INFINITO -----------------------------------------------------------------------


        fseek(archivo,sizeof(clientes),SEEK_END);

        
        } while(opcion != 3);


        fclose(archivo);
    }


    
}

#endif