#include <msp430.h>
#include "led.h"
#include "switches.h"

unsigned char green_led_state = 0;
unsigned char red_led_state = 0;

void led_init(){
  P1DIR |= LEDS;  // bits attached to leds are outputs
  switch_state_changed = 1;
  led_update();
}

void led_update() {
  if(green_led_state) {
    P1OUT |= LED_GREEN;
  } else {
    P1OUT &= ~LED_GREEN;
  }
  if(red_led_state) {
    P1OUT |= LED_RED;
  } else {
    P1OUT &= ~LED_RED;
  }
}

