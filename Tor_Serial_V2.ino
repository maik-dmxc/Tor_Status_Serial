


String state_str;

int out_open = D3;
int out_move = D2;
int out_close = D1;
int TorState = D4;
int TorStateOld;
unsigned long previousMillis = 0;        // will store last time LED was updated
const long MinZu = 350;
const long MaxZu = 700;
const long MinAuf = MaxZu;
const long MaxAuf =1000;
const long interval = MaxAuf;           // interval at which to blink (milliseconds)

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
     
     
Time = currentMillis - previousMillis;




    

    if (input != TorStateOld) {
//      Serial.println("Tor State hat sich unter 2 Sek geändert");
//      Serial.print("Time : ");
//      Serial.println(Time);
      
      TorStateOld = input;
      
      if (state_str != "Tor fährt zu" && Time < 700 && Time > 350){
      state_str = ("Tor fährt zu");
           
      Serial.println("Tor fahrtzu");

      }

      if (state_str != "Tor fährt auf" && Time < interval && Time > 700){
      state_str = ("Tor fährt auf");
           
      Serial.println("Tor fahrtauf");
            
      }
      
      digitalWrite(out_close, LOW);
      digitalWrite(out_move, HIGH);
      digitalWrite(out_open, LOW);
      
previousMillis = currentMillis;

    

  }
   if (input == TorStateOld && input == LOW && Time > interval) {

      if (state_str != "Tor offen"){
      Serial.println("Tor offen");
      state_str = ("Tor offen");
      
      }
      digitalWrite(out_close, LOW);
      digitalWrite(out_move, LOW);
      digitalWrite(out_open, HIGH);
      
    }
    if (input == TorStateOld && input == HIGH && Time > interval) {
      
      if (state_str != "Tor zu"){
      Serial.println("Tor zu");
      state_str = ("Tor zu");
       }
      digitalWrite(out_close, HIGH);
      digitalWrite(out_move, LOW);
      digitalWrite(out_open, LOW);
      
    }
}

