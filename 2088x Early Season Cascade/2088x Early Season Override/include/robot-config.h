
#include "lemlib/api.hpp" // IWYU pragma: keep
#include "main.h"

extern pros::Controller master;
extern pros::MotorGroup left_mg;    // Creates a motor group with forwards ports 1 & 3 and reversed port 2
extern pros::MotorGroup right_mg;  // Creates a motor group with forwards port 5 and reversed ports 4 & 6

extern pros::MotorGroup lift_intake; // lift or intake, depending on how the pto is actuated n stuff(2 11s)
extern pros::MotorGroup two_bar; // two bar connected to our lift(2 5.5s)
extern pros::Motor wrist; // rotates the claw at the end of the twobar(5.5)
extern pros::Motor claw; // its a claw(5.5)