#include <SoftwareSerial.h>
 
#define DEBUG true
 
SoftwareSerial esp8266(2,3); // make RX Arduino line is pin 2, make TX Arduino line is pin 3.
                             // This means that you need to connect the TX line from the esp to the Arduino's pin 2
                             // and the RX line from the esp to the Arduino's pin 3
void setup()
{
  Serial.begin(9600);
  esp8266.begin(9600); // your esp's baud rate might be different
  
  Serial.println("AT+RST");
  sendData("AT+RST\r\n",5000,DEBUG); // reset module
  Serial.println("AT+CWMODE=1");
  sendData("AT+CWMODE=1\r\n",5000,DEBUG); // configure as access point
  Serial.println("AT+CIFSR");
  sendData("AT+CIFSR\r\n",5000,DEBUG); // get ip address

  Serial.println("AT+CWJAP=\"Doma WIFI\",\"00024D2B8315A\"");
  Serial.println("wait 20 seconds");
  sendData("AT+CWJAP=\"Doma WIFI\",\"00024D2B8315A\"\r\n",20000,DEBUG); // get ip address

  
  Serial.println("AT+CIPMUX=1");
  sendData("AT+CIPMUX=1\r\n",1000,DEBUG); // configure for multiple connections
  Serial.println("AT+CIPSERVER=1,80");
  sendData("AT+CIPSERVER=1,80\r\n",1000,DEBUG); // turn on server on port 80
  Serial.println("AT+CIFSR");
  sendData("AT+CIFSR\r\n",5000,DEBUG); // get ip address
}
 
void loop()
{
  
  if(esp8266.available()) // check if the esp is sending a message 
  {
    while(esp8266.available())
    {
      // The esp has data so display its output to the serial window 
      char c = esp8266.read(); // read the next character.
      Serial.write(c);
    }  
  }
}
 
/*
* Name: sendData
* Description: Function used to send data to ESP8266.
* Params: command - the data/command to send; timeout - the time to wait for a response; debug - print to Serial window?(true = yes, false = no)
* Returns: The response from the esp8266 (if there is a reponse)
*/
String sendData(String command, const int timeout, boolean debug)
{
    String response = "";
    
    esp8266.print(command); // send the read character to the esp8266
    
    long int time = millis();
    
    while( (time+timeout) > millis())
    {
      while(esp8266.available())
      {
        
        // The esp has data so display its output to the serial window 
        char c = esp8266.read(); // read the next character.
        response+=c;
      }  
    }
    
    if(debug)
    {
      Serial.print(response);
    }
    
    return response;
}
