// Sample2.cpp: define o ponto de entrada para o aplicativo.
//

#include "Sample2.h"

using namespace std;

class Sample2 {

public:
	GLFWwindow* Window;
	int WINDOW_WIDTH = 800,
		WINDOW_HEIGHT = 600;

	Sample2();
	bool initialize();
	static void resize(GLFWwindow* Window, int w, int h);
	void render();
private:
};

Sample2::Sample2()
{

}

bool Sample2::initialize()
{

	assert(glfwInit() == GLFW_TRUE);

	Window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Sample 2", nullptr, nullptr);

	// Enable depth testing
	glEnable(GL_DEPTH_TEST);
	// Set up the projection matrix
	resize(Window, WINDOW_WIDTH, WINDOW_HEIGHT);

	glfwSetFramebufferSizeCallback(Window, resize);

	glfwMakeContextCurrent(Window);
	// Habilita ou desabilita o V-Sync
	glfwSwapInterval(0);

	return true;
}

void Sample2::resize(GLFWwindow* Window, int w, int h)
{
	// Prevent a divide by zero error
	if (h <= 0)
	{
		h = 1;
	}

	// When we resize the window, we tell OpenGL about the new viewport size
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);

	glMatrixMode(GL_PROJECTION); // deprecated

	glLoadIdentity();

	// then ew set up our projection matrix with the correct aspect ratio
	gluPerspective(60.0f, float(w) / float(h), 1.0f, 100.0f); // deprecated

	glMatrixMode(GL_MODELVIEW); // deprecated
	glLoadIdentity(); // deprecated

}

void Sample2::render()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	gluLookAt(
		0.0, 1.0, 6.0, // Position
		0.0, 0.0, 0.0, // Where we are looking
		0.0, 1.0, 0.0  // Up Vector
	);

	glBegin(GL_TRIANGLES);
	//  Send the vertices and colors for triangle
	glColor4f(1.0f, 0.0f, 0.0f, 1.0f);
	glVertex3f(2.0f, 2.5f, -1.0f);
	glColor4f(0.0f, 1.0f, 0.0f, 1.0f);
	glVertex3f(-3.5f, -2.5f, -1.0f);
	glColor4f(0.0f, 0.0f, 1.0f, 1.0f);
	glVertex3f(2.0f, -4.0f, -1.0f);
	glEnd();

	glBegin(GL_TRIANGLE_FAN);
	// Send the vertices and colors for the pentagon
	glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
	glVertex3f(-1.0f, 2.0f, 0.0f);
	glColor4f(1.0f, 1.0f, 0.0f, 1.0f);
	glVertex3f(-3.0f, -0.5f, 0.0f);
	glColor4f(0.0f, 1.0f, 1.0f, 1.0f);
	glVertex3f(-1.4f, -3.0f, 0.0f);
	glColor4f(0.0f, 0.0f, 0.0f, 1.0f);
	glVertex3f(1.0f, -2.0f, 0.0f);
	glColor4f(1.0f, 0.0f, 1.0f, 1.0f);
	glVertex3f(1.0f, 1.0f, 0.0f);
	glEnd();
}

int main()
{
	//cout << "Hello CMake." << endl;
	Sample2 sample;

	sample.initialize();
	sample.resize(sample.Window, sample.WINDOW_WIDTH, sample.WINDOW_HEIGHT);

	while (!glfwWindowShouldClose(sample.Window))
	{
		sample.render();

		glfwPollEvents();
		glfwSwapBuffers(sample.Window);
	}

	// Encerra a biblioteca GLFW
	glfwTerminate();

	return 0;
}
