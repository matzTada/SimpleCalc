#SimpleCalc

<a href="http://www.youtube.com/watch?feature=player_embedded&v=-ei_GP5pkSE
" target="_blank"><img src="http://img.youtube.com/vi/-ei_GP5pkSE/0.jpg " 
alt="movie on youtube" width=50% border="10" /></a>  
[movie on youtube](https://www.youtube.com/watch?v=-ei_GP5pkSE)  

##What you need?
* Arduino UNO  
* 4x4 Keypad
* 7 segment 4 digits display  

##Keypad
The Keypad used in this project. <https://www.parallax.com/product/27899>  

references  

* <http://playground.arduino.cc/Code/Keypad>
* <http://www.learningaboutelectronics.com/Articles/Arduino-keypad-circuit.php>

##7 segment 4 digits display
HS-3461BS is used  

references  

* <http://img.hqew.com/File/Images/250000-259999/251308/Electronic/2012816113627928480.jpg>
* <http://garretlab.web.fc2.com/arduino/introduction/beginning_with_7segment_led/>

<a><img src="http://img.hqew.com/File/Images/250000-259999/251308/Electronic/2012816113627928480.jpg" alt="" width=50%></a>  

##Pin assign

<a><img src="https://github.com/matzTada/SimpleCalc/blob/master/calc_breadboard.png" 
alt="calc_breadboard" width=50%></a>

Arduino|Other  
--- | ---   
0 (RX) | Keypad 1 (row 0)    
1 (TX) | Keypad 2 (row 1)  
2 | 7seg4dig display 1  
3 | 7seg4dig display 2   
4 | 7seg4dig display 3   
5 | 7seg4dig display 4   
6 | 7seg4dig display 5   
7 | 7seg4dig display 6 (via Resistor)      
8 | 7seg4dig display 7    
9 | 7seg4dig display 8 (via Resistor)    
10 | 7seg4dig display 9 (via Resistor)    
11 | 7seg4dig display 10   
12 | 7seg4dig display 11   
13 | 7seg4dig display 12 (via Resistor)    
A0 (14) | Keypad 7 (col 3)  
A1 (15) | Keypad 6 (col 2)  
A2 (16) | Keypad 5 (col 1)  
A3 (17) | Keypad 4 (col 0)  
A4 (18) | Keypad 3 (row 3)  
A5 (19) | Keypad 2 (row 2)  

