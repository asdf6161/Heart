################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../cpp/Blink.cpp \
../cpp/BlinkHeart.cpp 

OBJS += \
./cpp/Blink.o \
./cpp/BlinkHeart.o 

CPP_DEPS += \
./cpp/Blink.d \
./cpp/BlinkHeart.d 


# Each subdirectory must supply rules for building sources it contributes
cpp/%.o: ../cpp/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: MCU G++ Compiler'
	@echo $(PWD)
	arm-none-eabi-g++ -mcpu=cortex-m0 -mthumb -mfloat-abi=soft  -I"C:/Projects/CubeMX/Heart/Inc" -I"C:/Projects/CubeMX/Heart/Drivers/STM32F0xx_HAL_Driver/Inc" -I"C:/Projects/CubeMX/Heart/Drivers/STM32F0xx_HAL_Driver/Inc/Legacy" -I"C:/Projects/CubeMX/Heart/Drivers/CMSIS/Device/ST/STM32F0xx/Include" -I"C:/Projects/CubeMX/Heart/Drivers/CMSIS/Include"  -O3 -g -Wall -fmessage-length=0 -ffunction-sections -c -fno-exceptions -fno-rtti -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


