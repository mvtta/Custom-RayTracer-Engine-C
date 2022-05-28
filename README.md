<h2 align="center">
A (Mini) Raytracer Engine

</h2>
<h6 align="left">
Exploring the principles of raytracing, subject by 42 school.
</h6>

<h2>
</h2>

###### Cover image for project: from external web link 
![IMG_COVER](https://va.media.tumblr.com/tumblr_rccusoQ7SN1z7v8no_720.mp4)

<iframe width="560" height="315"
src="https://va.media.tumblr.com/tumblr_rccusoQ7SN1z7v8no_720.mp4" 
frameborder="0" 
allow="accelerometer; autoplay; encrypted-media; gyroscope; picture-in-picture" 
allowfullscreen></iframe>

#### Abstract 

```
Exploring the basics: The goal of such project, under the directions of 42 Pedagogy council, was to get us, students, to better understand the basic concepts of Graphic's Programing. As a personal quest, I added, the principles of math and physics, the foundation of our collective understanding of the universe.
                        In University, while studying Visual Culture, Semiotics with minor in Photography, it was commonly said in class that a Photograph is a drawing by light. While doing this project, its was a recurring thought, that raytracing is a sort of "painting by numbers".
                        Due to time constrains and my own personal limitations I didn't get to deep dive into photon behavior and other fascinating topics.

- In Part I, you may find the mandatory features of the 42 requirements to validate ths project. 
- In Part II, the extra features I've been working on. 
```

###### Part I

| Allowed libs | Allowed c functions | Shapes | Light System | Interactions |
|:------------:|:-------------------:|:------:|:------------:|:------------:|
| Libft + Minilibx| open, close, read, write, printf , malloc, free, perror, strerror, exit | plane, sphere, cylinder | You must implement Ambient and diffuse lighting | Pressing ESC must close the window and quit the program cleanly.  Clicking on the red cross on the window’s frame must close the window and quit the program cleanly. |

###### Renders I 


[objects_gi]: https://64.media.tumblr.com/95040833b48c66b3aa8e2b21f6c0516b/468d61b557d29e28-6e/s1280x1920/91d1443692d3cb572451a20c21ab1b311963db4c.png
[objects_sl]: variable value
[random]: variable value

Global Light  |  Spot Light
:------------:|:-------------------------:
![objects_gi] |  ![objects_sl]


|<img src="">|<img src="">|<img src="">


|<img src="">|<img src="">|<img src="">
=======
| sphere | cylinder | plane |
|:-------------------------:|:-------------------------:|:-------------------------:|
|<img src="https://64.media.tumblr.com/867a0a8548de0f4ea4b20995b1718552/6f82792bfefedfd5-11/s1280x1920/7a476bdf8b1a8135470cfb35bd22f3481420a860.pnj" width="200"> sub here|<img src="https://64.media.tumblr.com/8a89afa303e35e3b7ecdc12af7a256f3/6f82792bfefedfd5-d5/s1280x1920/6d9596d6e4ae985eea2510e29afc56fc33e31d72.pnj" width="200"> sub here|<img src="https://64.media.tumblr.com/df1b61f396d351c89c528f254d45c62f/6f82792bfefedfd5-37/s1280x1920/049f8fc3d6bf10e8dad1673624d85aad1b506a79.pnj" width="200"> sub here|<img src="https://64.media.tumblr.com/d02bf83e4f84a922b2fc2b3db5242e93/6f82792bfefedfd5-07/s2048x3072/4586c66567075e424166075f22e483c31b751c15.pnj" width="300"> sub here|<img src="https://64.media.tumblr.com/4cd662c870a7d0c3ccc1f6290bc4d3b2/6f82792bfefedfd5-94/s2048x3072/b38ba2b92918a69c0665f5e310659aa3a447b8e6.pnj" width="300"> sub here|<img src="https://64.media.tumblr.com/bca0384e480db8a57f51472efe8b4655/6f82792bfefedfd5-b3/s2048x3072/4b22b52dbbb010d96ee841b47daa23da35bc1dfe.pnj" width="300"> sub here|
<img src="https://64.media.tumblr.com/bca0384e480db8a57f51472efe8b4655/6f82792bfefedfd5-b3/s2048x3072/4b22b52dbbb010d96ee841b47daa23da35bc1dfe.pnj" width="300"> sub here|<img src="https://64.media.tumblr.com/150c50f11d69c0f2d070752cb56c898b/11dd4897a0228e1e-e2/s2048x3072/e64667920fbc4b2098e4a8ff82cc995592029ef9.pnj" width="300"> sub here|<img src="https://64.media.tumblr.com/97cbef294cc150e810d90c57fdc9abe9/11dd4897a0228e1e-4d/s2048x3072/e65e057a1b0ac380ee721ce89e64f7c0b40a0e1c.pnj" width="300"> sub here|<img src="https://64.media.tumblr.com/a4c59b9870a40056c3e3931a195623f7/11dd4897a0228e1e-a4/s2048x3072/ca453266dc6eb7e9af8ad162217f91130c9b8654.pnj" width="300"> sub here|<img src="https://64.media.tumblr.com/f98a201d001c3fa914338e4f785129e5/11dd4897a0228e1e-d7/s2048x3072/250153bd044c97c23fd42b11dc2d652c060714a0.pnj" width="300"> sub here|


###### Part II 

```
Exploring some more:

```
###### Part II Renders

| | | |
|:-------------------------:|:-------------------------:|:-------------------------:|
|<img src="https://64.media.tumblr.com/c5b04f340576ce5859ac69e6401450e3/6dab6b5c26e26f6c-30/s1280x1920/4b3d1abd358d41def4dbfb5b8d5ae40254d0cc88.jpg" width="200"> sub here|<img src="https://64.media.tumblr.com/33dbe83c6197a3cd6ad4310a0a5486bd/2176a82ead6fd58d-91/s1280x1920/beee5984a9e174ca46131c6196b61cc562744bb4.jpg" width="200"> sub here|<img src="https://64.media.tumblr.com/8da44fb8814ac1482f4a909f99f8ca41/2176a82ead6fd58d-89/s1280x1920/a16611cf91e0ba0ab41823313ff41dc4eb0cf3da.jpg" width="200"> sub here|<img src="https://64.media.tumblr.com/30b98071c89271d8b2de5f8caeb60885/27d8b878f7373bc3-45/s1280x1920/33724b1b0f3bf754bcb9b1613026e853d6c09be1.jpg" width="300"> sub here|

###### Project Structure

- [Block](#######-Block-I)
    * [Block](#######-Block-2)
    * [Block](#######-Block-2)
    * [Block](#######-Block-2)
- [Block](#######-Block-I)
    * [Block](#######-Block-2)
    * [Block](#######-Block-2)
    * [Block](#######-Block-2)

###### Custom Libraries 

| info one | info two |
|:---------:|:-----------------:|
|one | :) |
|two | :) |
|three| :) |
|four| :) |
|five| :) |

###### Custom Data Structures 

| info one | info two |
|:---------:|:-----------------:|
|one | :) |
|two | :) |
|three| :) |
|four| :) |
|five| :) |

