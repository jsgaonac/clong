#ifndef _CLONG_DEFS_H_
#define _CLONG_DEFS_H_

//A header file with all the constants used through the game.

//Determines if DEBUG information is displayed.
#define DEBUG 

#define SCREEN_W 800
#define SCREEN_H 600

#define PADDLE_W 20
#define PADDLE_H 150

#define PADDLE_MOV 600	//Movement per second of the paddles

#define PADDING	5		//Distance between end of screen and the paddles.

#define BALL_RAD 10
#define BALL_MOV 20
#define BALL_MOV_INC 5

#define ERR_NONE -1
#define ERR_CANT_INIT_WIND0W 0
#define ERR_CANT_LOAD_RES 1

#endif //_CLONG_DEFS_H_