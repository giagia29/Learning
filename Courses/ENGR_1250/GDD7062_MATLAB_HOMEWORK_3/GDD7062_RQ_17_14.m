%{
ENGR1250
Name: Gia Dao
Date: 4/10/2020
Problem Statement: Create a proper plot following the data
consider the vehicle speed versus reaction distance and 
braking distance

Variables:
db = braking distance [m]
dr = reaction distance [m]
v = vehicle speed [mph]
%}
%data points
v = [20,30,40,50,60,70];
dr = [6,9,12,15,18,21];
db = [6,14,24,38,55,75];
figure('color','w');
plot(v,dr,'sb',v,db,'sr');
axis([0 100 0 100]);
grid on;
%set y-axis to count by 10's
set(gca,'Ytick',0:10:100);
%set the name for x-axis of the graph
xlabel('Vehicle Speed(v) [mph]');
%set the name for y-axis of the graph
ylabel('Distance(d) [m]');
%set the title for the graph
title('Reaction Time vs Braking Time','FontWeight','bold','FontSize',16);
legend('Reaction Time','Braking Time');