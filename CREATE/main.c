#include <kipr/botball.h>

#include "Scorpion.h"

enum GameType {
    SEEDING = 0,
    DOUBLE_ELIM = 1
};


// ----------- SEEDING -----------


void seeding() {
    msleep(15000); // wait for wallaby

    scorpion.create.backward(15, 120);

    scorpion.create.forward(80, 300);
    scorpion.create.right(90, 0, 250);
    scorpion.create.backward(20, 120);
    scorpion.create.forward(6, 200);
    scorpion.create.left(90, 0, 200);

    scorpion.set_claw_to_position(CLAW_OPEN - 350);
    scorpion.lower_arm();

    // Get the first tribble pile

    scorpion.create.forward(44, 280);
    scorpion.grab_tribbles_slow();
    scorpion.set_arm_to_position(ARM_PARTIAL);
    scorpion.create.forward(16, 250);

    scorpion.create.right(90, 0, 150);
    scorpion.create.backward(18, 150);
    scorpion.create.forward(7, 150);
    scorpion.create.right(89, 0, 150);

    scorpion.controller.servo(BACK_SERVO, BACK_DOWN);
    msleep(250);

    scorpion.create.backward(5, 300);
    scorpion.create.backward_with_speed(17, 250, 245);
    scorpion.create.forward(10, 150);
    msleep(500);
    scorpion.create.backward(10, 120);

    scorpion.create.right(16, 0, 100);
    scorpion.create.left(6, 0, 50);
    scorpion.create.forward(10, 150);
    scorpion.create.backward(14, 120);

    scorpion.lift_basket_slow();

    scorpion.create.backward(35, 180);

    // Get second tribble pile

    scorpion.create.forward(15, 250);
    scorpion.create.left(6, 0, 200);
    scorpion.create.forward(30, 300);

    scorpion.raise_arm();
    scorpion.set_claw_to_position(CLAW_OPEN - 200);
    scorpion.set_arm_to_position(1890);

    scorpion.create.forward(22, 150);
    scorpion.grab_tribbles();

    scorpion.create.backward(5, 150);

    scorpion.raise_arm();
    scorpion.open_claw();

    // Get third tribble pile

    scorpion.create.left(156, 0, 250);
    scorpion.create.backward(22, 150);

    scorpion.lower_arm();

    scorpion.create.forward(20, 150);
    scorpion.grab_tribbles();

    scorpion.raise_arm();
    scorpion.set_claw_to_position(CLAW_PARTIAL);

    // squaring robot

    scorpion.create.right(88, 0, 250);
    scorpion.create.backward(30, 200);
    scorpion.create.forward(12, 150);
    scorpion.create.right(92, 0, 150);
    scorpion.create.backward(50, 300);
    scorpion.create.backward(20, 150);

    // squaring in corner

    scorpion.create.forward(7, 150);
    scorpion.create.left(93, 0, 150);
    scorpion.create.forward(13, 300);

    // grabbing 4th pile

    scorpion.open_claw();
    scorpion.lower_arm();
    scorpion.create.forward(10, 250);
    scorpion.grab_tribbles();
    msleep(400);

    // move out from under the ridge to score tribbles

    scorpion.set_arm_to_position(ARM_PARTIAL + 600);
    scorpion.create.forward(45, 250);
    scorpion.raise_arm();
    scorpion.set_claw_to_position(CLAW_PARTIAL);
    scorpion.set_arm_to_position(ARM_PARTIAL);

    // grabbing 5th pile

    scorpion.create.backward(30, 250);
    scorpion.set_arm_to_position(1850);
    scorpion.grab_tribbles_slow();
    scorpion.set_arm_to_position(ARM_PARTIAL);

    // squaring in the center of the field

    scorpion.create.forward(22, 300);
    scorpion.create.right(90, 0, 150);
    scorpion.create.backward(20, 150);
    scorpion.raise_arm();
    scorpion.set_claw_to_position(CLAW_PARTIAL);

    // move block (red/green) out of the way

    scorpion.set_arm_to_position(1700); // not parallel to tribbles
    scorpion.create.forward(34, 250);
    scorpion.close_claw();
    scorpion.set_arm_to_position(ARM_PARTIAL);
    scorpion.create.left(90, 0, 150);
    scorpion.set_arm_to_position(ARM_DOWN - 300);
    scorpion.set_claw_to_position(CLAW_OPEN - 400);
    scorpion.set_arm_to_position(ARM_PARTIAL);
    scorpion.create.right(90, 0, 150);
    scorpion.lower_arm();

    // grabbing 6th pile

    scorpion.create.forward(10, 250);
    scorpion.grab_tribbles();
    msleep(500);
    scorpion.raise_arm();
    msleep(200);
    scorpion.open_claw();
    msleep(200);
    scorpion.close_claw();

    // return to base

    scorpion.create.backward(50, 350);
    scorpion.create.backward(15, 120);
    scorpion.create.forward(12, 250);
    scorpion.create.right(90, 0, 250);
    scorpion.create.forward(109, 350);
    scorpion.create.left(92, 0, 150);
    scorpion.create.backward(20, 150);
 	scorpion.create.forward_with_speed(180, 300, 297);

    // score!

    scorpion.lower_arm();
    scorpion.drop_basket_slow();
}



