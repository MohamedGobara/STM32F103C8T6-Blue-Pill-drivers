################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/MCAL/RCC/src/RCC_program.c 

OBJS += \
./Drivers/MCAL/RCC/src/RCC_program.o 

C_DEPS += \
./Drivers/MCAL/RCC/src/RCC_program.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/MCAL/RCC/src/%.o Drivers/MCAL/RCC/src/%.su Drivers/MCAL/RCC/src/%.cyclo: ../Drivers/MCAL/RCC/src/%.c Drivers/MCAL/RCC/src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -c -I../Inc -I"D:/Projects/ARM course24/pandaKit/Drivers" -I"D:/Projects/ARM course24/pandaKit/Drivers/HAL" -I"D:/Projects/ARM course24/pandaKit/Drivers/LIB" -I"D:/Projects/ARM course24/pandaKit/Drivers/MCAL" -I"D:/Projects/ARM course24/pandaKit/Drivers/Services" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Drivers-2f-MCAL-2f-RCC-2f-src

clean-Drivers-2f-MCAL-2f-RCC-2f-src:
	-$(RM) ./Drivers/MCAL/RCC/src/RCC_program.cyclo ./Drivers/MCAL/RCC/src/RCC_program.d ./Drivers/MCAL/RCC/src/RCC_program.o ./Drivers/MCAL/RCC/src/RCC_program.su

.PHONY: clean-Drivers-2f-MCAL-2f-RCC-2f-src

