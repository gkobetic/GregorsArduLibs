#" Gregor's Arduino Libraries

### 1. Non stopable delay
Library for delays (time intervals) that do not stop the main loop from executing.

#### Create delay:
- MyDelay myDelay1(1000); -> 1000 is interval time in milliseconds when your code can be executed.
Add as many delays as you want. Name them like myDelay2(), myDelay3(), myDelay4(),...

#### Here are implemented functions:
- isInterval(); -> check if interval time has expired and execute your code
- start(); -> starts executing delay
- stop(); -> stop executing delay
- resume(); -> resumes executing delay
- reset(); -> resets timer and start counting interval time from the beginning
- setInterval(200); -> change interval time on existing delay. 200 is new interval time

Please see code example in Arduino IDE.

You can contact me any time:
- gkobetic@gmail.com
- https://www.notics.si/

Best regards!
