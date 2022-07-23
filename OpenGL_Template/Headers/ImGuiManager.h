#pragma once

struct GLFWwindow;

class ImGuiManager
{
public:
	void ImGui_CreateContext(GLFWwindow* glfwWindow);
	void ImGui_NewFrame();
	void ImGui_Render();
	void ImGui_Shutdown();
};