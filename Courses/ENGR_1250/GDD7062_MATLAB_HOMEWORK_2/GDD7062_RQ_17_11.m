%{
Name: Gia Dao
Class: ENGR 1250_003
Date: 4/4/2020

Problem Summary: Write a program to measure the efficiency of 
stove-top burners.

Variables:
v (volume of water) [gal]
m (mass of water) (g)
C (specific heat of water) = 4.186 J / (g * degree Celcius)
T1 (initial room temperature) [F]
t (time required to boil the water) [min]
E (energy required) [J]
Pin (Power of the stove) [W]
Pout(Power used by burner) [W]
n (efficiency of the stove) 
Name (the brand name and model of stove)
%}
clear
clc
close all
fprintf('Household Appliance Efficiency Calculator: Stove\n\n');
T1 = input('Type the initial room temperature of the water [deg F]: ');
t = input('Type the time it takes the water to boil [min]: ');
Name = input('Type the brand name and model of your stove: ','s');
Pin = input('Type the power of the stove-top burner [W]: ');
fprintf('\n');
%Provided 1 gallon of water
v = 1;
dwater = 1000;
%Conversion from [gal] to [m^3]
v = (v / 0.264) / (10^3);
% Calculate the mass of water on the stove
m = v * dwater; % [kg]
% Conversion from kg to g
m = m * 1000;
% Conversion from degree Fahrenheit to degree Celcius
T1 = 100 * (T1-32) / 180;
C = 4.186; %specific heat of water;
%Calculate thermal energy needed
E = m * C * (100 - T1); %100 is the boiling temperature of water
%Conversion of time from minutes to seconds
t = t * 60;
Pout = E / t;
fprintf('Energy required: %0.0f J\n',E);
fprintf('Power used by burner: %0.0f W\n\n',Pout);
n = (Pout / Pin) * 100;
fprintf('Burner efficiency for a Krispy 32-z stove: %0.1f%% ',n);





