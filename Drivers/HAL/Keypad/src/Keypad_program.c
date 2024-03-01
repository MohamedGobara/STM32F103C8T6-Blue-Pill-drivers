#include "Keypad/inc/Keypad_interface.h"

// Define the GPIO pins for keypad rows and columns based on the configuration file
/*#define ROW0_PIN GPIO_Pin0 // Example: replace GPIO_Pin0 with the appropriate GPIO pin
 #define ROW1_PIN GPIO_Pin1 // Example: replace GPIO_Pin1 with the appropriate GPIO pin
 #define ROW2_PIN GPIO_Pin2 // Example: replace GPIO_Pin2 with the appropriate GPIO pin
 #define ROW3_PIN GPIO_Pin3 // Example: replace GPIO_Pin3 with the appropriate GPIO pin

 #define COL0_PIN GPIO_Pin4 // Example: replace GPIO_Pin4 with the appropriate GPIO pin
 #define COL1_PIN GPIO_Pin5 // Example: replace GPIO_Pin5 with the appropriate GPIO pin
 #define COL2_PIN GPIO_Pin6 // Example: replace GPIO_Pin6 with the appropriate GPIO pin
 #define COL3_PIN GPIO_Pin7 // Example: replace GPIO_Pin7 with the appropriate GPIO pin
 */

extern GPIO_PinConfig row1_config;
extern GPIO_PinConfig row2_config;
extern GPIO_PinConfig row3_config;
extern GPIO_PinConfig row4_config;

// Initialize GPIO pins for
extern GPIO_PinConfig col1_config;
extern GPIO_PinConfig col2_config;
extern GPIO_PinConfig col3_config;
extern GPIO_PinConfig col4_config;

extern uint8_t KeyPad_KeysConfgArr[KEYPAD_RWOS][KEYPAD_COLUMNS];

extern GPIO_Pins Keypad_RowsArr[4];

extern GPIO_Pins Keypad_ColuArr[4];

// Define functions to initialize keypad and get key
void KeyPad_vInit(void) {
	// Initialize GPIO pins for keypad rows as outputs

	// Assign pin names to keypad row array
	Keypad_RowsArr[0] = row1_config.PIN_Name;
	Keypad_RowsArr[1] = row2_config.PIN_Name;
	Keypad_RowsArr[2] = row3_config.PIN_Name;
	Keypad_RowsArr[3] = row4_config.PIN_Name;

	// Assign pin names to keypad column array
	Keypad_ColuArr[0] = col1_config.PIN_Name;
	Keypad_ColuArr[1] = col2_config.PIN_Name;
	Keypad_ColuArr[2] = col3_config.PIN_Name;
	Keypad_ColuArr[3] = col4_config.PIN_Name;

	GPIO_RETURNtPinInit(&row1_config);
	GPIO_RETURNtPinInit(&row2_config);
	GPIO_RETURNtPinInit(&row3_config);
	GPIO_RETURNtPinInit(&row4_config);

	GPIO_RETURNtPinInit(&col1_config);
	GPIO_RETURNtPinInit(&col2_config);
	GPIO_RETURNtPinInit(&col3_config);
	GPIO_RETURNtPinInit(&col4_config);
}

uint8_t KeyPad_u8GetKey(void) {
	uint8_t key = NO_KEY;

	for (uint8_t ROW = 0; ROW < KEYPAD_RWOS; ROW++) {

		GPIO_RETURNtPinOut(GPIO_PORTA, Keypad_RowsArr[ROW], LOW_O);

		// Iterate over columns
		for (uint8_t COL = 0; COL < KEYPAD_COLUMNS; COL++) {
			// Read the state of the current column

			if (GPIO_u8PinRead(GPIO_PORTB, Keypad_ColuArr[COL]) == LOW_O) {
				// Return the character corresponding to the pressed key
				key = KeyPad_KeysConfgArr[ROW][COL];
				while (GPIO_u8PinRead(GPIO_PORTB, Keypad_ColuArr[COL]) == LOW_O);

			}
		}

		// Reset current row to LOW for next iteration
		GPIO_RETURNtPinOut(GPIO_PORTA, Keypad_RowsArr[ROW], High_O);
	}

	// If no key is pressed, return NO_KEY
	return key;
}
