#ifndef Episodios_H
#define Episodios_H

class Episodios{
    public:
        Episodios(int,string,string,string,double,int);
        void imprimircal(double, double);
        void imprimir();
        void operator >>(double);
        string gettitulo();
    private:
        int SID;
        double Calificacion;
        int Temporada;
        string Name;
        string Duracion;
        string EID;
};

Episodios::Episodios(int SID, string EID, string Name, string Duracion, double Calificacion, int Temporada){
    this -> SID = SID;
    this -> EID = EID;
    this -> Name = Name;
    this -> Duracion = Duracion;
    this -> Calificacion = Calificacion;
    this -> Temporada = Temporada;
}

void Episodios::imprimircal(double maxcali, double mincali){
    if (Calificacion >= mincali && Calificacion <= maxcali){
        cout << setw(8) << SID;
        cout << setw(17) << EID;
        cout << setw(50) << Name;
        cout << setw(10) << Duracion;
        cout << setw(14) << Calificacion;
        cout << setw(11) << Temporada << endl;
    } else {
        NULL;
    }
}

void Episodios::imprimir(){
    cout << setw(8) << SID;
    cout << setw(17) << EID;
    cout << setw(50) << Name;
    cout << setw(10) << Duracion;
    cout << setw(14) << Calificacion;
    cout << setw(11) << Temporada << endl;
}

string Episodios::gettitulo(){
    return Name;
}

void Episodios::operator >>(double cal){
    Calificacion = cal;
}
#endif