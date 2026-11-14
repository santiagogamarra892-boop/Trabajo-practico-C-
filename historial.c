#include <stdio.h>
#include <time.h>
#include "historial.h"
 

static void num(char *dst, size_t n, double v)
{
    char *p;
    snprintf(dst, n, "%.2f", v);
    for (p = dst; *p; p++) if (*p == '.') *p = ',';
}
 
static int archivo_tiene_datos(void)
{
    long tam = 0;
    FILE *f = fopen(ARCHIVO_HISTORIAL, "r");
    if (f == NULL) return 0;
    fseek(f, 0, SEEK_END);
    tam = ftell(f);
    fclose(f);
    return tam > 0;
}
 
int guardar_historial(const Parametros *p, const Resultados *r)
{
    char c[11][32];
    char fecha[32] = "";
    time_t ahora = time(NULL);
    struct tm *tmp = localtime(&ahora);
    int con_encabezado = archivo_tiene_datos();
    FILE *f;
 
    if (tmp != NULL) strftime(fecha, sizeof fecha, "%Y-%m-%d %H:%M:%S", tmp);
 
    f = fopen(ARCHIVO_HISTORIAL, "a");
    if (f == NULL) return 0;
 
    if (!con_encabezado) {
        fprintf(f, "Fecha;Masa_kg;Velocidad_ms;Altura_m;Coef_rozamiento;Area_paracaidas_m2;"
                   "Angulo_entrada_deg;Viento_ms;Fuerza_rozamiento_N;Desaceleracion_ms2;"
                   "Angulo_inclinacion_deg;Velocidad_impacto_ms;Tiempo_descenso_s\n");
    }
 
    num(c[0], sizeof c[0], p->masa_kg);
    num(c[1], sizeof c[1], p->velocidad_ms);
    num(c[2], sizeof c[2], p->altura_m);
    num(c[3], sizeof c[3], p->coef_rozamiento);
    num(c[4], sizeof c[4], p->area_paracaidas_m2);
    num(c[5], sizeof c[5], p->angulo_entrada_deg);
    num(c[6], sizeof c[6], p->viento_ms);
    num(c[7], sizeof c[7], r->fuerza_rozamiento_N);
    num(c[8], sizeof c[8], r->desaceleracion_ms2);
    num(c[9], sizeof c[9], r->angulo_inclinacion_deg);
    num(c[10], sizeof c[10], r->velocidad_impacto_ms);
 
    fprintf(f, "%s;%s;%s;%s;%s;%s;%s;%s;%s;%s;%s;%s;", fecha,
            c[0], c[1], c[2], c[3], c[4], c[5], c[6], c[7], c[8], c[9], c[10]);
    {
        char t[32];
        num(t, sizeof t, r->tiempo_descenso_s);
        fprintf(f, "%s\n", t);
    }
 
    fclose(f);
    return 1;
}