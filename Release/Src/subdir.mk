################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/main.c \
../Src/stm32f0xx_hal_msp.c \
../Src/stm32f0xx_it.c \
../Src/system_stm32f0xx.c 

CPP_SRCS += \
../Src/main.cpp 

OBJS += \
./Src/main.o \
./Src/stm32f0xx_hal_msp.o \
./Src/stm32f0xx_it.o \
./Src/system_stm32f0xx.o 

C_DEPS += \
./Src/main.d \
./Src/stm32f0xx_hal_msp.d \
./Src/stm32f0xx_it.d \
./Src/system_stm32f0xx.d 

CPP_DEPS += \
./Src/main.d 


# Each subdirectory must supply rules for building sources it contributes
Src/%.o: ../Src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m0 -mthumb -mfloat-abi=soft '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32F030x6 -I"C:/Projects/CubeMX/Heart/Inc" -I"C:/Projects/CubeMX/Heart/Drivers/STM32F0xx_HAL_Driver/Inc" -I"C:/Projects/CubeMX/Heart/Drivers/STM32F0xx_HAL_Driver/Inc/Legacy" -I"C:/Projects/CubeMX/Heart/Drivers/CMSIS/Device/ST/STM32F0xx/Include" -I"C:/Projects/CubeMX/Heart/Drivers/CMSIS/Include"  -Og -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Src/%.o: ../Src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: MCU G++ Compiler'
	@echo $(PWD)
	arm-none-eabi-g++ -mcpu=cortex-m0 -mthumb -mfloat-abi=soft  -I"C:/Projects/CubeMX/Heart/Inc" -I"C:/Projects/CubeMX/Heart/Drivers/STM32F0xx_HAL_Driver/Inc" -I"C:/Projects/CubeMX/Heart/Drivers/STM32F0xx_HAL_Driver/Inc/Legacy" -I"C:/Projects/CubeMX/Heart/Drivers/CMSIS/Device/ST/STM32F0xx/Include" -I"C:/Projects/CubeMX/Heart/Drivers/CMSIS/Include"  -O3 -g -Wall -fmessage-length=0 -ffunction-sections -c -fno-exceptions -fno-rtti -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


