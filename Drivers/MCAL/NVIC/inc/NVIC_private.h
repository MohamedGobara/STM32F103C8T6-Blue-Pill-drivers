#ifndef NVIC_PRIVATE_H
#define NVIC_PRIVATE_H

// Define the key value for accessing NVIC registers
#define VECT_KEY 0x5FA

// Define a structure representing NVIC registers
typedef struct {
    volatile uint32_t ISER[32];  // Interrupt Set-Enable Register
    volatile uint32_t ICER[32];  // Interrupt Clear-Enable Register
    volatile uint32_t ISPR[32];  // Interrupt Set-Pending Register
    volatile uint32_t ICPR[32];  // Interrupt Clear-Pending Register
    volatile uint32_t IABR[64];  // Interrupt Active Bit Register
    volatile uint8_t IPR[0xAE0]; // Interrupt Priority Register
    volatile uint32_t STIR;      // Software Trigger Interrupt Register
} NVIC_REG;

// Define the base address for NVIC registers
#define NVIC_BASEADDRESS  0xE000E100U

// Create a pointer to NVIC register structure, pointing to the base address of NVIC
#define NVIC              ((NVIC_REG*)NVIC_BASEADDRESS)

// Define the address of the Application Interrupt and Reset Control Register (AIRCR) in the System Control Block (SCB)
#define SCB_AIRCR          *(volatile uint32_t*)(0xE000ED0C)

#endif /* NVIC_PRIVATE_H */
