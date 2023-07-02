class Sample1
{
	int WINDOW_WIDTH = 800;
	int WINDOW_HEIGHT = 600;

public:
	bool initialize();
	void resize(int w, int h);
private:
};

bool Sample1::initialize()
{
	// Enable depth testing
	glEnable(GL_DEPTH_TEST);
	// Set up the projection matrix
	resize(WINDOW_WIDTH, WINDOW_HEIGHT);
	return true;
}

void Sample1::resize(int w, int h)
{
	// Prevent divide by zero error
	if (h <= 0)
	{
		h = 1;
	}

	// When we resize the window, we tell OpenGL about the new viewport size
	glViewPort(0, 0, (GLsizei)w, (GLsizei)h);

	glMatrixModel(GL_PROJECTION); //deprecated

	glLoadIdentity();

	// Then ew set up our projection matrix with the correct aspect ratio
	gluPerspective(60.0f, float(w) / float(h), 1.0f, 100.0f); //deprecated

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity(); //deprecated
}

void main() {

	Sample1::initialize();

}