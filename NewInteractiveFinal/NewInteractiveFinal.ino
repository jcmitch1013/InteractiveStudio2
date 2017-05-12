//*Code by Joshua Mitchell Adapted from VS1053 player_simple Example  Written by Limor Fried/Ladyada for Adafruit Industries. Additions by Allison Berkoy 
  
// include SPI, MP3 and SD libraries
#include <SPI.h>
#include <Adafruit_VS1053.h>
#include <SD.h>

// define the pins used
#define CLK 13       // SPI Clock, shared with SD card
#define MISO 12      // Input data, from VS1053/SD card
#define MOSI 11      // Output data, to VS1053/SD card



// These are the pins used for the music maker shield
#define SHIELD_RESET  -1      // VS1053 reset pin (unused!)
#define SHIELD_CS     7      // VS1053 chip select pin (output)
#define SHIELD_DCS    6      // VS1053 Data/command select pin (output)

// These are common pins between breakout and shield
#define CARDCS 4     // Card chip select pin
// DREQ should be an Int pin, see http://arduino.cc/en/Reference/attachInterrupt
#define DREQ 3       // VS1053 Data request, ideally an Interrupt pin

Adafruit_VS1053_FilePlayer musicPlayer = 

  // create shield-example object!
  Adafruit_VS1053_FilePlayer(SHIELD_RESET, SHIELD_CS, SHIELD_DCS, DREQ, CARDCS);

int potPin = A0;
int potPin2 = A1;

int btn1 = 5;
int btn2 = 9;
int btn3 = 8;

boolean gameOver = false;

void setup() {
  Serial.begin(9600);
  pinMode(btn1, INPUT);
  pinMode(btn2, INPUT);
  pinMode(btn3, INPUT);
  

  if (! musicPlayer.begin()) { // initialise the music player
     Serial.println(F("Couldn't find VS1053, do you have the right pins defined?"));
     //while (1);
  }
  Serial.println(F("VS1053 found"));
  
   if (!SD.begin(CARDCS)) {
    Serial.println(F("SD failed, or not present"));
   // while (1);  // don't do anything more
  }

 
  
  // Set volume for left, right channels. lower numbers == louder volume!
  musicPlayer.setVolume(1,1);
}

void loop() {
//gameOver = false;
  int reading = analogRead(potPin);
  int reading2= analogRead(potPin2);
  Serial.println(reading);
if(gameOver == false){

if (reading > 800){
  Serial.println(F("Playing track 001"));
  musicPlayer.playFullFile("tracks/track001.mp3");
  }
if (reading2 > 800){
  musicPlayer.playFullFile("tracks/track005.mp3");
}
}

  int btn1read= digitalRead(btn1);
  if(btn1read == HIGH){
    gameOver=true;
     musicPlayer.playFullFile("tracks/track004.mp3");
  }
 
  int btn2read =digitalRead(btn2);
  if(btn2read == HIGH){
    gameOver = true;
    musicPlayer.playFullFile("tracks/track004.mp3");
    }
  int btn3read =digitalRead(btn3);
   if(btn3read == HIGH){
    musicPlayer.playFullFile("tracks/track003.mp3");
    }

     
}





