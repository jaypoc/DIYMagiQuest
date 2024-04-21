#include "config.h"
#include "setup.h"
#include "infrared.h"
#include "networking.h"
#include "audio.h"

void setup() {
    Serial.begin(9600);
    while (!Serial) {
        ;
    }
    setupNetworking();
    setupAudio();
    setupInfrared();
}

void loop() {
    if (irrecv.decode(&results)) {
        decodeMagiQuest(&results, &data);
        debugIRData(data);
        if (WiFiMulti.run() == WL_CONNECTED) {
            playTrack(getTrackIndex(data.cmd.wand_id, data.cmd.magnitude)); // Get the track index from the server.
        } else {
            playTrack(1, 10000); // Track 1 is the default track if there's no connection.
        }
        irrecv.resume();
    }
    delay(100);
}