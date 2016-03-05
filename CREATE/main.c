#include <kipr/botball.h>

// #include "Create.h"
#include "Scorpion.h"
#include "create.h"
#include "generic.h"

int main()
{
    scorpion = new_scorpion();

    scorpion.create.connect();

    scorpion.wallaby.enable_servos();
    scorpion.wallaby.set_servo_position(BACK_SERVO, BACK_UP);
    scorpion.wallaby.set_servo_position(ARM_SERVO, ARM_UP);
    msleep(2000);

    scorpion.create.forward(4.5, 150);
    scorpion.create.left(89, 0, 150);

    scorpion.wallaby.set_servo_position(CLAW_SERVO, CLAW_PARTIAL);
    scorpion.wallaby.set_servo_position(ARM_SERVO, ARM_DOWN - 400);
    msleep(500);
    scorpion.create.forward(98, 250);
    scorpion.open_claw();

    scorpion.wallaby.set_servo_position(ARM_SERVO, ARM_DOWN);
    msleep(200);
    scorpion.wallaby.slow_servo(CLAW_SERVO, CLAW_PARTIAL, 1.2);
    msleep(200);

    // Get the first tribble pile

    scorpion.create.forward(2, 50);
    //scorpion.create.right(2, 0, 50);
    scorpion.create.forward(8, 50);
    scorpion.wallaby.slow_servo(CLAW_SERVO, CLAW_CLOSED, 1.2);
    msleep(200);

    scorpion.wallaby.set_servo_position(ARM_SERVO, ARM_UP);
    msleep(400);

    scorpion.create.right(195, 0, 150);
    scorpion.wallaby.set_servo_position(BACK_SERVO, BACK_DOWN);
    msleep(500);
    scorpion.create.backward(34, 100);
	scorpion.create.left(36, 0, 100);
    scorpion.create.backward(23, 100);
    scorpion.create.right(10, 0, 100);
    scorpion.create.backward(5, 150);

    scorpion.wallaby.set_servo_position(BACK_SERVO, BACK_UP);
    msleep(2000);
    scorpion.create.forward(3, 100);
    //create_backward(5, 100);

    scorpion.wallaby.set_servo_position(ARM_SERVO, ARM_DOWN);
    msleep(500);
    scorpion.wallaby.set_servo_position(ARM_SERVO, ARM_UP);
    msleep(500);
    scorpion.wallaby.set_servo_position(CLAW_SERVO, CLAW_OPEN);
    msleep(2000);

    scorpion.shake_arm();

    scorpion.create.left(10, 0, 100);
    scorpion.create.forward(35, 100);
    scorpion.lower_arm();
    scorpion.set_claw_to_position(CLAW_PARTIAL);
    scorpion.create.forward(5, 100);
    scorpion.close_claw_slow(1.2);

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
