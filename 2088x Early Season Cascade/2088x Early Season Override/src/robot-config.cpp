#include "lemlib/api.hpp" // IWYU pragma: keep
#include "pros/adi.hpp"

pros::Controller master(pros::E_CONTROLLER_MASTER);
pros::MotorGroup left_mg({-8, -12});    // Creates a motor group with forwards ports 1 & 3 and reversed port 2
pros::MotorGroup right_mg({3, 10});  // Creates a motor group with forwards port 5 and reversed ports 4 & 6

pros::MotorGroup cascade_intake({19, -11}); // lift or intake, depending on how the pto is actuated n stuff(2 11s)
pros::MotorGroup two_bar({13, -4}); // two bar connected to our lift(2 5.5s)
pros::Rotation two_barRotation(7);
pros::Motor wrist(20); // rotates the claw at the end of the twobar(5.5)
pros::Rotation wristRotation(-16);
pros::Motor claw(2); // its a claw(5.5)
pros::adi::Encoder encoder({17, 'B', 'C'}, true);
pros::adi::Pneumatics clawPiston({17, 'A'}, true); // starts retracted
