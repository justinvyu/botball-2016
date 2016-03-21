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

    ARM_UP = 250,
    ARM_PARTIAL = 1000,
    ARM_DOWN = 2198,

    CLAW_OPEN = 1950,
    CLAW_PARTIAL = 1250,
    CLAW_CLOSED = 120,

    BACK_UP = 200,
    BACK_DOWN = 1450
};

enum Constants {
    SERVO_DURATION = 1
};

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
    void (*shake)();
    void (*track)();

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
