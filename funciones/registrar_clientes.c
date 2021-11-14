#ifndef REGISTRO_C
#define REGISTRO_C

#include<stdio.h>
#include<stdlib.h>
#include"../estructuras.h"
#include"../prototipos.h"
//inclusion de la hora del sistema
#include"fecha.c"
#include"buscador_id_dni.c"
#include"globales.c"

void registrar_clientes() {
    FILE *archivo;
    int id = 0,centinela = 0, total_pagar = 0, descuento_realizado = 0;
    //limpiamos pantalla
    system("cls");
    //mostramos la fecha actual
    printf("%d/%d/%d\n",day,mont,year);
    //Abrimos el archivo para la carga de los datos del cliente
    if((archivo = fopen("clientes/clientes.dat","ab"))) {
        clientes carga_clientes;
        //solicitamos el DNI
        //////////////////////////////////////////// REUTILIZACION DE FUNCION SIN ESTE TEXTO
        if(centinela_global == 0) { //verificamos la variable global por si se esta reutilizando solo algunas partes de la funcion
            printf("REGISTRO DE CLIENTE NUEVO\n");
            printf("Ingrese el DNI (sin puntos) = ");
            scanf("%d",&carga_clientes.dni);
            fflush(stdin);
            //ahora vamos a verificar que el dni exista, en caso de que existiece significaria que ya esta registrado, y lo redireccionariamos al apartado de modificaciones c:
            verificacion_dni(&centinela,carga_clientes.dni);
        }
        if(centinela_modificador_global == 0) { 
            //no sucede nada
        }
        else
            centinela = 0; //modificamos el centinela que permite la ejecucion del codigo
        //FIN/////////////////////////////////////// REUTILIZACION DE FUNCION SIN ESTE TEXTO
        //si la centinela es igual a 1 significa que el dni está repetido y no entra al if
        if(centinela == 0) {

            char nombre_archivo[30] = {"clientes/id_clientes.dat"},nombre_contratos[30] = {"clientes/id_contratos.dat"};
            if(centinela_global == 0) { //verificamos la variable global por si se esta reutilizando solo algunas partes de la funcion
                /////////////////////////////////////////// SE TOMA LOS DATOS
                printf("Nombre Completo: ");
                //scanf("%s",carga_clientes.nombre);
                gets(carga_clientes.nombre);
                fflush(stdin);
                printf("Ingrese el numero telefonico: ");
                scanf("%lld",&carga_clientes.numero);
                fflush(stdin);
                printf("Ingrese la dirrecion: ");
                //scanf("%s",carga_clientes.direccion);
                gets(carga_clientes.direccion);
                fflush(stdin);
                printf("Ingrese la direccion del email: ");
                //scanf("%s",carga_clientes.email);
                gets(carga_clientes.email);
                fflush(stdin);
                //FIN////////////////////////////////////// SE TOMA LOS DATOS
            }
            else
            {
                //Luego de este else, se utilizara el dni
                carga_clientes.dni = dni_cliente_global;
            }
            printf("Seleccione un Servicio\n");
            //llamamos a una funcion para solicitar la seleccion de los servicios
            seleccionar_servicio(&total_pagar,carga_clientes.dni);
            //ahora cargamos ese total en el registro del cliente
            //verificamos que se hayan seleccionado servicios, ya que si nungun servicio ha sido
            //seleccionado, no se registra al cliente
            if(total_pagar != 0) {
                if(centinela_global == 0) { //verificamos la variable global por si se esta reutilizando solo algunas partes de la funcion
                    //generamos id
                    generador_id(&id,nombre_archivo);
                }
                else
                {
                    id = id_cliente_global;
                }
                //cargamos el id en el struct
                carga_clientes.id = id;
//--------------------------------- GENERAR CONTRATO --------------------------------- //
                //declaramos un id de contrato
                int id_contrato = 0; 
                //comenzamos con la apertura del archivo de contratos
                FILE *archivo_contratos;
                if((archivo_contratos = fopen("clientes/contratos.dat","ab")) != NULL) {
                    //llamamos a la funcion de generacion de contratos
                    generador_id(&id_contrato,nombre_contratos);
                    id_cliente_contrato_global = id_contrato;
                    //definimos a la estructura de contratos
                    contratos carga_contratos;
                    //procedemos a guardar los datos del cliente en contratos
                    carga_contratos.id_contrato = id_contrato;
                    carga_contratos.id = id;
                    carga_contratos.total = total_pagar;
                    carga_contratos.descuento = 0;
                    carga_contratos.descuento=realizar_descuento(total_pagar);
                    descuento_realizado= carga_contratos.descuento;
                    printf("Total = %d\n",total_pagar);
                    printf("Descuento = %d\n",descuento_realizado);
                    system("pause");


                    //------------------------- FECHA CONTRATO
                    //guardamos la fecha de inicio de contrato
                    carga_contratos.fecha_firma.sec = sec;
                    carga_contratos.fecha_firma.min = min;
                    carga_contratos.fecha_firma.day = day;
                    carga_contratos.fecha_firma.mont = mont;
                    carga_contratos.fecha_firma.year = year;

                    //------------------------- FECHA FIN CONTRATO
                    //llamamos a la funcion diferenciador fecha, para asignarle un descuento por 6 meses, si es que cumple alguna de las condiciones
                    int year_fun,mont_fun,day_fun;
                    fecha_diferenciador(year,mont,day,&year_fun,&mont_fun,&day_fun,6); //el 6 es por el descuento de 6 meses
                    //guardamos la fecha de fin de contrato
                    carga_contratos.fecha_fin.sec = sec;
                    carga_contratos.fecha_fin.min = min;
                    carga_contratos.fecha_fin.day = day_fun;
                    carga_contratos.fecha_fin.mont = mont_fun;
                    carga_contratos.fecha_fin.year = year_fun;

                    //------------------------- FECHA FACTURA
                    //generamos la primer fecha de factura
                    fecha_diferenciador(year,mont,inicio_dia_cobro,&year_fun,&mont_fun,&day_fun,1);
                    carga_contratos.fecha_factura.sec = sec;
                    carga_contratos.fecha_factura.min = min;
                    carga_contratos.fecha_factura.day = day_fun;
                    carga_contratos.fecha_factura.mont = mont_fun;
                    carga_contratos.fecha_factura.year = year_fun;

                    //------------------------- DEFINIMOS LOS ESTADOS
                    carga_clientes.estado_cliente = 1;
                    carga_contratos.estado_factura = 0;
                    carga_contratos.estado_renovacion = 1;
                    carga_contratos.dni = carga_clientes.dni;
                    //realizamos la escritura en el archivo
                    fwrite(&carga_contratos,sizeof(contratos),1,archivo_contratos);

                
                //creamos txt de contratos
                //cerramos el archivo
                fclose(archivo_contratos);
                }
                else
                    printf("El archivo aun no existe\n");

                    
//-FIN--------------------------- GENERAR CONTRATO ------------------------------FIN- //
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
//--------------------------------- GENERAMOS LA FACTURA DEL CLIENTE --------------------------------- //

            //llamamos a la funcion de generacion de factura
            generador_facturas(id,total_pagar,descuento_realizado);
            generador_txt(id);

//-FIN--------------------------- GENERAMOS LA FACTURA DEL CLIENTE ------------------------------FIN- //
        }
        else
        {
          //en caso de que el dni ya este registrado, le creamos un nuevo contrato con el nuevo servicio generado
          buscador_id_dni(0,carga_clientes.dni);
          modificar_clientes(global_id_cliente);
        }
    }
    else
        printf("Error\n");
    /////////////////////////////////////////////////////////////////////////////// RESETEO GLOBALES
    reseteo_globales();
    //FIN////////////////////////////////////////////////////////////////////////// RESETEO GLOBALES
}

#endif //REGISTRO_C