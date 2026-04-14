/*FADE QUE VAI DO ROSA ATÉ O AZUL E VOLTA
#include <zephyr/kernel.h>             // Funções básicas do Zephyr (ex: k_msleep, k_thread, etc.)
#include <zephyr/device.h>             // API para obter e utilizar dispositivos do sistema
#include <zephyr/drivers/gpio.h>       // API para controle de pinos de entrada/saída (GPIO)
#include <pwm_z42.h>                // Biblioteca personalizada com funções de controle do TPM (Timer/PWM Module)

// Define o valor do registrador MOD do TPM para configurar o período do PWM
#define TPM_MODULE 1000         // Define a frequência do PWM fpwm = (TPM_CLK / (TPM_MODULE * PS))
// Valores de duty cycle correspondentes a diferentes larguras de pulso

void delayMs(int n);

uint16_t duty_0  = 0;
uint16_t duty_10  = TPM_MODULE*0.1;
uint16_t duty_20  = TPM_MODULE*0.2;
uint16_t duty_30  = TPM_MODULE*0.3;
uint16_t duty_40  = TPM_MODULE*0.4;
uint16_t duty_50  = TPM_MODULE/2;     // 50% de duty cycle (meio brilho)
uint16_t duty_60  = TPM_MODULE*0.6;
uint16_t duty_70  = TPM_MODULE*0.7;
uint16_t duty_80  = TPM_MODULE*0.8;
uint16_t duty_90  = TPM_MODULE*0.9;
uint16_t duty_100  = TPM_MODULE*1.0;

int main(void)
{
    // Inicializa o módulo TPM2 com:
    // - base do TPMx
    // - fonte de clock PLL/FLL (TPM_CLK)
    // - valor do registrador MOD
    // - tipo de clock (TPM_CLK)
    // - prescaler de 1 a 128 (PS)
    // - modo de operação EDGE_PWM
    pwm_tpm_Init(TPM2, TPM_PLLFLL, TPM_MODULE, TPM_CLK, PS_128, EDGE_PWM);   
    pwm_tpm_Init(TPM0, TPM_PLLFLL, TPM_MODULE, TPM_CLK, PS_128, EDGE_PWM);

    // Inicializa o canal 0 do TPM2 para gerar sinal PWM na porta GPIOB_18
    // - modo TPM_PWM_H (nível alto durante o pulso)
    //pwm_tpm_Ch_Init(TPM2, 1, TPM_PWM_H, GPIOB, 19); //verde
    pwm_tpm_Ch_Init(TPM2, 0, TPM_PWM_H, GPIOB, 18); //vermelho
    pwm_tpm_Ch_Init(TPM0, 1, TPM_PWM_H, GPIOD, 1); //azul PORTA D
    // Define o valor do duty cycle: nesse caso, duty_100 (LED quase desligado)
    pwm_tpm_CnV(TPM2, 0, duty_0); //vermelho ligado
    pwm_tpm_CnV(TPM0, 1, duty_0); //azul ligado

    // Loop infinito
    for (;;)
    {
        // O programa poderia alterar o duty cycle dinamicamente aqui se desejado
        delayMs(500);
        pwm_tpm_CnV(TPM2, 0, duty_0);
        delayMs(500);
        pwm_tpm_CnV(TPM2, 0, duty_10);
        delayMs(500);
        pwm_tpm_CnV(TPM2, 0, duty_20);
        delayMs(500);
        pwm_tpm_CnV(TPM2, 0, duty_30);
        delayMs(500);
        pwm_tpm_CnV(TPM2, 0, duty_40);
        delayMs(500);
        pwm_tpm_CnV(TPM2, 0, duty_50);
        delayMs(500);
        pwm_tpm_CnV(TPM2, 0, duty_60);
        delayMs(500);
        pwm_tpm_CnV(TPM2, 0, duty_70);
        delayMs(500);
        pwm_tpm_CnV(TPM2, 0, duty_80);
        delayMs(500);
        pwm_tpm_CnV(TPM2, 0, duty_90);
        delayMs(500);
        pwm_tpm_CnV(TPM2, 0, duty_100);
        delayMs(500);
        pwm_tpm_CnV(TPM2, 0, duty_90);
        delayMs(500);
        pwm_tpm_CnV(TPM2, 0, duty_80);
        delayMs(500);
        pwm_tpm_CnV(TPM2, 0, duty_70);
        delayMs(500);
        pwm_tpm_CnV(TPM2, 0, duty_60);
        delayMs(500);
        pwm_tpm_CnV(TPM2, 0, duty_50);
        delayMs(500);
        pwm_tpm_CnV(TPM2, 0, duty_40);
        delayMs(500);
        pwm_tpm_CnV(TPM2, 0, duty_30);
        delayMs(500);
        pwm_tpm_CnV(TPM2, 0, duty_20);
        delayMs(500);
        pwm_tpm_CnV(TPM2, 0, duty_10);
        delayMs(500);
        pwm_tpm_CnV(TPM2, 0, duty_0);
    }

    return 0;
}

//criar o clock
void delayMs(int n) {
   volatile int i;
    volatile int j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < 7000; j++) {
        }
    }
}
*/
//fade de rosa
#include <zephyr/kernel.h>             // Funções básicas do Zephyr (ex: k_msleep, k_thread, etc.)
#include <zephyr/device.h>             // API para obter e utilizar dispositivos do sistema
#include <zephyr/drivers/gpio.h>       // API para controle de pinos de entrada/saída (GPIO)
#include <pwm_z42.h>                // Biblioteca personalizada com funções de controle do TPM (Timer/PWM Module)

