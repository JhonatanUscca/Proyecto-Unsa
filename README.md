# Proyecto final CCII: ¡No botes la basura!

## Concept

Un juego multijugador local donde los protagonistas buscan limpiar diferentes lugares ensuciados por otros niños, pero por aquella tarea recibirán un pago de sus vecinos por lo que estos buscan estropearse uno al otro para ganar más dinero.

## Members

- [Huaquisto Quispe Fabricio](https://github.com/fhuaquisto21)
- [Uscca Giraldo Jhonathan Bilbao](https://github.com/JhonatanUscca)
- [Caceres Cuba Jayan](https://github.com/jayan04mcc)
- [Rojas Miranda Eduardo Fabián](https://github.com/EduardoRojasM)
- [Condori Bernal Clever](https://github.com/kleber88)

## ToDo

- [x] Loop Main
- [x] Scene Manager
- [x] Scene Factory
- [x] Object Factory
- [x] Object class
- [x] Scene class
- [x] Character class
- [x] Network
- [x] Server
- [x] Client
- [ ] Graphics
- [ ] Sounds
- [ ] Menu
- [ ] Enemy
- [ ] Enemy logic
- [ ] Player
- [ ] Player camera
- [ ] ...

## Installation

### Windows

1. Descargar [SFML](https://www.sfml-dev.org/download.php) según el compilador de c++ a usar, se recomienda usar el compilador de [MinGW](https://www.mingw-w64.org/) para la tarea, pero también es válido instalar Visual Studio.
2. Mover la carpeta SFML al disco local "C" o actualizar el archivo "cmake/Makefile.Window" con la ruta absoluta a la librería.
3. (Opcional) Instalar [Chocolatery](https://chocolatey.org/) para ejecutar el siguiente comando: ``` choco install make ```, el comando instalará el paquete de "make" para la compilación del juego.
4. ``` make -f cmake/Makefile.Window ``` si usa el cmd o powershell de windows, pero si usa git bash deberá ejecutar el comando ``` make -f cmake/Makefile.Windows ```.

### Linux
1. Descargar [SFML](https://www.sfml-dev.org/download.php) para linux.
2. Mover la carpeta SFML/include a la ruta ``` ~/.local/include ``` o editar el archivo "cmake/Makefile.Linux" con la ruta absoluta a la librería.
3. Por defecto, Linux viene con "make" y el compilador "g++", puede verificar las librerías con el comando ```make --version``` y ```g++ --version```, si no arroja error podemos proceder.
4. Si los paquetes no se encuentran en su distribución puede instalarlo con (Arch linux) ``` sudo pacman -S make gcc ``` o con sus gestor de paquetes.
5. Ejecutar el comando ``` make -f cmake/Makefile.Linux ```.
