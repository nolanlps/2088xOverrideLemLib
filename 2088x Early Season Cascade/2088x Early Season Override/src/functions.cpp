#include "main.h"
#include "lemlib/api.hpp" // IWYU pragma: keep
#include <algorithm>
#include <cmath>

// Forward declarations so functions can be used before they are defined
void wristSet(int centidegrees);
void twoBarSet(int centidegrees);

// ALL positions in this file are in CENTIDEGREES (1 degree = 100 centidegrees)
// e.g. 180 degrees = 18000

static constexpr double MAX_MV = 12000.0; // move_voltage limit (millivolts)

////////////////////////////////////////////////////////////////
// WRIST PID
////////////////////////////////////////////////////////////////
int target1 = 0;
// const int numStates1 = 2;
// int states1[numStates1] = {0, 18000}; // 0 deg, 180 deg
// int currState1 = 0;
static int lastWristPos = 0;

// When true, wristControl() decides the wrist target from the arm position.
// Set to false if you want to control the wrist manually (wristCycle/wristSet).
bool wristAutoControl = true;

void wristLoop() {
    // TUNING: raise kp until it moves well, raise kd to stop overshoot.
    const double kp1 = 1.75;
    const double kd1 = 9.6;

    int pos = wristRotation.get_position();
    if (pos == PROS_ERR) return; // sensor read failed, don't drive blindly

    double error = target1 - pos;
    double velocity = pos - lastWristPos; // centidegrees per loop (10 ms)
    lastWristPos = pos;

    // Derivative on measurement (not on error) so changing the target
    // doesn't cause a sudden voltage spike.
    double output = (kp1 * error) - (kd1 * velocity);
    output = std::clamp(output, -MAX_MV, MAX_MV);

    wrist.move_voltage(static_cast<int32_t>(output));
}
//////////////////////////////////////////////////////////////////////////
// Runs ONCE per call (called every 10 ms from pidLoop). No while loop here!
void wristControl() {
    if (!wristAutoControl) return;

    // Arm angle thresholds in centidegrees (these were 210 / 275 degrees)
    const int TRACK_START = 16300;
    const int BACK_START = 2500;
    const int tung_start = 8000;
    const int BAD_START = 16000;

    int arm = two_barRotation.get_position();
    if (arm == PROS_ERR) return;

    if (arm < BACK_START) {
        wristSet(0);              // arm is all the way back
    } else if (arm > BACK_START) {
        wristSet(-(arm - BAD_START));
    // } else if (arm > tung_start) {
    //     wristSet((arm - TRACK_START));  // wrist follows arm, starting from 0
    } else {
        wristSet(0);                  // arm is in the normal range
    }
}
/////////////////////////////////////////////////////////


void wristSet(int centidegrees) {
    target1 = centidegrees;
}

////////////////////////////////////////////////////////////////
// TWO BAR (ARM) PID
////////////////////////////////////////////////////////////////
int target = 0;
const int numStates = 2;
int states[numStates] = {0, 27600}; // 0, 300, 180 degrees
int currState = 0;
static int lastTwoBarPos = 0;

void twoBarLoop() {
    // TUNING: the arm is heavier than the wrist, so it may need more kd.
    const double kp = 3;
    const double kd = 15;

    int pos = two_barRotation.get_position();
    if (pos == PROS_ERR) return;

    double error = target - pos;
    double velocity = pos - lastTwoBarPos;
    lastTwoBarPos = pos;

    double output = (kp * error) - (kd * velocity);
    output = std::clamp(output, -MAX_MV, MAX_MV);

    two_bar.move_voltage(static_cast<int32_t>(output));
}


const int numStates1 = 2;
int states1[numStates1] = {18000, 12000};
int currState1 = 0;

void highScoreCycle() {
    currState1 = (currState1 + 1) % numStates;
    if (currState1 == numStates1) {
        currState1 = 0;
    }
    target = states1[currState1];
}

void backMatchloadCycle() {
    // wrap around so we never read past the end of states[]
    currState = (currState + 1) % numStates;
    if (currState == numStates) {
        currState = 0;
    }
    // update the target FIRST, then make decisions based on the new target
    target = states[currState];
    
    // Manual wrist flip only when auto control is off
    // (otherwise wristControl() would overwrite it within 10 ms anyway)
    // if (!wristAutoControl) {
    //     if (target >= 30000) {
    //         wristSet(18000); // flip wrist so it doesn't go out of size
    //     } else if (target > 18000) {
    //         wristSet(0);
    //     }
    // }
}

void twoBarSet(int degrees) {
    target = degrees * 100;
}
