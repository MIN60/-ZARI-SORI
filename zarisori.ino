#include <SoftwareSerial.h>
#include <DFPlayer_Mini_Mp3.h>

const int controlPin = 3;
const int inputPin1 = 8;
const int inputPin2 = 9;
const int inputPin3 = 10;

int speakerOut = 13;

void setup(){
   pinMode (speakerOut, OUTPUT);
   pinMode (controlPin, INPUT);
   pinMode (inputPin1, INPUT_PULLUP);   //ON일 때 LOW, OFF일 때 HIGH
   pinMode (inputPin2, INPUT_PULLUP);
   pinMode (inputPin3, INPUT_PULLUP);

   Serial.begin (9600);
   mp3_set_serial (Serial);   // Mp3 module 통신 세팅
   delay(1);   // 볼륨값 적용을 위한 delay 
   mp3_set_volume (30);   // 볼륨조절 값 0~30
}

void loop(){
   //`int pot = analogRead(A0);
   //pot = map(pot, 0, 1023, 0, 30);
  // mp3_set_volume (pot);   // 볼륨조절 값 0~30
   
   int val = digitalRead(controlPin);
   if (val == HIGH){      //컨트롤 버튼이 눌렸을 때
     digitalWrite(speakerOut, HIGH);
      mp3_play (1);      //"현재"
      delay(1500);   //음성 초 확인 후 변동 있음
      
      if(digitalRead(inputPin1)==LOW && digitalRead(inputPin2)==LOW && digitalRead(inputPin3)==LOW){ //LOW=스위치 누름
        mp3_play (6);   //"자리가 없습니다."
      }
      
      else{
            if (digitalRead(inputPin1)==HIGH){
              mp3_play (2);   //"1번"
              delay(1500);   //음성 초 확인 후 변동 있음
            }
     
            if (digitalRead(inputPin2)==HIGH){
              mp3_play (3);   //"2번"
              delay(1500);   //음성 초 확인 후 변동 있음
            }
            
            if (digitalRead(inputPin3)==HIGH){
              mp3_play (4);   //"3번"
              delay(1500);   //음성 초 확인 후 변동 있음
           }

           mp3_play (5);   //"자리가 비어있습니다."
           delay(1500);
     }
   }
   else{
     digitalWrite(speakerOut, LOW);
   }
}
