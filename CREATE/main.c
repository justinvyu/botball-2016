#include <kipr/botball.h>

#include "Scorpion.h"

int main()
{
    scorpion = new_scorpion();

    scorpion.create.connect();
    scorpion.camera.open();

    scorpion.camera.update();
    scorpion.camera.update();

    printf("w: %d, h: %d", scorpion.camera.get_width(), scorpion.camera.get_height());

    scorpion.controller.enable_servos();

    scorpion.controller.servo(BACK_SERVO, BACK_UP);
    scorpion.set_claw_to_position(CLAW_PARTIAL);
    scorpion.set_arm_to_position(ARM_UP);

    scorpion.create.forward(105, 250);
    // scorpion.create.left(2, 0, 100);

    scorpion.open_claw();
    scorpion.lower_arm();

    scorpion.create.forward(2, 100);
    scorpion.create.left(1, 0, 100);

    // Get the first tribble pile

    scorpion.track();
    scorpion.create.forward(25, 150);
    scorpion.grab_tribbles();
    scorpion.set_arm_to_position(ARM_PARTIAL);

    scorpion.create.right(90, 0, 150);
    scorpion.create.backward(15, 120);
    scorpion.create.forward(3, 120);
    scorpion.create.right(87, 0, 150);

    scorpion.controller.servo(BACK_SERVO, BACK_DOWN);
    msleep(500);

    scorpion.create.backward(30, 200);
   // scorpion.create.left(14, 0, 100);
    scorpion.create.backward(14, 150);
    scorpion.create.left(1, 0, 100);
    scorpion.create.backward(4, 100);

    msleep(500);
    scorpion.create.right(8, 0, 100);
    scorpion.create.left(2, 0, 50);
    scorpion.create.right(2, 0, 50);
    scorpion.create.left(2, 0, 50);
    scorpion.create.backward(6, 150);

    scorpion.lift_basket_slow();

    scorpion.create.backward(10, 120);
    scorpion.create.forward(10, 100);

    scorpion.raise_arm();
    scorpion.open_claw();

    // Get second tribble pile

    scorpion.create.left(10, 0, 100);
    scorpion.create.forward(33, 200);

    scorpion.lower_arm();
    scorpion.create.right(5, 20, 200);
    scorpion.track();
    msleep(2000);
    scorpion.create.forward(10, 150);
    scorpion.grab_tribbles();

    scorpion.create.backward(5, 150);

    scorpion.raise_arm();
    scorpion.open_claw();
    scorpion.shake();

    // Get third tribble pile

    scorpion.create.left(135, 0, 150);
    scorpion.create.backward(10, 150);
    msleep(1000);

    scorpion.lower_arm();
    scorpion.track();
    scorpion.grab_tribbles();

    scorpion.create.backward(20, 200);
    scorpion.raise_arm();
    scorpion.open_claw();
    scorpion.shake();

    scorpion.drop_basket_slow();
    scorpion.camera.close();
    scorpion.create.disconnect();

  	return 0;
}
