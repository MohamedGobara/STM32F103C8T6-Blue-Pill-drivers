################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/HAL/LCD/src/LCD_config.c \
../Drivers/HAL/LCD/src/LCD_program.c 

OBJS += \
./Drivers/HAL/LCD/src/LCD_config.o \
./Drivers/HAL/LCD/src/LCD_program.o 

C_DEPS += \
./Drivers/HAL/LCD/src/LCD_config.d \
./Drivers/HAL/LCD/src/LCD_program.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/HAL/LCD/src/%.o Drivers/HAL/LCD/src/%.su Drivers/HAL/LCD/src/%.cyclo: ../Drivers/HAL/LCD/src/%.c Drivers/HAL/LCD/src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -c -I../Inc -I"D:/Projects/ARM course24/pandaKit/Drivers" -I"D:/Projects/ARM course24/pandaKit/Drivers/HAL" -I"D:/Projects/ARM course24/pandaKit/Drivers/LIB" -I"D:/Projects/ARM course24/pandaKit/Drivers/MCAL" -I"D:/Projects/ARM course24/pandaKit/Drivers/Services" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Drivers-2f-HAL-2f-LCD-2f-src

clean-Drivers-2f-HAL-2f-LCD-2f-src:
	-$(RM) ./Drivers/HAL/LCD/src/LCD_config.cyclo ./Drivers/HAL/LCD/src/LCD_config.d ./Drivers/HAL/LCD/src/LCD_config.o ./Drivers/HAL/LCD/src/LCD_config.su ./Drivers/HAL/LCD/src/LCD_program.cyclo ./Drivers/HAL/LCD/src/LCD_program.d ./Drivers/HAL/LCD/src/LCD_program.o ./Drivers/HAL/LCD/src/LCD_program.su

.PHONY: clean-Drivers-2f-HAL-2f-LCD-2f-src

