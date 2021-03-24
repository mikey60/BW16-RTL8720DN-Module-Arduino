EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A 11000 8500
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
L power:+3.3V #PWR0102
U 1 1 5FAB4FE6
P 7250 2450
F 0 "#PWR0102" H 7250 2300 50  0001 C CNN
F 1 "+3.3V" H 7265 2623 50  0000 C CNN
F 2 "" H 7250 2450 50  0001 C CNN
F 3 "" H 7250 2450 50  0001 C CNN
	1    7250 2450
	1    0    0    -1  
$EndComp
Wire Wire Line
	7250 2450 7250 2700
$Comp
L power:GND #PWR0103
U 1 1 5FAB86DE
P 5500 3350
F 0 "#PWR0103" H 5500 3100 50  0001 C CNN
F 1 "GND" H 5505 3177 50  0000 C CNN
F 2 "" H 5500 3350 50  0001 C CNN
F 3 "" H 5500 3350 50  0001 C CNN
	1    5500 3350
	1    0    0    -1  
$EndComp
Text Notes 8900 3750 0    50   ~ 0
Connections to USB\n to 3.3V serial converter
Wire Wire Line
	6700 4200 6700 4250
$Comp
L RTL8720:BW16 U1
U 1 1 5FA8CB0C
P 7050 3500
F 0 "U1" H 7050 4481 50  0000 C CNN
F 1 "BW16" H 7050 4390 50  0000 C CNN
F 2 "RTL8720DN:BW16" H 7050 3500 50  0001 C CNN
F 3 "http://wiki.ai-thinker.com/_media/esp8266/esp8266_series_modules_user_manual_v1.1.pdf" H 6700 3600 50  0001 C CNN
	1    7050 3500
	1    0    0    -1  
$EndComp
Wire Wire Line
	6900 4200 6900 4250
$Comp
L 74xx:74HC02 U2
U 1 1 600A37F1
P 3150 3300
F 0 "U2" H 3150 3625 50  0000 C CNN
F 1 "74HC02" H 3150 3534 50  0000 C CNN
F 2 "Package_SO:SOIC-14_3.9x8.7mm_P1.27mm" H 3150 3300 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74hc02" H 3150 3300 50  0001 C CNN
	1    3150 3300
	1    0    0    -1  
$EndComp
$Comp
L 74xx:74HC02 U2
U 3 1 600AA251
P 4200 4550
F 0 "U2" H 4200 4875 50  0000 C CNN
F 1 "74HC02" H 4200 4784 50  0000 C CNN
F 2 "Package_SO:SOIC-14_3.9x8.7mm_P1.27mm" H 4200 4550 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74hc02" H 4200 4550 50  0001 C CNN
	3    4200 4550
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0105
U 1 1 600B70D3
P 5800 6100
F 0 "#PWR0105" H 5800 5850 50  0001 C CNN
F 1 "GND" H 5805 5927 50  0000 C CNN
F 2 "" H 5800 6100 50  0001 C CNN
F 3 "" H 5800 6100 50  0001 C CNN
	1    5800 6100
	1    0    0    -1  
$EndComp
$Comp
L Device:R_Small_US R3
U 1 1 600CC76F
P 2350 2850
F 0 "R3" H 2418 2896 50  0000 L CNN
F 1 "1Meg" H 2418 2805 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 2350 2850 50  0001 C CNN
F 3 "~" H 2350 2850 50  0001 C CNN
	1    2350 2850
	1    0    0    -1  
$EndComp
$Comp
L Device:R_Small_US R2
U 1 1 600CE4DB
P 5850 3700
F 0 "R2" H 5918 3746 50  0000 L CNN
F 1 "1K" H 5918 3655 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 5850 3700 50  0001 C CNN
F 3 "~" H 5850 3700 50  0001 C CNN
	1    5850 3700
	1    0    0    -1  
$EndComp
$Comp
L Device:R_Small_US R6
U 1 1 600D1008
P 3950 3500
F 0 "R6" H 3882 3454 50  0000 R CNN
F 1 "10K" H 3882 3545 50  0000 R CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 3950 3500 50  0001 C CNN
F 3 "~" H 3950 3500 50  0001 C CNN
	1    3950 3500
	-1   0    0    1   
