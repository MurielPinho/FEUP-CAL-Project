################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Camiao.cpp \
../src/Empresa.cpp \
../src/Local.cpp \
../src/Produto.cpp \
../src/main.cpp 

OBJS += \
./src/Camiao.o \
./src/Empresa.o \
./src/Local.o \
./src/Produto.o \
./src/main.o 

CPP_DEPS += \
./src/Camiao.d \
./src/Empresa.d \
./src/Local.d \
./src/Produto.d \
./src/main.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


