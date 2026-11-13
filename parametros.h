#ifndef PARAMETROS_H
#define PARAMETROS_H


typedef struct {
    double masa_kg;              
    double velocidad_ms;         
    double altura_m;             
    double coef_rozamiento;      
    double area_paracaidas_m2;   
    double angulo_entrada_deg;   
    double viento_ms;            
} Parametros;

Parametros cargar_valores_iniciales(void);   
void modificar_parametros(Parametros *p);    

#endif