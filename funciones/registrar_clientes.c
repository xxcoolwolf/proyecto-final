#ifndef REGISTRO_C
#define REGISTRO_C

#include<stdio.h>
#include<stdlib.h>
#include"../estructuras.h"
#include"../prototipos.h"

void registrar_clientes() {
    FILE *archivo;
    int id = 0,centinela = 0, total_pagar = 0;
    //limpiamos pantalla
    system("cls");
    if((archivo = fopen("clientes/clientes.dat","ab"))) {
        clientes carga_clientes;
        //solicitamos el DNI
        printf("REGISTRO DE CLIENTE NUEVO\n");
        printf("Ingrese el DNI (sin puntos) = ");
        scanf("%d",&carga_clientes.dni);
        fflush(stdin);
        //ahora vamos a verificar que el dni exista, en caso de que existiece significaria que ya esta registrado, y lo redireccionariamos al apartado de modificaciones c:
        verificacion_dni(&centinela,carga_clientes.dni);
        if(centinela == 0) {
            char nombre_archivo[30] = {"clientes/id_clientes.dat"};
            printf("Nombre Completo: ");
            scanf("%s",carga_clientes.nombre);
            fflush(stdin);
            printf("Ingrese el numero telefonico: ");
            scanf("%lld",&carga_clientes.numero);
            fflush(stdin);
            printf("Ingrese la dirrecion: ");
            scanf("%s",carga_clientes.direccion);
            fflush(stdin);
            printf("Ingrese la direccion del email: ");
            scanf("%s",carga_clientes.email);
            fflush(stdin);
            printf("Seleccione un Servicio\n");
            //en esta llamamos a una funcion para solicitar la seleccion de los servicios
            seleccionar_servicio(&total_pagar,carga_clientes.dni);
            //ahora cargamos ese total en el registro del cliente
            //verificamos que se hayan seleccionado servicios
            if(total_pagar != 0) {
                //generamos id
                generador_id(&id,nombre_archivo);
                //cargamos el id en el struct
                carga_clientes.id = id;
                carga_clientes.total = total_pagar;
                //carga en el archivo binario
                fwrite(&carga_clientes,sizeof(clientes),1,archivo);
            }
            else
            {
                printf("Error 552: [DEBE SELECCIONAR SERVICIOS]\n");
                system("pause");
            }

            //cerramos el archivo
            fclose(archivo);
        }
        else
        {
          //en caso de que el dni ya este registrado, lo redirecciona a modificaciones
          modificar_clientes();
        }
    }
    else
        printf("Error\n");
}

#endif //REGISTRO_C