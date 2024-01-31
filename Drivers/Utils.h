/*
 * File:   Utils.h
 * Author: Mohamed Hussein
 * Date:   December 12 , 2023 (Date of creation)
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

#ifndef UTILS_H_
#define UTILS_H_

// This macro sets a specific bit in a register
#define SET_BIT(REG, BIT)   (REG |= 1 << BIT)

// This macro clears a specific bit in a register
#define CLEAR_BIT(REG, BIT) (REG &= ~(1 << BIT))

// This macro reads a specific bit from a register
#define READ_BIT(REG, BIT)  ((REG >> BIT) & 1)

// This macro toggles a specific bit in a register
#define TOGGLE_BIT(REG, BIT) (REG ^= (1 << BIT))

// This macro modifies a specific number of bits in a register starting from a given bit position
#define MOD_NUM_OF_BITS(REG, START_BIT, NUM_OF_BITS, VAL) {\
    uint32_t mask = (1 << NUM_OF_BITS) - 1 ;\
    uint32_t clear_mask = ~(mask << START_BIT) ;\
    uint32_t val = (VAL & mask) << START_BIT ;\
    REG = (REG & clear_mask) | val ;\
}
#endif /* UTILS_H_ */
