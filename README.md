# Task-8: Traffic-Light-Control-System

## Aim

Design and development of an embedded systems application for simulating traffic light control system at a crossroad using Arduino microcontrollers and corresponding hardware components as part of Embedded Systems Lab Training SS2022.


## Design Approach


The  design consists of two traffic lights one for each direction of the crossroad (Horizontal and Vertical). Each traffic will have three indicator lights and will be implemented using LEDs (Green, Yellow, Red). The system works in the following way:

1. When the system starts, one traffic light will be green initially and the other will be red.
2. After a preset amount of time expires the both traffic lights will become yellow for a very short time before switching and the light which was green will be red      and viceversa.
3. After the preset time expires the traffic light switches again and the cycle is repeated.
4. Two buttons will be provided in system to simulate pedestrians, if the button is pushed the above traffic cycle is interrupted and traffic light corresponding to the road which cuts the pedestrians path is turned red for a preset time so the pedestrians can pass.
5. Preset time will be alloted to the pedestrians to cross the road and will be signaled using a beeper. 
6. Cars will randomly approach either side of the road and will be simulated using queues coded in the controller.
7. The traffic simulated using the queue for the corresponding light which is green is processed until a preset time. 


## Components Required


| Component                     | Quantity      |
| :-----------------------------|   :---:       |
| `LED Red`                     | 2             |
| `LED Green`                   | 2             |
| `LED Yellow`                  | 2             |
| `Push button`                 | 2             |
| `Resistors 100 ohm`           | 8             |
| `ARduino UNO R3`              | 1             |
| `Buzzer`                      | 2             |
| `Connecting Wires`            | 
| 'BreadBoard'.                 |

## Circuit Diagram

![This is an image](Images/Diagram.png)

![This is an image](Images/Circuit_Diagram.jpg)

---



 




