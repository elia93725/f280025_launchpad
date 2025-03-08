/*
 * gpio.c
 *
 *  Created on: 30 gen 2025
 *      Author: EliaMura
 */


#include "gpio.h"

void GPIO_CANA(void){

    EALLOW;

    // CAN TXA
    GpioCtrlRegs.GPBGMUX1.bit.GPIO32    = 0b10;
    GpioCtrlRegs.GPBMUX1.bit.GPIO32     = 0b10;
    GpioCtrlRegs.GPBPUD.bit.GPIO32      = 1;
    GpioCtrlRegs.GPBQSEL1.bit.GPIO32    = 3;

    // CAN RXA
    GpioCtrlRegs.GPBGMUX1.bit.GPIO33    = 0b10;
    GpioCtrlRegs.GPBMUX1.bit.GPIO33     = 0b10;
    GpioCtrlRegs.GPBPUD.bit.GPIO33      = 1;
    GpioCtrlRegs.GPBQSEL1.bit.GPIO33    = 3;
    EDIS;

}


void GPIO_USER_LED(void){

    EALLOW;

    // USER LED (GPIO31 & GPIO34)
    GpioCtrlRegs.GPAGMUX2.bit.GPIO31     = 0;
    GpioCtrlRegs.GPAMUX2.bit.GPIO31      = 0;
    GpioCtrlRegs.GPBGMUX1.bit.GPIO34     = 0;
    GpioCtrlRegs.GPBMUX1.bit.GPIO34      = 0;
    GpioCtrlRegs.GPADIR.bit.GPIO31       = 1;
    GpioCtrlRegs.GPBDIR.bit.GPIO34       = 1;
    GpioCtrlRegs.GPAPUD.bit.GPIO31       = 1;
    GpioCtrlRegs.GPBPUD.bit.GPIO34       = 1;

    EDIS;


}


