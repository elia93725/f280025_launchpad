//###########################################################################
//
// FILE:    gpio_ex1_setup.c
//
// TITLE:   Device GPIO Setup
//! <h1> Device GPIO Setup </h1>
//! \addtogroup bitfield_example_list
//!
//! Configures the F28002X GPIO into two different configurations
//! This code is verbose to illustrate how the GPIO could be setup.
//! In a real application, lines of code can be combined for improved
//! code size and efficiency.
//! This example only sets-up the GPIO.
//! Nothing is actually done with the pins after setup.
//
//#############################################################################
//
//
// $Copyright:
// Copyright (C) 2023 Texas Instruments Incorporated - http://www.ti.com/
//
// Redistribution and use in source and binary forms, with or without 
// modification, are permitted provided that the following conditions 
// are met:
// 
//   Redistributions of source code must retain the above copyright 
//   notice, this list of conditions and the following disclaimer.
// 
//   Redistributions in binary form must reproduce the above copyright
//   notice, this list of conditions and the following disclaimer in the 
//   documentation and/or other materials provided with the   
//   distribution.
// 
//   Neither the name of Texas Instruments Incorporated nor the names of
//   its contributors may be used to endorse or promote products derived
//   from this software without specific prior written permission.
// 
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS 
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT 
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT 
// OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, 
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT 
// LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT 
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE 
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
// $
//#############################################################################

//
// Included Files
//
#include "f28x_project.h"
#include "main.h"
//
// Defines


//
// Function Prototypes
void InitCAN(void);

//




// Global Variables

unsigned char ucRXMsgData[8] = {0, 0, 0, 0, 0, 0, 0, 0};         // RX Data

char message1[8] = {0x1D, 0x5E, 0x6A, 0x5D,0x3B, 0x2E, 0x3E, 0xF4};
char message2[8] = {0x2, 0x2, 0xA, 0xD,0xB, 0xE, 0xE, 0xF};
char message3[8] = {0x3, 0x3, 0xA, 0xD,0xB, 0xE, 0xE, 0xF};
char message4[8] = {0x4, 0x4, 0xA, 0xD,0xB, 0xE, 0xE, 0xF};
char message5[8] = {0x5, 0x5, 0xA, 0xD,0xB, 0xE, 0xE, 0xF};

char message1_tx[8] = {0x11, 0x5E, 0x6A, 0x5D,0x3B, 0x2E, 0x3E, 0xF4};
char message1_OK[2] = {0x55, 0x01};
char message1_ERROR[2] = {0x55, 0x33};

uint32_t messageSize = sizeof(message1);          // Message Size (DLC)
volatile unsigned long msgCount = 0; // A counter that keeps track of the
                                     // number of times the transmit was
                                     // successful.
volatile unsigned long errFlag = 0;  // A flag to indicate that some
                                     // transmission error occurred.



uint16_t conta = 0;
uint16_t comando_feeder_default;
uint16_t comando_feeder_new = 0;
uint16_t dbg_can = 0;
uint16_t cnt_rx = 0;


OFS_Commands OFS_Setup;





//
// Main
//

