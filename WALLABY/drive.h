//
//  drive.h
//  Source written by Justin Yu
//

#include <kipr/botball.h>

#ifndef _DRIVE_H_
#define _DRIVE_H_

//primary driving code

#define MOT_LEFT 2
#define MOT_RIGHT 1

#define PI 3.14159265358979

#define SPD 100 //turning
#define SPDl 100. //left forward
#define SPDr 100. //right forward
#define rdistmult 1.0
#define SPDlb 8.  //left backward
#define SPDrb 8.  //right backward
#define rdistmultb (SPDrb/SPDlb)
#define wheeldiameter 5.0
#define ks 14.5 // Distance from one wheel to the other

#define CONVERSION (1100. / (PI * wheeldiameter))

long CMtoBEMF(float cm);
float BEMFtoCM(long ticks);

void drive_off();
void clear_all_drive();
void drive(int mL,int mR);
void slow_servo(int port, int position, float time);

void right(float degrees, float radius);
void left(float degrees, float radius);
void forward(float distance);
void multforward(float distance, float speedmult);
void backward(float distance);

#endif
