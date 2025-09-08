#include <avr/io.h>
#include <util/delay.h>

int main(void) {
    // LED Vermelho -> PB0
    // LED Amarelo  -> PB1
    // LED Azul     -> PB2
    // Botão        -> PD2

    DDRB |= (1 << PB0) | (1 << PB1) | (1 << PB2); // define PB0, PB1, PB2 como saída
    DDRD &= ~(1 << PD2); // define PD2 como entrada
    PORTD |= (1 << PD2); // pull-up interno no botão

    int estado = 0; // 0 = vermelho, 1 = azul

    // Estado inicial: vermelho aceso
    PORTB |= (1 << PB0);  
    PORTB &= ~((1 << PB1) | (1 << PB2));

    while (1) {
        // Verificando se o botão foi pressionado (LOW em PD2)
        if (!(PIND & (1 << PD2))) {
            _delay_ms(200); 

            if (estado == 0) {
                // Pisca o amarelo por 3 segundos
                for (int i = 0; i < 3; i++) {
                    PORTB |= (1 << PB1);   // liga amarelo
                    _delay_ms(500);
                    PORTB &= ~(1 << PB1);  // desliga amarelo
                    _delay_ms(500);
                }

                // Liga azul
                PORTB &= ~(1 << PB0); // desliga vermelho
                PORTB &= ~(1 << PB1); // desliga amarelo
                PORTB |= (1 << PB2);  // liga azul
                estado = 1;
            }
            else {
                // Voltando para vermelho
                PORTB |= (1 << PB0);
                PORTB &= ~((1 << PB1) | (1 << PB2));
                estado = 0;
            }
        }
    }

    return 0;
}