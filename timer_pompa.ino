#include <LiquidCrystal.h>

LiquidCrystal lcd (2,3,4,5,6,7);

uint16_t detik, menit, jam;

void setup() {
  detik = 0; 
  menit = 0;
  jam = 0;
  lcd.begin (16,2);  
  lcd.print ("POMPA NYALA");
  tone (8, 400, 5000);
}

void buzz (int times) {
  for (int i = 0; i < times; i++) {
    tone (8, 800, 500);
    delay (1000);    
  }   
}

void loop() {
  char display_clock [18];

  lcd.setCursor (0,1);
  uint16_t timer = millis()/1000;

  detik = timer % 60;
  menit = timer/60 % 60;
  jam = timer/3600;

  if (menit != 0 && menit % 10 == 0) {
    for (int i = 0; i < 5; i++) {
      buzz (menit/10);
      delay (1000);
    }       
  }  
  
  sprintf (display_clock, "%02u:%02u:%02u", jam, menit, detik);
   
  lcd.print (display_clock);
}
