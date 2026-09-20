#include "lemlib/api.hpp" // IWYU pragma: keep
#include "pros/adi.hpp"

pros::Controller master(pros::E_CONTROLLER_MASTER);
pros::MotorGroup left_mg({-4, -2});    // Creates a motor group with forwards ports 1 & 3 and reversed port 2
pros::MotorGroup right_mg({17, 20});  // Creates a motor group with forwards port 5 and reversed ports 4 & 6

pros::MotorGroup cascade_intake({3, -11}); // lift or intake, depending on how the pto is actuated n stuff(2 11s)
pros::MotorGroup two_bar({-7, 8}); // two bar connected to our lift(2 5.5s)
pros::Rotation two_barRotation(15);
pros::Motor wrist(9); // rotates the claw at the end of the twobar(5.5)
pros::Motor claw(-10); // its a claw(5.5)
pros::adi::Pneumatics clawPiston('A', true);