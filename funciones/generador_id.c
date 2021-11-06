#ifndef GENERADOR_ID
#define GENERADOR_ID

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"../estructuras.h"
#include"../prototipos.h"

//generador id
/*
by Sciangula Hugo v1 26/10/21
detalles: se crea por primera vez un id de cliente el cual nunca va a ser modificado, para ello, en un archivo binario, se procede a escribir por primera vez un 0, y una vez creado, se procede solo a leerlo, y ir incrementandolo de forma continia 1 a 1.
*/
void generador_id(int *id_generado,char *nombre_archivo) {
  FILE *generacion_id;
  //declaramos centinela para la primera vez que se vaya a crear el archivo
  int contador_id = 0,centinela = 0;
  //toda esta parte, seria la encargada de ir incrementandolo
  if((generacion_id = fopen(nombre_archivo,"r+b")) != NULL) {
    fread(&contador_id,sizeof(int),1,generacion_id);
    contador_id++;
    *id_generado = contador_id;
    rewind(generacion_id);
    fwrite(&contador_id,sizeof(int),1,generacion_id);
    //cerramos el archivo
    fclose(generacion_id);
  }
  else
  {
    //esta parte seria la encargada de crear el archivo por primera vez, y luego activar un centinela para asi poder generar un id de forma correcta para el primer cliente
      if((generacion_id = fopen(nombre_archivo,"wb")) != NULL) {
		  fwrite(&contador_id,sizeof(int),1,generacion_id);
          centinela = 1;
          //cerramos el archivo
          fclose(generacion_id);
      }
  }
  //esto solo se ejecutaria una vez, luego de que se haya creado el archibo binario con el acumulador de id, una vez creado ya no se volveria a ejecutar, porque el primer if que se ejecuta en esta funcion, es la encarga de hacer el incremento del id
  if(centinela == 1) {
    if((generacion_id = fopen(nombre_archivo,"r+b")) != NULL) {
      fread(&contador_id,sizeof(int),1,generacion_id);
      contador_id++;
      *id_generado = contador_id;
	    rewind(generacion_id);
      fwrite(&contador_id,sizeof(int),1,generacion_id);
      //cerramos el archivo
      fclose(generacion_id);
    }
  }
}

#endif //GENERADOR_ID
