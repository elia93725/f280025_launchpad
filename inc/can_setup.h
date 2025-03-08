/*
 * can_setup.h
 *
 *  Created on: 19 feb 2025
 *      Author: EliaMura
 */

#ifndef INC_CAN_SETUP_H_
#define INC_CAN_SETUP_H_

#include "F28x_Project.h"



//
// Defines
//
#define CAN_MSG_ID_0              0x21 // This example only supports standard ID
#define CAN_MSG_ID_1              0x311 // This example only supports standard ID
#define CAN_MSG_ID_2              0x312 // This example only supports standard ID
#define CAN_MSG_ID_3              0x313 // This example only supports standard ID
#define CAN_MSG_ID_4              0x314 // This example only supports standard ID
#define CAN_MSG_ID_OK             0x500 // This example only supports standard ID


#define CAN_MSG_ID_RX_1             0x200 // This example only supports standard ID
#define CAN_MSG_ID_RX_2             0x144 // This example only supports standard ID


#define CAN_TX_MSG_OBJ_1          1
#define CAN_TX_MSG_OBJ_2          3
#define CAN_TX_MSG_OBJ_3          5
#define CAN_TX_MSG_OBJ_4          7
#define CAN_TX_MSG_OBJ_5          9
#define CAN_TX_MSG_OBJ_OK         11


#define CAN_RX_MSG_OBJ_1          2
#define CAN_RX_MSG_OBJ_2          4
#define CAN_RX_MSG_OBJ_3          6
#define CAN_RX_MSG_OBJ_4          8
#define CAN_RX_MSG_OBJ_5          10

#define CAN_MAX_BIT_DIVISOR     (13)   // The maximum CAN bit timing divisor
#define CAN_MIN_BIT_DIVISOR     (5)    // The minimum CAN bit timing divisor
#define CAN_MAX_PRE_DIVISOR     (1024) // The maximum CAN pre-divisor
#define CAN_MIN_PRE_DIVISOR     (1)    // The minimum CAN pre-divisor

#define CAN_BTR_BRP_M           (0x3F)
#define CAN_BTR_BRPE_M          (0xF0000)

#define CAN_MSG_ID_SHIFT        18U




typedef enum
{
        //! Transmit message object.
        MSG_OBJ_TYPE_TRANSMIT,

        //! Receive message object.
        MSG_OBJ_TYPE_RECEIVE
}
msgObjType;



static const uint16_t canBitValues[] =
{
    0x1100, // TSEG2 2, TSEG1 2, SJW 1, Divide 5
    0x1200, // TSEG2 2, TSEG1 3, SJW 1, Divide 6
    0x2240, // TSEG2 3, TSEG1 3, SJW 2, Divide 7
    0x2340, // TSEG2 3, TSEG1 4, SJW 2, Divide 8
    0x3340, // TSEG2 4, TSEG1 4, SJW 2, Divide 9
    0x3440, // TSEG2 4, TSEG1 5, SJW 2, Divide 10
    0x3540, // TSEG2 4, TSEG1 6, SJW 2, Divide 11
    0x3640, // TSEG2 4, TSEG1 7, SJW 2, Divide 12
    0x3740  // TSEG2 4, TSEG1 8, SJW 2, Divide 13
};


extern uint32_t messageSize;
extern unsigned char ucRXMsgData[8];

//
// Function Prototypes
//


void setupMessageObject_TX(uint32_t objID, uint32_t msgID, msgObjType msgType);
void setupMessageObject_RX(uint32_t objID, uint32_t msgID, msgObjType msgType);
void sendCANMessage(uint32_t objID, char *message);
void sendCANMessageLength(uint32_t objID, char *message, uint32_t len);

bool getCANMessage(uint32_t objID);
uint32_t setCANBitRate(uint32_t sourceClock, uint32_t bitRate);


#endif /* INC_CAN_SETUP_H_ */
