float val_thr = 40;
float ir_val;
int ir_pin = 3;
int motor_frontA = 12;
int PWM_frontA = 3;
int motor_frontB = 13;
int PWM_frontB = 11;

int motor_A = 6;
int motor_B = 5;
// 0 is left, 1 is right
int motorDirection = 0;
int buttonPin = 2;
int buttonState = 0; 
int lastButtonState = 0; 

int first_gap = 0;
unsigned long gap_time =600;
unsigned long first_time;
unsigned long curr_time;

// invert motor direction
int check_dir(int curr_butt, int last_butt, int motor_dir){
  if ((curr_butt == HIGH) && (curr_butt != last_butt)){
      motor_dir = !motor_dir;
    }
  return motor_dir;
}

//dir = 0 then left, else then right
void move_side(int dir){
  if(dir == 0){
    analogWrite(motor_A, 100);
    analogWrite(motor_B, 0);
    delay(50);
    analogWrite(motor_A, 0);
    analogWrite(motor_B, 0);
    delay(10);
  }

  else{
    analogWrite(motor_A, 0);
    analogWrite(motor_B, 100);
    delay(50);
    analogWrite(motor_B, 0);
    analogWrite(motor_A, 0);
    delay(10);
  }
}

//dir = 0 is forward, else then backwards
void move_front(int dir){
  if(dir == 0){
    digitalWrite(motor_frontA, HIGH);
    analogWrite(PWM_frontA, 80);
    analogWrite(PWM_frontB, 80);
    delay(20);
    digitalWrite(motor_frontA, LOW);
    analogWrite(PWM_frontA, 0);
    analogWrite(PWM_frontB, 0);
  }

  else{
    digitalWrite(motor_frontB, HIGH);
    analogWrite(PWM_frontA, 80);
    analogWrite(PWM_frontB, 80);
    delay(20);
    digitalWrite(motor_frontB, LOW);
    analogWrite(PWM_frontA, 0);
    analogWrite(PWM_frontB, 0);
  }
}


void setup() {
  Serial.begin(9600);
  pinMode(ir_pin, INPUT);
  pinMode(buttonPin, INPUT);

  pinMode(motor_frontA, OUTPUT);
  pinMode(motor_frontB, OUTPUT);
  pinMode(PWM_frontA, OUTPUT);
  pinMode(PWM_frontB, OUTPUT);

  pinMode(motor_A, OUTPUT);
  pinMode(motor_B, OUTPUT);
}

void loop() {
  //take readings
  buttonState = digitalRead(buttonPin);
  ir_val = analogRead(ir_pin);
  Serial.println(ir_val);
  Serial.println(motorDirection);
  motorDirection = check_dir(buttonState, lastButtonState, motorDirection);
  lastButtonState = buttonState;
  Serial.println(ir_val);


  //IF gap exist, decides if theres a gao and move forward
  if(ir_val <= val_thr){

    //Starts recording time between gap if ir_val<(val_thr-3)
    if(ir_val <= (val_thr - 3)){
    //Records time when gap first detected
      if(first_gap == 0){
        first_time = millis();
        first_gap = 1;
      }  

      else if(first_gap == 1){
        curr_time = millis();

        if((curr_time - first_time) > gap_time){
          move_front(0);
        }

        else{
          //lastButtonState = buttonState;
          move_side(motorDirection);
        }
      }
    }

    else{
      move_front(0);
      move_side(motorDirection);
    }


  }

  //Move sideways if theres a wall
  else if((ir_val > val_thr) && (ir_val < (val_thr + 15))){
    first_gap = 0;
    move_side(motorDirection);
  }

  //Moves back when too close to the wall
  else{
    first_gap = 0;
    move_side(motorDirection);
    move_front(1);
  }
}
