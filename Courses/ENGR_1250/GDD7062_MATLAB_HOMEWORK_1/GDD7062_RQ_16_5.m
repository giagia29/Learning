%{
Name: Gia Dao ENGR 1250-003 Date: 03/26/2020

Problem summary: Determine the length of one side of a 
0.4 kilogram cube of solid gold, in unit of inches, knowing its 
specific gravity is 19.3.

Variables:
m: mass of the cube [kg]
SG: specific gravity 
l: length of the cube [in]
d: density of the cube [kg/m^3]
V: volume of the cube [m^3]

Equation: l = nthroot(V,3)
%}
clear
clc 
close all
%Input variables
m = 0.4;
SG = 19.3;
d = SG * 1000;
%1000 [kg/m^3] is the density of water
V = m / d;
%Calculate the length of the cube
l = nthroot(V,3);
%Conversion from m to in
l = (l * 100) / 2.54;

