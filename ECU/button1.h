/*
 * button1.h
 *
 * Created: 25/07/2022 06:40:47 م
 *  Author: Mahmoud Abdelmoniem
 */ 


#ifndef BUTTON1_H_
#define BUTTON1_H_
#include "../MCAL/GPIO/GPIO.h"

/*........section: macro declarations......... */



/*........section: macro function declarations......... */


/*........section: data type declarations......... */
typedef enum{
	BUTTON_PRESSED,
	BUTTON_RELEASED
}botton_state_t;

typedef enum
{
	PULLUP_RESISTOR,
	PULLDOWN_RESISTOR
}botton_active;

typedef struct
{
	pin_cofig_t button_pin;
	botton_state_t button_state;
	botton_active button_connection;
	
}button_t;


/*........section: function declarations......... */
Std_ReturnType button_intialize(const button_t * btn);
Std_ReturnType read_button_state(const button_t * btn,botton_state_t *btn_state);



#endif /* BUTTON1_H_ */