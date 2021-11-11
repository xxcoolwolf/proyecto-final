#ifndef VERIFICACION_DNI
#define VERIFICACION_DNI

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"../estructuras.h"
#include"../prototipos.h"

//verificacion del dni existente o no en el struct

void verificacion_dni(int *centinela, int dni_cargado) {
    FILE *archivo;
    printf("Vericacion dni cliente\n");
    if((archivo = fopen("clientes/clientes.dat","rb")) != NULL) {
      //obtenemos los datos del archivo binario en el struct
      clientes carga_clientes;
      fread(&carga_clientes,sizeof(clientes),1,archivo);
      while(!feof(archivo)) {
         //ahora comparamos con el dni cargado
         if(dni_cargado==carga_clientes.dni) {
           printf("Cliente ya registrado\n");
           //modificamos por referencia el centinela
           *centinela = 1;
         } 
        //seguimos recorriendo para que llegue al final
        fread(&carga_clientes,sizeof(clientes),1,archivo);
      }
    }
    else
      printf("Error\n");
}

#endif //VERIFICACION_DNI