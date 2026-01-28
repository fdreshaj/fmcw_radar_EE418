# fmcw_radar_EE418
FMCW Radar Design at 26.5 - 40 GHz

Initial Systems Level Overview
Bistatic Design
![alt text](image.png)


Monostatic Design

![alt text](image-1.png)


Initial Parts Search Tx bistatic:

MCU 

STM32H730VBT6


Synthesizer 
	ADF4371 62.5MHz - 32 GHz
	Refer to datasheet for more info 
	3.3V, 5V, min 200mA
	Pout = -7dBm at 30 GHz
	

PA  
    MAAP-118260 18-26 GHz 28.5 dB,28.5 dBm, 24 QFN
    MAAP-011319 24-30 GHz 24 dB, 27 dBm PSAT 24 QFN
    

Dir Coupler 

    FPC07181 20GHz ~ 40GHz 20dB 0.3dB IL, 15 dB RL


