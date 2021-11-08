#ifndef LISTAR_OPERACIONES_C
#define LISTAR_OPERACIONES_C

#include<stdio.h>
#include<stdlib.h>
#include"../estructuras.h"
#include"../prototipos.h"

/*
by Sciangula Hugo v1 07/11/2021
detalles: se van a listar los servicios que correspondan con una fecha y con un estatus definido
*/
void listar_operaciones() {
    int m1,y1,mfirma,yfirma, estado;
    system("cls");
    printf("Seleccione la fecha de busqueda mm/yy\n");
    scanf("%d %d",&m1,&y1);
    printf("Seleccione el estatus del cliente 0 Baja 1 Alta\n");
    scanf("%d",&estado);
    FILE *archivo_operaciones;
    if((archivo_operaciones = fopen("clientes/contratos.dat","rb")) != NULL) {
        contratos listar_op;
        fread(&listar_op,sizeof(contratos),1,archivo_operaciones);
        while(!feof(archivo_operaciones)) {
            //-------------------------- REASIGNAMOS
            mfirma = listar_op.fecha_firma.mont;
            yfirma = listar_op.fecha_firma.year;
            //buscamos a los clientes que cumplan con esa fecha
            if(m1 == mfirma && y1 == yfirma && listar_op.estado_cliente == estado) {
                //-------------------------- LISTAMOS LOS SERVICIOS
                FILE *archivo_servicios;
                if((archivo_servicios = fopen("clientes/servicios_clientes.dat","rb")) != NULL) {
                    servicios_clientes s_clientes;
                    fread(&s_clientes,sizeof(servicios_clientes),1,archivo_servicios);
                    while(!feof(archivo_servicios)) {
                        if(listar_op.dni == s_clientes.dni) {
                            printf("%-10d | %d/%d/%-10d | ",listar_op.id,s_clientes.fecha_alta.day,s_clientes.fecha_alta.mont,s_clientes.fecha_alta.year);
                            //traemos los detalles del cliente (total, nombre, estado)
                            if(s_clientes.estado_servicio == 1) {
                                printf("Activo   | ");
                            } else {
                                printf("Inactivo | ");
                            }
                            printf(" %-10s\n",s_clientes.nombre_servicio);
                        }
                        //volvemos a leer para evitar bucle
                        fread(&s_clientes,sizeof(servicios_clientes),1,archivo_servicios);
                    }
                    printf("\n");
                    fclose(archivo_servicios);
                }
                else
                    printf("Error apertura servicios_clientes.dat\n");
            }
            //volvemos a leer para evitar bucle
            fread(&listar_op,sizeof(contratos),1,archivo_operaciones);
        }
        fclose(archivo_operaciones);
    }
    else
        printf("Error apertura contratos.dat\n");
    system("pause");
}

#endif //LISTAR_OPERACIONES_C