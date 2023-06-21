/* 
 *  Ex_11 - Conditional
 *  Simple communication through the Serial monitor.
 *  
 */
String rcvString = "";
int ghost = 0;

void setup() {
   Serial.begin(9600); //set up serial library baud rate to 115200
   delay(2000);
   Serial.println("What is your height and weight?");
}

void loop() {
   if(Serial.available() >= 2) { //if number of bytes (characters) available for reading
      float height = Serial.parseFloat();
      float weight = Serial.parseFloat();
      float bmi = weight / (height * height);
      Serial.print("Your BMI is ");
      Serial.println(bmi);

      Serial.print("You are ");
      if (bmi < 16) {
        Serial.println("severely underweight.");
      }
      else if (bmi >= 16.0 && bmi < 18.4) {
        Serial.println("underweight.");
      }
      else if (bmi >= 18.5 && bmi < 24.9) {
        Serial.println("normal.");
      }
      else if (bmi >= 25.0 && bmi < 29.9) {
        Serial.println("overweight.");
      }
      else if (bmi >= 30.0 && bmi < 34.9) {
        Serial.println("moderately obese.");
      }
      else if (bmi >= 35.0 && bmi < 39.9) {
        Serial.println("severely obese.");
      }
      else if (bmi >= 40) {
        Serial.println("morbidly obese.");
      }

      Serial.println("");
      Serial.println("How many ghost do you see?");
   }
}
                    
                
