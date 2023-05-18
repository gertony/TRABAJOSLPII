#include <iostream>
#include <string>

using namespace std;

class MaterialBiblio{

    private:
        string titulo;
        string autor;
        string editorial;
        int codigoBarras;
    public:
        MaterialBiblio(string titulo, string autor, string editorial, int codigoBarras){
            this -> titulo = titulo;
            this -> autor = autor;
            this -> editorial = editorial;
            this -> codigoBarras = codigoBarras;
        }
        
        ~MaterialBiblio(){
            cout << "Ejecutando destructor padre..." << endl;
        }

    protected:
        void mostrarInfo(){
            cout << "-------------------" << endl;
            cout << "Titulo: " << titulo << endl;
            cout << "Autor: " << autor << endl;
            cout << "Editorial: " << editorial << endl;
            cout << "codigoBarras: " << codigoBarras << endl;
        
        }

};

class Libro : protected MaterialBiblio{
    private:
        string genero;
        int isbn;
    public:
        Libro(string titulo, string autor, string editorial, int codigoBarras, string genero, int isbn) : MaterialBiblio(titulo, autor, editorial, codigoBarras) {
            this->genero = genero;
            this->isbn = isbn;
}

        void mostrarInfo(){
            MaterialBiblio::mostrarInfo();

            cout << "Genero: " << genero << endl;
            cout << "ISBN: " << isbn << endl;
            cout << "-------------------" << endl;

        }

        ~Libro(){
            cout << "Ejecutando destructor Libro..." << endl;
        }
};

class Revista : protected MaterialBiblio{
    private:
        int nEdicion;
    public:
        Revista(string titulo, string autor, string editorial, int codigoBarras, int nEdicion) : MaterialBiblio(titulo, autor, editorial, codigoBarras){
            this -> nEdicion = nEdicion;
        }

        void mostrarInfo(){
            MaterialBiblio::mostrarInfo();

            cout << "Edicion: " << nEdicion << endl;
            cout << "-------------------" << endl;

        }

        ~Revista(){
            cout << "Ejecutando destructor Revista..." << endl;
        }
};

class Tesis : protected MaterialBiblio{
    private:
        string universidad;
        string asesor;
    public:
        Tesis(string titulo, string autor, string editorial, int codigoBarras, string universidad, string asesor) : MaterialBiblio(titulo, autor, editorial, codigoBarras){
            this -> universidad = universidad;
            this -> asesor = asesor;
        }

        void mostrarInfo(){
            MaterialBiblio::mostrarInfo();

            cout << "Universidad: " << universidad << endl;
            cout << "Asesor: " << asesor << endl;
            cout << "-------------------" << endl;

        }

        ~Tesis(){
            cout << "Ejecutando destructor Tesis..." << endl;
        }
};

class Comic : protected MaterialBiblio{
    private:
        string dibujante;
    public:
        Comic(string titulo, string autor, string editorial, int codigoBarras, string dibujante) : MaterialBiblio(titulo, autor, editorial, codigoBarras){
            this -> dibujante = dibujante;
        }

        void mostrarInfo(){
            MaterialBiblio::mostrarInfo();

            cout << "Dibujante Principal: " << dibujante << endl;
            cout << "-------------------" << endl;
            

        }

        ~Comic(){
            cout << "Ejecutando destructor Comic..." << endl;
        }
};


int main(){

    Libro l1("Libro 1", "Autor 1", "Editorial 1", 000001, "Genero 1", 1010101);
    Revista r1("Revista 1", "Autor 2", "Editorial 2", 000021, 1);
    Tesis t1("Tesis 1", "Autor 3", "Editorial 3", 011021, "UCSM", "ING MONTESINOS");
    Comic c1("Comic 1", "Autor 4", "Editorial 4", 0022321, "Dibujante 1");

    l1.mostrarInfo();
    r1.mostrarInfo();
    t1.mostrarInfo();
    c1.mostrarInfo();

    l1.~Libro();
    r1.~Revista();
    t1.~Tesis();
    c1.~Comic();
    return 0;

}
