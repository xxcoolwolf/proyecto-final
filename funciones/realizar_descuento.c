#ifndef DESCUENTO_C
#define DESCUENTO_C

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"../estructuras.h"
#include"../prototipos.h"

float realizar_descuento(float total){
    float descuento;
	if(total >= 3000 && total <= 4000) {
        //descuento del 20%
        descuento =total * 0.2;
    } 
    else 
    {
        if(total >= 4001 && total <= 6000) {
            //decuento del 25%
            descuento = total * 0.25;
        }
        else
        {
            if(total > 6000) {
                //descuento del 30%
                descuento = total * 0.3;
            }else{
                descuento=0;
            }
        }
    } 
	return descuento;
}

#endif