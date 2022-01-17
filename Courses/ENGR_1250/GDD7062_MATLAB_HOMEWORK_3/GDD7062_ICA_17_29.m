%{
ENGR1250
Name: Gia Dao
Date: 4/10/2020
Problem Statement: Graph the power (P,ordinate) versus the diameter
(D,abscissa) assuming the data are experimental.

Variables:
P (power) in unit of horsepower [hp]
D (diameter) in unint of feet [ft]
%}
%Set vectors for diameter and power
%data points
D = [0.5,0.75,1,1.5,2,2.25,2.5,2.75]; %D diameter [ft]
P = [0.004,0.04,0.13,0.65,3,8,18,22]; %P power [hp]
figure('color','w');
plot(D,P,'sb','MarkerFaceColor','b','MarkerSize',8);
grid on;
axis([0 3 0 23]);
set(gca,'Xtick',0:0.25:3);
%Set the name for x-axis of the graph
xlabel('Diameter D [ft]');
%Set the name for y-axis of the graph
ylabel('Power P [hp]');
%Set the title of the graph
title('Turbine Power','FontWeight','bold','FontSize',16);
