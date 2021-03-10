#include <Arduino.h>
#include <ESP8266WiFi.h>
#include "credentials.h"
#include "site.h"

#define greenLed 14
#define redLed 13
#define button 0

bool open = false;
bool committed = false;
long debounce_time = 0;
long current_time = 0;
char index_html_buffer[sizeof(index_html)/sizeof(char) + 1];

WiFiServer espServer(80);

void setup() {
	Serial.begin(115200);

	// WiFi setup and connection
	WiFi.mode(WIFI_STA);
	WiFi.begin(WIFI_SSID, WIFI_PASS);

	while (WiFi.status() != WL_CONNECTED) {
		delay(10);
	}

	espServer.begin();

	// Setup of leds and button interrupt
	pinMode(greenLed, OUTPUT);
	pinMode(redLed, OUTPUT);
	pinMode(button, INPUT_PULLUP);
	attachInterrupt(digitalPinToInterrupt(button), callback, FALLING);
}

void loop() {
	if (!committed) {
		setLed();
		setSite();
		committed = true;
	}

	WiFiClient client = espServer.available();

	if (!client) {
		return;
	}

	String request = client.readStringUntil('\r');
	client.flush();

	client.println("HTTP/1.1 200 OK");
	client.println("Content-Type: text/html");
	client.println();
	client.println(index_html_buffer);
}

void setLed() {
	digitalWrite(greenLed, open);
	digitalWrite(redLed, !open);
}

void setSite() {
	sprintf(index_html_buffer, index_html, open ? "open" : "closed");
}

ICACHE_RAM_ATTR void callback() {
	current_time = millis();

	if (current_time - debounce_time > 200) {
		open = !open;
		committed = false;
	}

	debounce_time = current_time;
}

