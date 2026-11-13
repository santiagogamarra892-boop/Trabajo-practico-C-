# Trabajo-practico-C-
TRABAJO PRÁCTICO INTEGRADOR FINAL Simulador de Misiones Artemis (Lenguaje c)
Integrantes: 
1) Arrua Bruno (29308) COM C
2) Gamarra Santiago Miguel (28815) COM C
3) Sálica Alarcón Alejo Emanuel (29276) COM C

Descripción del escenario 4:
Este proyecto consiste en un simulador por consola desarrollado en lenguaje C, basado en el Escenario 4: Reingreso Atmosférico, Frenado Aerodinámico y Amerizaje del Trabajo Práctico Integrador de la misión Artemis.
Luego de completar el sobrevuelo lunar, el módulo de tripulación Orion se separa del módulo de servicio y reingresa a la atmósfera terrestre. Durante el descenso, la resistencia aerodinámica reduce su velocidad. Posteriormente se despliegan los paracaídas y la cápsula realiza un amerizaje en el océano Pacífico.
El programa permite modificar parámetros de entrada, ejecutar una simulación, consultar los resultados y guardar un registro de las ejecuciones realizadas.

Funcionamiento del programa:
Al iniciar, se muestra un menú principal con las siguientes opciones:
- 1. Comenzar simulación: ejecuta el cálculo con los parámetros actuales y muestra los resultados.
- 2. Modificar parámetros: permite cambiar la masa, velocidad inicial, altura, coeficiente de rozamiento, área, ángulo de entrada y velocidad del viento. Al presionar ENTER sin ingresar un valor, se conserva el valor actual. Luego se puede confirmar si se desea ejecutar la simulación.
- 3. Mostrar datos: muestra los parámetros vigentes y, si ya se realizó una simulación, también presenta sus últimos resultados.
- 4. Créditos: muestra los integrantes, la materia y la comisión.
- 5. Salir: finaliza el programa.
Cada simulación realizada intenta guardarse automáticamente en el archivo historial_simulaciones.csv, que se crea en el directorio desde el cual se ejecuta el programa. El archivo contiene la fecha y hora, los parámetros utilizados y algunos resultados de la trayectoria numérica.

Organización de los archivos:
El proyecto está dividido en módulos para separar la interfaz, los parámetros, la lógica de simulación y el registro histórico.

main.c: Contiene main(), controla el menú y coordina el flujo general del programa.

parametros.h: Define la estructura Parametros y declara las funciones relacionadas con la carga y modificación de parámetros.

parametros.c: Inicializa los valores del escenario y permite modificarlos.

simulacion.h: Define la estructura Resultados y declara la función de simulación.

simulacion.c: Implementa el modelo numérico del descenso y los cálculos físicos del escenario.

interfaz.h: Declara las funciones de interacción y presentación por consola.

interfaz.c: Implementa el menú, la lectura y validación de entradas, y la presentación de parámetros y resultados.

historial.h: Declara la función encargada de guardar los resultados.

historial.c: Registra los datos de cada simulación en un archivo CSV.

Makefale: Contiene las reglas de compilación utilizadas actualmente.


