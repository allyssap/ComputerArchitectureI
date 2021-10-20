################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/COMP2650_Lab04_poulina.cpp \
../src/complement.cpp \
../src/conversion.cpp \
../src/logic.cpp 

OBJS += \
./src/COMP2650_Lab04_poulina.o \
./src/complement.o \
./src/conversion.o \
./src/logic.o 

CPP_DEPS += \
./src/COMP2650_Lab04_poulina.d \
./src/complement.d \
./src/conversion.d \
./src/logic.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cygwin C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


