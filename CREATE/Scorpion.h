//
//  Scorpion.h
//  Source written by Justin Yu
//

#include <kipr/botball.h>
#include "Create.h"
#include "Controller.h"
#include "Camera.h"

enum ServoPositions {
    ARM_SERVO = 0,
    CLAW_SERVO = 1,
    BACK_SERVO = 2,

    ARM_UP = 100,
    ARM_PARTIAL = 1000,
    ARM_DOWN = 2000,

    CLAW_OPEN = 1850,
    CLAW_PARTIAL = 1000,
    CLAW_CLOSED = 0,

    BACK_UP = 600,
    BACK_DOWN = 2047
};

#define SERVO_DURATION 1.2

enum Channel {
    RED_CHANNEL = 0,
    GREEN_CHANNEL = 1
};

typedef struct Scorpion {
    // Inheriting from Create
    Create create;
    Controller controller;
    Camera camera;

    // Custom properties/instance methods
    void (*grab_tribbles)();
    void (*grab_tribbles_slow)();
    void (*grab_tribbles_async)();
    void (*shake_arm)();
    enum Channel (*track)();
    enum Channel (*get_tribble_color)();

    void (*determine_action)(int *red, int *green);
    void (*isolate_tribbles)();

    void (*init)();
    void (*deinit)();

    void (*lower_arm)();
    void (*raise_arm)();
    void (*set_arm_to_position)(int position);

    void (*close_claw)();
    void (*close_claw_slow)(float time);
    void (*open_claw)();
    void (*set_claw_to_position)(int position);

    void (*lift_basket)();
    void (*drop_basket)();
    void (*lift_basket_slow)();
    void (*drop_basket_slow)();
} Scorpion;

extern Scorpion new_scorpion(); // constructor

// Global scorpion object
Scorpion scorpion;
