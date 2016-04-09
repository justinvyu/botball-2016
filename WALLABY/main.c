#include <kipr/botball.h>

#include "drive.h"

#define TOPHAT_LEFT 4
#define TOPHAT_RIGHT 5
#define THRESHOLD 850 // > 900 = on black duct tape  used to be 600

void line_follow() {
    motor(MOT_LEFT, 70);
    motor(MOT_RIGHT, 70);
    while(1) {
        if(analog10(TOPHAT_LEFT) > THRESHOLD) { // on black tape
            printf("Left side on the tape:  %d, %d", analog10(TOPHAT_LEFT), analog10(TOPHAT_RIGHT));
            motor(MOT_LEFT, -30);
            motor(MOT_RIGHT, 90);
        } else if(analog10(TOPHAT_RIGHT) > THRESHOLD) {
            motor(MOT_RIGHT, -30);
            motor(MOT_LEFT, 90);
        } else {
            printf("Going straight:  %d, %d", analog10(TOPHAT_LEFT), analog10(TOPHAT_RIGHT));
            motor(MOT_LEFT, 100);
            motor(MOT_RIGHT, 100);
        }
        msleep(50);
    }
}

void line_follow_R() {
    motor(MOT_LEFT, 70);
    motor(MOT_RIGHT, 70);
    clear_motor_position_counter(MOT_LEFT);
    clear_motor_position_counter(MOT_RIGHT);
    while((analog10(3)<300)||(get_motor_position_counter(MOT_RIGHT)<16500)) {
        if(analog10(TOPHAT_RIGHT) > THRESHOLD) {
            motor(MOT_RIGHT, -50);
            motor(MOT_LEFT, 90);
        } else {
            motor(MOT_LEFT, 70);
            motor(MOT_RIGHT, 190);
        }
        printf("Going straight:   %d, %d\n", analog10(TOPHAT_RIGHT),analog10(3)) ;
        msleep(50);
    }
    printf("Final: %d\n", analog10(3)) ;
}

void line_follow_L() {
    motor(MOT_LEFT, 70);
    motor(MOT_RIGHT, 70);
    clear_motor_position_counter(MOT_LEFT);
    clear_motor_position_counter(MOT_RIGHT);

    while((get_motor_position_counter(MOT_RIGHT)<20500)) {
        if(analog10(TOPHAT_RIGHT) < THRESHOLD) {
            motor(MOT_RIGHT, 90);
            motor(MOT_LEFT, -50);
        } else {
            motor(MOT_LEFT, 200);
            motor(MOT_RIGHT, 50);
        }
        printf("Going straight:   %d, %d\n", analog10(TOPHAT_RIGHT),analog10(3)) ;
        msleep(50);
    }
    printf("Final: %d\n", analog10(3)) ;

}

void lift_up() {
    enable_servo(0);
    set_servo_position(0,1500);
    msleep(1000);
    disable_servo(0);
}

void put_down() {
    enable_servo(0);
    set_servo_position(0,600);
    msleep(2000);
    disable_servo(0);
}

void shake() {
    enable_servo(0);
    set_servo_position(0,640);
    msleep(500);
    set_servo_position(0,600);
    msleep(500);
    set_servo_position(0,640);
    msleep(500);
    set_servo_position(0,600);
    msleep(500);
    disable_servo(0);
}

void close_to_right_side() {
    motor(MOT_LEFT, 83);
    motor(MOT_RIGHT, 65);
    clear_motor_position_counter(MOT_LEFT);
    clear_motor_position_counter(MOT_RIGHT);

    while((get_motor_position_counter(MOT_RIGHT)<10500)) {
        msleep(50);
    }
}

void close_to_left_side() {
    motor(MOT_LEFT, 70);
    motor(MOT_RIGHT, 83);
    clear_motor_position_counter(MOT_LEFT);
    clear_motor_position_counter(MOT_RIGHT);

    while((get_motor_position_counter(MOT_RIGHT)<2300)) {
        msleep(50);
    }
}

void close_to_left_side_2() {
    motor(MOT_LEFT, 70);
    motor(MOT_RIGHT, 90);
    clear_motor_position_counter(MOT_LEFT);
    clear_motor_position_counter(MOT_RIGHT);


    while((get_motor_position_counter(MOT_RIGHT)<7500)) {
        msleep(50);
    }
}

void go_forward(int distance) { // centimeters

    motor(MOT_LEFT, 83);
    motor(MOT_RIGHT, 88);
    clear_motor_position_counter(MOT_LEFT);
    clear_motor_position_counter(MOT_RIGHT);

    while(get_motor_position_counter(MOT_RIGHT) < (CONVERSION * distance)) {
        msleep(50);
    }
}

void slightly_left(int distance) { // centimeters
    motor(MOT_LEFT, 80);
    motor(MOT_RIGHT, 88);
    clear_motor_position_counter(MOT_LEFT);
    clear_motor_position_counter(MOT_RIGHT);

    while(get_motor_position_counter(MOT_RIGHT) < (CONVERSION * distance)) {
        msleep(50);
    }
}

void turn_right_before(){
    forward(10);
    ao();
    msleep(500);
    right(130,6);
    ao();

    close_to_right_side();

    ao();
    msleep(500);
    left(45,0);
    ao();
    msleep(500);

    forward(30);

    right(28,3);
    forward(100);

    left(60,3);
    backward(45);
}

int main()
{
    left(125,5);

    go_forward(15);
    ao();
    msleep(500);
    line_follow_R();

    ao();
    msleep(500);

    //first part

    go_forward(12);
    right(110,10);
    backward(34);

    //second part
    go_forward(40);

    ao();
    msleep(1000);

    forward(172);
    ao();
    msleep(1000);

    enable_servo(0);
    put_down();


    ao();
    msleep(1000);

    lift_up();
    disable_servo(0);

    //third part

    slightly_left(110);
    left(99,10);
    go_forward(40);
    line_follow_L();

    //fourth part

    go_forward(30);
    left(125,10);
    go_forward(50);
    left(125,10);
    enable_servo(0);
    slow_servo(0,300,2000);
    forward(300);
    disable_servo(0);

    return 0;
}
