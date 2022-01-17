%{
ENGR1250
Name: Gia Dao
Date: 4/10/2020

Problem statement: Create a plot of the decay of a radioactive
isotope A with the following equation
C = Co*(e)^(-t/k)

Variables:
Co is the initial amount of the element at time zero. [Co = 10g]
k is the decay rate of the isotope [k = 1.48 hours]
t (time) vary on the abscissa from 0 to 5 hours
%}
clear 
clc
close all
%Initialize the value of Co
Co = 10;
%Declare constant rate of decay
k = 1.48;
t = [0:0.5:5];
%Set the equation of decaying process
C = Co * exp(-t/k);
figure('color','w');
plot(t,C,'sr','MarkerFaceColor','r','MarkerSize',8);
grid on;
axis([0 5 0 10]);
set(gca,'Xtick',0:0.5:5);
%Set the name for x-axis on the graph
xlabel('Time t in hours [h]');
%Set the name for y-axis on the graph
ylabel('Amount of element A in grams [g]');
%Set the title
title('The decay of a radioactive isotope','FontWeight','bold','FontSize',16);
legend('Amount of element A');

