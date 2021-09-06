// Katelyn DePaula made for Aviel

//These correspond to the pins on NodeMCU
//these are the led strip colors
int red = 5;   //D1 in Node MCU
int blue = 0;   //D3
int green = 16; //D0

int blueButton = 2; // D4
int redButton = 14; //D5
int greenButton = 12; //D6

int blueState = LOW;
int lastBlueState;
int currBlueState;

int redState;
int lastRedState;
int currRedState = LOW;

int greenState;
int lastgreenState;
int currgreenState = LOW;

void setup()
{
  // Sets up pins
  pinMode (red, OUTPUT);
  pinMode (green, OUTPUT);
  pinMode (blue, OUTPUT);

  pinMode (redButton, INPUT_PULLUP);
  pinMode (greenButton, INPUT_PULLUP);
  pinMode(blueButton, INPUT_PULLUP);

  // Opens serial monitor at 115200 baud
  Serial.begin(115200);
  Serial.println("Setup runs...");
  currBlueState = digitalRead(blueButton);
  currRedState = digitalRead(redButton);
  currgreenState = digitalRead(greenButton);
}

void loop()
{

  //RED LED

  lastRedState = currRedState;      // save the last state
  currRedState = digitalRead(redButton); // read new state

  if (lastRedState == HIGH && currRedState == LOW) {
    Serial.println("The button is pressed");

    // toggle state of LED
    redState = !redState;

    // control LED arccoding to the toggled state
    digitalWrite(red, redState);
  }

  //BLUE LED

  lastBlueState = currBlueState;      // save the last state
  currBlueState = digitalRead(blueButton); // read new state

  if (lastBlueState == HIGH && currBlueState == LOW) {
    Serial.println("The button is pressed");

    // toggle state of LED
    blueState = !blueState;

    // control LED arccoding to the toggled state
    digitalWrite(blue, blueState);
  }

  //green LED
  lastgreenState = currgreenState;      // save the last state
  currgreenState = digitalRead(greenButton); // read new state

  if (lastgreenState == HIGH && currgreenState == LOW) {
    Serial.println("The button is pressed");

    // toggle state of LED
    greenState = !greenState;

    // control LED arccoding to the toggled state
    digitalWrite(green, greenState);
  }

  delay(100);
}
