cmake_minimum_required(VERSION 3.24)
project(algorithms_3_and_4)

set(CMAKE_CXX_STANDARD 17)
# Agrega todos los archivos .cpp de la carpeta 'algorithms_3' a la lista de fuentes
file(GLOB ALGORITHMS_3_SOURCES "algorithms_3/*.cpp")

# Agrega 'main.cpp' y los archivos de 'algorithms_3' al ejecutable
add_executable(algorithms_3_and_4 main.cpp ${ALGORITHMS_3_SOURCES} Algorithms_3/clase1.cpp Algorithms_3/Expresiones.cpp Algorithms_3/Final/Final.cpp Algorithms_3/Taller1/Taller1A.cpp Algorithms_3/Taller1/Taller1B.cpp "Algorithms_3/Taller 2/taller2.cpp" Algorithms_3/calculadoraListas.cpp Algorithms_3/final.cpp Algorithms_3/fullmatriz.cpp Algorithms_3/Infijo-posfijo-prefijo.cpp Algorithms_3/matDispersa.cpp)
