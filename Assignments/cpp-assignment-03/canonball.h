#pragma once
#include <vector>

double acclY();

double velY(double init_velocityY, double time);

double posX(double init_position, double init_velocity, double time);
double posY(double init_position, double init_velocity, double time);

void print_time(double time);
double flight_time(double init_velocityY);

double get_user_input_theta();
double get_user_input_abs_velocity();

double deg_to_rad(double deg);

double get_velX(double theta, double abs_velocity);
double get_velY(double theta, double abs_velcity);

double get_distance_traveled(double velX, double velY);

double target_practice(double distance_to_target, double velX, double velY);

std::vector<double> get_velocity_vector(double theta, double abs_velocity);