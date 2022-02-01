#define _USE_MATH_DEFINES

#include <canonball.h>
#include <iostream>
#include <cmath>
#include <stdlib.h>
// #include <vector>

using namespace std;

double acclY() {
    return -9.81;
}

double velY(double init_velocityY, double time) {
    return (init_velocityY + acclY() * time);
}

double posX(double init_position, double init_velocity, double time) {
    return (init_position + (init_velocity * time) + (pow(time, 2)) / 2);
}

double posY(double init_position, double init_velocity, double time) {
    return (init_position + (init_velocity * time) + (acclY() * pow(time, 2)) / 2);
}

void print_time(double time) {
    int hours{time / 3600};
    time = int(time) % (hours * 60);
    /*
        Redo this
    */

    int hours{8};
}

double flight_time(double init_velocityY) {
    return (-2 * init_velocityY / acclY());
}

double get_user_input_theta() {
    cout << "Oppgi vinkel: ";
    double angle_input;
    cin >> angle_input;
    
    return angle_input;
}

double get_user_input_abs_velocity() {
    cout << "Oppgi avsoluttfart: ";
    double abs_vel;
    cin >> abs_vel;

    return abs_vel;
}

double deg_to_rad(double deg) {
    return (deg * M_PI / 180);
}

double get_velX(double theta, double abs_velocity) {
    return (abs_velocity * cos(theta));
}

double get_velY(double theta, double abs_velocity) {
    return (abs_velocity * sin(theta));
}

std::vector<double> get_velocity_vector(double theta, double abs_velocity) {
    vector<double> vec{get_velX(theta, abs_velocity), get_velY(theta, abs_velocity)};
}

double get_distance_traveled(double velX, double velY) {
    double time_in_air{flight_time(velY)};
    return (time_in_air * velX);
}

double target_practice(double distance_to_target, double velX, double velY) {
    return (abs(distance_to_target - get_distance_traveled(velX, velY)));
}
