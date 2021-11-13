#include<stdio.h>
#include<stdlib.h>
#include"includes.h"
    int main() {
        system("cls");
        //ofrecemos las opciones v1 prototipo de menu
        int opcion_seleccionada,id_buscar,puestos=0,opcion_seleccionada_fecha;
        puesto(&puestos);
        fecha(1,0);
        do  {
            //limpiamos pantalla 
            system("cls");//
            //consultamos la fecha del sistema
            fecha(0,1);
            printf("XONARED - A la velocidad de la luz\n");
            if(puestos==1){
                printf("111 - Modificacion Fechas\n");
            }
            printf("0 - Finalizar Programa\n");
            printf("1 - Registrar Cliente\n");
            printf("2 - Lista Rapida\n");
            printf("3 - Generar Servicios\n");
            printf("4 - Listar Servicios\n");
            printf("5 - Detalles Completos\n");
            printf("6 - Modificar Cliente\n");
            printf("7 - Modificar Propriedades Servicio\n");
            printf("8 - Listar Contratos de fecha a fecha\n");
            printf("9 - Listar Operaciones\n");
            printf("10 - Pagar Factura\n");
            printf("11 - Modificar Estado Cliete\n");
            printf("12 - Servicio Mas Contratado\n");
            printf(">> ");
            scanf("%d",&opcion_seleccionada);
            switch(opcion_seleccionada) {
                if(puestos==1){
                    case 111:
                        do{
                            system("cls");
                            fecha(0,1);
                            printf("1 - Fecha actual\n");
                            printf("2 - Modificar Fecha\n");
                            printf("3 - Atras\n");
                            scanf("%d",&opcion_seleccionada_fecha);
                        }while(opcion_seleccionada_fecha<1 || opcion_seleccionada_fecha>3);
                        switch(opcion_seleccionada_fecha){
                            case 1:
                                fecha(1,0);
                            break;
                            case 2:
                                system("cls");
                                fecha(0,1);
                                printf("Introducir fecha actual (dd mm yy): ");scanf("%d %d %d",&day,&mont,&year);
                            break;
                        }
                    break;
                }
                case 1: registrar_clientes();//check
                break;
                case 2: listar_clientes();
                break;
                case 3: registrar_servicios();
                break;
                case 4: listar_servicios(1);
                break;
                case 5:
                //solicitamos el ID
                    printf("Ingrese el ID del cliente: ");
                    scanf("%d",&id_buscar);
                    detalles_cliente(id_buscar,0); 
                break;
                case 6:
                    modificar_clientes(); 
                break;
                case 7:
                    modificar_servicios(); 
                break;
                case 8:
                    listar_contrataciones();
                break;
                case 9:
                    listar_operaciones();
                break;
                case 10:
                    pago_facturas();
                break;
                case 11:
                    estado_clientes();
                break;
                case 12:
                    mayor_contratacion();
                break;
                case 13:
                break;
            }
        } while(opcion_seleccionada != 0);
        system("PAUSE");
        return 0;
    }