// Defining button inputs, BTN1 will move the LED's left, and BTN3 will move right. BTN2 resets.
const int buttonPins[] = {2, 3, 4};
const int ledPins[] = {30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41};

//setup code goes here, run once
void setup() {
    // Pin definition is based on a list and in order not to use a ton of #define statements, pins are ints and so I stored them in a list based on what they are.
    Serial.begin(9600);
    for(int i = 0; i < 3; i++) {
        pinMode(buttonPins[i], INPUT);
    }

    for(int i = 0; i < 12; i++) {
        pinMode(ledPins[i], OUTPUT);
    }

    switchLEDs(HIGH);
}

//loop access from the arduino. Runs infinitely
void loop() {
    runGame();
}

void runGame() {
    static int index = 11;
    if(digitalRead(buttonPins[0]) == 1 and index != 0) {
        digitalWrite(ledPins[index], LOW);
        index--;
    }
    else if(digitalRead(buttonPins[1]) == 1) {
        switchLEDs(HIGH);
    }
    else if(digitalRead(buttonPins[2]) == 1 and index != 11) {
        digitalWrite(ledPins[index], HIGH);
        index++;
    }    
    delay(250);
}

void switchLEDs(int m) {
    if (m == HIGH) {
        for(int i = 0; i < 12; i++) {
            digitalWrite(ledPins[i], HIGH);
        }
    }
    else if (m == LOW) {
        for(int i = 0; i < 12; i++) {
            digitalWrite(ledPins[i], LOW);
        }
    }
}