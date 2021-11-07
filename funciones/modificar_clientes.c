#ifndef MODIFICAR_CLIENTES
#define MODIFICAR_CLIENTES

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"../estructuras.h"
#include"../prototipos.h"

void modificar_clientes(){
  FILE *archivo;
    if((archivo=fopen("clientes/clientes.dat","r+b"))){
        int id=0,opcion,pos,idexistente=0;
        clientes modificar_clientes;
        //el usuario ingresa el id 
        printf("Ingrese el ID del cliente que desee modificar :");
        scanf("%d",&id);
        fread(&modificar_clientes,sizeof(clientes),1,archivo);
        while(!feof(archivo)) {
            //si el id es igual a modificar_clientes.id entonces entra al bucle
            if (id==modificar_clientes.id){
                //muestra los datos ya cargados anteriormente
                //printf("%-10d | %-10d | %-20s | %-10lld | %-30s | %-10.2f\n",modificar_clientes.id,modificar_clientes.dni, modificar_clientes.nombre, modificar_clientes.numero,modificar_clientes.direccion,modificar_clientes.total);
                do
                {
                    //si el ID EXISTE, entonces va a mostrar un menu en donde el cliente pueda elegir el dato que quiera modificar
                    printf("1-modificar el email del cliente \n");
                    printf("2-modificar el numero telefonico del cliente \n"); 
                    printf("3-modificar la direccion del cliente \n");   
                    printf("4-modificar los servicios del cliente \n");  
                    printf("5-finalizar\n"); 
                    printf("ingrese la opcion que desee\n");
                    //ingresa la opcion que desee
                    scanf("%d",&opcion);
                    switch(opcion) {
                        case 1:
                            //ingresamos el nuevo dato
                            printf("Ingrese el nuevo gmail del cliente:");
                            scanf("%s",modificar_clientes.email);
                            fflush(stdin);
                            //buscamos la posicion a la que se debe cambiar el dato
                            pos=ftell(archivo)-sizeof(clientes);
                            //se cambia
                            fseek(archivo,pos,SEEK_SET);
                            //modificamos en el archivo
                            fwrite(&modificar_clientes,sizeof(clientes),1,archivo);
                            printf("Se modifico el gmail para el cliente ingresado\n");
                            idexistente=1;
                        break;
                        case 2:
                            printf("Ingrese el nuevo numero del cliente:");
                            scanf("%lld",&modificar_clientes.numero);
                            fflush(stdin);
                            pos=ftell(archivo)-sizeof(clientes);
                            fseek(archivo,pos,SEEK_SET);
                            fwrite(&modificar_clientes,sizeof(clientes),1,archivo);
                            printf("Se modifico el numero para el cliente ingresado\n");
                            idexistente=1;
                        break;
                        case 3:
                            printf("Ingrese la nueva dirrecion del cliente:");
                            scanf("%s",modificar_clientes.direccion);
                            fflush(stdin);
                            pos=ftell(archivo)-sizeof(clientes);
                            fseek(archivo,pos,SEEK_SET);
                            fwrite(&modificar_clientes,sizeof(clientes),1,archivo);
                            printf("Se modifico la direccion para el cliente ingresado\n");
                            //si el id existe, entonces se cambia a 1
                            idexistente=1;
                        break;
                        case 4:
                            printf("ACA SE TIENE QUE MODIFICAR EL SERVICIO (actualizar)\n");
                            modificar_servicios_clientes(id);
                        break;
                        
                    }
            printf("Estoy dentro opcion %d\n",opcion);


//ERROR CRITICO FATAL DE BUCLE MEGA INFINITO -----------------------------------------------------------------------


            fseek(archivo,sizeof(clientes),SEEK_END);

            
            } while(opcion != 5);    
            }
        printf("Estoy fuera opcion %d\n",opcion);
        //leemos lo que se modifico en el archivo
        //
        fread(&modificar_clientes,sizeof(clientes),1,archivo);
        }
        //si el id que se ingreso todavia no fue resgitrado, va a mostar esto		
        if(idexistente==0){
            printf("El id ingresado no fue registrado\n");
        }
        //cierro el archivo
        fclose(archivo);
        system("PAUSE"); 
    }
    else
    	printf("error\n");

}


#endif //MODIFICAR_CLIENTES