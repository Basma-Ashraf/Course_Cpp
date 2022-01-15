################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../BMI_calculate.cpp \
../BMI_main.cpp \
../BMI_record.cpp 

OBJS += \
./BMI_calculate.o \
./BMI_main.o \
./BMI_record.o 

CPP_DEPS += \
./BMI_calculate.d \
./BMI_main.d \
./BMI_record.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -std=c++11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


