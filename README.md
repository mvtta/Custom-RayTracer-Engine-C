# miniRT
## Mini raytracing engine implementation -> rendering of simple CGI.

###### Experimenting with
```
gcc -framework OpenGL -framework AppKit libmlx.dylib  rtlib.h get_next_line.h get_next_line.c get_next_line_utils.c rt_utils.c ft_split.c parse.c minirt.c 

./a.out scene_test.rt
```

###### Stage of the project
```
Todo: 
1) background in gradient
2) decide if convert all rgb to hex
3) make room or put plane according to cam position
4) put light
```

###### Subject
```
"This project is an introduction to the beautiful world of Raytracing.  
 Once completed you will be able to render simple Computer-Generated-Images"
```
###### About
```
"In nature, a light source emits a ray of light which travels, eventually,  
to a surface that interrupts its progress. One can think of this "ray" as a stream of photons  
traveling along the same path. In a perfect vacuum this ray will be a straight line  
(ignoring relativistic effects). Any combination of four things might happen with this  
light ray: absorption, reflection, refraction and fluorescence. "
```
```
Instead of following the light path from it's source, wich would result in unnecessary  
computation, the basic idea is to reverse the light path from the "eye" or "camera".
```
## Research

[PurpleAlien](https://www.purplealienplanet.com/node/20)  
[Divide&Conquer](https://cs.swansea.ac.uk/wordpressvc/wp-content/uploads/2012/10/d-and-c-ray-tracing.pdf)  
[miniLibx](https://harm-smits.github.io/42docs/libs/minilibx/getting_started.html)  
[GlobalIllumination](http://www.kevinbeason.com/smallpt/)  
[RayTracingOneWeekend-book](https://raytracing.github.io/books/RayTracingInOneWeekend.html)  
[RayTracingOneWeekend-code](https://github.com/RayTracing/raytracing.github.io/blob/master/booksRayTracingInOneWeekend.html)  
[Cray](https://awesomeopensource.com/project/vkoskiv/c-ray)  
[Technical](https://www.slideshare.net/SyedZaidIrshad/ray-tracing-74531533)  


## Steps
```
0-> Collecting resources to suport my research
1-> Exploring minilibx && math.h functions
2-> Install Xquartz for window (u actually don't need this with minilxlib)
3-> test.c to init mlx && open window (basic window management) 
4-> test2.c pushing pixels to the window
5-> learned: vectors, 3D graphics fundamentals.  
6-> found vector lib made by Mashpoe and I'm going to try that out. made sense to have   vectors as arrays with it's special name instead of a structure.  

```
[vector lib by Mashpoe](https://github.com/Mashpoe/c-vector)

![small red pixel on window](https://github.com/m4r11/02.miniRT/blob/master/media/Screen%20Shot%202021-04-12%20at%2011.46.29.png)


## Glossary
```
endian: denoting or relating to two systems of ordering data, in which the most   significant unit is put either first or last.  
radian: is a pure measure based on the Radius of the circle. To go from radians to   degrees: multiply by 180, divide by π. To go from degrees to radians: multiply by π,   divide by 180   
float Degrees = Radians * 180.0f / 3.14159265359f  
float Radian = Degrees * 3.14159265359f / 180.0f  
The C language uses radians instead of degrees when calculating angles. Humans should   use radians as well, as they're logical and easy to work with (radians, not humans).  



```
=======
