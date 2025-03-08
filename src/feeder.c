/*
 * feeder.c
 *
 *  Created on: 17 feb 2025
 *      Author: EliaMura
 */

#include "feeder.h"
#include "can_setup.h"

void Setup_CAN_Write_Regs(){

    setupMessageObject_TX(CAN_TX_MSG_OBJ_1, CAN_MSG_ID_0, MSG_OBJ_TYPE_TRANSMIT);

    setupMessageObject_TX(CAN_TX_MSG_OBJ_2, CAN_MSG_ID_1, MSG_OBJ_TYPE_TRANSMIT);

    setupMessageObject_TX(CAN_TX_MSG_OBJ_3, CAN_MSG_ID_2, MSG_OBJ_TYPE_TRANSMIT);

    setupMessageObject_TX(CAN_TX_MSG_OBJ_4, CAN_MSG_ID_3, MSG_OBJ_TYPE_TRANSMIT);

    setupMessageObject_TX(CAN_TX_MSG_OBJ_5, CAN_MSG_ID_4, MSG_OBJ_TYPE_TRANSMIT);

    setupMessageObject_TX(CAN_TX_MSG_OBJ_OK, CAN_MSG_ID_OK, MSG_OBJ_TYPE_TRANSMIT);
}




