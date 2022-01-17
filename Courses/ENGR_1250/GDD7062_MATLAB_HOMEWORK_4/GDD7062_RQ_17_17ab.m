%{
Name: Gia Dao
ENGR 1250_003
Date: 4/18/2020

Problem Statement: Create a proper plot of the power P 
of a turbine versus the diameter D of the impeller
using the following data.

Variables: 
d: diameter of the impeller [ft]
P: Power of the turbine [hp]
m: variable d raises to the power of m (power equation)
b: constant coefficient
%}
clear
clc
close all

%plot the data
figure('color','w');
d = [0.5 0.75 1 1.5 2 2.25 2.5 2.75];
P = [0.004 0.04 0.13 0.65 3 8 18 22];
plot(d,P,'o k');
grid on
xlabel('Diameter (D) [ft]');
ylabel('Power (P) [hp]');
title('Power P [hp] vs Diameter D [ft]');
set(gca,'Xtick',0.25:0.25:3);
axis([0 3 0 23]);
%generate the trendline for data
c = polyfit(log10(d),log10(P),1);
m = c(1);
b = 10^(c(2));
%values of x_pd are equivalent to d (set on x-axis)
x_pd = [0 : 0.25 : 3];
%calculate the power using power equation
y_pd = b * (x_pd.^m);
hold on
plot(x_pd,y_pd,'-r','LineWidth',2);
%print out the equation for graph
TE = sprintf('P = %.2fD^{%0.0f}',b,m);
text(2.42,7,TE,'EdgeColor','k');


