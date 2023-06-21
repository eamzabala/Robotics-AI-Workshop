/* 
 *  Ex_12 - Loops
 *  Meet the FlintStones
 *  
 */

void setup() {
   Serial.begin(115200); //set up serial library baud rate to 115200
   delay(2000);

}

void loop() { // <- Loop() is a forever while loop in disguise.
    int count = 0;
    int number = 2;

    while (count < 30) {
    bool isPrime = true;

    for (int i = 2; i <= number/2; i++) {
      if (number % i == 0) {
        isPrime = false;
        break;
      }
    }

    if (isPrime) {
      count++;
      Serial.print(count);
      Serial.print(" : ");
      Serial.println(number);
    }

    number++;
  }

  // Stop the loop after 30 primes have been found
  while (true) {
    // Do nothing
  }
}
                    
                