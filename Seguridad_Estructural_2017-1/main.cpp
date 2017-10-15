#include "main.h"

int main(int argCount, char* arguments[])
{
	// Esta es una lista de las teclas que sea estar�n monitoreando.
	ConfigurationManager cm("configuracion_teclas.txt");

	// kw estar� monitoreando las teclas contenidas en key tan pronto se llame al m�todo run.
	KeyboardWatch kw(cm.getKeys());

	kw.getListeners()->push_front(&DetectionRecord());

	// Una vez configurados los listeners, se llama al m�todo run.
	kw.run();

	return 0;
}