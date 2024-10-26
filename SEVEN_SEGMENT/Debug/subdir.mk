################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../SEVEN_SEGMENT_config.c \
../SEVEN_SEGMENT_prog.c \
../main.c \
../prog.c 

OBJS += \
./SEVEN_SEGMENT_config.o \
./SEVEN_SEGMENT_prog.o \
./main.o \
./prog.o 

C_DEPS += \
./SEVEN_SEGMENT_config.d \
./SEVEN_SEGMENT_prog.d \
./main.d \
./prog.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega16 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


