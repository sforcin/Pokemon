# <A Text-Based Role-Playing Game (RPG) - Pokemon>
 > Authors: Sricharan Pamireddy (https://github.com/Sricharan-Pamireddy), Uma Akundi (https://github.com/umizoomiexe), Isabela Sforcin(https://github.com/sforcin), Brandon Nguyen(https://github.com/bnguy408), Andrew Do(https://github.com/androodo)

## Project Description
**Why is it important or interesting to you?**
  This project allows for creativity and an ability to be flexible with the details such as characters, attack strategies, and levels. It gives an opportunity to expand once a basic skeleton is made, allowing us to add components if time permits. 

**What languages/tools/technologies do you plan to use?**
  We will use C++ and a command line interface, along with some C++ standard libraries. We don’t plan on using any external libraries at this time. 

**What will be the input/output of your project?**
  The input of the project will be from the keyboard input from users and also files that can be read. The output will be text output to the console as the game is being played and also data being written to files.

**What are the features that the project provides?**
  Ability to store previous games (ongoing or completed) 
  The ability to load previous games to be resumed.
  NPC’s having predetermined actions based on user input
  Playable character options
  Different items and weapons (healing items, different weapon types and materials) 
  Player inventories (how much storage available)
  Character actions and abilities
  Experience and Levels (Characters gaining or losing experience based on actions/ levels unlocking access to more items) 

## User Interface Specification
 > Include a navigation diagram for your screens and the layout of each of those screens as desribed below. For all the layouts/diagrams, you can use any tool such as PowerPoint or a drawing program. (Specification requirement is adapted from the User Interface Design Document Template of CMSC 345 at the University of Maryland Global Campus)
### Navigation Diagram
![App Screenshot](https://github.com/cs100/final-project-spami-uakun-ialve-ado-bnguy/blob/master/user_navigation_diagram.png)

The navigation diagram above represents the flow of how a user will navigate / use the program.
The circle is the starting point where user can start a new game, resume a game, or will navigate to when they leave a game.
Users can then start a new game, select their characters, and start playing a new game.
Or, they can resume a game from an inputted file.
While playing the game, a user can pause the game and resume later, edit the current characters, delete the current game, or save and exit.

### Screen Layouts
In game screen layout:
```
-------------------------------
Choose your starter pokemon!:
      1. Charmander
      2. Squirtle
      3. Bulbasaur
-------------------------------
```
Main Menu/Landing Page: 
```
---------------------------
        MAIN MENU:
    1. Start new game
    2. Resume game
    3. View all games 
    4. Pokedex!
----------------------------
```
```
--------------------------
       Settings:
   1. Pause Game
   2. Edit / Add Characters
   3. Delete Game
   4. Save & Exit
   5. Resume Game
---------------------------
```
This is a general layout of our UI screens. Users will have options to input "1", "2", "3", etc... to choose what page to navigate to. We plan to have a similar text-based layouts when it comes to actions within the game/actually playing the game itself. If time permits, we may choose to incoorperate a visual component (however, this is undecided as of now).
## Class Diagram
<img width="1700" alt="image" src="https://github.com/cs100/final-project-spami-uakun-ialve-ado-bnguy/assets/147475405/0a31b6bd-66e8-49d1-92f1-f3cca301300f">
Updated UML Diagram.

Diagram is up to date with corrections
 
 > ## Phase III
 > You will need to schedule a check-in for the second scrum meeting with the same reader you had your first scrum meeting with (using Calendly). Your entire team must be present. This meeting will occur on week 8 during lab time.
 
 > BEFORE the meeting you should do the following:
 > * Update your class diagram from Phase II to include any feedback you received from your TA/grader.
 > * Considering the SOLID design principles, reflect back on your class diagram and think about how you can use the SOLID principles to improve your design. You should then update the README.md file by adding the following:
 >   * A new class diagram incorporating your changes after considering the SOLID principles. 
 >   * For each update in your class diagram, you must explain in 3-4 sentences:
 >     * What SOLID principle(s) did you apply?
>     
 1. Single Responsability Principe (SPR): I moved shared functionatilies such as the functions 'setName', 'getName', 'attack', and 'speedAttack' into the base class 'Pokemon', so each subclass has fewer responsabilities. This change ensures that subclasses are only responsible for their specific differences or extension, not common functionalities. This helped us code better by only having to write some functionalities and functions once, instead of having to implement them multiple times.
 2. Open/Closed Principle (OCP): I added an 'evolve' function, which will allow evolution behaviors to be added or changed specifically to each subclass. With this addition, the design encourages software entities to be open for extension but closed for modification. It also allows each Pokemon subclass to have its unique evolution behavior that could be extended without altering the codebase of other subclasses. This change increases flexibility and scalability of the game, and enables future modifications by isolating specific evolutionaty changes. These changes allowed us to write better code by sharing functionality across classes.
 3. Liskov Substitution Principle(LSP): By ensuring all Pokemon related methods are being implemented in the base class and overriden in subclasses, we reinforced the principle that subclasses can replace their base class without affecting the program. This change also proves that the objects in the subclasses inherited from the Pokemon class has access to every function and member variable present in member class. (Ensures proper and reliable polymorphic behavior acress the game's features).


 > ## Final deliverable
 ## Final Sprint Plan
  > All deliverables and user stories are either in testing or completed. Our last sprint will consist of everyone testing our user stories and fixing any errors and issues. All user stories have been assigned and distributed as per previous workflow (those who worked on the user story development were assigned to test, and a secondary developer was assigend to double check their test). Our sprint will last 1-2 weeks if executed. The last  of our user stories are "In Progress", and are unassigned. This is due to the fact that we unintentionally were able tp start working on those user stories as they overlapped in functionality with the "In testing"/"Completed" user stories. These "To do" functionalities would be reassigne dto developers and worked on in a later sprint. 
 ## Screenshots
 ![image](https://github.com/cs100/final-project-spami-uakun-ialve-ado-bnguy/assets/139840775/5e7368c8-3af6-4713-8637-6e28c783640a)
![image](https://github.com/cs100/final-project-spami-uakun-ialve-ado-bnguy/assets/139840775/2e8fd291-7f5c-4e46-9d95-5edab2361c03)
![image](https://github.com/cs100/final-project-spami-uakun-ialve-ado-bnguy/assets/139840775/1ce83c09-ebfc-4fa8-93f8-9236124abbcf)
![image](https://github.com/cs100/final-project-spami-uakun-ialve-ado-bnguy/assets/139840775/f3844293-37e5-438b-b7b0-6363953cf65a)



 ## Installation/Usage
  > Good day to our users! Our pokemon game is a text-based rpg. To use our game, download the files from master branch into your local. From there, open the terminal where all the files are stored, and run these commands in order:
```
    cmake .
    make
    ./Pokemon
```

 > and enjoy our game! If you need to ever exit, press "Ctrl + C" and your game will be saved at whatever point in time you leave. You can resume your game by running the commands above, and then choosing the 'Resume Game' option! Enjoy Pokemon - a Text-based RPG Game! 
 ## Testing
 > Testing

Our game was thoroughly tested using a combination of unit tests, memory checking tools, and manual testing to ensure reliability, correctness, and memory safety.

**Unit Testing**
We used the Google Test framework to write and run unit tests for core functionalities, including Pokémon evolution, abilities, player inventory management, and game save/load functionality. These tests ensure each component behaves as expected.

**Memory Safety**
Valgrind was used to check for memory leaks and other memory-related issues. We ensured that all allocated memory is properly freed and that no leaks were present by running:

valgrind --leak-check=full ./Pokemon
 
