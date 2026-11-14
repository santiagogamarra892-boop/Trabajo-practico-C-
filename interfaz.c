
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "interfaz.h"
 
#define TAM_LINEA 128
 

static int leer_linea(char *buf, size_t n)
{
    size_t len;
    if (fgets(buf, (int)n, stdin) == NULL) return 0;
 
    len = strlen(buf);
    if (len > 0 && buf[len - 1] == '\n') {
        buf[len - 1] = '\0';
    } else {
        int c;                                  
        while ((c = getchar()) != '\n' && c != EOF) { }
    }
    return 1;
}
 
int interfaz_menu_principal(void)
{
    char linea[TAM_LINEA];
    char *fin;
    long op;
 
    printf("\n==========================================\n");
    printf("         SIMULACION DE AMERIZAJE\n");
    printf("==========================================\n");
    printf("  INGRESE UN NUMERO DEL 1 AL 5\n\n");
    printf("  1_COMENZAR SIMULACION\n");
    printf("  2_MODIFICAR PARAMETROS\n");
    printf("  3_MOSTRAR DATOS\n");
    printf("  4_CREDITOS\n");
    printf("  5_SALIR\n\n");
    printf("  Opcion: ");
 
    if (!leer_linea(linea, sizeof linea)) return 5;   
 
    op = strtol(linea, &fin, 10);
    if (fin == linea || *fin != '\0' || op < 1 || op > 5) return 0;
    return (int)op;
}
 
int interfaz_confirmar_simulacion(void)
{
    char linea[TAM_LINEA];
    char *fin;
    long op;
 
    printf("\nIngrese 1 para realizar la simulacion (otro valor vuelve al menu): ");
    if (!leer_linea(linea, sizeof linea)) return 0;
 
    op = strtol(linea, &fin, 10);
    return (fin != linea && *fin == '\0' && op == 1);
}
 
double interfaz_pedir_double(const char *msg, double actual, double min, double max)
{
    char linea[TAM_LINEA];
 
    for (;;) {
        char *p, *fin;
        double v;
 
        printf("%s [actual: %g] (%g a %g): ", msg, actual, min, max);
        if (!leer_linea(linea, sizeof linea)) return actual;
        if (linea[0] == '\0') return actual;              /* ENTER: conserva el valor */
 
        for (p = linea; *p; p++) if (*p == ',') *p = '.'; /* acepta coma decimal */
 
        v = strtod(linea, &fin);
        if (fin == linea || *fin != '\0' || v != v) {
            printf("  Valor invalido, ingrese un numero.\n");
            continue;
        }
        if (v < min || v > max) {
            printf("  Fuera de rango, intente de nuevo.\n");
            continue;
        }
        return v;
    }
}
 
void interfaz_mostrar_parametros(const Parametros *p)
{
    printf("\n--- PARAMETROS ACTUALES ---\n");
    printf("Masa:                  %.2f kg\n",  p->masa_kg);
    printf("Velocidad inicial:     %.2f m/s\n", p->velocidad_ms);
    printf("Altura inicial:        %.2f m\n",   p->altura_m);
    printf("Coef. de rozamiento:   %.3f\n",     p->coef_rozamiento);
    printf("Area de paracaidas:    %.2f m2\n",  p->area_paracaidas_m2);
    printf("Angulo de entrada:     %.2f grados\n", p->angulo_entrada_deg);
    printf("Viento:                %.2f m/s\n", p->viento_ms);
}
 

void interfaz_mostrar_resultados(const Resultados *r)
{
    printf("\n--- RESULTADOS DE LA SIMULACION ---\n");

    printf("Fuerza de rozamiento (max): %.2f N\n",
           r->fuerza_rozamiento_N);

    printf("Desaceleracion (max): %.2f m/s2\n",
           r->desaceleracion_ms2);

    printf("Angulo de inclinacion: %.2f grados\n",
           r->angulo_inclinacion_deg);

    printf("Velocidad de impacto: %.2f m/s\n",
           r->velocidad_impacto_ms);

    printf("Tiempo de descenso: %.2f s\n",
           r->tiempo_descenso_s);

    printf("Desplazamiento horizontal: %.2f m\n",
           r->distancia_horizontal_m);

    printf("\n--- CALCULOS DEL ESCENARIO ARTEMIS ---\n");

    printf("Trabajo del rozamiento: %.2f J\n",
           r->trabajo_rozamiento_J);

    printf("Desaceleracion media: %.4f m/s2\n",
           r->desaceleracion_media_ms2);

    printf("Desaceleracion media: %.2f g\n",
           r->desaceleracion_media_g);

    printf("Fuerza promedio del agua: %.2f N\n",
           r->fuerza_agua_N);

    printf("Fuerza del agua respecto al peso: %.2f veces\n",
           r->fuerza_agua_veces_peso);

    printf("\nEvaluacion del angulo de entrada: ");

    if (r->evaluacion_angulo == -1) {
        printf("INFERIOR AL RANGO SEGURO: riesgo de rebote atmosferico.\n");
    } else if (r->evaluacion_angulo == 1) {
        printf("SUPERIOR AL RANGO SEGURO: desaceleracion excesiva.\n");
    } else {
        printf("DENTRO DEL RANGO SEGURO (5.5 a 7 grados).\n");
    }
}

 
void interfaz_mostrar_creditos(void)
{
    printf("\n--- CREDITOS ---\n");
    printf("Simulador de aterrizaje - Nave Artemis\n\n");

    printf("Integrantes:\n");
    printf("- Arrua Bruno\n");
    printf("- Gamarra Santiago\n");
    printf("- Salica Alarcon Alejo\n\n");

    printf("Materia: Algoritmos y Estructuras de Datos (AED)\n");
    printf("Comision: C\n");
}
 
void interfaz_mensaje(const char *texto)
{
    printf("\n>> %s\n", texto);
}