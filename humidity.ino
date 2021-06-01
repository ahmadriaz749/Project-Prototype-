#include <Adafruit_DHT.h>
#define DHTPIN 2 
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

int led2 = D7;

int analogValue;
string humidity = "";

void setup() 
{
    
    serial.begin(9600);
    dht.begin();
    pinMode(led2, OUTPUT);
    pinMode(humidity, INPUT);
    Particle.variable("humidity", humidity);
}

void loop() {

float h = dht.getHumidity();
humidity = string(h);
particle.publish("humidity", humidity, PRIVATE);
if (humidity > "30")
{
    //turn water supply on
}
else
{
    //turn water supply off
}

delay(10000);

}