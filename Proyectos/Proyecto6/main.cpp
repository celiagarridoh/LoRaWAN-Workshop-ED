
/***********************************************************
 * UniLab 4.0 - Taller LoRaWAN I (End Devices)             *
 * Fecha y lugar: 30/01/2026, IES Universidad Laboral      *
 * Autores: C. Garrido Hidalgo y L. Roda Sánchez           *
 * Basado en la librería y ejemplos:                       *
 * https://github.com/HelTecAutomation/Heltec_ESP32        *
 * https://github.com/adafruit/DHT-sensor-library          *
 * Universidad de Castilla-La Mancha - ETSIIAB             *
 * Proyecto 6: Gestión OLED para humedad y temperatura     * 
***********************************************************/

#include <Arduino.h>
#include <Wire.h> // I2C
#include <HT_SSD1306Wire.h>
#include <DHT.h>
#include <????.h>

#define DHTPIN 4       // Pin DATA conectado al DHT11
#define DHTTYPE DHT11  // Tipo de sensor DHT11

#define LED_PIN 35

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

RTC_DATA_ATTR SSD1306Wire display_oled(
  0x3C, 
  500000, 
  SDA_DISPLAY,
  SCL_DISPLAY,
  GEOMETRY_128_64,
  RST_DISPLAY
);

DHT dht(DHTPIN, DHTTYPE);

float temperatura = 0;
float humedad = 0;

void mostrar_display(void);
void actualizar_variables(void);

// Variables LoRaWAN:
/* OTAA */
uint8_t devEui[] = { ????, ????, ????, ????, ????, ????, ????, ???? };
uint8_t appEui[] = { ????, ????, ????, ????, ????, ????, ????, ???? };
uint8_t appKey[] = { ????, ????, ????, ????, ????, ????, ????, ????, ????, ????, ????, ????, ????, ????, ????, ???? };

/* ABP */
uint8_t nwkSKey[] = { ????, ????, ????, ????, ????, ????, ????, ????, ????, ????, ????, ????, ????, ????, ????, ???? };
uint8_t appSKey[] = { ????, ????, ????, ????, ????, ????, ????, ????, ????, ????, ????, ????, ????, ????, ????, ???? };
uint32_t devAddr =  ( uint32_t )0x007e6ae1;

/*LoraWan channelsmask*/
uint16_t userChannelsMask[6]={ 0x00FF,0x0000,0x0000,0x0000,0x0000,0x0000 };

/*LoraWan region, select in arduino IDE tools*/
LoRaMacRegion_t loraWanRegion = ????;

/*LoraWan Class, Class A and Class C are supported*/
DeviceClass_t  loraWanClass = CLASS_A;

/*the application data transmission duty cycle.  value in [ms].*/
uint32_t appTxDutyCycle = ????;

/*OTAA or ABP*/
bool overTheAirActivation = ????;

/*ADR enable*/
bool loraWanAdr = ????;

/* Indicates if the node is sending confirmed or unconfirmed messages */
bool isTxConfirmed = ?????;

/* Application port */
uint8_t appPort = ????;
/*!
* Number of trials to transmit the frame, if the LoRaMAC layer did not
* receive an acknowledgment. The MAC performs a datarate adaptation,
* according to the LoRaWAN Specification V1.0.2, chapter 18.4, according
* to the following table:
*
* Transmission nb | Data Rate
* ----------------|-----------
* 1 (first)       | DR
* 2               | DR
* 3               | max(DR-1,0)
* 4               | max(DR-1,0)
* 5               | max(DR-2,0)
* 6               | max(DR-2,0)
* 7               | max(DR-3,0)
* 8               | max(DR-3,0)
*
* Note, that if NbTrials is set to 1 or 2, the MAC will not decrease
* the datarate, in case the LoRaMAC layer did not receive an acknowledgment
*/
uint8_t confirmedNbTrials = ????;

/* Prepares the payload of the frame */
static void prepareTxFrame( uint8_t port )
{
	/*appData size is LORAWAN_APP_DATA_MAX_SIZE which is defined in "commissioning.h".
	*appDataSize max value is LORAWAN_APP_DATA_MAX_SIZE.
	*if enabled AT, don't modify LORAWAN_APP_DATA_MAX_SIZE, it may cause system hanging or failure.
	*if disabled AT, LORAWAN_APP_DATA_MAX_SIZE can be modified, the max value is reference to lorawan region and SF.
	*for example, if use REGION_CN470, 
	*the max value for different DR can be found in MaxPayloadOfDatarateCN470 refer to DataratesCN470 and BandwidthsCN470 in "RegionCN470.h".
	*/
  appDataSize = 5;
  appData[0] = 0x00;
  appData[1] = 0x01;
  appData[2] = 0x02;
  appData[3] = 0x03;
  appData[4] = 0x04;

}
// Variables LoRaWAN.


