#ifndef Videos_H
#define Videos_H

class Videos{
    public:
        Videos(int,string,string);
        virtual void showcalygen();
        virtual void showgenero();
        virtual void showcal();
    protected:
        int ID;
        string nombre;
        string genero;
};

Videos::Videos(int ID, string nombre, string genero){
    this -> ID = ID;
    this -> nombre = nombre;
    this -> genero = genero;
}

void Videos::showcalygen(){

}

void Videos::showgenero(){

}

void Videos::showcal(){
    
}

#endif