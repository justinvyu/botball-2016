//
//  Scorpion.c
//  Source written by Justin Yu
//

#include "Scorpion.h"
#include <math.h>

// custom subroutines

static void shake() {
    scorpion.set_arm_to_position(ARM_PARTIAL);
    int i;
    for(i = 0; i < 3; i++) {
        scorpion.controller.servo(BACK_SERVO, BACK_UP + 150);
        msleep(200);
        scorpion.controller.servo(BACK_SERVO, BACK_UP);
        msleep(200);
    }
    scorpion.raise_arm();
}

static void lower_arm() {
    scorpion.controller.servo(ARM_SERVO, ARM_DOWN);
    msleep(500);
}

static void raise_arm() {
    scorpion.controller.servo(ARM_SERVO, ARM_UP);
    msleep(500);
}

static void open_claw() {
    scorpion.controller.servo(CLAW_SERVO, CLAW_OPEN);
    msleep(500);
}

static void close_claw() {
    scorpion.controller.servo(CLAW_SERVO, CLAW_CLOSED);
    msleep(500);
}

static void close_claw_slow(float time) {
    scorpion.controller.slow_servo(CLAW_SERVO, CLAW_CLOSED, time);
}

static void set_claw_to_position(int position) {
    scorpion.controller.servo(CLAW_SERVO, position);
    msleep(500);
}

static void set_arm_to_position(int position) {
    scorpion.controller.servo(ARM_SERVO, position);
    msleep(500);
}

static void grab_tribbles() {
    scorpion.set_claw_to_position(CLAW_PARTIAL);
    scorpion.create.forward(12, 100);
    scorpion.close_claw_slow(1.2);
}

Scorpion new_scorpion() {
	Scorpion instance = {
        // Assign instance properties
        .grab_tribbles = &grab_tribbles,
        .shake = &shake,
        .lower_arm = &lower_arm,
        .raise_arm = &raise_arm,
        .open_claw = &open_claw,
        .close_claw = &close_claw,
        .close_claw_slow = &close_claw_slow,
        .set_claw_to_position = &set_claw_to_position,
        .set_arm_to_position = &set_arm_to_position
    };
    instance.create = new_create();
    instance.controller = new_create_controller();
    return instance;
}
