#include <stdio.h>

void SystemInitStage2(void);


void SystemInitStage2(void)
{

    /* All system initialization code should go here. */
    /* - Unlocks and disables WDT.
     * - Calls Cy_PDL_Init() function to define the driver library.
     * - Calls the Cy_SystemInit() function, if compiled from PSoC Creator.
     * - Calls \ref SystemCoreClockUpdate().
     */
    //printf("\nSystem Init Stage 2\n");


    return;
}
