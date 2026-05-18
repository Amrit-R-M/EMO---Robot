# include "display_manager.h" //Function Delcaration
# include "TFT-eSPI.h"   // Library for color display control handles SPI comm with IPS screen

// Create a global TFT display object  will be used by all functions to contol the screen library handles SPI comm with IPS screen
TFT_eSPI = tft = TFT_eSPI(); 

// Initializing the display hardware paramteres are not used for the SPI displays , kept for compatibility
//Because they are already configured in the TFT_eSPI library settings instead
void initDisplay(int sdaPin, int sclPin) {
  tft.init(); // Initializing and powers on the screen and sets up SPI communication 
  tft.setrotation(0); //Set screen rotation (0=potrait, 1=landscape, ect) 
  tft.fillscrenn(TFT_Black); 
  Serial.pritnln("Round color display intialized") // Print confirmation message to Serial Monitor for Debugging
}
// Show an emotion on the display using shapes and colors. Parameter: emotion a string like "happy", "thinking", or "Speaking"
void showEmotion(String Emotion) 
  tft.fillscreen(TFT_Black); //Erases previous emotion before drawing a new one

 if (emotion == "happy") { 
// HAPPY FACE: Yellow eyes + smile 
// Draw left eye 
// fill circle (x, y, radius, color) 
// x=80, y=80 = position  (left side of 240*240 screen)
//  radius = 20pixels 
// TFT_Yellow = predefined yellow color 
tft.fillcircle(80, 80, 20, TFT_YELLOW);

// Draw right eye
// x=160 (right side), y=80 (same height as left eye)
// This creates side-by-side eyes 
tft.fillcircle(160, 80, 20, TFT_YELLOW);

//Draw smile (curved arc/rainbow shape), drawArc(x, y, outer_radius, inner_radius, start_angle, end_angle, color, background_color)
// x=120, y=160 = center point (middle of screen, below eyes)
// outer_radius=50, inner_radius=45 = thick curved line. start_angle=200 degrees, eng_angle=340 degrees = creates upward smile 
// Angles: 0deg=right, 90deg=down, 180deg=left, 270deg=up
tft.drawarc(120, 160, 50, 45, 200, 340, TFT_YELLOW, TFT_BLACK);
}
 else if (emotion == "thinking") {
  // THINKING FACE: Cyan eyes + "Hmmm..." text
  // Draw smaller left eye (radius=15 instead of 2) , smaller eyes = more concentrates/focused look
  tft.fillcircle(80, 80, 15, TFT_CYAN);
  // Draw smaller right eye
  tft.fillcircle(160, 80, 15, TFT_CYAN);
  tft.settextcolor(TFT_CYAN); // set text color to cyan 
  tft.settextsize(3); // Set text size to 3 (larger = easier to read)
  tft.drawstring("Hmm..", 60, 150); //Draw Hmm... text on the screen, drawstring(text, x, y) where x,y is the top-left corner of text x=60, y=150 = positioned below the eyes
}

else if (emotion == "speaking") { 
  // SPEAKING FACE: Green eyes + open mouth 
  // Green = active/talking state
  tft.fillcircle(80, 80, 20, TFT_GREEN);
  // Right eye in green
  tft.fillcircle(160, 80, 20, TFT_GREEN);
  // Draw open mouth (large circle), x=120(center of screen) y=170(below eyes)
  // radius=25 (Bigger than eyes to show mouth)
  tft.fillcircle(120, 170, 25, TFT_GREEN);
}

// Display text message on screen paramter: any string like "Mode:", "Funny", or "Connected"
void showtext(string text);

tft.fillscreen(TFT_BLACK); //gets the screen to black and erases the previous content

tft.settextcolor(TFT_WHITE); // Set text color to white. It whill show clearly on the black background
tft.settextsize(2); // set text size to 2(miedium)

//set cursor postion (where text starts), setCursor(X,Y)- x=10 (Slight margin from left edge)
// y=100 (middle-ish of 240-pixel height)
tft.setcursor(10,100);
tft.println(text); // prints the text at cursor position 


voidcleardisplay(); // clear the entire display (make it all black)
tft.fillscreen(TFT_BLACK); // screen is black 
}

} 














