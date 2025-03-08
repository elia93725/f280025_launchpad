/*
 * can_setup.c
 *
 *  Created on: 19 feb 2025
 *      Author: EliaMura
 */


#include "can_setup.h"


extern uint16_t comando_feeder_default;
extern uint16_t comando_feeder_new;

//
// setupMessageObject - Setup message object as Transmit or Receive
//
void setupMessageObject_TX(uint32_t objID, uint32_t msgID, msgObjType msgType)
{
    //
    // Use Shadow variable for IF1CMD. IF1CMD should be written to in
    // single 32-bit write.
    //
    union CAN_IF1CMD_REG CAN_IF1CMD_SHADOW;

    //
    // Wait for busy bit to clear.
    //
    while(CanaRegs.CAN_IF1CMD.bit.Busy)
    {
    }

    //
    // Clear and Write out the registers to program the message object.
    //
    CAN_IF1CMD_SHADOW.all = 0;
    CanaRegs.CAN_IF1MSK.all = 0;
    CanaRegs.CAN_IF1ARB.all = 0;
    CanaRegs.CAN_IF1MCTL.all = 0;

    //
    // Set the Control, Mask, and Arb bit so that they get transferred to the
    // Message object.
    //
    CAN_IF1CMD_SHADOW.bit.Control = 1;
    CAN_IF1CMD_SHADOW.bit.Arb = 1;
    CAN_IF1CMD_SHADOW.bit.Mask = 1;
    CAN_IF1CMD_SHADOW.bit.DIR = 1;

    //
    // Set Message ID (this example assumes 11 bit ID mask)
    //
    CanaRegs.CAN_IF1ARB.bit.ID = (msgID << CAN_MSG_ID_SHIFT);
    CanaRegs.CAN_IF1ARB.bit.MsgVal = 1;

    //
    // Set the data length since this is set for all transfers.  This is
    // also a single transfer and not a FIFO transfer so set EOB bit.
    //
    CanaRegs.CAN_IF1MCTL.bit.DLC = messageSize;
    CanaRegs.CAN_IF1MCTL.bit.EoB = 1;

    //
    // Transfer data to message object RAM
    //
    CAN_IF1CMD_SHADOW.bit.MSG_NUM = objID;
    CanaRegs.CAN_IF1CMD.all = CAN_IF1CMD_SHADOW.all;
}


void setupMessageObject_RX(uint32_t objID, uint32_t msgID, msgObjType msgType)
{
    //
    // Use Shadow variable for IF1CMD. IF1CMD should be written to in
    // single 32-bit write.
    //
    union CAN_IF1CMD_REG CAN_IF1CMD_SHADOW;

    //
    // Wait for busy bit to clear.
    //
    while(CanaRegs.CAN_IF1CMD.bit.Busy)
    {
    }

    //
    // Clear and Write out the registers to program the message object.
    //
    CAN_IF1CMD_SHADOW.all = 0;
    CanaRegs.CAN_IF1MSK.all = 0;
    CanaRegs.CAN_IF1ARB.all = 0;
    CanaRegs.CAN_IF1MCTL.all = 0;

    //
    // Set the Control, Mask, and Arb bit so that they get transferred to the
    // Message object.
    //
    CAN_IF1CMD_SHADOW.bit.Control = 1;
    CAN_IF1CMD_SHADOW.bit.Arb = 1;
    CAN_IF1CMD_SHADOW.bit.Mask = 1;
    CAN_IF1CMD_SHADOW.bit.DIR = 1;

    // Request a Rx insterrupt
    //CanaRegs.CAN_IF1MCTL.bit.TxIE = !int_tx;
    CanaRegs.CAN_IF1ARB.bit.Dir = 0;
    CanaRegs.CAN_IF1MCTL.bit.RxIE = 1;


    // Mask in ricezione
    CanaRegs.CAN_IF1MSK.bit.MXtd    = 1;
    CanaRegs.CAN_IF1MSK.bit.MDir    = 1;
    CanaRegs.CAN_IF1MSK.bit.Msk     = (msgID << CAN_MSG_ID_SHIFT);   // uso tutti i bit della maschera per filtrare

    //
    // Set Message ID (this example assumes 11 bit ID mask)
    //
    CanaRegs.CAN_IF1ARB.bit.ID = (msgID << CAN_MSG_ID_SHIFT);
    CanaRegs.CAN_IF1ARB.bit.MsgVal = 1;


    //
    // Set the data length since this is set for all transfers.  This is
    // also a single transfer and not a FIFO transfer so set EOB bit.
    //
    CanaRegs.CAN_IF1MCTL.bit.DLC = messageSize;
    CanaRegs.CAN_IF1MCTL.bit.EoB = 1;


    //
    // Transfer data to message object RAM
    //
    CAN_IF1CMD_SHADOW.bit.MSG_NUM = objID;
    CanaRegs.CAN_IF1CMD.all = CAN_IF1CMD_SHADOW.all;
}

