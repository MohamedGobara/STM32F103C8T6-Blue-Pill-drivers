################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/MCAL/NVIC/src/NVIC_config.c \
../Drivers/MCAL/NVIC/src/NVIC_program.c 

OBJS += \
./Drivers/MCAL/NVIC/src/NVIC_config.o \
./Drivers/MCAL/NVIC/src/NVIC_program.o 

C_DEPS += \
./Drivers/MCAL/NVIC/src/NVIC_config.d \
./Drivers/MCAL/NVIC/src/NVIC_program.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/MCAL/NVIC/src/%.o Drivers/MCAL/NVIC/src/%.su Drivers/MCAL/NVIC/src/%.cyclo: ../Drivers/MCAL/NVIC/src/%.c Drivers/MCAL/NVIC/src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -c -I../Inc -I"D:/Projects/ARM course/pandaKit/Drivers" -I"D:/Projects/ARM course/pandaKit/Drivers/HAL" -I"D:/Projects/ARM course/pandaKit/Drivers/LIB" -I"D:/Projects/ARM course/pandaKit/Drivers/MCAL" -I"D:/Projects/ARM course/pandaKit/Drivers/Services" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Drivers-2f-MCAL-2f-NVIC-2f-src

clean-Drivers-2f-MCAL-2f-NVIC-2f-src:
	-$(RM) ./Drivers/MCAL/NVIC/src/NVIC_config.cyclo ./Drivers/MCAL/NVIC/src/NVIC_config.d ./Drivers/MCAL/NVIC/src/NVIC_config.o ./Drivers/MCAL/NVIC/src/NVIC_config.su ./Drivers/MCAL/NVIC/src/NVIC_program.cyclo ./Drivers/MCAL/NVIC/src/NVIC_program.d ./Drivers/MCAL/NVIC/src/NVIC_program.o ./Drivers/MCAL/NVIC/src/NVIC_program.su

.PHONY: clean-Drivers-2f-MCAL-2f-NVIC-2f-src

