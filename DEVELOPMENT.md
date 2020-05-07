# Development

---
4/21/2020 :
* Added audio for flying bird.
* Drew circular bird.
* Implemented functionality to keep track of score.

4/22/2020 :
* Changed what external library to use from Cinder-Bullet3D to json library.

4/23/2020
* Drew few rectangles to represent pipes.
* Randomized height of pipes.

4/25/2020 :
* Researched animation in Cinder by reading "Hello Cinder" guide online. 
* Based on research about cinder animation, changed existing code
about drawing pipes so that I only draw one pipe at a time and store
 pipes in a linked list.
 
4/26/2020 :
* Went through list of pipes from top pipes and bottom pipes and 
updated position of each pipe.
* Implemented functionality to choose how many pipes should be added to list.
* Fixed bug about pipes after they leave screen. To fix it, I changed the
position of the pipes back to the beginning of the screen when they are 
about to leave the screen.

4/27/2020 :
* Drew background including sky and ground.
* Changed color of pipes.
* Changed position of pipes and spacing between each top and bottom 
pipe to make the game moderately difficult .
* Made game over screen. For now since there is no collision the game over 
screen is shown when the j button is pressed instead of when there is a 
collision.
* Refactored code about scores. Used json library to store latest score 
of player in a json file and read the file.
* Added PrintText function used to print "Game Over" and the score in
game over screen. 

4/28/2020 :
* Made my own physics and added gravity to bird so that it falls 
at a rate of 9.8 meters per second. 
* Added functionality to make bird jump by increasing y position of bird 
when user presses down space bar.

4/30/2020:
* Drew Main Menu screen by drawing original background without the bird 
and then created simple logo for name of the game which was displayed in 
the middle of the screen. 
* Added instructions for user to press the p button to play game
*After realizing that there is a small time period that glitches between
when the user exits the main menu screen and enters screen for playing 
the game, I fixed the bug by not allowing for collision to be counted
during the first few frames after the user exits the main menu screen.

5/1/2020:
* Instead of just printing the score at the end of the game, I printed 
score during the game as well so player can see progress in score while 
they are playing.
* Resized game by changing size of app window, and changing size and 
positions of pipes and text.

5/2/2020:
* Added function to check for collision in pipe_engine class.
* Ran into issues involving not being able to get the accurate position 
of bird based on how it was falling and jumping.
* Fixed bug by adding function to check for collision in myApp class
and adding get methods within bird and pipe_engine_ class to retrieve 
positions of pipes and bird.
* While including different header files, there was a bug involving circular
dependencies. To fix it, I removed header files that I included which I was 
not using. 

5/4/2020:
* Added functionality to reset game by allowing user to press on tab button
which would move user back to main menu state and resetting score back to 0.
* To fix bug about bird disappearing when game was reset, I reset the 
position of the bird as well when resetting game. 

5/5/2020:
* Added documentation and comments in header files to make code more clear. 
* Renamed functions and variables so that they were more clear and followed 
Google style guide. 
* Changed absolute file paths to just local file paths. 
* Created member variables to magic numbers. 
