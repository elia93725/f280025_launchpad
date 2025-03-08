//###########################################################################
//
// FILE:   f28002x_pievect.c
//
// TITLE:  f28002x Device PIE Vector Initialization Functions
//
//###########################################################################
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
//###########################################################################

//
// Included Files
//
#include "f28002x_device.h"       // f28002x Header File Include File
#include "f28002x_examples.h"     // f28002x Examples Include File

//
// Globals
//
const struct PIE_VECT_TABLE PieVectTableInit = {
    PIE_RESERVED_ISR,               // Reserved
    PIE_RESERVED_ISR,               // Reserved
    PIE_RESERVED_ISR,               // Reserved
    PIE_RESERVED_ISR,               // Reserved
    PIE_RESERVED_ISR,               // Reserved
    PIE_RESERVED_ISR,               // Reserved
    PIE_RESERVED_ISR,               // Reserved
    PIE_RESERVED_ISR,               // Reserved
    PIE_RESERVED_ISR,               // Reserved
    PIE_RESERVED_ISR,               // Reserved
    PIE_RESERVED_ISR,               // Reserved
    PIE_RESERVED_ISR,               // Reserved
    PIE_RESERVED_ISR,               // Reserved
    TIMER1_ISR,                     // CPU Timer 1 Interrupt
    TIMER2_ISR,                     // CPU Timer 2 Interrupt
    DATALOG_ISR,                    // Datalogging Interrupt
    RTOS_ISR,                       // RTOS Interrupt from ERAD
    EMU_ISR,                        // Emulation Interrupt
    NMI_ISR,                        // Non-Maskable Interrupt
    ILLEGAL_ISR,                    // Illegal Operation Trap
    USER1_ISR,                      // User Defined Trap 1
    USER2_ISR,                      // User Defined Trap 2
    USER3_ISR,                      // User Defined Trap 3
    USER4_ISR,                      // User Defined Trap 4
    USER5_ISR,                      // User Defined Trap 5
    USER6_ISR,                      // User Defined Trap 6
    USER7_ISR,                      // User Defined Trap 7
    USER8_ISR,                      // User Defined Trap 8
    USER9_ISR,                      // User Defined Trap 9
    USER10_ISR,                     // User Defined Trap 10
    USER11_ISR,                     // User Defined Trap 11
    USER12_ISR,                     // User Defined Trap 12
    ADCA1_ISR,                      // 1.1 - ADCA Interrupt 1
    PIE_RESERVED_ISR,               // 1.2 - Reserved
    ADCC1_ISR,                      // 1.3 - ADCC Interrupt 1
    XINT1_ISR,                      // 1.4 - XINT1 Interrupt
    XINT2_ISR,                      // 1.5 - XINT2 Interrupt
    PIE_RESERVED_ISR,               // 1.6 - Reserved
    TIMER0_ISR,                     // 1.7 - Timer 0 Interrupt
    WAKE_ISR,                       // 1.8 - Standby and Halt Wakeup Interrupt
    EPWM1_TZ_ISR,                   // 2.1 - ePWM1 Trip Zone Interrupt
    EPWM2_TZ_ISR,                   // 2.2 - ePWM2 Trip Zone Interrupt
    EPWM3_TZ_ISR,                   // 2.3 - ePWM3 Trip Zone Interrupt
    EPWM4_TZ_ISR,                   // 2.4 - ePWM4 Trip Zone Interrupt
    EPWM5_TZ_ISR,                   // 2.5 - ePWM5 Trip Zone Interrupt
    EPWM6_TZ_ISR,                   // 2.6 - ePWM6 Trip Zone Interrupt
    EPWM7_TZ_ISR,                   // 2.7 - ePWM7 Trip Zone Interrupt
    PIE_RESERVED_ISR,               // 2.8 - Reserved
    EPWM1_ISR,                      // 3.1 - ePWM1 Interrupt
    EPWM2_ISR,                      // 3.2 - ePWM2 Interrupt
    EPWM3_ISR,                      // 3.3 - ePWM3 Interrupt
    EPWM4_ISR,                      // 3.4 - ePWM4 Interrupt
    EPWM5_ISR,                      // 3.5 - ePWM5 Interrupt
    EPWM6_ISR,                      // 3.6 - ePWM6 Interrupt
    EPWM7_ISR,                      // 3.7 - ePWM7 Interrupt
    PIE_RESERVED_ISR,               // 3.8 - Reserved
    ECAP1_ISR,                      // 4.1 - eCAP1 Interrupt
    ECAP2_ISR,                      // 4.2 - eCAP2 Interrupt
    ECAP3_ISR,                      // 4.3 - eCAP3 Interrupt
    PIE_RESERVED_ISR,               // 4.4 - Reserved
    PIE_RESERVED_ISR,               // 4.5 - Reserved
    PIE_RESERVED_ISR,               // 4.6 - Reserved
    PIE_RESERVED_ISR,               // 4.7 - Reserved
    PIE_RESERVED_ISR,               // 4.8 - Reserved
    EQEP1_ISR,                      // 5.1 - eQEP1 Interrupt
    EQEP2_ISR,                      // 5.2 - eQEP2 Interrupt
    PIE_RESERVED_ISR,               // 5.3 - Reserved
    PIE_RESERVED_ISR,               // 5.4 - Reserved
    CLB1_ISR,                       // 5.5 - CLB1 (Reconfigurable Logic) Interrupt
    CLB2_ISR,                       // 5.6 - CLB2 (Reconfigurable Logic) Interrupt
    PIE_RESERVED_ISR,               // 5.7 - Reserved
    PIE_RESERVED_ISR,               // 5.8 - Reserved
    SPIA_RX_ISR,                    // 6.1 - SPIA Receive Interrupt
    SPIA_TX_ISR,                    // 6.2 - SPIA Transmit Interrupt
    SPIB_RX_ISR,                    // 6.3 - SPIB Receive Interrupt
    SPIB_TX_ISR,                    // 6.4 - SPIB Transmit Interrupt
    PIE_RESERVED_ISR,               // 6.5 - Reserved
    PIE_RESERVED_ISR,               // 6.6 - Reserved
    PIE_RESERVED_ISR,               // 6.7 - Reserved
    PIE_RESERVED_ISR,               // 6.8 - Reserved
    DMA_CH1_ISR,                    // 7.1 - DMA Channel 1 Interrupt
    DMA_CH2_ISR,                    // 7.2 - DMA Channel 2 Interrupt
    DMA_CH3_ISR,                    // 7.3 - DMA Channel 3 Interrupt
    DMA_CH4_ISR,                    // 7.4 - DMA Channel 4 Interrupt
    DMA_CH5_ISR,                    // 7.5 - DMA Channel 5 Interrupt
    DMA_CH6_ISR,                    // 7.6 - DMA Channel 6 Interrupt
    PIE_RESERVED_ISR,               // 7.7 - Reserved
    PIE_RESERVED_ISR,               // 7.8 - Reserved
    I2CA_ISR,                       // 8.1 - I2CA Interrupt 1
    I2CA_FIFO_ISR,                  // 8.2 - I2CA Interrupt 2
    I2CB_ISR,                       // 8.3 - I2CB Interrupt 1
    I2CB_FIFO_ISR,                  // 8.4 - I2CB Interrupt 2
    PIE_RESERVED_ISR,               // 8.5 - Reserved
    PIE_RESERVED_ISR,               // 8.6 - Reserved
    PIE_RESERVED_ISR,               // 8.7 - Reserved
    PIE_RESERVED_ISR,               // 8.8 - Reserved
    SCIA_RX_ISR,                    // 9.1 - SCIA Receive Interrupt
    SCIA_TX_ISR,                    // 9.2 - SCIA Transmit Interrupt
    PIE_RESERVED_ISR,               // 9.3 - Reserved
    PIE_RESERVED_ISR,               // 9.4 - Reserved
    CANA0_ISR,                      // 9.5 - CANA Interrupt 0
    CANA1_ISR,                      // 9.6 - CANA Interrupt 1
    PIE_RESERVED_ISR,               // 9.7 - Reserved
    PIE_RESERVED_ISR,               // 9.8 - Reserved
    ADCA_EVT_ISR,                   // 10.1 - ADCA Event Interrupt
    ADCA2_ISR,                      // 10.2 - ADCA Interrupt 2
    ADCA3_ISR,                      // 10.3 - ADCA Interrupt 3
    ADCA4_ISR,                      // 10.4 - ADCA Interrupt 4
    PIE_RESERVED_ISR,               // 10.5 - Reserved
    PIE_RESERVED_ISR,               // 10.6 - Reserved
    PIE_RESERVED_ISR,               // 10.7 - Reserved
    PIE_RESERVED_ISR,               // 10.8 - Reserved
    PIE_RESERVED_ISR,               // 11.1 - Reserved
    PIE_RESERVED_ISR,               // 11.2 - Reserved
    PIE_RESERVED_ISR,               // 11.3 - Reserved
    PIE_RESERVED_ISR,               // 11.4 - Reserved
    PIE_RESERVED_ISR,               // 11.5 - Reserved
    PIE_RESERVED_ISR,               // 11.6 - Reserved
    PIE_RESERVED_ISR,               // 11.7 - Reserved
    PIE_RESERVED_ISR,               // 11.8 - Reserved
    XINT3_ISR,                      // 12.1 - XINT3 Interrupt
    XINT4_ISR,                      // 12.2 - XINT4 Interrupt
    XINT5_ISR,                      // 12.3 - XINT5 Interrupt
    MPOST_ISR,                      // 12.4 - MPOST Interrupt
    FMC_ISR,                        // 12.5 - Flash Wrapper Operation Done Interrupt
    PIE_RESERVED_ISR,               // 12.6 - Reserved
    FPU_OVERFLOW_ISR,               // 12.7 - FPU Overflow Interrupt
    FPU_UNDERFLOW_ISR,              // 12.8 - FPU Underflow Interrupt
    PIE_RESERVED_ISR,               // 1.9 - Reserved
    PIE_RESERVED_ISR,               // 1.10 - Reserved
    PIE_RESERVED_ISR,               // 1.11 - Reserved
    PIE_RESERVED_ISR,               // 1.12 - Reserved
    PIE_RESERVED_ISR,               // 1.13 - Reserved
    PIE_RESERVED_ISR,               // 1.14 - Reserved
    PIE_RESERVED_ISR,               // 1.15 - Reserved
    PIE_RESERVED_ISR,               // 1.16 - Reserved
    PIE_RESERVED_ISR,               // 2.9 - Reserved
    PIE_RESERVED_ISR,               // 2.10 - Reserved
    PIE_RESERVED_ISR,               // 2.11 - Reserved
    PIE_RESERVED_ISR,               // 2.12 - Reserved
    PIE_RESERVED_ISR,               // 2.13 - Reserved
    PIE_RESERVED_ISR,               // 2.14 - Reserved
    PIE_RESERVED_ISR,               // 2.15 - Reserved
    PIE_RESERVED_ISR,               // 2.16 - Reserved
    PIE_RESERVED_ISR,               // 3.9 - Reserved
    PIE_RESERVED_ISR,               // 3.10 - Reserved
    PIE_RESERVED_ISR,               // 3.11 - Reserved
    PIE_RESERVED_ISR,               // 3.12 - Reserved
    PIE_RESERVED_ISR,               // 3.13 - Reserved
    PIE_RESERVED_ISR,               // 3.14 - Reserved
    PIE_RESERVED_ISR,               // 3.15 - Reserved
    PIE_RESERVED_ISR,               // 3.16 - Reserved
    PIE_RESERVED_ISR,               // 4.9 - Reserved
    PIE_RESERVED_ISR,               // 4.10 - Reserved
    ECAP3_2_ISR,                    // 4.11 - eCAP3_2 Interrupt
    PIE_RESERVED_ISR,               // 4.12 - Reserved
    PIE_RESERVED_ISR,               // 4.13 - Reserved
    PIE_RESERVED_ISR,               // 4.14 - Reserved
    PIE_RESERVED_ISR,               // 4.15 - Reserved
    PIE_RESERVED_ISR,               // 4.16 - Reserved
    PIE_RESERVED_ISR,               // 5.9 - Reserved
    PIE_RESERVED_ISR,               // 5.10 - Reserved
    PIE_RESERVED_ISR,               // 5.11 - Reserved
    PIE_RESERVED_ISR,               // 5.12 - Reserved
    PIE_RESERVED_ISR,               // 5.13 - Reserved
    PIE_RESERVED_ISR,               // 5.14 - Reserved
    PIE_RESERVED_ISR,               // 5.15 - Reserved
    PIE_RESERVED_ISR,               // 5.16 - Reserved
    PIE_RESERVED_ISR,               // 6.9 - Reserved
    PIE_RESERVED_ISR,               // 6.10 - Reserved
    PIE_RESERVED_ISR,               // 6.11 - Reserved
    PIE_RESERVED_ISR,               // 6.12 - Reserved
    PIE_RESERVED_ISR,               // 6.13 - Reserved
    PIE_RESERVED_ISR,               // 6.14 - Reserved
    PIE_RESERVED_ISR,               // 6.15 - Reserved
    PIE_RESERVED_ISR,               // 6.16 - Reserved
    PIE_RESERVED_ISR,               // 7.9 - Reserved
    PIE_RESERVED_ISR,               // 7.10 - Reserved
    FSITXA1_ISR,                    // 7.11 - FSITXA_INT1 Interrupt
    FSITXA2_ISR,                    // 7.12 - FSITXA_INT2 Interrupt
    FSIRXA1_ISR,                    // 7.13 - FSIRXA_INT1 Interrupt
    FSIRXA2_ISR,                    // 7.14 - FSIRXA_INT2 Interrupt
    PIE_RESERVED_ISR,               // 7.15 - Reserved
    DCC0_ISR,                       // 7.16 - DCC0 Interrupt
    LINA_0_ISR,                     // 8.9 - LINA Interrupt0
    LINA_1_ISR,                     // 8.10 - LINA Interrupt1
    LINB_0_ISR,                     // 8.11 - LINB Interrupt0
    LINB_1_ISR,                     // 8.12 - LINB Interrupt1
    PMBUSA_ISR,                     // 8.13 - PMBUSA Interrupt
    PIE_RESERVED_ISR,               // 8.14 - Reserved
    PIE_RESERVED_ISR,               // 8.15 - Reserved
    DCC1_ISR,                       // 8.16 - DCC1 Interrupt
    PIE_RESERVED_ISR,               // 9.9 - Reserved
    PIE_RESERVED_ISR,               // 9.10 - Reserved
    PIE_RESERVED_ISR,               // 9.11 - Reserved
    PIE_RESERVED_ISR,               // 9.12 - Reserved
    BGCRC_ISR,                      // 9.13 - BGCRC
    PIE_RESERVED_ISR,               // 9.14 - Reserved
    PIE_RESERVED_ISR,               // 9.15 - Reserved
    HICA_ISR,                       // 9.16 - HICA Interrupt
    ADCC_EVT_ISR,                   // 10.9 - ADCC Event Interrupt
    ADCC2_ISR,                      // 10.10 - ADCC Interrupt 2
    ADCC3_ISR,                      // 10.11 - ADCC Interrupt 3
    ADCC4_ISR,                      // 10.12 - ADCC Interrupt 4
    PIE_RESERVED_ISR,               // 10.13 - Reserved
    PIE_RESERVED_ISR,               // 10.14 - Reserved
    PIE_RESERVED_ISR,               // 10.15 - Reserved
    PIE_RESERVED_ISR,               // 10.16 - Reserved
    PIE_RESERVED_ISR,               // 11.9 - Reserved
    PIE_RESERVED_ISR,               // 11.10 - Reserved
    PIE_RESERVED_ISR,               // 11.11 - Reserved
    PIE_RESERVED_ISR,               // 11.12 - Reserved
    PIE_RESERVED_ISR,               // 11.13 - Reserved
    PIE_RESERVED_ISR,               // 11.14 - Reserved
    PIE_RESERVED_ISR,               // 11.15 - Reserved
    PIE_RESERVED_ISR,               // 11.16 - Reserved
    PIE_RESERVED_ISR,               // 12.9 - Reserved
    RAM_CORR_ERR_ISR,               // 12.10 - RAM Correctable Error Interrupt
    FLASH_CORR_ERR_ISR,             // 12.11 - Flash Correctable Error Interrupt
    RAM_ACC_VIOL_ISR,               // 12.12 - RAM Access Violation Interrupt
    SYS_PLL_SLIP_ISR,               // 12.13 - System PLL Interrupt
    PIE_RESERVED_ISR,               // 12.14 - Reserved
    PIE_RESERVED_ISR,               // 12.15 - Reserved
    PIE_RESERVED_ISR,               // 12.16 - Reserved
};

//
// InitPieVectTable - This function initializes the PIE vector table to a
//                    known state and must be executed after boot time.
//
void InitPieVectTable(void)
{
    Uint16 i;
    Uint32 *Source = (void *) &PieVectTableInit;
    Uint32 *Dest = (void *) &PieVectTable;

    //
    // Do not write over first 3 32-bit locations (these locations are
    // initialized by Boot ROM with boot variables)
    //
    Source = Source + 3;
    Dest = Dest + 3;

    EALLOW;
    for(i = 0; i < 221; i++)
    {
    	*Dest++ = *Source++;
    }
    EDIS;

    //
    // Enable the PIE Vector Table
    //
    PieCtrlRegs.PIECTRL.bit.ENPIE = 1;
}

//
// End of file
//
