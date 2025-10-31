cmake_minimum_required(VERSION 3.10)
project(SistemaIoTSensores)

set(CMAKE_CXX_STANDARD 11)

# Esta línea incluye los directorios para encontrar los .h (include/lista_gestion.h, etc.)
# Si todos tus .h están en el directorio raíz o en 'include', esta línea está bien.
include_directories(include)

# ----------------------------------------------------------------------
# MODIFICACIÓN CLAVE: Incluir todos los archivos .cpp
# ----------------------------------------------------------------------
add_executable(sensores
    src/main.cpp
    src/lista_gestion.cpp
    src/sensor_base.cpp
    # Los archivos sensor_temperatura.h y sensor_presion.h usan templates
    # y por lo general no necesitan un .cpp separado, pero si existen, inclúyelos.
    # src/sensor_temperatura.cpp
    # src/sensor_presion.cpp
)
# ----------------------------------------------------------------------

install(TARGETS sensores DESTINATION bin)
