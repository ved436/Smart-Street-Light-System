#include <LiquidCrystal.h>

LiquidCrystal lcd(3, 4, 5, A0, A1, A2);

#define LDR_PIN 2
#define TRIG_PIN 7
#define ECHO_PIN 6

#define LED1_PIN 9
#define LED2_PIN 10
#define LED3_PIN 11
#define LED4_PIN 12
#define LED5_PIN 13

unsigned long lastDetectionTime = 0;

void setup()
{
  pinMode(LDR_PIN, INPUT);

  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  pinMode(LED1_PIN, OUTPUT);
  pinMode(LED2_PIN, OUTPUT);
  pinMode(LED3_PIN, OUTPUT);
  pinMode(LED4_PIN, OUTPUT);
  pinMode(LED5_PIN, OUTPUT);

  Serial.begin(9600);

  lcd.begin(16, 2);
  lcd.clear();
  lcd.print("Smart Street");
  lcd.setCursor(0, 1);
  lcd.print("Light System");
  delay(2000);
  lcd.clear();
}

void loop()
{
  int ldrState = digitalRead(LDR_PIN);

  // DAYTIME
  if (ldrState == LOW)
  {
    digitalWrite(LED1_PIN, LOW);
    digitalWrite(LED2_PIN, LOW);
    digitalWrite(LED3_PIN, LOW);
    digitalWrite(LED4_PIN, LOW);
    digitalWrite(LED5_PIN, LOW);

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Mode: DAY");
    lcd.setCursor(0, 1);
    lcd.print("Lights: OFF");

    Serial.println("DAYTIME - All Lights OFF");

    delay(200);
    return;
  }

  // NIGHTTIME
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);

  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);

  digitalWrite(TRIG_PIN, LOW);

  long duration = pulseIn(ECHO_PIN, HIGH);

  float distance = duration * 0.034 / 2;

  Serial.print("NIGHT | Distance = ");
  Serial.print(distance);
  Serial.println(" cm");

  // Base Street Lights
  digitalWrite(LED1_PIN, HIGH);
  digitalWrite(LED5_PIN, HIGH);

  if (distance <= 20)
  {
    lastDetectionTime = millis();

    digitalWrite(LED2_PIN, HIGH);
    digitalWrite(LED3_PIN, HIGH);
    digitalWrite(LED4_PIN, HIGH);

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Mode: NIGHT");
    lcd.setCursor(0, 1);
    lcd.print("Vehicle: YES");

    Serial.println("Vehicle Detected -> All Lights ON");
  }
  else
  {
    if (millis() - lastDetectionTime < 3000)
    {
      digitalWrite(LED2_PIN, HIGH);
      digitalWrite(LED3_PIN, HIGH);
      digitalWrite(LED4_PIN, HIGH);

      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Mode: NIGHT");
      lcd.setCursor(0, 1);
      lcd.print("Vehicle: YES");
    }
    else
    {
      digitalWrite(LED2_PIN, LOW);
      digitalWrite(LED3_PIN, LOW);
      digitalWrite(LED4_PIN, LOW);

      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Mode: NIGHT");
      lcd.setCursor(0, 1);
      lcd.print("Vehicle: NO");

      Serial.println("No Vehicle -> Only End Lights ON");
    }
  }

  delay(200);
}
