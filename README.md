# ESP-32-http-request-based-vehicle-controlling
A 3 wheeler(2 wheels powered) mini car would be controlled via http requests sent to esp32 from any device at same Wi-Fi network. Sending http requests manually is possible but won't be practical so I made a python code to send http requests from your desktop or laptop using your keyboard and gaming keys "W", "S", "A", "D".
## License

This project is licensed under the [Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International License](LICENSE).

For full license details, please refer to the `LICENSE` file in this repository.

<h3>Components you need:</h3>
<ul>
<li> ESP-32 Dev module.</li>
<li>Jumper wires and breadboard.</li>
<li>5-8 volt portable high current power source(2 pieces of 18650 Li-ion battery in series is recomended) to power the motors properly.</li>
<li>Step down buck converter like LM2596 to reduce the battery voltage so it can power your ESP-32 board on 3.3 volts.</li>
<li>Mini voltmeter to monitor output voltage of LM2596 buck converter. (If the buck converter doesn't come with inbuilt voltmeter for monitoring.)</li>
<li>Any H-Gate motor driver for 2 motors. I used HW-310 MINI L293D Motor Drive Module Motor Driver.</li>
<li>4 diodes to protect your ESP-32 pins from unintentional current given by motor driver.</li>
<li>PVC board. I used 8 by 4 inches.</li>
<li>2 gear motors. (The yellow plastic gear motors in the market.)</li>
<li>2 Wheels for gear motor. (Yellow rim and black tires.)</li>
<li>1 free spinning caster wheel. (For the front). </li>
</ul>

<h3>Step 1: Programming your ESP-32</h3>
<ul>
  <li>Put your ESP32 on a boeardborad and make sure that the right side pins(while the usb port is towards your face) are accessible from breadboard.</li>
  <li>Copy the C++ code from the file named ESP-32main.ino. Change the SSID and Password value to your home wifi name and home wi-fi password. If no wifi available at home, create one using a mobile phone by turning on wi-fi hotspot.</li>
<li>Now upload your code to your ESP-32 via arduino IDE or any other IDE you like.</li>
<li>Open serial monitor at 112500 baud after uploading the Code. The monitor should give you a IP adress. Note that down as we would need it later.</li>
  <P>Now your ESP-32 programming is done. Let's now do the wiring of our hardware.</P>
</ul>
<h3>Step 2: Making the actual vehicle. </h3>
<ul>
  <li>Take the PVC board and attach the 2 motors, 2 wheels and the caster wheel as shown in the image.
</li>
<img src="https://github.com/user-attachments/assets/fe2d057f-20e2-44d7-beba-df0c2e34a35a" width="250" height="250">
<li>While facing the motor terminal upwards, assume left terminal as positive and right terminal as negative. Look at the picture at bottom for reference.</li>
<img src="https://github.com/user-attachments/assets/ef098f74-9ace-44c7-ac0c-34a3c448bc10" width="250" height="250" >
<li>Now while facing the caster wheel upwards, assume the right motor as "Motor A" and the left motor as "Motor B". Look at the picture shown below for reference.</li>
<img src="https://github.com/user-attachments/assets/df9bfd2a-7096-4fce-b876-e17284e66fc0" width="250" height="250">
<li>Now connect your components in your breadboard as shown below.</li>
<img src="https://github.com/user-attachments/assets/331e5cc3-9280-4a81-b70b-ce556004bf1e" width="250" height="250">
<li>Now put everything on your car safely and glue them if needed.</li>
<li>I used two 18650 3.7v(4v when fully charged) Li-ion battery in series for power supply. You can use any battery you want. Remember, exceeding 6 Volts may damage your motor overtime.(I used 8 Volts as it was vesetile for me.)</li>
<li>Make sure to step down the voltage to 3.33V in LM2596 converter output before powering your ESP-32 board. Exceeding this voltage while connected to your ESP-32 board may cook your board.(I cooked my board once.)</li>

</ul>
<h3>Step 3: Setup controller program.</h3>
<ul>
  <li>Install and setup your preferable IDE for python programing. I use Visual Studio Code with Code Runner extension.</li>
  <li>Download controller.py file from this repo and open it in your IDE. </li>
  <li>Now replace the value of ESP_IP variable with your own ESP_IP which you noted down before from 115200 baud serial monitor while programing your ESP-32</li>
  <li>Now power up everything according to circuit design mentioned before.</li>
  <li>Now run the python code and you are good to go. Enjoy your keyboard controlled vehicle.</li>
</ul>






