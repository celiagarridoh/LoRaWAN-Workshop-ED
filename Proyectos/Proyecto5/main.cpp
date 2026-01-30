
/***********************************************************
 * UniLab 4.0 - Taller LoRaWAN I (End Devices)             *
 * Fecha y lugar: 30/01/2026, IES Universidad Laboral      *
 * Autores: C. Garrido Hidalgo y L. Roda Sánchez           *
 * Basado en la librería y ejemplos:                       *
 * https://github.com/HelTecAutomation/Heltec_ESP32        *
 * https://github.com/adafruit/DHT-sensor-library          *
 * Universidad de Castilla-La Mancha - ETSIIAB             *
 * Proyecto 5: Humedad y temperatura (buzzer)              * 
***********************************************************/

#include <Arduino.h>
#include <Wire.h> // I2C
#include <HT_SSD1306Wire.h>
#include <???.h>

#define DHTPIN ????   // Pin DATA conectado al DHT11
#define DHTTYPE ????  // Tipo de sensor DHT11
#define BUZZER_PIN ????

#define SCL_DISPLAY 18
#define SDA_DISPLAY 17
#define RST_DISPLAY 21
#define V_EXT_DISPLAY 36

#define LINEA_VERTICAL_1 0
#define LINEA_VERTICAL_2 55
#define LINEA_VERTICAL_3 72
#define LINEA_VERTICAL_4 128

#define LINEA_HORIZONTAL_1 0
#define LINEA_HORIZONTAL_2 20
#define LINEA_HORIZONTAL_3 38
#define LINEA_HORIZONTAL_4 50

// Frecuencias (Hz)
#define NOTA_GRAVE ????
#define NOTA_AGUDA ????

RTC_DATA_ATTR SSD1306Wire display(
  0x3C, 
  500000, 
  SDA_DISPLAY,
  SCL_DISPLAY,
  GEOMETRY_128_64,
  RST_DISPLAY
);

DHT dht(????, ????);

float temperatura = 0;
float humedad = 0;

void setup() {
  Serial.begin(115200);
  delay(500);
  dht.begin();

  Serial.println("DHT11 inicializado");

  pinMode(V_EXT_DISPLAY, OUTPUT); // configuración E/S
  pinMode(RST_DISPLAY, OUTPUT); // gestión en librería
  pinMode(BUZZER_PIN, OUTPUT);

  Wire.begin(SDA_DISPLAY, SCL_DISPLAY); // inicialización

  if (display.init())
    Serial.println("OLED inicializado");
  else
    Serial.println("Error");
}

void loop() {

  display.clear();

  temperatura = ????.????();
  humedad = ????.????();

  display.setFont(ArialMT_Plain_16);
  display.setTextAlignment(TEXT_ALIGN_CENTER);
  display.drawString(64, 0, "UniLab 4.0"); //coordenadas 64,0 (centrado)

  display.setFont(ArialMT_Plain_10);
  display.setTextAlignment(TEXT_ALIGN_LEFT);
  display.drawString(LINEA_VERTICAL_1, LINEA_HORIZONTAL_2, "T = " + String(temperatura) + "ºC"); 
  display.drawString(LINEA_VERTICAL_1, LINEA_HORIZONTAL_3, "0ºC"); 

  display.setTextAlignment(TEXT_ALIGN_RIGHT);
  display.drawString(LINEA_VERTICAL_2, LINEA_HORIZONTAL_3, "50ºC"); 

  display.drawRect(LINEA_VERTICAL_1, LINEA_HORIZONTAL_4, 50, 10); // x, y, anchura, altura
  display.fillRect(LINEA_VERTICAL_1+1, LINEA_HORIZONTAL_4+1, temperatura, 8); // relleno de la barra (omitiendo primer y último pixel)


  display.setTextAlignment(TEXT_ALIGN_LEFT);
  display.drawString(LINEA_VERTICAL_3, LINEA_HORIZONTAL_2, "H = " + String(humedad) + "%"); 
  display.drawString(LINEA_VERTICAL_3, LINEA_HORIZONTAL_3, "0%"); 

  display.setTextAlignment(TEXT_ALIGN_RIGHT);
  display.drawString(LINEA_VERTICAL_4, LINEA_HORIZONTAL_3, "100%"); 

  display.drawRect(LINEA_VERTICAL_3, LINEA_HORIZONTAL_4, 50, 10); // x, y, anchura, altura
  display.????(LINEA_VERTICAL_3+1, LINEA_HORIZONTAL_4+1, humedad*50/100, 8); // relleno de la barra (omitiendo primer y último pixel)

  display.display();

  if(temperatura >= 25){
    for (int i = 0; i < 5; i++) {
      tone(????, ????);
      delay(????);
      noTone(????);
      delay(????);

      tone(????, ????);
      delay(????);
      noTone(????);
      delay(????);
    }
  }

 delay(2);
}









