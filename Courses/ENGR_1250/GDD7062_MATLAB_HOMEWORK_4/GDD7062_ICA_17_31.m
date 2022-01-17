%{
Name: Gia Dao
ENGR 1250_003
Date: 4/17/2020

Problem statement: Create a plot to compare a carbon film resistor
with a resistor fabricated from specially doped silicon

CF: Resistance R of Carbon Film [Ohm]
DP: Resistance R of Doped Silicon [Ohm]
T: Temperature T in degree Celcius 
m: The slope of CF and T 
b: The y-intercept of line CF vs T
n: The slope of DP and T
a: The y-intercept of line DP vs T
%}
clear
clc 
close all

%plotting the points
figure('color','w');
T = [15 20 25];
CF = [10.05 10.048 10.045];
DP = [10.15 9.85 9.48];
plot(T,CF,'s r', T,DP,'d b');
grid on 
xlabel('Temperature (T) [degree Celcius]');
ylabel('Resistance (R) [Ohm]');
title('Carbon Film Resistor vs Doped Silicon Resistor');

%generate trendline for Resistance R in CF vs Temperature T
c = polyfit(T,CF,1);
m = c(1);
b = c(2);
%values of x_cf represent Temperature T used for Carbon Film
x_cf = [15 : 1 : 25];
y_cf = m * x_cf + b; 
hold on
plot(x_cf,y_cf,'--r','LineWidth',1);


%generate trendline for Resistance R in DP vs Temperature T
d = polyfit(T,DP,1);
n = d(1);
a = d(2);
%values of x_dp represent Temperature T used for Doped Silicon
x_dp = [15 : 1: 25];
y_dp = n*x_dp + a;
hold on
plot(x_dp,y_dp,'-. b','LineWidth',2);

%set up equations for both trendlines
TC = sprintf('RCF = %.4fT + %.4f',m,b);
text(20,10,TC,'EdgeColor','k');
TD = sprintf('RDP = %.4fT + %.4f',n,a);
text(17,9.7,TD,'EdgeColor','k');
legend('Carbon Film','Doped Silicon');






