
#include <stdio.h>
#include "parametros.h"
#include "simulacion.h"
#include "interfaz.h"
#include "historial.h"

enum {
    OPC_SIMULAR = 1,
    OPC_MODIFICAR,
    OPC_MOSTRAR,
    OPC_CREDITOS,
    OPC_SALIR
};

static void ejecutar_simulacion(const Parametros *params, Resultados *ultimo, int *hay_resultado)
{
    *ultimo = simular(params);
    *hay_resultado = 1;

    interfaz_mostrar_resultados(ultimo);
    guardar_historial(params, ultimo);
}

int main(void)
{
    Parametros params = cargar_valores_iniciales();   /* constantes del escenario */
    Resultados ultimo;
    int hay_resultado = 0;
    int opcion;

    do {
        opcion = interfaz_menu_principal();

        switch (opcion) {
        case OPC_SIMULAR:
            ejecutar_simulacion(&params, &ultimo, &hay_resultado);
            break;

        case OPC_MODIFICAR:
            modificar_parametros(&params);
            if (interfaz_confirmar_simulacion()) {    /* "Ingrese 1 para realizar simulacion" */
                ejecutar_simulacion(&params, &ultimo, &hay_resultado);
            }
            break;

        case OPC_MOSTRAR:
            interfaz_mostrar_parametros(&params);
            if (hay_resultado) {
                interfaz_mostrar_resultados(&ultimo);
            } else {
                interfaz_mensaje("Todavia no se realizo ninguna simulacion.");
            }
            break;

        case OPC_CREDITOS:
            interfaz_mostrar_creditos();
            break;

        case OPC_SALIR:
            interfaz_mensaje("Saliendo del simulador...");
            break;

        default:
            interfaz_mensaje("Opcion invalida. Ingrese un numero del 1 al 5.");
            break;
        }
    } while (opcion != OPC_SALIR);

    return 0;
}