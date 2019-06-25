#include "iorepo.h"

IORepo repo;

void setup() {
  
  IO a;
  a.setup("lamp0", 3, IO::BOOL, IO::OUT);
  IO b;
  b.setup("lamp1", 4, IO::BOOL, IO::OUT);

  repo.setup(2);
  repo.put(0, a);
  repo.put(1, b);

  Serial.begin(9600);
}

void loop() {
  Serial.println(repo.get("lamp1").getPin());
  delay(1000);

}