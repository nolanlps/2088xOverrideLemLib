#include "lemlib/api.hpp" // IWYU pragma: keep
#include "pros/adi.hpp"

pros::Controller master(pros::E_CONTROLLER_MASTER);
pros::MotorGroup left_mg({-15, -6});    // Creates a motor group with forwards ports 1 & 3 and reversed port 2
pros::MotorGroup right_mg({4, 5});  // Creates a motor group with forwards port 5 and reversed ports 4 & 6

pros::MotorGroup cascade_intake({14, -3}); // lift or intake, depending on how the pto is actuated n stuff(2 11s)
pros::MotorGroup two_bar({17, -16}); // two bar connected to our lift(2 5.5s)
pros::Rotation two_barRotation(18);
pros::Motor wrist(19); // rotates the claw at the end of the twobar(5.5)
pros::Rotation wristRotation(-12);
pros::Motor claw(-10); // its a claw(5.5)
pros::adi::Pneumatics clawPiston('A', true);