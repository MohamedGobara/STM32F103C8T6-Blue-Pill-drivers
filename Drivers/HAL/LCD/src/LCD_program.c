#include "GPIO/inc/GPIO_interface.h"
#include "LCD/inc/LCD_interface.h"

/* check mode is 4 bit or 8 bit */

#if LCD_MODE==_8_BIT


static void WriteInsterction(uint8_t ins) {


	GPIO_RETURNtPinOut(LCD_RS_PIN ,LOW_O );
	DIO_WritePort(LCD_PORT,ins) ;

	GPIO_RETURNtPinOut(LCD_E_PIN , High_O) ;
	SysTick_vDelayms(1) ;
	GPIO_RETURNtPinOut(LCD_E_PIN , LOW_O) ;
	SysTick_vDelayms(1) ;

}


static void WriteData(uint8_t data) {


	GPIO_RETURNtPinOut(LCD_RS_PIN ,High_O );
	DIO_WritePort(LCD_PORT,data) ;

	GPIO_RETURNtPinOut(LCD_E_PIN , High_O) ;
	SysTick_vDelayms(1) ;
	GPIO_RETURNtPinOut(LCD_E_PIN , LOW_O) ;
	SysTick_vDelayms(1) ;

}


void LCD_Init(void) {

	SysTick_vDelayms(50) ;
	WriteInsterction(0x38)  ;//screen on 8 bit mode
	WriteInsterction(0x0f) ; //cursor off 0x0e ,0x0f
	WriteInsterction(0x01) ; //clear screen
	SysTick_vDelayms(1) ;
	WriteInsterction(0x06)  ; //increase DDRAM address no shift


}


/* check mode is 4 bit or 8 bit */

#elif LCD_MODE==_4_BIT

static void WriteInsterction(uint8_t ins) {

	GPIO_RETURNtPinOut(LCD_RS_PORT, LCD_RS_PIN, LOW_O);

	GPIO_RETURNtPinOut(D7_PORT, D7, READ_BIT(ins, 7));
	GPIO_RETURNtPinOut(D6_PORT, D6, READ_BIT(ins, 6));
	GPIO_RETURNtPinOut(D5_PORT, D5, READ_BIT(ins, 5));
	GPIO_RETURNtPinOut(D4_PORT, D4, READ_BIT(ins, 4));

	GPIO_RETURNtPinOut(LCD_E_PORT, LCD_E_PIN, High_O);
	SysTick_vDelayms(1);
	GPIO_RETURNtPinOut(LCD_E_PORT, LCD_E_PIN, LOW_O);
	SysTick_vDelayms(1);

	GPIO_RETURNtPinOut(D7_PORT, D7, READ_BIT(ins, 3));
	GPIO_RETURNtPinOut(D6_PORT, D6, READ_BIT(ins, 2));
	GPIO_RETURNtPinOut(D5_PORT, D5, READ_BIT(ins, 1));
	GPIO_RETURNtPinOut(D4_PORT, D4, READ_BIT(ins, 0));

	GPIO_RETURNtPinOut(LCD_E_PORT, LCD_E_PIN, High_O);
	SysTick_vDelayms(1);
	GPIO_RETURNtPinOut(LCD_E_PORT, LCD_E_PIN, LOW_O);
	SysTick_vDelayms(1);

}

static void WriteData(uint8_t data) {

	GPIO_RETURNtPinOut(LCD_RS_PORT, LCD_RS_PIN, High_O);
	GPIO_RETURNtPinOut(D7_PORT, D7, READ_BIT(data, 7));
	GPIO_RETURNtPinOut(D6_PORT, D6, READ_BIT(data, 6));
	GPIO_RETURNtPinOut(D5_PORT, D5, READ_BIT(data, 5));
	GPIO_RETURNtPinOut(D4_PORT, D4, READ_BIT(data, 4));

	GPIO_RETURNtPinOut(LCD_E_PORT, LCD_E_PIN, High_O);
	SysTick_vDelayms(1);
	GPIO_RETURNtPinOut(LCD_E_PORT, LCD_E_PIN, LOW_O);
	SysTick_vDelayms(1);

	GPIO_RETURNtPinOut(D7_PORT, D7, READ_BIT(data, 3));
	GPIO_RETURNtPinOut(D6_PORT, D6, READ_BIT(data, 2));
	GPIO_RETURNtPinOut(D5_PORT, D5, READ_BIT(data, 1));
	GPIO_RETURNtPinOut(D4_PORT, D4, READ_BIT(data, 0));

	GPIO_RETURNtPinOut(LCD_E_PORT, LCD_E_PIN, High_O);
	SysTick_vDelayms(1);
	GPIO_RETURNtPinOut(LCD_E_PORT, LCD_E_PIN, LOW_O);
	SysTick_vDelayms(1);

}