//
// sendCANMessage - Transmit data from the specified message object
//
void sendCANMessage(uint32_t objID, char *message)
{
    //
    // Use Shadow variable for IF1CMD. IF1CMD should be written to in
    // single 32-bit write.
    //
    union CAN_IF1CMD_REG CAN_IF1CMD_SHADOW;

    //
    // Wait for busy bit to clear.
    //
    while(CanaRegs.CAN_IF1CMD.bit.Busy)
    {
    }

    //
    // Write data to transfer into DATA-A and DATA-B interface registers
    //
    uint16_t index;
    for(index = 0; index < messageSize; index++)
    {
        switch(index)
        {
            case 0:
                CanaRegs.CAN_IF1DATA.bit.Data_0 = message[index];
                break;
            case 1:
                CanaRegs.CAN_IF1DATA.bit.Data_1 = message[index];
                break;
            case 2:
                CanaRegs.CAN_IF1DATA.bit.Data_2 = message[index];
                break;
            case 3:
                CanaRegs.CAN_IF1DATA.bit.Data_3 = message[index];
                break;
            case 4:
                CanaRegs.CAN_IF1DATB.bit.Data_4 = message[index];
                break;
            case 5:
                CanaRegs.CAN_IF1DATB.bit.Data_5 = message[index];
                break;
            case 6:
                CanaRegs.CAN_IF1DATB.bit.Data_6 = message[index];
                break;
            case 7:
                CanaRegs.CAN_IF1DATB.bit.Data_7 = message[index];
                break;
        }
    }

    //
    // Set Direction to write and set DATA-A/DATA-B to be transfered to
    // message object
    //
    CAN_IF1CMD_SHADOW.all = 0;
    CAN_IF1CMD_SHADOW.bit.DIR = 1;
    CAN_IF1CMD_SHADOW.bit.DATA_A = 1;
    CAN_IF1CMD_SHADOW.bit.DATA_B = 1;

    //
    // Set Tx Request Bit
    //
    CAN_IF1CMD_SHADOW.bit.TXRQST = 1;


    //
    // Transfer the message object to the message object specified by
    // objID.
    //
    CAN_IF1CMD_SHADOW.bit.MSG_NUM = objID;
    CanaRegs.CAN_IF1CMD.all = CAN_IF1CMD_SHADOW.all;


    comando_feeder_new = comando_feeder_default;

}



