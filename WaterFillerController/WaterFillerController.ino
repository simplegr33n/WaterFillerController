int CONTROLLER_STATE = 0; // 0 = Booting, 1 = Ready, 2 = Filling, 3 = Issue
int ISSUE_STATE = 1;      // 1 = issue (init with this), 0 = clear.
// for demo
unsigned long lastDemoStateShift;

/////////////////////////////////////////////////////////////////////////////////////////////////////////
// Hardware Inputs                                                                                     //
/////////////////////////////////////////////////////////////////////////////////////////////////////////
int encoderSwitchValue;
volatile int encoderCounter = 0;

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
    initInputs();        // init transimitter input
}

void loop()
{
    // DEBUG DEMO "stateSwitcher()":
    stateSwitcher();

    updateInputs(); // get updated input states

    if (ISSUE_STATE == 1)
    {
        stopFill(); // Issue state
    }
    else
    {
        lightGreenLED(); // Non-issue state

        if (encoderSwitchValue == 1)
        {
            runFill(); // Filling state
        }
        else
        {
            killRedLED();
            killBlueLED();
        }
    }
}

void stateSwitcher()
{
    if (millis() - lastDemoStateShift > 15000)
    {

        lastDemoStateShift = millis();

        if (ISSUE_STATE == 0)
        {
            ISSUE_STATE = 1;
        }
        else
        {
            ISSUE_STATE = 0;
        }
    }
}

void stopFill()
{
    killBlueLED();
    killGreenLED();
    lightRedLED();
}

void runFill()
{
    lightBlueLED();
}
