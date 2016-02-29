################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../colas/Cola.cpp \
../colas/main.cpp 

OBJS += \
./colas/Cola.o \
./colas/main.o 

CPP_DEPS += \
./colas/Cola.d \
./colas/main.d 


# Each subdirectory must supply rules for building sources it contributes
colas/%.o: ../colas/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


