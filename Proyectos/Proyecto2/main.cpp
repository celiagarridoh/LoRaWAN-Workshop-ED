
/***********************************************************
 * UniLab 4.0 - Taller LoRaWAN I (End Devices)             *
 * Fecha y lugar: 30/01/2026, IES Universidad Laboral      *
 * Autores: C. Garrido Hidalgo y L. Roda Sánchez           *
 * Basado en la librería y ejemplos:                       *
 * https://github.com/HelTecAutomation/Heltec_ESP32        *
 * Universidad de Castilla-La Mancha - ETSIIAB             *
 * Proyecto 2: Conexión I2C con OLED (ALU)                 * 
***********************************************************/

#include <Arduino.h>
#include <????.h>

#define SCL_DISPLAY ????
#define SDA_DISPLAY ????
#define RST_DISPLAY ????
#define V_EXT_DISPLAY ????

void setup() {
  Serial.begin(115200);
  delay(500);

  pinMode(V_EXT_DISPLAY, ????); // configruación E/S
  pinMode(RST_DISPLAY, ????);

  digitalWrite(V_EXT_DISPLAY, ????); // alimentación
  delay(1);
  digitalWrite(RST_DISPLAY, ????); // aplicamos reset
  delay(1);
  digitalWrite(RST_DISPLAY, ????); 
  delay(1); // esperamos a que arranque
  
  ????.begin(????, ????);
  ????.setClock(????); // frecuencia estándar
}

void loop() {
  uint8_t error, address, nDevices = 0;

  Serial.println("Buscando esclavos...\n");

  for(address = 1; address < ????; address++) {
    ????.beginTransmission(address);
    error = Wire.????();

    if(error == 0) {
      Serial.print("Dispositivo encontrado en 0x");
      Serial.println(address, HEX);
      nDevices++;
    }
  }

  if (nDevices == 0)
    Serial.println("\nNo se encontraron dispositivos\n");
  else
    Serial.println("\nEscaneo terminado\n");

  while(1);
}