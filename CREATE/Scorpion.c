//
//  Scorpion.c
//  Source written by Justin Yu
//

#include "Scorpion.h"
#include "generic.h"
#include <math.h>

static void shake_arm() {
    int i;
    for(i = 0; i < 3; i++) {
        set_servo_position(ARM_SERVO, ARM_UP_UP);
        msleep(200);
        set_servo_position(ARM_SERVO, ARM_UP);
        msleep(200);
    }
}

static void lower_arm() {
    set_servo_position(ARM_SERVO, ARM_DOWN);
    msleep(200);
}

static void raise_arm() {
    set_servo_position(ARM_SERVO, ARM_UP);
    msleep(200);
}

static void open_claw() {
    set_servo_position(CLAW_SERVO, CLAW_OPEN);
    msleep(200);
}

static void close_claw() {
    set_servo_position(CLAW_SERVO, CLAW_CLOSED);
    msleep(200);
}

static void set_claw_to_position(int position) {
    set_servo_position(CLAW_SERVO, position);
    msleep(200);
}

static void grab_tribbles() {
    servo_set(CLAW_SERVO, CLAW_CLOSED, 1.5);
    msleep(1000);

    set_servo_position(ARM_SERVO, ARM_UP);
    msleep(200);

    set_servo_position(CLAW_SERVO, CLAW_OPEN);
    msleep(1000);

    shake_arm();

    set_servo_position(ARM_SERVO, ARM_DOWN);
    msleep(200);
}

Scorpion new_scorpion() {
	Scorpion instance = {
        // Assign instance properties
        .grab_tribbles = &grab_tribbles,
        .shake_arm = &shake_arm,
        .lower_arm = &lower_arm,
        .raise_arm = &raise_arm,
        .open_claw = &open_claw,
        .close_claw = &close_claw,
        .set_claw_to_position = &set_claw_to_position
    };
    instance.create = new_create();
    instance.wallaby = new_create_controller();
    return instance;
}