###### Other Features Implemented

| | | |
|:-------------------------:|:-------------------------:|:-------------------------:|
|<img src="https://64.media.tumblr.com/c5b04f340576ce5859ac69e6401450e3/6dab6b5c26e26f6c-30/s1280x1920/4b3d1abd358d41def4dbfb5b8d5ae40254d0cc88.jpg" width="200"> sub here|<img src="https://64.media.tumblr.com/33dbe83c6197a3cd6ad4310a0a5486bd/2176a82ead6fd58d-91/s1280x1920/beee5984a9e174ca46131c6196b61cc562744bb4.jpg" width="200"> sub here|<img src="https://64.media.tumblr.com/8da44fb8814ac1482f4a909f99f8ca41/2176a82ead6fd58d-89/s1280x1920/a16611cf91e0ba0ab41823313ff41dc4eb0cf3da.jpg" width="200"> sub here|<img src="https://64.media.tumblr.com/30b98071c89271d8b2de5f8caeb60885/27d8b878f7373bc3-45/s1280x1920/33724b1b0f3bf754bcb9b1613026e853d6c09be1.jpg" width="300"> sub here|

###### Features to implement

- bullet one
- bullet two
- bullet three
- bullet four

###### Interaction Commands

| info one | info two |
|:---------:|:-----------------:|
|one | :) |
|two | :) |
|three| :) |
|four| :) |
|five| :) |

###### Compile 

```bash
make
```
###### Interact

```bash
$ echo The value of variable x = $x
```

###### Wip 

| info one | info two |
|:---------:|:-----------------:|
|one | :) |
|two | :) |
|three| :) |
|four| :) |
|five| :) |


###### Research 

>[LINK1](https://)  
>[LINK2](https://)  
>[LINK3](https://)  
>[LINK4](https://)  

###### Acknowledgements 

```
Final notes. 
Sure, a real-life Epstein drive is still a few  
breakthroughs away. But the rocket-building game  
lets you pilot a fusion-propelled craft right now.
```
###### Languages used (extended version)
[![Top Langs](https://github-readme-stats.vercel.app/api/top-langs/?username=m4r11&langs_count=8&layout=compact&theme=dark&align="center")](https://github.com/m4r11/github-readme-stats)
---  

###### Badges
![shell](https://img.shields.io/badge/Shell_Script-121011?style=for-the-badge&logo=gnu-bash&logoColor=white)
![sql](https://img.shields.io/badge/MySQL-00000F?style=for-the-badge&logo=mysql&logoColor=white)
![mark](https://img.shields.io/badge/Markdown-000000?style=for-the-badge&logo=markdown&logoColor=white)

![c](https://img.shields.io/badge/C-00599C?style=for-the-badge&logo=c&logoColor=white)
![py](https://img.shields.io/badge/Python-14354C?style=for-the-badge&logo=python&logoColor=white)
![php](https://img.shields.io/badge/PHP-777BB4?style=for-the-badge&logo=php&logoColor=white)

[![GitHub Stars](https://img.shields.io/github/stars/IgorAntun/node-chat.svg)](https://github.com/m4r11/Template-Project)
[![GitHub Issues](https://img.shields.io/github/issues/IgorAntun/node-chat.svg)](https://github.com/m4r11/Template-Project/issues)
[![Current Version](https://img.shields.io/badge/version-1.0.7-green.svg)](https://github.com/m4r11/Template-Project)
[![Live Demo](https://img.shields.io/badge/demo-online-green.svg)](https://github.com/m4r11/Template-Project)
[![Gitter](https://badges.gitter.im/Join%20Chat.svg)](https://github.com/m4r11/Template-Project?utm_source=badge&utm_medium=badge&utm_campaign=pr-badge)
![madebash](https://img.shields.io/badge/Made%20with-Bash-1f425f.svg)
