# Moon Terminal

Moon Terminal es una implementacion de Moon Engine ofrece los compnentes y sistemas basicos para realizar un juego en la terminal de Linux y Windows

### Requisitos

- CMake 
- Ninja para Windows y GNU Make para Linux
- git
- Clang Compiler para Linux y Cygwin para windows
- ncurses para el manejo de la terminal

### Ejemplo
En el directorio `example/ExampleMoonTerminal`

**Instrucciones de Copilacion del ejemplo**

**Linux**

- `cd example/ExampleMoonTerminal`
- `cd vendor`
- `git clone git@github.com:reitmas32/Moon.git`
- `cd Moon`
- `git checkout experimental`
- `cd ..`
- `git clone git@github.com:reitmas32/Moon_Terminal.git`
- `mkdir build`
- `cd build`
- `cmake .. -DCMAKE_CXX_COMPILER=clang++ -DCMAKE_C_COMPILER=clang`

**Windows**

- `cd example/ExampleMoonTerminal`
- `cd vendor`
- `git clone git@github.com:reitmas32/Moon.git`
- `cd Moon`
- `git checkout experimental`
- `cd ..`
- `git clone git@github.com:reitmas32/Moon_Terminal.git`
- `mkdir build`
- `cd build`
- `cmake .. -G "Ninja" -DCMAKE_CXX_COMPILER=g++ -DCMAKE_C_COMPILER=gcc`