void setup() {
  Serial.begin(115200);
  while (!Serial) {}

  String message;
  int key;
  char edoc;

  Serial.println("Enter message to encrypt: ");
  while (Serial.available() == 0) {}
  message = Serial.readString();

  Serial.println("Enter key for encryption: ");
  while (Serial.available() == 0) {}
  key = Serial.parseInt();

  Serial.println("Encode or Decode? (E|D) ");
  while (Serial.available() == 0) {}
  edoc = Serial.read();

  Serial.print("Original message: ");
  Serial.println(message);  

  if (edoc == 'E') {
    // Encrypt the message
    for (int i = 0; i < message.length(); i++) {
      if (isLetter(message[i])) {
        message[i] = (message[i] - 'A' + key) % 26 + 'A';
      }
    }

    Serial.print("Encrypted message: ");
    Serial.println(message);
  }
  // Decrypt the message
  else if (edoc == 'D') {
    for (int i = 0; i < message.length(); i++) {
      if (isLetter(message[i])) {
        message[i] = (message[i] - 'A' - key + 26) % 26 + 'A';
      }
    }

    Serial.print("Decrypted message: ");
    Serial.println(message);
  }
  Serial.print("Original message: ");
  Serial.println(message);  
}

void loop() {
  // Do nothing
}

bool isLetter(char c) {
  return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
}