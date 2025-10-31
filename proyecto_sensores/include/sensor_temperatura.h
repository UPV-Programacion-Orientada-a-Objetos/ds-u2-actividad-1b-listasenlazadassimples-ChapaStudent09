#ifndef SENSOR_TEMPERATURA_H
#define SENSOR_TEMPERATURA_H

#include "sensor_base.h"
#include "lista_sensor.h"

/**
 * @brief Sensor que maneja lecturas de temperatura (float)
 */
class SensorTemperatura : public SensorBase {
private:
    ListaSensor<float> historial;

public:
    SensorTemperatura(const char* id) : SensorBase(id) {}
    
    ~SensorTemperatura() {
        std::cout << "  [Destructor Sensor " << nombre << "] Liberando lista interna..." << std::endl;
    }
    
    void agregarLectura(float valor) {
        historial.insertar(valor);
    }
    
    void procesarLectura() override {
        std::cout << "-> Procesando Sensor " << nombre << "..." << std::endl;
        
        if (historial.getCantidad() == 0) {
            std::cout << "[Sensor Temp] Sin lecturas disponibles." << std::endl;
            return;
        }
        
        if (historial.getCantidad() > 1) {
            historial.eliminarMenor();
        }
        
        double promedio = historial.calcularPromedio();
        std::cout << "[Sensor Temp] Promedio: " << promedio 
                  << " sobre " << historial.getCantidad() << " lectura(s)." << std::endl;
    }
    
    void imprimirInfo() const override {
        std::cout << "Sensor Temperatura: " << nombre 
                  << " | Lecturas: " << historial.getCantidad() << std::endl;
    }
};

#endif
