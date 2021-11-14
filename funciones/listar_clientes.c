#ifndef LISTAR_CLIENTES_C
#define LISTAR_CLIENTES_C

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"../estructuras.h"
#include"../prototipos.h"

//listado de clientes


void listar_clientes() {
    int id_cliente,centinela=0;
    float total_mostrar;
    FILE *archivo;
    //limpiamos pantalla
    system("cls");
    if((archivo = fopen("clientes/clientes.dat","rb"))) {
        clientes carga_clientes;
        printf("LISTADO DE CLIENTES\n");
        fread(&carga_clientes,sizeof(clientes),1,archivo);
        if(!feof(archivo)) {
            while(!feof(archivo))
            {
                if(centinela!=carga_clientes.id){
                            FILE *arch;
                            if((arch=fopen("clientes/contratos.dat","rb"))!=NULL){
                                // printf("1HOLAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA\n");
                                contratos busq_c;
                                total_mostrar=0;
                                fread(&busq_c,sizeof(busq_c),1,arch);
                                while(!feof(arch)){
                                    // printf("2HOLAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA\n");
                                    if(carga_clientes.id == busq_c.id && busq_c.estado_contrato==1){
                                        total_mostrar+=(busq_c.total-busq_c.descuento);
                                    }
                                    fread(&busq_c,sizeof(busq_c),1,arch);
                                }
                                fclose(arch);
                            }
                            
            //--------------------------------- LISTADO DE CON DETALLES DE LA CUENTA --------------------------------- //
                            FILE *archivo_contratos;
                            if((archivo_contratos = fopen("clientes/contratos.dat","rb")) != NULL) {
                                contratos listar_contratos;
                                //ahora lo leemos a nuestro archivo
                                fread(&listar_contratos,sizeof(contratos),1,archivo_contratos);
                                //realizamos la busqueda de los detalles del cliente
                                while(!feof(archivo_contratos)) {
                                    if(carga_clientes.id == listar_contratos.id) {
                                        if(listar_contratos.total == 0)
                                            listar_contratos.descuento = 0;
                                            // printf("3HOLAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA\n");
                                        printf("%-10d | %-10d | %-20s | %-10lld | %-30s | %-10.2f\n",carga_clientes.id,carga_clientes.dni, carga_clientes.nombre, carga_clientes.numero,carga_clientes.direccion,total_mostrar);
                                        fseek(archivo_contratos,sizeof(listar_contratos),SEEK_END);
                                    }
                                //nos movemos en el archivo
                                // printf("4HOLAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA\n");
                                fread(&listar_contratos,sizeof(contratos),1,archivo_contratos);
                                }
                                // printf("5HOLAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA\n");
                                centinela=carga_clientes.id;
                            }
                            else
                                printf("Error\n");

                }
                
//-FIN--------------------------- LISTADO DE CON DETALLES DE LA CUENTA ------------------------------FIN- //
            //nos movemos en el archivo
                centinela=carga_clientes.id;
            fread(&carga_clientes,sizeof(clientes),1,archivo);
            }
            //cerramos el archivo
            fclose(archivo);
            printf("Ingrese el ID del cliente para ver los detalles o 0 (salir)\n");
            scanf("%d",&id_cliente);
            if(id_cliente != 0)
                detalles_cliente(id_cliente,1);
        }
        else {
            printf("No hay clientes cargados\n");
            system("pause");
        }
    }
    else
        printf("Error\n");
}

#endif //LISTAR_CLIENTES_C