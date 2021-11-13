#ifndef SELECCIONAR_SERVICIO
#define SELECCIONAR_SERVICIO

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"../estructuras.h"
#include"../prototipos.h"
#include"fecha.c"

//seleccionar servicios

void seleccionar_servicio(int *total_pagar,int dni) {
    FILE *archivo,*verificacion,*cambiar_total;
    int servicio_seleccionado,centinela=0;
    servicios carga_servicios;
        //lo realizamos con un do por el hecho de que se requiere seleccionar varios tipos de servicios
        do
        {   
            //listamos los servicios
            listar_servicios(0); //0 mostrar menu, 1 no mostrar menu
            //luego de listar todos los servicios con el tipo, le consultamos que servicio quiere agregar 
            printf("ID del servicio o 0 (Salir)\n");
            scanf("%d",&servicio_seleccionado);
            /////////////////VERIFICACION DE LA EXISTENCIA DEL ID SELECCIONADO////////////////////////
            if((verificacion=fopen("clientes/servicios_clientes.dat","r+b"))){
                servicios_clientes busqueda_servicio;
                fread(&busqueda_servicio,sizeof(busqueda_servicio),1,verificacion);
                centinela=0;
                while(!feof(verificacion)){
                    //si tanto el id del servicio es igual al seleccionado, el dni de la persona coincida con el dni almacenado en el servicio y el estado del servicio sea activo (1). Entra
                    if(servicio_seleccionado==busqueda_servicio.id_servicio && dni==busqueda_servicio.dni && busqueda_servicio.estado_servicio==1){
                        printf("Actualmente el servicio con id %d ya se encuentra seleccionado por el cliente.\n",busqueda_servicio.id_servicio);
                        centinela=1;
                        system("pause");
                        //si tanto el id del servicio es igual al seleccionado, el dni de la persona coincida con el dni almacenado en el servicio y el estado del servicio sea inactivo (0). Entra
                    }else if(servicio_seleccionado==busqueda_servicio.id_servicio && dni==busqueda_servicio.dni && busqueda_servicio.estado_servicio==0){
                        printf("Nombre: %s\n",busqueda_servicio.nombre_servicio);
                        // reactivamos el serivcio
                        busqueda_servicio.estado_servicio=1;
                        busqueda_servicio.fecha_alta.day = day;
                        busqueda_servicio.fecha_alta.mont = mont;
                        busqueda_servicio.fecha_alta.year = year;
                        fseek(verificacion,sizeof(busqueda_servicio)*(-1),SEEK_CUR);
                        fwrite(&busqueda_servicio,sizeof(busqueda_servicio),1,verificacion);
                        fseek(verificacion,sizeof(busqueda_servicio),SEEK_END);
                        printf("Servicio reactivado\n");
                        ////////////////////////////AUMENTAR EL TOTAL/////////////////////////////////
                        if((cambiar_total=fopen("servicios/servicios.dat","rb"))!=NULL){
                            servicios servicio_buscado;
                            fread(&servicio_buscado,sizeof(servicio_buscado),1,cambiar_total);
                            while(!feof(cambiar_total)){
                                if(servicio_buscado.id==servicio_seleccionado){
                                    *total_pagar = *total_pagar + servicio_buscado.precio;
                                }
                                fread(&servicio_buscado,sizeof(servicio_buscado),1,cambiar_total);
                            }
                            
                            fclose(cambiar_total);
                        }
                        ////////////////////////////FIN AUMENTAR EL TOTAL/////////////////////////////////
                        centinela=1;
                        system("pause");
                        // break;
                    }
                    fread(&busqueda_servicio,sizeof(busqueda_servicio),1,verificacion);
                }
            }
            /////////////////FIN VERIFICACION DE LA EXISTENCIA DEL ID SELECCIONADO////////////////////////







        if(centinela==0){
            //abrimos el archivo servicios.dat
            if((archivo = fopen("servicios/servicios.dat","rb")) != NULL) {
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
                                
                                //----------------------------- guaramos el precio del servicio
                                guardar_servicios.precio = carga_servicios.precio;

                                //--------------------- Guardamos la fecha de contratacion
                                guardar_servicios.fecha_alta.day = day;
                                guardar_servicios.fecha_alta.mont = mont;
                                guardar_servicios.fecha_alta.year = year;
                                //test
                                //--------------------- Guardamos la fecha de contratacion
                                fwrite(&guardar_servicios,sizeof(servicios_clientes),1,archivo_servicios);
                                //fprintf(archivo_tx,"%s",carga_servicios.nombre);
                                fclose(archivo_servicios); 
                            }
                            //aca le asignamos el total que tendria que pagar el cliente
                            *total_pagar = *total_pagar + carga_servicios.precio;
                        }
                        //volvemos a leer para movernos y chequear los demas servicios
                        fread(&carga_servicios,sizeof(servicios),1,archivo);
                    }
                }
        //cerrar el archivo
                fclose(archivo);
            }
            else
                printf("Error\n");
                
            }

        }while(servicio_seleccionado != 0);
    //pausamos pantalla
    system("pause");
}

#endif //SELECCIONAR_SERVICIO