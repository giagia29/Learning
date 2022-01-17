%{
Name: Gia Dao
ENGR 1250_003
Date: 4/17/2020

Problem Statement: Create a proper plot of the data
to show the comparison of the resistance among three
different CdS photoresistors when they were placed at various
distances from the light source.

d: distance from the light source [m]
RA: resistance of A photoresistor [Ohm]
RB: resistance of B photoresistor [Ohm]
RC: resistance of C photoresistor [Ohm]
m,n,p: constant power for each photoresistor, from A to C, consecutively

%}
clear
clc
close all
%plot the data
figure('color','w');
d = [1 3 6 10]; %various distance values
RA = [79 400 1100 2500];
RB = [150 840 2500 4900];
RC = [460 2500 6900 15000];
%values for resistance R from A to C depends on d
plot(d,RA,'s r',d,RB,'o b',d,RC,'d k');
grid on
xlabel('Distance from Light (d) [m]');
ylabel('Resistance R [Ohm]');
title('Resistance R vs Distance from Light d');
set(gca,'Ytick',400:2500:16000);
set(gca,'Xtick',0:1:10);
axis([0 10 0 16000]);
%generate trendline for Resistance A
a = polyfit(log10(d),log10(RA),1);
m = a(1);
a1 = 10^(a(2));
%a1 is the constant coefficent of A power equation.
x_a = [0 : 1 : 10];
y_a = a1 * (x_a.^m);
hold on
plot(x_a,y_a,'-r','LineWidth',2);

%generate trendline for Resistance B
b = polyfit(log10(d),log10(RB),1);
n = b(1);
b1 = 10^(b(2));
%b1 is the constant coefficent of B power equation
x_b = [0 : 1 : 10];
y_b = b1 * (x_b.^n);
hold on
plot(x_b,y_b,'-.b','LineWidth',2);

%generate trendline for Resistance C
c = polyfit(log10(d),log10(RC),1);
p = c(1);
c1 = 10^(c(2));
%c1 is the constant coefficient of C power equation
x_c = [0 : 1 : 10];
y_c = c1 * (x_c.^p);
hold on
plot(x_c,y_c,'--k','LineWidth',1);
%set up equations for each Cds photoresistors
TA = sprintf('RA = %0.2fd^{%0.2f}',a1,m);
TB = sprintf('RB = %0.2fd^{%0.2f}',b1,n);
TC = sprintf('RC = %0.2fd^{%0.2f}',c1,p);
text(7.25,1000,TA);
text(7.25,5200,TB);
text(3.5,7200,TC);
legend('Resistor A','Resistor B','Resistor C');







