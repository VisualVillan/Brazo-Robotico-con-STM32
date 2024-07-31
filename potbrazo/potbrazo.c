#include "potbrazo.h"

void initADC(void)
{
    // Habilitar el reloj para el ADC y los GPIO
    RCC->APB2ENR |= (1 << 0) | (1 << 2) | (1 << 9);
    
    // Configurar PA0, PA1, PA2 y PA3 como entradas analógicas
    GPIOA->CRL &= ~(0xF << 0);  // PA0
    GPIOA->CRL &= ~(0xF << 4);  // PA1
    GPIOA->CRL &= ~(0xF << 8);  // PA2
    GPIOA->CRL &= ~(0xF << 12); // PA3

    // Desactivar el ADC antes de la configuración
    ADC1->CR2 &= ~(1 << 0);

    // Configuración de la secuencia de conversión
    ADC1->SQR1 &= ~(0xFFFFFF);
    ADC1->SQR1 |= (3 << 20); // 4 conversiones
    ADC1->SQR3 &= ~(0x3FFFFFFF);
    ADC1->SQR3 |= (0x0 << 0) | (0X1 << 5) | (0x2 << 10) | (0x3 << 15); // Canal 0-3

    // Configuración del tiempo de muestreo
    ADC1->SMPR2 |= (0x7 << 0);   // Canal 0
    ADC1->SMPR2 |= (0x7 << 3);   // Canal 1
    ADC1->SMPR2 |= (0x7 << 6);   // Canal 2
    ADC1->SMPR2 |= (0x7 << 9);   // Canal 3

    // Habilitar el ADC
    ADC1->CR2 |= (1 << 0);
}

uint16_t leerPuerto(uint8_t canal)
{
    ADC1->SQR3 = (ADC1->SQR3 & ~(0x3 << (canal * 5))) | (canal << (canal * 5));
    ADC1->CR2 |= (1 << 0); 
    ADC1->CR2 |= (1 << 22);
    while (!(ADC1->SR & (1 << 1)));
    uint16_t valorADC = ADC1->DR & 0xFFF;
    ADC1->SR &= ~(1 << 1);

    return valorADC;
}
