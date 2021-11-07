#include<stdio.h>
#include<stdlib.h>
#include"includes.h"
    int main() {
        system("cls");
        //consultamos la fecha del sistema
        fecha();
        //ofrecemos las opciones v1 prototipo de menu
        int opcion_seleccionada,id_buscar;
        do  {
            //limpiamos pantalla 
            system("cls");
            printf("%d/%d/%d\n",day,mont,year);
            printf("XONARED - A la velocidad de la luz\n");
            printf("1 - Registrar Cliente\n");
            printf("2 - Lista Rapida\n");
            printf("3 - Generar Servicios\n");
            printf("4 - Listar Servicios\n");
            printf("5 - Detalles Completos\n");
            printf("6 - Modificar Cliente\n");
            printf("7 - Hola Menali\n");
            scanf("%d",&opcion_seleccionada);
            switch(opcion_seleccionada) {
                case 1: registrar_clientes();
                break;
                case 2: listar_clientes();
                break;
                case 3: registrar_servicios();
                break;
                case 4: listar_servicios();
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
            }
        } while(opcion_seleccionada != 0);
        system("PAUSE");
        return 0;
    }