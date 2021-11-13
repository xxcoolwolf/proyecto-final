#ifndef PAGO_FACTURAS_C
#define PAGO_FACTURAS_C

#include<stdio.h>
#include<stdlib.h>
#include"../estructuras.h"
#include"../prototipos.h"
#include"fecha.c"

void pago_facturas() {
    int id_buscado,opcion,no_pagado = 0,total_pagar = 0,descuento = 0,centinela_activo = 0;
    system("cls");
    printf("Ingrese el id de la cuenta\n");
    scanf("%d",&id_buscado);
    FILE *ap_facturas;
    //abrimos la factura del cliente
    if((ap_facturas = fopen("clientes/facturas.dat","rb")) != NULL) {
        facturas e_facturas;
        //traemos los datos del archivo
        fread(&e_facturas,sizeof(facturas),1,ap_facturas);
        while(!feof(ap_facturas)) {
            //buscamos al cliente por ID 
            if(id_buscado == e_facturas.id) {
                if(e_facturas.estado_factura == 1 && e_facturas.fecha_pago.mont == mont && e_facturas.fecha_pago.year == year) {
                    printf("Tu factura ya esta pagada, espera al proximo mes!\n");
                }
                else
                {
                    //activamos el centinela vencido
                    no_pagado = 1;
                    //mostramos los detalles
                    printf("PAGAR FACTURA \n\n");
                    printf("ID Cliente = %d\n",id_buscado);
                    /////////////////////////////////////////////////////
                    //Aca traemos el monto total a pagar
                    FILE *ap_contratos;
                    if((ap_contratos = fopen("clientes/contratos.dat","rb")) != NULL) {
                        contratos e_contratos;
                        fread(&e_contratos,sizeof(contratos),1,ap_contratos);
                        while(!feof(ap_contratos)) {
                            //buscamos al cliente
                            if(e_contratos.id == id_buscado && e_contratos.estado_cliente == 1) {
                                total_pagar = e_contratos.total;
                                descuento = e_contratos.descuento;
                                centinela_activo = 1;
                            }
                            else
                            {
                                // en caso de que se haya dado de baja
                                if(e_contratos.id == id_buscado && e_contratos.estado_cliente == 0) {
                                    centinela_activo = 0;
                                    no_pagado = 0;
                                }
                            }
                            //volvemos a avanzar para evitar el bucle
                            fread(&e_contratos,sizeof(contratos),1,ap_contratos);
                        }
                        //cerramos el archivo
                        fclose(ap_contratos);
                    }
                    else
                        printf("Error de apertura contratos.dat\n");
                    /////////////////////////////////////////////////////
                    printf("Fecha Vencimiento = %d/%d/%d\n",e_facturas.fecha_vencimiento.day,e_facturas.fecha_vencimiento.mont,e_facturas.fecha_vencimiento.year);
                    printf("Monto a Pagar = $%d\n",total_pagar-descuento);
                    //verificamos que la factura no este vencida corroborando con la fecha
                    if(e_facturas.fecha_vencimiento.day < day) {
                        //significa que su factura esta vencida y se le va a hacer un recargo
                        printf("RECARGO POR VENCIMIENTO = $%d\n",total_pagar * 0.2);
                        total_pagar = total_pagar * 1.2; //le hacemos un incremento del 20%
                    }
                    printf("Total a pagar = $%d\n\n",total_pagar);
                    if(centinela_activo == 1) {
                        printf("1 (Pagar) 0 (Cancelar)\n");
                        scanf("%d",&opcion);
                    }
                    else
                    {
                        system("cls");
                        printf("No podes pagar, has sido dado de baja!\n");
                    }
                    //imprimimos mensaje de pago
                    if(opcion == 1)
                        printf("Pago realizado correctamente \n");
                        //FALTO GUARDAR EL PAGADO
                    
                }
                fseek(ap_facturas,sizeof(facturas),SEEK_END);
            }
            //volvemos a leer para evitar bucle
            fread(&e_facturas,sizeof(facturas),1,ap_facturas);
        }
        //cerramos el archivo
        fclose(ap_facturas);
    }
    else
    {
        printf("Error de apertura facturas.dat\n");
    }
        

    
    //A partir de aca vamos a realizar las modificaciones en la factura del mismo cliente
    if(no_pagado == 1) {
        int year_fun,mont_fun,day_fun;
        no_pagado = 0;
        FILE *m_facturas; //m de modificar
        if((m_facturas = fopen("clientes/facturas.dat","r+b")) != NULL) {
            facturas e_facturas;
            //traemos los datos a la estructura
            fread(&e_facturas,sizeof(facturas),1,m_facturas);
            while(!feof(m_facturas)) {
                //buscamos al cliente 
                if(id_buscado == e_facturas.id) {
                    //como ya esta vencido, automaticamente cambiamos al estatus 0
                    e_facturas.estado_factura = 0;
                    //si el cliente selecciono pagar, le renovamos por 1 mes
                    
                    if(opcion == 1) {
                        opcion = 0;
                        fecha_diferenciador(year,mont,day,&year_fun,&mont_fun,&day_fun,1);
                        //guardamos la che que se pago
                        e_facturas.fecha_pago.day = day;
                        e_facturas.fecha_pago.mont = mont;
                        e_facturas.fecha_pago.year = year;
                        //aca guardamos las fechas de cobro para la siguiente factura
                        e_facturas.fecha_proximo.day = inicio_dia_cobro;
                        e_facturas.fecha_proximo.mont = mont_fun;
                        e_facturas.fecha_proximo.year = year_fun;
                        e_facturas.fecha_vencimiento.day = fin_dia_cobro;
                        e_facturas.fecha_vencimiento.mont = mont_fun;
                        e_facturas.fecha_vencimiento.year = year_fun;
                        //aca indicamos que ya pago la factura
                        e_facturas.estado_factura = 1;
                        /////////////////////////////////////////////////////
                        //Aca traemos el monto total a pagar
                        FILE *ap_contratos;
                        if((ap_contratos = fopen("clientes/contratos.dat","r+b")) != NULL) {
                            contratos e_contratos;
                            fread(&e_contratos,sizeof(contratos),1,ap_contratos);
                            while(!feof(ap_contratos)) {
                                //buscamos al cliente
                                if(e_contratos.id == id_buscado) {
                                    e_contratos.estado_factura = 1;
                                    e_contratos.fecha_factura.day = day_fun;
                                    e_contratos.fecha_factura.mont = mont_fun;
                                    e_contratos.fecha_factura.year = year_fun;
                                    //obtenemos la ubicacion en la que estamos
                                    int posicion_contratos = ftell(ap_contratos)-sizeof(contratos);
                                    //nos posicionamos para realizar la modificacion
                                    fseek(ap_contratos,posicion_contratos,SEEK_SET);
                                    //guardamos los datos
                                    fwrite(&e_contratos,sizeof(contratos),1,ap_contratos);
                                    break;
                                }
                                //volvemos a avanzar para evitar el bucle
                                fread(&e_contratos,sizeof(contratos),1,ap_contratos);
                            }
                            //cerramos el archivo
                            fclose(ap_contratos);
                        }
                        else
                            printf("Error de apertura contratos.dat\n");
                        /////////////////////////////////////////////////////
                    }
                    else
                    {
                        //en desarrollo
                    }

                    //obtenemos la ubicacion en la que estamos
                    int posicion = ftell(m_facturas)-sizeof(facturas);
                    //nos posicionamos para realizar la modificacion
                    fseek(m_facturas,posicion,SEEK_SET);
                    //guardamos los datos
                    fwrite(&e_facturas,sizeof(facturas),1,m_facturas);
                    break;
                }
                //volvemos a leer para evitar bucle
                fread(&e_facturas,sizeof(facturas),1,m_facturas);
            }

            //cerramos el archivo
            fclose(m_facturas);
        }
        else
            printf("Error de apertura facturas.dat\n");
    }
    //pausamos
    system("pause");
}

#endif //PAGO_FACTURAS_C