#ifndef VERIFICADOR_VENCIMIENTO_CONTRATO_C
#define VERIFICADOR_VENCIMIENTO_CONTRATO_C

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"../estructuras.h"
#include"../prototipos.h"
#include"fecha.c"

void verificador_vencimiento_contrato(){
    int p_day,p_mont,p_year,finalizar=0,finalizar2 = 0,id_guardado,numero_contrato;
    char nombre_contratos[30] = {"clientes/id_contratos.dat"};

    FILE *a_contrato;
    if((a_contrato=fopen("clientes/contratos.dat","a+b"))!=NULL){
        contratos revision;
        while(finalizar==0){
                    //rewind(a_contrato);
                    fread(&revision,sizeof(revision),1,a_contrato);
                    while(!feof(a_contrato)){
                        finalizar=1;

                        if(revision.fecha_fin.day==day && revision.fecha_fin.mont==mont && revision.fecha_fin.year==year && revision.estado_contrato==1){
                            finalizar=0;
                            finalizar2=0;
                            printf("Finalizar = 0 id_cliente = %d\n",revision.id);
                            revision.estado_contrato=0;
                            id_guardado=revision.id_contrato;
                            printf("Id guardado = %d\n",id_guardado);

                            fseek(a_contrato,sizeof(revision)*(-1),SEEK_CUR);
                            fwrite(&revision,sizeof(revision),1,a_contrato);
                            fseek(a_contrato,sizeof(revision),SEEK_END);
                        }
                        fread(&revision,sizeof(revision),1,a_contrato);
                    }

                if(finalizar2==0){
                    finalizar = 1;
                    finalizar2 = 1;
                    numero_contrato=0;
                    contratos check;
                    rewind(a_contrato);
                    printf("1Entraaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa\n");
                    fread(&check,sizeof(check),1,a_contrato);
                    while(!feof(a_contrato)){
                        printf("2Entraaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa\n");

                        if(id_guardado==check.id_contrato){
                            printf("2Entraaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa id_c = %d id = %d\n",check.id_contrato,check.id);
                            fecha_diferenciador(year,mont,day,&p_year,&p_mont,&p_day,12);
                            check.fecha_fin.day=p_day;
                            check.fecha_fin.mont=p_mont;
                            check.fecha_fin.year=p_year;
                            printf("3Entraaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa\n");
                            generador_id(&numero_contrato,nombre_contratos);
                            check.id_contrato=numero_contrato;
                            printf("4Entraaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa\n");
                            fwrite(&check,sizeof(check),1,a_contrato);
                            fseek(a_contrato,sizeof(check),SEEK_END);
                            
                        }
                        fread(&check,sizeof(check),1,a_contrato);
                    }
                    printf("Estoy fuera del while\n");
                }

            system("pause");

        }
        fclose(a_contrato);
    }



printf("Sistem Final\n");
system("pause");
}


#endif