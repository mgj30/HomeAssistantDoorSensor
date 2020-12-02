EESchema Schematic File Version 4
EELAYER 30 0
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
$Comp
L MCU_Module:WeMos_D1_mini W1
U 1 1 5FB8578C
P 5850 4350
F 0 "W1" H 5850 3461 50  0000 C CNN
F 1 "WeMos_D1_mini" H 5850 3370 50  0000 C CNN
F 2 "Module:WEMOS_D1_mini_light" H 5850 3200 50  0001 C CNN
F 3 "https://wiki.wemos.cc/products:d1:d1_mini#documentation" H 4000 3200 50  0001 C CNN
	1    5850 4350
	1    0    0    -1  
$EndComp
$Comp
L Transistor_BJT:2N3904 Q1
U 1 1 5FB8746F
P 4950 3000
F 0 "Q1" H 5140 3046 50  0000 L CNN
F 1 "2N3904" H 5140 2955 50  0000 L CNN
F 2 "Package_TO_SOT_THT:TO-92_Inline" H 5150 2925 50  0001 L CIN
F 3 "https://www.onsemi.com/pub/Collateral/2N3903-D.PDF" H 4950 3000 50  0001 L CNN
	1    4950 3000
	0    1    1    0   
$EndComp
$Comp
L Device:Battery_Cell BT1
U 1 1 5FB882D9
P 3800 4350
F 0 "BT1" H 3918 4446 50  0000 L CNN
F 1 "Battery_Cell" H 3918 4355 50  0000 L CNN
F 2 "Battery:BatteryHolder_Keystone_1042_1x18650" V 3800 4410 50  0001 C CNN
F 3 "~" V 3800 4410 50  0001 C CNN
	1    3800 4350
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_Reed_Opener SW1
U 1 1 5FB8B266
P 5500 2050
F 0 "SW1" H 5500 2272 50  0000 C CNN
F 1 "SW_Reed_Opener" H 5500 2181 50  0000 C CNN
F 2 "DoorSensor:THT_reed_switch_20mmL" H 5500 2050 50  0001 C CNN
F 3 "~" H 5500 2050 50  0001 C CNN
	1    5500 2050
	1    0    0    -1  
$EndComp
$Comp
L Device:CP1 C1
U 1 1 5FB8CEF7
P 4950 2400
F 0 "C1" H 4835 2354 50  0000 R CNN
F 1 "CP1" H 4835 2445 50  0000 R CNN
F 2 "Capacitor_THT:CP_Radial_D4.0mm_P1.50mm" H 4950 2400 50  0001 C CNN
F 3 "~" H 4950 2400 50  0001 C CNN
	1    4950 2400
	-1   0    0    1   
$EndComp
$Comp
L Device:R R1
U 1 1 5FB8EC0D
P 4250 3100
F 0 "R1" H 4320 3146 50  0000 L CNN
F 1 "10K" H 4320 3055 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0309_L9.0mm_D3.2mm_P12.70mm_Horizontal" V 4180 3100 50  0001 C CNN
F 3 "~" H 4250 3100 50  0001 C CNN
	1    4250 3100
	0    -1   -1   0   
$EndComp
$Comp
L Device:R R2
U 1 1 5FB8F232
P 7000 2250
F 0 "R2" H 7070 2296 50  0000 L CNN
F 1 "10K" H 7070 2205 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0309_L9.0mm_D3.2mm_P12.70mm_Horizontal" V 6930 2250 50  0001 C CNN
F 3 "~" H 7000 2250 50  0001 C CNN
	1    7000 2250
	0    -1   -1   0   
$EndComp
$Comp
L Device:R R3
U 1 1 5FB8F7B9
P 4500 2250
F 0 "R3" H 4570 2296 50  0000 L CNN
F 1 "10K" H 4570 2205 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0309_L9.0mm_D3.2mm_P12.70mm_Horizontal" V 4430 2250 50  0001 C CNN
F 3 "~" H 4500 2250 50  0001 C CNN
	1    4500 2250
	0    -1   -1   0   
$EndComp
$Comp
L Device:R R4
U 1 1 5FB8FCEE
P 6650 4650
F 0 "R4" H 6720 4696 50  0000 L CNN
F 1 "1K" H 6720 4605 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0309_L9.0mm_D3.2mm_P12.70mm_Horizontal" V 6580 4650 50  0001 C CNN
F 3 "~" H 6650 4650 50  0001 C CNN
	1    6650 4650
	0    1    1    0   
$EndComp
$Comp
L Device:R R5
U 1 1 5FB903A3
P 6650 4550
F 0 "R5" H 6720 4596 50  0000 L CNN
F 1 "1K" H 6720 4505 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0309_L9.0mm_D3.2mm_P12.70mm_Horizontal" V 6580 4550 50  0001 C CNN
F 3 "~" H 6650 4550 50  0001 C CNN
	1    6650 4550
	0    -1   -1   0   
