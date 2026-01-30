
/***********************************************************
 * UniLab 4.0 - Taller LoRaWAN I (End Devices)             *
 * Fecha y lugar: 30/01/2026, IES Universidad Laboral      *
 * Autores: C. Garrido Hidalgo y L. Roda Sánchez           *
 * Basado en la librería y ejemplos:                       *
 * https://github.com/HelTecAutomation/Heltec_ESP32        *
 * Universidad de Castilla-La Mancha - ETSIIAB             *
 * Proyecto 3: Gestión OLED                                * 
***********************************************************/

#include <Arduino.h>
#include <Wire.h>
#include <????.h>

#define SCL_DISPLAY 18
#define SDA_DISPLAY 17
#define RST_DISPLAY 21
#define V_EXT_DISPLAY 36

RTC_DATA_ATTR SSD1306Wire display(
  ????, 
  500000, 
  ????,
  ????,
  GEOMETRY_128_64,
  ????
);

uint32_t contador = 0;

void setup() {
  Serial.begin(115200);
  delay(500);

  pinMode(V_EXT_DISPLAY, ????); // configuración E/S
  pinMode(RST_DISPLAY, ????); // gestión en librería

  Wire.begin(????, ????); // inicialización

  if (display.init())
    Serial.println("OLED inicializado");
  else
    Serial.println("Error");
}

void loop() {

  contador++;

  if (contador == 50) // limitamos contador a 50
    contador = 0;

  display.clear();

  ????.setFont(ArialMT_Plain_10);
  display.????(TEXT_ALIGN_CENTER);
  display.????(????, 0, "UniLab 4.0 - OLED OK"); //coordenadas 64,0 (centrado)

  display.????(ArialMT_Plain_16);
  display.????(????, ????, "Contador: " + String(contador)); // mayor tamaño de fuente

  display.????(0, 52, 128, 10); // x, y, anchura, altura
  display.????(1, 53, contador * ????/50, 8); // relleno de la barra (omitiendo primer y último pixel)

  ????.????();

  delay(500);
}









