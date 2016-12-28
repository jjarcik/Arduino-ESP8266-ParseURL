# Arduino-ESP8266-ParseURL

In Arduino upload empty bare project, and use this AT commands via serial monitor. 

## wires
| Arduino | ESP8266 |
| ------- |:-------:|
| TX | TX |
| RX | RX |

## commands 
(check this site http://www.pridopia.co.uk/pi-doc/ESP8266ATCommandsSet.pdf)

- AT+RST
- AT+CWMODE=1
- AT+CWMODE?
- AT+CIFSR // GET IP (ex. 10.0.0.7)
- AT+CWJAP= “Wi-FiNetwork”,“Password”
- AT+CIPMUX=1
- AT+CIPSERVER=1,80

## browser
open http://10.0.0.7

## response serial monitor:
```
+IPD,0,410:GET / HTTP/1.1
Host: 10.0.0.7
Connection: keep-alive
Cache-Control: max-age=0
Upgrade-Insecure-Requests: 1
User-Agent: Mozilla/5.0 (Windows NT 10.0; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/55.0.2883.87 Safari/537.36
Accept: text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,*/*;q=0.8
Accept-Encoding: gzip, deflate, sdch
Accept-Language: cs,en-GB;q=0.8,en;q=0.6,sk;q=0.4


OK
```

## source

http://www.jayconsystems.com/tutorials/esp01/

Send AT Commands and Print Output:

http://allaboutee.com/2014/12/27/esp8266-arduino-code-and-circuit/

Send Data From Webpage to Arduino

http://allaboutee.com/2015/01/02/esp8266-arduino-led-control-from-webpage/

https://medium.com/@nowir3s/getting-started-with-esp8266-875fb54441d6?swoff=true#.gsqifpo54
