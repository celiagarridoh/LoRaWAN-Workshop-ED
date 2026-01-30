## Workshop de introducción al diseño de end devices LoRaWAN 
**Introducción al diseño de end devices LoRaWAN** (enmarcado en el proyecto **📌 UniLAB 4.0: Smart Energy para Escuelas del Futuro** - IES Universidad Laboral de Albacete en colaboración con Universidad de Castilla-La Mancha)

---

## 🧠 Descripción del workshop
Este workshop introduce el **diseño y desarrollo de un end device LoRaWAN Clase A**, empleando una **MCU Heltec LoRa 32 v3.2 (ESP32-S3)**.  

El desarrollo se realiza utilizando **VS Code y PlatformIO**, con el **framework Arduino**, integrando la **pila LoRaWAN de RadioLib**, distintos **periféricos I2C/SPI** y **sensores digitales**.  

A lo largo del taller se construyen aplicaciones progresivas que permiten al alumnado adquirir competencias prácticas en:
- Programación de microcontroladores
- Comunicación serie e I2C
- Gestión de displays OLED
- Integración de sensores
- Conectividad LoRaWAN en la banda **EU868** mediante **OTAA**

---

## 🧩 Bloques de contenido / Proyectos

### 🔹 Proyecto 1: Aplicación básica de monitorización por puerto serie
Desarrollo de una primera aplicación para la **monitorización de un contador incremental**, mostrando su valor por el **puerto serie** y proporcionando **notificación visual mediante el LED** integrado.

### 🔹 Proyecto 2: Inicialización del bus I2C y detección de dispositivos
Creación de una aplicación para **inicializar el bus de comunicación I2C** y **escaneo de dispositivos esclavos**, con especial atención a la detección del **display OLED SSD1306**.
### 🔹 Proyecto 3: Visualización en display OLED mediante I2C
Gestión del **display OLED SSD1306** a través del protocolo I2C para mostrar:
- El valor incremental de un contador  
- Una **barra de progreso** asociada al mismo  
### 🔹 Proyecto 4: Representación de variables ambientales simuladas
Extensión del proyecto anterior para la **visualización de valores ficticios de temperatura y humedad**, utilizando el display OLED y la librería `HT_SSD1306Wire.h`.
### 🔹 Proyecto 5: Monitorización ambiental y alarmas
Integración de un **sensor digital real de temperatura y humedad** junto con un **buzzer pasivo**, permitiendo:
- Monitorización ambiental
- Generación de **alarmas acústicas** por umbral de temperatura

### 🔹 Proyecto 6: Integración con red LoRaWAN
Integración final del sistema de monitorización con la **red LoRaWAN**, mediante un **end device Clase A**, utilizando:
- Activación **OTAA**
- Banda de frecuencia **EU868**
- Se habilita el envío de datos ambientales hacia la red LoRaWAN.

---

## 📁 Estructura del repositorio

```
README.md
LICENSE-CODE.txt
LICENSE-MATERIAL.txt
├── Proyectos
│   ├── Proyecto1_Monitorizacion_Serie_LED
│   │   ├── main.cpp
│   │   └── platformio.ini
│   ├── Proyecto2_Escaner_I2C_OLED
│   │   ├── main.cpp
│   │   └── platformio.ini
│   ├── Proyecto3_Display_OLED_Contador
│   │   ├── main.cpp
│   │   └── platformio.ini
│   ├── Proyecto4_Display_Temp_Humedad_Simulada
│   │   ├── main.cpp
│   │   └── platformio.ini
│   ├── Proyecto5_Monitorizacion_Alarmas
│   │   ├── main.cpp
│   │   └── platformio.ini
│   └── Proyecto6_LoRaWAN_OTAA_EU868
│       ├── main.cpp
│       └── platformio.ini
├── Soluciones
│   ├── Proyecto1_Monitorizacion_Serie_LED
│   │   ├── main.cpp
│   │   └── platformio.ini
│   ├── Proyecto2_Escaner_I2C_OLED
│   │   ├── main.cpp
│   │   └── platformio.ini
│   ├── Proyecto3_Display_OLED_Contador
│   │   ├── main.cpp
│   │   └── platformio.ini
│   ├── Proyecto4_Display_Temp_Humedad_Simulada
│   │   ├── main.cpp
│   │   └── platformio.ini
│   ├── Proyecto5_Monitorizacion_Alarmas
│   │   ├── main.cpp
│   │   └── platformio.ini
│   └── Proyecto6_LoRaWAN_OTAA_EU868
│       ├── main.cpp
│       └── platformio.ini
```

---

## 👥 Autores
- Celia Garrido Hidalgo (Universidad de Castilla-La Mancha)  
- Luis Roda Sánchez (Universidad de Castilla-La Mancha)  

## 🏫 Afiliaciones
- Escuela Técnica Superior de Ingeniería Industrial de Albacete
- Departamento de Ingeniería Eléctrica, Electrónica, Automática y Comunicaciones  
- Universidad de Castilla-La Mancha  
- Grupo de Electrónica Aplicada, Procesado de Datos, IoT y Comunicaciones Avanzadas


---

## ⚖️ Licencia

- **Código fuente**: uso permitido únicamente con fines **educativos y no comerciales** (reconocimiento de autoría).  
- **Diapositivas y material docente**: licenciados bajo  
  **Creative Commons Atribución–NoComercial–CompartirIgual 4.0 Internacional (CC BY-NC-SA 4.0)**.

Para usos comerciales, contactar previamente con los autores.

---

## 📬 Contacto
Para dudas técnicas, reutilización del material o colaboraciones académicas, contactar con los autores del proyecto.


