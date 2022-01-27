#pragma once

double acclY();
double velY(double init_velocityY, double time);
double posX(double init_position, double init_velocity, double time);
double posY(double init_position, double init_velocity, double time);

void print_time(double time);
double flight_time(double init_velocityY);