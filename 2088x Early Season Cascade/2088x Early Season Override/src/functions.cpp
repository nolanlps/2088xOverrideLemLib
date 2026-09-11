#include "main.h"
#include "lemlib/api.hpp" // IWYU pragma: keep


//cool functions with arm and PID and stuff

int target = 0;
const int numStates = 3;
//make sure these are in centidegrees (1 degree = 100 centidegrees)
int states[numStates] = {0, 300, 2000};
int currState = 0;


void nextState() {
    currState += 1;
    if (currState == numStates) {
        currState = 0;
    } else if(currState == 2) {
//flip wrist to not go out of sisze im too fat to code
    }
    target = states[currState];

}

void twoBarLoop() {

        double kp = 0.5;
        double error = target - two_barRotation.get_position();
        double velocity = kp * error;
        two_bar.move_voltage(velocity);
    
}

void twoBarSet(int degrees) {
  target = degrees;
}

