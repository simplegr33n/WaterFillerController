/////////////////////////////////////////////////////////////////////////////////////////////////////////
// Hardware Inputs                                                                                     //
/////////////////////////////////////////////////////////////////////////////////////////////////////////
int encoderSwitchValue;
volatile int encoderCounter = 0;

unsigned long lastEncoderPress;

/////////////////////////////////////////////////////////////////////////////////////////////////////////
// ///////////////                                                                                     //
// END GLOBAL VARS                                                                                     //
// ///////////////                                                                                     //
/////////////////////////////////////////////////////////////////////////////////////////////////////////

void setup()
{
    Serial.begin(115200);
    initIndicatorLeds(); // init indicator LEDS
    initOLED();          // init display
    initInputs();        // init transimitter inputs
}

void loop()
{
    lightRedLED();

    updateInputs(); // get updated input states

    if (encoderSwitchValue == 1 && (millis() - lastEncoderPress > 500))
    {
        lastEncoderPress = millis();

        // do stuff

        return;
    }
}