/*#include "DIO.h"

#include "bitMath.h"
#include "register.h"

// Function implementations for DIO operations
void pinMode(uint8_t port_pin, uint8_t state) {
  // Extract port and pin from combined macro
  uint8_t port = (port_pin >> 4) & 0x0F;
  uint8_t pin = port_pin & 0x0F;

  // Set the corresponding bit in DDR register based on state
  if (state == OUTPUT) {
    setBit(*(&DDRX + port), pin);
  } else {
    clearBit(*(&DDRX + port), pin);
  }
}

void digitalWrite(uint8_t port_pin, uint8_t state) {
  // Extract port and pin from combined macro
  uint8_t port = (port_pin >> 4) & 0x0F;
  uint8_t pin = port_pin & 0x0F;

  // Set or clear the corresponding bit in PORT register based on state
  if (state == HIGH) {
    setBit(*(&PORTX + port), pin);
  } else {
    clearBit(*(&PORTX + port), pin);
  }
}

uint8_t digitalRead(uint8_t port_pin) {
  // Extract port and pin from combined macro
  uint8_t port = (port_pin >> 4) & 0x0F;
  uint8_t pin = port_pin & 0x0F;

  // Read the corresponding bit from PIN register
  return getBit(*(&PINX + port), pin);
}

void digitalToggle(uint8_t port_pin) {
  // Extract port and pin from combined macro
  uint8_t port = (port_pin >> 4) & 0x0F;
  uint8_t pin = port_pin & 0x0F;

  // Toggle the corresponding bit in PORT register
  toggleBit(*(&PORTX + port), pin);
}

// Replace X in DDRX, PINX, and PORTX with actual port letter (A, B, C, D) based on your AVR microcontroller
*/


#include "DIO.h"
#include "register.h"
#include "bitMath.h"

void pinMode(uint8_t port_pin, uint8_t state) {
    uint8_t port = port_pin / 10;
    uint8_t pin = port_pin % 10;

    if (state == 1)
        SET_BIT(DDR_REG(port), pin);
    else
        CLEAR_BIT(DDR_REG(port), pin);
}

void digitalWrite(uint8_t port_pin, uint8_t state) {
    uint8_t port = port_pin / 10;
    uint8_t pin = port_pin % 10;

    if (state == 1)
        SET_BIT(PORT_REG(port), pin);
    else
        CLEAR_BIT(PORT_REG(port), pin);
}

uint8_t digitalRead(uint8_t port_pin) {
    uint8_t port = port_pin / 10;
    uint8_t pin = port_pin % 10;

    return GET_BIT(PIN_REG(port), pin);
}

void digitalToggle(uint8_t port_pin) {
    uint8_t port = port_pin / 10;
    uint8_t pin = port_pin % 10;

    TOGGLE_BIT(PORT_REG(port), pin);
}










