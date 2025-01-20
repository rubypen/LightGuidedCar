//DO NOT TOUCH THESE 3 VARIABLES
const int SETUP_TIME = 5000;
const int AUTONOMOUS_TIME = 15000;
const int STOP_TIME = 2000;




//------------------------MOTORS - RWD----------------------------
//    10    11     5     6
int motorF1, motorB1, motorF2, motorB2;




//--------------------------BUTTONS------------------------------
//     3                    b4: A5    A1
int button1, button2;//remove A1 && A5
bool b1Pressed = false, b2Pressed = false;




//----------------------LED COMMUNICATOR-------------------------
//  13
int led;




//--------------------------SENSORS------------------------------
//     8    9
int trigger, echo;




//   A2    A3
int flex1, flex2;




//    A1    A4    A0      A5  
int photo1, photo2, photo3, photo4;




//==========================SETUP + LOOP=========================
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
 
  //--------------------motors-------------------
  motorF1 = 10; motorB1 = 11;
  motorF2 = 5; motorB2 = 6;
 
  //-------------------buttons-------------------
  button1 = 3;
 
  //-------------------sensors--------------------
  photo1 = A1; photo2 = A4; photo3 = A0; photo4 = A5;
  flex1 = A2; flex2 = A3;
 
  //---------------------led----------------------
  led = 13;
 
  //-------------------pinModes-------------------
  pinMode(motorF1, OUTPUT);
  pinMode(motorB1, OUTPUT);
  pinMode(motorF2, OUTPUT);
  pinMode(motorB2, OUTPUT);
 
  pinMode(button1, INPUT); pinMode(button2, INPUT);
 
  pinMode(flex1, INPUT); pinMode(flex2, INPUT);
 
  pinMode(photo1, INPUT);pinMode(photo2, INPUT);
  pinMode(photo3, INPUT);pinMode(photo4, INPUT);
 
 
  pinMode(led, OUTPUT);
}
//============================================================
//DO NOT WRITE CODE IN THE LOOP METHOD.
void loop() {  
  //turnL();
  //motorForward();
  //autonomousMode();
  //teleOpMode();
  //motorOff();
  long mil = millis();
  if(mil < 20000)
    autonomousMode();
  else if(mil < 22000)
    motorOff();
  else
    teleOpMode();
  
  /*//DO NOT TOUCH THIS CODE
  long mil = millis();
  if(mil<SETUP_TIME)
  {
    //LEAVE THIS BLANK
  }
  else if(mil<AUTONOMOUS_TIME+SETUP_TIME)
  {
    autonomousMode();
  }
  else if(mil<AUTONOMOUS_TIME+SETUP_TIME+STOP_TIME)
  {
    fullStop();
  }
  else
  {
    teleOpMode();
  }*/
}
//============================================================




