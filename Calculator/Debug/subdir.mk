################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Calc.c \
../DIO_Prog.c \
../KEY_PAD_prog.c \
../LCD_prog.c \
../Stack.c \
../main.c 

OBJS += \
./Calc.o \
./DIO_Prog.o \
./KEY_PAD_prog.o \
./LCD_prog.o \
./Stack.o \
./main.o 

C_DEPS += \
./Calc.d \
./DIO_Prog.d \
./KEY_PAD_prog.d \
./LCD_prog.d \
./Stack.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


