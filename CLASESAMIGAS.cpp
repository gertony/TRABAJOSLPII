#include <iostream>
#include <string>
using namespace std;

class Cuentas;
class CajeroAmigo{
    public:
        string nomb_cajero;
        int codigo;
        void accedersaldo(Cuentas &c);
        CajeroAmigo();
};

class Cuentas{
  public:
    friend void CajeroAmigo::accedersaldo(Cuentas &);
    int nro_cuenta;
    float saldo;
    string pass_web;
    string pass_cajeros;
    
    Cuentas();
};

void CajeroAmigo::accedersaldo(Cuentas &c){
    cout<<"El saldo es: "<<c.saldo;
}
Cuentas::Cuentas(){
    nro_cuenta = 0;
    saldo = 2000;
    pass_web = "123";
    pass_cajeros = "123";
}

CajeroAmigo::CajeroAmigo(){
    codigo = 0;
    nomb_cajero = "no name";
}
int main()
{
    Cuentas c01;
    c01.nro_cuenta = 2;
    c01.saldo = 2000;
    c01.pass_web = "321";
    c01.pass_cajeros = "321";
    
    CajeroAmigo cajB;
    cajB.accedersaldo(c01);
    return 0;
}