$EndComp
$Comp
L Device:C_Small C2
U 1 1 600D675B
P 3950 3800
F 0 "C2" H 4042 3846 50  0000 L CNN
F 1 "0.47uf" H 4042 3755 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 3950 3800 50  0001 C CNN
F 3 "~" H 3950 3800 50  0001 C CNN
	1    3950 3800
	1    0    0    -1  
$EndComp
$Comp
L Device:R_Small_US R5
U 1 1 600DA80E
P 2350 3400
F 0 "R5" H 2282 3354 50  0000 R CNN
F 1 "10K" H 2282 3445 50  0000 R CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 2350 3400 50  0001 C CNN
F 3 "~" H 2350 3400 50  0001 C CNN
	1    2350 3400
	-1   0    0    1   
$EndComp
$Comp
L Device:C_Small C1
U 1 1 600DB243
P 2350 3700
F 0 "C1" H 2442 3746 50  0000 L CNN
F 1 "0.47uf" H 2442 3655 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 2350 3700 50  0001 C CNN
F 3 "~" H 2350 3700 50  0001 C CNN
	1    2350 3700
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0106
U 1 1 600E65AA
P 4550 4000
F 0 "#PWR0106" H 4550 3750 50  0001 C CNN
F 1 "GND" H 4555 3827 50  0000 C CNN
F 2 "" H 4550 4000 50  0001 C CNN
F 3 "" H 4550 4000 50  0001 C CNN
	1    4550 4000
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0107
U 1 1 600E6D89
P 2850 3900
F 0 "#PWR0107" H 2850 3650 50  0001 C CNN
F 1 "GND" H 2855 3727 50  0000 C CNN
F 2 "" H 2850 3900 50  0001 C CNN
F 3 "" H 2850 3900 50  0001 C CNN
	1    2850 3900
	1    0    0    -1  
$EndComp
Wire Wire Line
	3950 3600 3950 3700
Wire Wire Line
	4550 3300 4450 3300
Wire Wire Line
	2850 3200 2350 3200
Wire Wire Line
	2350 3200 2350 3300
Wire Wire Line
	3950 3300 3950 3400
$Comp
L 74xx:74HC02 U2
U 2 1 600A6987
P 4850 3400
F 0 "U2" H 4850 3725 50  0000 C CNN
F 1 "74HC02" H 4850 3634 50  0000 C CNN
F 2 "Package_SO:SOIC-14_3.9x8.7mm_P1.27mm" H 4850 3400 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74hc02" H 4850 3400 50  0001 C CNN
	2    4850 3400
	1    0    0    -1  
$EndComp
Wire Wire Line
	4550 3500 4550 3950
Wire Wire Line
	2850 3400 2850 3850
Wire Wire Line
	3950 3900 3950 3950
Wire Wire Line
	3950 3950 4550 3950
Connection ~ 4550 3950
Wire Wire Line
	4550 3950 4550 4000
Wire Wire Line
	2350 3800 2350 3850
Wire Wire Line
	2350 3850 2850 3850
Connection ~ 2850 3850
Wire Wire Line
	2850 3850 2850 3900
Wire Wire Line
	2350 3500 2350 3600
Wire Wire Line
	2350 2950 2350 3200
Connection ~ 2350 3200
Wire Wire Line
	2350 3200 2050 3200
Wire Wire Line
	2050 4650 3900 4650
Wire Wire Line
	3950 3300 3750 3300
Wire Wire Line
	3750 3300 3750 4450
Wire Wire Line
	3750 4450 3900 4450
Connection ~ 3950 3300
$Comp
L power:+3.3V #PWR0108
U 1 1 6010EC37
P 5850 3500
F 0 "#PWR0108" H 5850 3350 50  0001 C CNN
F 1 "+3.3V" H 5865 3673 50  0000 C CNN
F 2 "" H 5850 3500 50  0001 C CNN
F 3 "" H 5850 3500 50  0001 C CNN
	1    5850 3500
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR0109
U 1 1 6010F57F
P 2350 2650
F 0 "#PWR0109" H 2350 2500 50  0001 C CNN
F 1 "+3.3V" H 2365 2823 50  0000 C CNN
F 2 "" H 2350 2650 50  0001 C CNN
F 3 "" H 2350 2650 50  0001 C CNN
	1    2350 2650
	1    0    0    -1  
$EndComp
Wire Wire Line
	2350 2750 2350 2650
Wire Wire Line
	5850 3500 5850 3600
