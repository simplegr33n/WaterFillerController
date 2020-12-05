#define ENCODER_CLK_Pin 9
#define ENCODER_DT_Pin 8
#define ENCODER_SW_Pin 7

volatile uint8_t ENCODER_PHASE;
volatile uint8_t PREV_ENCODER_PHASE;
volatile bool ENCODER_INCREASE;
volatile bool ENCODER_DECREASE;

/////////////////////////////////////////////////////////////////////////////////////////////////////////
// ///////////////                                                                                     //
// END GLOBAL VARS                                                                                     //
// ///////////////                                                                                     //
/////////////////////////////////////////////////////////////////////////////////////////////////////////

void initInputs()
{
    // Set up encoder pots and switch
    pinMode(ENCODER_CLK_Pin, INPUT);
    pinMode(ENCODER_DT_Pin, INPUT);
    pinMode(ENCODER_SW_Pin, INPUT);

    //    // Initialize Encoder interrupts
    //    cli();
    //    ENCODER_PHASE = PIND;                      // Get state of Port D
    //    PCICR |= (1 << PCIE2);                     // Pin Change Interrupt Control Register enabling Port K
    //    PCMSK2 |= (1 << PCINT21) | (1 << PCINT22); // Enable mask on PCINT21-22 to trigger interrupt on state change
    //    sei();
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////
// Input functions                                                                                     //
/////////////////////////////////////////////////////////////////////////////////////////////////////////
//// Handle Pin Change Interrupt Vector
//ISR(PCINT2_vect)
//{
//    cli();
//    PREV_ENCODER_PHASE = ENCODER_PHASE;
//    ENCODER_PHASE = PIND; // Get state of Port D
//
//    if ((ENCODER_PHASE != PREV_ENCODER_PHASE))
//    {
//        if (ENCODER_PHASE & 0b01000000 && !(PREV_ENCODER_PHASE & 0b01000000)) // if CLK pin has changed
//        {
//            if (ENCODER_PHASE & 0b00100000) // if CLK differs from DT
//            {
//                updateEncoderCounters(-1); // decrease
//                return;
//            }
//            else
//            {
//                updateEncoderCounters(1); // increase
//                return;
//            }
//        }
//
//        //  NOTE: Only using CLK changes to both keep ISR short and because higher acuity makes the cursor move to quickly in the menu
//        // setable rotary sensitivity may be a nice feature, but might best be accomplished here with a simple multiplier
//    }
//    sei();
//}
//
//void updateEncoderCounters(int changeValue)
//{
//    encoderCounter += changeValue; // only change actual encoder counter (a value which is transmitted) if not in menu/setting something
//}

void updateInputs()
{
    getButtonValues();
}

void getButtonValues()
{
    encoderSwitchValue = 0; // Encoder switch value
    if (digitalRead(ENCODER_SW_Pin) == 0)
    {
        encoderSwitchValue = 1;
    }
}
