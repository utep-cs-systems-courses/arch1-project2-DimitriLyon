#include <msp430.h>
#include "song.h"
#include "stateMachines.h"
#include "buzzer.h"
#include "led.h"

void reset() {
  buzzer_set_period(0);
  red_led_state = 0;
  green_led_state = 1;
  switch_state_num = 0;
  quarter_second_count = 0;
  songState = 0;
}

extern int songState;
void playSong1() {
  switch(songState++) {
  case 0:
  case 2:
    buzzer_set_period(4545);
    red_led_state = 1;
    green_led_state = 0;
    break;
  case 1:
  case 3:
    buzzer_set_period(2272);
    red_led_state = 0;
    green_led_state = 1;
    break;
  default:
    reset();
  }
}
//d4 e4 f#4 a4 r r
//d4 e4 f#4 b4 r r
//d4 e4 f#4 c#5 r r
//stop
//d4 6811
//e4 6067
//f#4- 5,406
//a4 - 4,545
//b4 - 4,050
//c#5- 3,608
void playSong2() {
  switch(songState++) {
  case 0:
  case 6:
  case 12:
    green_led_state = 1;
    red_led_state = 0;
    buzzer_set_period(6811);
    break;
  case 1:
  case 7:
  case 13:
    green_led_state = 0;
    red_led_state = 1;
    buzzer_set_period(6067);
    break;
  case 2:
  case 8:
  case 14:
    red_led_state = 0;
    buzzer_set_period(5406);
    break;
  case 3:
    buzzer_set_period(4545);
    red_led_state = 1;
    green_led_state = 1;
    break;
  case 9:
    buzzer_set_period(4050);
    red_led_state = 1;
    green_led_state = 1;
    break;
  case 15:
    buzzer_set_period(3608);
    red_led_state = 1;
    green_led_state = 1;
    break;
  case 4:
  case 5:
  case 10:
  case 11:
  case 16:
  case 17:
    red_led_state = !red_led_state;
    green_led_state = !green_led_state;
    break;
  default:
    reset();
  }
}
/*
C#5 3608
G4  5102
f#4 5406
a3  9091
f#3 12195
e3  12135
 */
void playSong3() {
  switch(songState++) {
  case 0:
    buzzer_set_period(3608);//g1r1
    green_led_state = 1;
    red_led_state = 1;
    break;
  case 1:
    buzzer_set_period(5102);//g0r0
    green_led_state = 0;
    red_led_state = 0;
    break;
  case 2:
    buzzer_set_period(5406);//g1r0
    green_led_state = 1;
    break;
  case 3:
    buzzer_set_period(8099);//g0r1
    green_led_state = 0;
    red_led_state = 1;
    break;
  case 4:
    buzzer_set_period(9091);//g0r0
    red_led_state = 0;
    break;
  case 5:
  case 6:
    buzzer_set_period(12135);//g1r1
    green_led_state = 1;
    red_led_state = 1;
    break;
  default:
    reset();
  }
}

/* 
   b4 4050
   d5 3405
   g5 2551
   a5 2273
   d6 1912
   b5 2025
   g5 2551
   
   b d r g
   r r a r
   r c r b
   r r g r 
 */

void playSong4() {
  switch(songState++) {
  case 0:
    buzzer_set_period(4050);
    break;
  case 1:
    buzzer_set_period(3405);
    break;
  case 3:
    buzzer_set_period(2551);
    break;
  case 6:
    buzzer_set_period(2273);
    break;
  case 9:
    buzzer_set_period(1975);
    break;
  case 11:
    buzzer_set_period(2025);
    break;
  case 14:
    buzzer_set_period(2551);
    break;
  case 2:
  case 4:
  case 5:
  case 7:
  case 8:
  case 10:
  case 12:
  case 13:
  case 15:
    break;
  default:
    reset();
  }
}
