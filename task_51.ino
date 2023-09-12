const byte BUTTON_PIN = 2;
const byte PULL_UP = INPUT_PULLUP;

byte buttonState = 0;
float startTime = 0;
float endTime = 0;
float elapsedTime = 0;

bool buttonPressed = false;

void setup()
{
  pinMode(BUTTON_PIN, PULL_UP);
  Serial.begin(9600);
}

void loop()
{
  buttonState = digitalRead(BUTTON_PIN);
  buttonState = 1 - buttonState;
  
  if (buttonState && !buttonPressed)
  {
    buttonPressed = true;
    startTime = millis();
  }
  
  if (!buttonState && buttonPressed)
  {
    buttonPressed = false;
    endTime = millis();
    elapsedTime = (endTime - startTime) / 1000;
    Serial.print("Time = ");
    Serial.print(elapsedTime);
    Serial.println(" S");
  }
}
