//
//  Create.c
//  Source written by Justin Yu
//

#include "Create.h"
#include <math.h>

// Methods Prototypes

static void create_write_int(int decimal);
static void forward(float dist, int speed);
static void backward(float dist, int speed);
static void left(int angle, float radius, int speed);
static void right(int angle, float radius, int speed);

// Number of "create ticks" per centimeter moved
#define CTICK_PER_CM 10.0

#define get_high_byte(byte) ((byte >> 8) & 255)
#define get_low_byte(byte) (byte & 255)

static void create_write_int(int decimal) {
  	// [high byte][low byte]
    create.write_byte(get_high_byte(decimal));
    create.write_byte(get_low_byte(decimal));
}

static void forward(float dist, int speed) {
    if(speed < -500 || speed > 500)
        return;
    if(dist < 0.) {
        create.backward(-dist, speed);
        return;
    }

    // t = d / r
    float travel_time = (dist * 10) / (float)speed; // speed is in mm/sec
    create.drive_direct(speed, speed);
    msleep(travel_time * 1000.); // convert to milliseconds

    create.block();
}

static void backward(float dist, int speed) {
    // Make sure parameters are valid
    if(speed < -500 || speed > 500)
        return;
    if(dist < 0.) {
        create.forward(-dist, speed);
        return;
    }

    // t = d / r
    float travel_time = (dist * 10) / (float)speed; // speed is in mm/sec
    create.drive_direct(-speed, -speed);
    msleep(travel_time * 1000.); // convert to milliseconds

    create.block();
}

static void forward_with_speed(float dist, int left_speed, int right_speed) {
    // Make sure parameters are valid
    if(left_speed < -500 || right_speed > 500 || right_speed < -500 || right_speed > 500)
        return;

    // t = d / r
    float travel_time = (dist * 10) / (float)((left_speed + right_speed) / 2); // speed is in mm/sec
    create.drive_direct(left_speed, right_speed);
    msleep(travel_time * 1000.); // convert to milliseconds

    create.block();
}

static void backward_with_speed(float dist, int left_speed, int right_speed) {
    // Make sure parameters are valid
    if(left_speed < -500 || right_speed > 500 || right_speed < -500 || right_speed > 500)
        return;

    // t = d / r
    float travel_time = (dist * 10) / (float)((left_speed + right_speed) / 2); // speed is in mm/sec
    create.drive_direct(-left_speed, -right_speed);
    msleep(travel_time * 1000.); // convert to milliseconds

    create.block();
}

static void forward_until_bump(int speed) {
    create.drive_direct(speed, speed);
    while(create.get_lbump() == 0 && create.get_rbump() == 0
          && create.get_lclightbump() == 0 && create.get_rclightbump() == 0) {
        msleep(10);
    }
    create.stop();
}

static void left(int angle, float radius, int speed) {
    if(radius < 0.)
        return;
    if (speed < -500 || speed > 500)
        return;
    if(angle < 0.) {
        create.right(-angle, radius, speed);
        return;
    }

    long radiusTicks = radius * CTICK_PER_CM;
    create.set_total_angle(0);

  	// create turn byte (decimal): 137
  	// [137][speed high][speed low][radius high][radius low]

    if(radius == 0) {
        create_spin_CCW(speed);
    } else {
        create.write_byte(137);
        create.write_int(speed);
        create.write_int(radiusTicks);
    }

    while(create.get_total_angle() < angle);

    create.block();
}

static void right(int angle, float radius, int speed) {
    if(radius < 0.)
        return;
    if (speed < -500 || speed > 500)
        return;
    if(angle < 0.) {
        create.left(-angle, radius, speed);
        return;
    }

    long radiusTicks = radius * CTICK_PER_CM;
    create.set_total_angle(0);

    if(radius == 0)
        create_spin_CW(speed);
    else {
        // create turn byte (decimal): 137
        // [137][speed high][speed low][radius high][radius low]
        create.write_byte(137);
        create.write_int(speed);
        create.write_int(-radiusTicks);
    }

    while(create.get_total_angle() >= -angle);

    create.block();
}

static void send() {
    create.write_byte(142); // Sensor input
    create.write_byte(35);	// 35 : OI Mode
}

static void receive() {
    char buffer[1];
    char *bptr = buffer;
    create_read_block(bptr, 1);
}

static void block() {
    create.stop();
    create.send();
    create.receive();
}

Create new_create() {
    Create instance = {
        // Assign method references
        .forward = &forward,
        .backward = &backward,
        .forward_with_speed = &forward_with_speed,
        .backward_with_speed = &backward_with_speed,
        .forward_until_bump = &forward_until_bump,
        .left = &left,
        .right = &right,
        .drive_direct = &create_drive_direct,
        .spin_clockwise = &create_spin_CW,
        .spin_counterclockwise = &create_spin_CCW,
        .stop = &create_stop,
        .get_distance = &get_create_distance,
        .set_distance = &set_create_distance,
        .get_total_angle = &get_create_total_angle,
        .set_total_angle = &set_create_total_angle,
        .get_lbump = &get_create_lbump,
        .get_rbump = &get_create_rbump,
        .get_lclightbump = &get_create_lclightbump,
        .get_rclightbump = &get_create_rclightbump,
        .write_byte = &create_write_byte,
        .write_int = &create_write_int,
        .block = &block,
        .send = &send,
        .receive = &receive,
        .get_battery_charge = &get_create_battery_charge,
        .full = &create_full,
        .connect = &create_connect,
        .disconnect = &create_disconnect
    };
    create = instance;
    return instance;
}
