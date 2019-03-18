#include <VirtualWire.h>

int pinBtn = 8;
int val = 0;
bool isSent = false;

const int transmit_pin = 12;
byte count = 1;

const int receive_pin = 11;

void setup() {
  delay(1000);
  Serial.begin(9600);
  pinMode(pinBtn, INPUT);
  Serial.println("Setup");

  vw_set_rx_pin(receive_pin);
  vw_setup(2000);
  vw_rx_start();
}

void loop() {
  uint8_t buf[VW_MAX_MESSAGE_LEN];
  uint8_t buflen = VW_MAX_MESSAGE_LEN;

  if (vw_get_message(buf, &buflen)) // Non-blocking
  {
    int i;
    Serial.print("Got: ");
    for (i = 0; i < buflen; i++)
    {
      Serial.print(buf[i], HEX);
      Serial.print(' ');
    }
    Serial.println();
  }
  
  val = digitalRead(pinBtn);
  if (val == HIGH && isSent == false) {
    isSent = true;
    Serial.println("Sending...");
  }
}

void sendMsg() {
  char msg[7] = {'h','e','l','l','o',' ','#'};  
  msg[6] = count;
  vw_send((uint8_t *)msg, 7);
  vw_wait_tx();
  count = count + 1;
}
