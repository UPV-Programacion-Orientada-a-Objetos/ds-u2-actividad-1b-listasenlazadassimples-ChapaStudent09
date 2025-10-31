#ifndef LISTA_GESTION_H
#define LISTA_GESTION_H

#include "sensor_base.h"

/**
 * @brief Nodo para la lista de gestion polimorfica
 */
struct NodoSensor {
    SensorBase* sensor;
    NodoSensor* siguiente;
    
    NodoSensor(SensorBase* s) : sensor(s), siguiente(nullptr) {}
};

/**
 * @brief Lista de gestion que maneja todos los sensores
 */
class ListaGestion {
private:
    NodoSensor* cabeza;

public:
    ListaGestion() : cabeza(nullptr) {}
    
    ~ListaGestion() {
        std::cout << "\n--- Liberacion de Memoria en Cascada ---" << std::endl;
        NodoSensor* actual = cabeza;
        while (actual != nullptr) {
            NodoSensor* siguiente = actual->siguiente;
            std::cout << "[Destructor General] Liberando Nodo: " 
                      << actual->sensor->getNombre() << std::endl;
            delete actual->sensor;
            delete actual;
            actual = siguiente;
        }
        std::cout << "Sistema cerrado. Memoria limpia." << std::endl;
    }
    
    void agregar(SensorBase* sensor) {
        NodoSensor* nuevo = new NodoSensor(sensor);
        
        if (cabeza == nullptr) {
            cabeza = nuevo;
        } else {
            NodoSensor* actual = cabeza;
            while (actual->siguiente != nullptr) {
                actual = actual->siguiente;
            }
            actual->siguiente = nuevo;
        }
    }
    
    SensorBase* buscar(const char* id) {
        NodoSensor* actual = cabeza;
        while (actual != nullptr) {
            const char* nombre = actual->sensor->getNombre();
            bool igual = true;
            
            for (int i = 0; nombre[i] != '\0' || id[i] != '\0'; i++) {
                if (nombre[i] != id[i]) {
                    igual = false;
                    break;
                }
            }
            
            if (igual) {
                return actual->sensor;
            }
            actual = actual->siguiente;
        }
        return nullptr;
    }
    
    void procesarTodos() {
        std::cout << "\n--- Ejecutando Polimorfismo ---" << std::endl;
        NodoSensor* actual = cabeza;
        while (actual != nullptr) {
            actual->sensor->procesarLectura();
            actual = actual->siguiente;
        }
    }
    
    void mostrarTodos() const {
        std::cout << "\n--- Lista de Sensores ---" << std::endl;
        NodoSensor* actual = cabeza;
        while (actual != nullptr) {
            actual->sensor->imprimirInfo();
            actual = actual->siguiente;
        }
    }
};

#endif
