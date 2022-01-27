#include <canonball.h>
#include <iostream>

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