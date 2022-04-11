#include <msp430.h>
#include "stateMachines.h"
#include "led.h"
#include "buzzer.h"
#include "song.h"
//Gets called every quarter second
void state_advance() {
  if (switch_state_num) {
    run_state();
    quarter_second_count++;
  } else {
    quarter_second_count = 0;
  }
  led_update();
}
void run1() {
  playSong1();
}
void run2(){
  playSong2();
}
void run3(){
  playSong3();
}
void run4() {
  playSong4();
}

void run_state() {
  switch(switch_state_num) {
  case 1:
    run1();
    break;
  case 2:
    run2();
    break;
  case 3:
    run3();
    break;
  case 4:
    run4();
    break;
  }
}
