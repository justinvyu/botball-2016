//
//  main.c
//  Source written by Justin Yu
//

#include <kipr/botball.h>

// #include "Create.h"
#include "Scorpion.h"
#include "create.h"
#include "generic.h"

int main()
{
    scorpion = new_scorpion();

    scorpion.create.connect();

    scorpion.create.forward(3, 150);
    scorpion.create.left(90, 0, 150);

    scorpion.wallaby.set_servo_position(CLAW_SERVO, CLAW_OPEN);
    scorpion.wallaby.set_servo_position(ARM_SERVO, ARM_DOWN - 200);
    scorpion.wallaby.set_servo_position(BACK_SERVO, BACK_UP);
    scorpion.wallaby.enable_servos();

    scorpion.create.forward(105, 250);
    scorpion.create.left(1, 0, 50);

    scorpion.wallaby.set_servo_position(ARM_SERVO, ARM_DOWN);
    msleep(200);
    scorpion.wallaby.slow_servo(CLAW_SERVO, CLAW_PARTIAL, 1.2);
    msleep(200);

    scorpion.create.forward(2, 50);
    scorpion.create.right(2, 0, 50);
    scorpion.create.forward(8, 50);
    scorpion.wallaby.slow_servo(CLAW_SERVO, CLAW_CLOSED, 1.2);
    msleep(200);

    scorpion.wallaby.set_servo_position(ARM_SERVO, ARM_UP);
    msleep(400);

    create_right(210, 0, 150);
    scorpion.wallaby.set_servo_position(BACK_SERVO, BACK_LIFTED);
    msleep(500);
    scorpion.create.backward(30, 100);
    create_left(18, 0, 100);
    scorpion.create.backward(35, 100);
    scorpion.wallaby.set_servo_position(BACK_SERVO, BACK_UP);
    msleep(2000);
    scorpion.create.forward(5, 100);
    //create_backward(6, 100);
    scorpion.wallaby.set_servo_position(ARM_SERVO, ARM_DOWN);
    msleep(500);
    scorpion.wallaby.set_servo_position(ARM_SERVO, ARM_UP);
    msleep(500);
    scorpion.wallaby.set_servo_position(CLAW_SERVO, CLAW_OPEN);
    msleep(2000);

    scorpion.shake_arm();
    scorpion.create.backward(15, 50);
    scorpion.create.left(15, 0, 100);
    scorpion.lower_arm();
    scorpion.create.forward(20, 100);
    scorpion.set_claw_to_position(CLAW_PARTIAL);
    scorpion.create.forward(5, 100);
    scorpion.close_claw();

    scorpion.create.backward(10, 150);
    scorpion.wallaby.set_servo_position(ARM_SERVO, ARM_DOWN);
    msleep(500);
    scorpion.wallaby.set_servo_position(ARM_SERVO, ARM_UP);
    msleep(500);
    scorpion.wallaby.set_servo_position(CLAW_SERVO, CLAW_OPEN);
    msleep(2000);

    scorpion.shake_arm();

  	return 0;
}
