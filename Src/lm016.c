#include "lm016.h"
#include "stm32f4xx_hal_gpio.h"
//HD7 HD6 HD5 HD4 LD3 LD2 LD1 LD0
void lcd_init(lcd_t * lcd){
	
}


//HAL_GPIO_WritePin(lcd->data_ports[0],lcd->data_pins[0],1);
void lcd_putchar(lcd_t * lcd, uint8_t character){

}
void lcd_set_curser(lcd_t * lcd, uint16_t row, uint16_t col){
	
}
void lcd_clear(lcd_t * lcd){
	
}
void lcd_puts(lcd_t * lcd, char* str){
	
}