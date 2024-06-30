# Sun Following Solar Panel
The advantages of sun following solar panel is that we can absorb maximum solar energy falling on the panel.<br>
Sun following solar panels can be used in powering traffic lights, industrial and household needs.<br>

<b>Components Used:</b>
<li>Arduino UnoR3<li>LDR 2<li>Servo motor<li>10kohm Resistors<li> Solar panel<li>Jumper Wires<li>Power source<br>
[Mechanical support to hold the panel and LDRs is also used.]
  
<b>Working:</b>
<br>There are two Ldrs mounted on the support along with a solar panel.
When these LDRs are exposed to sun light they create a resistance depending on the intensity of light falling on them.
When connected to a development board, values corresponding to intensity can be obtained.
By calculating the difference between these values the ldr which has higher intensity can be determined.
After getting this data the servo motor that is attached to the mechanical support can be made to move to that angle where the solar panel is exposed to the Sun resulting in higher energy absorption. In the code.ino the servo is allowed to rotate from 30 degrees to 180 degrees. This range can be changed in order to get maximum power for maximum time. <br>
This process is repeated until the Ldr data suggests that the mechanical support is perpendicular to the light falling on it.<br><br>
YouTube Demo Video Link - https://youtu.be/I8gClb1xTpQ
