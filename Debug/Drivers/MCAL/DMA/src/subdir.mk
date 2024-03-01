################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/MCAL/DMA/src/DMA_program.c 

OBJS += \
./Drivers/MCAL/DMA/src/DMA_program.o 

C_DEPS += \
./Drivers/MCAL/DMA/src/DMA_program.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/MCAL/DMA/src/%.o Drivers/MCAL/DMA/src/%.su Drivers/MCAL/DMA/src/%.cyclo: ../Drivers/MCAL/DMA/src/%.c Drivers/MCAL/DMA/src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -c -I../Inc -I"D:/Projects/ARM course24/pandaKit/Drivers" -I"D:/Projects/ARM course24/pandaKit/Drivers/HAL" -I"D:/Projects/ARM course24/pandaKit/Drivers/LIB" -I"D:/Projects/ARM course24/pandaKit/Drivers/MCAL" -I"D:/Projects/ARM course24/pandaKit/Drivers/Services" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Drivers-2f-MCAL-2f-DMA-2f-src

clean-Drivers-2f-MCAL-2f-DMA-2f-src:
	-$(RM) ./Drivers/MCAL/DMA/src/DMA_program.cyclo ./Drivers/MCAL/DMA/src/DMA_program.d ./Drivers/MCAL/DMA/src/DMA_program.o ./Drivers/MCAL/DMA/src/DMA_program.su

.PHONY: clean-Drivers-2f-MCAL-2f-DMA-2f-src

