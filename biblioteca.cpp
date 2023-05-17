#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Libro;

class Usuario {
public:
    void consultarDisponibilidad(const Libro& libro);

    friend class Biblioteca;
};

class Libro {
private:
    string titulo;
    string autor;
    bool disponible;

public:
    Libro(const string& titulo, const string& autor) : titulo(titulo), autor(autor), disponible(true) {}

    friend class Biblioteca;
    friend ostream& operator<<(ostream& os, const Libro& libro);
    friend bool operator==(const Libro& libro1, const Libro& libro2);
    friend void Usuario::consultarDisponibilidad(const Libro& libro);

    string getTitulo() const {
        return titulo;
    }

    bool isDisponible() const {
        return disponible;
    }

    void setDisponible(bool value) {
        disponible = value;
    }
};

ostream& operator<<(ostream& os, const Libro& libro) {
    os << "Título: " << libro.titulo << ", Autor: " << libro.autor;
    if (libro.disponible) {
        os << " (Disponible)";
    } else {
        os << " (Prestado)";
    }
    return os;
}

bool operator==(const Libro& libro1, const Libro& libro2) {
    return libro1.titulo == libro2.titulo && libro1.autor == libro2.autor;
}

class Biblioteca {
private:
    vector<Libro> libros;

public:
    void prestarLibro(Libro& libro) {
        if (libro.disponible) {
            libro.disponible = false;
            cout << "Se ha prestado el libro '" << libro.titulo << "'." << endl;
        } else {
            cout << "El libro '" << libro.titulo << "' no está disponible para préstamo." << endl;
        }
    }

    void devolverLibro(Libro& libro) {
        if (!libro.disponible) {
            libro.disponible = true;
            cout << "Se ha devuelto el libro '" << libro.titulo << "'." << endl;
        } else {
            cout << "El libro '" << libro.titulo << "' no ha sido prestado." << endl;
        }
    }

    void mostrarLibros() {
        cout << "Lista de libros:" << endl;
        for (const Libro& libro : libros) {
            cout << libro << endl;
        }
    }

    void agregarLibro(const Libro& libro) {
        libros.push_back(libro);
    }
    
    vector<Libro> buscarPorAutor(const string& autor) const {
        vector<Libro> resultados;

        for (const Libro& libro : libros) {
            if (libro.autor == autor) {
            resultados.push_back(libro);
            }
        }

        return resultados;
    }

    void imprimirResultadosAutor(const vector<Libro>& resultados) const {
    cout << "Libros encontrados para el autor:" << endl;
    for (const Libro& libro : resultados) {
        cout << libro << endl;
    }
}

    friend Usuario;
};

void Usuario::consultarDisponibilidad(const Libro& libro) {
    cout << "El libro '" << libro.titulo << "' está ";
    if (libro.disponible) {
        cout << "disponible." << endl;
    } else {
        cout << "prestado." << endl;
    }
}

int main() {
    Biblioteca biblioteca;

    Libro libro1("Harry Potter", "J.K. Rowling");
    Libro libro2("1984", "George Orwell");

    biblioteca.agregarLibro(libro1);
    biblioteca.agregarLibro(libro2);

    biblioteca.mostrarLibros();

    Usuario usuario;
    usuario.consultarDisponibilidad(libro1);

    biblioteca.prestarLibro(libro1);
    usuario.consultarDisponibilidad(libro1);
    biblioteca.devolverLibro(libro1);
    usuario.consultarDisponibilidad(libro1);
    string autorBusqueda = "George Orwell";
    vector<Libro> librosAutor = biblioteca.buscarPorAutor(autorBusqueda);
    biblioteca.imprimirResultadosAutor(librosAutor);

return 0;
}