$Comp
L Connector:Conn_01x03_Female J1
U 1 1 600CA2E2
P 1250 4350
F 0 "J1" H 1142 4635 50  0000 C CNN
F 1 "Mag Switch" H 1142 4544 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x03_P2.54mm_Vertical" H 1250 4350 50  0001 C CNN
F 3 "~" H 1250 4350 50  0001 C CNN
	1    1250 4350
	-1   0    0    -1  
$EndComp
Wire Wire Line
	1450 4450 3750 4450
Connection ~ 3750 4450
Wire Wire Line
	1450 4250 1700 4250
$Comp
L power:GND #PWR0110
U 1 1 600EA759
P 1700 4800
F 0 "#PWR0110" H 1700 4550 50  0001 C CNN
F 1 "GND" H 1705 4627 50  0000 C CNN
F 2 "" H 1700 4800 50  0001 C CNN
F 3 "" H 1700 4800 50  0001 C CNN
	1    1700 4800
	1    0    0    -1  
$EndComp
Wire Wire Line
	7650 3700 7750 3700
Wire Wire Line
	7650 3100 7750 3100
Wire Wire Line
	7750 3100 7750 2100
Wire Wire Line
	3500 2100 3500 3300
Wire Wire Line
	3500 3300 3450 3300
Wire Wire Line
	7750 4550 7750 3700
Wire Wire Line
	4500 4550 5400 4550
$Comp
L Device:R_Small_US R1
U 1 1 600C65AB
P 10050 3350
F 0 "R1" H 9982 3304 50  0000 R CNN
F 1 "2K" H 9982 3395 50  0000 R CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 10050 3350 50  0001 C CNN
F 3 "~" H 10050 3350 50  0001 C CNN
	1    10050 3350
	-1   0    0    1   
$EndComp
$Comp
L power:GND #PWR0104
U 1 1 5FAB8F75
P 10050 3600
F 0 "#PWR0104" H 10050 3350 50  0001 C CNN
F 1 "GND" H 10055 3427 50  0000 C CNN
F 2 "" H 10050 3600 50  0001 C CNN
F 3 "" H 10050 3600 50  0001 C CNN
	1    10050 3600
	1    0    0    -1  
$EndComp
Wire Wire Line
	7650 3800 8700 3800
Wire Wire Line
	7650 3200 8800 3200
Wire Wire Line
	8800 3200 8800 2900
Wire Wire Line
	7850 2000 7850 3300
Wire Wire Line
	7850 3300 7650 3300
$Comp
L Regulator_Linear:AMS1117-3.3 U3
U 1 1 600EFF79
P 2350 1550
F 0 "U3" H 2350 1792 50  0000 C CNN
F 1 "AMS1117-3.3" H 2350 1701 50  0000 C CNN
F 2 "Package_TO_SOT_SMD:SOT-223-3_TabPin2" H 2350 1750 50  0001 C CNN
F 3 "http://www.advanced-monolithic.com/pdf/ds1117.pdf" H 2450 1300 50  0001 C CNN
	1    2350 1550
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C3
U 1 1 6010B1B3
P 1800 1800
F 0 "C3" H 1892 1846 50  0000 L CNN
F 1 "22uf" H 1892 1755 50  0000 L CNN
F 2 "Resistor_SMD:R_1210_3225Metric_Pad1.42x2.65mm_HandSolder" H 1800 1800 50  0001 C CNN
F 3 "~" H 1800 1800 50  0001 C CNN
	1    1800 1800
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x03_Female J2
U 1 1 60113324
P 9150 3300
F 0 "J2" H 9042 3585 50  0000 C CNN
F 1 "UART" H 9042 3494 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x03_P2.54mm_Vertical" H 9150 3300 50  0001 C CNN
F 3 "~" H 9150 3300 50  0001 C CNN
	1    9150 3300
	1    0    0    -1  
$EndComp
Wire Wire Line
	8700 3800 8700 3300
Wire Wire Line
	8700 3300 8950 3300
Wire Wire Line
	8950 3400 8850 3400
Wire Wire Line
	8850 3400 8850 3550
Wire Wire Line
	5800 5700 5800 5900
Wire Wire Line
	5800 5900 5800 6050
