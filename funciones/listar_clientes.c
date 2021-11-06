#ifndef LISTAR_CLIENTES_C
#define LISTAR_CLIENTES_C

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"../estructuras.h"
#include"../prototipos.h"

//listado de clientes
/*
by Sciangula Hugo v1 26/10/21
detalles: se listan los clientes una vez leido el struct, nada del otro mundo
*/

void listar_clientes() {
    int id_cliente;
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
                printf("%-10d | %-10d | %-20s | %-10lld | %-30s | %-10.2f\n",carga_clientes.id,carga_clientes.dni, carga_clientes.nombre, carga_clientes.numero,carga_clientes.direccion,carga_clientes.total);
                //lo volvemos a enviar al archivo
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