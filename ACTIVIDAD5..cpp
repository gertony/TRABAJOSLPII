#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Clase Vehiculo
class Vehiculo {
protected:
    string marca;
    string modelo;
    int año;
    string tipo_combustible;
    int capacidad_asientos;
public:
    Vehiculo(string _marca, string _modelo, int _año, string _tipo_combustible, int _capacidad_asientos) {
        marca = _marca;
        modelo = _modelo;
        año = _año;
        tipo_combustible = _tipo_combustible;
        capacidad_asientos = _capacidad_asientos;
    }
    virtual void mostrar_datos()=0;
};

// Clase Auto
class Auto : public Vehiculo {
private:
    int cantidad_puertas;
public:
    Auto(string _marca, string _modelo, int _año, string _tipo_combustible, int _cantidad_puertas, int _capacidad_asientos)
        : Vehiculo(_marca, _modelo, _año, _tipo_combustible, _capacidad_asientos) {
        cantidad_puertas = _cantidad_puertas;
    }
    void mostrar_datos() {
        cout << "Auto " << marca << " " << modelo << " (" << año << ")" << endl;
        cout << "Tipo de combustible: " << tipo_combustible << endl;
        cout << "Cantidad de puertas: " << cantidad_puertas << endl;
        cout << "Capacidad de asientos: " << capacidad_asientos << endl;
    }
};

// Clase Camioneta
class Camioneta : public Vehiculo {
private:
    int capacidad_carga;
public:
    Camioneta(string _marca, string _modelo, int _año, string _tipo_combustible, int _capacidad_carga, int _capacidad_asientos)
        : Vehiculo(_marca, _modelo, _año, _tipo_combustible, _capacidad_asientos) {
        capacidad_carga = _capacidad_carga;
    }
    void mostrar_datos() {
        cout << "Camioneta " << marca << " " << modelo << " (" << año << ")" << endl;
        cout << "Tipo de combustible: " << tipo_combustible << endl;
        cout << "Capacidad de carga: " << capacidad_carga << " kg" << endl;
        cout << "Capacidad de asientos: " << capacidad_asientos << endl;
    }
};

// Clase Camion
class Camion : public Vehiculo {
private:
    int capacidad_carga;
    int cantidad_ejes;
public:
    Camion(string _marca, string _modelo, int _año, string _tipo_combustible, int _capacidad_asientos, int _capacidad_carga, int _cantidad_ejes) : Vehiculo(_marca, _modelo, _año, _tipo_combustible, _capacidad_asientos) {
        capacidad_carga = _capacidad_carga;
        cantidad_ejes = _cantidad_ejes;
    }
    void mostrar_datos() {
        cout << "Camion " << marca << " " << modelo << " (" << año << ")" << endl;
        cout << "Tipo de combustible: " << tipo_combustible << endl;
        cout << "Capacidad de carga: " << capacidad_carga << " kg" <<endl;
        cout << "Capacidad de asientos: " << capacidad_asientos << endl;  
        cout << "Cantidad de ejes: " << cantidad_ejes << endl;
    }
};

// Función main
int main() {
    vector<Vehiculo*> flota;
    bool seguir = true;
    int opcion;

    while (seguir) {
        cout << "¿Qué desea hacer?" << endl;
        cout << "1. Agregar vehículo" << endl;
        cout << "2. Mostrar flota" << endl;
        cout << "3. Salir" << endl;
        cin >> opcion;

        switch(opcion) {
            case 1: {
                int tipo_vehiculo;
                string marca, modelo, tipo_combustible;
                int año, cantidad_puertas, capacidad_carga, cantidad_ejes, capacidad_asientos;  // Nuevo atributo
                cout << "¿Qué tipo de vehículo desea agregar?" << endl;
                cout << "1. Auto" << endl;
                cout << "2. Camioneta" << endl;
                cout << "3. Camión" << endl;
                cin >> tipo_vehiculo;

                cout << "Ingrese la marca: ";
                cin >> marca;
                cout << "Ingrese el modelo: ";
                cin >> modelo;
                cout << "Ingrese el año: ";
                cin >> año;
                cout << "Ingrese el tipo de combustible: ";
                cin >> tipo_combustible;
                cout << "Ingrese la capacidad de asientos: ";  // Nuevo atributo
                cin >> capacidad_asientos;

                switch(tipo_vehiculo) {
                    case 1: {
                        cout << "Ingrese la cantidad de puertas: ";
                        cin >> cantidad_puertas;
                        flota.push_back(new Auto(marca, modelo, año, tipo_combustible, capacidad_asientos, cantidad_puertas));
                        break;
                    }
                    case 2: {
                        cout << "Ingrese la capacidad de carga (en kg): ";
                        cin >> capacidad_carga;
                        flota.push_back(new Camioneta(marca, modelo, año, tipo_combustible, capacidad_asientos, capacidad_carga));
                        break;
                    }
                    case 3: {
                        cout << "Ingrese la capacidad de carga (en kg): ";
                        cin >> capacidad_carga;
                        cout << "Ingrese la cantidad de ejes: ";
                        cin >> cantidad_ejes;
                        flota.push_back(new Camion(marca, modelo, año, tipo_combustible, capacidad_asientos, capacidad_carga, cantidad_ejes));
                        break;
                    }
                    default: {
                        cout << "Opción inválida" << endl;
                        break;
                    }
                }
                break;
            }
            case 2: {
                if (flota.empty()) {
                    cout << "La flota está vacía" << endl;
                } else {
                    cout << "Flota de vehículos:" << endl;
                    for (auto vehiculo : flota) {
                        vehiculo->mostrar_datos();
                        cout << endl;
                    }
                }
                break;
            }
            case 3: {
                seguir = false;
                break;
            }
            default: {
                cout << "Opción inválida" << endl;
                break;
            }
        }
    }

    // Libera la memoria de los objetos Vehiculo creados
    for (auto vehiculo : flota) {
        delete vehiculo;
    }

    return 0;
}
