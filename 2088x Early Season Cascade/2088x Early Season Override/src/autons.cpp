#include "main.h"
#include "lemlib/api.hpp" // IWYU pragma: keep

//imagine working auto code
void sawp() {


    chassis.setPose(2,2,-55);
    pullToggle.extend();

    pros::delay(300);
    chassis.swingToHeading(0, DriveSide::LEFT, 1000, {.maxSpeed = 110, .minSpeed = 100});
    pros::delay(500);
    chassis.setPose(0, 0, 0);
    pullToggle.retract();
    // chassis.swingToHeading(-65, DriveSide::LEFT, 1500, {.maxSpeed = 110, .minSpeed = 100});
    cascadelift(12000, 200);
    chassis.moveToPoint(-7, 10, 3000, {.maxSpeed = 110, .minSpeed = 80});
    pros::delay(700);
    claw.move_velocity(-12000);

    cascadelift(-12000, 300);
    pros::delay(1000);
claw.move_velocity(0);

    // clawPiston.extend();
    // chassis.swingToHeading(-0, DriveSide::RIGHT, 8000, {.maxSpeed = 110, .minSpeed = 100});
twoBarSet(180);
wristRotation.set_position(90);
chassis.turnToHeading(0, 1000);
chassis.moveToPoint(-16, 11,  1000, {.maxSpeed = 100, .minSpeed = 30});
chassis.turnToHeading(0, 1000);
cascadelift(-12000, 200);
// chassis.setPose(0, 0, 0);
twoBarSet(280);
wristRotation.set_position(90);
// twoBarSet(280);
}

void threePin() {
wristAutoControl = !wristAutoControl;
    chassis.setPose(2,2,-55);
    pullToggle.extend();
    pros::delay(200);

    chassis.swingToHeading(0, DriveSide::LEFT, 2000, {.maxSpeed = 110, .minSpeed = 100});
    pros::delay(400);
    chassis.setPose(0, 0, 0);
    pros::delay(200);
    pullToggle.retract();
    // chassis.swingToHeading(-65, DriveSide::LEFT, 1500, {.maxSpeed = 110, .minSpeed = 100});
    cascadelift(12000, 500);
    chassis.moveToPose(-14.75, 14, -110, 3500, {.maxSpeed = 80, .minSpeed = 80});
    pros::delay(800);
    cascadelift(-10000, 800);
    claw.move_velocity(-12000);
    pros::delay(500);

    // chassis.moveToPoint(-14.5, 14, 2000, {.maxSpeed = 95, .minSpeed = 30});
    chassis.turnToHeading(-90, 500);
    

    //     claw.move_velocity(2000);
    // clawPiston.extend();
    // cascadelift(-12000, 200);



    chassis.moveToPoint(8, 12, 1000, {.forwards = false, .maxSpeed = 100, .minSpeed = 30});
wristSet(9000);
pros::delay(500);
wristRotation.set_position(0);
wristAutoControl = !wristAutoControl;
cascadelift(-12000, 600);
claw.move_velocity(12000);
clawPiston.extend();
    chassis.turnToHeading(-30, 1000);
    chassis.moveToPoint(-14, 39.5, 1000, {.maxSpeed = 60, .minSpeed = 30});
    pros::delay(1750);
clawPiston.retract();
pros::delay(750);
    cascadelift(12000, 600);
    chassis.turnToHeading(180, 1000);
    chassis.moveToPoint(-8, 15, 1000, {.maxSpeed = 60, .minSpeed = 30});
    pros::delay(600);
    cascadelift(-10000, 500);
    clawPiston.extend();
    chassis.moveToPoint(-12, 27, 1000, {.forwards = false, .maxSpeed = 90, .minSpeed = 30});
    chassis.turnToHeading(-135, 500);
} 