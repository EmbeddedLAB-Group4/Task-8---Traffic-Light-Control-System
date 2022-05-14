
int s1=0;
int s2=0;

int red1 = 13;
int yellow1 = 12;
int green1 = 11;
int buzzer1= 10;
int petred1 =6;
int petgreen1 =5;

int red2 = 9;
int yellow2 = 8;
int green2 = 7;
int buzzer2= 4;
int petred2 =1;
int petgreen2 =0;

int car1;
int car2;




void setup() {
  
    pinMode(red1, OUTPUT);
    pinMode(yellow1, OUTPUT);
    pinMode(green1, OUTPUT);
    pinMode(buzzer1, OUTPUT);
    pinMode(petred1, OUTPUT);
    pinMode(petgreen1, OUTPUT);
    digitalWrite(green1, HIGH);
    digitalWrite(red1, LOW);
    digitalWrite(yellow1, LOW);
    digitalWrite(buzzer1, LOW),
    digitalWrite(petred1, HIGH);
    digitalWrite(petgreen1, LOW);
    attachInterrupt(digitalPinToInterrupt(3),stop1,RISING);
  // interupt checking in pin 3 for rising edge
  
    pinMode(red2, OUTPUT);
    pinMode(yellow2, OUTPUT);
    pinMode(green2, OUTPUT);
    pinMode(buzzer2, OUTPUT);
    pinMode(petred2, OUTPUT);
    pinMode(petgreen2, OUTPUT);
    digitalWrite(green2, HIGH);
    digitalWrite(red2, LOW);
    digitalWrite(yellow2, LOW);
    digitalWrite(buzzer2, LOW);
    digitalWrite(petred2, HIGH);
    digitalWrite(petgreen2, LOW);
    
    attachInterrupt(digitalPinToInterrupt(2),stop2,RISING);
  // interupt checking in pin 3 for rising edge
    Serial.begin(9600);
    car1 =0;
    car2 =0;
    queue1pop(5);
    queue2push(5);
    
    
    
}


void loop() {
  
 if(s1 == 1 && s2== 0 ){
   // checking if button 1 is pressed 
        digitalWrite(buzzer1, HIGH);
        digitalWrite(petred1, LOW);
        digitalWrite(petgreen1, HIGH);
            changeLights1(0);
        for(long int i = 0; i < 6000; i++){
          delay(1);
          }
        digitalWrite(buzzer1, LOW);
        digitalWrite(petred1, HIGH);
        digitalWrite(petgreen1, LOW);
        s1 = 0;
        changeLights1(1);
        queue1push(3);  // push 3 cars in queue 1
        queue2pop(3);  // pop 3 cars in queue 2
        
        
        }else if(s2 ==1 && s1==0)
    {
   // checking if button 2 is pressed 
        digitalWrite(buzzer2, HIGH);
        digitalWrite(petred2, LOW);
        digitalWrite(petgreen2, HIGH);
            changeLights1(1);
        for(long int i = 0; i < 6000; i++){
          delay(1);
          }
        digitalWrite(buzzer2, LOW);
        digitalWrite(petred2, LOW);
        digitalWrite(petgreen2, HIGH);
        s2 = 0;
        changeLights1(1);
        queue1pop(3);   // pop 3 cars in queue 1
        queue2push(3);  // push 3 cars in queue 2
    
        
    }else if(s1 ==1 && s2==1)
            {
   // checking if button 1 and button2  is pressed 
        digitalWrite(buzzer1, HIGH);
        digitalWrite(buzzer2, HIGH);
        digitalWrite(petred1, LOW);
        digitalWrite(petgreen1, HIGH);
        digitalWrite(petred2, LOW);
        digitalWrite(petgreen2, HIGH);
            changeLights1(2);
        for(long int i = 0; i < 6000; i++){
          delay(1);
          }
        digitalWrite(buzzer1, LOW);
        digitalWrite(buzzer2, LOW);
        digitalWrite(petred1, HIGH);
        digitalWrite(petgreen1, LOW);
        digitalWrite(petred2, HIGH);
        digitalWrite(petgreen2, LOW);
        queue1push(3);// push 3 cars in queue 1
        queue2push(3);// pop 3 cars in queue 2
        s1 =0;
        s2 = 0;
        }
 
  
    else {
          changeLights1(0);
            queue1push(5); // push 5 cars in queue 1
            queue2pop(5);    // pop 5 cars in queue 2
            changeLights1(1);
        queue1pop(5);  // pop 5 cars in queue 1
        queue2push(5); // push 5 cars in queue 2    
         }
  
   
 }

