/* 
 *  Ex_14 - Physical Computing
 *  Revisit Input & Output
 *  
 *  LED 
 *  -- GP12
 *  Switch
 *  -- GP7
 *  
 */

#define ONBOARD_LED 12    // LED GP12
#define ONBOARD_SW  7    // Switch GP7

int current_LED = LOW;
int stage = 0;

void setup() {
  Serial.begin(115200);
  pinMode(ONBOARD_LED, OUTPUT);
  pinMode(ONBOARD_SW, INPUT_PULLUP); 
  digitalWrite(ONBOARD_LED, current_LED);   
}

void loop() {

  current_LED = (current_LED == HIGH || stage == 3) ? LOW: HIGH;
  digitalWrite(ONBOARD_LED, current_LED);
  
  if (digitalRead(ONBOARD_SW) == LOW) { 
    switch(stage) {
      case 0:
       Serial.print(stage);
       delay(1000);
       stage = 1;
       Serial.println(stage);
       break;
      case 1:
       Serial.print(stage);
       delay(500);
       stage = 2;
       Serial.println(stage);
       break;
      case 2: 
       Serial.print(stage);
       delay(100);
       stage = 3;
       Serial.println(stage);
       break;
      case 3:
       Serial.print(stage);
       current_LED = HIGH;
       stage = 0;
       Serial.println(stage);
       break;
    }
  }
  else {
     delay(500);
  }
}