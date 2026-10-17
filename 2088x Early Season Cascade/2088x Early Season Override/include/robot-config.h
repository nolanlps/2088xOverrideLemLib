
#include "lemlib/api.hpp" // IWYU pragma: keep
#include "main.h"

extern pros::Controller master;
extern lemlib::Chassis chassis;

extern pros::MotorGroup cascade_intake; // lift or intake, depending on how the pto is actuated n stuff(2 11s)
extern pros::MotorGroup two_bar; // two bar connected to our lift(2 5.5s)
extern pros::Rotation two_barRotation;
extern pros::Motor wrist; // rotates the claw at the end of the twobar(5.5)
extern pros::Rotation wristRotation;
extern pros::Motor claw; // its a claw(5.5)
extern pros::adi::Pneumatics clawPiston;
extern pros::adi::Pneumatics pullToggle;