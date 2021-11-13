#ifndef BUSCADOR_ID_DNI_C
#define BUSCADOR_ID_DNI_C

#include<stdio.h>
#include<stdlib.h>
#include"../estructuras.h"
#include"../prototipos.h"

//GLOBALES
int global_dni_cliente, global_id_cliente;

//NOTA IMPORATAN: solo utilizar estas variables globales cuando previamente fue llamadao buscador_id_dni();

void buscador_id_dni(int id, int dni) {
    //reseteamos las variables globales
    global_dni_cliente = 0;
    global_id_cliente = 0;
    //realizaremos una busqueda en el contrato por dni o por ID
    FILE *ap_archivo;
    if((ap_archivo = fopen("clientes/contratos.dat","rb")) != NULL) {
        //declaramos nuestra estructura
        contratos e_contratos;
        //leemos el archivo
        fread(&e_contratos,sizeof(contratos),1,ap_archivo); 
        while(!feof(ap_archivo)) {
            /////////////////// BUSQUEDA
            if(id != 0) { //si estabamos buscando por id
                if(id == e_contratos.id) {
                    global_dni_cliente = e_contratos.dni;
                    global_id_cliente = e_contratos.id;
                }
            }
            else
            {
                if(dni != 0) { //si estamos buscando por dni
                    if(dni == e_contratos.dni) { 
                        global_dni_cliente = e_contratos.dni;
                        global_id_cliente = e_contratos.id;
                    }
                }
            }    
            //realizamos la busqueda nuevamente para evitar bucle
            fread(&e_contratos,sizeof(contratos),1,ap_archivo); 
        }
        //cerramos el archivo
        fclose(ap_archivo);
    }
    else
        printf("Error en la apertura contratos.dat\n");
}

#endif //BUSCADOR_ID_DNI_C