void main(void)
{
    //
    //Step 1. Initialize System Control:
    //PLL, WatchDog,enabe Peripheral Clocks
    //This example function is found in the f28004x_sysctrl.c file.
    //
    InitSysCtrl();

    //
    //Step 2. Initialize GPIO
    //
    InitGpio();

    //
    //Step 3. Clear all __interrupts and initialize PIE vector table:
    //Disable CPU __interrupts
    //
    DINT;

    //
    //Initialize the PIE control registers to their default state.
    //The default state is all PIE interrupts disabled and flags
    //are cleared.
    //
    InitPieCtrl();

    //
    //Disable CPU interrupts and clear all CPU interrupt flags:
    //
    IER = 0x0000;
    IFR = 0x0000;

    //
    //Initialize the PIE vector table with pointers to the shell Interrupt
    //Service Routines (ISR).
    //
    InitPieVectTable();

    EALLOW;

    PieVectTable.CANA0_INT = &cana_isr;

    PieCtrlRegs.PIEIER9.bit.INTx5 = 1;

    IER |= M_INT9;         // abilito l'interrupt per il cana1

    EDIS;


    GPIO_CANA();
    GPIO_USER_LED();

    InitCAN();

    ClkCfgRegs.CLKSRCCTL2.bit.CANABCLKSEL = 0;      // usa il clock PER.SYSCLK (periferiche)

    uint32_t status = setCANBitRate(100000000, 500000);

        //
        // If values requested are too small or too large, catch error
        //
        if(status == 0)
        {
            errFlag++;
            ESTOP0;         // Stop here and handle error
        }



        //
        // Enable the CAN for operation.
        //

        CanaRegs.CAN_CTL.bit.DAR    = 1;      // Disable automatic retransmission

        CanaRegs.CAN_CTL.bit.Test   = 0;      // Enable test mode and select external loopback
        CanaRegs.CAN_TEST.bit.EXL   = 0;      // External Loopback

        //
        // Enable test mode and select external loopback
        //

        //
        // Initialize the message object that will be used for sending CAN
        // messages.
        //

        //setupMessageObject(1, 0x312, MSG_OBJ_TYPE_RECEIVE);
        setupMessageObject_RX(CAN_RX_MSG_OBJ_1, CAN_MSG_ID_RX_1, MSG_OBJ_TYPE_RECEIVE);
        //setupMessageObject(CAN_RX_MSG_OBJ_2, CAN_MSG_ID_RX_2, MSG_OBJ_TYPE_RECEIVE);

    #if 1
        setupMessageObject_TX(CAN_TX_MSG_OBJ_1, CAN_MSG_ID_0, MSG_OBJ_TYPE_TRANSMIT);

        setupMessageObject_TX(CAN_TX_MSG_OBJ_2, CAN_MSG_ID_1, MSG_OBJ_TYPE_TRANSMIT);

        setupMessageObject_TX(CAN_TX_MSG_OBJ_3, CAN_MSG_ID_2, MSG_OBJ_TYPE_TRANSMIT);

        setupMessageObject_TX(CAN_TX_MSG_OBJ_4, CAN_MSG_ID_3, MSG_OBJ_TYPE_TRANSMIT);

        setupMessageObject_TX(CAN_TX_MSG_OBJ_5, CAN_MSG_ID_4, MSG_OBJ_TYPE_TRANSMIT);

        setupMessageObject_TX(CAN_TX_MSG_OBJ_OK, CAN_MSG_ID_OK, MSG_OBJ_TYPE_TRANSMIT);
        setupMessageObject_TX(CAN_TX_MSG_OBJ_OK, CAN_MSG_ID_OK, MSG_OBJ_TYPE_TRANSMIT);
    #endif

        //
        // Initialize the message object that will be used for receiving CAN
        // messages.
        //
        //setupMessageObject(CAN_RX_MSG_OBJ, CAN_MSG_ID_1, MSG_OBJ_TYPE_RECEIVE);


        GpioDataRegs.GPBSET.bit.GPIO34 = 1;
        GpioDataRegs.GPASET.bit.GPIO31 = 1;


        CanaRegs.CAN_CTL.bit.IE0 = 1;
        CanaRegs.CAN_GLB_INT_EN.bit.GLBINT0_EN = 1;

        CanaRegs.CAN_CTL.bit.Init   = 0;      // Enable the CAN for operation (0 processa i messaggi normalmente)

        EINT;   // Enable Global interrupt INTM
        ERTM;   // Enable Global realtime interrupt DBGM


        comando_feeder_default = 0;         // di default si rimane nello stato di standby


    while(1)
    {


        conta++;
        //
        // Send the CAN message using object number 1 (not the same thing as
        // CAN ID, which is also 1 in this example).  This function will cause
        // the message to be transmitted right away.
        //


#if 0
        if (CanbRegs.CAN_ES.bit.EPass) {
            // Indica che il bus è in modalità error-passive
            GpioDataRegs.GPASET.bit.GPIO31 = 1;
        }


        if (CanbRegs.CAN_ES.bit.BOff) {

            GpioDataRegs.GPBSET.bit.GPIO34 = 1;
            // Indica che il bus è in modalità bus-off
        }
#endif

#if 0
        // TESTATO, SEMBRA ANDARE --> PASSARE A CONFIGURAZIONE IN INTERRUPT RX
        getCANMessage(CAN_RX_MSG_OBJ_1);
        getCANMessage(CAN_RX_MSG_OBJ_2);
#endif


        //
        // Now wait 1 second before continuing
        //

        DELAY_US(1000*1000);


        // TESTATO, SEMBRA ANDARE --> PASSARE A CONFIGURAZIONE IN INTERRUPT TX

        switch(comando_feeder_new){
        case 0:

            cnt_rx = 0;

            sendCANMessage(CAN_TX_MSG_OBJ_1, message1);

            // Vado a leggermi il contenuto del messaggio che ho inviato (RX)
            getCANMessage(1);

#if 0
            // Mando il primo messaggio con ID e DATA (TX)
            sendCANMessage(CAN_TX_MSG_OBJ_1, message1);

            // Vado a leggermi il contenuto del messaggio che ho inviato (RX)
            getCANMessage(1);

            // Controllo che il buffer TX corrisponda al buffer RX
            for(i = 0; i < sizeof(message1); i++){
                ucRXMsgData[5] = 45;
                if(message1[i] == ucRXMsgData[i])
                    cnt_rx++;
            }

            // Se il contatore è lungo come il buffer allora è andata a buon fine, invio messaggio POSITIVO
            if(cnt_rx == sizeof(message1)){
                sendCANMessageLength(CAN_TX_MSG_OBJ_OK, message1_OK, sizeof(message1_OK));
            }
            // altrimenti invio messaggio NEGATIVO
            else{
                sendCANMessageLength(CAN_TX_MSG_OBJ_OK, message1_ERROR, sizeof(message1_OK));
            }
#endif
            break;

        case 1:
            sendCANMessage(CAN_TX_MSG_OBJ_2, message2);

            break;

        case 2:
            sendCANMessage(CAN_TX_MSG_OBJ_3, message3);


            break;

        case 3:
            sendCANMessage(CAN_TX_MSG_OBJ_4, message4);
            GpioDataRegs.GPBTOGGLE.bit.GPIO34 = 1;

            break;

        case 4:

            sendCANMessage(CAN_TX_MSG_OBJ_5, message5);
            break;

        }


        if(OFS_Setup.Write == 1){

            sendCANMessage(CAN_TX_MSG_OBJ_1, message1_tx);

            sendCANMessage(CAN_TX_MSG_OBJ_2, message2);

            sendCANMessage(CAN_TX_MSG_OBJ_3, message3);

            sendCANMessage(CAN_TX_MSG_OBJ_4, message4);

            sendCANMessage(CAN_TX_MSG_OBJ_5, message5);

            OFS_Setup.Write = 0;

        }




    }
}



//
// End of File
//
