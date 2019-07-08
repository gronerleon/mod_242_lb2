#include <TimerOne.h>
#include <Wire.h>
#include <MultiFuncShield.h>

int led1 = 13;
int led2 = 12;
int led3 = 11;
int led4 = 10;

int cnt = 0;
int marks = 0;
float cntMarks = 0;
float average = 0;

void setup() {
  Timer1.initialize();
  MFS.initialize(&Timer1);    // initialize multi-function shield library
  MFS.write(0);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);  
  Serial.begin(9600);
}

void loop() {
  byte btn = MFS.getButton();

        if (btn == BUTTON_1_PRESSED || btn == BUTTON_1_LONG_PRESSED)
        {
          cnt++;
          MFS.write(cnt);
          }
        else if (btn == BUTTON_2_PRESSED || btn == BUTTON_2_LONG_PRESSED)
        {
          marks = marks + cnt;
          cntMarks++;
          cnt = 0;
          MFS.write("done");
        }
        else if (btn == BUTTON_3_PRESSED || btn == BUTTON_3_LONG_PRESSED)
        {
          average = marks / cntMarks;
          MFS.write(average, 2);
          if (average < 4) 
          {
            delay(1500);
            MFS.write("bad");
            digitalWrite(led1, HIGH);
            delay(250);
            digitalWrite(led1, LOW);
            delay(250);
          }
          else if (average <= 5 && average >= 4) 
          {
            delay(1500);
            MFS.write("nice");
            digitalWrite(led1, HIGH);
            digitalWrite(led2, HIGH);
            delay(250);
            digitalWrite(led1, LOW);
            digitalWrite(led2, LOW);
            delay(250);
          }
          else if (average <= 5.5 && average > 5)
          {
            delay(1500);
            MFS.write("good");
            digitalWrite(led1, HIGH);
            digitalWrite(led2, HIGH);
            digitalWrite(led3, HIGH);
            delay(250);
            digitalWrite(led1, LOW);
            digitalWrite(led2, LOW);
            digitalWrite(led3, LOW);
            delay(250);
          }
          else if (average > 5.5)
          {
            delay(1500);
            MFS.write("pro");
            digitalWrite(led1, HIGH);
            digitalWrite(led2, HIGH);
            digitalWrite(led3, HIGH);
            digitalWrite(led4, HIGH);
            delay(250);
            digitalWrite(led1, LOW);
            digitalWrite(led2, LOW);
            digitalWrite(led3, LOW);
            digitalWrite(led4, LOW);
            delay(250);
          }
        }
  }
