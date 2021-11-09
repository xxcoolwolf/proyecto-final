#ifndef DIAS_DE_CADA_MES
#define DIAS_DE_CADA_MES

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"../estructuras.h"
#include"../prototipos.h"
#include"fecha.c"




int meses(int op,int mes){
    FILE *dias_meses;
    switch(op){
        case 1:
            if((dias_meses=fopen("../dias_meses.dat","w+b"))!=NULL){
                d_mes carga_mes;
                carga_mes.numero_mes=1;
                carga_mes.dias_mes=31;
                fwrite(&carga_mes,sizeof(carga_mes),1,dias_meses);

                carga_mes.numero_mes=2;
                if(year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)){
                    carga_mes.dias_mes=29;
                }else{
                    carga_mes.dias_mes=28;
                }
                fwrite(&carga_mes,sizeof(carga_mes),1,dias_meses);

                carga_mes.numero_mes=3;
                carga_mes.dias_mes=31;
                fwrite(&carga_mes,sizeof(carga_mes),1,dias_meses);

                carga_mes.numero_mes=4;
                carga_mes.dias_mes=30;
                fwrite(&carga_mes,sizeof(carga_mes),1,dias_meses);

                carga_mes.numero_mes=5;
                carga_mes.dias_mes=31;
                fwrite(&carga_mes,sizeof(carga_mes),1,dias_meses);

                carga_mes.numero_mes=6;
                carga_mes.dias_mes=30;
                fwrite(&carga_mes,sizeof(carga_mes),1,dias_meses);

                carga_mes.numero_mes=7;
                carga_mes.dias_mes=30;
                fwrite(&carga_mes,sizeof(carga_mes),1,dias_meses);

                carga_mes.numero_mes=8;
                carga_mes.dias_mes=31;
                fwrite(&carga_mes,sizeof(carga_mes),1,dias_meses);

                carga_mes.numero_mes=9;
                carga_mes.dias_mes=30;
                fwrite(&carga_mes,sizeof(carga_mes),1,dias_meses);

                carga_mes.numero_mes=10;
                carga_mes.dias_mes=31;
                fwrite(&carga_mes,sizeof(carga_mes),1,dias_meses);

                carga_mes.numero_mes=11;
                carga_mes.dias_mes=30;
                fwrite(&carga_mes,sizeof(carga_mes),1,dias_meses);

                carga_mes.numero_mes=12;
                carga_mes.dias_mes=31;
                fwrite(&carga_mes,sizeof(carga_mes),1,dias_meses);
                fclose(dias_meses);
            }
            return 0;
        break;
        case 2:
        if(mes>=1 && mes<=12){

            int dias_mes_seleccionado;
            if((dias_meses=fopen("../dias_meses.dat","r+b"))!=NULL){
                d_mes lectura_mes;
                printf("1NOOOOOO-----------\n");
                fread(&lectura_mes,sizeof(lectura_mes),1,dias_meses);
printf("2NOOOOOO-----------\n");
                while(!feof(dias_meses)){
                    printf("LLLectura_mes.numero_mes = %d\n",lectura_mes.numero_mes);

                    if(mes==lectura_mes.numero_mes){

                        printf("Mes = %d lectura_mes.numero_mes = %d\n",mes,lectura_mes.numero_mes);

                        dias_mes_seleccionado=lectura_mes.dias_mes;

                        printf("2Diaaaaa = %d\n",dias_mes_seleccionado);

                    }

                    fread(&lectura_mes,sizeof(lectura_mes),1,dias_meses);
                }
                fclose(dias_meses);
            }
            return dias_mes_seleccionado;
        }else{
            return -1;
        }
        break;
    }
    
}




#endif