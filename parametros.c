

#include <stdio.h>
#include "parametros.h"
#include "interfaz.h"

Parametros cargar_valores_iniciales(void)
{
    Parametros p = {
        .masa_kg            = 10400.0,
        .velocidad_ms       = 11000.0,
        .altura_m           = 120000.0,
        .coef_rozamiento    = 1.0,
        .area_paracaidas_m2 = 2886.0,
        .angulo_entrada_deg = 6.25,
        .viento_ms          = 0.0
    };

    return p;
}

void modificar_parametros(Parametros *p)
{
    printf("\n--- MODIFICAR PARAMETROS ---\n");
    printf("(ENTER sin escribir nada conserva el valor actual)\n\n");

    p->masa_kg = interfaz_pedir_double(
        "Ingrese la masa (kg)", p->masa_kg, 1.0, 1000000.0);

    p->velocidad_ms = interfaz_pedir_double(
        "Ingrese la velocidad inicial (m/s)",
        p->velocidad_ms, 0.0, 20000.0);

    p->altura_m = interfaz_pedir_double(
        "Ingrese la altura inicial (m)",
        p->altura_m, 1.0, 150000.0);

    p->coef_rozamiento = interfaz_pedir_double(
        "Ingrese el coeficiente de rozamiento",
        p->coef_rozamiento, 0.01, 5.0);

    p->area_paracaidas_m2 = interfaz_pedir_double(
        "Ingrese el area de paracaidas (m2)",
        p->area_paracaidas_m2, 0.1, 100000.0);

    p->angulo_entrada_deg = interfaz_pedir_double(
        "Ingrese el angulo de entrada (grados)",
        p->angulo_entrada_deg, 1.0, 90.0);

    p->viento_ms = interfaz_pedir_double(
        "Ingrese la velocidad del viento (m/s)",
        p->viento_ms, -100.0, 100.0);

    printf("\nParametros actualizados.\n");
}
