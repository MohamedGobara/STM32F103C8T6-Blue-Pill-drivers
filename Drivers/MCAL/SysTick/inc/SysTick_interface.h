#ifndef SYSTICK_INTERFACE_H
#define SYSTICK_INTERFACE_H

/*
 * File:   SysTick.h
 * Author: Mohamed Hussein
 * Date:   February 13, 2024 (Date of creation)
 *
 * Description:
 * ------------
 * This header file contains declarations for the SysTick timer module on STM32 microcontrollers.
 * It defines constants, macros, and function prototypes related to the SysTick timer.
 *
 * Usage:
 * ------
 * 1. Include this file in your project to access SysTick timer functionalities.
 * 2. Ensure that the necessary SysTick configuration header file is included.
 * 3. Use the provided constants, macros, and function prototypes to configure and utilize the SysTick timer
 *    for timing and delay operations in your application.
 *
 */

#include <stdint.h> // Include standard integer types

#include "Utils.h" // Include utility functions
#include "STDTypes.h" // Include standard types

#include "SysTick/inc/SysTick_config.h" // Include SysTick configuration header file
#include "SysTick/inc/SysTick_private.h" // Include private SysTick header file

/**
 * @brief Initialize the SysTick timer.
 * This function initializes the SysTick timer with the configured settings.
 * Call this function before using any other SysTick functions.
 */
void SysTick_vInit(void);

/**
 * @brief Delay for a specified duration in microseconds.
 * @param local_time: The time to delay in microseconds.
 * Note: This function is a busy-wait delay and may not be precise for long durations.
 */
void SysTick_vDelayus(const uint32_t local_time);

/**
 * @brief Delay for a specified duration in milliseconds.
 * @param local_time: The time to delay in milliseconds.
 * Note: This function is a busy-wait delay and may not be precise for long durations.
 */
void SysTick_vDelayms(uint32_t local_time);

/**
 * @brief Delay for a specified duration in microseconds, executing a callback function periodically.
 * @param local_time: The time to delay in microseconds.
 * @param local_ptrFun: A pointer to the function to be executed periodically during the delay.
 * Note: This function is a busy-wait delay and may not be precise for long durations.
 */
void SysTick_vFunUS(const uint32_t local_time, void (*local_ptrFun)(void));

#endif /* SYSTICK_INTERFACE_H */
