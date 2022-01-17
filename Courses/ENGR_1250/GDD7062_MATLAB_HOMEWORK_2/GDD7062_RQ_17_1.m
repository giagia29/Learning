%{
Name: Gia Dao C
Class: ENGR 1250_003
Date: 4/3/2020

Problem Summary: Write a MATLAB program that will ask user to
input the mass of a cube of solid gold in units of kilograms and
display the length of a single side of the cube in units of inches
Knowing that the specific gravity of gold is 19.3

Variables:

SG (specific gravity) = 19.3
m (mass) [kg]
l (length) [in]
v (volume) [m^3]
d (density of the cube)

%}
clear
clc
close all
m = input('Enter the mass of the cube [kilograms]: ');
dwater = 1000;
SG = 19.3;
d = SG * dwater; %1000 kg/m^3 is the density of water.
%volume equals to mass divided by density.
v = m / d;
l = nthroot(v,3); %length is now having unit of meter.
%Conversion of length from meters to inches.
l = (l * 100) / 2.54;
fprintf('The length of a one side of the cube is %0.2f inches.',l);



