#include "lemlib/api.hpp" // IWYU pragma: keep
#include "pros/adi.hpp"


//dt/sensor configuration
pros::MotorGroup left_motors({-8,-12}, pros::MotorGearset::blue); // left motors use 600 RPM cartridges
pros::MotorGroup right_motors({3, 10}, pros::MotorGearset::blue); // right motors use 200 RPM cartridges
pros::Imu imu(14);

// drivetrain settings
lemlib::Drivetrain drivetrain(&left_motors, // left motor group
                              &right_motors, // right motor group
                              11.75, // 10 inch track width
                              lemlib::Omniwheel::NEW_275, // using new 4" omnis
                              450, // drivetrain rpm is 360
                              2 // horizontal drift is 2 (for now)
);

// lateral motion controller
lemlib::ControllerSettings linearController(11, // proportional gain (kP)
                                            0, // integral gain (kI)
                                            7, // derivative gain (kD)
                                            3, // anti windup
                                            1, // small error range, in inches
                                            100, // small error range timeout, in milliseconds
                                            3, // large error range, in inches
                                            500, // large error range timeout, in milliseconds
                                            20 // maximum acceleration (slew)
);

// angular motion controller
lemlib::ControllerSettings angularController(3.5, // proportional gain (kP)
                                             0, // integral gain (kI)
                                             14, // derivative gain (kD)
                                             3, // anti windup
                                             1, // small error range, in degrees
                                             100, // small error range timeout, in milliseconds
                                             3, // large error range, in degrees
                                             500, // large error range timeout, in milliseconds
                                             0 // maximum acceleration (slew)
);

// sensors for odometry
lemlib::OdomSensors sensors(nullptr, // vertical tracking wheel
                            nullptr, // vertical tracking wheel 2, set to nullptr as we don't have a second one
                            nullptr, // horizontal tracking wheel
                            nullptr, // horizontal tracking wheel 2, set to nullptr as we don't have a second one
                            &imu // inertial sensor
);

lemlib::Chassis chassis(drivetrain, linearController, angularController, sensors);

pros::Controller master(pros::E_CONTROLLER_MASTER);
////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////

pros::MotorGroup cascade_intake({19, -11}); // lift or intake, depending on how the pto is actuated n stuff(2 11s)
pros::MotorGroup two_bar({13, -4}); // two bar connected to our lift(2 5.5s)
pros::Rotation two_barRotation(7);
pros::Motor wrist(20); // rotates the claw at the end of the twobar(5.5)
pros::Rotation wristRotation(-16);
pros::Motor claw(2); // its a claw(5.5)
pros::adi::Encoder encoder({18, 'B', 'C'}, true);
pros::adi::Pneumatics clawPiston({18, 'A'}, false); // starts retracted
pros::adi::Pneumatics pullToggle('h', false);