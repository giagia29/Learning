%{
Name: Gia Dao
Class: ENGR 1250_003
Date: 4/3/2020

Problem Summary: Determine the distance can travel by the Microjoule
using the user-specified amount of ethanol.

Variables: 
x (amount of ethanol) [g]
SG (specific gravity of ethanol) = 0.789
d (distance can travel with provided amount of ethanol) [km]
P (performance of Microjoule) = 10,705 [mi/gal]
v (volume of ethanol) [m^3]
D density of ethanol
%}
clear
clc
close all
SG = 0.789;
P = 10705;
dwater = 1000;
m = input('Enter mass of ethanol [grams]: ');
m = m / 1000; % Conversion from g to kg
%Calculate density of the provided amount of ethanol
D = SG * dwater; %1000 kg/m^3 is the density of water.
V = m / D; % Calculate the volume in units of m^3
V = V * (10^3) * 0.264; %Conversion from m^3 to gal
%Calculate the distance
d = V * P; % The distance now is in units of mile
d = d / 0.621; % Conversion from miles to km
fprintf('The distance the Microjoule traveled is %0.0f kilometers.', d);

