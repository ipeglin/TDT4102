#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
#include <stdlib.h>

#include "canonball.h"
#include "utilities.h"

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
    int temp{int(time)};
    temp = temp % 3600;
    int minutes{temp / 60};
    int seconds{temp % 60};

    cout << minutes << " " << (minutes == 1 ? "minutt" : "minutter") << " ";
    cout << seconds << " " << (seconds == 1 ? "sekund" : "sekunder") << endl;
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

vector<double> get_velocity_vector(double theta, double abs_velocity) {
    vector<double> vec{get_velX(theta, abs_velocity), get_velY(theta, abs_velocity)};
    return vec;
}

double get_distance_traveled(double velX, double velY) {
    double time_in_air{flight_time(velY)};
    return (time_in_air * velX);
}

double target_practice(double distance_to_target, double velX, double velY) {
    return (distance_to_target - get_distance_traveled(velX, velY));
}

bool is_correct_distance_to_target(double distance_to_target, double velX, double velY) {
    double error = target_practice(distance_to_target,velX,velY);
    return (error == 0) ?  true : false;
}

void play_target_practice() {
    int target_position{random_with_limits(100, 1000)};
    int failed_attempts{0};
    double angle_input, velocity_input;

    while (failed_attempts < 10) {
        cout << "\n\nVinkel for skuddet (grader): ";
        cin >> angle_input;

        cout << "Startfart for skuddet (m/s): ";
        cin >> velocity_input;

        vector<double> velocity_vec{get_velocity_vector(deg_to_rad(angle_input), velocity_input)};
        double hit_difference{target_practice(target_position, velocity_vec[0], velocity_vec[1])};
        double flight_duration{flight_time(velocity_vec[1])};

        cout << "Elements in velocity array:" << endl;
        for (int i = 0; i < velocity_vec.size(); i++) {
            cout << velocity_vec[i] << ", ";
        }

            cout << "----------------------------" << endl
                 << "  Distance to target: " << target_position << "m" << endl
                 << "  The shot was " << abs(hit_difference) << "m too " << ((hit_difference > 0) ? "short" : "far") << endl
                 << "  The canonball took " << flight_duration << "s to hit." << endl
                 << "-------------------------" << endl;

        if (abs(hit_difference) < 5) {
            cout << "HIT!!!" << endl;
            break;
        } else {
            cout << "MISS..." << endl;
            failed_attempts++;
        }
    }

    cout << "WOW! Dette var du ikke god på. Værre treffsikkerhet har jeg aldri sett. Absolutt håpløs." << endl;
}