
- [Dynamic Path Planning Module](#dynamic-path-planning-module)
- [Required Packages](#required-packages)
- [Building the Project](#building-the-project)
- [Supported Planning Models](#supported-planning-models)
- [Example](#example)

# Dynamic Path Planning Module

The intent of this module is to provide a drop-in module to generate directed graphs and dynamically plan routes between nodes.

# Required Packages

A few packages are needed to be able to compile the tracking program. These packages are readily available using [vcpkg](https://github.com/microsoft/vcpkg) provided by Microsoft. The installation of `vcpkg` should reside in the root directory. The following commands will install the needed packages.

```bash
$ vcpkg install --triplet=x64  gtest
```

An additional dependancy is required which handles the Linear Algebra aspects of the module. This module can be found at the following location.

```bash
$ git clone https://github.com/EthanHowellUKY/linear-algebra.git
```

# Building the Project

This project is configured to build as a library and will produce no executable. The provided `CMakeLists.txt` build file is built to adhere to the following file structure.

```txt
./
+-- libs/
|   +-- PathPlanning/
|   |   +-- .gitignore
|   |   +-- .gitattributes
|   |   +-- include/
|   |   |   +-- PathPlanning/
|   |   |   |   +-- AStar.h
|   |   |   |   +-- Planner.h
|   |   |   |   +-- PlannerFactory.h
|   |   |   |   +-- RRTStar.h
|   |   |   +-- Graph/
|   |   |   |   +-- Graph.h
|   |   |   |   +-- Node.h
|   |   +-- src/
|   |   |   +-- AStar.cpp
|   |   |   +-- Graph.cpp
|   |   |   +-- Node.cpp
|   |   |   +-- Planner.cpp
|   |   |   +-- PlannerFactory.cpp
|   |   |   +-- RRTStar.cpp
|   |   +-- test/
|   |   |   +-- CMakeLists.txt
|   |   |   +-- path-test.cpp
|   |   +-- CHANGELOG.md
|   |   +-- CMakeLists.txt
|   |   +-- LICENSE.md
|   |   +-- README.md
|   +-- LinearAlgebra/
|   |   +-- ...
|   |   +-- ...
|   |   +-- ...
+-- src/
|   +-- main.cpp
|   +-- CMakeLists.txt
+-- CMakeLists.txt
```

To follow this structure, add these lines to  `./CMakeLists.txt`

```cmake
...
set(CMAKE_INCLUDE_CURRENT_DIR ON)

add_subdirectory(libs/PathPlanning)
add_subdirectory(src)
...
```

And add these lines to `src/CMakeLists.txt`

```cmake
...
project(${CMAKE_PROJECT_NAME} CXX)
file(GLOB_RECURSE HEADER_FILES *.h)
file(GLOB_RECURSE SRC_FILES *.cpp)
...

...
target_link_libraries(${CMAKE_PROJECT_NAME}
    echo::linearalgebra
    echo::pathplanning
)
...
```

# Supported Planning Models

Currently, only A* is supported to generate paths on a directed graph. Future implementations are in progress to support the RRT* algorithm as well as A* search over a grid.

# Example

The following example shows how the module can be used to build a simple graph and generate a path between two nodes. Because the Nodes are connected to one another as linked lists, each node needs to be initialized as a pointer.

```cpp
#include <iostream>
#include <string>
#include <deque>

#include "Graph/Node.h"
#include "PathPlanning/PlannerFactory.h"

int main(int argc, char *argv[])
{
	Planner *path_planner = PlannerFactory::create(PATHPLANNER::ASTAR);

	Node *x1 = new Node(1, "X1", std::vector<float>{0, 0, 0});
	Node *x2 = new Node(2, "X2", std::vector<float>{1, 0, 0});
	Node *x3 = new Node(3, "X3", std::vector<float>{1, 10, 0});
	Node *x4 = new Node(4, "X4", std::vector<float>{2, 0, 0});

	/*
					 ( x_3 )
				    o
				   /  \
				 /     \
		( x_1 ) o -- o -- o ( x_4 )
	    		 ( x_2 )
	*/
	
	x1->add_edge(x2, DIRECTION::BIDIRECTIONAL);
	x1->add_edge(x3, DIRECTION::BIDIRECTIONAL);
	x2->add_edge(x4, DIRECTION::BIDIRECTIONAL);
	x3->add_edge(x4, DIRECTION::BIDIRECTIONAL);

	x1->g = 0;

	std::deque<Node *> path = path_planner->get_path(x1, x4);
	path_planner->print_path(path); // X1 -> X2 -> X4

	delete x1;
	delete x2;
	delete x3;
	delete x4;

	return 0;
}
```