$EndComp
$Comp
L Device:R R6
U 1 1 5FB9080E
P 6650 2900
F 0 "R6" H 6720 2946 50  0000 L CNN
F 1 "100K" H 6720 2855 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0309_L9.0mm_D3.2mm_P12.70mm_Horizontal" V 6580 2900 50  0001 C CNN
F 3 "~" H 6650 2900 50  0001 C CNN
	1    6650 2900
	1    0    0    -1  
$EndComp
$Comp
L Device:LED D1
U 1 1 5FB92AB7
P 7250 4850
F 0 "D1" H 7243 5067 50  0000 C CNN
F 1 "RED" H 7243 4976 50  0000 C CNN
F 2 "LED_THT:LED_D3.0mm" H 7250 4850 50  0001 C CNN
F 3 "~" H 7250 4850 50  0001 C CNN
	1    7250 4850
	-1   0    0    1   
$EndComp
$Comp
L Device:LED D2
U 1 1 5FB9326A
P 7250 4550
F 0 "D2" H 7243 4767 50  0000 C CNN
F 1 "Green" H 7243 4676 50  0000 C CNN
F 2 "LED_THT:LED_D3.0mm" H 7250 4550 50  0001 C CNN
F 3 "~" H 7250 4550 50  0001 C CNN
	1    7250 4550
	-1   0    0    1   
$EndComp
$Comp
L pspice:DIODE D3
U 1 1 5FB9437E
P 6750 3950
F 0 "D3" H 6750 4215 50  0000 C CNN
F 1 "DIODE" H 6750 4124 50  0000 C CNN
F 2 "Diode_THT:D_A-405_P7.62mm_Horizontal" H 6750 3950 50  0001 C CNN
F 3 "~" H 6750 3950 50  0001 C CNN
	1    6750 3950
	1    0    0    -1  
$EndComp
Wire Wire Line
	6550 3950 6250 3950
Wire Wire Line
	6950 3350 5450 3350
Wire Wire Line
	5450 3350 5450 3950
Wire Wire Line
	4950 2800 4950 2550
Wire Wire Line
	5450 3950 4700 3950
Wire Wire Line
	4700 3950 4700 3100
Wire Wire Line
	4700 3100 4750 3100
Connection ~ 5450 3950
Wire Wire Line
	4950 2250 4950 2050
Wire Wire Line
	4950 2050 5300 2050
Wire Wire Line
	4700 3100 4400 3100
Connection ~ 4700 3100
Wire Wire Line
	3800 4150 3800 3100
Wire Wire Line
	3800 3100 4100 3100
Wire Wire Line
	3800 3100 3800 1750
Wire Wire Line
	3800 1750 5850 1750
Wire Wire Line
	5850 1750 5850 2050
Connection ~ 3800 3100
Wire Wire Line
	5150 3100 5150 5450
Wire Wire Line
	5150 5450 3800 5450
Wire Wire Line
	3800 5450 3800 4550
Wire Wire Line
	5950 3550 5950 1750
Wire Wire Line
	5950 1750 5850 1750
Connection ~ 5850 1750
Wire Wire Line
	5850 5150 5850 5450
Wire Wire Line
	5850 5450 5150 5450
Connection ~ 5150 5450
Wire Wire Line
	6950 3350 6950 3950
Wire Wire Line
	6650 3050 6650 3850
Wire Wire Line
	6650 3850 6250 3850
Wire Wire Line
	6650 2750 6650 1750
Wire Wire Line
	6650 1750 5950 1750
Connection ~ 5950 1750
Wire Wire Line
	6850 2250 4950 2250
Connection ~ 4950 2250
Wire Wire Line
	7150 2250 7150 4450
Wire Wire Line
	7150 4450 6250 4450
Wire Wire Line
	4650 2250 4950 2250
Wire Wire Line
	4350 2250 3550 2250
Wire Wire Line
	3550 2250 3550 4550
Wire Wire Line
	3550 4550 3800 4550
Connection ~ 3800 4550
Wire Wire Line
	3800 4550 3800 4450
Wire Wire Line
	6500 4550 6250 4550
Wire Wire Line
	7100 4550 6800 4550
Wire Wire Line
	7400 4550 7400 4850
Wire Wire Line
	7400 5450 5850 5450
Connection ~ 5850 5450
Connection ~ 7400 4850
Wire Wire Line
	7400 4850 7400 5450
Wire Wire Line
	6250 4650 6500 4650
Wire Wire Line
	7100 4850 7100 4650
Wire Wire Line
	6800 4650 7100 4650
Wire Wire Line
	5700 2050 5850 2050
$EndSCHEMATC
