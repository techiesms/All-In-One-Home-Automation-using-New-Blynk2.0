
// Fill-in information from your Blynk Template here
#define BLYNK_TEMPLATE_ID "ID"
#define BLYNK_DEVICE_NAME "NAME"


#define BLYNK_FIRMWARE_VERSION        "0.1.0"

#define BLYNK_PRINT Serial
//#define BLYNK_DEBUG

#define APP_DEBUG 

// Define Relay Pins
#define r1 15
#define r2 2
#define r3 4
#define r4 22

// Define Switch Pins
#define s1 32
#define s2 35
#define s3 34
#define s4 39

// Pins of Fan Regulator Knob
#define f1  27
#define f2  14
#define f3  12
#define f4  13

// Pins of Relay (Fan Speed Control)
#define Speed1 21
#define Speed2 19
#define Speed4 18

bool speed1_flag = 1;
bool speed2_flag = 1;
bool speed3_flag = 1;
bool speed4_flag = 1;
bool speed0_flag = 1;

// Switch Flags
bool SWITCH5_FLAG = 1;
bool SWITCH6_FLAG = 1;
bool SWITCH7_FLAG = 1;
bool SWITCH8_FLAG = 1;

// Default Relay State
bool relay1 = LOW;
bool relay2 = LOW;
bool relay3 = LOW;
bool relay4 = LOW;


// Uncomment your board, or configure a custom board in Settings.h
//#define USE_WROVER_BOARD

#include "BlynkEdgent.h"


BLYNK_WRITE(V0)
{
  int fan_speed = param.asInt(); // assigning incoming value from pin V0 to a variable
  Serial.print("FAN VALUE -");Serial.print(fan_speed);Serial.println("-");
  if (fan_speed == 0)
  {
    speed0();
  }
  if (fan_speed == 1)
  {
    speed1();
  }
  if (fan_speed == 2)
  {
    speed2();
  }
  if (fan_speed == 3)
  {
    speed3();
  }
  if (fan_speed == 4)
  {
    speed4();
  }
}

BLYNK_WRITE(V1)
{
  int pinValue = param.asInt(); // assigning incoming value from pin V1 to a variable
  relay1 = pinValue;
  digitalWrite(r1 , pinValue);
  // process received value
}

BLYNK_WRITE(V2)
{
  int pinValue = param.asInt(); // assigning incoming value from pin V1 to a variable
  relay2 = pinValue;
  Serial.print("Relay2 - ");Serial.println(pinValue);
  digitalWrite(r2 , pinValue);
  // process received value
}

BLYNK_WRITE(V3)
{
  int pinValue = param.asInt(); // assigning incoming value from pin V1 to a variable
  relay3 = pinValue;
  Serial.print("Relay3 - ");Serial.println(pinValue);
  digitalWrite(r3 , pinValue);
  // process received value
}

BLYNK_WRITE(V4)
{
  int pinValue = param.asInt(); // assigning incoming value from pin V1 to a variable
  relay4 = pinValue;
  digitalWrite(r4 , pinValue);
  // process received value
}


void setup()
{
  Serial.begin(115200);
  delay(100);

  pinMode(s1, INPUT_PULLUP);
  pinMode(s2, INPUT_PULLUP);
  pinMode(s3, INPUT_PULLUP);
  pinMode(s4, INPUT_PULLUP);

  pinMode(f1, INPUT_PULLUP);
  pinMode(f2, INPUT_PULLUP);
  pinMode(f3, INPUT_PULLUP);
  pinMode(f4, INPUT_PULLUP);

  pinMode(r1, OUTPUT);
  pinMode(r2, OUTPUT);
  pinMode(r3, OUTPUT);
  pinMode(r4, OUTPUT);

  pinMode(Speed1, OUTPUT);
  pinMode(Speed2, OUTPUT);
  pinMode(Speed4, OUTPUT);

  digitalWrite(r1, 0);
  digitalWrite(r2, 0);
  digitalWrite(r3, 0);
  digitalWrite(r4, 0);

  BlynkEdgent.begin();
}

void loop()
{
  BlynkEdgent.run();
  swfeedback();
}
