#include <msp430.h>
#include "stateMachines.h"


/* This interrupt occurs 250 times/ second.
 * I want a song update every quarter second.
 * However, 250 / 4 = 62.5
 * I decided to work around this by having state updates per cycle.
 * The first one is at 62 interrupts, which is 1/2 an interrupt too soon.
 * The second is 63 interrupts later at 125, which is 1/2 an interrupt too late.
 * This allows me to stay alligned with half second intervals and get "close enough"
 * to my original plan of 4 interrupts per second.
 */
void
__interrupt_vec(WDT_VECTOR) WDT(){	/* 250 interrupts/sec */
  static unsigned char blink_count = 0;
  if (++blink_count == 63) { //blink_count gets incremented here
    state_advance();
  }
  if (blink_count == 125) {
    state_advance();
    blink_count = 0;  //blink_count = gets reset here.
  }
}