void setup() {
  Serial.begin(115200);

  delay(500);
  dht.begin();

  Serial.println("DHT11 inicializado");

  pinMode(V_EXT_DISPLAY, OUTPUT); // configuración E/S
  pinMode(RST_DISPLAY, OUTPUT); // gestión en librería

  Wire.begin(SDA_DISPLAY, SCL_DISPLAY); // inicialización

  if (display_oled.init())
    Serial.println("OLED inicializado");
  else
    Serial.println("Error");

  pinMode(LED_PIN, ????);

  Mcu.begin(????, ????);

}

void loop() {

  ????();
  ????();
  
switch( deviceState )
	{
		case DEVICE_STATE_INIT:
		{
	    	LoRaWAN.init(loraWanClass,loraWanRegion);
			//both set join DR and DR when ADR off 
			LoRaWAN.????(????);
	  		deviceState = DEVICE_STATE_JOIN;

			break;
		}
		case DEVICE_STATE_JOIN:
		{
			LoRaWAN.????();
			break;
		}
		case DEVICE_STATE_SEND:
		{
			prepareTxFrame( ???? );
			LoRaWAN.????();
			deviceState = DEVICE_STATE_CYCLE;
			digitalWrite(LED_PIN, ????);
  			delay(500);
  			digitalWrite(LED_PIN, ????);
  			delay(500);
			
			break;
		}
		case DEVICE_STATE_CYCLE:
		{
			// Schedule next packet transmission
			txDutyCycleTime = appTxDutyCycle + randr( -APP_TX_DUTYCYCLE_RND, APP_TX_DUTYCYCLE_RND );
			LoRaWAN.cycle(txDutyCycleTime);
			deviceState = DEVICE_STATE_SLEEP;
			break;
		}
		case DEVICE_STATE_SLEEP:
		{
			LoRaWAN.sleep(????);
			break;
		}
		default:
		{
			deviceState = ????;
			break;
		}
	}

  //delay (15000);
}

void ????(void){
  temperatura = dht.????();
  humedad = dht.????();
}


void mostrar_display(void){
  display_oled.clear();

  display_oled.setFont(ArialMT_Plain_16);
  display_oled.setTextAlignment(TEXT_ALIGN_CENTER);
  display_oled.drawString(64, 0, "UniLab 4.0"); //coordenadas 64,0 (centrado)

  display_oled.setFont(ArialMT_Plain_10);
  display_oled.setTextAlignment(TEXT_ALIGN_LEFT);
  display_oled.drawString(LINEA_VERTICAL_1, LINEA_HORIZONTAL_2, "T = " + String(temperatura) + "ºC"); 
  display_oled.drawString(LINEA_VERTICAL_1, LINEA_HORIZONTAL_3, "0ºC"); 

  display_oled.setTextAlignment(TEXT_ALIGN_RIGHT);
  display_oled.drawString(LINEA_VERTICAL_2, LINEA_HORIZONTAL_3, "50ºC"); 

  display_oled.drawRect(LINEA_VERTICAL_1, LINEA_HORIZONTAL_4, 50, 10); // x, y, anchura, altura
  display_oled.fillRect(LINEA_VERTICAL_1+1, LINEA_HORIZONTAL_4+1, temperatura, 8); // relleno de la barra (omitiendo primer y último pixel)

  display_oled.setTextAlignment(TEXT_ALIGN_LEFT);
  display_oled.drawString(LINEA_VERTICAL_3, LINEA_HORIZONTAL_2, "H = " + String(humedad) + "%"); 
  display_oled.drawString(LINEA_VERTICAL_3, LINEA_HORIZONTAL_3, "0%"); 

  display_oled.setTextAlignment(TEXT_ALIGN_RIGHT);
  display_oled.drawString(LINEA_VERTICAL_4, LINEA_HORIZONTAL_3, "100%"); 

  display_oled.drawRect(LINEA_VERTICAL_3, LINEA_HORIZONTAL_4, 50, 10); // x, y, anchura, altura
  display_oled.fillRect(LINEA_VERTICAL_3+1, LINEA_HORIZONTAL_4+1, humedad*50/100, 8); // relleno de la barra (omitiendo primer y último pixel)

  display_oled.????();

  delay(20);
}











