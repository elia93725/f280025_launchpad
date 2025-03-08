/*
 * isr.c
 *
 *  Created on: 19 feb 2025
 *      Author: EliaMura
 */

#include "F28x_Project.h"
#include "isr.h"


extern uint16_t dbg_can;
//extern uint16_t comando_feeder;


bool getCANMessage(uint32_t objID);

__interrupt void cana_isr(void){

    dbg_can++;
#if 0
    while(!CanaRegs.CAN_ES.bit.TxOk){
    }
#endif

#if 0
    if(!CanaRegs.CAN_ES.bit.TxOk){
        CanaRegs.CAN_ES.bit.TxOk = 0;
        GpioDataRegs.GPATOGGLE.bit.GPIO31 = 1;
        comando_feeder = 0;
    }
#endif

    if((CanaRegs.CAN_IPEN_21 && (1 << 2)) && (CanaRegs.CAN_INT.bit.INT0ID == 2)){

        getCANMessage(2);

        GpioDataRegs.GPATOGGLE.bit.GPIO31 = 1;
        //comando_feeder = 2;
        CanaRegs.CAN_IF2CMD.bit.ClrIntPnd = 1;

    }


    CanaRegs.CAN_GLB_INT_CLR.bit.INT0_FLG_CLR = 1;
    PieCtrlRegs.PIEACK.bit.ACK9 = 1;

}

