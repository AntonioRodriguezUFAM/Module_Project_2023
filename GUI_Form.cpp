#include "GUI_Form.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThread]
void main()
{
     Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    ModuleProject2023::GUI_Form form;
    
    Application::Run(% form);
    }