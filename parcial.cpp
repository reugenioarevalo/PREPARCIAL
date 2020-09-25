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
void vacio(int *v, int t){
    for(int i=0;i<t; i++){
        v[i] = 0;
    }
}
Rutina rutXidUs(int idUsuario){
      FILE *p;
    int posiciones=0;
    Rutina reg, err;

    p = fopen("archivos/Entrenamientos.dat", "rb");
        if(p==NULL){
            cout << "Error de archivo";
            return err ;
        }
    while(fread(&reg,sizeof (Rutina),1,p)==1){
            if(reg.idUsuario==idUsuario){
                return reg;
            }
    }

    fclose(p);
   return err;

}
///*Para cada perfil, indicar el promedio de peso.*/
void promPeso(){}

///*Listar apellidos y nombres del usuario que más tiempo en promedio haya entrenado.*/
void mayorTiempoEntrenado(){

    Rutina *vec;
    Rutina rutinaPorUs;
    int *tiemp;
   int  cant_user=0;
    int cant_rutinas=0;

    cant_rutinas=contarRutinas();

    tiemp = (int *) malloc(sizeof(int) * cant_rutinas);
    if (tiemp == NULL){ return;}


    vec = (Rutina *) malloc(sizeof(Rutina) * cant_rutinas);
    if (vec == NULL){ free(tiemp); return; }


   if(leer_rutina(vec, cant_rutinas) == cant_rutinas){
    for(int i=0; i< cant_rutinas; i++){
        if(vec[i].idUsuario != vec[i+1].idUsuario){
            cant_user++;
        }
    }
    vacio(tiemp, cant_user );
    for(int i=0; i< cant_user; i++){
            for(int j=0; j< cant_rutinas; j++){
                rutinaPorUs= rutXidUs(vec[i].idUsuario);
                if(vec[i].idUsuario==rutinaPorUs.idUsuario){
                    tiemp[i]+=rutinaPorUs.tiempo;
                }
            }
        cout<<tiemp[i]<<endl;
        }
    }

    else{
        cout<<"Hubo un error al reportar.";
    }
    anykey();
    free(tiemp);
    free(vec);
    return;
}

int leer_rutina(Rutina *vec, int cant){
    int c;
    FILE *p = fopen("archivos/Entrenamientos.dat", "rb");
    if (p == NULL){
        return 0;
    }
    c = fread(vec, sizeof(Rutina), cant, p);
    fclose(p);
    return c;
}
