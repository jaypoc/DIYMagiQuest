#include <ESP8266WiFi.h>
#include <ESP8266WiFiMulti.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClient.h>
#include "config.h"

const char* ssid = STASSID;
const char* password = STAPSK;
const char* host = "192.168.10.234";
const uint16_t port = 3000;

ESP8266WiFiMulti WiFiMulti;
WiFiClient client;
HTTPClient http;

void setupNetworking() {
    WiFiMulti.addAP(ssid, password);
    Serial.println("Connecting to WiFi");
    while(WiFiMulti.run() != WL_CONNECTED) {
        delay(1000);
        Serial.print(".");
    }
    Serial.println("Connected to WiFi");
}

/* Sends a http POST request with the following payload 
 * 
 *  {
 *      "wand_id": 1234567890,
 *      "magnitude": 20000,
 *      "device_id": "00:00:00:00:00:00"
 *  }
 *  
 */

int getTrackIndex(int wand_id, int magnitude) {
    if (http.begin(client, APIURL)) {
        http.addHeader("Content-Type", "application/json");
        String payload = "{\"wand_id\": " + String(wand_id) + ", \"magnitude\": " + String(magnitude) +", \"device_id\": " + WiFi.macAddress() + "}";
        int httpCode = http.POST(payload);
        if (httpCode > 0) {
            if (httpCode == HTTP_CODE_OK || httpCode == HTTP_CODE_MOVED_PERMANENTLY) {
                String payload = http.getString();
                Serial.println(payload);
            }
        } else {
            Serial.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
        }
        http.end();
    } else {
        Serial.println("[HTTP] Unable to connect");
    }
    return random(1, 5);
}