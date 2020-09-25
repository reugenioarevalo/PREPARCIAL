#include <iostream>
#include <cstdio>
#include <stdlib.h>
#include <ctime>
#include <string.h>
#include <cstring>
#include <cctype>
#include <algorithm>
#include "rutinas.h"
#include "usuarios.h"
#include "menus.h"
#include "fechas.h"
#include "ui.h"
#include "rlutil.h"
#include "reportes.h"
#include "preparcial.h"
#include "parcial.h"

using namespace rlutil;
using namespace std;
const char *RUTINAS = "archivos/Entrenamientos.dat";

///*Para cada perfil, indicar el promedio de peso.*/
void promPeso(){}

///*Listar apellidos y nombres del usuario que más tiempo en promedio haya entrenado.*/
void mayorTiempoEntrenado(){
//   FILE *p;
//    Rutina reg;
    Rutina *vec;
    int *tiemp;
   int  cant_user=0;
    int cant_rutinas=0;
 //  int cantRutXUsuario=1;
    cant_rutinas=contarRutinas();

    tiemp = (int *) malloc(sizeof(int) * cant_rutinas);
    if (tiemp == NULL){return;}

    vec = (Rutina *) malloc(sizeof(Rutina) * cant_rutinas);
    if (vec == NULL){ free(tiemp); return; }
//
//    p=fopen(RUTINAS,"rb");
//    if(p==NULL){
//            return  ;
//    }
//    fread(&reg,sizeof(Rutina),1,p);
//    fclose(p);


   if(leer_rutina(vec, cant_rutinas) == cant_rutinas){

    for(int i=0; cant_rutinas; i++){
        if(vec[i].idUsuario != vec[i+1].idUsuario){
            cant_user++;
        }
    }
    cout<<cant_user;
    }else{
        cout<<"Hubo un error al reportar.";
    }

    free(tiemp);
    free(vec);
    return;
}

int leer_rutina(Rutina *vec, int cant){
    int c;
    FILE *p = fopen(RUTINAS, "rb");
    if (p == NULL){
        return 0;
    }
    c = fread(vec, sizeof(Rutina), cant, p);
    fclose(p);
    return c;
}

/**
float *kgs;
    Participante *vec;
    int cant_participantes = cantidad_participantes();
    kgs = (float *) malloc(sizeof(float) * cant_participantes);
    if (kgs == NULL){
        return;
    }
    vec = (Participante *) malloc(sizeof(Participante) * cant_participantes);
    if (vec == NULL){
        free(kgs);
        return;
    }
    poner0(kgs, cant_participantes);
    */
