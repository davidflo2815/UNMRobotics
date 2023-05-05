clear all
clear clc
clear variables


% -------------O-------O-X
%     Arm 1    | Arm 2 | Main mass

% Stuff you get from your SRD
alpha = 000;
m = 000;
v = 000;

% Stuff you estimate / assume for arm 1
arm1w = 000;
arm1l = 000;
arm1m = 000;

% Stuff you estimate / assume for arm 2
arm2w = 000;
arm2l = 000;
arm2m = 000;

% Intermediate calculations
I1 = ((arm1l * arm1w^3 / 12) + (arm1l / 2)^2) * arm1m;
I2 = ((arm2l * arm2w^3 / 12) + (arm2l / 2)^2) * arm2m;
Im = (arm1l + arm2l)^2 * m;

Itotal = Im + (I2 + arm2m * (arm2l / 2 + arm1l)^2) + I1;

tau = alpha * Itotal;
omega = v / (arm1l + amr2l);

% Final values
torque = tau;
RPM = omega;



M1 = m1



F_Weight = 10;
conv_factor = 0.453592;
Inc_to_Meter = 0.0254;

D4 = [12,13,14,15,16,17,18]*Inc_to_Meter;
A3 = [12,13,14,15,16,17,18]*Inc_to_Meter;
P1_angle = linspace(0,90,90);
A_Horizontal = zeros(90,7);
D_Total = zeros(90,7);
Torque = zeros(90,7);




for theta = 1:90
    for xx = 1:7
        A_Horizontal(theta,xx)= A3(xx)*sin(P1_angle(theta)*(pi/180));
        D_Total(theta,xx) = A_Horizontal(theta,xx) + D4(xx);
        Torque(theta,xx) = D_Total(theta,xx)*(F_Weight*conv_factor);
    end
end

theta = 1:90;
xx = 1:7;

[X, Y] = meshgrid (theta, xx);
contour(X, Y, transpose(Torque), 'ShowText', 'on', 'fill', 'on');

% [r, thetas] = meshgrid (0:90:90,0:1*pi/180:(2*pi));
% x=r.*cos (thetas);
% y=r.*sin(thetas);
% h = polar(x,y) ;
% hold on;
% contourf (x,y,transpose(Torque));
% camroll(90)
% colorbar
% axis image
% grid on
% % print()
