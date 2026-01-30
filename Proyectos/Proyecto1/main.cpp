
/******************************************************
 * UniLab 4.0 - Taller LoRaWAN I (End Devices)        *
 * Fecha y lugar: 30/01/2026, IES Universidad Laboral *
 * Autores: C. Garrido Hidalgo y L. Roda Sánchez      *
 * Universidad de Castilla-La Mancha - ETSIIAB        *
 * Proyecto 1: Hello World (ALU)                      * 
******************************************************/

#include <????.h>

#define LED_PIN ???? // macro para LED

// contador global

void setup() {
  Serial.begin(????); // puerto serie (115200 8-N-1)
  
  // configuramos el pin como salida

  Serial.println(????);
}

void loop() {
  Serial.println(????); // valor del contador

  digitalWrite(????, ????); // encendemos LED
  delay(1000);

  ???? // apagamos LED y esperamos
  ????
}