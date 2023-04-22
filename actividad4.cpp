#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Producto{
    private:
        string name;
        float price;
        int id;
        int cant;

    public:
        Producto(string name, float price, int id, int cant){
            this -> name = name;
            this -> price = price;
            this -> id = id;
            this -> cant = cant;
        }

        string getName() {return name;}
        float getPrice() {return price;}
        int getId() {return id;}
        int getCant() {return cant;}
        void setCant(int _cant) {cant = _cant;}
};

class Almacen{
    private:
       vector<Producto*> productos;
    public:


    void addProducto(Producto* producto){
        productos.push_back(producto);
    }
    void mostrar(){
        cout<<" LISTA DE PRODUCTOS EN ALMACEN: "<<endl;
        for(int i = 0; i< productos.size() ; i++){
            cout<<" Poducto #"<<i<<endl;
            cout<<" - Nombre: "<<productos[i]->getName()<<endl;
            cout<<" - Precio: "<<productos[i]->getPrice()<<endl;
            cout<<" - Cantidad: "<<productos[i]->getCant()<<endl;
            cout<<" - ID: "<<productos[i]->getId()<<endl;

        }
    }
    vector<Producto*> getProductos(){return productos;}
    void buy(Producto* producto){
        int aux;
        cout<<"Que cantidad de "<<producto->getName()<<" desea adquirir?"<<endl;
        cin>>aux;
        if (aux > producto->getCant()){
            cout<<"Error: No hay suficiente cantidad."<<endl;
        }else{
        producto->setCant(producto->getCant()-aux);
        cout<<"Compra hecha"<<endl;}
    }
};


int main(){

    Producto* p1 = new Producto("Leche",  4, 1, 10);
    Producto* p2 = new Producto("Azucar",  3, 2, 7);
    Producto* p3 = new Producto("Huevos",  1, 3, 15);

    Almacen a1;
    a1.addProducto(p1);
    a1.addProducto(p2);
    a1.addProducto(p3);

    int opcion = 0;
    while(opcion != 4){
        cout << "==== MENU DE COMPRA ====" << endl;
        cout << "1. Mostrar lista de productos" << endl;
        cout << "2. Comprar producto" << endl;
        cout << "3. Salir" << endl;
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch(opcion){
            case 1:
                a1.mostrar();
                break;
            case 2:
                int idProducto;
                cout << "Ingrese el ID del producto que desea comprar: ";
                cin >> idProducto;
                for(int i = 0; i < a1.getProductos().size(); i++){
                    if(a1.getProductos()[i]->getId() == idProducto){
                        a1.buy(a1.getProductos()[i]);
                        break;
                    }
                    if(i == a1.getProductos().size()-1){
                        cout << "No se encontró ningún producto con ese ID." << endl;
                    }
                }
                break;
            case 3:
                cout << "Saliendo del programa..." << endl;
                break;
            default:
                cout << "Opción no válida. Intente de nuevo." << endl;
        }
    }
    return 0;
}
