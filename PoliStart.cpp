#include "PoliStart.h"
 
using namespace System;
using namespace  System::Windows::Forms;

[STAThread]
void main() //se pueden eliminar los argumentos del main
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew Polidash::PoliStart());
}