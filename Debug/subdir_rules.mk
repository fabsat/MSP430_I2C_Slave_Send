################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
TI_USCI_I2C_slave.obj: ../TI_USCI_I2C_slave.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: MSP430 Compiler'
	"D:/Programs/ti/ccsv6/tools/compiler/ti-cgt-msp430_4.4.4/bin/cl430" -vmsp --abi=eabi --use_hw_mpy=none --include_path="D:/Programs/ti/ccsv6/ccs_base/msp430/include" --include_path="D:/Programs/ti/ccsv6/tools/compiler/ti-cgt-msp430_4.4.4/include" --advice:power=all -g --define=__MSP430G2553__ --diag_warning=225 --display_error_number --diag_wrap=off --printf_support=minimal --preproc_with_compile --preproc_dependency="TI_USCI_I2C_slave.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

main.obj: ../main.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: MSP430 Compiler'
	"D:/Programs/ti/ccsv6/tools/compiler/ti-cgt-msp430_4.4.4/bin/cl430" -vmsp --abi=eabi --use_hw_mpy=none --include_path="D:/Programs/ti/ccsv6/ccs_base/msp430/include" --include_path="D:/Programs/ti/ccsv6/tools/compiler/ti-cgt-msp430_4.4.4/include" --advice:power=all -g --define=__MSP430G2553__ --diag_warning=225 --display_error_number --diag_wrap=off --printf_support=minimal --preproc_with_compile --preproc_dependency="main.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '


