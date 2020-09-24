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

using namespace rlutil;
using namespace std;
const char *RUTINAS = "archivos/Entrenamientos.dat";

void promRutina(){
    FILE *p;
    Rutina reg, *vRutina;
    float prom;
    int cuantas, acuTime=0, cont;

    cuantas = contarRutinas();
    vRutina= (Rutina *)malloc(cuantas*sizeof(Rutina));
    if(vRutina == NULL){
            cout<<"\nERROR !!! no se pudo reservar memoria.";
            anykey();
            cls();
            return;
    }
    p= fopen(RUTINAS, "rb");
        if(p==NULL){
            cout<<"Error al leer el archivo. ";
            return;
       }

        fread(vRutina, sizeof(Rutina), cuantas, p);
        fclose(p);


        for(int i =0 ; i<cuantas; i++){
            acuTime +=vRutina[i].tiempo;
        }

        prom= ((float)acuTime/(float)cuantas);
        cout<<"\nEl Tiempo promedio es:"<<prom;

        for(int i= 0 ; i<cuantas; i++){
            if( vRutina[i].tiempo > prom){
                mostrarRutina(vRutina[i]);
            }
        }

        free(vRutina);
		anykey();

}

