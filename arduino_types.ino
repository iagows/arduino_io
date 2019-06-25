#include "io.h"

#define PIN_OBJ_0 13

IO io;

void setup() {
  io.setup(1, PIN_OBJ_0, IO::BOOL, IO::OUT, "led");

  io.set(LOW);
}

void loop() {
  io.set(io.get() == LOW ? HIGH : LOW);
  //Serial.println(io.get());
  delay(500);
}
