#include "io.h"

#define PIN_NUMBER 13

IO io;
void setup() {
  io.setup(1, PIN_NUMBER, IO::BOOL, IO::OUT, "sensor/actuator's name");
}

void loop() {
  io.set(io.get() == LOW ? HIGH : LOW);
  delay(500);
}
