################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/GraphViewer-1.2/cpp/connection.cpp \
../src/GraphViewer-1.2/cpp/graphviewer.cpp 

OBJS += \
./src/GraphViewer-1.2/cpp/connection.o \
./src/GraphViewer-1.2/cpp/graphviewer.o 

CPP_DEPS += \
./src/GraphViewer-1.2/cpp/connection.d \
./src/GraphViewer-1.2/cpp/graphviewer.d 


# Each subdirectory must supply rules for building sources it contributes
src/GraphViewer-1.2/cpp/%.o: ../src/GraphViewer-1.2/cpp/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


