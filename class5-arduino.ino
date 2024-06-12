#define ENA 13
#define IN1 11
#define IN2 10

int motor_pwm;
void drive_motor_control(int direction, int pwm)
{
  switch(direction)
  {
    case 1:      // 전진 모터 구동
          digitalWrite(IN1, HIGH);
          digitalWrite(IN2, LOW);
          analogWrite(ENA, pwm);
          break;
    case 0:     // 정지
          digitalWrite(IN1, LOW);
          digitalWrite(IN2, LOW);
          analogWrite(ENA, 0);
          break;
    case -1:   //후진 모터 구동
          digitalWrite(IN1, LOW);
          digitalWrite(IN2, HIGH);
          analogWrite(ENA, pwm);
          break;
  }
}

void serial_com(void)
{
  String Serial_Data_String;
  String Pwm_Data_String;
  int index_s, index_e;
  index_s = index_e = 0;
  if(Serial.available() <= 0) return;
  Serial_Data_String = Serial.readStringUntil("\n");
  
  index_s = Serial_Data_String.indexOf("#");
  index_e = Serial_Data_String.indexOf("*");

  //Serial.println(index_s);
  //Serial.println(index_e);

  if((index_s == -1) || (index_e == -1)) 
  {
    //Serial.println("NO Protocol");
    return;
  }
  else
  {
    if(Serial_Data_String.charAt(2) == 'M') 
    {
       if(Serial_Data_String.indexOf("0", 3) == 4)
       {
          Pwm_Data_String = Serial_Data_String.substring(6, index_e - 1);
          //Serial.println(Pwm_Data_String);
          motor_pwm == Pwm_Data_String.toInt();
          drive_motor_control(0, motor_pwm);
       }
       if(Serial_Data_String.indexOf("1", 3) == 4)
       {
          Pwm_Data_String = Serial_Data_String.substring(6, index_e - 1);
          //Serial.println(Pwm_Data_String);
          motor_pwm == Pwm_Data_String.toInt();
          drive_motor_control(1, motor_pwm);
       }
       if((Serial_Data_String.indexOf("-", 3) == 4) && (Serial_Data_String.indexOf("1", 4) == 5))
       {
          Pwm_Data_String = Serial_Data_String.substring(7, index_e - 1);
          //Serial.println(Pwm_Data_String);
          motor_pwm == Pwm_Data_String.toInt();
          drive_motor_control(-1, motor_pwm);
       }
          
    }   
  }
}

void setup() {
  // put your setup code here, to run once:
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  serial_com(); 
  drive_motor_control(1, 200);
}
