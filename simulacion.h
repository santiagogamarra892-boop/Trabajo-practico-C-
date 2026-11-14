#ifndef SIMULACION_H
#define SIMULACION_H
 
#include "parametros.h"
 
typedef struct {
    double fuerza_rozamiento_N;
    double desaceleracion_ms2;
    double angulo_inclinacion_deg;
    double velocidad_impacto_ms;
    double tiempo_descenso_s;
    double distancia_horizontal_m;

    /* Calculos especificos del escenario Artemis */
    double trabajo_rozamiento_J;
    double desaceleracion_media_ms2;
    double desaceleracion_media_g;
    double fuerza_agua_N;
    double fuerza_agua_veces_peso;
    int evaluacion_angulo;
} Resultados;
 
Resultados simular(const Parametros *p);
 
#endif