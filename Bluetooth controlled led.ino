int LED = 4;
String readString;
void setup() {
    pinMode (LED, OUTPUT);

    Serial.begin(9600);
}
void loop() {
  while(Serial.available()){  //Check if there is an available byte to read 
    delay(50);                //Delay added to make thing stable 
    char c = Serial.read();   //Conduct a serial read 
    readString+=c;
  }

  if(readString.length() > 0) {
    Serial.println(readString);
    if(readString == "ON"){
       LED_on();
    }

    if(readString == "OFF"){
       LED_off();
    }
    

    readString = "";
  }
}
void LED_on ()
{
   digitalWrite(LED, HIGH);
}
void LED_off ()
{
   digitalWrite(LED, LOW);
}

