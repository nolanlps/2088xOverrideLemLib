#include "main.h"
#include "lemlib/api.hpp" // IWYU pragma: keep

//imagine working auto code
void sawp() {
    chassis.setPose(2,2,-55);
    pullToggle.extend();
    pros::delay(300);
    chassis.swingToHeading(0, DriveSide::LEFT, 1000, {.maxSpeed = 110, .minSpeed = 100});
    pros::delay(500);
    pullToggle.retract();
    chassis.swingToHeading(-65, DriveSide::LEFT, 1500, {.maxSpeed = 110, .minSpeed = 100});
    cascadelift(12000, 200);
    chassis.moveToPoint(-3.5, 4.4, 3000, {.maxSpeed = 110, .minSpeed = 80});
    pros::delay(300);
    claw.move_velocity(6000);
    cascadelift(-6000, 300);
    clawPiston.extend();
    chassis.swingToHeading(-0, DriveSide::RIGHT, 8000, {.maxSpeed = 110, .minSpeed = 100});
    chassis.moveToPoint(-10, 6, 1000);
}