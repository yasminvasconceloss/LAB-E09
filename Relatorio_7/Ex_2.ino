ISR(INT0_vect){
  // Inverte a saída 4 (PD4)
  PORTD ^= 0b00010000;
  _delay_ms(1000);
  PORTD ^= 0b00010000;
}
 
ISR(INT1_vect){
 // Habilta/desabilita INT0
 EIMSK ^= 0b00000001;
}
 
int main(void){
  DDRD = 0b00110000;
  // Habilita o resistor interno de pull-up no pino 2 (PD2)
  PORTD = 0b00001100;
  // Configura a interrupção externa 1 para transição de descida
  EICRA = 0b00001010;
  // Habilita a interrupção externa 1
  EIMSK = 0b00000011;
  // Habilita a interrupção global
  sei();
  //Super loop
  while (1){
    // Inverte a saída 5 (PD5)
    PORTD ^= 0b00100000;
    _delay_ms(500);
  }
}