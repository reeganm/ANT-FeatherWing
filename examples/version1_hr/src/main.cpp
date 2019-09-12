/***********************************
 * AntPlus HRDisplay example
 *
 * Finds a nearby HR Monitor, pairs
 * to it and then reads the information
 * out via the serial port. This example
 * utilizies the adafruit 4 segment
 * alphanumeric display
 *
 * Author Curtis Malainey
 ************************************/
#include <SPI.h>
#include <Wire.h>
#include <Arduino.h>
#include <Adafruit_GFX.h>
#include <Adafruit_LEDBackpack.h>
#include "ANT.h"
#include "ANTPLUS.h"

#define BAUD_RATE 9600
#define CHANNEL_0 0

#define ANT_RESET_PIN 33
#define ANT_SLEEP_PIN 27
#define ANT_SUSPEND_PIN 4
#define ANT_BR1_PIN 32
#define ANT_BR2_PIN 21
#define ANT_BR3_PIN 14

#define DISPLAY_ADDR 0x70

const uint8_t NETWORK_KEY[] = {0x00, 0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77}; // get this from thisisant.com

AntWithCallbacks ant = AntWithCallbacks();
AntPlusRouter router = AntPlusRouter();
ProfileHeartRateDisplay hr = ProfileHeartRateDisplay();
Adafruit_AlphaNum4 display = Adafruit_AlphaNum4();

void heartRateBaseDataPageHandler(AntRxDataResponse& msg, uintptr_t data);
void batteryStatusDataPageHandler(HeartRateBatteryStatus& msg, uintptr_t data);
void capabilitiesDataPageHandler(HeartRateCapabilities& msg, uintptr_t data);
void cumulativeOperatingTimeDataPageHandler(HeartRateCumulativeOperatingTime& msg, uintptr_t data);
void defaultDataPageHandler(HeartRateDefault& msg, uintptr_t data);
void manufacturerInformationDataPageHandler(HeartRateManufacturerInformation& msg, uintptr_t data);
void previousHeartBeatDataPageHandler(HeartRatePreviousHeartBeat& msg, uintptr_t data);
void productInformationDataPageHandler(HeartRateProductInformation& msg, uintptr_t data);
void swimIntervalSummary(HeartRateSwimIntervalSummary& msg, uintptr_t data);

void heartRateFeatures(uint8_t bitfield);
void printStatus(uint8_t status);
void writeStringToDisplay(char* buf);

void setup() {
    char buf[5];

    display.begin(DISPLAY_ADDR);
    display.clear();
    pinMode(ANT_RESET_PIN, OUTPUT);
    pinMode(ANT_BR1_PIN, OUTPUT);
    pinMode(ANT_BR2_PIN, OUTPUT);
    pinMode(ANT_BR3_PIN, OUTPUT);
    digitalWrite(ANT_RESET_PIN, HIGH);
    digitalWrite(ANT_BR1_PIN, HIGH);
    digitalWrite(ANT_BR2_PIN, LOW);
    digitalWrite(ANT_BR3_PIN, HIGH);
    Serial1.begin(BAUD_RATE);
    ant.setSerial(Serial1);
    delay(5000);
    writeStringToDisplay("ANT+");

    router.setDriver(&ant); // never touch ant again
    router.setAntPlusNetworkKey(NETWORK_KEY);
    router.setProfile(CHANNEL_0, &hr);
    // Delay after initial setup to wait for user to connect on serial

    Serial.begin(115200);
    Serial.println("Running");
    hr.onDataPage(heartRateBaseDataPageHandler);
    hr.onHeartRateBatteryStatus(batteryStatusDataPageHandler);
    hr.onHeartRateCapabilities(capabilitiesDataPageHandler);
    hr.onHeartRateCumulativeOperatingTime(cumulativeOperatingTimeDataPageHandler);
    hr.onHeartRateDefault(defaultDataPageHandler);
    hr.onHeartRateManufacturerInformation(manufacturerInformationDataPageHandler);
    hr.onHeartRatePreviousHeartBeat(previousHeartBeatDataPageHandler);
    hr.onHeartRateProductInformation(productInformationDataPageHandler);
    hr.onHeartRateSwimIntervalSummary(swimIntervalSummary);
    hr.begin();
    // wait for pair to complete
    uint8_t status = hr.waitForPair();
    // print channel status
    Serial.println("===========================");
    printStatus(status);
    writeStringToDisplay("ID->");
    delay(2000);
    Serial.print("Device Number: ");
    Serial.println(hr.getDeviceNumber());
    sprintf(buf, "%4x", hr.getDeviceNumber());
    writeStringToDisplay(buf);
    Serial.print("Transmisison Type: ");
    Serial.println(hr.getTransmissionType());
    delay(2000);
}

void loop() {
    router.loop();
}

void writeHrToDisplay(uint8_t hr) {
    char buf[5];

    sprintf(buf, "%4d", hr);
    writeStringToDisplay(buf);
}

void writeStringToDisplay(char* buf) {
    int i;
    for (i = 0; i < 4; i++) {
        display.writeDigitAscii(i, buf[i]);
    }
    display.writeDisplay();
}

