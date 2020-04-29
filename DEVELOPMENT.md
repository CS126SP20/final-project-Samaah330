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
when user presses down space bar. However, I need to work on this part more 
because it is not complete since the jump is not smooth.


