#include "servobrazo.h"

void servo1()
{
   // PB1 TIM3 CH4
    RCC->APB2ENR |= (1<<3) | (1<<0);  // Habilitar GPIOB y AFIO
    RCC->APB1ENR |= (1<<1);           // Habilitar TIM3

    GPIOB->CRL &= ~(0xF << 4);        // Limpiar configuración de PB1
    GPIOB->CRL |= (0xA << 4);         // Configurar PB1 como salida alternativa push-pull

    TIM3->PSC = 7;                    // Prescaler
    TIM3->ARR = 20000;                // Auto-reload register
    TIM3->CCR4 = 1000;                // Capture/Compare register 4

    TIM3->CCMR2 &= ~(0xFF << 8);      // Limpiar bits
    TIM3->CCMR2 |= (0x68 << 8);       // Configurar como PWM mode 1 en CH4

    TIM3->CCER |= (1 << 12);          // Habilitar salida en CH4
    TIM3->CR1 |= (1 << 7) | (1 << 0); // Auto-reload preload enable y counter enable
}

void servo2()
{
    // PB0 TIM3 CH3
    RCC->APB2ENR |= (1<<3) | (1<<0);  // Habilitar GPIOB y AFIO
    RCC->APB1ENR |= (1<<1);           // Habilitar TIM3

    GPIOB->CRL &= ~(0xF << 0);        // Limpiar configuración de PB0
    GPIOB->CRL |= (0xA << 0);         // Configurar PB0 como salida alternativa push-pull

    TIM3->PSC = 7;                    // Prescaler
    TIM3->ARR = 20000;                // Auto-reload register
    TIM3->CCR3 = 1000;               // Capture/Compare register 3

    TIM3->CCMR2 &= ~(0xFF << 0);      // Limpiar bits
    TIM3->CCMR2 |= (0x68 << 0);       // Configurar como PWM mode 1 en CH3

    TIM3->CCER |= (1 << 8);           // Habilitar salida en CH3
    TIM3->CR1 |= (1 << 7) | (1 << 0); // Auto-reload preload enable y counter enable
}

void servo3()
{
    // PA7 TIM3 CH2
    RCC->APB2ENR |= (1<<0) | (1<<2);  // Habilitar GPIOA y AFIO
    RCC->APB1ENR |= (1<<1);           // Habilitar TIM3

    GPIOA->CRL &= ~(0xF << 28);       // Limpiar configuración de PA7
    GPIOA->CRL |= (0xA << 28);        // Configurar PA7 como salida alternativa push-pull

    TIM3->PSC = 7;                    // Prescaler
    TIM3->ARR = 20000;                // Auto-reload register
    TIM3->CCR2 = 1000;               // Capture/Compare register 2

    TIM3->CCMR1 &= ~(0xFF << 8);      // Limpiar bits
    TIM3->CCMR1 |= (0x68 << 8);       // Configurar como PWM mode 1 en CH2

    TIM3->CCER |= (1 << 4);           // Habilitar salida en CH2
    TIM3->CR1 |= (1 << 7) | (1 << 0); // Auto-reload preload enable y counter enable
}

void servo4()
{
    // PA6 TIM3 CH1
    RCC->APB2ENR |= (1<<0) | (1<<2);  // Habilitar GPIOA y AFIO
    RCC->APB1ENR |= (1<<1);           // Habilitar TIM3

    GPIOA->CRL &= ~(0xF << 24);       // Limpiar configuración de PA6
    GPIOA->CRL |= (0xA << 24);        // Configurar PA6 como salida alternativa push-pull

    TIM3->PSC = 7;                    // Prescaler
    TIM3->ARR = 20000;                // Auto-reload register
    TIM3->CCR1 = 1000;               // Capture/Compare register 1

    TIM3->CCMR1 &= ~(0xFF << 0);      // Limpiar bits
    TIM3->CCMR1 |= (0x68 << 0);       // Configurar como PWM mode 1 en CH1

    TIM3->CCER |= (1 << 0);           // Habilitar salida en CH1
    TIM3->CR1 |= (1 << 7) | (1 << 0); // Auto-reload preload enable y counter enable
}