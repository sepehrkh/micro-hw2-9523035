#include "lm016.h"
#include "stm32f4xx_hal_gpio.h"
//Rs HD7 HD6 HD5 HD4 LD3 LD2 LD1 LD0
void lcd_init(lcd_t * lcd){

	for(int i = 0; i <= 7; i++){
			HAL_GPIO_WritePin(lcd->data_ports[i], lcd->data_pins[i], GPIO_PIN_RESET);
	}
	HAL_GPIO_WritePin(lcd->en_port, lcd->en_pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(lcd->rs_port, lcd->rs_pin, GPIO_PIN_RESET);
	HAL_Delay(500);
	//lcd initialization:
	lcd_putchar(lcd,0x33);
	lcd_putchar(lcd,0x32);
	//lcd Functionset:
	if(lcd->mode == 1)
		lcd_putchar(lcd,0x28);
	else
		lcd_putchar(lcd,0x38);
	//Display on:
	lcd_putchar(lcd,0x0E);
	//Entry mode:
	lcd_putchar(lcd,0x06);
	//lcd clear:
	lcd_putchar(lcd,0x01);
	//Return home:
	lcd_putchar(lcd,0x02);
}


void lcd_putchar(lcd_t * lcd, uint8_t character){
			HAL_Delay(1);
			
			if((character & 0x100) == 0x100)
			HAL_GPIO_WritePin(lcd->rs_port, lcd->rs_pin, GPIO_PIN_SET);
			else
			HAL_GPIO_WritePin(lcd->rs_port, lcd->rs_pin, GPIO_PIN_RESET);
			
			if((character & 0x80) == 0x80)
			HAL_GPIO_WritePin(lcd->data_ports[7], lcd->data_pins[7], GPIO_PIN_SET);
			else
			HAL_GPIO_WritePin(lcd->data_ports[7], lcd->data_pins[7], GPIO_PIN_RESET);
			
			if((character & 0x40) == 0x40)
			HAL_GPIO_WritePin(lcd->data_ports[6], lcd->data_pins[6], GPIO_PIN_SET);
			else
			HAL_GPIO_WritePin(lcd->data_ports[6], lcd->data_pins[6], GPIO_PIN_RESET);
			
			if((character & 0x20) == 0x20)
			HAL_GPIO_WritePin(lcd->data_ports[5], lcd->data_pins[5], GPIO_PIN_SET);
			else
			HAL_GPIO_WritePin(lcd->data_ports[5], lcd->data_pins[5], GPIO_PIN_RESET);
			
			if((character & 0x10) == 0x10)
			HAL_GPIO_WritePin(lcd->data_ports[4], lcd->data_pins[4], GPIO_PIN_SET);
			else
			HAL_GPIO_WritePin(lcd->data_ports[4], lcd->data_pins[4], GPIO_PIN_RESET);
			
			if(lcd -> mode == 0 ){
				
			if((character & 0x08) == 0x08)
			HAL_GPIO_WritePin(lcd->data_ports[3], lcd->data_pins[3], GPIO_PIN_SET);
			else
			HAL_GPIO_WritePin(lcd->data_ports[3], lcd->data_pins[3], GPIO_PIN_RESET);
			
			if((character & 0x04) == 0x04)
			HAL_GPIO_WritePin(lcd->data_ports[2], lcd->data_pins[2], GPIO_PIN_SET);
			else
			HAL_GPIO_WritePin(lcd->data_ports[2], lcd->data_pins[2], GPIO_PIN_RESET);
			
			if((character & 0x02) == 0x02)
			HAL_GPIO_WritePin(lcd->data_ports[1], lcd->data_pins[1], GPIO_PIN_SET);
			else
			HAL_GPIO_WritePin(lcd->data_ports[1], lcd->data_pins[1], GPIO_PIN_RESET);
			
			if((character & 0x01) == 0x01)
			HAL_GPIO_WritePin(lcd->data_ports[0], lcd->data_pins[0], GPIO_PIN_SET);
			else
			HAL_GPIO_WritePin(lcd->data_ports[0], lcd->data_pins[0], GPIO_PIN_RESET);
			}
			HAL_Delay(1);
			HAL_GPIO_WritePin(lcd->en_port, lcd->en_pin, GPIO_PIN_SET);
			HAL_Delay(2);
			HAL_GPIO_WritePin(lcd->en_port, lcd->en_pin, GPIO_PIN_RESET);
			HAL_Delay(30);
			
			for(int i = 0; i <= 7; i++){
				HAL_GPIO_WritePin(lcd->data_ports[i], lcd->data_pins[i], GPIO_PIN_RESET);
			}
			HAL_GPIO_WritePin(lcd->en_port, lcd->en_pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(lcd->rs_port, lcd->rs_pin, GPIO_PIN_RESET);
			
			if(lcd -> mode == 1 ){
				
			if((character & 0x100) == 0x100)
			HAL_GPIO_WritePin(lcd->rs_port, lcd->rs_pin, GPIO_PIN_SET);
			else
			HAL_GPIO_WritePin(lcd->rs_port, lcd->rs_pin, GPIO_PIN_RESET);
				
			if((character & 0x08) == 0x08)
			HAL_GPIO_WritePin(lcd->data_ports[7], lcd->data_pins[7], GPIO_PIN_SET);
			else
			HAL_GPIO_WritePin(lcd->data_ports[7], lcd->data_pins[7], GPIO_PIN_RESET);
			
			if((character & 0x04) == 0x04)
			HAL_GPIO_WritePin(lcd->data_ports[6], lcd->data_pins[6], GPIO_PIN_SET);
			else
			HAL_GPIO_WritePin(lcd->data_ports[6], lcd->data_pins[6], GPIO_PIN_RESET);
			
			if((character & 0x02) == 0x02)
			HAL_GPIO_WritePin(lcd->data_ports[5], lcd->data_pins[5], GPIO_PIN_SET);
			else
			HAL_GPIO_WritePin(lcd->data_ports[5], lcd->data_pins[5], GPIO_PIN_RESET);
			
			if((character & 0x01) == 0x01)
			HAL_GPIO_WritePin(lcd->data_ports[4], lcd->data_pins[4], GPIO_PIN_SET);
			else
			HAL_GPIO_WritePin(lcd->data_ports[4], lcd->data_pins[4], GPIO_PIN_RESET);
			}
			HAL_Delay(1);
			HAL_GPIO_WritePin(lcd->en_port, lcd->en_pin, GPIO_PIN_SET);
			HAL_Delay(2);
			HAL_GPIO_WritePin(lcd->en_port, lcd->en_pin, GPIO_PIN_RESET);
			HAL_Delay(30);
			
			for(int i = 0; i <= 7; i++){
				HAL_GPIO_WritePin(lcd->data_ports[i], lcd->data_pins[i], GPIO_PIN_RESET);
			}
			HAL_GPIO_WritePin(lcd->en_port, lcd->en_pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(lcd->rs_port, lcd->rs_pin, GPIO_PIN_RESET);
}
void lcd_set_curser(lcd_t * lcd, uint16_t row, uint16_t col){
	
}
void lcd_clear(lcd_t * lcd){
	
}
void lcd_puts(lcd_t * lcd, char* str){
	
}
