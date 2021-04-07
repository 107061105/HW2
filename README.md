# HW2

## I. Introduction

In this assignment, we will gengerate a waveform with a fixed frequency and the selected slew rate, then send it to the picoscope and PC. By doing this, we can compare the difference between signal displayed on the picoscope, also the sampled signal.

## II. Equipment List
### 1. PC or notebook (or an optional VM copy just in case your notebook fails)
### 2. USB Stick to transfer codes and backup data (Recommended but optional)
### 3. A phone (to take a picture of your hardware setup)
### 4. B_L4S5I_IOT01A
### 5. Bread board
### 6. Buttons * 3 (Please keep the same connection as HW2)
### 7. Picoscope
### 8. uLCD display
### 9. Wires

## III. Implement

We need to contain following

### 1.Inputs
Add buttons on the bread board (as DigitalIn): up, down and select. In this assignment, we can select four different slew rates: 1/8, 1/4, 1/2, 1.
### 2.Display
When we implement this program, we will show four slew rates as a menu in uLCD.
![image](https://github.com/107061105/HW2/blob/master/Figure_0.png)
### 3.Generate waveform 
Use DAC to generate a wave form with the chosen frequency and pass the generated signal through a RC low pass filter. In this assignment, we use a RC filter with a pole of 360Hz as a low pass filter.
### 4.Measure
Use Picoscope to measure the generated wave form, and use measure function to verify signal.
### 5.Sample
Sample the generated wave form and send the value to PC/Python. In this assignment, sampling rate is 200 * 50 = 10k for 50Hz, 200 * 100 = 20k for 100Hz, 200 * 500 = 200k for 500Hz.
### 6.Analysis
Analyze the captured waveform: show frequency response and wave on screen with Matplotlib.

## IV. Result

The result is as following:
### 50Hz :
![image](https://github.com/107061105/HW2/blob/master/Figure_0.png)
### 100Hz :
![image](https://github.com/107061105/HW2/blob/master/Figure_1.png)
### 500Hz :
![image](https://github.com/107061105/HW2/blob/master/Figure_2.png)

As above pictures can see, comparing to the signal of 50Hz and the signal of 100Hz, the signal of 500Hz is filtered by RC filter. The frequency component after 360Hz is relatively reduce. 

