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
    cascadelift(12000, 1000);
    chassis.moveToPose(-15.4, 13, -110, 1800, {.maxSpeed = 127, .minSpeed = 80});
        pros::delay(550);
    cascadelift(-10000, 750);
    claw.move_velocity(-12000);
pros::delay(300);
    // pros::delay(500);
    clawPiston.extend();

    chassis.turnToHeading(-90, 200);



    chassis.moveToPoint(5, 12, 1000, {.forwards = false, .maxSpeed = 120, .minSpeed = 40});
wristSet(9500);
pros::delay(700);
wristRotation.set_position(0);
wristAutoControl = !wristAutoControl;
cascadelift(-12000, 600);
claw.move_velocity(12000);

//     chassis.turnToHeading(-33, 1000);
//     chassis.moveToPoint(-20, 47.5, 1000, {.maxSpeed = 65, .minSpeed = 30});
//     pros::delay(1050);
// clawPiston.retract();
// pros::delay(750);
//     cascadelift(12000, 600);
//     chassis.turnToHeading(180, 1000);
//     chassis.moveToPoint(-8, 15, 1000, {.maxSpeed = 80, .minSpeed = 30});
//     pros::delay(600);
//     cascadelift(-10000, 600);
//     clawPiston.extend();
//     pros::delay(200);
//     chassis.moveToPoint(-12, 27, 1000, {.forwards = false, .maxSpeed = 90, .minSpeed = 30});
//     chassis.turnToHeading(-127, 500);
// cascadelift(-12000, 600);
//     chassis.moveToPoint(-29.25, 11, 1000, {.maxSpeed = 65, .minSpeed = 30});
//     pros::delay(650);
//         clawPiston.retract();
//         pros::delay(500);
//         chassis.turnToHeading(90, 500, {.maxSpeed = 90});
//         cascadelift(12000, 1000);
//         pros::delay(200);
//         chassis.moveToPoint(-10, 12, 1000, {.maxSpeed = 127, .minSpeed = 50});
//         pros::delay(700);
//         cascadelift(-10000, 400);
//         clawPiston.extend();

} 

void wallPins() {
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
    cascadelift(12000, 300);
    chassis.moveToPoint(-12, 11, 1800, {.maxSpeed = 127, .minSpeed = 80});
        pros::delay(550);
    cascadelift(-10000, 800);
    claw.move_velocity(-12000);
pros::delay(300);
    // pros::delay(500);
    clawPiston.extend();
    // chassis.moveToPoint(-14.5, 14, 2000, {.maxSpeed = 95, .minSpeed = 30});
    chassis.turnToHeading(0, 500);
            wristSet(90000);
            pros::delay(500);



        wristRotation.set_position(0);
wristAutoControl = !wristAutoControl;
clawPiston.retract();
twoBarSet(286);
claw.move_velocity(12000);
chassis.moveToPoint(-18, 0, 500, {.forwards = false});
twoBarSet(60);
wristAutoControl = !wristAutoControl;
wristSet(180);
cascadelift(12000, 300);
chassis.moveToPoint(-18, 5, 500);
cascadelift(-10000, 400);
clawPiston.extend();




}