%{
Name: Gia Dao
ENGR 1250-003
Date: 03/26/2020

Problem: Determine the mass of oxygen gas in units of grams
in a container, knowing the volume of container, the temperature in the
container and pressure in the container.

Variables:
m = mass of oxygen [g]
n = Amount of oxygen [mole]
V = volume of the container [gal]
T = temperature in the container [degrees Celcius]
P = pressure in the container [atm]
R = constant value = 0.08206 [(atm L)/(mol K)]

Equation: PV=nRT
m = M*n; (M = molecular weight of oxygen = 64 as there
are 2 molecules of oxygen)
%}
clear
clc
close all
V = 1.25;
%Conversion from gal to L
V = V / 0.264;
T = 125;
%Conversion from Celcius to Kelvin
T = T + 273;
P = 2.5;
%Calculate the amount of oxygen in the container
n = (P * V)/(0.08206 * T);
%Calculate the mass
m = 64 * n;
