#ifndef HISTORIAL_H
#define HISTORIAL_H
 
#include "parametros.h"
#include "simulacion.h"
 
#define ARCHIVO_HISTORIAL "historial_simulaciones.csv"
 
int guardar_historial(const Parametros *p, const Resultados *r);
 
#endif