Connection ~ 5800 5900
$Comp
L 74xx:74HC02 U2
U 4 1 600AB677
P 6100 5800
F 0 "U2" H 6100 6125 50  0000 C CNN
F 1 "74HC02" H 6100 6034 50  0000 C CNN
F 2 "Package_SO:SOIC-14_3.9x8.7mm_P1.27mm" H 6100 5800 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74hc02" H 6100 5800 50  0001 C CNN
	4    6100 5800
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C4
U 1 1 60126351
P 2800 1750
F 0 "C4" H 2892 1796 50  0000 L CNN
F 1 "22uf" H 2892 1705 50  0000 L CNN
F 2 "Resistor_SMD:R_1210_3225Metric_Pad1.42x2.65mm_HandSolder" H 2800 1750 50  0001 C CNN
F 3 "~" H 2800 1750 50  0001 C CNN
	1    2800 1750
	1    0    0    -1  
$EndComp
Wire Wire Line
	1800 1900 1800 2050
Wire Wire Line
	1800 2050 2350 2050
Wire Wire Line
	2800 2050 2800 1850
Wire Wire Line
	2350 1850 2350 2050
Connection ~ 2350 2050
Wire Wire Line
	2350 2050 2800 2050
$Comp
L power:GND #PWR0111
U 1 1 6012A0BC
P 2350 2050
F 0 "#PWR0111" H 2350 1800 50  0001 C CNN
F 1 "GND" H 2355 1877 50  0000 C CNN
F 2 "" H 2350 2050 50  0001 C CNN
F 3 "" H 2350 2050 50  0001 C CNN
	1    2350 2050
	1    0    0    -1  
$EndComp
Wire Wire Line
	2650 1550 2800 1550
Wire Wire Line
	2800 1550 2800 1650
Wire Wire Line
	2050 1550 1800 1550
Wire Wire Line
	1800 1550 1800 1700
Wire Wire Line
	2800 1550 3150 1550
Connection ~ 2800 1550
$Comp
L power:+3.3V #PWR0112
U 1 1 6012FA26
P 3150 1550
F 0 "#PWR0112" H 3150 1400 50  0001 C CNN
F 1 "+3.3V" H 3165 1723 50  0000 C CNN
F 2 "" H 3150 1550 50  0001 C CNN
F 3 "" H 3150 1550 50  0001 C CNN
	1    3150 1550
	1    0    0    -1  
$EndComp
$Comp
L Device:R_Small_US R7
U 1 1 60133CD1
P 2350 1050
F 0 "R7" V 2282 1004 50  0000 R CNN
F 1 "0" V 2282 1095 50  0000 R CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 2350 1050 50  0001 C CNN
F 3 "~" H 2350 1050 50  0001 C CNN
	1    2350 1050
	0    1    1    0   
$EndComp
Wire Wire Line
	1800 1550 1800 1350
Wire Wire Line
	1800 1050 2250 1050
Connection ~ 1800 1550
Wire Wire Line
	2450 1050 2800 1050
Wire Wire Line
	2800 1050 2800 1550
Wire Wire Line
	1450 1650 1450 1750
Wire Wire Line
	1450 2050 1800 2050
Connection ~ 1800 2050
$Comp
L Connector:Conn_01x02_Female J4
U 1 1 6016319A
P 6000 2900
F 0 "J4" H 5892 3085 50  0000 C CNN
F 1 "GPIO2" H 5892 2994 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x02_P2.54mm_Vertical" H 6000 2900 50  0001 C CNN
F 3 "~" H 6000 2900 50  0001 C CNN
	1    6000 2900
	-1   0    0    -1  
$EndComp
Wire Wire Line
	6200 2900 6450 2900
Wire Wire Line
	6200 3000 6300 3000
Wire Wire Line
	6300 3000 6300 3300
Wire Wire Line
	5900 3100 6450 3100
Wire Wire Line
	7650 4000 7850 4000
Wire Wire Line
	7850 4000 7850 4350
Wire Wire Line
	7650 3900 7950 3900
Wire Wire Line
	7950 3900 7950 4250
Wire Wire Line
	8050 4150 8050 3600
Wire Wire Line
	8050 3600 7650 3600
$Comp
L Connector:Conn_01x06_Female J5
U 1 1 6017DF0A
P 8550 4050
F 0 "J5" H 8303 3543 50  0000 L CNN
F 1 "GPIO1" H 8302 3661 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x06_P2.54mm_Vertical" H 8550 4050 50  0001 C CNN
F 3 "~" H 8550 4050 50  0001 C CNN
	1    8550 4050
	1    0    0    -1  
