#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "incFiles/stm32f103x6.h"
#include "servobrazo/servobrazo.h"
#include "uartbrazo/uartbrazo.h"
#include "potbrazo/potbrazo.h"

void delay(uint32_t tiempo)
{
	uint32_t i = 0;
	for(i = 0; i < tiempo;i++);
}

int main()
{
    uint16_t valorADC0 = 0;
    uint16_t valorADC1 = 0;
    uint16_t valorADC2 = 0;
    uint16_t valorADC3 = 0;
    uint32_t angulo_inicial = 1000;
	uint32_t angulo_final = 2000;
    uint32_t anguloADC = 0;
    servo1();
    servo2();
    servo3();
    servo4();
    inicializarUART();
    initADC();
    uint8_t instruccion = 0;

    enviarPalabra("BIENVENIDOS AL PROGRAMA BRAZO ROBOTICO");
    nuevaLinea();
    enviarPalabra("Ingresa la letra correspondiente");
    instruccion = leerCaracter(); // Leer la instrucción del usuario
    if(instruccion == 'a')
    {
        enviarPalabra("Los brazos roboticos se encuentran inhabilitados");
        nuevaLinea();
    }
    else if(instruccion == 'b')
    {
        while(1){           
            valorADC0 = leerPuerto(0);
            anguloADC = angulo_inicial + ((valorADC0 *(angulo_final - angulo_inicial))/4096);
            TIM3 -> CCR4 = anguloADC;
            TIM3 -> CCR3 = anguloADC;
            TIM3 -> CCR2 = anguloADC;
            TIM3 -> CCR1 = anguloADC;        
        }

    }

    else if(instruccion =='g')
    {
        uint16_t valorA0 = leerPuerto(0); 
        uint16_t valorA1 = leerPuerto(1); 
        uint16_t valorA2 = leerPuerto(2); 
        uint16_t valorA3 = leerPuerto(3); 
        char mensajeInicial[100] = "Valor del ADC PA0: ";
        char valorADC_0[32];
        sprintf(valorADC_0, "%d", valorA0);
        strcat(mensajeInicial, valorADC_0);

        enviarPalabra(mensajeInicial);
        nuevaLinea();
        
        char mensajeInicial1[100] = "Valor del ADC PA1: ";
        char valorADC_1[32];
        sprintf(valorADC_1, "%d", valorA1);
        strcat(mensajeInicial1, valorADC_1);

        enviarPalabra(mensajeInicial1);
        nuevaLinea();
            
        char mensajeInicial2[100] = "Valor del ADC PA2: ";
        char valorADC_2[32];
        sprintf(valorADC_2, "%d", valorA2);
        strcat(mensajeInicial2, valorADC_2);

        enviarPalabra(mensajeInicial2);
        nuevaLinea();

        char mensajeInicial3[100] = "Valor del ADC PA3: ";
        char valorADC_3[32];
        sprintf(valorADC_3, "%d", valorA3);
        strcat(mensajeInicial3, valorADC_3);

        enviarPalabra(mensajeInicial3);
        nuevaLinea();
    }
    else if(instruccion =='h')
    {
        enviarPalabra("h");

    }
    else if(instruccion =='i')
    {
        enviarPalabra("Instruccion i");
        nuevaLinea();
    }
    for(uint32_t i = 0; i < 100000; i++);
    return 0;
}
