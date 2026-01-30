
/***********************************************************
 * UniLab 4.0 - Taller LoRaWAN I (End Devices)             *
 * Fecha y lugar: 30/01/2026, IES Universidad Laboral      *
 * Autores: C. Garrido Hidalgo y L. Roda Sánchez           *
 * Basado en la librería y ejemplos:                       *
 * https://github.com/HelTecAutomation/Heltec_ESP32        *
 * Universidad de Castilla-La Mancha - ETSIIAB             *
 * Proyecto 4: Gestión OLED para humedad y temperatura     * 
***********************************************************/

#include <Arduino.h>
#include <Wire.h> // I2C
#include <HT_SSD1306Wire.h>

#define SCL_DISPLAY 18
#define SDA_DISPLAY 17
#define RST_DISPLAY 21
#define V_EXT_DISPLAY 36

#define LINEA_VERTICAL_1 ????
#define LINEA_VERTICAL_2 ????
#define LINEA_VERTICAL_3 ????
#define LINEA_VERTICAL_4 ????

#define LINEA_HORIZONTAL_1 ????
#define LINEA_HORIZONTAL_2 ????
#define LINEA_HORIZONTAL_3 ????
#define LINEA_HORIZONTAL_4 ????


RTC_DATA_ATTR SSD1306Wire display(
  0x3C, 
  500000, 
  SDA_DISPLAY,
  SCL_DISPLAY,
  GEOMETRY_128_64,
  RST_DISPLAY
);

float temperatura = 21.00;
float humedad = 54.23;


void setup() {
  Serial.begin(115200);
  delay(500);

  pinMode(V_EXT_DISPLAY, OUTPUT); // configuración E/S
  pinMode(RST_DISPLAY, OUTPUT); // gestión en librería

  Wire.begin(SDA_DISPLAY, SCL_DISPLAY); // inicialización

  if (display.init())
    Serial.println("OLED inicializado");
  else
    Serial.println("Error");
}

void loop() {

  display.clear();

  display.setFont(ArialMT_Plain_16);
  display.setTextAlignment(????);
  display.drawString(64, 0, "UniLab 4.0"); //coordenadas 64,0 (centrado)

  display.setFont(????); // reducimos el tamaño de fuente
  display.setTextAlignment(TEXT_ALIGN_LEFT);
  display.drawString(????, ????, "T = " + String(temperatura) + "ºC"); 
  display.drawString(????, ????, "0ºC"); 

  display.setTextAlignment(TEXT_ALIGN_RIGHT);
  display.drawString(????, ????, "50ºC"); 

  display.drawRect(????, ????, 50, 10); // x, y, anchura, altura
  display.fillRect(????+1, ????+1, temperatura, 8); // relleno de la barra (omitiendo primer y último pixel)


  display.setTextAlignment(TEXT_ALIGN_LEFT);
  display.drawString(????, ????, "H = " + String(humedad) + "%"); 
  display.drawString(????, ????, "0%"); 

  display.setTextAlignment(TEXT_ALIGN_RIGHT);
  display.drawString(????, ????, "100%"); 

  display.drawRect(????, ????, 50, 10); // x, y, anchura, altura
  display.fillRect(????+1, ????+1, humedad*50/????, 8); // relleno de la barra (omitiendo primer y último pixel)

  display.????();

  while(1);
}