$EndComp
Wire Wire Line
	8250 3950 8350 3950
Wire Wire Line
	8150 4050 8350 4050
Wire Wire Line
	8050 4150 8350 4150
Wire Wire Line
	7950 4250 8350 4250
Wire Wire Line
	7850 4350 8350 4350
Wire Wire Line
	8350 3850 8350 3500
Wire Wire Line
	8350 3500 7650 3500
Wire Wire Line
	8250 3950 8250 3400
Wire Wire Line
	8250 3400 7650 3400
Wire Wire Line
	8150 4050 8150 3000
Wire Wire Line
	8150 3000 7650 3000
NoConn ~ 6400 5800
Wire Wire Line
	5850 3800 5850 4000
Wire Wire Line
	5850 4000 6300 4000
Wire Wire Line
	6300 4000 6300 3300
Connection ~ 6300 3300
Wire Wire Line
	6300 3300 6450 3300
$Comp
L Device:R_Small_US R4
U 1 1 600E8247
P 4450 2850
F 0 "R4" H 4518 2896 50  0000 L CNN
F 1 "1Meg" H 4518 2805 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 4450 2850 50  0001 C CNN
F 3 "~" H 4450 2850 50  0001 C CNN
	1    4450 2850
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR0113
U 1 1 600E824E
P 4450 2650
F 0 "#PWR0113" H 4450 2500 50  0001 C CNN
F 1 "+3.3V" H 4465 2823 50  0000 C CNN
F 2 "" H 4450 2650 50  0001 C CNN
F 3 "" H 4450 2650 50  0001 C CNN
	1    4450 2650
	1    0    0    -1  
$EndComp
Wire Wire Line
	4450 2750 4450 2650
Wire Wire Line
	4450 2950 4450 3300
Connection ~ 4450 3300
Wire Wire Line
	4450 3300 3950 3300
$Comp
L power:GND #PWR0114
U 1 1 6010EA37
P 7650 2750
F 0 "#PWR0114" H 7650 2500 50  0001 C CNN
F 1 "GND" H 7655 2577 50  0000 C CNN
F 2 "" H 7650 2750 50  0001 C CNN
F 3 "" H 7650 2750 50  0001 C CNN
	1    7650 2750
	1    0    0    -1  
$EndComp
Wire Wire Line
	7650 2750 7650 2700
Wire Wire Line
	7650 2500 7650 2450
Wire Wire Line
	7650 2450 7250 2450
Connection ~ 7250 2450
$Comp
L Device:C_Small C5
U 1 1 60120753
P 7650 2600
F 0 "C5" H 7742 2646 50  0000 L CNN
F 1 "0.1uf" H 7742 2555 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 7650 2600 50  0001 C CNN
F 3 "~" H 7650 2600 50  0001 C CNN
	1    7650 2600
	-1   0    0    -1  
$EndComp
Text Label 850  1600 0    50   ~ 0
+3.3_5V
Wire Wire Line
	1450 1550 1800 1550
$Comp
L Connector:Conn_01x02_Female J3
U 1 1 6013A65C
P 1250 1550
F 0 "J3" H 950 1650 50  0000 C CNN
F 1 "Power" H 1142 1644 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x02_P2.54mm_Vertical" H 1250 1550 50  0001 C CNN
F 3 "~" H 1250 1550 50  0001 C CNN
	1    1250 1550
	-1   0    0    -1  
$EndComp
Text Label 1000 1700 0    50   ~ 0
GND
Text Label 9200 3250 0    50   ~ 0
TXD
Connection ~ 8800 3200
Wire Wire Line
	8800 3200 8950 3200
Text Label 9200 3350 0    50   ~ 0
RXD
Text Label 9200 3450 0    50   ~ 0
GND
Wire Wire Line
	10050 3450 10050 3550
Text Label 8600 3850 0    50   ~ 0
PA12
Text Label 8600 3950 0    50   ~ 0
PA30
Text Label 8600 4050 0    50   ~ 0
PA14
Text Label 8600 4200 0    50   ~ 0
PA27
Text Label 8600 4300 0    50   ~ 0
PA25
Text Label 8600 4400 0    50   ~ 0
PA15
Text Label 5800 2900 0    50   ~ 0
PA13
Text Label 5850 3050 0    50   ~ 0
PB3
Text Label 1050 4500 0    50   ~ 0
NC
Wire Wire Line
	2050 3200 2050 4350
