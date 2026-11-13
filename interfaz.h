#ifndef INTERFAZ_H
#define INTERFAZ_H
 
#include "parametros.h"
#include "simulacion.h"
 
int    interfaz_menu_principal(void);        
int    interfaz_confirmar_simulacion(void);    
double interfaz_pedir_double(const char *msg, double actual, double min, double max);
void   interfaz_mostrar_parametros(const Parametros *p);
void   interfaz_mostrar_resultados(const Resultados *r);
void   interfaz_mostrar_creditos(void);
void   interfaz_mensaje(const char *texto);
 
#endif