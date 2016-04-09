#include <kipr/botball.h>

#include "Scorpion.h"

int main()
{
    scorpion = new_scorpion();
    scorpion.init();

    scorpion.create.forward(112, 300);
    scorpion.create.right(90, 0, 150);
    scorpion.create.backward(20, 120);
    scorpion.create.forward(5, 150);
    scorpion.create.left(90, 0, 150);

    scorpion.open_claw();
    scorpion.lower_arm();

    // Get the first tribble pile

    scorpion.create.forward(20, 150);
    scorpion.grab_tribbles();
    scorpion.set_arm_to_position(ARM_PARTIAL);

    scorpion.create.right(90, 0, 150);
    scorpion.create.backward(15, 120);
    scorpion.create.forward(6, 120);
    scorpion.create.right(95, 0, 150);

    scorpion.controller.servo(BACK_SERVO, BACK_DOWN);
    msleep(500);

    // scorpion.create.backward_with_speed(39, 200, 212);
    scorpion.create.backward(35, 150);
    scorpion.create.backward(10, 100);
    scorpion.create.forward(10, 100);
    msleep(1000);
    scorpion.create.backward(10, 100);

    msleep(500);
    scorpion.create.right(10, 0, 100);
    scorpion.create.left(6, 0, 50);
    scorpion.create.backward(4, 100);

    msleep(500);
    scorpion.lift_basket_slow();
    msleep(500);

    scorpion.create.forward(10, 120);
    scorpion.create.right(1, 0, 150);
    scorpion.create.backward(30, 120);

    scorpion.raise_arm();
    scorpion.open_claw();

    // Get second tribble pile

    scorpion.create.forward(15, 150);
    scorpion.create.left(8, 0, 100);
    scorpion.create.forward(33, 200);

    scorpion.lower_arm();
    scorpion.create.forward(22, 150);
    scorpion.grab_tribbles();

    scorpion.create.backward(5, 150);

    scorpion.raise_arm();
    scorpion.open_claw();

    // Get third tribble pile

    scorpion.create.left(145, 0, 150);
    scorpion.create.backward(10, 150);
    msleep(1000);

    scorpion.lower_arm();

    //scorpion.track();
    //scorpion.create.left(3, 0, 150);
    scorpion.create.forward(8, 150);
    scorpion.grab_tribbles();

    scorpion.create.backward(20, 200);
    scorpion.raise_arm();
    scorpion.open_claw();

    // check if there are tribbles remaining - TODO

  // scorpion.create.forward(10, 100);

    // squaring robot

    scorpion.create.right(65, 0, 150);
    scorpion.create.backward(30, 200);
    scorpion.create.forward(12, 150);
    scorpion.create.left(91, 0, 150);
    scorpion.create.forward_until_bump(250);
    scorpion.create.backward(5, 120);

    // squaring in corner

    scorpion.create.right(90, 0, 150);
    scorpion.create.backward(20, 120);
    scorpion.create.forward(10, 150);
    scorpion.create.right(90, 0, 150);
    scorpion.create.backward(15, 150);
    scorpion.create.forward(5, 150);
    scorpion.create.left(92, 0, 150);
    scorpion.create.forward(18, 150);

    // grabbing 4th pile

    scorpion.open_claw();
    scorpion.lower_arm();
    scorpion.create.forward(10, 150);
    scorpion.grab_tribbles();
    scorpion.raise_arm();
    scorpion.open_claw();
    scorpion.set_claw_to_position(CLAW_OPEN - 250);

    // scorpion.create.forward_until_bump(250);

    scorpion.lower_arm();
    scorpion.create.forward(25, 150);
    scorpion.grab_tribbles();
    scorpion.raise_arm();
    scorpion.open_claw();

    scorpion.create.forward_until_bump(250);
    scorpion.create.backward(10, 150);
    scorpion.create.right(90, 0, 250);
    scorpion.create.backward(15, 150);

    scorpion.create.forward(40, 250);
    scorpion.lower_arm();
    scorpion.create.forward(10, 150);
    scorpion.grab_tribbles();
    scorpion.raise_arm();
    scorpion.open_claw();
    scorpion.shake_arm();

    scorpion.deinit();
  	return 0;
}
