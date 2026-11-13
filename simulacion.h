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
} Resultados;
 
Resultados simular(const Parametros *p);
 
#endif