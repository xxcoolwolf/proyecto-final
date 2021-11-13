#ifndef REGISTRO_C
#define REGISTRO_C

#include<stdio.h>
#include<stdlib.h>
#include"../estructuras.h"
#include"../prototipos.h"
//inclusion de la hora del sistema
#include"fecha.c"
#include"buscador_id_dni.c"

void registrar_clientes() {
    FILE *archivo;
    int id = 0,centinela = 0, total_pagar = 0, descuento = 0;
    //limpiamos pantalla
    system("cls");
    //mostramos la fecha actual
    printf("%d/%d/%d\n",day,mont,year);
    //Abrimos el archivo para la carga de los datos del cliente
    if((archivo = fopen("clientes/clientes.dat","ab"))) {
        clientes carga_clientes;
        //solicitamos el DNI
        printf("REGISTRO DE CLIENTE NUEVO\n");
        printf("Ingrese el DNI (sin puntos) = ");
        scanf("%d",&carga_clientes.dni);
        fflush(stdin);
        //ahora vamos a verificar que el dni exista, en caso de que existiece significaria que ya esta registrado, y lo redireccionariamos al apartado de modificaciones c:
        verificacion_dni(&centinela,carga_clientes.dni);
        //si la centinela es igual a 1 significa que el dni está repetido y no entra al if
        if(centinela == 0) {
            //toma de datos
            char nombre_archivo[30] = {"clientes/id_clientes.dat"},nombre_contratos[30] = {"clientes/id_contratos.dat"};
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
            printf("Seleccione un Servicio\n");
            //llamamos a una funcion para solicitar la seleccion de los servicios
            seleccionar_servicio(&total_pagar,carga_clientes.dni);
            //ahora cargamos ese total en el registro del cliente
            //verificamos que se hayan seleccionado servicios, ya que si nungun servicio ha sido
            //seleccionado, no se registra al cliente
            if(total_pagar != 0) {
                //generamos id
                generador_id(&id,nombre_archivo);
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
                    //definimos a la estructura de contratos
                    contratos carga_contratos;
                    //procedemos a guardar los datos del cliente en contratos
                    carga_contratos.id_contrato = id_contrato;
                    carga_contratos.id = id;
                    carga_contratos.total = total_pagar;
                    carga_contratos.descuento = 0;
                    //realizamos los descuentos dependiendo del monto a pagar
                    if(total_pagar >= 3000 && total_pagar <= 4000) {
                        //descuento del 20%
                        carga_contratos.descuento = total_pagar * 0.2;
                        //guardamos estos parametros para luego mandarlos a la generacion de factura
                        descuento = carga_contratos.descuento;
                    } 
                    else 
                    {
                        if(total_pagar >= 4001 && total_pagar <= 6000) {
                            //decuento del 25%
                            carga_contratos.descuento = total_pagar * 0.25;
                            //guardamos estos parametros para luego mandarlos a la generacion de factura
                            descuento = carga_contratos.descuento;
                        }
                        else
                        {
                            if(total_pagar > 6000) {
                                //descuento del 30%
                                carga_contratos.descuento = total_pagar * 0.3;
                                //guardamos estos parametros para luego mandarlos a la generacion de factura
                                descuento = carga_contratos.descuento;
                            }
                        }
                    } 
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
                    carga_contratos.estado_cliente = 1;
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
            generador_facturas(id,total_pagar,descuento);
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
}

#endif //REGISTRO_C