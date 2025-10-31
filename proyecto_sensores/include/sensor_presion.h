#ifndef SENSOR_PRESION_H
#define SENSOR_PRESION_H

#include "sensor_base.h"
#include "lista_sensor.h"

/**
 * @brief Sensor que maneja lecturas de presion (int)
 */
class SensorPresion : public SensorBase {
private:
    ListaSensor<int> historial;

public:
    SensorPresion(const char* id) : SensorBase(id) {}
    
    ~SensorPresion() {
        std::cout << "  [Destructor Sensor " << nombre << "] Liberando lista interna..." << std::endl;
    }
    
    void agregarLectura(int valor) {
        historial.insertar(valor);
    }
    
    void procesarLectura() override {
        std::cout << "-> Procesando Sensor " << nombre << "..." << std::endl;
        
        if (historial.getCantidad() == 0) {
            std::cout << "[Sensor Presion] Sin lecturas disponibles." << std::endl;
            return;
        }
        
        double promedio = historial.calcularPromedio();
        std::cout << "[Sensor Presion] Promedio: " << promedio 
                  << " sobre " << historial.getCantidad() << " lectura(s)." << std::endl;
    }
    
    void imprimirInfo() const override {
        std::cout << "Sensor Presion: " << nombre 
                  << " | Lecturas: " << historial.getCantidad() << std::endl;
    }
};

#endif