// ----------- DE -----------


void double_elimination() {

    // counter variables
    int red_count, green_count = 0;

    scorpion.create.backward(15, 120);

    scorpion.create.forward(30, 300);
    scorpion.lower_arm();
    scorpion.set_claw_to_position(CLAW_PARTIAL);
    scorpion.grab_tribbles();
    scorpion.raise_arm();

    scorpion.create.right(90, 0, 250);
    scorpion.create.backward(20, 120);
    scorpion.create.forward(6, 200);
    scorpion.create.left(90, 0, 200);

    scorpion.create.forward(40, 250);
    scorpion.lower_arm();

    // Get the first tribble pile

    scorpion.set_claw_to_position(CLAW_OPEN - 350);
    scorpion.create.forward(30, 280);

    scorpion.determine_action(&red_count, &green_count);
    printf("red_count: %d, green_count: %d\n\n", red_count, green_count);

    scorpion.set_arm_to_position(ARM_PARTIAL);
    scorpion.create.forward(25, 250);

    scorpion.create.right(90, 0, 150);
    scorpion.create.backward(18, 150);
    scorpion.create.forward(7, 150);
    scorpion.create.right(89, 0, 150);

    scorpion.controller.servo(BACK_SERVO, BACK_DOWN);
    msleep(250);

    // lifting up basket

    scorpion.create.backward(5, 300);
    scorpion.create.backward_with_speed(17, 250, 245);
    scorpion.create.forward(10, 150);
    msleep(500);
    scorpion.create.backward(10, 120);

    scorpion.create.right(16, 0, 100);
    scorpion.create.left(6, 0, 50);
    scorpion.create.forward(10, 150);
    scorpion.create.backward(14, 120);

    scorpion.lift_basket_slow();

    scorpion.create.backward(35, 180);

    // Get second tribble pile

    scorpion.create.forward(15, 250);
    scorpion.create.left(6, 0, 200);
    scorpion.create.forward(30, 300);

    scorpion.raise_arm();
    scorpion.set_claw_to_position(CLAW_OPEN - 200);
    scorpion.set_arm_to_position(1890);

    scorpion.create.forward(22, 150);

    scorpion.determine_action(&red_count, &green_count);
    printf("red_count: %d, green_count: %d\n\n", red_count, green_count);

    scorpion.create.backward(5, 150);

    scorpion.raise_arm();
    scorpion.open_claw();

    // Get third tribble pile

    scorpion.create.left(156, 0, 250);
    scorpion.create.backward(22, 150);

    scorpion.lower_arm();

    scorpion.create.forward(20, 150);
    scorpion.grab_tribbles();

    scorpion.raise_arm();
    scorpion.set_claw_to_position(CLAW_PARTIAL);

    // squaring robot

    scorpion.create.right(88, 0, 250);
    scorpion.create.backward(30, 200);
    scorpion.create.forward(12, 150);
    scorpion.create.right(92, 0, 150);
    scorpion.create.backward(50, 300);
    scorpion.create.backward(20, 150);

    // squaring in corner

    scorpion.create.forward(7, 150);
    scorpion.create.left(93, 0, 150);
    scorpion.create.forward(13, 300);

    // grabbing 4th pile

    scorpion.open_claw();
    scorpion.lower_arm();
    scorpion.create.forward(10, 250);
    scorpion.grab_tribbles();
    msleep(400);

    scorpion.create.backward(50, 350);
    scorpion.create.backward(15, 120);
    scorpion.create.forward(12, 250);
    scorpion.create.right(90, 0, 250);
    scorpion.create.forward(109, 350);
    scorpion.create.left(92, 0, 150);
    scorpion.create.backward(20, 150);
 	scorpion.create.forward_with_speed(180, 300, 297);

    scorpion.lower_arm();
    scorpion.drop_basket_slow();
}

int main() {
    scorpion = new_scorpion();
    scorpion.init();

    enum GameType game_type = DOUBLE_ELIM;

    shut_down_in(119);

    if(game_type == SEEDING) seeding();
    else if(game_type == DOUBLE_ELIM) double_elimination();

    scorpion.deinit();
  	return 0;
}
