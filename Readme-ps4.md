# PS4: N-Body Simulation

## Contact
Name: Dhruvkumar Patel
Section: 204
Time to Complete: 10 hours around


## Description
Explain what the project does.
In this projected i wrote the universe constructor that reads the file that is provided which contain the information about the radius , numplanets, position, velocity , mass,imagefile and getter function for the radius,numplanets,velocity, position and mass and all this getter function get the data from the operator>>. Also the draw function in the universe helps to render all the celestial body with the universe and renders the taregt and the draw function in the celestialbody its draw the celestial body according to the positions and in celestialbody.cpp operator>> reads the details of a celestial body like position,velocity, mass and image name and also load the texture for the celestial body and calculate the position on the window with the help of the radius and window dimension. Overall, the project does universe constructor read the data of the numplanets and universe radius and the celestial body data and the draw method for the both in the universe and the celestialbody is used to draw the celestial body on the window with the specific position and everything and both overload operator used in universe and celestial body helps for the input and the output of the objects and used of the shared pointer for the managing the memory.
PARTB

In this we created moveacceleration,moveplanet in the celestialBody and step function in the universe what it does that in the moveacc which calculate all the physics works which is first it calculated the distance between the current body and the other body and then it compute the square of the distance and direct distance with the help of the gravitational force F and we calculate the force of the each component and then also the acceleration of both the component by dividing the force by th emass of the current body. At last it updates the velocities of the current body by adding the product of the acceleration and time. In movepla this updates the position of the celestial body depends on the velocity and the time and also updates the position recalculating the screen coordinates where the the body should be drawn and the step function in the universe it iterates every celestial bodies calling the moveacc on each body to updates its velocity based on the gravitational influnce of every other body and then it iterates through all the bodies again and the calling the function movepla to updates its position based on its velocity of the each planet. and in the command line first argument is T and the second value which is the delat_t and t starts at 0.0 and it continue as long as t < T using the leapfrog scheme and when the animation stops it print out the final states of the universe in the terminal.
### Features
Describe what your major decisions were and why you did things that way.
The major decision i took was to used shared pointer rather than vector because it automaticall manages the memory of the objects and use of the shared pointer is that celestialBody can be shared at different part of the code wihout manual managing the memory and helps from the memory leak. This helps to implement the feauture of the celestial bodies when needed to be accessed or modify from the multiple places and it automatic cleanup.

PARTB
Here i made the function moveacc and movepla in the CelestialBody so it make easy for calculation and evrything it makes clean to see and also easy to access the value of the position, velocity and mass for the calculation and with the help to this calculated the physics formula all in the moveacc and updates the velocity and the in move pla it calculated the position and this function can me directly called by the step function to calculate the position and velocity of each of the body and update it which make it easy for me to do this way.

### Memory
Describe how you managed the lifetimes of your objects, including if you used smart pointers.
I used the shared pointer because it is easy for managing the meomory it automatical manages the memory of the object it points to and for the lifetime of the objects as long as the there least one shared pointer to an object it remains alive if the last shared pointer to the object is destroyed the object is also deleted. The use of the shared pointer in project id for the managing the celestialBody it easy for the memory management and it for automatic cleaup it prevents from the memory leaks.

PartB
As i used the shared pointer which helped me in the step function because it updates the velocity and the position of all the celestiaBody based on the gravitational interaction without any fear of accessing the wrong elements or deleting memeory and also in the moveacc and movepla which update the position and velocity with the help of the shared pointer it makes it easy for the updating each bodies position and velocity without the fear of the memory leak and the lifetime of the celestial bodies were managed automatically. Mainly in part b the main part was to handle the position and velocity of each celestial body.

### Issues
What did you have trouble with?  What did you learn?  What doesn't work?  Be honest.  You might be penalized if you claim something works and it doesn't.
I was having problem how to set the bodies to the centre of the sfml windows but then the professor helped in the discord that how you can do it so that it the centre of the sfml window and figured out to manage the scaling of the window size and getting to the centre of the window and also had problem when submitting to the gardescope it fails the formatting issue and it should be in folder and asked the professor the formatting he told to write the test for the operator and it helped to worked with the test also.

Partb
There was no issue but having the issue when uploding in the gardescope it was not passing the test for the anti gravity and all so i made a test to check the position and velocity after the animation and then it worked.

### Extra Credit
Anything special you did.  This is required to earn bonus points.
If you created your own universe file.  Describe it here and explain why it is interesting.
Only the extra thing i have done is that added the background image in the sfml window which was already provided in the folder i used that and created texture and sprite to load and draw the image for the background.

Partb

Nothing done for the extra credit.

## Acknowledgements
List all sources of help including the instructor or TAs, classmates, and web pages.
If you used images or other resources than the ones provided, list them here.

I got most the help from the professor in the discord and just used the background image from the nbody folder.

PartB
As i  was having trouble in the test cases then i got the helped from the discord as most of the question were answered by the professor and it helped me to pass all the test accept the extra credit.
