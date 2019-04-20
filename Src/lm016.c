#include "lm016.h"
#include "stm32f4xx_hal_gpio.h"

int c = 0;
void lcd_init(lcd_t * lcd){
	HAL_GPIO_WritePin(lcd->en_port, lcd->en_pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(lcd->rs_port, lcd->rs_pin, GPIO_PIN_RESET);
	for(int i = 0; i <= 7; i++){
		HAL_GPIO_WritePin(lcd->data_ports[i], lcd->data_pins[i], GPIO_PIN_RESET);
	}
	HAL_Delay(500);
	//lcd initialization:
	HAL_GPIO_WritePin(lcd->data_ports[4], lcd->data_pins[4], GPIO_PIN_SET);
	HAL_GPIO_WritePin(lcd->data_ports[5], lcd->data_pins[5], GPIO_PIN_SET);
	HAL_Delay(1);
	HAL_GPIO_WritePin(lcd->en_port, lcd->en_pin, GPIO_PIN_SET);
	HAL_Delay(5);
	HAL_GPIO_WritePin(lcd->en_port, lcd->en_pin, GPIO_PIN_RESET);
	HAL_Delay(5);
	
	HAL_GPIO_WritePin(lcd->data_ports[4], lcd->data_pins[4], GPIO_PIN_RESET);
	HAL_GPIO_WritePin(lcd->data_ports[5], lcd->data_pins[5], GPIO_PIN_RESET);
	
	HAL_GPIO_WritePin(lcd->data_ports[4], lcd->data_pins[4], GPIO_PIN_SET);
	HAL_GPIO_WritePin(lcd->data_ports[5], lcd->data_pins[5], GPIO_PIN_SET);
	HAL_Delay(1);
	HAL_GPIO_WritePin(lcd->en_port, lcd->en_pin, GPIO_PIN_SET);
	HAL_Delay(5);
	HAL_GPIO_WritePin(lcd->en_port, lcd->en_pin, GPIO_PIN_RESET);
	HAL_Delay(5);
	
	HAL_GPIO_WritePin(lcd->data_ports[4], lcd->data_pins[4], GPIO_PIN_RESET);
	HAL_GPIO_WritePin(lcd->data_ports[5], lcd->data_pins[5], GPIO_PIN_RESET);
	
	HAL_GPIO_WritePin(lcd->data_ports[4], lcd->data_pins[4], GPIO_PIN_SET);
	HAL_GPIO_WritePin(lcd->data_ports[5], lcd->data_pins[5], GPIO_PIN_SET);
	HAL_Delay(1);
	HAL_GPIO_WritePin(lcd->en_port, lcd->en_pin, GPIO_PIN_SET);
	HAL_Delay(5);
	HAL_GPIO_WritePin(lcd->en_port, lcd->en_pin, GPIO_PIN_RESET);
	HAL_Delay(5);
	
	HAL_GPIO_WritePin(lcd->data_ports[4], lcd->data_pins[4], GPIO_PIN_RESET);
	HAL_GPIO_WritePin(lcd->data_ports[5], lcd->data_pins[5], GPIO_PIN_RESET);
	
	if(lcd->mode == 1){
		HAL_GPIO_WritePin(lcd->data_ports[5], lcd->data_pins[5], GPIO_PIN_SET);
		HAL_Delay(1);
		HAL_GPIO_WritePin(lcd->en_port, lcd->en_pin, GPIO_PIN_SET);
		HAL_Delay(5);
		HAL_GPIO_WritePin(lcd->en_port, lcd->en_pin, GPIO_PIN_RESET);
		HAL_Delay(5);
		HAL_GPIO_WritePin(lcd->data_ports[5], lcd->data_pins[5], GPIO_PIN_RESET);
	}
	//lcd Functionset:
	if(lcd->mode == 1){
		HAL_GPIO_WritePin(lcd->data_ports[5], lcd->data_pins[5], GPIO_PIN_SET);
		HAL_Delay(1);
		HAL_GPIO_WritePin(lcd->en_port, lcd->en_pin, GPIO_PIN_SET);
		HAL_Delay(5);
		HAL_GPIO_WritePin(lcd->en_port, lcd->en_pin, GPIO_PIN_RESET);
		HAL_Delay(5);
		
		HAL_GPIO_WritePin(lcd->data_ports[5], lcd->data_pins[5], GPIO_PIN_RESET);
		
		HAL_GPIO_WritePin(lcd->data_ports[7], lcd->data_pins[7], GPIO_PIN_SET);
		HAL_Delay(1);
		HAL_GPIO_WritePin(lcd->en_port, lcd->en_pin, GPIO_PIN_SET);
		HAL_Delay(5);
		HAL_GPIO_WritePin(lcd->en_port, lcd->en_pin, GPIO_PIN_RESET);
		HAL_Delay(5);
		HAL_GPIO_WritePin(lcd->data_ports[7], lcd->data_pins[7], GPIO_PIN_RESET);
	}
	if(lcd->mode == 0){
		HAL_GPIO_WritePin(lcd->data_ports[5], lcd->data_pins[5], GPIO_PIN_SET);
		HAL_GPIO_WritePin(lcd->data_ports[4], lcd->data_pins[4], GPIO_PIN_SET);
		HAL_GPIO_WritePin(lcd->data_ports[3], lcd->data_pins[3], GPIO_PIN_SET);
		HAL_Delay(1);
		HAL_GPIO_WritePin(lcd->en_port, lcd->en_pin, GPIO_PIN_SET);
		HAL_Delay(5);
		HAL_GPIO_WritePin(lcd->en_port, lcd->en_pin, GPIO_PIN_RESET);
		HAL_Delay(5);
		HAL_GPIO_WritePin(lcd->data_ports[5], lcd->data_pins[5], GPIO_PIN_RESET);
		HAL_GPIO_WritePin(lcd->data_ports[4], lcd->data_pins[4], GPIO_PIN_RESET);
		HAL_GPIO_WritePin(lcd->data_ports[3], lcd->data_pins[3], GPIO_PIN_RESET);
	}
	//Display on:
	if(lcd->mode == 1){
		HAL_Delay(1);
		HAL_GPIO_WritePin(lcd->en_port, lcd->en_pin, GPIO_PIN_SET);
		HAL_Delay(5);
		HAL_GPIO_WritePin(lcd->en_port, lcd->en_pin, GPIO_PIN_RESET);
		HAL_Delay(5);
	
		HAL_GPIO_WritePin(lcd->data_ports[7], lcd->data_pins[7], GPIO_PIN_SET);
		HAL_GPIO_WritePin(lcd->data_ports[6], lcd->data_pins[6], GPIO_PIN_SET);
		HAL_GPIO_WritePin(lcd->data_ports[5], lcd->data_pins[5], GPIO_PIN_SET);
		HAL_Delay(1);
		HAL_GPIO_WritePin(lcd->en_port, lcd->en_pin, GPIO_PIN_SET);
		HAL_Delay(5);
		HAL_GPIO_WritePin(lcd->en_port, lcd->en_pin, GPIO_PIN_RESET);
		HAL_Delay(5);
		HAL_GPIO_WritePin(lcd->data_ports[7], lcd->data_pins[7], GPIO_PIN_RESET);
		HAL_GPIO_WritePin(lcd->data_ports[6], lcd->data_pins[6], GPIO_PIN_RESET);
		HAL_GPIO_WritePin(lcd->data_ports[5], lcd->data_pins[5], GPIO_PIN_RESET);
	}
	if(lcd->mode == 0){
		HAL_GPIO_WritePin(lcd->data_ports[3], lcd->data_pins[3], GPIO_PIN_SET);
		HAL_GPIO_WritePin(lcd->data_ports[2], lcd->data_pins[2], GPIO_PIN_SET);
		HAL_GPIO_WritePin(lcd->data_ports[1], lcd->data_pins[1], GPIO_PIN_SET);
		HAL_Delay(1);
		HAL_GPIO_WritePin(lcd->en_port, lcd->en_pin, GPIO_PIN_SET);
		HAL_Delay(5);
		HAL_GPIO_WritePin(lcd->en_port, lcd->en_pin, GPIO_PIN_RESET);
		HAL_Delay(5);
		HAL_GPIO_WritePin(lcd->data_ports[3], lcd->data_pins[3], GPIO_PIN_RESET);
		HAL_GPIO_WritePin(lcd->data_ports[2], lcd->data_pins[2], GPIO_PIN_RESET);
		HAL_GPIO_WritePin(lcd->data_ports[1], lcd->data_pins[1], GPIO_PIN_RESET);
	}
	//Entry mode:
	if(lcd->mode == 1){
		HAL_Delay(1);
		HAL_GPIO_WritePin(lcd->en_port, lcd->en_pin, GPIO_PIN_SET);
		HAL_Delay(5);
		HAL_GPIO_WritePin(lcd->en_port, lcd->en_pin, GPIO_PIN_RESET);
		HAL_Delay(5);

		HAL_GPIO_WritePin(lcd->data_ports[6], lcd->data_pins[6], GPIO_PIN_SET);
		HAL_GPIO_WritePin(lcd->data_ports[5], lcd->data_pins[5], GPIO_PIN_SET);
		HAL_Delay(1);
		HAL_GPIO_WritePin(lcd->en_port, lcd->en_pin, GPIO_PIN_SET);
		HAL_Delay(5);
		HAL_GPIO_WritePin(lcd->en_port, lcd->en_pin, GPIO_PIN_RESET);
		HAL_Delay(5);
		HAL_GPIO_WritePin(lcd->data_ports[6], lcd->data_pins[6], GPIO_PIN_RESET);
		HAL_GPIO_WritePin(lcd->data_ports[5], lcd->data_pins[5], GPIO_PIN_RESET);
	}
	if(lcd->mode == 0){
		HAL_GPIO_WritePin(lcd->data_ports[2], lcd->data_pins[2], GPIO_PIN_SET);
		HAL_GPIO_WritePin(lcd->data_ports[1], lcd->data_pins[1], GPIO_PIN_SET);
		HAL_Delay(1);
		HAL_GPIO_WritePin(lcd->en_port, lcd->en_pin, GPIO_PIN_SET);
		HAL_Delay(5);
		HAL_GPIO_WritePin(lcd->en_port, lcd->en_pin, GPIO_PIN_RESET);
		HAL_Delay(5);
		HAL_GPIO_WritePin(lcd->data_ports[2], lcd->data_pins[2], GPIO_PIN_RESET);
		HAL_GPIO_WritePin(lcd->data_ports[1], lcd->data_pins[1], GPIO_PIN_RESET);
	}
	//lcd clear and return home:
	lcd_clear(lcd);
}

void lcd_putchar(lcd_t * lcd, uint8_t character){
			HAL_Delay(1);
			HAL_GPIO_WritePin(lcd->en_port, lcd->en_pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(lcd->rs_port, lcd->rs_pin, GPIO_PIN_RESET);
			for(int i = 0; i <= 7; i++){
				HAL_GPIO_WritePin(lcd->data_ports[i], lcd->data_pins[i], GPIO_PIN_RESET);
			}
			HAL_GPIO_WritePin(lcd->rs_port, lcd->rs_pin, GPIO_PIN_SET);
			
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
			HAL_Delay(5);
			HAL_GPIO_WritePin(lcd->en_port, lcd->en_pin, GPIO_PIN_RESET);
			HAL_Delay(5);
			
			HAL_GPIO_WritePin(lcd->en_port, lcd->en_pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(lcd->rs_port, lcd->rs_pin, GPIO_PIN_RESET);
			for(int i = 0; i <= 7; i++){
				HAL_GPIO_WritePin(lcd->data_ports[i], lcd->data_pins[i], GPIO_PIN_RESET);
			}
			if(lcd -> mode == 1 ){
			HAL_GPIO_WritePin(lcd->rs_port, lcd->rs_pin, GPIO_PIN_SET);
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
			HAL_Delay(5);
			HAL_GPIO_WritePin(lcd->en_port, lcd->en_pin, GPIO_PIN_RESET);
			HAL_Delay(5);
			
			HAL_GPIO_WritePin(lcd->en_port, lcd->en_pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(lcd->rs_port, lcd->rs_pin, GPIO_PIN_RESET);
			for(int i = 0; i <= 7; i++){
				HAL_GPIO_WritePin(lcd->data_ports[i], lcd->data_pins[i], GPIO_PIN_RESET);
			}
			c += 1;
			if (c == 16)
				lcd_set_curser(lcd,2,1);
}

void lcd_set_curser(lcd_t * lcd, uint16_t row, uint16_t col){
	HAL_GPIO_WritePin(lcd->en_port, lcd->en_pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(lcd->rs_port, lcd->rs_pin, GPIO_PIN_RESET);
	for(int i = 0; i <= 7; i++){
		HAL_GPIO_WritePin(lcd->data_ports[i], lcd->data_pins[i], GPIO_PIN_RESET);
	}
	if(row == 2){
		c = 15 + col;
		if(lcd->mode == 0){
			HAL_GPIO_WritePin(lcd->data_ports[7], lcd->data_pins[7], GPIO_PIN_SET);
			HAL_GPIO_WritePin(lcd->data_ports[6], lcd->data_pins[6], GPIO_PIN_SET);
			HAL_Delay(1);
			HAL_GPIO_WritePin(lcd->en_port, lcd->en_pin, GPIO_PIN_SET);
			HAL_Delay(5);
			HAL_GPIO_WritePin(lcd->en_port, lcd->en_pin, GPIO_PIN_RESET);
			HAL_Delay(5);
			HAL_GPIO_WritePin(lcd->data_ports[7], lcd->data_pins[7], GPIO_PIN_RESET);
			HAL_GPIO_WritePin(lcd->data_ports[6], lcd->data_pins[6], GPIO_PIN_RESET);
			for(int i=1;i<col;i++){
				HAL_GPIO_WritePin(lcd->data_ports[4], lcd->data_pins[4], GPIO_PIN_SET);
				HAL_GPIO_WritePin(lcd->data_ports[2], lcd->data_pins[2], GPIO_PIN_SET);
				HAL_Delay(1);
				HAL_GPIO_WritePin(lcd->en_port, lcd->en_pin, GPIO_PIN_SET);
				HAL_Delay(5);
				HAL_GPIO_WritePin(lcd->en_port, lcd->en_pin, GPIO_PIN_RESET);
				HAL_Delay(5);
				HAL_GPIO_WritePin(lcd->data_ports[4], lcd->data_pins[4], GPIO_PIN_RESET);
				HAL_GPIO_WritePin(lcd->data_ports[2], lcd->data_pins[2], GPIO_PIN_RESET);
			}
		}
		if(lcd->mode == 1){
			HAL_GPIO_WritePin(lcd->data_ports[7], lcd->data_pins[7], GPIO_PIN_SET);
			HAL_GPIO_WritePin(lcd->data_ports[6], lcd->data_pins[6], GPIO_PIN_SET);
			HAL_Delay(1);
			HAL_GPIO_WritePin(lcd->en_port, lcd->en_pin, GPIO_PIN_SET);
			HAL_Delay(5);
			HAL_GPIO_WritePin(lcd->en_port, lcd->en_pin, GPIO_PIN_RESET);
			HAL_Delay(5);
			HAL_GPIO_WritePin(lcd->data_ports[7], lcd->data_pins[7], GPIO_PIN_RESET);
			HAL_GPIO_WritePin(lcd->data_ports[6], lcd->data_pins[6], GPIO_PIN_RESET);
			HAL_Delay(1);
			HAL_GPIO_WritePin(lcd->en_port, lcd->en_pin, GPIO_PIN_SET);
			HAL_Delay(5);
			HAL_GPIO_WritePin(lcd->en_port, lcd->en_pin, GPIO_PIN_RESET);
			HAL_Delay(5);
			for(int i=1;i<col;i++){
				HAL_GPIO_WritePin(lcd->data_ports[4], lcd->data_pins[4], GPIO_PIN_SET);
				HAL_Delay(1);
				HAL_GPIO_WritePin(lcd->en_port, lcd->en_pin, GPIO_PIN_SET);
				HAL_Delay(5);
				HAL_GPIO_WritePin(lcd->en_port, lcd->en_pin, GPIO_PIN_RESET);
				HAL_Delay(5);
				HAL_GPIO_WritePin(lcd->data_ports[4], lcd->data_pins[4], GPIO_PIN_RESET);
				HAL_GPIO_WritePin(lcd->data_ports[6], lcd->data_pins[6], GPIO_PIN_SET);
				HAL_Delay(1);
				HAL_GPIO_WritePin(lcd->en_port, lcd->en_pin, GPIO_PIN_SET);
				HAL_Delay(5);
				HAL_GPIO_WritePin(lcd->en_port, lcd->en_pin, GPIO_PIN_RESET);
				HAL_Delay(5);
				HAL_GPIO_WritePin(lcd->data_ports[6], lcd->data_pins[6], GPIO_PIN_RESET);
			}
		}
	}
	if(row == 1){
		c = col - 1;
		if(lcd->mode == 0){
			HAL_GPIO_WritePin(lcd->data_ports[1], lcd->data_pins[1], GPIO_PIN_SET);
			HAL_Delay(1);
			HAL_GPIO_WritePin(lcd->en_port, lcd->en_pin, GPIO_PIN_SET);
			HAL_Delay(5);
			HAL_GPIO_WritePin(lcd->en_port, lcd->en_pin, GPIO_PIN_RESET);
			HAL_Delay(5);
			HAL_GPIO_WritePin(lcd->data_ports[1], lcd->data_pins[1], GPIO_PIN_RESET);
			for(int i=1;i<col;i++){
				HAL_GPIO_WritePin(lcd->data_ports[4], lcd->data_pins[4], GPIO_PIN_SET);
				HAL_GPIO_WritePin(lcd->data_ports[2], lcd->data_pins[2], GPIO_PIN_SET);
				HAL_Delay(1);
				HAL_GPIO_WritePin(lcd->en_port, lcd->en_pin, GPIO_PIN_SET);
				HAL_Delay(5);
				HAL_GPIO_WritePin(lcd->en_port, lcd->en_pin, GPIO_PIN_RESET);
				HAL_Delay(5);
				HAL_GPIO_WritePin(lcd->data_ports[4], lcd->data_pins[4], GPIO_PIN_RESET);
				HAL_GPIO_WritePin(lcd->data_ports[2], lcd->data_pins[2], GPIO_PIN_RESET);
			}
		}
		if(lcd->mode == 1){
			HAL_Delay(1);
			HAL_GPIO_WritePin(lcd->en_port, lcd->en_pin, GPIO_PIN_SET);
			HAL_Delay(5);
			HAL_GPIO_WritePin(lcd->en_port, lcd->en_pin, GPIO_PIN_RESET);
			HAL_Delay(5);
			HAL_GPIO_WritePin(lcd->data_ports[5], lcd->data_pins[5], GPIO_PIN_SET);
			HAL_Delay(1);
			HAL_GPIO_WritePin(lcd->en_port, lcd->en_pin, GPIO_PIN_SET);
			HAL_Delay(5);
			HAL_GPIO_WritePin(lcd->en_port, lcd->en_pin, GPIO_PIN_RESET);
			HAL_Delay(5);
			HAL_GPIO_WritePin(lcd->data_ports[5], lcd->data_pins[5], GPIO_PIN_RESET);
			for(int i=1;i<col;i++){
				HAL_GPIO_WritePin(lcd->data_ports[4], lcd->data_pins[4], GPIO_PIN_SET);
				HAL_Delay(1);
				HAL_GPIO_WritePin(lcd->en_port, lcd->en_pin, GPIO_PIN_SET);
				HAL_Delay(5);
				HAL_GPIO_WritePin(lcd->en_port, lcd->en_pin, GPIO_PIN_RESET);
				HAL_Delay(5);
				HAL_GPIO_WritePin(lcd->data_ports[4], lcd->data_pins[4], GPIO_PIN_RESET);
				HAL_GPIO_WritePin(lcd->data_ports[6], lcd->data_pins[6], GPIO_PIN_SET);
				HAL_Delay(1);
				HAL_GPIO_WritePin(lcd->en_port, lcd->en_pin, GPIO_PIN_SET);
				HAL_Delay(5);
				HAL_GPIO_WritePin(lcd->en_port, lcd->en_pin, GPIO_PIN_RESET);
				HAL_Delay(5);
				HAL_GPIO_WritePin(lcd->data_ports[6], lcd->data_pins[6], GPIO_PIN_RESET);
			}
		}
	}
}

void lcd_clear(lcd_t * lcd){
	HAL_GPIO_WritePin(lcd->en_port, lcd->en_pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(lcd->rs_port, lcd->rs_pin, GPIO_PIN_RESET);
	for(int i = 0; i <= 7; i++){
		HAL_GPIO_WritePin(lcd->data_ports[i], lcd->data_pins[i], GPIO_PIN_RESET);
	}
	//clearing lcd:
	if(lcd->mode == 1){
		HAL_Delay(1);
		HAL_GPIO_WritePin(lcd->en_port, lcd->en_pin, GPIO_PIN_SET);
		HAL_Delay(5);
		HAL_GPIO_WritePin(lcd->en_port, lcd->en_pin, GPIO_PIN_RESET);
		HAL_Delay(5);

		HAL_GPIO_WritePin(lcd->data_ports[4], lcd->data_pins[4], GPIO_PIN_SET);
		HAL_Delay(1);
		HAL_GPIO_WritePin(lcd->en_port, lcd->en_pin, GPIO_PIN_SET);
		HAL_Delay(5);
		HAL_GPIO_WritePin(lcd->en_port, lcd->en_pin, GPIO_PIN_RESET);
		HAL_Delay(5);
		HAL_GPIO_WritePin(lcd->data_ports[4], lcd->data_pins[4], GPIO_PIN_RESET);
	}
	if(lcd->mode == 0){
		HAL_GPIO_WritePin(lcd->data_ports[0], lcd->data_pins[0], GPIO_PIN_SET);
		HAL_Delay(1);
		HAL_GPIO_WritePin(lcd->en_port, lcd->en_pin, GPIO_PIN_SET);
		HAL_Delay(5);
		HAL_GPIO_WritePin(lcd->en_port, lcd->en_pin, GPIO_PIN_RESET);
		HAL_Delay(5);
		HAL_GPIO_WritePin(lcd->data_ports[0], lcd->data_pins[0], GPIO_PIN_RESET);
	}
	//Return home:
	if(lcd->mode == 1){
		HAL_Delay(1);
		HAL_GPIO_WritePin(lcd->en_port, lcd->en_pin, GPIO_PIN_SET);
		HAL_Delay(5);
		HAL_GPIO_WritePin(lcd->en_port, lcd->en_pin, GPIO_PIN_RESET);
		HAL_Delay(5);
		
		HAL_GPIO_WritePin(lcd->data_ports[5], lcd->data_pins[5], GPIO_PIN_SET);
		HAL_Delay(1);
		HAL_GPIO_WritePin(lcd->en_port, lcd->en_pin, GPIO_PIN_SET);
		HAL_Delay(5);
		HAL_GPIO_WritePin(lcd->en_port, lcd->en_pin, GPIO_PIN_RESET);
		HAL_Delay(5);
		HAL_GPIO_WritePin(lcd->data_ports[5], lcd->data_pins[5], GPIO_PIN_RESET);
	}
	if(lcd->mode == 0){
		HAL_GPIO_WritePin(lcd->data_ports[1], lcd->data_pins[1], GPIO_PIN_SET);
		HAL_Delay(1);
		HAL_GPIO_WritePin(lcd->en_port, lcd->en_pin, GPIO_PIN_SET);
		HAL_Delay(5);
		HAL_GPIO_WritePin(lcd->en_port, lcd->en_pin, GPIO_PIN_RESET);
		HAL_Delay(5);
		HAL_GPIO_WritePin(lcd->data_ports[1], lcd->data_pins[1], GPIO_PIN_RESET);
	}
}
void lcd_puts(lcd_t * lcd, char* str, int length){
	for(int i = 0; i < length; i++){
		lcd_putchar(lcd,str[i]);
	}
}
