#include <stdio.h>
#include "pico/stdlib.h" // Uso da biblioteca padrão para o Raspberry Pi Pico W

#define LED_PIN 11 //Este é o pino GPIO a qual o LED está conectado. 
#define PONTO 200 // Duração do ponto (.) em ms
#define TRACO 800 // Duração do traço (-) em ms
#define Intervalo 3000 // Intervalo de 3 segundos entre cada Sinal SOS


//Função para piscar o LED (pontos)

void pisca_ponto( int duracao) {
    gpio_put(LED_PIN,1);
    sleep_ms(duracao);
    gpio_put(LED_PIN,0);
    sleep_ms(duracao);
}

void pisca_traco( int duracao) {
    gpio_put(LED_PIN,1);
    sleep_ms(duracao);
    gpio_put(LED_PIN,0);
    sleep_ms(duracao);
}

int main()
{
    stdio_init_all(); // Sempre chamar esta função. Inicializa as funções padrão do micro
    gpio_init(LED_PIN); //iNICIALIZA A PORTA 11, ONDE ESTÁ O PINO. 
    gpio_set_dir(LED_PIN,GPIO_OUT); //Após inicializado, definir o pino como SAÍDA.

    while (true) {
        for (int  i=0; i<3; i++){
            pisca_ponto(200);
            sleep_ms(125);
        }
        sleep_ms(250); //Intervalo de 0,25s até o traço

        for (int  i=0; i<3; i++){
            pisca_traco(800);
            sleep_ms(125);
        }
        sleep_ms(250);

        for (int  i=0; i<3; i++){
            pisca_ponto(200);
            sleep_ms(125);
        }
        sleep_ms(3000);
    }
        return 0;
}
