#ifndef LISTA_SENSOR_H
#define LISTA_SENSOR_H

#include <iostream>

/**
 * @brief Nodo generico para la lista enlazada
 */
template <typename T>
struct Nodo {
    T dato;
    Nodo<T>* siguiente;
    
    Nodo(T valor) : dato(valor), siguiente(nullptr) {}
};

/**
 * @brief Lista enlazada simple generica para almacenar lecturas
 */
template <typename T>
class ListaSensor {
private:
    Nodo<T>* cabeza;
    int cantidad;

public:
    ListaSensor() : cabeza(nullptr), cantidad(0) {}
    
    ~ListaSensor() {
        Nodo<T>* actual = cabeza;
        while (actual != nullptr) {
            Nodo<T>* siguiente = actual->siguiente;
            std::cout << "  [Log] Liberando nodo con valor: " << actual->dato << std::endl;
            delete actual;
            actual = siguiente;
        }
    }
    
    /**
     * @brief Inserta un valor al final de la lista
     */
    void insertar(T valor) {
        Nodo<T>* nuevo = new Nodo<T>(valor);
        
        if (cabeza == nullptr) {
            cabeza = nuevo;
        } else {
            Nodo<T>* actual = cabeza;
            while (actual->siguiente != nullptr) {
                actual = actual->siguiente;
            }
            actual->siguiente = nuevo;
        }
        cantidad++;
        std::cout << "[Log] Insertando valor: " << valor << std::endl;
    }
    
    /**
     * @brief Calcula el promedio de los valores
     */
    double calcularPromedio() {
        if (cantidad == 0) return 0.0;
        
        double suma = 0;
        Nodo<T>* actual = cabeza;
        while (actual != nullptr) {
            suma += actual->dato;
            actual = actual->siguiente;
        }
        return suma / cantidad;
    }
    
    /**
     * @brief Obtiene la cantidad de elementos
     */
    int getCantidad() const {
        return cantidad;
    }
    
    /**
     * @brief Elimina el valor mas bajo de la lista
     */
    void eliminarMenor() {
        if (cabeza == nullptr) return;
        
        // Buscar el menor
        Nodo<T>* actual = cabeza;
        T menor = cabeza->dato;
        while (actual != nullptr) {
            if (actual->dato < menor) {
                menor = actual->dato;
            }
            actual = actual->siguiente;
        }
        
        // Eliminar el primer nodo con ese valor
        if (cabeza->dato == menor) {
            Nodo<T>* temp = cabeza;
            cabeza = cabeza->siguiente;
            std::cout << "  Valor mas bajo eliminado: " << menor << std::endl;
            delete temp;
            cantidad--;
            return;
        }
        
        actual = cabeza;
        while (actual->siguiente != nullptr) {
            if (actual->siguiente->dato == menor) {
                Nodo<T>* temp = actual->siguiente;
                actual->siguiente = temp->siguiente;
                std::cout << "  Valor mas bajo eliminado: " << menor << std::endl;
                delete temp;
                cantidad--;
                return;
            }
            actual = actual->siguiente;
        }
    }
};

#endif