void sendCANMessageLength(uint32_t objID, char *message, uint32_t len)
{
    //
    // Use Shadow variable for IF1CMD. IF1CMD should be written to in
    // single 32-bit write.
    //
    union CAN_IF1CMD_REG CAN_IF1CMD_SHADOW;

    //
    // Wait for busy bit to clear.
    //
    while(CanaRegs.CAN_IF1CMD.bit.Busy)
    {
    }

    //
    // Write data to transfer into DATA-A and DATA-B interface registers
    //
    uint16_t index;
    for(index = 0; index < messageSize; index++)
    {
        if(index > (len-1)){
            message[index] = 0;
        }
        switch(index)
        {
            case 0:
                CanaRegs.CAN_IF1DATA.bit.Data_0 = message[index];
                break;
            case 1:
                CanaRegs.CAN_IF1DATA.bit.Data_1 = message[index];
                break;
            case 2:
                CanaRegs.CAN_IF1DATA.bit.Data_2 = message[index];
                break;
            case 3:
                CanaRegs.CAN_IF1DATA.bit.Data_3 = message[index];
                break;
            case 4:
                CanaRegs.CAN_IF1DATB.bit.Data_4 = message[index];
                break;
            case 5:
                CanaRegs.CAN_IF1DATB.bit.Data_5 = message[index];
                break;
            case 6:
                CanaRegs.CAN_IF1DATB.bit.Data_6 = message[index];
                break;
            case 7:
                CanaRegs.CAN_IF1DATB.bit.Data_7 = message[index];
                break;
        }
    }

    //
    // Set Direction to write and set DATA-A/DATA-B to be transfered to
    // message object
    //
    CAN_IF1CMD_SHADOW.all = 0;
    CAN_IF1CMD_SHADOW.bit.DIR = 1;
    CAN_IF1CMD_SHADOW.bit.DATA_A = 1;
    CAN_IF1CMD_SHADOW.bit.DATA_B = 1;

    //
    // Set Tx Request Bit
    //
    CAN_IF1CMD_SHADOW.bit.TXRQST = 1;


    //
    // Transfer the message object to the message object specified by
    // objID.
    //
    CAN_IF1CMD_SHADOW.bit.MSG_NUM = objID;
    CanaRegs.CAN_IF1CMD.all = CAN_IF1CMD_SHADOW.all;


    comando_feeder_new = comando_feeder_default;

}



//
// getCANMessage - Check the message object for new data.
//                 If new data, data written into array and return true.
//                 If no new data, return false.
//
bool getCANMessage(uint32_t objID)
{
    bool status;

    //
    // Use Shadow variable for IF2CMD. IF2CMD should be written to in
    // single 32-bit write.
    //
    union CAN_IF2CMD_REG CAN_IF2CMD_SHADOW;

    //
    // Set the Message Data A, Data B, and control values to be read
    // on request for data from the message object.
    //
    CAN_IF2CMD_SHADOW.all = 0;
    CAN_IF2CMD_SHADOW.bit.Control = 1;
    CAN_IF2CMD_SHADOW.bit.DATA_A = 1;
    CAN_IF2CMD_SHADOW.bit.DATA_B = 1;
    CAN_IF2CMD_SHADOW.bit.Arb = 1;

    //
    // Transfer the message object to the message object IF register.
    //
    CAN_IF2CMD_SHADOW.bit.MSG_NUM = objID;                              // So quale mailbox voglio andare a leggere in ricezione
    CanaRegs.CAN_IF2CMD.all = CAN_IF2CMD_SHADOW.all;


    //
    // Wait for busy bit to clear.
    //
    while(CanaRegs.CAN_IF2CMD.bit.Busy)
    {
    }

    // Se mi il nuovo dato è riferito alla mailbox che mi interessa

    if(CanaRegs.CAN_NDAT_21 && objID){
    //
    // See if there is new data available.
    //
        if(CanaRegs.CAN_IF2MCTL.bit.NewDat == 1)
        {

        //
        // Read out the data from the CAN registers.
        //
            uint16_t index;
            for(index = 0; index < messageSize; index++)
            {
                switch(index)
                {
                    case 0:
                        ucRXMsgData[index] = CanaRegs.CAN_IF2DATA.bit.Data_0;
                    break;
                    case 1:
                        ucRXMsgData[index] = CanaRegs.CAN_IF2DATA.bit.Data_1;
                    break;
                    case 2:
                        ucRXMsgData[index] = CanaRegs.CAN_IF2DATA.bit.Data_2;
                    break;
                    case 3:
                        ucRXMsgData[index] = CanaRegs.CAN_IF2DATA.bit.Data_3;
                    break;
                    case 4:
                        ucRXMsgData[index] = CanaRegs.CAN_IF2DATB.bit.Data_4;
                    break;
                    case 5:
                        ucRXMsgData[index] = CanaRegs.CAN_IF2DATB.bit.Data_5;
                    break;
                    case 6:
                        ucRXMsgData[index] = CanaRegs.CAN_IF2DATB.bit.Data_6;
                    break;
                    case 7:
                        ucRXMsgData[index] = CanaRegs.CAN_IF2DATB.bit.Data_7;
                    break;
                }
            }
        }


        //
        // Populate Shadow Variable
        //
        CAN_IF2CMD_SHADOW.all = CanaRegs.CAN_IF2CMD.all;

        //
        // Clear New Data Flag
        //
        CAN_IF2CMD_SHADOW.bit.TxRqst = 1;

        //
        // Transfer the message object to the message object IF register.
        //
        CAN_IF2CMD_SHADOW.bit.MSG_NUM = objID;
        CanaRegs.CAN_IF2CMD.all = CAN_IF2CMD_SHADOW.all;

        status = true;
    }
    else
    {
        status = false;
    }

    return(status);
}

