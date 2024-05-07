Phase I - Proposal (Due Monday 4/22/2024 10:00 pm)  due before lab (Thursday Night) 

You will be completing Phase I prompts in the README.md file in your project GitHub repository. The README.md file will need to have:

Title of the project: A Text-Based Role-Playing Game (RPG) - Pokemon 

Group member names & links to github pages:  Sricharan Pamireddy (https://github.com/Sricharan-Pamireddy), Uma Akundi (https://github.com/umizoomiexe), Isabela Sforcin(https://github.com/sforcin), Brandon Nguyen(https://github.com/bnguy408), Andrew Do(https://github.com/androodo)

A Project description:

Why is it important or interesting to you?
  This project allows for creativity and an ability to be flexible with the details such as characters, attack strategies, and levels. It gives an opportunity to expand once a basic skeleton is made, allowing us to add components if time permits. 

What languages/tools/technologies do you plan to use?
  We will use C++ and a command line interface, along with some C++ standard libraries. We don’t plan on using any external libraries at this time. 

What will be the input/output of your project?
  The input of the project will be from the keyboard input from users and also files that can be read. The output will be text output to the console as the game is being played and also data being written to files.

What are the features that the project provides?
  Ability to store previous games (ongoing or completed) 
  The ability to load previous games to be resumed.
  NPC’s having predetermined actions based on user input
  Playable character options
  Different items and weapons (healing items, different weapon types and materials) 
  Player inventories (how much storage available)
  Character actions and abilities
  Experience and Levels (Characters gaining or losing experience based on actions/ levels unlocking access to more items) 




 > As you complete each section you **must** remove the prompt text. Every *turnin* of this project includes points for formatting of this README so keep it clean and keep it up to date. 
 > Prompt text is any lines beginning with "\>"
 > Replace anything between \<...\> with your project specifics and remove angle brackets. For example, you need to name your project and replace the header right below this line with that title (no angle brackets). 
# <A Text-Based Role-Playing Game (RPG) - Pokemon>
 > Your author list below should include links to all members GitHub (remove existing author).
 
 > Authors: Sricharan Pamireddy (https://github.com/Sricharan-Pamireddy), Uma Akundi (https://github.com/umizoomiexe), Isabela Sforcin(https://github.com/sforcin), Brandon Nguyen(https://github.com/bnguy408), Andrew Do(https://github.com/androodo)

 > You will be forming a group of **FOUR** students and working on an interesting project. The project has 4 phases, each one with specific requirements. A list of proposed project ideas that have been successful in previous quarters is listed in the project specifications document on Canvas. You can select an idea from the list and start thinking about the features you will implement. If you want to propose your own original idea, you will have to contact your instructor to discuss the project and obtain written permission before you submit your project proposal (Phase 1). The project work should be divided almost equally among team members. You can of course help each other, but it needs to be clear who will be responsible for which features. Additionally, you are expected to follow Scrum patterns, specifically the use of a Scrum (Project) board, Sprints, and Scrum meetings.
 > ## Expectations
 > * The backend of your project should be implemented in C++. If you wish to choose anoher programming language (e.g. Java, Python), please discuss with your lab TA to obtain permission.
 > * You can incorporate additional technologies/tools but they must be approved (in writing) by the instructor or the TA.
 > * Each member of the group **must** be committing code regularly and make sure their code is correctly attributed to them. We will be checking attributions to determine if there was equal contribution to the project.
 > * **Each member of the group must actively participate in the Github Project board, writing unit tests, and reviewing commited code.**
> * All project phases are to be submitted to this GitHub repository. You should modify this README file to reflect the different phases of the project. In addition, you should regularly hold sprint meetings with your group. You will need to hold two to three scrum/check-in meetings with your lab TA/reader at different times in addition to the final demo.
## Project Description
 > Your project description should summarize the project you are proposing. Be sure to include:
 > * Why is it important or interesting to you?
 > * What languages/tools/technologies do you plan to use? (This list may change over the course of the project)
 > * What will be the input/output of your project?
 > * What are the features that the project provides?
 > This description should be in enough detail that the TA/instructor can determine the complexity of the project and if it is sufficient for the team members to complete in the time allotted. 
 > 
 > You also need to set up an empty project board using GitHub projects (board view with default columns). Make sure you add the board under your project repository. You should also have a Product Backlog and In testing columns added. All columns should be in the right order.
 > ## Phase II
 > In addition to completing the "User Interface Specification" and "Class Diagram" sections below, you will need to:
 > * Create an "Epic" (note) for each feature. Place these epics in the `Product Backlog` column
 > * Complete your first *sprint planning* meeting to plan out the next 7 days of work.
 >   * Break down the "Epics" into smaller actionable user stories (i.e. smaller development tasks). Convert them into issues and assign them to team members. Place these in the `TODO` column (aka Sprint Backlog).
 >   * These cards should represent roughly 7 days worth of development time for your team. Then, once the sprint is over you should be repeating these steps to plan a new sprint, taking you until your second scrum meeting with the reader in phase III.
 > * Schedule two check-ins using Calendly. Both time slots should be during your lab on week 6. Your entire team must be present for both check-ins.
 >   * The first check-in needs to be scheduled with your lab TA. During that meeting, you will discuss your project design/class diagram from phase II.
 >   * The second check-in should be scheduled with a reader. During that meeting you will discuss:
 >     * The tasks you are planning for the first sprint
 >     * How work will be divided between the team members
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
This is a general layout of our UI screens. Users will have options to input "1", "2", "3", etc... to choose where to navigate. We plan to have a similar Text-based layout when it comes to attacking within the game/ actually playing the game itself. If time permits, we may choose to incoorperate a visual component (however, this is undecided as of now).
## Class Diagram
![App Screenshot](https://github.com/cs100/final-project-spami-uakun-ialve-ado-bnguy/blob/master/UML%20class%20Pokemon%20(1).png)
 > Include a **class diagram(s)** for your project and a **description** of the diagram(s). Your class diagram(s) should include all the main classes you plan for the project. This should be in sufficient detail that another group could pick up the project this point and successfully complete it. Use proper UML notation (as discussed in the course slides).
 
 > ## Phase III
 > You will need to schedule a check-in for the second scrum meeting with the same reader you had your first scrum meeting with (using Calendly). Your entire team must be present. This meeting will occur on week 8 during lab time.
 
 > BEFORE the meeting you should do the following:
 > * Update your class diagram from Phase II to include any feedback you received from your TA/grader.
 > * Considering the SOLID design principles, reflect back on your class diagram and think about how you can use the SOLID principles to improve your design. You should then update the README.md file by adding the following:
 >   * A new class diagram incorporating your changes after considering the SOLID principles.
 >   * For each update in your class diagram, you must explain in 3-4 sentences:
 >     * What SOLID principle(s) did you apply?
 >     * How did you apply it? i.e. describe the change.
 >     * How did this change help you write better code?
 > * Perform a new sprint plan like you did in Phase II.
 > * You should also make sure that your README file (and Project board) are up-to-date reflecting the current status of your project and the most recent class diagram. Previous versions of the README file should still be visible through your commit history.
 
> During the meeting with your reader you will discuss: 
 > * How effective your last sprint was (each member should talk about what they did)
 > * Any tasks that did not get completed last sprint, and how you took them into consideration for this sprint
 > * Any bugs you've identified and created issues for during the sprint. Do you plan on fixing them in the next sprint or are they lower priority?
 > * What tasks you are planning for this next sprint.

 > ## Final deliverable
 > All group members will give a demo to the reader during lab time. ou should schedule your demo on Calendly with the same reader who took your second scrum meeting. The reader will check the demo and the project GitHub repository and ask a few questions to all the team members. 
 > Before the demo, you should do the following:
 > * Complete the sections below (i.e. Screenshots, Installation/Usage, Testing)
 > * Plan one more sprint (that you will not necessarily complete before the end of the quarter). Your In-progress and In-testing columns should be empty (you are not doing more work currently) but your TODO column should have a full sprint plan in it as you have done before. This should include any known bugs (there should be some) or new features you would like to add. These should appear as issues/cards on your Project board.
 > * Make sure your README file and Project board are up-to-date reflecting the current status of your project (e.g. any changes that you have made during the project such as changes to your class diagram). Previous versions should still be visible through your commit history. 
 
 ## Screenshots
 > Screenshots of the input/output after running your application
 ## Installation/Usage
 > Instructions on installing and running your application
 ## Testing
 > How was your project tested/validated? If you used CI, you should have a "build passing" badge in this README.
 
