This is the guide to Run the program.
---------------------------------------
When you extract the zip file, in there you will find the main.exe (double click) if it runs then perfect!
you can check our program out.

--------------------------------------------------------------------------------------------------------------------

Note: If the main.exe doesn't executes (throws an error) don't worry. Follow the steps below.


Step#01: First we Compile ALL .cpp files together!. Open the folder 'CCP Project' in VS Code IDE, then select main.cpp.
--------

Step#02: Run this command In the Terminal:
--------
-----------------------------------------------------------------------------------------------------------------
 g++ main.cpp Player.cpp Planet.cpp Ship.cpp Market.cpp Event.cpp GameSave.cpp GameEngine.cpp -o main
------------------------------------------------------------------------------------------------------------------

Then run it with: .\main

The program will run in the Terminal. Enjoy checking out our 'Mehnat'! :)
-------------------------------------------------------------------------------------------------------------------------

List of Implemented OOPs Features:
- Encapsulation → Player class
- Inheritance → Ship subclasses
- Polymorphism → virtual functions in Ship & Event
- Abstraction → pure virtual functions

Plus mention static members, friend functions, composition etc.