int x;

void main() {
  ANSELA= 0xFF;           //Set port A as analog and the rest as digital.
  ANSELB= 0x00;
  ANSELC= 0x00;
  ANSELD= 0x00;

  TRISA= 0xFF;              //Set port A as input and the rest as output.
  TRISB= 0x00;
  TRISC= 0x00;
  TRISD= 0x00;

  UART1_Init(9600);        //Initilize UART monitor.
  Delay_ms(1000);
  while (1) {              //Endless loop
  x = ADC_Read(1);         //Reads analogue input from RA1
  if (x<1500) {
  UART_Write("The lights are off, LED's will turn on"); //writes to UART monitor
  PORTB= 0xFF;          //Turn on all LED's
  PORTC= 0xFF;
  PORTD= 0xFF;
  Delay_ms(100);
  }
  else {
  UART_Write("The lights are on, LED's will turn off");
  PORTB= 0x00;            //Turn off all LED's
  PORTC= 0x00;
  PORTD= 0x00;
  Delay_ms(100);
}
}
}