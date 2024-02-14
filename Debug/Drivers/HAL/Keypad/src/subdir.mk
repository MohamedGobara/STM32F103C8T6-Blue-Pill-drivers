################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/HAL/Keypad/src/Keypad_config.c \
../Drivers/HAL/Keypad/src/Keypad_program.c 

OBJS += \
./Drivers/HAL/Keypad/src/Keypad_config.o \
./Drivers/HAL/Keypad/src/Keypad_program.o 

C_DEPS += \
./Drivers/HAL/Keypad/src/Keypad_config.d \
./Drivers/HAL/Keypad/src/Keypad_program.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/HAL/Keypad/src/%.o Drivers/HAL/Keypad/src/%.su Drivers/HAL/Keypad/src/%.cyclo: ../Drivers/HAL/Keypad/src/%.c Drivers/HAL/Keypad/src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -c -I../Inc -I"D:/Projects/ARM course/pandaKit/Drivers" -I"D:/Projects/ARM course/pandaKit/Drivers/HAL" -I"D:/Projects/ARM course/pandaKit/Drivers/LIB" -I"D:/Projects/ARM course/pandaKit/Drivers/MCAL" -I"D:/Projects/ARM course/pandaKit/Drivers/Services" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Drivers-2f-HAL-2f-Keypad-2f-src

clean-Drivers-2f-HAL-2f-Keypad-2f-src:
	-$(RM) ./Drivers/HAL/Keypad/src/Keypad_config.cyclo ./Drivers/HAL/Keypad/src/Keypad_config.d ./Drivers/HAL/Keypad/src/Keypad_config.o ./Drivers/HAL/Keypad/src/Keypad_config.su ./Drivers/HAL/Keypad/src/Keypad_program.cyclo ./Drivers/HAL/Keypad/src/Keypad_program.d ./Drivers/HAL/Keypad/src/Keypad_program.o ./Drivers/HAL/Keypad/src/Keypad_program.su

.PHONY: clean-Drivers-2f-HAL-2f-Keypad-2f-src

