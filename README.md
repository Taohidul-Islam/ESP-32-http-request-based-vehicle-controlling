# ESP-32-http-request-based-vehicle-controlling
A 3 wheeler(2 wheels powered) mini car would be controlled via http requests sent to esp32 from any device at same Wi-Fi network. Sending http requests manually is possible but won't be practical so I made a python code to send http requests from your desktop or laptop using your keyboard and gaming keys "W", "S", "A", "D".


<h3>Components you need:</h3>
<ul>
<li> ESP-32 Dev module.</li>
<li>Jumper wires and breadboard.</li>
<li>5-8 volt portable high current power source(2 pieces of 18650 Li-ion battery in series is recomended) to power the motors properly.</li>
<li>Step down buck converter like LM2596 to reduce the battery voltage so it can power your ESP-32 board on 3.3 volts.</li>
<li>Mini voltmeter to monitor output voltage of LM2596 buck converter. (If the buck converter doesn't come with inbuilt voltmeter for monitoring.)</li>
<li>Any H-Gate motor driver for 2 motors. I used HW-310 MINI L293D Motor Motor Drive Module Motor Driver.</li>
<li>4 diodes to protect your ESP-32 pins from unintentional current given by motor driver.</li>
<li>PVC board. I used 8 by 4 inches.</li>
<li>2 gear motors. (The yellow plastic gear motors in the market.)</li>
<li>2 Wheels for gear motor. (Yellow rim and black tires.)</li>
<li>1 free spinning caster wheel. (For the front). </li>
</ul>

<h3>Step 1: Programming your ESP-32</h3>
<ul>
  <li>Put your ESP32 on a boeardborad and make sure that the right side pins(while the usb port is towards your face) are accessible from breadboard.</li>
  <li>Copy the C++ code from the file named ESP-32main. Change the SSID and Password value to your home wifi name and home wi-fi password. If no wifi available at home, create one using a mobile phone by turning on wi-fi hotspot.</li>
<li>Now upload your code to your ESP-32 via arduino IDE or any other IDE you like.</li>
<li>Open serial monitor at 112500 baud after uploading the Code. The monitor should give you a IP adress. Note that down as we would need it later.</li>
  <P>Now your ESP-32 programming is done. Let's now do the wiring of our hardware.</P>
</ul>
<h3>Step 2: Making the actual vehicle. </h3>