void batteryStatusDataPageHandler(HeartRateBatteryStatus& msg, uintptr_t data) {
    Serial.print("Battery Level: ");
    Serial.println(msg.getBatteryLevel());
    Serial.print("Fractional Battery Voltage: ");
    Serial.println(msg.getFractionalBatteryVoltage());
    Serial.print("Coarse Battery Voltage: ");
    Serial.println(msg.getCoarseBatteryVoltage());
    Serial.print("Battery Status: ");
    Serial.println(msg.getBatteryStatus());
}

void capabilitiesDataPageHandler(HeartRateCapabilities& msg, uintptr_t data) {
    Serial.print("Features Supported: ");
    heartRateFeatures(msg.getFeaturesSupported());
    Serial.print("Features Enabled: ");
    heartRateFeatures(msg.getFeaturesEnabled());
}

void cumulativeOperatingTimeDataPageHandler(HeartRateCumulativeOperatingTime& msg, uintptr_t data) {
    Serial.print("Cumulative Operating Time: ");
    Serial.println(msg.getCumulativeOperatingTime());
}

void defaultDataPageHandler(HeartRateDefault& msg, uintptr_t data) {
    // All fields are reserved
}

void manufacturerInformationDataPageHandler(HeartRateManufacturerInformation& msg, uintptr_t data) {
    Serial.print("Manufacturer ID LSB: ");
    Serial.println(msg.getManufacturerIdLsb());
    Serial.print("Serial Number: ");
    Serial.println(msg.getSerialNumber());
}

void previousHeartBeatDataPageHandler(HeartRatePreviousHeartBeat& dp, uintptr_t data) {
    Serial.print("Manufacturer Specific Byte: ");
    Serial.println(dp.getManufacturerSpecific());
    Serial.print("Previous Heart Beat Event Time: ");
    Serial.println(dp.getPreviousHeartBeatEventTime());
}

void productInformationDataPageHandler(HeartRateProductInformation& msg, uintptr_t data) {
    Serial.print("Hardware Version: ");
    Serial.println(msg.getHardwareVersion());
    Serial.print("Software Version: ");
    Serial.println(msg.getSoftwareVersion());
    Serial.print("Model Number: ");
    Serial.println(msg.getModelNumber());
}

void swimIntervalSummary(HeartRateSwimIntervalSummary& msg, uintptr_t data) {
    Serial.print("Interval Average Heart Rate: ");
    Serial.println(msg.getIntervalAverageHeartRate());
    Serial.print("Interval Maximum Heart Rate: ");
    Serial.println(msg.getIntervalMaximumHeartRate());
    Serial.print("Session Average Heart Rate: ");
    Serial.println(msg.getSessionAverageHeartRate());
}

void heartRateBaseDataPageHandler(AntRxDataResponse& msg, uintptr_t data) {
    HeartRateBaseMainDataPage dp = HeartRateBaseMainDataPage(msg);
    Serial.println("===========================");
    Serial.print("DataPage: ");
    Serial.println(dp.getDataPageNumber());
    Serial.print("Heart Beat Event Time: ");
    Serial.println(dp.getHeartBeatEventTime());
    Serial.print("Heart Beat Count: ");
    Serial.println(dp.getHeartBeatCount());
    Serial.print("Computed Heart Rate: ");
    Serial.println(dp.getComputedHeartRate());
    writeHrToDisplay(dp.getComputedHeartRate());
}

void heartRateFeatures(uint8_t bitfield) {
    if (bitfield & ANTPLUS_HEARTRATE_DATAPAGE_CAPABILITIES_FEATURES_EXTENDEDRUNNING) {
        Serial.print("Extended Running ");
    }
    if (bitfield & ANTPLUS_HEARTRATE_DATAPAGE_CAPABILITIES_FEATURES_EXTENDEDCYCLING) {
        Serial.print("Extended Cycling ");
    }
    if (bitfield & ANTPLUS_HEARTRATE_DATAPAGE_CAPABILITIES_FEATURES_EXTENDEDSWIMMING) {
        Serial.print("Extended Swimming ");
    }
    if (bitfield & ANTPLUS_HEARTRATE_DATAPAGE_CAPABILITIES_FEATURES_MANUFACTURER1) {
        Serial.print("Manufacturer Bit 1 ");
    }
    if (bitfield & ANTPLUS_HEARTRATE_DATAPAGE_CAPABILITIES_FEATURES_MANUFACTURER2) {
        Serial.print("Manufacturer Bit 2 ");
    }
    Serial.println();
}

void printStatus(uint8_t status) {
    Serial.print("Channel Status: ");
    switch (status) {
    case CHANNEL_STATUS_UNASSIGNED:
        Serial.println("Unassigned");
        break;
    case CHANNEL_STATUS_ASSIGNED:
        Serial.println("Assigned");
        break;
    case CHANNEL_STATUS_SEARCHING:
        Serial.println("Searching");
        break;
    case CHANNEL_STATUS_TRACKING:
        Serial.println("Tracking");
        break;
    }
}
