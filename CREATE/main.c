//
//  main.c
//  Source written by Justin Yu
//

#include <kipr/botball.h>

#include "create.h"

int main() {
    create_connect();

    create_left(90, 0, 200);

    create_disconnect();
    return 0;
}
