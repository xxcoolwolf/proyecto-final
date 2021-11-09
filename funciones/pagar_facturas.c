#ifndef PAGAR_FACTURAS
#define PAGAR_FACTURAS

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"../estructuras.h"
#include"../prototipos.h"
#include"fecha.c"

void pagar_facturas(){

    //---------------------PERIODO DE LA FACTURA------------------------------------
    // if(fecha_ahora==fecha_firma){
    //     i_p=fecha_firma;
    //     f_p=30/fecha_firma.mes/f_firma.año;
    // }else{
    //     i_p=1/f_p.mes+1/f_p.año;
    //     f_p=30/f_p.mes+1/f_p.año;
    // }
    int id,dni_buscado;
    printf("Ingresar el id del cliente: ");scanf("%d",&id);
    int dda,mma,yya,posicion;
    dda=day;
    mma=mont;
    printf("mmaaaa = %d\n",mma);
    yya=year;
    fechas mes_siguiente;
    // printf("Periodo de Facturación: %d/%d/%d - %d/%d/%d",i_p.day,i_p.mont,i_p.year,f_p.day,f_p.mont,f_p.year);

    //BUSQUEDA DEL DNI DEL CLIENTE CON ID n

    FILE *archivo_clientes;
    if((archivo_clientes=fopen("clientes/clientes.dat","r+b"))){
        clientes busqueda_dni;
        //busqueda de la fecha de firma de cliente con id n
        fread(&busqueda_dni,sizeof(busqueda_dni),1,archivo_clientes);
        while(!feof(archivo_clientes)){
            
            if(id==busqueda_dni.id){
                dni_buscado=busqueda_dni.dni;
                printf("DNI cliente = %d\n",dni_buscado);
            }


            fread(&busqueda_dni,sizeof(busqueda_dni),1,archivo_clientes);
        }

        fclose(archivo_clientes);
    }



//     FILE *archivo_contrato;
//     if((archivo_contrato=fopen("clientes/contratos.dat","r+b"))){
//         contratos busqueda_contrato;
//         //busqueda de la fecha de firma de cliente con id n
//         fread(&busqueda_contrato,sizeof(busqueda_contrato),1,archivo_contrato);
//         while(!feof(archivo_contrato)){
            
//             if(dni_buscado==busqueda_contrato.dni){
//                 // if(fecha_ahora==fecha_firma){
//                 //     i_p=fecha_firma;
//                 //     f_p=30/fecha_firma.mes/f_firma.año;
//                 // }else{
//                 //     i_p=1/f_p.mes+1/f_p.año;
//                 //     f_p=30/f_p.mes+1/f_p.año;
//                 // }
//                 printf("Dentro de segundo if\n");
//                 // mes_siguiente.mont=busqueda_contrato.fecha_firma.mont+1;
//                 // if(mes_siguiente.mont>12){
//                 //     mes_siguiente.year=busqueda_contrato.fecha_firma.year+1;
//                 //     mes_siguiente.mont=1;
//                 // }else{
//                 //     mes_siguiente.year=busqueda_contrato.fecha_firma.year;
//                 // }

// printf("0busqueda = %d\n",busqueda_contrato.estado_factura);
//                     if(busqueda_contrato.estado_factura==10){
//                         printf("1busqueda = %d\n",busqueda_contrato.estado_factura);
//                 // if(mes_siguiente.mont==mma && busqueda_contrato.fecha_firma.year==yya){
//                         printf("Dentro de 3 if\n");
//                         busqueda_contrato.i_p.day=dda;
//                         busqueda_contrato.i_p.mont=mma;
//                         busqueda_contrato.i_p.year=yya;
//                         printf("1MMAAAAAAAAAAAAAAAA = %d",mma);
//                         busqueda_contrato.f_p.day=meses(2,mma);
//                         busqueda_contrato.f_p.mont=mma;
//                         busqueda_contrato.f_p.year=yya;
//                         printf("1PUNTOOOOOOOOOOOOOOOOOOOO\n");
//                         busqueda_contrato.estado_factura=1;
//                         posicion = ftell(archivo_contrato) - sizeof(busqueda_contrato);
//                         //ahora nos movemos hacia esa posicion desde el inicio
//                         fseek(archivo_contrato,posicion,SEEK_SET);
//                         fwrite(&busqueda_contrato,sizeof(busqueda_contrato),1,archivo_contrato);
//                         printf("Se desactivo correctamente el producto \n");
//                         system("pause");
//                         //lo mandamos al final
//                         fseek(archivo_contrato,sizeof(busqueda_contrato),SEEK_SET);
//                         // printf("0Periodo de Facturación: %d/%d/%d - %d/%d/%d\n",i_p.day,i_p.mont,i_p.year,f_p.day,f_p.mont,f_p.year);
//                     // }else{
//                     }else if(busqueda_contrato.estado_factura==1){
//                         busqueda_contrato.estado_factura=0;
//                         if(busqueda_contrato.estado_factura==0){
//                             busqueda_contrato.i_p.day=1;
//                             busqueda_contrato.i_p.mont=busqueda_contrato.f_p.mont+1;
//                             busqueda_contrato.i_p.year=yya;//---------------CAMBIAR DE AÑO SI SE PASA DE MESES
//                             printf("1MMAAAAAAAAAAAAAAAA = %d",busqueda_contrato.i_p.mont);
//                             busqueda_contrato.f_p.day=meses(2,busqueda_contrato.f_p.mont+1);
//                             busqueda_contrato.f_p.mont=busqueda_contrato.f_p.mont+1;
//                             busqueda_contrato.f_p.year=yya;//---------------CAMBIAR DE AÑO SI SE PASA DE MESES
//                             printf("2PUNTOOOOOOOOOOOOOOOOOOOO\n");
//                             busqueda_contrato.estado_factura=1;
//                             posicion = ftell(archivo_contrato) - sizeof(busqueda_contrato);
//                             //ahora nos movemos hacia esa posicion desde el inicio
//                             fseek(archivo_contrato,posicion,SEEK_SET);
//                             fwrite(&busqueda_contrato,sizeof(busqueda_contrato),1,archivo_contrato);
//                             printf("Se desactivo correctamente el producto \n");
//                             system("pause");
//                             //lo mandamos al final
//                             fseek(archivo_contrato,sizeof(busqueda_contrato),SEEK_SET);
//                         }
                        
//                         // printf("1Periodo de Facturación: %d/%d/%d - %d/%d/%d\n",i_p.day,i_p.mont,i_p.year,f_p.day,f_p.mont,f_p.year);
//                     // }
//                     }
                    
//                 // printf("Periodo de Facturación: %d/%d/%d - %d/%d/%d",i_p.day,i_p.mont,i_p.year,f_p.day,f_p.mont,f_p.year);



                
//             }

//             printf("3PUNTOOOOOOOOOOOOOOOOOOOO\n");
//             fread(&busqueda_contrato,sizeof(busqueda_contrato),1,archivo_contrato);
//         }

//         fclose(archivo_contrato);
//     }


    
// printf("4PUNTOOOOOOOOOOOOOOOOOOOO\n");



    //fin obtención de períoda de la factura

    //----------------------------AUMENTO POR DEMORA--------------------------------
    // Modificación del total a pagar por demora
    // if(f_actual>f_venc_1 && f_actual>f_venc_2){
    //     total=total+(0.02*total);
    // }else if(f_actual.mes>f_venc_2){
    //     a=f_actual.mes;
    //     b=f_venc_2.mes;
    //     n=a-f;
    //     for (i=1;i<=n;i++)
    //     {
    //         total=total+(0.01*total);
    //     }
        
    // }else if(f_actual.mes<f_venc_2.mes){
    //     n=12-f_venc_2.mes;
    //     n=n+f_actual.mes;
    //     for (i=1;i<=n;i++)
    //     {
    //         total=total+(0.01*total);
    //     }
    // }
    // Fin Modificación del total a pagar por demora

























    // int da,ma,ya;

    // FILE *demora;

    // if((demora=fopen("clientes/contratos.dat","a+b"))!=NULL){






    //     fclose(demora);
    // }

    // da=day;
    // ma=mont;
    // ya=year;

    // vd1=5;
    // vm1=mont;
    // vy1=year;

    // vd2=10;
    // vm2=mont;
    // vy2=year;
    // int centinela=0,centinela2=0;
    // if(ya > vy1) {
    //     centinela = 1;
    // } 
    // else 
    // {
    //     if(ya == vy1) {
    //         if(ma > vm1) {
    //             centinela = 1;
    //         }
    //         else
    //         {
    //             if(ma == vm1) {
    //                 if(da > vd1) {
    //                     centinela = 1;
    //                 }
    //             }
    //         }
    //     }  
    // } //y2 > yfirma

    // if(ya > vy2) {
    //     centinela2 = 1;
    // } 
    // else 
    // {
    //     if(ya == vy1) {
    //         if(ma > vm2) {
    //             centinela2 = 1;
    //         }
    //         else
    //         {
    //             if(ma == vm1) {
    //                 if(da > vd2) {
    //                     centinela2 = 1;
    //                 }
    //             }
    //         }
    //     }  
    // } //y2 > yfirma


    // if(centinela == 1 && centinela2 == 1) {

        


    // }

    // if( && f_actual>f_venc_2){
    //     total=total+(0.02*total);
    // }else if(f_actual.mes>f_venc_2){
    //     a=f_actual.mes;
    //     b=f_venc_2.mes;
    //     n=a-f;
    //     for (i=1;i<=n;i++)
    //     {
    //         total=total+(0.01*total);
    //     }
        
    // }else if(f_actual.mes<f_venc_2.mes){
    //     n=12-f_venc_2.mes;
    //     n=n+f_actual.mes;
    //     for (i=1;i<=n;i++)
    //     {
    //         total=total+(0.01*total);
    //     }
    // }

























































    FILE *archivo;
    if((archivo = fopen("clientes/clientes.dat","r+b")) != NULL) {
        //limpiamos la pantalla
        // system("cls");
        rewind(archivo);
        printf("DETALLES DEL CLIENTE\n\n");
        clientes datos_clientes;
        //veo si no esta vacio el archivo
        fread(&datos_clientes,sizeof(clientes),1,archivo);
        while(!feof(archivo)) {
            //lo buscamos por id
            if(id == datos_clientes.id) {
                printf("ID Cliente: %d\n",datos_clientes.id);
                printf("Nombre: %s\n",datos_clientes.nombre);
                printf("DNI: %d\n",datos_clientes.dni);
                printf("Email: %s\n",datos_clientes.email);
                printf("Numero Telefonico: %lld\n\n",datos_clientes.numero);
                
//--------------------------------- DETALLES DE CONTRATO ---------------------------------A //

                printf("ESTADO DE LA CUENTA\n\n");
                //abrimos el archivo para detallar el estado de la cuenta (lo obtenemos de contrato.dat)
                FILE *archivo_contrato;
                float total_pagar,descuento;
                if((archivo_contrato = fopen("clientes/contratos.dat","a+b")) != NULL) {
                    contratos listar_contrato;
                    //lo leemos en nuestra estructura
                    fread(&listar_contrato,sizeof(contratos),1,archivo_contrato);
                    //buscamos el contrato por su id
                    while(!feof(archivo_contrato)) {
                        if(datos_clientes.id == listar_contrato.id) {
                            //mostramos los detalles de la factura
                            printf("Fecha de inicio contrato: %d/%d/%d\n",listar_contrato.fecha_firma.day,listar_contrato.fecha_firma.mont,listar_contrato.fecha_firma.year);
                            printf("Fecha de fin contrato: %d/%d/%d\n",listar_contrato.fecha_fin.day,listar_contrato.fecha_fin.mont,listar_contrato.fecha_fin.year);
                            //-------------------- Obtenemos el descuento y el total
                            total_pagar = listar_contrato.total;
                            descuento = listar_contrato.descuento;
                            //-------------------- Imprimimos los detalles de las facturas
                            if(listar_contrato.estado_cliente == 0) {
                                printf("Fecha de baja: %d/%d/%d\n",listar_contrato.fecha_baja.day,listar_contrato.fecha_baja.mont,listar_contrato.fecha_baja.year);
                            }
                            printf("Factura a pagar: %d/%d/%d\n",listar_contrato.fecha_factura.day,listar_contrato.fecha_factura.mont,listar_contrato.fecha_factura.year);
                            printf("Estado Cliente: %d\n",listar_contrato.estado_cliente);
                            printf("Estado Factura: %d\n",listar_contrato.estado_factura);
                            printf("Estado Renovacion: %d\n\n",listar_contrato.estado_renovacion);
                            // printf("Periodo de Facturación: %d/%d/%d - %d/%d/%d\n",listar_contrato.i_p.day,listar_contrato.i_p.mont,listar_contrato.i_p.year,listar_contrato.f_p.day,listar_contrato.f_p.mont,listar_contrato.f_p.year);
                        }
                        //leemos nuevamente para movernos
                        fread(&listar_contrato,sizeof(contratos),1,archivo_contrato);    
                    }
                //cerramos el archivo
                // fclose(archivo_contrato);
                // }   
                // else
                //     printf("Error en la apertura de contratos.dat\n");  

                    //   printf("3Periodo de Facturación: %d/%d/%d - %d/%d/%d\n",i_p.day,i_p.mont,i_p.year,f_p.day,f_p.mont,f_p.year);      
//-FIN--------------------------- DETALLES DE CONTRATO ------------------------------FIN- //

                printf("SERVICIO/S DEL CLIENTE\n\n");
                //abrimos el archivo "servicios_clientes.dat"y buscamos los servicios que tiene
                FILE *archivo_servicios;
                if((archivo_servicios = fopen("clientes/servicios_clientes.dat","rb")) != NULL) {
                    servicios_clientes datos_servicios_clientes;
                    //leo para ver los servicios del cliente
                    fread(&datos_servicios_clientes,sizeof(servicios_clientes),1,archivo_servicios);
                    while(!feof(archivo_servicios)) {
                        if(datos_clientes.dni == datos_servicios_clientes.dni) {
                            printf("%-10d | %-20s | %-10d | %d/%d/%d\n",datos_servicios_clientes.id_servicio,datos_servicios_clientes.nombre_servicio,datos_servicios_clientes.estado_servicio,datos_servicios_clientes.fecha_alta.day,datos_servicios_clientes.fecha_alta.mont,datos_servicios_clientes.fecha_alta.year);
                            //lo mandamos al final
                            //--------------- ERROR, no hay que mandarlo al final, porque tiene que listar todos los servicios que encuente, nose quien escribio esto!
                            //fseek(archivo,sizeof(clientes),SEEK_END);
                            //fseek(archivo_servicios,sizeof(servicios_clientes),SEEK_END);
                        }
                        //volvemos a hacer la lectura del siguiente elemento
                        fread(&datos_servicios_clientes,sizeof(servicios_clientes),1,archivo_servicios);
                    }
                    //cerramos el archivo
                    fclose(archivo_servicios);
                    printf("\n");
                    //------------------------ Mostramos el total a pagar
                    printf("MONTOS\n\n");
                    printf("Total = $%.2f\n",total_pagar);
                    printf("Descuento = $%.2f\n",descuento);
                    printf("Total a pagar = $%.2f\n",total_pagar-descuento);
                }
                else
                    printf("Error\n");
                //PONER DO WHILE-----------------------------------------------------
                printf("Pagar contrato: ");scanf("%d",&listar_contrato.estado_factura);
                printf("1busqueda = %d\n",listar_contrato.estado_factura);
                posicion=ftell(archivo_contrato)-sizeof(listar_clientes);
                fseek(archivo_contrato,posicion,SEEK_SET);
                fwrite(&listar_clientes,sizeof(listar_clientes),1,archivo_contrato);
                

                fclose(archivo_contrato);
                }   
                else
                    printf("Error en la apertura de contratos.dat\n");
            }
            //volvemos a hacer la lectura del siguiente elemento
            fread(&datos_clientes,sizeof(clientes),1,archivo);
        }
        //pausamos pantalla
        system("pause");
        //cerramos el archivo
        fclose(archivo);
    }
    else
        printf("Error\n");
    




}





#endif