void changeLights1(int a){
    // green off, yellow on for 2 seconds and then to red for 9sec
  

  
  if(a == 0)
  {
    digitalWrite(green1, LOW);
    digitalWrite(yellow1, HIGH);
    digitalWrite(red1, LOW);
    digitalWrite(green2, LOW);
    digitalWrite(yellow2, HIGH);
    digitalWrite(red2, LOW);
    for(long int i = 0; i < 2000; i++){
// delay 2 sec
      delay(1);
      }
    
    // turn off yellow, then turn red on for 6 seconds
    digitalWrite(green1, LOW);
    digitalWrite(yellow1, LOW);
    digitalWrite(red1, HIGH);
    digitalWrite(green2, HIGH);
    digitalWrite(yellow2, LOW);
    digitalWrite(red2, LOW);
    
    for(long int i = 0; i < 9000; i++){
      
      delay(1);
      }
    
  }else if(a ==1)
  {
    digitalWrite(green1, LOW);
    digitalWrite(yellow1, HIGH);
    digitalWrite(red1, LOW);
    digitalWrite(green2, LOW);
    digitalWrite(yellow2, HIGH);
    digitalWrite(red2, LOW);
    
    // this is to check if button is still pressed while delaying 
    for(long int i = 0; i < 2000; i++){
      delay(1);
      }
    
    // turn off yellow, then turn red on for 6 seconds
    digitalWrite(green1, HIGH);
    digitalWrite(yellow1, LOW);
    digitalWrite(red1, LOW);
    digitalWrite(green2, LOW);
    digitalWrite(yellow2, LOW);
    digitalWrite(red2, HIGH);
    for(long int i = 0; i < 9000; i++){
      delay(1);
    }
    
    
  }else if( a ==2)
  {
    
    digitalWrite(green1, LOW);
    digitalWrite(yellow1, HIGH);
    digitalWrite(red1, LOW);
    digitalWrite(green2, LOW);
    digitalWrite(yellow2, HIGH);
    digitalWrite(red2, LOW);
    
    // this is to check if button is still pressed while delaying 
    for(long int i = 0; i < 2000; i++){
      delay(1);
      }
    
    // turn off yellow, then turn red on for 6 seconds
    digitalWrite(green1, LOW);
    digitalWrite(yellow1, LOW);
    digitalWrite(red1, HIGH);
    digitalWrite(green2, LOW);
    digitalWrite(yellow2, LOW);
    digitalWrite(red2, HIGH);
    for(long int i = 0; i < 9000; i++){
      delay(1);
      }

  }
  
}

void stop1()
{
  s1 = 1;
  // change the variable to 1 to save the interrupt
}

void stop2()
{
  s2 = 1;
  // change the variable to 1 to save the interrupt
}

void queue1push(int a)
{
  car1 = car1+a;
  Serial.print("no of cars in signal 1:");
  if(car1<=0){car1=0;}
  Serial.println(car1);
}
void queue1pop(int a)
{
  car1 = car1-a;
  Serial.print("no of cars in signal 1:");
  if(car1<=0){car1=0;}
  Serial.println(car1);
}
void queue2push(int a)
{
  car2 = car2+a;
  Serial.print("no of cars in signal 2:");
  if(car2<=0){car2=0;}
  Serial.println(car2);
}
void queue2pop(int a)
{
  car2 = car2-a;
  Serial.print("no of cars in signal 2:");
  if(car2<=0){car2=0;}
  Serial.println(car2);
}

 
   
