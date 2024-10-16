# so_long
A 2D game where a character must collect all the collectibles and escape the map. The game uses the MiniLibX library for graphics.

## 🎮 Description
• The player’s goal is to collect every collectible present on the map, then escape
chosing the shortest possible route. <br/> 
• The W, A, S, and D keys must be used to move the main character. <br/>
• The player should be able to move in these 4 directions: up, down, left, right. <br/>
• The player should not be able to move into walls. <br/>
• At every move, the current number of movements must be displayed in the shell. <br/>
• You have to use a 2D view (top-down or profile). <br/>
• The game doesn’t have to be real time. <br/>

## 🎨 Graphic management
• Your program has to display the image in a window. <br/>
• The management of your window must remain smooth (changing to another window, minimizing, and so forth). <br/>
• Pressing ESC must close the window and quit the program in a clean way. <br/>
• Clicking on the cross on the window’s frame must close the window and quit the
program in a clean way. <br/>
• The use of the images of the MiniLibX is mandatory. <br/>

## 🗺️ Map
• The map has to be constructed with 3 components: walls, collectibles, and free
space. <br/>
• The map can be composed of only these 5 characters: <br/>
&emsp; &emsp; 0 for an empty space, <br/>
&emsp; &emsp; 1 for a wall, <br/>
&emsp; &emsp; C for a collectible, <br/>
&emsp; &emsp; E for a map exit, <br/>
&emsp; &emsp; P for the player’s starting position <br/>
• The map must contain 1 exit, at least 1 collectible, and 1 starting position to
be valid. <br/>
The map must be rectangular. <br/>
• The map must be closed/surrounded by walls. If it’s not, the program must return
an error. <br/>
• You have to check if there’s a valid path in the map. <br/>
• You must be able to parse any kind of map, as long as it respects the above rules. <br/>
• If any misconfiguration of any kind is encountered in the file, the program must
exit in a clean way, and return "Error\n" followed by an explicit error message of
your choice.

## 💡 Bonus
• Make the player lose when they touch an enemy patrol.
• Display the movement count directly on screen instead of writing it in the shell.
