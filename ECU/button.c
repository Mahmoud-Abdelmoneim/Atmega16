/*
 * button.c
 *
 * Created: 25/07/2022 06:40:30 
 *  Author: Mahmoud Abdelmoniem
 */ 
#include "../ECU/button1.h"
#include "stdio.h"

/**
 * @brief Initialize the assigned pin to be Input.
 * @param btn pointer to the button configurations
 * @return  Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue while performing this action
 */
Std_ReturnType button_intialize(const button_t * btn)
{        
      Std_ReturnType ret= E_OK;
    if(NULL==btn)
    {
        ret=E_NOT_OK;
    }
    else
    {
      ret =gpio_pin_dirction_init(&(btn->button_pin));
        
    }   
    return ret;

}
/**
 * @brief Read the state of the button
 * @param btn pointer to the button configurations
 * @param btn_state button state @ref button_state_t
 * @return  Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue while performing this action
 */
Std_ReturnType read_button_state(const button_t * btn,botton_state_t *btn_state)
{
       Std_ReturnType ret= E_NOT_OK;
       
       logic_t Pin_Logic_Status =GPIO_LOW;
    if(NULL==btn || NULL== btn_state)
    {
        ret=E_NOT_OK;
    }
   else{
        gpio_read_logic(&(btn->button_pin), &Pin_Logic_Status);
        switch(btn->button_connection){
            case PULLUP_RESISTOR:
            {
                    if(GPIO_HIGH == Pin_Logic_Status){
                        *btn_state = BUTTON_PRESSED;
                    }
                    else{
                        *btn_state = BUTTON_RELEASED;
                    }
            break;
            }
        
            case PULLDOWN_RESISTOR:
                    {
                    if(GPIO_HIGH == Pin_Logic_Status){
                        *btn_state = BUTTON_RELEASED;
                    }
                    else{
                        *btn_state = BUTTON_PRESSED;
                    }
                    break;
                    }
            default: ;
            
        ret = E_OK;
    }
    
}
       return ret;
}
