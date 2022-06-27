# About The Project
Spartox is a small game where the player can roam around the map (explore) and find encounters (combat). Explore the map, find points of interest, beat the encounter and finish the game.

# Built with
Softwares that are used to create this project are:
* Unreal Engine 5.0.2
* Blender

# Roadmap
This is the current roadmap of the project:
- [x] FSM - for player and AI control
   - [x] BaseState
   - [x] BaseStateController
- [x] Player FSM - for easier player control
   - [x] PlayerBaseState
   - [x] Other states that inherit from player base state
   - [x] Blueprintable version of said states
- [ ] Inventory System
   - [X] Item base class
   - [ ] Item data-base 
   - [ ] Blueprintable Item
   - [ ] Equipable, usable, throwable, destroyable items
- [ ] Player Components  
   - [x] Movement component
   - [ ] Interact component
   - [ ] Inventory component
- [ ] Pathfinding system
   - [ ] Generate nodes
   - [ ] Generate grid
   - [ ] Create A* pathfinding algorithm
   - [ ] Generate a path
   - [ ] Create a spline from the points for smooth movement

# Systems
* FSM - Finite State Machine that is used to control the state of the player/AI at any point in the game. Every object that has the FSM can only have one active state. This is useful because when there is an error while object is in a certain state it is very easy to debug since every state does only one thing, we can write every behavior of the object in that state (animation to play, sound to play, what to do, etc.) as well as there is no enumerators cluttered all over the palce for the state behavior of the object. Below is the example of the FSM in action. 

https://user-images.githubusercontent.com/79630981/174326130-131d8f13-4be4-427f-ab5c-57570e2e97bb.mp4
