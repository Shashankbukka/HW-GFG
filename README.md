# HW-GFG
Assignments of Fall 17 GFG course (Grad Level - 691)
Class Page : https://www.csee.umbc.edu/~olano/class/491-17-8/


# Description
Unreal Engine source code was utilized for all the assigments.
There are a total of four assigments in the course, which vary from basic texture mapping to Volumetric cloud rendering and adding a PostProcess Pass into the engine source code.

# Assignment 1 : Baking Computation

The aim for this assignment is to Bake expensive content to a texture. An emissive material with a couple of noise nodes provides the cloud like structure.

![image](https://user-images.githubusercontent.com/31554097/47885803-41855b80-de0d-11e8-8ba1-301b276eaa0b.png)


-> Create an emissive material based on the object texture coordinates and at least one Voronoi noise and one Perlin noise node to make a cloud-like texture designed to seamlessly wrap
-> Create a Render Target texture and add a "Level Blueprint" to draw your noise material into the render target texture at BeginPlay.
-> Create a second emissive material that uses texture coordinates to look up in the render target texture.
-> Use ProfileGPU to collect timings for Baked and Computed textures


# Assignment 2 : Code Scripting

Use shaders and C++ scripting in UE4 and create 3D materials and spawn the texture from a C++ Actor.

![image](https://user-images.githubusercontent.com/31554097/47886124-b6a56080-de0e-11e8-95ff-1c5cae54fa46.png)

-> Create the Baked texture from the previous assignment.
-> Create an Actor with a C++ actor component.
-> Bake the material through the C++ actor component.
-> Bake a 3D Material into slices and pack it into a 2D Texture.
-> Create a material to use this tiled texture, turning the 3D position into 2D texture coordinates for the lookup.

# Assignment 3 : Volumetrics 

Make simple engine changes, raymarch in a shader and provide volumetric cloud texture for the Sky Sphere.

# Assignment 4 : Post Processing

Add a new Post Processing Pass using existing similar code in the engine
