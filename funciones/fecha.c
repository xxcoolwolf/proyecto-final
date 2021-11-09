#ifndef FECHA_C
#define FECHA_C
//funciones
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

/*
by Sciangula Hugo 67377
detalles: en esta funcion, lo que se hace es obtener la fecha actual del sistema, y se avisa a todas las funciones que requieren saber dicha fecha, a partir de variables globales.
*/

//GLOBALES
int year,mont,day,hour,min,sec;

void fecha() {
    time_t fecha; //lo definimos tipo time_t
    fecha=time(NULL); //le asignamos NULL
    struct tm tiempoLocal = *localtime(&fecha); //obtenemos la hora del sistema en donde se ejecuta el codigo
    //obtenemos year
    year = tiempoLocal.tm_year+1900;
    //obtenemos mes
    mont = tiempoLocal.tm_mon+1;
    //obtenemos day
    day = tiempoLocal.tm_mday;
    //obtenemos hour
    hour = tiempoLocal.tm_hour;
    //obtenemos min
    min = tiempoLocal.tm_min;
    //obtenemos sec
    sec = tiempoLocal.tm_sec;

    meses(1,0);


    //system("pause");
    //imprimimos
    printf("%d/%d/%d %d:%d",day,mont,year,hour,min);
    if(hour > 12) 
        printf("PM\n");
    else
        printf("AM\n");
}

#endif //FECHA_C