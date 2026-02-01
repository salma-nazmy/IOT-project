#include <PubSubClient.h>
#include <ESP8266WiFi.h>

#define  ssid "mywifi"
#define pass "1234"
#define broker "broker.emqx.io"
#define port 1883

long long int threshold;
char data[100];
int irState = 0;

WiFiClient wiclient;
PubSubClient client(wiclient);

void callback (char* topic, byte* payload, unsigned int length){
  Serial.print("Topic: ");
  Serial.println(topic);
  for(int i = 0; i<length; i++){
    data[i] = (char)payload[i];
  }
  Serial.println();
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  WiFi.begin(ssid, pass);
  while(WiFi.status() != WL_CONNECTED){
    Serial.println("Connecting to wifi...");
    Serial.print("WiFi status: ");
    Serial.println(WiFi.status());
  }
  Serial.println("WiFi is connected.");

  pinMode(D5, OUTPUT);
  pinMode(D1, INPUT);
  
  client.setCallback(callback);
  client.setServer(broker, port);

  while(!client.connect("Secb5salma")){
    Serial.println("Connecting to broker...");
  }
  Serial.println("Broker is connected");
  client.subscribe("/sector/salma/led");
  threshold = millis();
}


void loop() {
  // put your main code here, to run repeatedly:
  client.loop();

  if(data[0] == '1'){
    digitalWrite(D5, HIGH);
  }
  else{
    digitalWrite(D5, LOW);
  }

  irState = digitalRead(D2);

  if(millis()- threshold >= 1000 && irState == 0){  
    while(!client.publish("/sector/salma/ir", "1")){
       Serial.println("Publishing...");
    }
    Serial.println("Published.");
    threshold = millis();
  }
  else if(millis()- threshold >= 1000 && irState == 1){  
    while(!client.publish("/sector/salma/ir", "0")){
       Serial.println("Publishing...");
    }
    Serial.println("Published.");
    threshold = millis();
  }
}
