/*
 * C
 *
 * Copyright 2021 MicroEJ Corp. All rights reserved.
 * This library is provided in source code for use, modification and test, subject to license terms.
 * Any modification of the source code will break MicroEJ Corp. warranties on the whole library.
 */

#include <stdio.h>
#include <zephyr.h>

#include "microjvm_main.h"
#include "sni.h"

/******************************************************
 *                    Constants
 ******************************************************/

/* MicroJvm task constants */
#define MICROJVM_STACK_SIZE                (21 * 1024)
#define JAVA_TASK_PRIORITY                 (8) 

/******************************************************
 *               Static Function Declarations
 ******************************************************/

static void xJavaTaskFunction(void * param1, void * param2, void * param3)
{
    microjvm_main();
}

K_THREAD_DEFINE(jvm_thread, MICROJVM_STACK_SIZE,
                xJavaTaskFunction, NULL, NULL, NULL,
                JAVA_TASK_PRIORITY, 0, 0);

jdouble Java_com_microej_core_tests_MicroejCoreValidation_testDouble(jdouble a, jdouble b)
{
    return a * b;
}

jfloat Java_com_microej_core_tests_MicroejCoreValidation_testFloat(jfloat a, jfloat b)
{
    return a * b;
}
