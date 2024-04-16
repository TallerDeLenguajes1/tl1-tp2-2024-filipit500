#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define COMPUTADORAS 5
struct {
int velocidad;
int anio;
int cantidad;
char *tipo_cpu;
} typedef compu;

void cargarCaracteristicas(compu *compus,int cantidadComputadoras);
void mostrarPc(compu *compus,int cantidadComputadoras);
void pcMasVieja(compu *compus,int cantidadComputadoras);
void pcMasVelocidad(compu *compus,int cantidadComputadoras);

int main()
{
    srand(time(NULL));
    compu computadoras[COMPUTADORAS];
    cargarCaracteristicas(computadoras,COMPUTADORAS);
    mostrarPc(computadoras,COMPUTADORAS);
    pcMasVieja(computadoras,COMPUTADORAS);
    pcMasVelocidad(computadoras,COMPUTADORAS);
    for(int i = 0; i < COMPUTADORAS; i++){
        free(computadoras[i].tipo_cpu);
    }
    return 0;
}

void cargarCaracteristicas(compu *compus,int cantidadComputadoras)
{
    char tipos[6][10]={"Intel", "AMD", "Celeron", "Athlon", "Core", "Pentium"};
    for(int i = 0; i < cantidadComputadoras; i++){
        compus[i].velocidad = rand () % 3 + 1;
        compus[i].anio = 2015 + rand () % (2023 - 2015 + 1);
        compus[i].cantidad = rand () % 8 + 1;
        int tipo = rand () % 6;
        compus[i].tipo_cpu = malloc(10*sizeof(char));
        strcpy(compus[i].tipo_cpu,tipos[tipo]);
    }
}

void mostrarPc(compu *compus,int cantidadComputadoras)
{
    for(int i = 0; i < cantidadComputadoras; i++){
        printf("******COMPUTADORA %d*******\n",i+1);
        printf("velocidad: %d GHz\n", compus[i].velocidad);
        printf("anio de fabricacion: %d\n", compus[i].anio);
        printf("cantidad de nucleos: %d\n", compus[i].cantidad);
        printf("tipo de procesador: ");
        puts(compus[i].tipo_cpu);
    }
}

void pcMasVieja(compu *compus,int cantidadComputadoras)
{
    int mayor = 10000,computadora;
    for(int i = 0; i < cantidadComputadoras; i++){
        if(compus[i].anio < mayor){
            mayor = compus[i].anio;
            computadora = i;
        }
    }
    printf("******COMPUTADORA MAS VIEJA*******\n");
        printf("velocidad: %d GHz\n", compus[computadora].velocidad);
        printf("anio de fabricacion: %d\n", compus[computadora].anio);
        printf("cantidad de nucleos: %d\n", compus[computadora].cantidad);
        printf("tipo de procesador: ");
        puts(compus[computadora].tipo_cpu);
}

void pcMasVelocidad(compu *compus,int cantidadComputadoras)
{
    int menor = 0,computadora;
    for(int i = 0; i < cantidadComputadoras; i++){
        if(compus[i].velocidad > menor){
            menor = compus[i].velocidad;
            computadora = i;
        }
    }

        printf("******COMPUTADORA MAS RAPIDA*******\n");
        printf("velocidad: %d GHz\n", compus[computadora].velocidad);
        printf("anio de fabricacion: %d\n", compus[computadora].anio);
        printf("cantidad de nucleos: %d\n", compus[computadora].cantidad);
        printf("tipo de procesador: ");
        puts(compus[computadora].tipo_cpu);
}