# Fan-Controller-Using-Atmega32
Build-Driver for Fan controlling using peripherals DIO, ADC and PWM.
Implement the following Fan Controller system with the specifications listed below:
1. The aim of this project is to design a temperature-controlled fan using ATmega32
microcontroller, in which the fan is automatically turned ON or OFF according to the
temperature. Use ATmega16 Microcontroller with frequency 1Mhz.
2. In this project, the LM35 temperature sensor will give continuous analog output
corresponding to the temperature sensed by it. This analog signal is given to the ADC,
which converts the analog values to digital values.
3. The digital output of the ADC is equivalent to sensed analog voltage.
4. In order to get the temperature from the sensed analog voltage, we need to perform some
calculations in the programming for the microcontroller.
5. Once the calculations are done by the microcontroller according to the logic, the
temperature is displayed on the LCD.
6. The microcontroller will continuously monitor the temperature and based on the
temperature value, the microcontroller will drive the fan like that:
    a. If the temperature is less than 30C turn off the fan.
    b. If the temperature is greater than or equal 30C turn on the fan with 25% of its
    maximum speed.
    c. If the temperature is greater than or equal 60C turn on the fan with 50% of its
    maximum speed.
    d. If the temperature is greater than or equal 90C turn on the fan with 75% of its
    maximum speed.e. If the temperature is greater than or equal 120C turn on the fan with 100% of its
    maximum speed.
7. The main principle of the circuit is to switch on/off the fan connected to DC motor based
on temperature value. The DC-Motor rotates in clock-wise direction or stopped based on
the fan state.
8. The LCD should display the temperature value and the fan state continuously.
9. Control the DC-Motor speed using PWM signal generated from Timer0.
