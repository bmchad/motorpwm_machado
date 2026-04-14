#include <zephyr/kernel.h>             // Funções básicas do Zephyr (ex: k_msleep, k_thread, etc.)
#include <zephyr/device.h>             // API para obter e utilizar dispositivos do sistema
#include <zephyr/drivers/gpio.h>       // API para controle de pinos de entrada/saída (GPIO)
#include <pwm_z42.h>                // Biblioteca personalizada com funções de controle do TPM (Timer/PWM Module)

// Define o valor do registrador MOD do TPM para configurar o período do PWM
#define TPM_MODULE 1000         // Define a frequência do PWM fpwm = (TPM_CLK / (TPM_MODULE * PS))
// Valores de duty cycle correspondentes a diferentes larguras de pulso

void delayMs(int n);

uint16_t duty_0 = TPM_MODULE*0/100;
/*
uint16_t duty_1 = TPM_MODULE*1/100;
uint16_t duty_2 = TPM_MODULE*2/100;
uint16_t duty_3 = TPM_MODULE*3/100;
uint16_t duty_4 = TPM_MODULE*4/100;
uint16_t duty_5 = TPM_MODULE*5/100;
uint16_t duty_6 = TPM_MODULE*6/100;
uint16_t duty_7 = TPM_MODULE*7/100;
uint16_t duty_8 = TPM_MODULE*8/100;
uint16_t duty_9 = TPM_MODULE*9/100;
uint16_t duty_10 = TPM_MODULE*10/100;
uint16_t duty_11 = TPM_MODULE*11/100;
uint16_t duty_12 = TPM_MODULE*12/100;
uint16_t duty_13 = TPM_MODULE*13/100;
uint16_t duty_14 = TPM_MODULE*14/100;
uint16_t duty_15 = TPM_MODULE*15/100;
uint16_t duty_16 = TPM_MODULE*16/100;
uint16_t duty_17 = TPM_MODULE*17/100;
uint16_t duty_18 = TPM_MODULE*18/100;
uint16_t duty_19 = TPM_MODULE*19/100;
uint16_t duty_20 = TPM_MODULE*20/100;
uint16_t duty_21 = TPM_MODULE*21/100;
uint16_t duty_22 = TPM_MODULE*22/100;
uint16_t duty_23 = TPM_MODULE*23/100;
uint16_t duty_24 = TPM_MODULE*24/100;
uint16_t duty_25 = TPM_MODULE*25/100;
uint16_t duty_26 = TPM_MODULE*26/100;
uint16_t duty_27 = TPM_MODULE*27/100;
uint16_t duty_28 = TPM_MODULE*28/100;
uint16_t duty_29 = TPM_MODULE*29/100;
uint16_t duty_30 = TPM_MODULE*30/100;
uint16_t duty_31 = TPM_MODULE*31/100;
uint16_t duty_32 = TPM_MODULE*32/100;
uint16_t duty_33 = TPM_MODULE*33/100;
uint16_t duty_34 = TPM_MODULE*34/100;
uint16_t duty_35 = TPM_MODULE*35/100;
uint16_t duty_36 = TPM_MODULE*36/100;
uint16_t duty_37 = TPM_MODULE*37/100;
uint16_t duty_38 = TPM_MODULE*38/100;
uint16_t duty_39 = TPM_MODULE*39/100;
uint16_t duty_40 = TPM_MODULE*40/100;
uint16_t duty_41 = TPM_MODULE*41/100;
uint16_t duty_42 = TPM_MODULE*42/100;
uint16_t duty_43 = TPM_MODULE*43/100;
uint16_t duty_44 = TPM_MODULE*44/100;
uint16_t duty_45 = TPM_MODULE*45/100;
uint16_t duty_46 = TPM_MODULE*46/100;
uint16_t duty_47 = TPM_MODULE*47/100;
uint16_t duty_48 = TPM_MODULE*48/100;
uint16_t duty_49 = TPM_MODULE*49/100;
uint16_t duty_50 = TPM_MODULE*50/100;
uint16_t duty_51 = TPM_MODULE*51/100;
uint16_t duty_52 = TPM_MODULE*52/100;
uint16_t duty_53 = TPM_MODULE*53/100;
uint16_t duty_54 = TPM_MODULE*54/100;
uint16_t duty_55 = TPM_MODULE*55/100;
uint16_t duty_56 = TPM_MODULE*56/100;
uint16_t duty_57 = TPM_MODULE*57/100;
uint16_t duty_58 = TPM_MODULE*58/100;
uint16_t duty_59 = TPM_MODULE*59/100;
uint16_t duty_60 = TPM_MODULE*60/100;
uint16_t duty_61 = TPM_MODULE*61/100;
uint16_t duty_62 = TPM_MODULE*62/100;
uint16_t duty_63 = TPM_MODULE*63/100;
uint16_t duty_64 = TPM_MODULE*64/100;
uint16_t duty_65 = TPM_MODULE*65/100;
uint16_t duty_66 = TPM_MODULE*66/100;
uint16_t duty_67 = TPM_MODULE*67/100;
uint16_t duty_68 = TPM_MODULE*68/100;
uint16_t duty_69 = TPM_MODULE*69/100;
uint16_t duty_70 = TPM_MODULE*70/100;
uint16_t duty_71 = TPM_MODULE*71/100;
uint16_t duty_72 = TPM_MODULE*72/100;
uint16_t duty_73 = TPM_MODULE*73/100;
uint16_t duty_74 = TPM_MODULE*74/100;
uint16_t duty_75 = TPM_MODULE*75/100;
uint16_t duty_76 = TPM_MODULE*76/100;
uint16_t duty_77 = TPM_MODULE*77/100;
uint16_t duty_78 = TPM_MODULE*78/100;
uint16_t duty_79 = TPM_MODULE*79/100;
uint16_t duty_80 = TPM_MODULE*80/100;
uint16_t duty_81 = TPM_MODULE*81/100;
uint16_t duty_82 = TPM_MODULE*82/100;
uint16_t duty_83 = TPM_MODULE*83/100;
uint16_t duty_84 = TPM_MODULE*84/100;
uint16_t duty_85 = TPM_MODULE*85/100;
uint16_t duty_86 = TPM_MODULE*86/100;
uint16_t duty_87 = TPM_MODULE*87/100;
uint16_t duty_88 = TPM_MODULE*88/100;
uint16_t duty_89 = TPM_MODULE*89/100;
uint16_t duty_90 = TPM_MODULE*90/100;
uint16_t duty_91 = TPM_MODULE*91/100;
uint16_t duty_92 = TPM_MODULE*92/100;
uint16_t duty_93 = TPM_MODULE*93/100;
uint16_t duty_94 = TPM_MODULE*94/100;
uint16_t duty_95 = TPM_MODULE*95/100;
uint16_t duty_96 = TPM_MODULE*96/100;
uint16_t duty_97 = TPM_MODULE*97/100;
uint16_t duty_98 = TPM_MODULE*98/100;
uint16_t duty_99 = TPM_MODULE*99/100;
*/
uint16_t duty_100 = TPM_MODULE*100/100;
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

    //ptd3 - in1 -> motor a direto
//ptd2  - in2 -> motor a reverso
//ptd0 - in3 -> motor b direto
//ptd5 - in4 -> motor b reverso

    pwm_tpm_Ch_Init(TPM0, 3, TPM_PWM_H, GPIOD, 3); 
    pwm_tpm_Ch_Init(TPM0, 2, TPM_PWM_H, GPIOD, 2); 
    pwm_tpm_Ch_Init(TPM0, 0, TPM_PWM_H, GPIOD, 0); 
    pwm_tpm_Ch_Init(TPM0, 5, TPM_PWM_H, GPIOD, 5); 
    // Define o valor do duty cycle: nesse caso, duty_100 (LED quase desligado)

    // Loop infinito
    int n = 0;
    while(1){
        uint16_t duty_n  = TPM_MODULE*n/100;
        while(1){
        //acelerar para frente, manter maximo por 3 segundos, desacelerar para frente
                uint16_t duty_n  = TPM_MODULE*n/100;
        pwm_tpm_CnV(TPM0, 3, duty_n);
        pwm_tpm_CnV(TPM0, 2, duty_0);
        pwm_tpm_CnV(TPM0, 0, duty_n);
        pwm_tpm_CnV(TPM0, 5, duty_0);
        k_msleep(50);
        n++;
        if(n == 100) {
            k_msleep(3000);
            while(1){
            //desacelerar para trás
            uint16_t duty_n  = TPM_MODULE*n/100;
            pwm_tpm_CnV(TPM0, 3, duty_n);
            pwm_tpm_CnV(TPM0, 2, duty_0);
            pwm_tpm_CnV(TPM0, 0, duty_n);
            pwm_tpm_CnV(TPM0, 5, duty_0);
            k_msleep(50);
            n--;
            if(n == 0) break;
        }
        if(n == 0) break;
        }
    }
    //acelerar para trás, manter maximo por 3 segundos, desacelerar para trás

        while(1){
                    uint16_t duty_n  = TPM_MODULE*n/100;
        pwm_tpm_CnV(TPM0, 3, duty_0);
        pwm_tpm_CnV(TPM0, 2, duty_n);
        pwm_tpm_CnV(TPM0, 0, duty_0);
        pwm_tpm_CnV(TPM0, 5, duty_n);
        k_msleep(50);
        n++;
        if(n == 100){
            k_msleep(3000);
             while(1){
            //desacelerar para frente
            uint16_t duty_n  = TPM_MODULE*n/100;
            pwm_tpm_CnV(TPM0, 3, duty_0);
            pwm_tpm_CnV(TPM0, 2, duty_n);
            pwm_tpm_CnV(TPM0, 0, duty_0);
            pwm_tpm_CnV(TPM0, 5, duty_n);
            k_msleep(50);
            n--;
            if(n == 0) break;
        }
    }
        if(n == 0) break;
        }
    }
return 0;
}