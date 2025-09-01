int main(){
  DDRD = 0b00000011;
  while(1){
    PORTD = 0b00000001;
    _delay_ms(500);
    PORTD = 0b00000010;
    _delay_ms(500);
    PORTD = 0b00000000;
    _delay_ms(500);
 
  }
}