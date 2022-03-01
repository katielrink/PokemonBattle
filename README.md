# Pokemon Battle
This is a Pokemon battle simulator for you and your friend mark to test your pokemon in battle. The Pokemon are hardcoded, but you are able to view and edit your own pokemon within the simulation.</br>
Within the simulation itself, you are able to view your pokemon and their individual stats. You may also edit each stat individually for every pokemon. Further, you can enter a battle against your opponent Mark. In this battle, you select three of your pokemon, and then each turn select which Pokemon you want to battle with. The user always attacks first, and the first person to defeat all three Pokemon wins.
 
### Exploitation Goal
Due to your suspicion that Mark has been playing his Pokemon game unfairly(hence preventing you from playing Animal Crossing), you chose the totally reasonable retaliation of deleting all of his Pokemon. To successfully exploit the program, you must not only gain access to Mark's data from inside the simulation, but also delete all of his Pokemon without deleteing his hardcoded data.

### Compilation
Enter the following line into a command prommpt while in the folder containing the main.cpp file </br>
```
g++ *.cpp -fno-stack-protector -static -g -o a.out
```
It was developed on a 64 bit Kali Linux, but a 32 bit should also compile. No additional files should be required.
