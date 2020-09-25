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
Rutina rutXidUs(int id){
      FILE *p;
    int posiciones=0;
    Rutina reg, err;

    p = fopen("archivos/Entrenamientos.dat", "rb");
        if(p==NULL){
            cout << "Error de archivo";
            return err ;
        }
    while(fread(&reg,sizeof (Rutina),1,p)==1){
            if(reg.id==id){
                return reg;
            }
    }

    fclose(p);
   return err;

}
///*Para cada perfil, indicar el promedio de peso.*/
void promPeso(){
    Usuario regAux, reg;
    float pesoA=0, pesoB=0, pesoC=0;
    int contA=0, contB=0, contC=0, cantU;
    cantU=contarRegistro();
    cout<<cantU<<endl;
    for(int i=0; i< cantU; i++){
        regAux = leerUsuario(i);
        switch(regAux.perfAct){
            case 'A': pesoA +=regAux.peso; contA++;break;
            case 'B': pesoB +=regAux.peso; contB++; break;
            case 'C': pesoC +=regAux.peso; contC++;break;
            default: break;
        }

    }
       cout<<"PARA EL PERFIL A EL PESO PROMEDIO ES: "<<pesoA/contA<<" KG."<<endl;       cout<<"PARA EL PERFIL B EL PESO PROMEDIO ES: "<<pesoB/contB<<" KG."<<endl;       cout<<"PARA EL PERFIL C EL PESO PROMEDIO ES: "<<pesoC/contC<<" KG."<<endl;
    anykey();
}

///*Listar apellidos y nombres del usuario que más tiempo en promedio haya entrenado.*/
void mayorTiempoEntrenado(){

    Rutina *vec;
    Rutina rutinaPorUs;
    float promMax=0;
    float prom=0;
    int *tiemp;
   int  cant_user=0, us=0;
    int cant_rutinas=0, cant_userU, cuantos=0;
    cant_userU=contarRegistro();
    int vecUs[cant_userU], vecCuanto[cant_userU]={0};
    cant_rutinas=contarRutinas();

    tiemp = (int *) malloc(sizeof(int) * cant_rutinas);
    if (tiemp == NULL){ return;}


    vec = (Rutina *) malloc(sizeof(Rutina) * cant_rutinas);
    if (vec == NULL){ free(tiemp); return; }


   if(leer_rutina(vec, cant_rutinas) == cant_rutinas){
    for(int i=0; i< cant_rutinas; i++){
        if(vec[i].idUsuario != vec[i+1].idUsuario){
             vecUs[cant_user]=vec[i].idUsuario;
            cant_user++;
        }
    }

    vacio(tiemp, cant_user );
            for(int i=0; i< cant_user; i++){
                for(int j=0; j<= cant_rutinas; j++){
                rutinaPorUs= rutXidUs(vec[j].id);
                if(vecUs[i]==rutinaPorUs.idUsuario ){
                    tiemp[i]=tiemp[i]+rutinaPorUs.tiempo;
                    vecCuanto[i]++;
                }
            }

        }
        for(int i=0; i<cant_user; i++){
            prom =(float)tiemp[i]/vecCuanto[i];
            if(promMax==0 || prom>promMax){
                promMax=prom;
                us=vecUs[i];
            }
            prom=0;
        }
                cout<<" El Promedio Max es "<<promMax<<" corresponde al usuario  "<<us<<" " <<endl;
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
