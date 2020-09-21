#ifndef Peliculas_H
#define Peliculas_H

#include "Videos.h"

class Peliculas: public Videos{
    public:
        Peliculas(double,string,int,string,string);
        string getname();
        void operator >>(double);
        void showcalygen(double,double,string);
        void showgenero(string);
        void showcal(double,double);
    private:
        double calificacion;
        string duracion;
};

Peliculas::Peliculas(double calificacion, string duracion, int ID, string nombre, string genero):Videos(ID, nombre, genero){
    this -> calificacion = calificacion;
    this -> duracion = duracion;
}

string Peliculas::getname(){
    return nombre;
}

void Peliculas::operator >>(double cal){
    calificacion = cal;
}

void Peliculas::showcalygen(double maxcali, double mincali, string gen){
    //cout << calificacion << genero;
    if (genero == gen){
        if (calificacion >= mincali && calificacion <= maxcali){
            cout << setw(8) << ID ;
            cout << setw(34) << nombre;
            cout << setw(10) << duracion;
            cout << setw(10) << genero;
            cout << setw(14) << calificacion << endl;
        }
    }
}

void Peliculas::showgenero(string gen){
    if (genero == gen){
        cout << setw(8) << ID ;
        cout << setw(34) << nombre;
        cout << setw(10) << duracion;
        cout << setw(10) << genero;
        cout << setw(14) << calificacion << endl;
    }
}

void Peliculas::showcal(double maxcali, double mincali){
    if (calificacion >= mincali && calificacion <= maxcali){
        cout << setw(8) << ID ;
        cout << setw(34) << nombre;
        cout << setw(10) << duracion;
        cout << setw(10) << genero;
        cout << setw(14) << calificacion << endl;
    }
}

#endif