EESchema Schematic File Version 4
LIBS:D52M Feather Wing-cache
EELAYER 26 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Wire Wire Line
	4400 4700 4400 4850
Wire Wire Line
	4400 2700 4400 2400
Wire Wire Line
	5000 3000 5150 3000
Wire Wire Line
	5000 3100 5150 3100
Wire Wire Line
	5000 3500 5150 3500
Wire Wire Line
	5000 3400 5150 3400
Wire Wire Line
	5000 3700 5150 3700
Wire Wire Line
	5000 3800 5150 3800
Wire Wire Line
	5000 3900 5150 3900
Wire Wire Line
	5000 4000 5150 4000
Wire Wire Line
	5000 4100 5150 4100
Wire Wire Line
	5000 4200 5150 4200
Wire Wire Line
	5000 4300 5150 4300
Wire Wire Line
	5000 4400 5150 4400
Wire Wire Line
	3800 4400 3650 4400
Wire Wire Line
	3800 4300 3650 4300
Wire Wire Line
	3800 4100 3650 4100
Wire Wire Line
	3800 4000 3650 4000
Wire Wire Line
	3800 3900 3650 3900
Wire Wire Line
	3800 3800 3650 3800
Wire Wire Line
	3800 3600 3650 3600
Wire Wire Line
	3800 3500 3650 3500
Wire Wire Line
	3800 3400 3650 3400
Wire Wire Line
	3800 3100 3650 3100
Wire Wire Line
	3800 3000 3650 3000
Text Label 3500 3200 0    50   ~ 0
RESET
Wire Wire Line
	3500 3200 3800 3200
Text Label 4400 2400 0    50   ~ 0
3V3
Text Label 4400 4850 0    50   ~ 0
GND
Text Label 3400 4200 0    50   ~ 0
SUSPEND
Text Label 5150 4100 0    50   ~ 0
SLEEP
Text Label 5150 3700 0    50   ~ 0
GND
Text Label 3650 4300 0    50   ~ 0
BR2
Wire Wire Line
	3400 4200 3800 4200
Text Label 5150 3100 0    50   ~ 0
RXD0
Text Label 5150 3800 0    50   ~ 0
BR1
Text Label 5150 3000 0    50   ~ 0
BR3
$Comp
L ESP~FEATHER:ESP32FEATHER U1
U 1 1 5C7F9088
P 7350 3050
F 0 "U1" H 7375 3415 50  0000 C CNN
F 1 "ESP32FEATHER" H 7375 3324 50  0000 C CNN
F 2 "ESP32FEATHER:ESP32FEATHER" H 7350 3050 50  0001 C CNN
F 3 "" H 7350 3050 50  0001 C CNN
	1    7350 3050
	1    0    0    -1  
$EndComp
$Comp
L RF_Module:D52MxxM8 U2
U 1 1 5C7FB0DE
P 4400 3700
F 0 "U2" H 4400 4878 50  0000 C CNN
F 1 "D52MxxM8" H 4400 4787 50  0000 C CNN
F 2 "RF_Module:Garmin_M8-35_9.8x14.0mm_Layout6x6_P1.5mm" H 4400 2550 50  0001 C CNN
F 3 "https://www.thisisant.com/assets/resources/D00001687_D52_Module_Datasheet.v.2.3_(Garmin).pdf" H 4500 2850 50  0001 C CNN
	1    4400 3700
	1    0    0    -1  
$EndComp
Wire Wire Line
	7800 4450 7850 4450
Wire Wire Line
	7800 4350 7850 4350
Wire Wire Line
	7800 4150 7850 4150
Wire Wire Line
	7800 4050 7850 4050
Text Label 6800 3250 0    50   ~ 0
3V3
Text Label 6800 3450 0    50   ~ 0
GND
Text Label 6600 4050 0    50   ~ 0
SUSPEND
Text Label 6800 4650 0    50   ~ 0
BR2
Text Label 7850 4450 0    50   ~ 0
BR3
Text Label 7850 4350 0    50   ~ 0
BR1
Text Label 7850 4150 0    50   ~ 0
RESET
Text Label 7850 4050 0    50   ~ 0
SLEEP
Wire Wire Line
	6800 3250 6950 3250
Wire Wire Line
	6800 3450 6950 3450
Wire Wire Line
	6600 4050 6950 4050
Wire Wire Line
	6800 4650 6950 4650
Wire Wire Line
	6950 4450 6750 4450
Wire Wire Line
	3800 3700 3650 3700
Text Label 3650 3700 0    50   ~ 0
TXD0
Text Label 6750 4450 0    50   ~ 0
TXD0
Wire Wire Line
	6950 4550 6750 4550
Text Label 6750 4550 0    50   ~ 0
RXD0
$EndSCHEMATC
