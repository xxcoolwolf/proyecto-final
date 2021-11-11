#ifndef GENERADOR_FACTURAS_C
#define GENERADOR_FACTURAS_C

#include<stdio.h>
#include<stdlib.h>
#include"../estructuras.h"
#include"../prototipos.h"
#include"fecha.c"


void generador_facturas(int id,int total, int descuento) {
    FILE *ap_facturas,*ap_contratos,*ap_servicios;
    if((ap_facturas = fopen("clientes/facturas.dat","ab")) != NULL) {
        facturas e_facturas; //e_ de estructura
        //cargamos el identificador el  cliente ID
        e_facturas.id = id;
        //cargamos el total a pagar
        e_facturas.estado_cliente = 1;
        e_facturas.estado_factura = 0;
        //cargamos las fechas del pago
        e_facturas.fecha_proximo.day = inicio_dia_cobro;
        e_facturas.fecha_proximo.mont = mont;
        e_facturas.fecha_proximo.year = year;
        //hacer validacion de dias!
        e_facturas.fecha_vencimiento.day = fin_dia_cobro;
        e_facturas.fecha_vencimiento.mont = mont;
        e_facturas.fecha_vencimiento.year = year;
        //guardamos todos los datos
        fwrite(&e_facturas,sizeof(facturas),1,ap_facturas);
        //cerramos el archivo
        fclose(ap_facturas);
    }
    else
        printf("Error apertura facturas.dat");
}

#endif //GENERADOR_FACTURAS_C