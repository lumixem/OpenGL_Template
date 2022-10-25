# OpenGL Visual Studio Template

This is a simple OpenGL template created in Visual Studio. It supports OpenGL version 4.6 or below.

The template already displays a simple triangle, contains a Dear ImGui context and displays an ImGui window, therefore it is easy to build upon and expand. 

## Building
1. Download the zip
2. Extract to your desired location
3. Open the .sln file
4. Build the solution. The .vcxproj will then appear

## Current features:
- [**GLFW**](https://www.glfw.org/)
- [**GLAD**](https://glad.dav1d.de/)
- [**Dear ImGui**](https://github.com/ocornut/imgui)
- [**glm**](https://glm.g-truc.net/0.9.9/) as a maths library 
- [**stb_image**](https://github.com/nothings/stb) for loading images/textures
- **Loading shaders from files**

### Features to add:
- Model loading using [assimp](https://github.com/assimp/assimp) or [tiny obj loader](https://github.com/tinyobjloader/tinyobjloader)
- An input system

![triangle](https://user-images.githubusercontent.com/78048342/180626613-707dd39b-b443-4b4a-b1c6-1e585c9d40ff.png)

This project is licensed under the terms of the MIT license.
