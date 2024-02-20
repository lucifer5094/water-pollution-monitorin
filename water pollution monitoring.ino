#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <DHT.h>

#define pH_SENSOR_PIN A2             //ph sensor
#define TDS_SENSOR_PIN A1            //tds sensor
#define WATER_LEVEL_SENSOR_PIN A3    //water level sensor
#define DHTPIN 10                    //temperature and humidity sensor
#define DHTTYPE DHT11
#define TURBIDITY_SENSOR_PIN A0      // Define the pin for the turbidity sensor
#define trigPin 12                   //ultrasonic sensor
#define echoPin 11
float pHValue;
float tdsValue;
int turbidityValue;

LiquidCrystal_I2C lcd(0x27, 16, 2);  // 16x2 display
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  dht.begin();
  pinMode(pH_SENSOR_PIN, INPUT);
  pinMode(TDS_SENSOR_PIN, INPUT);
  pinMode(WATER_LEVEL_SENSOR_PIN, INPUT);
  pinMode(TURBIDITY_SENSOR_PIN, INPUT); // Initialize the turbidity sensor pin
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  // Initialize the LCD
  lcd.init();
  // Turn on the backlight
  lcd.backlight();
  // Set a default contrast level (you may need to adjust this)
  lcd.setContrast(50);  // You can try different values (0-100) to get the desired contrast
  // Set cursor to the first column of the first row
  lcd.setCursor(0, 0);

}

void loop() {
  // Read the analog value from the pH sensor
  int pH_sensor_value = analogRead(pH_SENSOR_PIN);
  float pH_voltage = pH_sensor_value * (5.0 / 1024.0);
  pHValue = 3.5 * pH_voltage;

  // Read the analog value from the TDS sensor
  int tds_sensor_value = analogRead(TDS_SENSOR_PIN);
  float tds_voltage = tds_sensor_value * (5.0 / 1023.0);
  tdsValue = tds_voltage * 1000 / 2.0;

  // Read water level sensor data
  int waterLevel = digitalRead(WATER_LEVEL_SENSOR_PIN);

  // Read temperature and humidity
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();

  // Read the analog value from the turbidity sensor
  turbidityValue = analogRead(TURBIDITY_SENSOR_PIN);

  // Read distance of objects using ultrasonic sensor
  long duration, distance;

  digitalWrite(trigPin, LOW);         //clear the trigpin
  delay(2);                         
  digitalWrite(trigPin, HIGH);        //set the trigpin high
  delay(10);
  digitalWrite(trigPin, LOW);         //set the trigpin low

  duration = pulseIn(echoPin, HIGH);  //Read the echopin, and calculate the duration of the pulse
  distance = (duration*0.034/2);      //calculate the distance

  // Print pH value to serial monitor
  Serial.print("pH Value: ");
  Serial.println(pHValue);



  // Print TDS value to serial monitor
  Serial.print("TDS Value: ");
  Serial.println(tdsValue);

 

  // Print turbidity value to serial monitor
  Serial.print("Turbidity: ");
  Serial.println(turbidityValue);

  // Print water level status to serial monitor
  if (waterLevel == HIGH) {
    Serial.println("नाव डूब रही है"); // Hindi: "Boat is sinking"
  } else {
    Serial.println("Water level is normal ");
  }

  // Print temperature and humidity to serial monitor
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" °C");
  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.println(" %");
  

  // Print the distance value on serial monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println("cm");

  Serial.print("\n");


  // Display pH value on LCD
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("pH Value: ");
  lcd.print(pHValue);
  delay(2000);

// Display tds value on LCD
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("TDS value: ");
  lcd.print(tdsValue);
  delay(2000);

  // Display turbidity value on LCD
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Turbidity: ");
  lcd.print(turbidityValue);
  delay(2000);

// Display temperature value on LCD
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Temp:");
  lcd.print(temperature);
  lcd.print(" °C");
  delay(2000);

  // Display humidity value on LCD
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Humidity: ");
  lcd.print(humidity);
  lcd.print("%");
  delay(2000); 

  //Display distance of object on lcd display
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Distance: ");
  lcd.print(distance);
  lcd.print("cm");
  delay(2000);

}