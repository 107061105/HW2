# HW2

## I. Introduction

In this assignment, we will gengerate triangle waves, then send it to the picoscope and PC. By doing this, we can compare the difference between signal displayed on the picoscope, and the sampled signal.

## II. Implement

We need to contain following

### 1.Inputs
Add buttons on the bread board (as DigitalIn): up, down and select. In this assignment, we can select three different frequecies: 50Hz, 100Hz and 500Hz.
### 2.Display
When we implement this program, we will show three of frequencies as a menu in uLCD.
### 3.Generate waveform 
Use DAC to generate a wave form with the chosen frequency and pass the generated signal through a RC low pass filter. In this assignment, we use a RC filter with a pole of 360Hz as a low pass filter.
### 4.Measure
Use Picoscope to measure the generated wave form, and use measure function to verify signal.
### 5.Sample
Sample the generated wave form and send the value to PC/Python. In this assignment, sampling rate is 200 * 50 = 10k for 50Hz, 200 * 100 = 20k for 100Hz, 200 * 500 = 200k for 500Hz.
### 6.Analysis
Analyze the captured waveform: show frequency response and wave on screen with Matplotlib.

## III. Result

The result is as following:
### 50Hz :
### 100Hz :
### 500Hz :

