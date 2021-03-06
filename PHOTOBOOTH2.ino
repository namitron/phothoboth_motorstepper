/*
  Simple example for receiving
  
  https://github.com/sui77/rc-switch/
*/

#include <RCSwitch.h>
#include <AccelStepper.h> 
#define dirPin 4 // pin yang terhubung ke DIR+ motor driver
#define stepPin 5 // pin yang terhubung ke PUL+ motor driver
AccelStepper stepper = AccelStepper(1, stepPin, dirPin);
#define stepsPerRevolution 4000 // sesuaikan dengan settingan SW1-SW3 pada modul motor driver
RCSwitch mySwitch = RCSwitch();
int arah = 0;

void setup() {
  Serial.begin(9600);
  mySwitch.enableReceive(0);  // Receiver on interrupt 0 => that is pin #2
  pinMode(13, OUTPUT);

}

void loop() {
  if (mySwitch.available()) {
    

    Serial.println(mySwitch.getReceivedValue());
    mySwitch.resetAvailable();
  }
  
  if (mySwitch.getReceivedValue()==8977804)
    {
      arah = 1;
      digitalWrite(13, HIGH);
     }

   else if (mySwitch.getReceivedValue()==8977796)
    {
      arah = 2;
      digitalWrite(13, LOW);
     }

   else if (mySwitch.getReceivedValue()==                         8977802 && arah == 1){
      stepper.setMaxSpeed(1000); // atur kecepatan, dapat docoba dirubah untuk latihan
      stepper.setAcceleration(300);
      stepper.moveTo(800); // beri target 360*
      stepper.runToPosition(); //jalankan 
      mySwitch.resetAvailable();
   }


      else if (mySwitch.getReceivedValue()==8977794 && arah == 1){
    
       digitalWrite(dirPin, LOW);
      
      for (int i = 0; i < stepsPerRevolution; i++) {
        digitalWrite(stepPin, LOW);
        delayMicroseconds(750); // ganti delay untuk mempercepat motor
        digitalWrite(stepPin, HIGH);
        delayMicroseconds(750); // ganti delay untuk mempercepat motor
        mySwitch.resetAvailable();
        }
       }

      else if (mySwitch.getReceivedValue()==      8977801 && arah == 1){
    
       digitalWrite(dirPin, LOW);
      
      for (int i = 0; i < stepsPerRevolution; i++) {
        digitalWrite(stepPin, LOW);
        delayMicroseconds(500); // ganti delay untuk mempercepat motor
        digitalWrite(stepPin, HIGH);
        delayMicroseconds(500); // ganti delay untuk mempercepat motor
        mySwitch.resetAvailable();
        }
   }

         else if (mySwitch.getReceivedValue()==      8977793 && arah == 1){
    
       digitalWrite(dirPin, LOW);
      
      for (int i = 0; i < stepsPerRevolution; i++) {
        digitalWrite(stepPin, LOW);
        delayMicroseconds(250); // ganti delay untuk mempercepat motor
        digitalWrite(stepPin, HIGH);
        delayMicroseconds(250); // ganti delay untuk mempercepat motor
        mySwitch.resetAvailable();
        }
   }

   //ARAH JARUM JAM
      else if (mySwitch.getReceivedValue()==                         8977802 && arah == 2){
    
       digitalWrite(dirPin, HIGH); // putar berlawanan jarum jam

       for (int i = 0; i < stepsPerRevolution; i++) {
        digitalWrite(stepPin, HIGH);
        delayMicroseconds(1000); // ganti delay untuk mempercepat motor
        digitalWrite(stepPin, LOW);
        delayMicroseconds(1000); // ganti delay untuk mempercepat motor
        mySwitch.resetAvailable();
        }
   }


      else if (mySwitch.getReceivedValue()==8977794 && arah == 2){
    
       digitalWrite(dirPin, HIGH);
      
      for (int i = 0; i < stepsPerRevolution; i++) {
        digitalWrite(stepPin, LOW);
        delayMicroseconds(750); // ganti delay untuk mempercepat motor
        digitalWrite(stepPin, HIGH);
        delayMicroseconds(750); // ganti delay untuk mempercepat motor
        mySwitch.resetAvailable();
        }
       }

      else if (mySwitch.getReceivedValue()==      8977801 && arah == 2){
    
       digitalWrite(dirPin, HIGH);
      
      for (int i = 0; i < stepsPerRevolution; i++) {
        digitalWrite(stepPin, LOW);
        delayMicroseconds(500); // ganti delay untuk mempercepat motor
        digitalWrite(stepPin, HIGH);
        delayMicroseconds(500); // ganti delay untuk mempercepat motor
        mySwitch.resetAvailable();
        }
   }

         else if (mySwitch.getReceivedValue()==      8977793 && arah == 2){
    
       digitalWrite(dirPin, HIGH);
      
      for (int i = 0; i < stepsPerRevolution; i++) {
        digitalWrite(stepPin, LOW);
        delayMicroseconds(250); // ganti delay untuk mempercepat motor
        digitalWrite(stepPin, HIGH);
        delayMicroseconds(250); // ganti delay untuk mempercepat motor
        mySwitch.resetAvailable();
        }
   }
}
