#ifndef FECHA_DIFERENCIADOR_C
#define FECHA_DIFERENCIADOR_C
//funciones
#include<stdio.h>
#include<stdlib.h>

// diferenciador de fechas
/*
by Sciangula Hugo 67377
detalles: en esta funcion, lo que se hace es obtener la diferencia que hay entre una fecha y otra, con un lapso de meses que nosotros definamos
*/
void fecha_diferenciador(int year, int mont, int day, int *year_ouput, int *mont_ouput, int *day_ouput, int lapso) {
    //empezamos nuestro sistema de diferenciacion
    *day_ouput = day;
    *year_ouput = year;
    *mont_ouput = mont + lapso;
    if(*mont_ouput > 12) {
        //significa que superamso el year
        *mont_ouput = mont - lapso;
        //ahora incrementamos el year
        *year_ouput = year + 1;
        *day_ouput = day;
        //--------------------------------- NOTA
        //hacer la parte de verificacion de dias, si me inscribo el 30 de agosto, y tengo un lapso de 6 meses, tendria, que terminar el 30 de febrero, pero no existe esa fecha, entonces hay que cobrarle el 2 del marzo......
    }
}

#endif //FECHA_DIFERENCIADOR_C