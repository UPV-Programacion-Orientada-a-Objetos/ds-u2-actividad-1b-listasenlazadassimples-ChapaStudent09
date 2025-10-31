#include <iostream>
#include <cstring>
#include "lista_gestion.h"
#include "sensor_temperatura.h"
#include "sensor_presion.h"

using namespace std;

void mostrarMenu() {
    cout << "\n=== Sistema IoT de Monitoreo Polimórfico ===" << endl;
    cout << "1. Crear Sensor Temperatura" << endl;
    cout << "2. Crear Sensor Presion" << endl;
    cout << "3. Registrar Lectura" << endl;
    cout << "4. Ejecutar Procesamiento Polimorfico" << endl;
    cout << "5. Mostrar Sensores" << endl;
    cout << "6. Cerrar Sistema" << endl;
    cout << "Opcion: ";
}

int main() {
    ListaGestion sistema;
    int opcion;
    
    cout << "--- Sistema IoT de Monitoreo Polimorfico ---\n" << endl;
    
    do {
        mostrarMenu();
        cin >> opcion;
        
        if (opcion == 1) {
            char id[50];
            cout << "ID del sensor: ";
            cin >> id;
            
            SensorTemperatura* temp = new SensorTemperatura(id);
            sistema.agregar(temp);
            cout << "Sensor '" << id << "' (Temperatura) creado." << endl;
            
        } else if (opcion == 2) {
            char id[50];
            cout << "ID del sensor: ";
            cin >> id;
            
            SensorPresion* pres = new SensorPresion(id);
            sistema.agregar(pres);
            cout << "Sensor '" << id << "' (Presion) creado." << endl;
            
        } else if (opcion == 3) {
            char id[50];
            cout << "ID del sensor: ";
            cin >> id;
            
            SensorBase* sensor = sistema.buscar(id);
            if (sensor == nullptr) {
                cout << "Sensor no encontrado." << endl;
                continue;
            }
            
            cout << "Tipo (1=Temp/2=Presion): ";
            int tipo;
            cin >> tipo;
            
            if (tipo == 1) {
                float valor;
                cout << "Valor (float): ";
                cin >> valor;
                SensorTemperatura* temp = dynamic_cast<SensorTemperatura*>(sensor);
                if (temp) {
                    temp->agregarLectura(valor);
                    cout << "Lectura agregada: " << valor << endl;
                }
            } else if (tipo == 2) {
                int valor;
                cout << "Valor (int): ";
                cin >> valor;
                SensorPresion* pres = dynamic_cast<SensorPresion*>(sensor);
                if (pres) {
                    pres->agregarLectura(valor);
                    cout << "Lectura agregada: " << valor << endl;
                }
            }
            
        } else if (opcion == 4) {
            sistema.procesarTodos();
            
        } else if (opcion == 5) {
            sistema.mostrarTodos();
            
        } else if (opcion == 6) {
            cout << "\nCerrando sistema..." << endl;
        }
        
    } while (opcion != 6);
    
    return 0;
}
