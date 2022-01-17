%{
Name: Gia Dao ENGR_1250_003 Date: 05/01/2020

Problem Statement: Determine the state of users' Apple TV by allowing them
to provide the power currently being used by their devices in units of
watts.

Variable
PC: Power Consumption in units of Watts [W]

%}
clear
clc
close all
PC = input('Enter the power currently being used by Apple TV in units of watts: ');
if (PC < 0.5)
    fprintf('Off/Standby\n');
elseif(0.5 <= PC && PC <= 1.5)
    fprintf('Idle\n');
elseif(1.5 <= PC && PC <= 1.6)
    fprintf('Streaming via Ethernet\n');
elseif(1.6 <= PC && PC <= 2)
    fprintf('Streaming via Wifi\n');
else
    fprintf('State of device is unknown\n');
end