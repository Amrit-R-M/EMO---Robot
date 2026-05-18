# include "display_manager.h" //Function Delcaration
# include <TFT_eSPI.h>  // Library for color display control handles SPI comm with IPS screen

// Create a global TFT display object  will be used by all functions to contol the screen library handles SPI comm with IPS screen
TFT_eSPI tft = TFT_eSPI(); 

// Initializing the display hardware paramteres are not used for the SPI displays , kept for compatibility
//Because they are already configured in the TFT_eSPI library settings instead
void initDisplay(int sdaPin, int sclPin) {
  tft.init(); // Initializing and powers on the screen and sets up SPI communication 
  tft.setRotation(0); //Set screen rotation (0=potrait, 1=landscape, ect) 
  tft.fillScreen(TFT_BLACK); 
  Serial.println("Round color display intialized"); // Print confirmation message to Serial Monitor for Debugging
}
// Show an emotion on the display using shapes and colors. Parameter: emotion a string like "happy", "thinking", or "Speaking"
void showEmotion(String emotion) {
  tft.fillScreen(TFT_BLACK); //Erases previous emotion before drawing a new one
 if (emotion == "happy") { 
// HAPPY FACE: Yellow eyes + smile 
// Draw left eye 
// fill circle (x, y, radius, color) 
// x=80, y=80 = position  (left side of 240*240 screen)
//  radius = 20pixels 
// TFT_Yellow = predefined yellow color 
tft.fillCircle(80, 80, 20, TFT_YELLOW);

// Draw right eye
// x=160 (right side), y=80 (same height as left eye)
// This creates side-by-side eyes 
tft.fillCircle(160, 80, 20, TFT_YELLOW);

//Draw smile (curved arc/rainbow shape), drawArc(x, y, outer_radius, inner_radius, start_angle, end_angle, color, background_color)
// x=120, y=160 = center point (middle of screen, below eyes)
// outer_radius=50, inner_radius=45 = thick curved line. start_angle=200 degrees, eng_angle=340 degrees = creates upward smile 
// Angles: 0deg=right, 90deg=down, 180deg=left, 270deg=up
tft.drawArc(120, 160, 50, 45, 200, 340, TFT_YELLOW, TFT_BLACK);
}
 else if (emotion == "thinking") {
  // THINKING FACE: Cyan eyes + "Hmmm..." text
  // Draw smaller left eye (radius=15 instead of 2) , smaller eyes = more concentrates/focused look
  tft.fillCircle(80, 80, 15, TFT_CYAN);
  // Draw smaller right eye
  tft.fillCircle(160, 80, 15, TFT_CYAN);
  tft.setTextColor(TFT_CYAN); // set text color to cyan 
  tft.setTextSize(3); // Set text size to 3 (larger = easier to read)
  tft.drawString("Hmm..", 60, 150); //Draw Hmm... text on the screen, drawstring(text, x, y) where x,y is the top-left corner of text x=60, y=150 = positioned below the eyes
}

else if (emotion == "speaking") { 
  // SPEAKING FACE: Green eyes + open mouth 
  // Green = active/talking state
  tft.fillCircle(80, 80, 20, TFT_GREEN);
  // Right eye in green
  tft.fillCircle(160, 80, 20, TFT_GREEN);
  // Draw open mouth (large circle), x=120(center of screen) y=170(below eyes)
  // radius=25 (Bigger than eyes to show mouth)
  tft.fillCircle(120, 170, 25, TFT_GREEN);
}
}

// Display text message on screen paramter: any string like "Mode:", "Funny", or "Connected"
void showText(String text) {

tft.fillScreen(TFT_BLACK); //gets the screen to black and erases the previous content

tft.setTextColor(TFT_WHITE); // Set text color to white. It whill show clearly on the black background
tft.setTextSize(2); // set text size to 2(miedium)

//set cursor postion (where text starts), setCursor(X,Y)- x=10 (Slight margin from left edge)
// y=100 (middle-ish of 240-pixel height)
tft.setCursor(10,100);
tft.println(text); // prints the text at cursor position 
}

void clearDisplay() { // clear the entire display (make it all black)
tft.fillScreen(TFT_BLACK); // screen is black 
} 













