int main(){
  DDRD = DDRD | 0b11000000;
  PORTD = PORTD | 0b00110000;
  PORTD &= ~(0b11000000);
 
  for(;;){
    int botao = PIND & 0b00100000;
    int botao2 = PIND & 0b00010000;
 
    if(botao == 0){
      PORTD = PORTD | 0b10000000;
      _delay_ms(1000);
      PORTD &= ~(0b10000000);
      PORTD = PORTD | 0b01000000;
      _delay_ms(1000);
      PORTD &= ~(0b01000000);
    }
    if(botao2 == 0){
      PORTD = PORTD | 0b10000000;
      _delay_ms(100);
      PORTD &= ~(0b10000000);
      PORTD = PORTD | 0b01000000;
      _delay_ms(100);
      PORTD &= ~(0b01000000);
    }
  }
}