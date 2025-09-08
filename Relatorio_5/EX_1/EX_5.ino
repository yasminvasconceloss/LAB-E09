int main() {
  // Motor = PD3, Alarme = PD6
  // Liga = PD2, Desliga = PD4, Sensor = PD5

  DDRD = DDRD | 0b01001000;    // PD3 e PD6 --> saída
  DDRD = DDRD & ~(0b00110100); // PD2, PD4 e PD5 --> entrada

  PORTD = PORTD | 0b00110100;  // pull-up em Liga, Desliga e Sensor
  PORTD = PORTD & ~(0b01001000); // Motor e Alarme inicialmente LOW

  for () {
    int liga    = PIND & 0b00000100; // PD2
    int desliga = PIND & 0b00010000; // PD4
    int sensor  = PIND & 0b00100000; // PD5

    // Se sensor detecta peça (HIGH) --> motor desliga, alarme liga

    if (sensor) {
      PORTD &= ~(0b00001000); // Motor off
      PORTD |=  (0b01000000); // Alarme on
    }

    // Botão Desliga --> motor desliga
    else if (desliga == 0) {
      PORTD &= ~(0b00001000); // Motor off
    }

    // Botão Liga --> motor liga e alarme desliga (se sensor estiver livre)
    else if (liga == 0) {
      PORTD |=  (0b00001000); // Motor on
      PORTD &= ~(0b01000000); // Alarme off
    }
  }
}