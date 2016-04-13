//
//  Create.h
//  Source written by Justin Yu
//

#include <kipr/botball.h>

typedef struct Create {
    // movement
    void (*forward)(float dist, int speed);
    void (*backward)(float dist, int speed);
    void (*left)(int angle, float radius, int speed);
    void (*right)(int angle, float radius, int speed);

    void (*spin_clockwise)(int speed);
    void (*spin_counterclockwise)(int speed);
    void (*drive_direct)(int l_speed, int r_speed);
    void (*stop)();

    void (*forward_until_bump)(int speed);
    void (*forward_with_speed)(float dist, int left_speed, int right_speed);
    void (*backward_with_speed)(float dist, int left_speed, int right_speed);

    // sensors
    int (*get_distance)();
    void (*set_distance)(int dist);

    int (*get_total_angle)();
    void (*set_total_angle)(int angle);

    int (*get_lbump)();
    int (*get_rbump)();
    int (*get_lclightbump)(); // left-center bump
    int (*get_rclightbump)(); // right-center bump

    // OI
    void (*write_byte)(char byte);
    void (*write_int)(int decimal);

    void (*block)();
    void (*send)();
    void (*receive)();

    // misc
    int (*get_battery_charge)();
    void (*full)();
    int (*connect)();
    void (*disconnect)();
} Create;

extern Create new_create(); // constructor

Create create; // global create reference
