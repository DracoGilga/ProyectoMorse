#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include "CredencialesWifi.h"


const int ledPin = 2; // Pin del LED

ESP8266WebServer server(80);
String receivedData = ""; // Variable para almacenar los datos recibidos
bool isBlinking = false; // Variable para controlar el parpadeo del LED
void handleData() {
  receivedData = server.arg("data");
  server.send(200, "text/plain", "Datos recibidos: " + receivedData);

  // Parpadeo en código Morse
  String morseCode = encodeMorseCode(receivedData);
  blinkMorseCode(morseCode);

}

String encodeMorseCode(String message) {
  const String morseTable[26] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."
  };

  String encodedMessage = "";
  message.toUpperCase();

  // Convertir cada carácter del mensaje en su equivalente en código Morse
  for (int i = 0; i < message.length(); i++) {
    char currentChar = message.charAt(i);
    if (isAlpha(currentChar)) {
      int index = currentChar - 'A';
      encodedMessage += morseTable[index];
      encodedMessage += " "; // Separador entre caracteres en código Morse
    }
  }

  return encodedMessage;
}

void blinkMorseCode(String morseCode) {
  const int dotDuration = 150; // Duración de un punto en ms

  for (int i = 0; i < morseCode.length(); i++) {
    char currentSymbol = morseCode.charAt(i);

    if (currentSymbol == '.') {
      digitalWrite(ledPin, HIGH);
      delay(dotDuration);
      digitalWrite(ledPin, LOW);
      delay(dotDuration);
    }
    else if (currentSymbol == '-') {
      digitalWrite(ledPin, HIGH);
      delay(dotDuration * 3);
      digitalWrite(ledPin, LOW);
      delay(dotDuration);
    }
    else if (currentSymbol == ' ') {
      delay(dotDuration * 2); // Espacio entre caracteres en código Morse
    }
  }
}

void setup() {
  pinMode(ledPin, OUTPUT); 
  digitalWrite(ledPin, LOW); 

  Serial.begin(115200);
  delay(1000);
  
  Serial.println();
  Serial.print("Conectando a ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    digitalWrite(ledPin, HIGH); 
    delay(250);
    digitalWrite(ledPin, LOW);
    delay(250);
    Serial.print(".");
  }

  digitalWrite(ledPin, LOW); 
  Serial.println("");
  Serial.println("Conexión WiFi establecida");
  Serial.print("Dirección IP: ");
  Serial.println(WiFi.localIP());

  server.on("/data", handleData);
  server.begin();
  Serial.println("Servidor web iniciado");
}

void loop() {
  server.handleClient();

  // Imprimir los datos recibidos en Serial.print si no está parpadeando
  if (!isBlinking && !receivedData.isEmpty()) {
    Serial.println("Datos recibidos: " + receivedData);
    receivedData = ""; // Limpiar los datos recibidos después de mostrarlos
  }

}

