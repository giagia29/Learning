%{
Name: Gia Dao ENGR_1250_003 Date: 05/01/2020

Problem Statement: Create a program to determine whether a user-specified
altitude [meters] is in the troposphere, lower stratosphere, or upper
stratosphere.

If the altitude's value that user entered is a nonpositive value or a value of 50,000 or greater, the program
will inform the user of the error
If the altitude's value that user entered is a positive value less than 50,000, the program will calculate the
temperature and pressure.

Variables:
H: Altitude in units of meters [m]
T: Temperature in units of degree Celcius [C]
P: Pressure in units of kilopascals [kPa]

%}
clear
clc
close all
T = 0;
P = 0;
H = input('Please enter a positive value less than 50000 for altitude in meters: ');
if (H < 0 || H >= 50000)
    fprintf("The value you entered is not valid.\n");
elseif(0 < H && H < 11000) 
    T = 15.04 - 0.00649 * H;
    P = 101.29 * ((T + 273.1) / 288.08)^(5.256);
    fprintf('An altitude of %0.0f is in the troposhere with a temperature of %0.0f and pressure of %0.0f kPa.\n',H,T,P);
elseif(11000 <= H && H < 25000)
    T = -56.46;
    P = 22.65 * exp(1.73 - 0.000157 * H);
    fprintf('An altitude of %0.0f is in the lower stratosphere with a temperature of %0.0f and pressure of %0.0f kPa.\n',H,T,P);
elseif(25000 <= H && H < 50000)
    T = -131.21 + 0.00299 * H;
    P = 2.488 * ((T + 273.1) / 216.6)^(-11.388);
    fprintf('An altitude of %0.0f is in the upper stratosphere with a temperature of %0.0f and pressure of %0.0f kPa.\n',H,T,P);
end
    
    
