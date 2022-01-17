%{
Name: Gia Dao
ENGR 1250-003
Date: 03/26/2020

Problem: How far the Microjoule will travel in kilometers
given a user-specified amount of ethanol, provided in units of grams

Variables:
m: mass of ethanol given by the user [g]
SG: specific gravity of ethanol
V: volume of ethanol [m^3]
d: density of ethanol [kg/m^3]
D: distance can travel using the provided ethanol
P: Performance of the team (provided)
%}
clear
clc
close all
P = 10705;
m = 100;
%Conversion from g to kg
m = m / 1000;
SG = 0.789;
%1000 is the density of water
d = SG * 1000;
%Calculate the volume of ethanol
V = m / d;
%Conversion from m^3 to gal
V = V * (10^3) * 0.264;
%Calculate distance travel
D = P * V / 0.621;

