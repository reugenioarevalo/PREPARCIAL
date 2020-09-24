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

void listarRutinaIdxAnio(){
    FILE *p;
    Rutina regRut;
    Usuario regUs;
    int idUsuario, anio, cantidad;
    title("LISTADO POR ID Y POR ANIO ");
    gotoxy(1,3);

    cout<<"\nIngrese el ID  de usuario a listar:";
    cin>>idUsuario;
    cout<<"\nIngrese el anio de rutina a listar:";
    cin>>anio;

    regUs= leerUsuario(buscarID(idUsuario));
    cantidad=cantRutinasUsuario(idUsuario, anio);
    cls();
    title("LISTADO POR ID Y POR ANIO ");
    gotoxy(1,3);
    cout<<regUs.apellidos<<" "<<regUs.nombres;
    cout<<" tiene: "<<cantidad<<" Rutinas en el anio: "<<anio<<endl;
    anykey();


}