uint32_t setCANBitRate(uint32_t sourceClock, uint32_t bitRate)
{
    uint32_t desiredRatio;
    uint32_t canBits;
    uint32_t preDivide;
    uint32_t regValue;
    uint16_t canControlValue;

    //
    // Calculate the desired clock rate.
    //
    desiredRatio = sourceClock / bitRate;                   // rapporto tra il clock del micro e il bit-rate del canbus

    //
    // Make sure that the Desired Ratio is not too large.  This enforces the
    // requirement that the bit rate is larger than requested.
    //
    if((sourceClock / desiredRatio) > bitRate)
    {
        desiredRatio += 1;
    }

    //
    // Check all possible values to find a matching value.
    //
    while(desiredRatio <= CAN_MAX_PRE_DIVISOR * CAN_MAX_BIT_DIVISOR)
    {
        //
        // Loop through all possible CAN bit divisors.
        //
        for(canBits = CAN_MAX_BIT_DIVISOR;
            canBits >= CAN_MIN_BIT_DIVISOR;
            canBits--)
        {
            //
            // For a given CAN bit divisor save the pre divisor.
            //
            preDivide = desiredRatio / canBits;

            //
            // If the calculated divisors match the desired clock ratio then
            // return these bit rate and set the CAN bit timing.
            //
            if((preDivide * canBits) == desiredRatio)
            {
                //
                // Start building the bit timing value by adding the bit timing
                // in time quanta.
                //
                regValue = canBitValues[canBits - CAN_MIN_BIT_DIVISOR];

                //
                // To set the bit timing register, the controller must be
                // placed
                // in init mode (if not already), and also configuration change
                // bit enabled.  The state of the register should be saved
                // so it can be restored.
                //
                canControlValue = CanaRegs.CAN_CTL.all;
                CanaRegs.CAN_CTL.bit.Init = 1;
                CanaRegs.CAN_CTL.bit.CCE = 1;

                //
                // Now add in the pre-scalar on the bit rate.
                //
                regValue |= ((preDivide - 1) & CAN_BTR_BRP_M) |
                            (((preDivide - 1) << 10) & CAN_BTR_BRPE_M);

                //
                // Set the clock bits in the and the bits of the
                // pre-scalar.
                //
                CanaRegs.CAN_BTR.all = regValue;

                //
                // Restore the saved CAN Control register.
                //
                CanaRegs.CAN_CTL.all = canControlValue;

                //
                // Return the computed bit rate.
                //
                return(sourceClock / ( preDivide * canBits));
            }
        }

        //
        // Move the divisor up one and look again.  Only in rare cases are
        // more than 2 loops required to find the value.
        //
        desiredRatio++;
    }
    return 0;
}


