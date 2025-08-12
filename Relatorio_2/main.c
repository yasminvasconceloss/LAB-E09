#include <avr/io.h>
#include <util/delay.h>

/*Para representar o funcionamento de um semáforo de trânsito, crie uma máquina de
estados, sabendo que:
O tempo de cada estado é: Verde – 12s / Amarelo – 3s / Vermelho – 15s 

Desenvolva um código que obedeça ao diagrama de estados.
Utilize variáveis com nomes objetivos para ilustrar os estados. Compile o projeto e
execute para conferir a lógica elaborada na máquina de estados.
*/


// Definindo os estados
#define VERDE    0
#define AMARELO  1
#define VERMELHO 2

// Tempos em ms
#define TEMPO_VERDE    12000
#define TEMPO_AMARELO  3000
#define TEMPO_VERMELHO 15000

unsigned char estado_atual = VERDE;

int main(void)
{
    for (;;)
    {
        switch (estado_atual)
        {
            case VERDE:
                _delay_ms(TEMPO_VERDE);
                estado_atual = AMARELO;
                break;

            case AMARELO:
                _delay_ms(TEMPO_AMARELO);
                estado_atual = VERMELHO;
                break;

            case VERMELHO:
                _delay_ms(TEMPO_VERMELHO);
                estado_atual = VERDE;
                break;

            default:
                estado_atual = VERDE;
                break;
        }
    }
}