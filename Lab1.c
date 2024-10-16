/*
 * Lab1.c
 *
 * Created: 9/6/2024 1:27:48 PM
 * Author : pathey1590
 * Morse Code string is .--. . - . .-. / .- - .... . -.-- / .---- ...-- .---- ..--- ...-- .---- ...-- ----. -....
 */ 

#define F_CPU 16000000UL // 16MHz clock from the debug processor
#include <avr/io.h>
#include <util/delay.h>
#include <string.h>


void morseTranslate(int c){
	if (c == 'A' || c == 'a'){
		dot();
		dash();
	}
	else if (c == 'B' || c == 'b'){
		dash();
		dot();
		dot();
		dot();
	}
	else if (c == 'C' || c == 'c'){
		dash();
		dot();
		dash();
		dot();
	}
	else if (c == 'D' || c == 'd'){
		dash();
		dot();
		dot();
	}
	else if (c == 'E' || c == 'e'){
		dot();
	}
	else if (c == 'F' || c == 'f'){
		dot();
		dot();
		dash();
		dot();
	}
	else if (c == 'G' || c == 'g'){
		dash();
		dash();
		dot();
	}
	else if (c == 'H' || c == 'h'){
		dot();
		dot();
		dot();
		dot();
	}
	else if (c == 'I' || c == 'i'){
		dot();
		dot();
	}
	else if (c == 'J' || c == 'j'){
		dot();
		dash();
		dash();
		dash();
	}
	else if (c == 'K' || c == 'k'){
		dash();
		dot();
		dash();
	}
	else if (c == 'L' || c == 'l'){
		dot();
		dash();
		dot();
		dot();
	}
	else if (c == 'M' || c == 'm'){
		dash();
		dash();
	}
	else if (c == 'N' || c == 'n'){
		dash();
		dot();
	}
	else if (c == 'O' || c == 'o'){
		dash();
		dash();
		dash();
	}
	else if (c == 'P' || c == 'p'){
		dot();
		dash();
		dash();
		dot();
	}
	else if (c == 'Q' || c == 'q'){
		dash();
		dash();
		dot();
		dash();
	}
	else if (c == 'R' || c == 'r'){
		dot();
		dash();
		dot();
	}
	else if (c == 'S' || c == 's'){
		dot();
		dot();
		dot();
	}
	else if (c == 'T' || c == 't'){
		dash();
	}
	else if (c == 'U' || c == 'u'){
		dot();
		dot();
		dash();
	}
	else if (c == 'V' || c == 'v'){
		dot();
		dot();
		dot();
		dash();
	}
	else if (c == 'W' || c == 'w'){
		dot();
		dash();
		dash();
	}
	else if (c == 'X' || c == 'x'){
		dash();
		dot();
		dot();
		dash();
	}
	else if (c == 'Y' || c == 'y'){
		dash();
		dot();
		dash();
		dash();
	}
	else if (c == 'Z' || c == 'z'){
		dash();
		dash();
		dot();
		dot();
	}
	else if (c == '1'){
		dot();
		dash();
		dash();
		dash();
		dash();
	}
	else if (c == '2'){
		dot();
		dot();
		dash();
		dash();
		dash();
	}
	else if (c == '3'){
		dot();
		dot();
		dot();
		dash();
		dash();
	}
	else if (c == '4'){
		dot();
		dot();
		dot();
		dot();
		dash();
	}
	else if (c == '5'){
		dot();
		dot();
		dot();
		dot();
		dot();
	}
	else if (c == '6'){
		dash();
		dot();
		dot();
		dot();
		dot();
	}
	else if (c == '7'){
		dash();
		dash();
		dot();
		dot();
		dot();
	}
	else if (c == '8'){
		dash();
		dash();
		dash();
		dot();
		dot();
	}
	else if (c == '9'){
		dash();
		dash();
		dash();
		dash();
		dot();
	}
	else if (c == '0'){
		dash();
		dash();
		dash();
		dash();
		dash();
	}
	else if(c == ' '){
		spc();
	}
	PORTB &= ~(1<<PORTB5); //Clear port bit B5 to 0 to turn off the LED
	_delay_ms(400);
}

void dot(){
	PORTB |= (1<<PORTB5); //Set port bit B5 to 1 to turn on the LED
	_delay_ms(200); //delay 100ms
	PORTB &= ~(1<<PORTB5); //Clear port bit B5 to 0 to turn off the LED
	_delay_ms(200);
}

void dash(){
	PORTB |= (1<<PORTB5); //Set port bit B5 to 1 to turn on the LED
	_delay_ms(600); //delay 100ms
	PORTB &= ~(1<<PORTB5); //Clear port bit B5 to 0 to turn off the LED
	_delay_ms(200);
}

void spc(){
	PORTB &= ~(1<<PORTB5); //Clear port bit B5 to 0 to turn off the LED
	_delay_ms(800);
}

int main(void)
{
	/* Replace with your application code */
	DDRB |= (1<<DDB5); //0x20 (hex) // Set port bit B5 in data direction register to 1: an OUTput
	int m = '\0';
	unsigned char k[21];
	strcpy(k,"Peter Athey 131231396");
	int i = 0;
	while(1){
		if(i == 21){
			i = 0;
			continue;
		}
		
		morseTranslate(k[i]);
		
		i += 1;
	}
}
