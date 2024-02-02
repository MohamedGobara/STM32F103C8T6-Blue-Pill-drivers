/*
 * File:   STDTybes.h
 * Author: Mohamed Hussein
 * Date:   December 16 , 2023 (Date of creation)
 *
 * Description:
 * ------------
 * Briefly describe the purpose and functionality of this code file.
 * Include any relevant information about the code's usage, algorithms used, or notable features.
 *
 * Usage:
 * ------
 * Explain how to use or integrate this code, including function calls, inputs, and outputs.
 * If this file is part of a larger project, mention its role in the project's architecture.
 *
 */

#ifndef STDTYPES_H_
#define STDTYPES_H_

#define NULL      0
#define NULL_FPTR (void*)0

// Define a custom boolean enumeration with values FALSE and TRUE
typedef enum {
    FALSE = 0, // FALSE is assigned 0
    TRUE,      // TRUE is assigned 1 (implicitly)
} TF_t;


// Define an enumeration for return status values
typedef enum {
    ERROR_ret = 0,    // Indicates an error condition, assigned 0
    OK_ret,           // Indicates successful completion, assigned 1
    TimeOut_ret,      // Indicates a timeout condition, assigned 2
} RETURN_t;




#endif /* STDTYPES_H_ */