//WRITE CODE IN HERE:  YOUR AUTONOMOUS CODE GOES IN HERE.  PART 1 OF RACE
void autonomousMode(){
  long sec = millis();  //250;//60 fourthSeconds
  long num = 5100;


  Serial.println("IM IN AUTON");
 
  if(sec <  1000+5000)
    motorOff();
  else if(sec < 1500+num)
    motorForward(255);
  else if(sec < 1700+num)
    motorOff();
  else if(sec < 1900+num)
    turnR(150);
  else if(sec < 2300+num)
    motorForward(255);
  else if(sec < 2500+num)
    motorOff();
  else if(sec < 2700+num)
    turnR(150);
  else if(sec < 3400+num)
    motorForward(255);
  else if(sec < 3600+num)
    motorOff();
  else if(sec < 3800 + num)
    turnL(200);/*
  else if(sec < 25)
    motorForward();
  else if(sec < 26)
    motorOff();
  else if(sec < 26.5)
    turnL();
  else if(sec < 32)
    motorForward();
  else if(sec < 33)
    motorOff();
  else if(sec < 36)
    turnL();
  else if(sec < 38)
    motorForward();
  else if(sec < 39)
    motorOff();
  else if(sec < 41)
    turnL();
  else if(sec < 44)
    motorForward();
  else if(sec < 45)
    motorOff();
  else if(sec < 45.5)
    turnR();
  else if(sec < 46)
    motorForward();
  else if(sec < 46.5)
    motorOff();
  else if(sec < 47)
    turnR();
  else if(sec < 49)
    motorForward();
  else if(sec < 50)
    motorOff();
  else if(sec < 51)
    turnL();
  else if(sec < 52)
    motorForward();
  else if(sec < 53)
    motorOff();
  else if(sec < 53.5)
    turnL();
  else if(sec < 54)
    motorForward();
  else if(sec < 54.5)
    motorOff();
  else if(sec < 55)
    turnL();
  else if(sec < 55.5)
    motorForward();
  else if(sec < 56)
    motorOff();
  else if(sec < 56.5)
    turnR();
  else if(sec < 57)
    motorForward();
  else if(sec < 57.5)
    motorOff();
  else if(sec < 58)
    turnR();
  else if(sec < 60)
    motorForward();
  else if(sec < 61)
    motorOff();
  else if(sec < 61.5)
    turnR();
  else if(sec < 62)
    motorForward();
  else if(sec < 62.5)
    motorOff();
  else if(sec < 63)
    turnR();
  else if(sec < 63.5)
    motorForward();
  else if(sec < 64)
    motorOff();
  else if(sec < 64.5)
    turnL();
  else if(sec < 65.5)
    motorForward();
  else if(sec < 66)
    motorOff();
  else if(sec < 66.5)
    turnL();
  else if(sec < 67.5)
    motorForward();*/
  else
    motorOff();
 
}
//WRITE CODE IN HERE:  YOUR TELEOP CODE GOES IN HERE.  PART 2 OF RACE
//you MUST write this method
void teleOpMode()
{
  Serial.println("IM IN TELEOP");
  int photoState1= analogRead(photo1);
  int photoState2 = analogRead(photo2);
  int photoState3 = analogRead(photo3);
  int photoState4 = analogRead(photo4);
 
  int photoScale1 = map(photoState1, 54, 974, 0, 255);
  int photoScale2= map(photoState2, 54, 974, 0, 255);
  int photoScale3= map(photoState3, 54, 974, 0, 255);
  int photoScale4 = map(photoState4, 54, 974, 0, 255);
 
  Serial.println(photoScale1);
  /*Serial.println(photoScale2);
  Serial.println(photoScale3);
  Serial.println(photoScale4);*/
 
  if(photoScale1 > 40)
  {
    digitalWrite(led, HIGH);
    motorBackward(255);
  }
  else if(photoScale2 > 40)
  {
    digitalWrite(led, HIGH);
    turnL(150);
  }
  else if(photoScale3 > 40)
  {
    digitalWrite(led, HIGH);
    turnR(150);
  }
  else if(photoScale4 > 40)
  {
    motorForward(255);
    digitalWrite(led, HIGH);    
  }
  else
  {
    ledOff();
    motorOff();
  }
}
//WRITE CODE IN HERE:  YOU SHOULD MAKE EVERY MOTOR STOP
//you MUST write this method
void fullStop(){
  analogWrite(motorF1, 0);
  analogWrite(motorB1, 0);
  analogWrite(motorF2, 0);
  analogWrite(motorB2, 0);
}




//Feel free to add more methods.




//----------------------------MOTOR METHODS-----------------------
void motorOff()
{
  analogWrite(motorF1, 0);
  analogWrite(motorB1, 0);
  analogWrite(motorF2, 0);
  analogWrite(motorB2, 0);
}
void motorForward(int pow)
{
  analogWrite(motorF1, 0);
  analogWrite(motorB1, pow);
  analogWrite(motorF2, 0);
  analogWrite(motorB2, pow);
}
void motorBackward(int pow)
{
  analogWrite(motorF1, pow);
  analogWrite(motorB1, 0);
  analogWrite(motorF2, pow);
  analogWrite(motorB2, 0);
}
void turnL(int pow)
{
  analogWrite(motorF1, 0);
  analogWrite(motorB1, pow);
}
void turnR(int pow)
{  
  analogWrite(motorF2, 0);
  analogWrite(motorB2, pow);
}




//-------------------------MISCELLANEOUS--------------------------
//LED
void ledOn()
{
  digitalWrite(led, 1);
}
void ledOff()
{
  digitalWrite(led, 0);
}








//PHOTO
void nightLight()
{
  int photoState = analogRead(photo1);
  int photoScale = map(photoState, 54, 974, 0, 255);
  Serial.println(photoScale);
  if(photoScale > 125)
    digitalWrite(led, HIGH);
  else
    digitalWrite(led, LOW);
}




void handlePhoto()
{
  int photoState = analogRead(photo1);
  Serial.print("photoState = ");
  Serial.println(photoState);
}




void handleFlex()
{
  int flexState = analogRead(flex1);
  Serial.print("flexState = ");
  Serial.println(flexState);
}
