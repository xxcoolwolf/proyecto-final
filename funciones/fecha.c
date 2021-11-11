#ifndef FECHA_C
#define FECHA_C
//funciones
#include<stdio.h>
#include<stdlib.h>
#include<time.h>


//GLOBALES
int year,mont,day,hour,min,sec,inicio_dia_cobro = 1,fin_dia_cobro = 10;

void fecha(int centinela,int centinela2) {
    
    time_t fecha; //lo definimos tipo time_t
    fecha=time(NULL); //le asignamos NULL
    struct tm tiempoLocal = *localtime(&fecha); //obtenemos la hora del sistema en donde se ejecuta el codigo
    //obtenemos year
    if(centinela==1){
        year = tiempoLocal.tm_year+1900;
        //obtenemos mes
        mont = tiempoLocal.tm_mon+1;
        //obtenemos day
        day = tiempoLocal.tm_mday;
    }    //obtenemos hour
        hour = tiempoLocal.tm_hour;
    
    //obtenemos min
    min = tiempoLocal.tm_min;
    //obtenemos sec
    sec = tiempoLocal.tm_sec;
    // system("pause");
    //imprimimos
    if(centinela2==1){
        printf("%d/%d/%d %d:%d",day,mont,year,hour,min);
        if(hour > 12) 
            printf("PM\n");
        else
            printf("AM\n");
    }

}

#endif //FECHA_C