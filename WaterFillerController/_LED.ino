#define GREEN_LED_PIN 4
#define RED_LED_PIN 3
#define BLUE_LED_PIN 2

void initIndicatorLeds()
{
    pinMode(GREEN_LED_PIN, OUTPUT);
    pinMode(BLUE_LED_PIN, OUTPUT);
    pinMode(RED_LED_PIN, OUTPUT);

    ledStartupSequence();
}

void ledStartupSequence()
{
    analogWrite(RED_LED_PIN, 255);
    delay(200);
    analogWrite(RED_LED_PIN, 0);
    delay(200);
    analogWrite(BLUE_LED_PIN, 255);
    delay(200);
    analogWrite(BLUE_LED_PIN, 0);
    delay(200);
    analogWrite(GREEN_LED_PIN, 255);
    delay(200);
    analogWrite(GREEN_LED_PIN, 0);
    delay(200);
    analogWrite(BLUE_LED_PIN, 255);
    analogWrite(GREEN_LED_PIN, 255);
    analogWrite(RED_LED_PIN, 255);
    delay(200);
}

void lightRedLED()
{
    analogWrite(RED_LED_PIN, 255);
}

void lightGreenLED()
{
    analogWrite(GREEN_LED_PIN, 255);
}

void lightBlueLED()
{
    analogWrite(BLUE_LED_PIN, 255);
}

void turnOffLED()
{
    digitalWrite(RED_LED_PIN, LOW);
    digitalWrite(BLUE_LED_PIN, LOW);
    digitalWrite(GREEN_LED_PIN, LOW);
}
