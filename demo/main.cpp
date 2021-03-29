#include "mbed.h"
#include "uLCD_4DGL.h"
using namespace std::chrono;

uLCD_4DGL uLCD(D1, D0, D2); // serial tx, serial rx, reset pin;

AnalogOut  aout(PA_4);
InterruptIn up(PB_1);
InterruptIn down(PB_4);
InterruptIn confirm(PA_3);
EventQueue queue(64 * EVENTS_EVENT_SIZE);
Timer debounce;                  //define debounce timer

Thread t;

int flag = 0;
int c = 0;

void Freq_info() {
      uLCD.cls();
      uLCD.printf("\n Frequency is:\n");
      if (c == 0) {             // 100HZ
            uLCD.printf("\n > 100Hz\n");
            uLCD.printf("\n   200Hz\n");
            uLCD.printf("\n   1000Hz\n");
      } else if (c == 1) {      // 200HZ
            uLCD.printf("\n   100Hz\n");
            uLCD.printf("\n > 200Hz\n");
            uLCD.printf("\n   1000Hz\n");
      } else if (c == 2) {      // 1000HZ
            uLCD.printf("\n   100Hz\n");
            uLCD.printf("\n   200Hz\n");
            uLCD.printf("\n > 1000Hz\n");
      }
}

void Freq_confirm() {
      uLCD.printf("\n Confirm!\n");
}

void Freq_up() {
      if (duration_cast<milliseconds>(debounce.elapsed_time()).count() > 500) {
            flag = 0;
            if (c == 2) c = 0;
            else c++;
            queue.call(Freq_info);
            debounce.reset(); //restart timer when the toggle is performed
      }
}

void Freq_down() {
      if (duration_cast<milliseconds>(debounce.elapsed_time()).count() > 500) {
            flag = 0;
            if (c == 0) c = 2;
            else c--;
            queue.call(Freq_info);
            debounce.reset(); //restart timer when the toggle is performed
      }
}

void Freq_conf() {
      if (duration_cast<milliseconds>(debounce.elapsed_time()).count() > 500) {
            flag = 1;
            queue.call(Freq_confirm);
            debounce.reset(); //restart timer when the toggle is performed
      }      
}

int main(void)
{
      //count = 0;
      t.start(callback(&queue, &EventQueue::dispatch_forever));
      debounce.start();

      up.rise(Freq_up);
      down.rise(Freq_down);
      confirm.rise(Freq_conf);

      while (1) {
            if ((c == 0) && flag) {
                  for (float i = 0.0f; i < 0.9f; i += 0.018f) {
                        aout = i;
                        wait_us(1);
                  }
                 for (float i = 0.9f; i > 0.0f; i -= 0.002f) {
                        aout = i;
                        wait_us(7);
                  }
            } else if ((c == 1) && flag) {
                 for (float i = 0.0f; i < 0.9f; i += 0.036f) {
                        aout = i;
                        wait_us(7);
                  }
                 for (float i = 0.9f; i > 0.0f; i -= 0.0045f) {
                        aout = i;
                        wait_ns(13000);
                  }
            } else if ((c == 2) && flag) {
                  for (float i = 0.0f; i < 0.9f; i += 0.06f) {
                      aout = i;
                  }
                  for (float i = 0.9f; i > 0.0f; i -= 0.0085f) {
                        aout = i;
                        wait_ns(1);
                  }
            }
      }
}
