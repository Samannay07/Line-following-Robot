//digital read to read high and low from ir sensors
//digital write to 
//turns ke liye maybe use pwm pins D5 D6
//ENA=Motor speed of motor A, ENB= Motor speed of motor B;






int left_sensor=2;
int leftc_sensor=3;
int rightc_sensor=4;
int right_sensor=5;

int IN1=6;
int IN2=7;
int IN3=8;
int IN4=9;

int ENA=10;
int ENB=11;



void setup() {
  pinMode(left_sensor,INPUT);
  pinMode(leftc_sensor,INPUT);
  pinMode(rightc_sensor,INPUT);
  pinMode(right_sensor,INPUT);

  pinMode(IN1,OUTPUT);
  pinMode(IN2,OUTPUT);
  pinMode(IN3,OUTPUT);
  pinMode(IN4,OUTPUT);

  pinMode(ENA,OUTPUT);
  pinMode(ENB,OUTPUT);

}

void loop() {
  int l=digitalRead(left_sensor);//left ir sensor input
  int lc=digitalRead(leftc_sensor);//left centre sensor input
  int rc=digitalRead(rightc_sensor);//right centre sensor input
  int r=digitalRead(right_sensor);//left sensor input

  //*********WHITE LINE FOLLOWER
  if(l==LOW && r==LOW) 
  {
     //MOVE FORWARD
      if (lc==HIGH && rc==HIGH)
          {
            forward();
          }
    //LEFT TURN
      else if(lc==HIGH && rc==LOW)
        {
          leftturn();
        }
    //RIGHT TURN
      else if(lc==LOW && rc==HIGH)
        {
          rightturn();
        }
  //CROSSROADS or circle
      else if(lc==LOW && rc==LOW)
        {
          rightturn();
        }

  //SHARP LEFT sharp right and reverse baaki hai
      
    }

  //********BLACK LINE FOLLOWER
  else if(l==HIGH && r==HIGH)
  {  //MOVE FORWARD
    if (lc==LOW && rc==LOW)
        {
          forward();
        }
      //LEFT TURN
    else if(lc==LOW && rc==HIGH)
      {
        leftturn();
      }
      //RIGHT TURN
    else if(lc==HIGH && rc==LOW)
      {
        rightturn();
      }
      //CROSSROADS or circle
    else if(lc==HIGH && rc==HIGH)
      {
        rightturn();
      }

//SHARP LEFT sharp right and reverse baaki hai, but sharp turn kiya to edge follower mess up hoga
  
  
  }

  //*******RIGHT BLACK EDGE FOLLOWER
  else if(l==HIGH && r==LOW)
  {
    if(lc==LOW && rc==LOW)
    {
      forward();
    }
    else if(lc==HIGH && rc==LOW)
    {
      rightturn();
    }
    else if(lc==HIGH && rc==HIGH)
    {
      rightturn();
    }
  }

  else if(l==LOW && r==HIGH)
  {
    if(lc==LOW && rc==LOW)
    {
      forward();
    }
    else if(lc==LOW && rc==HIGH)
    {
      leftturn();
    }
    else if(lc==HIGH && rc==HIGH)
    {
      leftturn();
    }
  }
  
  else
  {
    stopmotor();
  }
}


//FUNCTIONS

void forward() {
  analogWrite(ENA, 150);
  analogWrite(ENB, 150);

  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void leftturn() {
  analogWrite(ENA, 100);
  analogWrite(ENB, 150);

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void rightturn() {
  analogWrite(ENA, 150);
  analogWrite(ENB, 100);

  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

void stopmotor() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}