Wire Wire Line
	1700 4250 1700 4800
Wire Wire Line
	1450 4350 2050 4350
Connection ~ 2050 4350
Wire Wire Line
	2050 4350 2050 4650
Text Label 1000 4250 0    50   ~ 0
GND
Text Label 1050 4400 0    50   ~ 0
NO
Wire Wire Line
	8850 3550 10050 3550
Connection ~ 10050 3550
Wire Wire Line
	10050 3550 10050 3600
$Comp
L power:GND #PWR0101
U 1 1 5FAB4A39
P 6800 4300
F 0 "#PWR0101" H 6800 4050 50  0001 C CNN
F 1 "GND" H 6805 4127 50  0000 C CNN
F 2 "" H 6800 4300 50  0001 C CNN
F 3 "" H 6800 4300 50  0001 C CNN
	1    6800 4300
	1    0    0    -1  
$EndComp
Wire Wire Line
	6700 4250 6800 4250
Wire Wire Line
	6800 4300 6800 4250
Connection ~ 6800 4250
Wire Wire Line
	6800 4250 6900 4250
$Comp
L Switch:SW_SPST SW2
U 1 1 601EECF7
P 9850 2900
F 0 "SW2" H 9850 3135 50  0000 C CNN
F 1 "DNLOAD" H 9850 3044 50  0000 C CNN
F 2 "Button_Switch_SMD:SW_Push_SPST_NO_Alps_SKRK" H 9850 2900 50  0001 C CNN
F 3 "~" H 9850 2900 50  0001 C CNN
	1    9850 2900
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_SPST SW1
U 1 1 601F6CE8
P 5700 3100
F 0 "SW1" H 5700 3335 50  0000 C CNN
F 1 "RESET" H 5700 3244 50  0000 C CNN
F 2 "Button_Switch_SMD:SW_SPST_EVQPE1" H 5700 3100 50  0001 C CNN
F 3 "~" H 5700 3100 50  0001 C CNN
	1    5700 3100
	1    0    0    -1  
$EndComp
Wire Wire Line
	8800 2900 9650 2900
Wire Wire Line
	10050 2900 10050 3250
Wire Wire Line
	5500 3100 5500 3350
$Comp
L power:PWR_FLAG #FLG0101
U 1 1 60235956
P 1200 1350
F 0 "#FLG0101" H 1200 1425 50  0001 C CNN
F 1 "PWR_FLAG" V 1200 1477 50  0000 L CNN
F 2 "" H 1200 1350 50  0001 C CNN
F 3 "~" H 1200 1350 50  0001 C CNN
	1    1200 1350
	0    -1   -1   0   
$EndComp
$Comp
L power:PWR_FLAG #FLG0102
U 1 1 60236052
P 1250 1750
F 0 "#FLG0102" H 1250 1825 50  0001 C CNN
F 1 "PWR_FLAG" V 1250 1877 50  0000 L CNN
F 2 "" H 1250 1750 50  0001 C CNN
F 3 "~" H 1250 1750 50  0001 C CNN
	1    1250 1750
	0    -1   -1   0   
$EndComp
Wire Wire Line
	1250 1750 1450 1750
Connection ~ 1450 1750
Wire Wire Line
	1450 1750 1450 2050
Wire Wire Line
	1200 1350 1800 1350
Connection ~ 1800 1350
Wire Wire Line
	1800 1350 1800 1050
$Comp
L 74xx:74HC02 U2
U 5 1 60204E68
P 5050 5550
F 0 "U2" H 5280 5596 50  0000 L CNN
F 1 "74HC02" H 5280 5505 50  0000 L CNN
F 2 "" H 5050 5550 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74hc02" H 5050 5550 50  0001 C CNN
	5    5050 5550
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR0115
U 1 1 60213A19
P 5050 4900
F 0 "#PWR0115" H 5050 4750 50  0001 C CNN
F 1 "+3.3V" H 5065 5073 50  0000 C CNN
F 2 "" H 5050 4900 50  0001 C CNN
F 3 "" H 5050 4900 50  0001 C CNN
	1    5050 4900
	1    0    0    -1  
