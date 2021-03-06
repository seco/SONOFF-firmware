/*
 Sonoff: firmware
 More info: https://github.com/tschaban/SONOFF-firmware
 LICENCE: http://opensource.org/licenses/MIT
 2016-10-27 tschaban https://github.com/tschaban
*/

/* Set relay to ON */
void relayOn() {
  digitalWrite(RELAY, HIGH);
  publishRelayStateMessage();
  Serial << "Relay set to ON" << endl;
  memory.saveRelayState(1);
  blinkLED();
}

/* Set relay to OFF */
void relayOff() {
  digitalWrite(RELAY, LOW);
  publishRelayStateMessage();
  Serial << "Relay set to OFF" << endl;
  memory.saveRelayState(0);
  blinkLED();
}

/* Toggle relay */
void relayToggle() {
  if (digitalRead(RELAY) == LOW) {
    relayOn();
  } else {
    relayOff();
  }
}
