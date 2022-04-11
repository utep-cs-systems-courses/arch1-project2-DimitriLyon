#include <msp430.h>
#include "song.h"
#include "stateMachines.h"
#include "buzzer.h"
#include "led.h"



void playSong1() {
  switch(songState++) {
  case 0:
  case 2:
    buzzer_set_period(4545);
    break;
  case 1:
  case 3:
    buzzer_set_period(2272);
    break;
  default:
    buzzer_set_period(0);
    red_led_state = 0;
    switch_state_num = 0;
    quarter_second_count = 0;
    songState = 0;
  }
}


void playSong2() {

}

void playSong3() {

}

void playSong4() {

}
