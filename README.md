# IntelligentAgent-WumpusWorld


The Wumpus world is a simple world example to illustrate the worth of a knowledge-based agent and to represent knowledge representation. It was inspired by a video game Hunt the Wumpus by Gregory Yob in 1973.

The Wumpus world is a cave which has 4/4 rooms connected with passageways. So there are total 16 rooms which are connected with each other. We have a knowledge-based agent who will go forward in this world. The cave has a room with a beast which is called Wumpus, who eats anyone who enters the room. The Wumpus can be shot by the agent, but the agent has a single arrow. In the Wumpus world, there are some Pits rooms which are bottomless, and if agent falls in Pits, then he will be stuck there forever. The exciting thing with this cave is that in one room there is a possibility of finding a heap of gold. So the agent goal is to find the gold and climb out the cave without fallen into Pits or eaten by Wumpus. The agent will get a reward if he comes out with gold, and he will get a penalty if eaten by Wumpus or falls in the pit.

This library of a model-based agent will obtain the percepts received from the the environment (namely the Wumpus World game) and make decisions based on Rule-Matching.

## Getting Started

Clone the repository
### Prerequisites

c++14

### Building the repository

```bash
cd IntelligentAgent-WumpusWorld
mkdir build
cd build
cmake ..
make
./wwia
```

## Running the tests


## Authors

* **Arisema mezgebe** - *Initial work* - [PurpleBooth]()
* **Yonathan Cherkos** - *Initial work* - [PurpleBooth]()
* **Eden melaku** - *Initial work* - [PurpleBooth]()

See also the list of [contributors](https://github.com/arisemaM/IntelligentAgent-WumpusWorld/contributors) who participated in this project.

## License

This project is licensed under the MIT License - see the [LICENSE.md](LICENSE.md) file for details
