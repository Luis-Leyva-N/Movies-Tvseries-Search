#ifndef Series_H
#define Series_H

#include "Videos.h"
#include "Episodios.h"

class Series: public Videos{
    public:
        Series(int,int,string,string);
        string getnombre();
        void calificar(int);
        void showcalygen(double,double,string);
        void showgenero(string);
        void showcal(double,double);
        void imprimirtitulo();
    private:
        int temporadas;
        vector<Episodios*>ListaE;
};

Series::Series(int temporadas, int ID, string nombre, string genero):Videos(ID, nombre, genero){
    this -> temporadas = temporadas;

    int SID;
    double Calificacion;
    int Temporada;
    string EID, name, Duracion;
    string line, valor;
    char delim = ',';
    int col;

    ifstream episodio("ProyectoIntegrador-Episodios.csv");
    getline(episodio,line);
            while (getline(episodio,line)) {
                stringstream ss(line);
                col = 0;
                while (getline(ss,valor,delim)) {
                    switch (col) {
                        case 0: 
                            SID = stoi(valor);
                            break;
                        case 1: 
                            EID = valor;
                            break;
                        case 2: 
                            name = valor;
                            break;
                        case 3: 
                            Duracion = valor;
                            break;
                        case 4:
                            Calificacion = stod(valor);
                            break;
                        case 5:
                            Temporada = stoi(valor);
                            break;
                    }
                    col++;
                }
                if (SID == ID){
                    ListaE.push_back(new Episodios(SID,EID,name,Duracion,Calificacion,Temporada));
                }
                
            }
}

string Series::getnombre(){
    return nombre;
}

void Series::showcalygen(double maxcali, double mincali, string gen){
    if (genero == gen){
            cout << setw(8) << "ID";
            cout << setw(18) << "Nombre";
            cout << setw(10) << "Genero";
            cout << setw(12) << "Temporadas" << endl;
            cout << setw(8) << ID;
            cout << setw(18) << nombre;
            cout << setw(10) << genero;
            cout << setw(12) << temporadas << endl;
            cout << "-----Episodios-----" << endl;
            cout << setw(8) << "ID Serie";
            cout << setw(17) << "ID Episodio";
            cout << setw(50) << "Nombre";
            cout << setw(10) << "Duracion";
            cout << setw(14) << "Calificacion";
            cout << setw(11) << "Temporada" << endl;

            for(int i = 0; i < ListaE.size(); i++){
                ListaE[i] -> imprimircal(maxcali, mincali);
            }
            cout << endl;
    }
}

void Series::showgenero(string gen){
    if (genero == gen){
        cout << setw(8) << "ID";
        cout << setw(18) << "Nombre";
        cout << setw(10) << "Genero";
        cout << setw(12) << "Temporadas" << endl;
        cout << setw(8) << ID;
        cout << setw(18) << nombre;
        cout << setw(10) << genero;
        cout << setw(12) << temporadas << endl;
        cout << "-----Episodios-----" << endl;
        cout << setw(8) << "ID Serie";
        cout << setw(17) << "ID Episodio";
        cout << setw(50) << "Nombre";
        cout << setw(10) << "Duracion";
        cout << setw(14) << "Calificacion";
        cout << setw(11) << "Temporada" << endl;

        for(int i = 0; i < ListaE.size(); i++){
            ListaE[i] -> imprimir();
        }
        cout << endl;
    }
}

void Series::showcal(double maxcali, double mincali){
    cout << setw(8) << "ID";
    cout << setw(18) << "Nombre";
    cout << setw(10) << "Genero";
    cout << setw(12) << "Temporadas" << endl;
    cout << setw(8) << ID;
    cout << setw(18) << nombre;
    cout << setw(10) << genero;
    cout << setw(12) << temporadas << endl;
    cout << "-----Episodios-----" << endl;
    cout << setw(8) << "ID Serie";
    cout << setw(17) << "ID Episodio";
    cout << setw(50) << "Nombre";
    cout << setw(10) << "Duracion";
    cout << setw(14) << "Calificacion";
    cout << setw(11) << "Temporada" << endl;

    for(int i = 0; i < ListaE.size(); i++){
        ListaE[i] -> imprimircal(maxcali, mincali);
    }
        cout << endl;
}

void Series::imprimirtitulo(){
    for(int i = 0; i < ListaE.size(); i++){
        cout << i+1 << ") " << ListaE[i] -> gettitulo() << endl;
    }
}

void Series::calificar(int a){
    cout << "Seleccione calificacion. 0 a 10" << endl;
    double cal;
    cin >> cal;
    while(cal < 0|| cal > 10){
        cout << "Seleccione un valor valido. 0 a 10" << endl;
        cin >> cal;
    }
    *ListaE[a-1] >> cal;
}

#endif