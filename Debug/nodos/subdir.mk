################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../nodos/Node.cpp 

OBJS += \
./nodos/Node.o 

CPP_DEPS += \
./nodos/Node.d 


# Each subdirectory must supply rules for building sources it contributes
nodos/%.o: ../nodos/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


