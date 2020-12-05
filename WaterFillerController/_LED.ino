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
    analogWrite(BLUE_LED_PIN, 255);
    analogWrite(GREEN_LED_PIN, 255);
    delay(300);
    analogWrite(RED_LED_PIN, 0);
    analogWrite(BLUE_LED_PIN, 0);
    analogWrite(GREEN_LED_PIN, 0);
}

void lightRedLED()
{
    analogWrite(RED_LED_PIN, 255);
}

void killRedLED()
{
    digitalWrite(RED_LED_PIN, LOW);
}

void lightGreenLED()
{
    analogWrite(GREEN_LED_PIN, 255);
}

void killGreenLED()
{
    digitalWrite(GREEN_LED_PIN, LOW);
}

void lightBlueLED()
{
    digitalWrite(BLUE_LED_PIN, HIGH);
}

void killBlueLED()
{
    digitalWrite(BLUE_LED_PIN, LOW);
}

void turnOffLED()
{
    digitalWrite(RED_LED_PIN, LOW);
    digitalWrite(BLUE_LED_PIN, LOW);
    digitalWrite(GREEN_LED_PIN, LOW);
}
