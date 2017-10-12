
int ThermistorPin = 0;
float Vret,i,j,Rth = 10000,BKK,logR, R, T, B = 3435, E1 = 298.15,K;

void setup() {
Serial.begin(9600);

 for(i=10; i<= 1024; i=i+10)
 {
      
      Serial.print("ADC=");
      Serial.print(i);
      Serial.print("   ");
      delay(200);

  j=i;
  BKK = 1024/j-1.0;
  logR = log(BKK);
  T = (1 /(1/E1+1/B*logR));

  Serial.print("T=");
  Serial.print(T);
  Serial.print("   ");

 K=T-273.15;
  Serial.print("K=");
  Serial.print(K);
  Serial.print("   ");

  
  Serial.println("  ");
  
  }
}



void loop() {
  
  Vret = analogRead(ThermistorPin);
  BKK = Rth * (1024.0 / (float)Vret - 1.0);
  logR = log(BKK);
  

  T = (1 / (1/B + 1/E1*logR));
 
 
  Serial.print("BOARD Temprature="); 
  Serial.println(T);

}

 

  
 
