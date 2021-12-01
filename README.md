# Snake
## A personal rendition of the original snake game. Evolution below!

### The first snake:  
> ![image](https://user-images.githubusercontent.com/56971161/115440100-39c7f600-a1c4-11eb-8ef0-8f3e4b17caba.png)  
> Added a linked list to store the snake. A normal array would probably be more efficient, but a linked list has a little more fun.
  
### User input can be received:  
> ![image](https://user-images.githubusercontent.com/56971161/116749477-dacd6280-a9b5-11eb-949f-b446b3255688.png)  
> Using a do while loop to receive user input.
  
### New arena and snake movement:  
> ![](https://i.gyazo.com/257cd6934a3d632a93a4aea25b93013d.gif)  
> The movement feels a little bit clunky and the snake will only move once after every directional key press.

### Addition of the Curses library:  
> ![](https://i.gyazo.com/aaf138ec6463615af6cb9418bf5bc426.gif)  
> Implemented Curses library to receive the user input, display the game, tweak game speed, etc. 

### Pause feature / Snake movement update:  
> ![](https://i.gyazo.com/c659a263532e68554ae4f5242f1330de.gif)  
> Added pause feature and further advanced snake movements. The snake will no longer be able to turn into itself (ie. snake going left cannot flip to the right).  

### Fully functional apple:
> ![](https://i.gyazo.com/a57b3f992313b95af12c1c0f12123f3a.gif)  
> A single apple will spawn at random coordinates in the arena. The apple will always spawn two blocks from the arena border because it is sometimes difficult to perceive the distance between the snake and arena border.  
