//
//  Scorpion.c
//  Source written by Justin Yu
//

#include "Scorpion.h"
#include <math.h>

// custom subroutines

static void init() {
    scorpion.create.connect();
    scorpion.camera.open();

    scorpion.controller.enable_servos();
    scorpion.controller.servo(BACK_SERVO, BACK_UP);
    scorpion.set_claw_to_position(CLAW_PARTIAL);
    scorpion.set_arm_to_position(ARM_UP);
}

static void deinit() {
    scorpion.camera.close();
    scorpion.create.disconnect();
}

static void shake_arm() {
    scorpion.controller.servo(ARM_SERVO, 0);
    msleep(250);
    int i;
    for(i = 0; i < 3; i++) {
        scorpion.controller.servo(ARM_SERVO, ARM_UP);
        msleep(200);
        scorpion.controller.servo(ARM_SERVO, 0);
        msleep(200);
    }}

static void lower_arm() {
    scorpion.controller.slow_servo(ARM_SERVO, ARM_DOWN, SERVO_DURATION);
}

static void raise_arm() {
    scorpion.controller.slow_servo(ARM_SERVO, ARM_UP, SERVO_DURATION);
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

static void lift_basket() {
    scorpion.controller.servo(BACK_SERVO, BACK_UP);
    msleep(500);
}

static void drop_basket() {
    scorpion.controller.servo(BACK_SERVO, BACK_DOWN);
    msleep(500);
}

static void lift_basket_slow() {
    scorpion.controller.slow_servo(BACK_SERVO, BACK_UP, SERVO_DURATION);
}

static void drop_basket_slow() {
    scorpion.controller.slow_servo(BACK_SERVO, BACK_DOWN, SERVO_DURATION);
}

static void grab_tribbles() {
    scorpion.controller.slow_servo(CLAW_SERVO, CLAW_PARTIAL, 0.8);
    scorpion.create.forward(12, 100);
    scorpion.close_claw_slow(1.2);
}

static enum Channel get_tribble_color() {
    scorpion.camera.update();
    scorpion.camera.update();

    enum Channel desired_channel;

    scorpion.create.drive_direct(20, 20);
    while(1) {
        scorpion.camera.update();
        scorpion.camera.update();
        scorpion.camera.update();

        int red_area = scorpion.camera.get_object_area(RED_CHANNEL, 0);
        int green_area = scorpion.camera.get_object_area(GREEN_CHANNEL, 0);
        if(red_area == -1 && green_area == -1) {
            continue;
        }
        if(red_area < green_area) {
            printf("GREEN\n\n");
            desired_channel = GREEN_CHANNEL;
            break;
        } else if(red_area > green_area) {
            printf("RED\n\n");
            desired_channel = RED_CHANNEL;
            break;
        }
        msleep(20);
    }
    scorpion.create.stop();

    return desired_channel;
}

static enum Channel track_tribbles() {
    enum Channel desired_channel = scorpion.get_tribble_color();

    printf("DESIRED CHANNEL = %d\n", desired_channel);

    while(1) {
        scorpion.camera.update();

        int x = scorpion.camera.get_object_center_x(desired_channel, 0);
        if(x >= 0 && x <= 72) { // left
            scorpion.create.spin_counterclockwise(40);
        } else if(x >= 89 && x <= 159) {
            scorpion.create.spin_clockwise(40);
        } else if(x >= 73 && x <= 88) { // center range
             break;
        }
        msleep(5);

        if(scorpion.create.get_lbump() == 1) {
             scorpion.create.right(1, 0, 150);
             break;
        }
        if(scorpion.create.get_rbump() == 1) {
             scorpion.create.left(1, 0, 150);
             break;
        }
    }
    scorpion.create.stop();

    return desired_channel;
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
        .close_claw_slow = &close_claw_slow,
        .set_claw_to_position = &set_claw_to_position,
        .set_arm_to_position = &set_arm_to_position,
        .lift_basket = &lift_basket,
        .drop_basket = &drop_basket,
        .lift_basket_slow = &lift_basket_slow,
        .drop_basket_slow = &drop_basket_slow,
        .track = &track_tribbles,
        .get_tribble_color = &get_tribble_color,
        .init = &init,
        .deinit = &deinit
    };
    instance.create = new_create();
    instance.controller = new_create_controller();
    instance.camera = new_camera();
    return instance;
}
