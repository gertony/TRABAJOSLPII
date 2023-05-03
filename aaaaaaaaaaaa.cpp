
#include <iostream>
#include<string>
using namespace std;

class Cirugia;

class Cajero{
  public:
    string nombre = "";
    void consultarCosto(Cirugia &o);
    void cambiarCosto(Cirugia &o, int n);
    void consultarIntervencion(Cirugia &o);
    void cambiarIntervencion(Cirugia &o, string in);
    Cajero();
};

class Cirugia{
    private:
        string interverncion;
        int costo;
    protected:
        float cirujano;
    public:
    friend void consultarCosto(Cirugia &);
    friend void cambiarCosto(Cirugia &, int n);
    friend void consultarIntervencion(Cirugia &);
    friend void cambiarIntervencion(Cirugia&, string a);
    int getCosto(){
        return costo;
    }
    void setCosto(int co){
        costo = co;
    }
    string getIntervencion(){return interverncion;}
    void setIntervencion(int in){
        interverncion = in;
    }
        Cirugia();
};

void Cajero::consultarCosto(Cirugia &o){
    cout<<"Costo Cirugia: "<<o.getCosto();
}
void Cajero::cambiarCosto(Cirugia &o, int n){
    o.setCosto(n);
}
void Cajero::consultarIntervencion(Cirugia &o){
    cout<<"Interverncion: "<<o.getIntervencion();
}
void Cajero::cambiarIntervencion(Cirugia &o, string a){
    o.setIntervencion(a);
}
Cirugia::Cirugia(){
    interverncion = "";
    costo = 0;
    cirujano = "";
}
int main()
{
    Cirugia c1;
    Cajero caj;
    caj.cambiarIntervencion("Brazo");
    caj.cambiarCosto(100);
    caj.consultarIntervencion();
    caj.consultarCosto();
    


    return 0;
}
