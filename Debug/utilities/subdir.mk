################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../utilities/fsl_debug_console.c 

OBJS += \
./utilities/fsl_debug_console.o 

C_DEPS += \
./utilities/fsl_debug_console.d 


# Each subdirectory must supply rules for building sources it contributes
utilities/%.o: ../utilities/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -D__NEWLIB__ -DCPU_LPC802M001JDH20 -DCPU_LPC802M001JDH20_cm0plus -DFSL_RTOS_BM -DSDK_OS_BAREMETAL -DSDK_DEBUGCONSOLE=0 -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -I"/Users/luke/Documents/MCUXpresso Workspace/TunerAPI/board" -I"/Users/luke/Documents/MCUXpresso Workspace/TunerAPI/source" -I"/Users/luke/Documents/MCUXpresso Workspace/TunerAPI" -I"/Users/luke/Documents/MCUXpresso Workspace/TunerAPI/drivers" -I"/Users/luke/Documents/MCUXpresso Workspace/TunerAPI/device" -I"/Users/luke/Documents/MCUXpresso Workspace/TunerAPI/CMSIS" -I"/Users/luke/Documents/MCUXpresso Workspace/TunerAPI/component/uart" -I"/Users/luke/Documents/MCUXpresso Workspace/TunerAPI/utilities" -O0 -fno-common -g3 -Wall -c -ffunction-sections -fdata-sections -ffreestanding -fno-builtin -fmerge-constants -fmacro-prefix-map="../$(@D)/"=. -mcpu=cortex-m0plus -mthumb -D__NEWLIB__ -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


