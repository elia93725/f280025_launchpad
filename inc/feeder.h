/*
 * feeder.h
 *
 *  Created on: 17 feb 2025
 *      Author: EliaMura
 */

#ifndef INC_FEEDER_H_
#define INC_FEEDER_H_

#include"F28x_Project.h"


typedef enum{

    STANDBY_MODE,
    WRITE_SINGLE,
    READ_SINGLE,
    WRITE_MULTIPLE,
    READ_MULTIPLE,
    READ_VERSION,
    FEEDING_ERROR,
    CONNECTION_ERROR

}Feeder_Commands;


typedef struct{

    uint16_t Write;
    uint16_t Read;
    uint16_t Feed;
    uint16_t WriteServoParam;

}OFS_Commands;




void Setup_CAN_Write_Regs();




#endif /* INC_FEEDER_H_ */
