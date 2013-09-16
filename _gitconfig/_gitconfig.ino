/*
  EGG eVENDING MACHINE CODE FOR Y AXIS TRIAL 1 
 CC NARRENCER , TILAK , CPDO , DENNIS ASHOK
 
 */ 
int xr1 = 36;// x fwd
int xr2 = 34;
int xr3 = 32;// x rev
int xr4 = 30;

int yr1 = 28;// y relay fwd
int yr2 = 26;
int yr3 = 24;// y rev
int yr4 = 22;


int gr1 = 44; // gripper fwd 
int gr2 = 42; 
int gr3 = 40; // gripper rev
int gr4 = 38; 

// the setup routine runs once when you press reset:
void setup() { 
  Serial.begin(9600); 
  // initialize the digital pin as an output.
  pinMode(yr1, OUTPUT);
  pinMode(yr2, OUTPUT);
  pinMode(yr3, OUTPUT);
  pinMode(yr4, OUTPUT);
  // x axis innitilaization 
  pinMode(xr1, OUTPUT);
  pinMode(xr2, OUTPUT);
  pinMode(xr3, OUTPUT);
  pinMode(xr4, OUTPUT);

 }

// the loop routine runs over and over again forever:
void loop() {
  // Assuming the gripper is going to be on the Left First 
// Write the left proximity code   
  int left_p_grip1 = analogRead(A10); //left position gripper proximity sensor
  float left_p_grip = left_p_grip1 * (5.0 / 1023.0);
  Serial.println(left_p_grip);   
  
// Y axis move down   
// The sensor inside the gripper is sensing looking for a egg tray
  int gripper_egg1 = analogRead(A12); // gripper proximity sensor
  float gripper_egg = gripper_egg1 * (5.0 / 1023.0);
  Serial.println(gripper_egg);
 
 
  if (gripper_egg>3)
  {
  digitalWrite(yr3, HIGH);   // DOWN TURN ON  
  digitalWrite(yr4,HIGH);
  delay(300);               //
  digitalWrite(yr3, LOW);   // DOWN TURN OFF
  digitalWrite(yr4,LOW);
  delay(500);
  }
 
 
 // Initilise and grip the egg 
 else 
 { // timing to be tuned better 
  digitalWrite(yr3, LOW);   // DOWN TURN OFF
  digitalWrite(yr4,LOW);
  delay(1000);
  digitalWrite(gr3, HIGH);  // inverse TURN ON
  digitalWrite(gr4, HIGH);
  delay(6000);               // wait for a second
  digitalWrite(gr3, LOW);  // REVERSE TURN OFF
  digitalWrite(gr4, LOW);
  delay(4000);               // wait for a second
 }
 
 
 
  /*
  digitalWrite(yr1, HIGH);  // REVERSE TURN ON
  digitalWrite(yr2, HIGH);
  delay(3000);               // wait for a second
  digitalWrite(yr1, LOW);  // REVERSE TURN ON
  digitalWrite(yr2, LOW);
  delay(100);               // wait for a second
  */
} 
