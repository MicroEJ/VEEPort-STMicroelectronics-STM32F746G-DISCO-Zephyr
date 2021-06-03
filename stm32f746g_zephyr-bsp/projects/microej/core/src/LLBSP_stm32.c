/*
 * C
 *
 * Copyright 2021 MicroEJ Corp. All rights reserved.
 * This library is provided in source code for use, modification and test, subject to license terms.
 * Any modification of the source code will break MicroEJ Corp. warranties on the whole library.
 */

/******************************************************************************
Includes   <System Includes> , "Project Includes"
 ******************************************************************************/

#include <stdio.h>
#include <zephyr.h>

#include "LLBSP_impl.h"
#include "microej.h"

extern void* SOAR_START;
extern void* SOAR_END;

/*******************************************************************************
 * Function Name: LLBSP_IMPL_isInReadOnlyMemory
 * Description  : checks if the given pointer is in a read only memory or not.
 *******************************************************************************/
uint8_t LLBSP_IMPL_isInReadOnlyMemory(void* ptr)
{
    uint8_t result = MICROEJ_FALSE;
    if ((uint32_t)ptr >= (uint32_t)&SOAR_START && (uint32_t)ptr <= (uint32_t)&SOAR_END)
    {
        result = MICROEJ_TRUE;
    }
    return result;
}

/*******************************************************************************
 * Function Name: LLBSP_IMPL_putchar
 * Description  : puts the character to stdout stream.
 *******************************************************************************/
void LLBSP_IMPL_putchar(int32_t c)
{
    putchar(c);
}

/* End of File */
