const int OUT_PIN = 8;
const int SAMPLE_TIME = 13;
unsigned long millisCurrent;
unsigned long millisLast = 0;
unsigned long millisElapsed = 0;
int sampleBufferValue = 0;
#include <Adafruit_NeoPixel.h>
#define PIN  2

Adafruit_NeoPixel strip(300, 2, NEO_GRB + NEO_KHZ800);

void setup() {

  Serial.begin(115200);
  strip.begin(); // Initialize NeoPixel strip object (REQUIRED)
  strip.clear();
  strip.setBrightness(150);
  strip.show();  // Initialize all pixels to 'off'
}

void loop() {
   millisCurrent = millis();
   millisElapsed = millisCurrent - millisLast;
 
   if (digitalRead(OUT_PIN) == LOW) {
     sampleBufferValue++;
   }
 
   if (millisElapsed > SAMPLE_TIME) {
      
     lightUpExceptGreenEven(0 ,sampleBufferValue, 0.065 , 148 , 0 , 211 , 0);
     lightUpExceptGreenEven(40 ,sampleBufferValue, 0.015, 255 , 70 , 0 ,  0);
     lightUpExceptGreenEven(80 ,sampleBufferValue, 0.03   , 0 , 0 , 255 , 0);
     lightUpGreen(120 ,sampleBufferValue, 0.01   , 0 , 255 ,  0 , 3);
     lightUpExceptGreenOdd(194 ,sampleBufferValue, 0.050 , 255 , 255 , 0 , 0);
     lightUpExceptGreenOdd(234 ,sampleBufferValue, 0.027 , 75 , 0 , 180,  0);
     lightUpExceptGreenOdd(274 ,sampleBufferValue, 0.015 , 255 , 0 , 0 , 0);
          
     sampleBufferValue = 0;
     millisLast = millisCurrent;
     strip.show();
     strip.clear();
   }

}



void lightUpExceptGreenEven(int pixel , int bufferValue , double ratio , int r , int g , int b , int constant){
    double numOfLights = bufferValue * (ratio) + constant;
    int n = round(numOfLights);
    int stop = 1;
    Serial.println(n);
    for(int i = pixel , j = i + 34 ; i  <=  pixel +n && stop <=15 ; i++, j--){
       strip.setPixelColor(i , r,g,b);
       strip.setPixelColor(j , r,g,b);
       //strip.setBrightness(random(255));
       stop++;
  }
  strip.show();    
}

void lightUpGreen(int pixel , int bufferValue , double ratio , int r , int g , int b , int constant){
    double numOfLights = bufferValue * (ratio) + constant;
    int n = round(numOfLights);
    for(int i = pixel  ; i <= pixel+n ; i++){
       strip.setPixelColor(i , r,g,b);
       strip.setPixelColor(i+40 , r,g,b);
       //strip.setBrightness(random(255));
    }
  strip.show();    
}

void lightUpExceptGreenOdd(int pixel , int bufferValue , double ratio , int r , int g ,int b, int constant ){
  double numOfLights = bufferValue * (ratio) + constant;
  int n = round(numOfLights);
  int stop = 1;
  for(int i = pixel , j = pixel + 6 ; i >= pixel-n && stop <= 15 ; i--,j++){
    strip.setPixelColor(i , r,g,b);
    strip.setPixelColor(j, r,g,b);
    //strip.setBrightness(random(255));
    stop++;
  }
  strip.show();   
}




  
