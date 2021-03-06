
#include <Adafruit_NeoPixel.h>
#include <IRremote.h>
IRrecv irrecv(8);
decode_results results;

Adafruit_NeoPixel pixels = 
		Adafruit_NeoPixel(30, 6,NEO_GRB+NEO_KHZ800);

void setup()
{
	Serial.begin(9600);
	irrecv.enableIRIn();
	pixels.begin();
	pixels.setBrightness(50);
}

void loop()
{
	//pastebin.com/0A81Hem1
	int num = 0;
	if (irrecv.decode(&results)) {
		long int res = results.value;
		if(res == 0xE0E046B9) {
			Serial.println("right");
			num = 1;
		}
		if(res == 0xE0E046B9) {
			Serial.println("left");
			num = 2;
		}
		if(res == 0xE0E046B9) {
			Serial.println("up");
			num = 3;
		}
		Serial.println(results.value, HEX);
		irrecv.resume(); // Receive the next value
	}
	if(num == 1) fill(0, 29, 200, 0, 0, 0);
	if(num == 2) fill(0, 14, 0, 200, 0, 0);
	if(num == 3) fill(0, 14, 0, 200, 0, 0);
	//
	//fill(0, 14, 0, 200, 0, 0);
	//fill(15, 29, 0, 0, 200, 0);
	//rainbow(30);
	//runningFire(5, 200, 0, 0, 50);
}

void fill(int start, int end, int r, int g, int b, int t)
{
	for(int i=start; i <= end; i++)
	{
		pixels.setPixelColor(i, r, g, b);
		pixels.show();
		delay(t);
	}
}
//HSV HUE SATURATION VALUE
void rainbow(int t)
{
	for(int i = 0; i <= 255; i++)
	{
		for(int j = 0; j <= 29; j++)
		{
			pixels.setPixelColor(j, wheel((j+i) & 255) );
		}
		pixels.show();
		delay(t);
	}
}
//pos 0 - 255 
//    0 - 85 green - red
//    85 - 170 red - blue
//    170 - 255 blue - green
uint32_t wheel(int pos)
{
	if(pos < 85) { // green to red
		return pixels.Color(pos * 3, 255 - pos * 3, 0);
	}
	else if(pos < 170) { // red to blue
		pos -= 85;
		return pixels.Color(255 - pos * 3, 0, pos * 3);
	}
	else { // blue to green
		pos -= 170;
		return pixels.Color(0, pos * 3, 255 - pos * 3);
	}
}

void runningFire(int n, int r, int g, int b, int t)
{
	for(int i=0; i<=29+n; i++)
	{
		int r_step = r / n, g_step = g / n, b_step = b / n;
		for(int j=0; j<=n; j++)
		{
			pixels.setPixelColor(i-j, r - r_step * j, 
									g - g_step * j, b - b_step * j);
		}
		pixels.show();
		delay(t);
	}
}

void clean(int start, int end)
{
	for(int i = start; i <= end; i++)
	{
		pixels.setPixelColor(i, 0,0,0);
	}
	pixels.show();
}//pastebin.com/Vapv9LQE
#include <Adafruit_NeoPixel.h>
#include <IRremote.h>
IRrecv irrecv(8);
decode_results results;

Adafruit_NeoPixel pixels = 
		Adafruit_NeoPixel(30, 6,NEO_GRB+NEO_KHZ800);

void setup()
{
	Serial.begin(9600);
	irrecv.enableIRIn();
	pixels.begin();
	pixels.setBrightness(50);
}

void loop()
{
	if (irrecv.decode(&results)) {
		long int res = results.value;
		if(res == 0xE0E046B9) {
			Serial.println("right");
		}
		Serial.println(results.value, HEX);
		irrecv.resume(); // Receive the next value
	}
	//fill(0, 29, 200, 0, 0, 0);
	//fill(0, 14, 0, 200, 0, 0);
	//fill(15, 29, 0, 0, 200, 0);
	//rainbow(30);
	runningFire(5, 200, 0, 0, 50);
}

void fill(int start, int end, int r, int g, int b, int t)
{
	for(int i=start; i <= end; i++)
	{
		pixels.setPixelColor(i, r, g, b);
		pixels.show();
		delay(t);
	}
}
//HSV HUE SATURATION VALUE
void rainbow(int t)
{
	for(int i = 0; i <= 255; i++)
	{
		for(int j = 0; j <= 29; j++)
		{
			pixels.setPixelColor(j, wheel((j+i) & 255) );
		}
		pixels.show();
		delay(t);
	}
}
//pos 0 - 255 
//    0 - 85 green - red
//    85 - 170 red - blue
//    170 - 255 blue - green
uint32_t wheel(int pos)
{
	if(pos < 85) { // green to red
		return pixels.Color(pos * 3, 255 - pos * 3, 0);
	}
	else if(pos < 170) { // red to blue
		pos -= 85;
		return pixels.Color(255 - pos * 3, 0, pos * 3);
	}
	else { // blue to green
		pos -= 170;
		return pixels.Color(0, pos * 3, 255 - pos * 3);
	}
}

void runningFire(int n, int r, int g, int b, int t)
{
	for(int i=0; i<=29+n; i++)
	{
		int r_step = r / n, g_step = g / n, b_step = b / n;
		for(int j=0; j<=n; j++)
		{
			pixels.setPixelColor(i-j, r - r_step * j, 
									g - g_step * j, b - b_step * j);
		}
		pixels.show();
		delay(t);
	}
}

void clean(int start, int end)
{
	for(int i = start; i <= end; i++)
	{
		pixels.setPixelColor(i, 0,0,0);
	}
	pixels.show();
}