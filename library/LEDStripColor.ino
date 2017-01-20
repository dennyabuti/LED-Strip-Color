int randNumber = 0;
int green = 7;
int red = 6;
int blue = 5;

int ind = 0;
String inputString = "";
int rgb[3];
void setup() {
  
  pinMode(green, OUTPUT);
  pinMode(red, OUTPUT);
  pinMode(blue, OUTPUT);
  Serial.begin(9600);
  randomSeed(analogRead(0));
}

void loop() {
  // Example input [255,255,255] 
  while(Serial.available() > 0){
    char inChar = (char)Serial.read();
    if(inChar == '[') {
      //reset values
      inputString ="";
      ind = 0;
    } else if(inChar == ','){
      rgb[ind] = inputString.toInt();
      inputString ="";
      ind++;
    } else if( inChar == ']'){
      rgb[ind] = inputString.toInt();
      inputString ="";
      ind++;
      Serial.println("Turning on light");
    }else {
      inputString += inChar;
    }
  }
  
  analogWrite(red, rgb[0]);
  analogWrite(green, rgb[1]);
  analogWrite(blue, rgb[2]);
        
}
