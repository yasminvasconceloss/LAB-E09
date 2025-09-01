int main(){
  DDRD = DDRD | 0b11000000;
  PORTD = PORTD | 0b00100000;
  unsigned char posicao = 0;
  while(1){
    int botao = PIND & 0b00100000;
   
    if(botao == 0){
      posicao++;
      _delay_ms(500);
     
    }
     switch(posicao){
      case 1:
        PORTD = 0b01000000;
        break;
      case 2:
        PORTD = 0b10000000;
        break;
      case 3:
        PORTD = 0b00000000;
        break;
      default:
        posicao=1;
        break;
      }
   
 
  }
}