extern GPIO_PinConfig D7_PIN;
extern GPIO_PinConfig D6_PIN;
extern GPIO_PinConfig D5_PIN;
extern GPIO_PinConfig D4_PIN;
extern GPIO_PinConfig EN_PIN;
extern GPIO_PinConfig RS_PIN;

void LCD_Init(void) {

	GPIO_RETURNtPinInit(&D7_PIN);
	GPIO_RETURNtPinInit(&D6_PIN);
	GPIO_RETURNtPinInit(&D5_PIN);
	GPIO_RETURNtPinInit(&D4_PIN);

	GPIO_RETURNtPinInit(&EN_PIN);
	GPIO_RETURNtPinInit(&RS_PIN);

	SysTick_vDelayms(50);
	WriteInsterction(0x02);
	WriteInsterction(0x28); //screen on 4 bit mode  with 2 line 5*7
	WriteInsterction(0x0c); //cursor off 0x0e ,0x0f
	WriteInsterction(0x01); //clear screen
	SysTick_vDelayms(1);
	WriteInsterction(0x06); //increase DDRAM address no shift

}

#endif

void LCD_WriteChar(uint8_t ch) {

	WriteData(ch);

}

void LCD_Clear(void) {

	WriteInsterction(0x01);

}

void LCD_WriteNumber(int32_t num) {

	uint8_t i = 0, str[16], negative_flag = 0;

	int8_t j;

	//zero
	if (num == 0) {

		LCD_WriteChar('0');

	}

	if (num < 0) {
		negative_flag = 1;
		num = num * -1;
	}

	//positive number
	while (num) {
		str[i] = (num % 10) + '0';
		num = num / 10;
		i++;
	}

	if (negative_flag == 1) {
		LCD_WriteChar('-');
	}
	for (j = i; j > 0; j--) {

		LCD_WriteChar(str[j - 1]);

	}

}

void LCD_WriteString(uint8_t *str) {

	uint8_t *ptr = str;

	while (*ptr) {

		LCD_WriteChar(*ptr);
		ptr++;

	}

}

void LCD_WriteBinary(uint8_t num) {

	for (int8_t i = 7; i >= 0; i--) {
		if (((num >> i) & 1) == 1) {
			LCD_WriteChar('1');
		} else {
			LCD_WriteChar('0');

		}

	}

}

void LCD_WriteHex(uint8_t num) {

	uint8_t arr[] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A',
			'B', 'C', 'D', 'E', 'F' };
	struct temp {
		uint8_t left :4;
		uint8_t right :4;
	};
	struct temp s1;
	s1.right = num;
	s1.left = num >> 4;

	LCD_WriteChar(arr[(s1.left)]);
	LCD_WriteChar(arr[(s1.right)]);

}

void LCD_ReturnHome(void) {

	WriteInsterction(0x02);

}

void LCD_GoTo(uint8_t line, uint8_t cell) {

	if (line == 0) {

		WriteInsterction(0x80 + cell);

	} else if (line == 1) {

		WriteInsterction((0x80 + 0x40) + cell);

	}

}

void LCD_WriteNumber4D(uint32_t num) {

	LCD_WriteChar(((num % 10000) / 1000) + '0');
	LCD_WriteChar(((num % 1000) / 100) + '0');
	LCD_WriteChar(((num % 100) / 10) + '0');
	LCD_WriteChar(((num % 10) / 1) + '0');
}

void LCD_GoToClear(uint8_t line, uint8_t cell, uint8_t numOfCells) {

	uint8_t i;
	LCD_GoTo(line, cell);

	for (i = 0; i < numOfCells; i++) {

		LCD_WriteChar(' ');

	}

}

void LCD_CreateCharacter(uint8_t *pattern, uint8_t location) {

	uint8_t i = 0;

	WriteInsterction(0x40 + (location * 8));
	for (i; i < 8; i++) {

		WriteData(pattern[i]);

	}
	WriteInsterction(0x80); // return again to DDRAM

}

