


String state_str;

int out_open = D3;
int out_move = D2;
int out_close = D1;
int TorState = D4;
int TorStateOld;
unsigned long previousMillis = 0;        // will store last time LED was updated
const long interval = 2000;           // interval at which to blink (milliseconds)
unsigned long Time;          //Periodendauer in us

void setup() {
  Serial.begin(9600);
 

  pinMode(TorState, INPUT);
  pinMode(out_open, OUTPUT);
  pinMode(out_move, OUTPUT);
  pinMode(out_close, OUTPUT);
  digitalWrite(out_close, LOW);
  digitalWrite(out_move, LOW);
  digitalWrite(out_open, LOW);
}






void loop() {
   
    
  
  int input = digitalRead(TorState);
  unsigned long currentMillis = millis();
     
     

  if (currentMillis - previousMillis >= interval) {
    
      previousMillis = currentMillis;

   if (input == TorStateOld && input == LOW) {

      if (state_str != "Tor offen"){
      Serial.println("Tor offen");
      state_str = ("Tor offen");
      
      }
      digitalWrite(out_close, LOW);
      digitalWrite(out_move, LOW);
      digitalWrite(out_open, HIGH);
    }
    if (input == TorStateOld && input == HIGH) {
      
      if (state_str != "Tor zu"){
      Serial.println("Tor zu");
      state_str = ("Tor zu");
       }
      digitalWrite(out_close, HIGH);
      digitalWrite(out_move, LOW);
      digitalWrite(out_open, LOW);
    }

    
  }else{
    if (input != TorStateOld) {

      Time = currentMillis - previousMillis;
      
      
      if (state_str != "Tor fährt zu" && state_str != "Tor fährt auf" && Time < 600 && Time > 350){
      state_str = ("Tor fährt zu");
           
      Serial.println("Tor fahrtzu");
      }

      if (state_str != "Tor fährt auf" && state_str != "Tor fährt zu" && Time < 1000 && Time > 800){
      state_str = ("Tor fährt auf");
           
      Serial.println("Tor fahrtauf");
      }
      
      previousMillis = currentMillis;
      digitalWrite(out_close, LOW);
      digitalWrite(out_move, HIGH);
      digitalWrite(out_open, LOW);
      TorStateOld = input;

    }

  }
}

