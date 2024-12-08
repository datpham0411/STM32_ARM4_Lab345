################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/button.c \
../Core/Src/clock_automatic.c \
../Core/Src/clock_manual.c \
../Core/Src/clock_setting.c \
../Core/Src/clock_update.c \
../Core/Src/ds3231.c \
../Core/Src/fsm_automatic.c \
../Core/Src/fsm_manual.c \
../Core/Src/fsm_setting.c \
../Core/Src/global.c \
../Core/Src/i2c.c \
../Core/Src/lcd.c \
../Core/Src/led7_segment.c \
../Core/Src/led_7seg.c \
../Core/Src/main.c \
../Core/Src/picture.c \
../Core/Src/software_timer.c \
../Core/Src/spi.c \
../Core/Src/stm32f4xx_hal_msp.c \
../Core/Src/stm32f4xx_it.c \
../Core/Src/syscalls.c \
../Core/Src/sysmem.c \
../Core/Src/system_stm32f4xx.c \
../Core/Src/traffic_light.c \
../Core/Src/uart.c \
../Core/Src/usart.c \
../Core/Src/utils.c 

OBJS += \
./Core/Src/button.o \
./Core/Src/clock_automatic.o \
./Core/Src/clock_manual.o \
./Core/Src/clock_setting.o \
./Core/Src/clock_update.o \
./Core/Src/ds3231.o \
./Core/Src/fsm_automatic.o \
./Core/Src/fsm_manual.o \
./Core/Src/fsm_setting.o \
./Core/Src/global.o \
./Core/Src/i2c.o \
./Core/Src/lcd.o \
./Core/Src/led7_segment.o \
./Core/Src/led_7seg.o \
./Core/Src/main.o \
./Core/Src/picture.o \
./Core/Src/software_timer.o \
./Core/Src/spi.o \
./Core/Src/stm32f4xx_hal_msp.o \
./Core/Src/stm32f4xx_it.o \
./Core/Src/syscalls.o \
./Core/Src/sysmem.o \
./Core/Src/system_stm32f4xx.o \
./Core/Src/traffic_light.o \
./Core/Src/uart.o \
./Core/Src/usart.o \
./Core/Src/utils.o 

C_DEPS += \
./Core/Src/button.d \
./Core/Src/clock_automatic.d \
./Core/Src/clock_manual.d \
./Core/Src/clock_setting.d \
./Core/Src/clock_update.d \
./Core/Src/ds3231.d \
./Core/Src/fsm_automatic.d \
./Core/Src/fsm_manual.d \
./Core/Src/fsm_setting.d \
./Core/Src/global.d \
./Core/Src/i2c.d \
./Core/Src/lcd.d \
./Core/Src/led7_segment.d \
./Core/Src/led_7seg.d \
./Core/Src/main.d \
./Core/Src/picture.d \
./Core/Src/software_timer.d \
./Core/Src/spi.d \
./Core/Src/stm32f4xx_hal_msp.d \
./Core/Src/stm32f4xx_it.d \
./Core/Src/syscalls.d \
./Core/Src/sysmem.d \
./Core/Src/system_stm32f4xx.d \
./Core/Src/traffic_light.d \
./Core/Src/uart.d \
./Core/Src/usart.d \
./Core/Src/utils.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/%.o: ../Core/Src/%.c Core/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

