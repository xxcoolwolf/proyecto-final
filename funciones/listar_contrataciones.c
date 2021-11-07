#ifndef LISTAR_CONTRATACIONES_C
#define LISTAR_CONTRATACIONES_C

#include<stdio.h>
#include<stdlib.h>
#include"../estructuras.h"
#include"../prototipos.h"

/*
by Sciangula Hugo 67377
detalles: en esta funcion se van a listar todas las contrataciones que se hicieron de una fecha a otra
*/

void listar_contrataciones() {
    int y1,y2,m1,m2,d1,d2,dfirma,mfirma,yfirma,centinela = 0;
    system("cls");
    printf("Ingrese desde que fecha buscar: ");
    scanf("%d %d %d",&d1,&m1,&y1);
    printf("Ingrese hasta que fecha buscar: ");
    scanf("%d %d %d",&d2,&m2,&y2);
    printf("\n");
    FILE *archivo_contrataciones;
    //limpiamos la pantalla
    system("cls");
    if((archivo_contrataciones = fopen("clientes/contratos.dat","rb")) != NULL) {
        contratos listar_contratos;
        fread(&listar_contratos,sizeof(contratos),1,archivo_contrataciones);
        while(!feof(archivo_contrataciones)) {
            //-------------------------- RENOMBRAMOS
            dfirma = listar_contratos.fecha_firma.day;
            mfirma = listar_contratos.fecha_firma.mont;
            yfirma = listar_contratos.fecha_firma.year;
            //verificamos el year
            if(y2 > yfirma) {
                centinela = 1;
            } 
            else 
            {
                if(y2 == yfirma) {
                    if(m2 > mfirma) {
                        centinela = 1;
                    }
                    else
                    {
                        if(m2 == mfirma) {
                            if(d2 > dfirma) {
                                centinela = 1;
                            }
                        }
                    }
                }  
            } //y2 > yfirma
            if((dfirma >= d1 && mfirma >= m1 && yfirma >= y1) && centinela == 1) {
                printf("%-10d | %d/%d/%-10d | ",listar_contratos.id,listar_contratos.fecha_firma.day,listar_contratos.fecha_firma.mont,listar_contratos.fecha_firma.year); 
                //traemos los detalles del cliente (total, nombre, estado)
                if(listar_contratos.estado_cliente == 1) {
                    printf("Activo | ");
                } else {
                    printf("Inactivo | ");
                }
                printf(" %.2f\n",listar_contratos.total-listar_contratos.descuento);
            }
            //nos movemos para evitar el bucle
            fread(&listar_contratos,sizeof(contratos),1,archivo_contrataciones);
        }
    fclose(archivo_contrataciones);
    }   
    else
        printf("Error de apertura contratos.dat\n"); 
    system("pause");
}

#endif //LISTAR_CONTRATACIONES_C