$EndComp
Wire Wire Line
	5050 5050 5050 4900
Wire Wire Line
	5050 6050 5800 6050
Connection ~ 5800 6050
Wire Wire Line
	5800 6050 5800 6100
Text Notes 8550 2450 0    50   ~ 0
To put the device in download mode: \n  Press and hold DNLOAD (SW2)\n  Press and release RESET (SW1)\n  Release DNLOAD (SW2)
Text Notes 1700 900  0    50   ~ 0
R7 is normally open when AMS1117-3.3 is installed and\n  using a 5V power connection on J3\nDon't install  AMS1117-3.3 and short R7 or \n   install a 0 Ohm resistor to connect J3, 3.3 volts (LiFePO4 Battery)\n   directly to board 3.3v connections.
Text Notes 1800 5600 0    50   ~ 0
The 74HC02 (U2) and its associated resistors and capacitors\n   R3-R6 and C1-C2 are only needed for the door switch application.\nIt provides a 200 msec logic high pulse to PA26 when the\n   door is opened and closed to wakeup the device from deepsleep.
Text Notes 1800 6100 0    50   ~ 0
Resistors R5 and R6  are for protecting the gate inputs\n  from residual charge on the capacitors when the power\n  is removed.  Not sure if they are needed by had a blown\n  input on the breadboard.
$Comp
L Connector:Conn_01x03_Female J6
U 1 1 6025FA4A
P 6400 2500
F 0 "J6" H 6292 2785 50  0000 C CNN
F 1 "GPIO3" H 6292 2694 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x03_P2.54mm_Vertical" H 6400 2500 50  0001 C CNN
F 3 "~" H 6400 2500 50  0001 C CNN
	1    6400 2500
	1    0    0    -1  
$EndComp
Text Label 6500 2600 0    50   ~ 0
PA26
Text Label 6500 2500 0    50   ~ 0
PB2
Text Label 6500 2400 0    50   ~ 0
PB1
Wire Wire Line
	3500 2100 5700 2100
Wire Wire Line
	5700 2400 5700 2100
Connection ~ 5700 2100
Wire Wire Line
	5700 2100 7750 2100
Wire Wire Line
	5700 2400 6200 2400
Wire Wire Line
	5300 2000 7850 2000
Wire Wire Line
	5150 3400 5300 3400
Wire Wire Line
	6200 2500 5300 2500
Connection ~ 5300 2500
Wire Wire Line
	5300 2500 5300 2000
Wire Wire Line
	6200 2600 5400 2600
Wire Wire Line
	5300 3400 5300 2500
Wire Wire Line
	5400 2600 5400 4550
Connection ~ 5400 4550
Wire Wire Line
	5400 4550 7750 4550
$Comp
L Connector:Conn_01x02_Female J7
U 1 1 60454734
P 3700 1550
F 0 "J7" H 3400 1650 50  0000 C CNN
F 1 "Pwr " H 3592 1644 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x02_P2.54mm_Vertical" H 3700 1550 50  0001 C CNN
F 3 "~" H 3700 1550 50  0001 C CNN
	1    3700 1550
	1    0    0    -1  
$EndComp
Wire Wire Line
	3500 1650 3250 1650
Wire Wire Line
	3250 1650 3250 2050
Wire Wire Line
	3250 2050 2800 2050
Connection ~ 2800 2050
Wire Wire Line
	3500 1550 3150 1550
Connection ~ 3150 1550
Text Label 3800 1650 0    50   ~ 0
GND
Text Label 3800 1550 0    50   ~ 0
+3.3V_OUT
$Comp
L Connector:Conn_01x01_Female J8
U 1 1 604762E4
P 1450 1050
F 0 "J8" H 1342 1235 50  0000 C CNN
F 1 "Pwr" H 1342 1144 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x01_P2.54mm_Vertical" H 1450 1050 50  0001 C CNN
F 3 "~" H 1450 1050 50  0001 C CNN
	1    1450 1050
	-1   0    0    -1  
$EndComp
Text Label 1000 1100 0    50   ~ 0
+5V_OUT
Wire Wire Line
	1650 1050 1800 1050
Connection ~ 1800 1050
Text Notes 5200 1600 0    50   ~ 0
Note: Can connect 3.3 volts directly to PB3 to measure the battery.\n Set PB3 to an output before going into deep sleep for negligible current draw.
$EndSCHEMATC
