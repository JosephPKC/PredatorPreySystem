# PredatorPreySystem
A Predator Prey simulation made in C++, using Qt OpenGL.
This program was written in C++, and using Qt Creator and Qt OpenGL.
This was written for CS 3A for PCC.

This program will simulate an environment with different species. 
Do note, that this is not meant to be in any way accurate. This is simply a simple simulation of fake creatures.

# Creatures
-Predators hunt Prey, and nothing else. This is your generic predator.
-Prey, on the other hand, do not have to eat. Instead, they are hunted by the other creatures.
-Hunters are the alpha predators. They hunt other Preadators and Prey, but they also hunter other Hunters.
-Infected are creatures that "breed" by hunting. Whenever they hunt another non-Infected creature, they instead turn that creature into an Infected.

# GUI
-The GUI has toggles to enabled Hunters and Infected.
-The GUI has text boxes for you to set the parameters: starting numbers for each creature, and the breed, eating, and life parameters.
-The GUI has labels to denote the current populations of each creature.
