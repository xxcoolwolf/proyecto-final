#ifndef VERIFICADOR_VENCIMIENTO_CONTRATO_OLD_C
#define VERIFICADOR_VENCIMIENTO_CONTRATO_OLD_C

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"../estructuras.h"
#include"../prototipos.h"
#include"fecha.c"

void verificador_vencimiento_contrato(){
    int p_day,p_mont,p_year,finalizar=0;

    FILE *a_contrato;
    if((a_contrato=fopen("clientes/contratos.dat","r+b"))!=NULL){
        // printf("1Entraaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa\n");
        contratos revision;
        while(finalizar==0){
                    rewind(a_contrato);
                    // printf("2Entraaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa\n");
                    fread(&revision,sizeof(revision),1,a_contrato);
                    while(!feof(a_contrato)){
                        finalizar=1;
                        // printf("3Entraaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa id = %d\n",revision.id);

                        if(revision.fecha_fin.day==day && revision.fecha_fin.mont==mont && revision.fecha_fin.year==year && revision.estado_contrato==1){
                            finalizar=0;
                            // printf("4Entraaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa\n");
                            fecha_diferenciador(year,mont,day,&p_year,&p_mont,&p_day,12);
                            revision.fecha_fin.day=p_day;
                            revision.fecha_fin.mont=p_mont;
                            revision.fecha_fin.year=p_year;

                            fseek(a_contrato,sizeof(revision)*(-1),SEEK_CUR);
                            fwrite(&revision,sizeof(revision),1,a_contrato);
                            fseek(a_contrato,sizeof(revision),SEEK_END);
                        }
// printf("3,1Entraaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa\n");
                        fread(&revision,sizeof(revision),1,a_contrato);
                    }
                    // printf("5Entraaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa\n");
        }
        fclose(a_contrato);
        // printf("200Entraaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa\n");
    }





}


#endif