// Define o valor do registrador MOD do TPM para configurar o período do PWM
#define TPM_MODULE 1000         // Define a frequência do PWM fpwm = (TPM_CLK / (TPM_MODULE * PS))
// Valores de duty cycle correspondentes a diferentes larguras de pulso

void delayMs(int n);

int main(void)
{
    // Inicializa o módulo TPM2 com:
    // - base do TPMx
    // - fonte de clock PLL/FLL (TPM_CLK)
    // - valor do registrador MOD
    // - tipo de clock (TPM_CLK)
    // - prescaler de 1 a 128 (PS)
    // - modo de operação EDGE_PWM
    pwm_tpm_Init(TPM2, TPM_PLLFLL, TPM_MODULE, TPM_CLK, PS_128, EDGE_PWM);   
    pwm_tpm_Init(TPM0, TPM_PLLFLL, TPM_MODULE, TPM_CLK, PS_128, EDGE_PWM);

    // Inicializa o canal 0 do TPM2 para gerar sinal PWM na porta GPIOB_18
    // - modo TPM_PWM_H (nível alto durante o pulso)
    //pwm_tpm_Ch_Init(TPM2, 1, TPM_PWM_H, GPIOB, 19); //verde
    pwm_tpm_Ch_Init(TPM2, 0, TPM_PWM_H, GPIOB, 18); //vermelho
    pwm_tpm_Ch_Init(TPM0, 1, TPM_PWM_H, GPIOD, 1); //azul PORTA D
    // Define o valor do duty cycle: nesse caso, duty_100 (LED quase desligado)
    
   // uint16_t duty_0  = 0;
   // uint16_t duty_65  = TPM_MODULE*65/100;

    //pwm_tpm_CnV(TPM2, 0, duty_0); //vermelho ligado
    //pwm_tpm_CnV(TPM0, 1, duty_65); //azul ligado

    // Loop infinito
    int n = 0;
    while(1)
    {
        uint16_t duty_n  = TPM_MODULE*n/100;
        pwm_tpm_CnV(TPM2, 0, duty_n);
        pwm_tpm_CnV(TPM0, 1, duty_n);
        k_msleep(25);
        n++;
        if(n == 100) while(1)
        {
            uint16_t duty_n  = TPM_MODULE*n/100;
            pwm_tpm_CnV(TPM2, 0, duty_n);
            pwm_tpm_CnV(TPM0, 1, duty_n);
            k_msleep(25);
            n--;
            if(n == 0) break;
        }
    }

    return 0;
}

