/*
 * Bit_Config.h
 *
 * Created: 27/07/2022 05:34:34 م
 *  Author: Mahmoud Abdelmoniem
 */ 
#include "stdio.h"

#ifndef BIT_CONFIG_H_
#define BIT_CONFIG_H_


#define MASK_PIN    1

#define SET_BIT(_REG,PIN)      (_REG=_REG | (MASK_PIN <<PIN))
#define CLEAR_BIT(_REG,PIN)    (_REG=_REG & (~(MASK_PIN<<PIN)))
#define TOGGLE_BIT(_REG,PIN)   (_REG=_REG ^ (MASK_PIN<<PIN))
#define READ_BIT(_REG,PIN)     ((_REG>>PIN)  & MASK_PIN)




#endif /* BIT_CONFIG_H_ */