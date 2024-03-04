# Documentation
______________________________________________
## How To Begin
1. Write the `int main(int argc, char* argv[]` loop
2. Then, inside the loop, call MEngine and create a window by using `__call_name__.createWindow(string title, int width, int height, boolean fullscreen, boolean resizable)`
3. Finally, write the rest function `__call_name__.restRender()` first, and then the show render `__call_name__.showRender()` and update functions `__call_name__.updateRender(boolean run)` in that order. *NOTE: You will be putting all your game assets that you want to render between the rest and show render function.
______________________________________________
## Drawing Rectangles
Between the rest and show render functions, use your call varaible to call the `.drawRectangle(int (x, y), int width, int height, int r, int g, int b, boolean showOutlineOnly)` function.

***EXAMPLE:*** <br />
int pos[2] = { 50, 50 }; <br />
screen.drawRectangle(pos, 50, 50, 155, 155, 155, false);
______________________________________________
## Drawing Lines
Between the rest and show render functions, use your call varaible to call the `.drawLine(int point1 (x, y), int point2 (x, y), int r, int g, int b)` function.

***EXAMPLE:*** <br />
int pos[2] = { 50, 50 }; <br />
int pos2[2] = { 100, 100 }; <br />
screen.drawRectangle(pos, pos2, 155, 155, 155);
