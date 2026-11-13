#include <math.h>
#include "simulacion.h"
 
#define GRAVEDAD       9.81
#define DENSIDAD_AIRE  1.225
#define PASO_TIEMPO    0.001    
#define TIEMPO_MAXIMO  3600.0     
#define PI_            3.14159265358979323846
 
Resultados simular(const Parametros *p)
{
    Resultados r = {0};
 
    double ang = p->angulo_entrada_deg * PI_ / 180.0;
    double x  = 0.0;
    double y  = p->altura_m;
    double vx = p->velocidad_ms * cos(ang);
    double vy = -p->velocidad_ms * sin(ang);   
    double t  = 0.0;
    double k  = 0.5 * DENSIDAD_AIRE * p->coef_rozamiento * p->area_paracaidas_m2;
 
    double fuerza_max = 0.0;
 
    while (y > 0.0 && t < TIEMPO_MAXIMO) {
        double rvx = vx - p->viento_ms;        
        double rvy = vy;
        double vrel = sqrt(rvx * rvx + rvy * rvy);
 
        double fuerza = k * vrel * vrel;
        if (fuerza > fuerza_max) fuerza_max = fuerza;
 
        double ax = 0.0;
        double ay = -GRAVEDAD;
        if (vrel > 0.0) {
            ax -= fuerza * (rvx / vrel) / p->masa_kg;
            ay -= fuerza * (rvy / vrel) / p->masa_kg;
        }
 
        vx += ax * PASO_TIEMPO;
        vy += ay * PASO_TIEMPO;
        x  += vx * PASO_TIEMPO;
        y  += vy * PASO_TIEMPO;
        t  += PASO_TIEMPO;
    }
 
    r.fuerza_rozamiento_N      = fuerza_max;
    r.desaceleracion_ms2       = fuerza_max / p->masa_kg;
    r.angulo_inclinacion_deg   = atan2(-vy, fabs(vx)) * 180.0 / PI_;
    r.velocidad_impacto_ms     = sqrt(vx * vx + vy * vy);
    r.tiempo_descenso_s        = t;
    r.distancia_horizontal_m   = x;
    return r;
}