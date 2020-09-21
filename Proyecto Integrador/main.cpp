#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iomanip>

using std::cout;
using std::cin;
using std::string;
using std::vector;
using std::ifstream;
using std::stringstream;
using std::endl;
using std::setw;
using std::getline;
using std::stoi;
using std::stod;

#include "Peliculas.h"
#include "Series.h"

int main(){
    int num, ID, temporadas;
    double calificacion;
    string nombre, genero, duracion;
    string line, valor;
    char delim = ',';
    int col, a;
    double max, min;
    vector<Peliculas*>ListaP;
    vector<Series*>ListaS;

    num = 10;

    while(num != 0){
        cout << "Bienvenido, eliga una de las siguientes opciones" << endl;
        cout << "1) Cargar Datos" << endl;
        cout << "2) Mostrar videos por genero y rango de calificacion" << endl;
        cout << "3) Mostrar videos de un genero" << endl;
        cout << "4) Mostrar episodios de una serie en un rango de calificacion" << endl;
        cout << "5) Mostrar peliculas con un rango de calificacion" << endl;
        cout << "6) Calificar un titulo" << endl;
        cout << "0) Salir" << endl;

        cin >> num;
        while(num < 0 || num > 6){
            cout << "Seleccione un valor valido. 0 a 6" << endl;
            cin >> num;
        }   

        if (num == 1){
            cout << endl << "Cargando datos..." << endl;
            ifstream pelicula("ProyectoIntegrador-Peliculas.csv");
            ifstream serie("ProyectoIntegrador-Series.csv");
            getline(serie,line);
            while (getline(serie,line)) {
                stringstream ss(line);
                col = 0;
                while (getline(ss,valor,delim)) {
                    switch (col) {
                        case 0: 
                            ID = stoi(valor);
                            break;
                        case 1: 
                            nombre = valor;
                            break;
                        case 2: 
                            genero = valor;
                            break;
                        case 3: 
                            temporadas = stoi(valor);
                            break;
                    }
                    col++;
                }
                ListaS.push_back(new Series(temporadas,ID,nombre,genero));
            }

            getline(pelicula,line);
            while (getline(pelicula,line)) {
                stringstream ss(line);
                col = 0;
                while (getline(ss,valor,delim)) {
                    switch (col) {
                        case 0: 
                            ID = stoi(valor);
                            break;
                        case 1: 
                            nombre = valor;
                            break;
                        case 2: 
                            duracion = valor;
                            break;
                        case 3: 
                            genero = valor;
                            break;
                        case 4:
                            calificacion = stod(valor);
                            break;
                    }
                    col++;
                }
                ListaP.push_back(new Peliculas(calificacion,duracion,ID,nombre,genero));
            }
            cout << endl << "Datos Cargados." << endl << endl;
        } else if (num == 2){
            cout << endl << "Rango de calificacion. 0 a 10" << endl;
            cout << "Mayor que:" << endl;
            cin >> min;
            while(min < 0 || min > 10){
                cout << "Seleccione un valor valido. 0 a 10" << endl;
                cin >> min;
            }

            cout << "Menor que:" << endl;
            cin >> max;
            while(max <= min || max > 10){
                cout << "Seleccione un valor valido. Mayor al valor minimo" << endl;
                cin >> max;
            }

            cout << endl << "Ahora escoja un genero" << endl;
            cout << "1) Drama" << endl;
            cout << "2) Accion" << endl;
            cout << "3) Misterio" << endl;
            cin >> a;
            while(a < 1 || a > 3){
                cout << "Seleccione un valor valido. 1 a 3" << endl;
                cin >> a;
            }
            
            if (a == 1){
                genero = "Drama";
            } else if (a == 2){
                genero = "Accion";
            } else if (a == 3){
                genero = "Misterio";
            }

            cout << endl << "-----Peliculas-----" << endl;
            cout << setw(8) << "ID";
            cout << setw(34) << "Nombre";
            cout << setw(10) << "Duracion";
            cout << setw(10) << "Genero";
            cout << setw(14) << "Calificacion" << endl;
            for(int i = 0; i < ListaP.size(); i++){
                ListaP[i] -> showcalygen(max,min,genero);
            }

            cout << endl << "-----Series-----" << endl;
            for(int i = 0; i < ListaS.size(); i++){
                ListaS[i] -> showcalygen(max,min,genero);
            }
        } else if (num == 3){
            cout << endl << "Escoja un genero" << endl;
            cout << "1) Drama" << endl;
            cout << "2) Accion" << endl;
            cout << "3) Misterio" << endl;
            cin >> a;
            while(a < 1 || a > 3){
                cout << "Seleccione un valor valido. 1 a 3" << endl;
                cin >> a;
            }
            if (a == 1){
                genero = "Drama";
            } else if (a == 2){
                genero = "Accion";
            } else if (a == 3){
                genero = "Misterio";
            }

            cout << endl << "-----Peliculas-----" << endl;
            cout << setw(8) << "ID";
            cout << setw(34) << "Nombre";
            cout << setw(10) << "Duracion";
            cout << setw(10) << "Genero";
            cout << setw(14) << "Calificacion" << endl;
            for(int i = 0; i < ListaP.size(); i++){
                ListaP[i] -> showgenero(genero);
            }

            cout << endl << "-----Series-----" << endl;
            for(int i = 0; i < ListaS.size(); i++){
                ListaS[i] -> showgenero(genero);
            }
        } else if (num == 4){
            cout << endl << "Elije una serie" << endl;
            cout << "-----Series-----" << endl;
            for(int i = 0; i < ListaS.size(); i++){
               cout << i+1 <<") " << ListaS[i] -> getnombre() << endl;
            }
            cout << endl;
            cin >> a;
            while(a < 1 || a > ListaS.size()){
                cout << "Seleccione un valor valido." << endl;
                cin >> a;
            }

            cout << endl << "Rango de calificacion. 0 a 10" << endl;
            cout << "Mayor que:" << endl;
            cin >> min;
            while(min < 0 || min > 10){
                cout << "Seleccione un valor valido. 0 a 10" << endl;
                cin >> min;
            }

            cout << "Menor que:" << endl;
            cin >> max;
            while(max <= min || max > 10){
                cout << "Seleccione un valor valido. Mayor al valor minimo" << endl;
                cin >> max;
            }

            ListaS[a-1] -> showcal(max,min);
        } else if (num == 5){
            cout << endl << "Rango de calificacion. 0 a 10" << endl;
            cout << "Mayor que:" << endl;
            cin >> min;
            while(min < 0 || min > 10){
                cout << "Seleccione un valor valido. 0 a 10" << endl;
                cin >> min;
            }

            cout << "Menor que:" << endl;
            cin >> max;
            while(max <= min || max > 10){
                cout << "Seleccione un valor valido. Mayor al valor minimo" << endl;
                cin >> max;
            }

            cout << endl << "-----Peliculas-----" << endl;
            cout << setw(8) << "ID";
            cout << setw(34) << "Nombre";
            cout << setw(10) << "Duracion";
            cout << setw(10) << "Genero";
            cout << setw(14) << "Calificacion" << endl;
            for(int i = 0; i < ListaP.size(); i++){
                ListaP[i] -> showcal(max,min);
            }
        } else if (num == 6){
            cout << endl << "Calificar Pelicula o Serie. 1/2" << endl;
            cin >> a;
            while (a < 1 || a > 2){
                cout << "Numero Invalido. 1 o 2" << endl;
                cin >> a;
            }
            
            if (a == 1){
                cout << endl << "Seleccione Pelicula" << endl;
                for(int i = 0; i < ListaP.size(); i++){
                    cout << i+1 <<") " << ListaP[i] -> getname() << endl;
                }
                cin >> a;
                while(a < 0 || a > ListaP.size()){
                    cout << "Numero Invalido" << endl;
                    cin >> a;
                }
                cout << "Seleccione calificacion. 0 a 10" << endl;
                double cal;
                cin >> cal;
                while(cal < 0 || cal > 10){
                    cout << "Numero Invalido" << endl;
                    cin >> cal;
                }
                *ListaP[a-1] >> cal;
            } else if (a == 2){
                cout << endl << "Seleccione Serie" << endl;
                for(int i = 0; i < ListaS.size(); i++){
                    cout << i+1 <<") " << ListaS[i] -> getnombre() << endl;
                }
                cin >> a;
                while(a < 0 || a > ListaS.size()){
                    cout << "Numero Invalido" << endl;
                    cin >> a;
                }
                ListaS[a-1] -> imprimirtitulo();
                cout << "Seleccione Episodio" << endl;
                int b;
                cin >> b;
                ListaS[a-1] -> calificar(b);
            }
        }
    }

    return 0;
}
