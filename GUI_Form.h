#pragma once
/*
 STB Error unresolved external symbol _stbi_load #3
Ref :https://github.com/nothings/stb/issues/3
From stb_image.h:
Do this:
#define STB_IMAGE_IMPLEMENTATION

Before you include this file in one C or C++ file to create the implementation.
That's because STB_IMAGE_IMPLEMENTATION needs to be defined within a .c or .cpp file, not within a header.
When you define STB_IMAGE_IMPLEMENTATION, you are creating the bulk of the stb_image code.
You only want that code to exist once, like the code in your own project,
which is why it has to be defined within a .c or .cpp file

*/


//Load Images
#define STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "include/stb_image.h"
// Write Images
#include "include/stb_image_write.h"

#include "Filter_Gpu.h"
#include"Filter_CPU.h"

#include <string>
#include <msclr\marshal_cppstd.h>

#include <chrono>

#include <iostream>

using namespace std::chrono;


namespace ModuleProject2023 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Diagnostics;
	using namespace System::IO;

	/// <summary>
	/// Summary for GUI_Form
	/// </summary>
	public ref class GUI_Form : public System::Windows::Forms::Form
	{
	public:
		GUI_Form(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~GUI_Form()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ Load_image;
	protected:
	private: System::Windows::Forms::Button^ Exit;
	private: System::Windows::Forms::Button^ Close_Image;
	private: System::Windows::Forms::PictureBox^ Input_Image_Box;
	private: System::Windows::Forms::PictureBox^ Output_Image_Box_01;
	private: System::Windows::Forms::PictureBox^ Output_Image_Box_02;

	private: System::Windows::Forms::LinkLabel^ Github;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::OpenFileDialog^ openFileDialog1;
	private: System::Windows::Forms::TextBox^ CPUTimeBox;

	private: System::Windows::Forms::TextBox^ GPUTimeBox;


	private: System::Windows::Forms::Label^ CPU_Timer;
	private: System::Windows::Forms::Label^ GPU_Timer;
	private: System::Windows::Forms::Label^ Timer;
	private: System::Windows::Forms::CheckBox^ GPU_ON;
	private: System::Windows::Forms::Button^ ImageToInv;

	private: System::Windows::Forms::Button^ ImageToRed;
	private: System::Windows::Forms::Label^ Filters;
	private: System::Windows::Forms::Button^ ImageToGray;

	private: System::Windows::Forms::Button^ ImageToGreen;
	private: System::Windows::Forms::Button^ ImageToBlue;


	private: System::Windows::Forms::Button^ ImageToHist;
	private: System::Windows::Forms::Label^ Pipeline_State_01_Label;
	private: System::Windows::Forms::TextBox^ Pipeline_State_01_textBox;
	private: System::Windows::Forms::Label^ Pipeline_State_02_Label;
	private: System::Windows::Forms::TextBox^ Pipeline_State_02_textBox;













	private: System::ComponentModel::IContainer^ components;




	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(GUI_Form::typeid));
			this->Load_image = (gcnew System::Windows::Forms::Button());
			this->Exit = (gcnew System::Windows::Forms::Button());
			this->Close_Image = (gcnew System::Windows::Forms::Button());
			this->Input_Image_Box = (gcnew System::Windows::Forms::PictureBox());
			this->Output_Image_Box_01 = (gcnew System::Windows::Forms::PictureBox());
			this->Output_Image_Box_02 = (gcnew System::Windows::Forms::PictureBox());
			this->Github = (gcnew System::Windows::Forms::LinkLabel());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->CPUTimeBox = (gcnew System::Windows::Forms::TextBox());
			this->GPUTimeBox = (gcnew System::Windows::Forms::TextBox());
			this->CPU_Timer = (gcnew System::Windows::Forms::Label());
			this->GPU_Timer = (gcnew System::Windows::Forms::Label());
			this->Timer = (gcnew System::Windows::Forms::Label());
			this->GPU_ON = (gcnew System::Windows::Forms::CheckBox());
			this->ImageToInv = (gcnew System::Windows::Forms::Button());
			this->ImageToRed = (gcnew System::Windows::Forms::Button());
			this->Filters = (gcnew System::Windows::Forms::Label());
			this->ImageToGray = (gcnew System::Windows::Forms::Button());
			this->ImageToGreen = (gcnew System::Windows::Forms::Button());
			this->ImageToBlue = (gcnew System::Windows::Forms::Button());
			this->ImageToHist = (gcnew System::Windows::Forms::Button());
			this->Pipeline_State_01_Label = (gcnew System::Windows::Forms::Label());
			this->Pipeline_State_01_textBox = (gcnew System::Windows::Forms::TextBox());
			this->Pipeline_State_02_Label = (gcnew System::Windows::Forms::Label());
			this->Pipeline_State_02_textBox = (gcnew System::Windows::Forms::TextBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Input_Image_Box))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Output_Image_Box_01))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Output_Image_Box_02))->BeginInit();
			this->SuspendLayout();
			// 
			// Load_image
			// 
			this->Load_image->Font = (gcnew System::Drawing::Font(L"Calibri", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Load_image->Location = System::Drawing::Point(15, 60);
			this->Load_image->Name = L"Load_image";
			this->Load_image->Size = System::Drawing::Size(160, 32);
			this->Load_image->TabIndex = 0;
			this->Load_image->Text = L"Load_Image";
			this->Load_image->UseVisualStyleBackColor = true;
			this->Load_image->Click += gcnew System::EventHandler(this, &GUI_Form::Load_image_Click);
			// 
			// Exit
			// 
			this->Exit->Font = (gcnew System::Drawing::Font(L"Calibri", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Exit->Location = System::Drawing::Point(15, 98);
			this->Exit->Name = L"Exit";
			this->Exit->Size = System::Drawing::Size(160, 32);
			this->Exit->TabIndex = 1;
			this->Exit->Text = L"Exit";
			this->Exit->UseVisualStyleBackColor = true;
			this->Exit->Click += gcnew System::EventHandler(this, &GUI_Form::Exit_Click);
			// 
			// Close_Image
			// 
			this->Close_Image->Font = (gcnew System::Drawing::Font(L"Calibri", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Close_Image->Location = System::Drawing::Point(20, 22);
			this->Close_Image->Name = L"Close_Image";
			this->Close_Image->Size = System::Drawing::Size(160, 32);
			this->Close_Image->TabIndex = 2;
			this->Close_Image->Text = L"Close_Image";
			this->Close_Image->UseVisualStyleBackColor = true;
			this->Close_Image->Click += gcnew System::EventHandler(this, &GUI_Form::Close_Image_Click);
			// 
			// Input_Image_Box
			// 
			this->Input_Image_Box->Location = System::Drawing::Point(15, 136);
			this->Input_Image_Box->MaximumSize = System::Drawing::Size(487, 466);
			this->Input_Image_Box->Name = L"Input_Image_Box";
			this->Input_Image_Box->Size = System::Drawing::Size(487, 466);
			this->Input_Image_Box->SizeMode = System::Windows::Forms::PictureBoxSizeMode::CenterImage;
			this->Input_Image_Box->TabIndex = 3;
			this->Input_Image_Box->TabStop = false;
			// 
			// Output_Image_Box_01
			// 
			this->Output_Image_Box_01->Location = System::Drawing::Point(534, 136);
			this->Output_Image_Box_01->MaximumSize = System::Drawing::Size(487, 466);
			this->Output_Image_Box_01->Name = L"Output_Image_Box_01";
			this->Output_Image_Box_01->Size = System::Drawing::Size(487, 466);
			this->Output_Image_Box_01->SizeMode = System::Windows::Forms::PictureBoxSizeMode::CenterImage;
			this->Output_Image_Box_01->TabIndex = 4;
			this->Output_Image_Box_01->TabStop = false;
			// 
			// Output_Image_Box_02
			// 
			this->Output_Image_Box_02->Location = System::Drawing::Point(1050, 136);
			this->Output_Image_Box_02->MaximumSize = System::Drawing::Size(487, 466);
			this->Output_Image_Box_02->Name = L"Output_Image_Box_02";
			this->Output_Image_Box_02->Size = System::Drawing::Size(487, 466);
			this->Output_Image_Box_02->SizeMode = System::Windows::Forms::PictureBoxSizeMode::CenterImage;
			this->Output_Image_Box_02->TabIndex = 5;
			this->Output_Image_Box_02->TabStop = false;
			// 
			// Github
			// 
			this->Github->AutoSize = true;
			this->Github->Font = (gcnew System::Drawing::Font(L"Cambria", 10.2F, System::Drawing::FontStyle::Underline, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Github->ImageAlign = System::Drawing::ContentAlignment::TopCenter;
			this->Github->Location = System::Drawing::Point(254, 610);
			this->Github->Name = L"Github";
			this->Github->Size = System::Drawing::Size(60, 20);
			this->Github->TabIndex = 7;
			this->Github->TabStop = true;
			this->Github->Text = L"GitHub";
			this->Github->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->Github->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, &GUI_Form::Github_LinkClicked);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Calibri", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(16, 607);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(184, 21);
			this->label1->TabIndex = 8;
			this->label1->Text = L"Antonio Souto Rodriguez";
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// CPUTimeBox
			// 
			this->CPUTimeBox->Font = (gcnew System::Drawing::Font(L"Calibri", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->CPUTimeBox->Location = System::Drawing::Point(1156, 56);
			this->CPUTimeBox->Name = L"CPUTimeBox";
			this->CPUTimeBox->Size = System::Drawing::Size(381, 29);
			this->CPUTimeBox->TabIndex = 9;
			// 
			// GPUTimeBox
			// 
			this->GPUTimeBox->Font = (gcnew System::Drawing::Font(L"Calibri", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->GPUTimeBox->Location = System::Drawing::Point(1156, 98);
			this->GPUTimeBox->Name = L"GPUTimeBox";
			this->GPUTimeBox->Size = System::Drawing::Size(381, 29);
			this->GPUTimeBox->TabIndex = 10;
			// 
			// CPU_Timer
			// 
			this->CPU_Timer->AutoSize = true;
			this->CPU_Timer->Font = (gcnew System::Drawing::Font(L"Calibri", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->CPU_Timer->Location = System::Drawing::Point(1046, 59);
			this->CPU_Timer->Name = L"CPU_Timer";
			this->CPU_Timer->Size = System::Drawing::Size(90, 23);
			this->CPU_Timer->TabIndex = 11;
			this->CPU_Timer->Text = L"CPU Timer";
			// 
			// GPU_Timer
			// 
			this->GPU_Timer->AutoSize = true;
			this->GPU_Timer->Font = (gcnew System::Drawing::Font(L"Calibri", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->GPU_Timer->Location = System::Drawing::Point(1046, 98);
			this->GPU_Timer->Name = L"GPU_Timer";
			this->GPU_Timer->Size = System::Drawing::Size(92, 23);
			this->GPU_Timer->TabIndex = 12;
			this->GPU_Timer->Text = L"GPU Timer";
			// 
			// Timer
			// 
			this->Timer->AutoSize = true;
			this->Timer->Font = (gcnew System::Drawing::Font(L"Calibri", 19.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Timer->Location = System::Drawing::Point(1155, 7);
			this->Timer->Name = L"Timer";
			this->Timer->Size = System::Drawing::Size(97, 40);
			this->Timer->TabIndex = 13;
			this->Timer->Text = L"Timer";
			this->Timer->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// GPU_ON
			// 
			this->GPU_ON->AutoSize = true;
			this->GPU_ON->Font = (gcnew System::Drawing::Font(L"Calibri", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->GPU_ON->Location = System::Drawing::Point(1442, 23);
			this->GPU_ON->Name = L"GPU_ON";
			this->GPU_ON->Size = System::Drawing::Size(95, 27);
			this->GPU_ON->TabIndex = 14;
			this->GPU_ON->Text = L"GPU ON";
			this->GPU_ON->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->GPU_ON->UseVisualStyleBackColor = true;
			// 
			// ImageToInv
			// 
			this->ImageToInv->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->ImageToInv->Font = (gcnew System::Drawing::Font(L"Calibri", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ImageToInv->Location = System::Drawing::Point(674, 61);
			this->ImageToInv->Name = L"ImageToInv";
			this->ImageToInv->Size = System::Drawing::Size(160, 32);
			this->ImageToInv->TabIndex = 15;
			this->ImageToInv->Text = L"Image To Inv";
			this->ImageToInv->UseVisualStyleBackColor = true;
			this->ImageToInv->Click += gcnew System::EventHandler(this, &GUI_Form::ImageToInv_Click);
			// 
			// ImageToRed
			// 
			this->ImageToRed->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->ImageToRed->Font = (gcnew System::Drawing::Font(L"Calibri", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ImageToRed->Location = System::Drawing::Point(840, 23);
			this->ImageToRed->Name = L"ImageToRed";
			this->ImageToRed->Size = System::Drawing::Size(160, 32);
			this->ImageToRed->TabIndex = 16;
			this->ImageToRed->Text = L"Image To Red";
			this->ImageToRed->UseVisualStyleBackColor = true;
			this->ImageToRed->Click += gcnew System::EventHandler(this, &GUI_Form::ImageToRed_Click);
			// 
			// Filters
			// 
			this->Filters->AutoSize = true;
			this->Filters->Font = (gcnew System::Drawing::Font(L"Calibri", 19.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Filters->Location = System::Drawing::Point(527, 7);
			this->Filters->Name = L"Filters";
			this->Filters->Size = System::Drawing::Size(101, 40);
			this->Filters->TabIndex = 17;
			this->Filters->Text = L"Filters";
			this->Filters->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// ImageToGray
			// 
			this->ImageToGray->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->ImageToGray->Font = (gcnew System::Drawing::Font(L"Calibri", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ImageToGray->Location = System::Drawing::Point(674, 22);
			this->ImageToGray->Name = L"ImageToGray";
			this->ImageToGray->Size = System::Drawing::Size(160, 32);
			this->ImageToGray->TabIndex = 18;
			this->ImageToGray->Text = L"Image To Gray";
			this->ImageToGray->UseVisualStyleBackColor = true;
			this->ImageToGray->Click += gcnew System::EventHandler(this, &GUI_Form::ImageToGray_Click);
			// 
			// ImageToGreen
			// 
			this->ImageToGreen->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->ImageToGreen->Font = (gcnew System::Drawing::Font(L"Calibri", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ImageToGreen->Location = System::Drawing::Point(840, 61);
			this->ImageToGreen->Name = L"ImageToGreen";
			this->ImageToGreen->Size = System::Drawing::Size(160, 32);
			this->ImageToGreen->TabIndex = 19;
			this->ImageToGreen->Text = L"Image To Green";
			this->ImageToGreen->UseVisualStyleBackColor = true;
			this->ImageToGreen->Click += gcnew System::EventHandler(this, &GUI_Form::ImageToGreen_Click);
			// 
			// ImageToBlue
			// 
			this->ImageToBlue->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->ImageToBlue->Font = (gcnew System::Drawing::Font(L"Calibri", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ImageToBlue->Location = System::Drawing::Point(840, 99);
			this->ImageToBlue->Name = L"ImageToBlue";
			this->ImageToBlue->Size = System::Drawing::Size(160, 32);
			this->ImageToBlue->TabIndex = 20;
			this->ImageToBlue->Text = L"Image To Blue";
			this->ImageToBlue->UseVisualStyleBackColor = true;
			this->ImageToBlue->Click += gcnew System::EventHandler(this, &GUI_Form::ImageToBlue_Click);
			// 
			// ImageToHist
			// 
			this->ImageToHist->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->ImageToHist->Font = (gcnew System::Drawing::Font(L"Calibri", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ImageToHist->Location = System::Drawing::Point(674, 99);
			this->ImageToHist->Name = L"ImageToHist";
			this->ImageToHist->Size = System::Drawing::Size(160, 32);
			this->ImageToHist->TabIndex = 21;
			this->ImageToHist->Text = L"Image To Hist";
			this->ImageToHist->UseVisualStyleBackColor = true;
			// 
			// Pipeline_State_01_Label
			// 
			this->Pipeline_State_01_Label->AutoSize = true;
			this->Pipeline_State_01_Label->Font = (gcnew System::Drawing::Font(L"Calibri", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Pipeline_State_01_Label->Location = System::Drawing::Point(530, 621);
			this->Pipeline_State_01_Label->Name = L"Pipeline_State_01_Label";
			this->Pipeline_State_01_Label->Size = System::Drawing::Size(137, 23);
			this->Pipeline_State_01_Label->TabIndex = 23;
			this->Pipeline_State_01_Label->Text = L"Pipeline State 01";
			// 
			// Pipeline_State_01_textBox
			// 
			this->Pipeline_State_01_textBox->Font = (gcnew System::Drawing::Font(L"Calibri", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Pipeline_State_01_textBox->Location = System::Drawing::Point(683, 618);
			this->Pipeline_State_01_textBox->Name = L"Pipeline_State_01_textBox";
			this->Pipeline_State_01_textBox->Size = System::Drawing::Size(338, 29);
			this->Pipeline_State_01_textBox->TabIndex = 22;
			// 
			// Pipeline_State_02_Label
			// 
			this->Pipeline_State_02_Label->AutoSize = true;
			this->Pipeline_State_02_Label->Font = (gcnew System::Drawing::Font(L"Calibri", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Pipeline_State_02_Label->Location = System::Drawing::Point(1046, 618);
			this->Pipeline_State_02_Label->Name = L"Pipeline_State_02_Label";
			this->Pipeline_State_02_Label->Size = System::Drawing::Size(137, 23);
			this->Pipeline_State_02_Label->TabIndex = 25;
			this->Pipeline_State_02_Label->Text = L"Pipeline State 02";
			// 
			// Pipeline_State_02_textBox
			// 
			this->Pipeline_State_02_textBox->Font = (gcnew System::Drawing::Font(L"Calibri", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Pipeline_State_02_textBox->Location = System::Drawing::Point(1209, 615);
			this->Pipeline_State_02_textBox->Name = L"Pipeline_State_02_textBox";
			this->Pipeline_State_02_textBox->Size = System::Drawing::Size(328, 29);
			this->Pipeline_State_02_textBox->TabIndex = 24;
			// 
			// GUI_Form
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ControlDark;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(1555, 650);
			this->Controls->Add(this->Pipeline_State_02_Label);
			this->Controls->Add(this->Pipeline_State_02_textBox);
			this->Controls->Add(this->Pipeline_State_01_Label);
			this->Controls->Add(this->Pipeline_State_01_textBox);
			this->Controls->Add(this->ImageToHist);
			this->Controls->Add(this->ImageToBlue);
			this->Controls->Add(this->ImageToGreen);
			this->Controls->Add(this->ImageToGray);
			this->Controls->Add(this->Filters);
			this->Controls->Add(this->ImageToRed);
			this->Controls->Add(this->ImageToInv);
			this->Controls->Add(this->GPU_ON);
			this->Controls->Add(this->Timer);
			this->Controls->Add(this->GPU_Timer);
			this->Controls->Add(this->CPU_Timer);
			this->Controls->Add(this->GPUTimeBox);
			this->Controls->Add(this->CPUTimeBox);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->Github);
			this->Controls->Add(this->Output_Image_Box_02);
			this->Controls->Add(this->Output_Image_Box_01);
			this->Controls->Add(this->Input_Image_Box);
			this->Controls->Add(this->Close_Image);
			this->Controls->Add(this->Exit);
			this->Controls->Add(this->Load_image);
			this->DoubleBuffered = true;
			this->ForeColor = System::Drawing::Color::Black;
			this->MinimumSize = System::Drawing::Size(1167, 631);
			this->Name = L"GUI_Form";
			this->Text = L"GUI 2023 - PROJECTS";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Input_Image_Box))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Output_Image_Box_01))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Output_Image_Box_02))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Close_Image_Click(System::Object^ sender, System::EventArgs^ e) {
		Input_Image_Box->ImageLocation = "";
		Output_Image_Box_01->Image = nullptr;
		Output_Image_Box_02->Image = nullptr;
	}
	private: System::Void Exit_Click(System::Object^ sender, System::EventArgs^ e) {
		Application::Exit();
	}
private: System::Void Load_image_Click(System::Object^ sender, System::EventArgs^ e) {
	// Diferent Methods to open images
	// Image.Frofile --> 1 St Method
	//Input_Image_Box->Image.FromFile("C:\Arquivos de Programas RFB\IRPF2022\online.png");

	//Load Image 2nd Method
	//Input_Image_Box->ImageLocation = "C:/Arquivos de Programas RFB/IRPF2022/online.png";
	//openFileDialog1->ShowDialog();

	// From OpenfileDialog --> 3rd Method
	OpenFileDialog^ ofd = gcnew OpenFileDialog();
	
	if (ofd->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
		Input_Image_Box->ImageLocation = ofd->FileName;
	}
}
private: System::Void panel1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
}
private: System::Void Github_LinkClicked(System::Object^ sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^ e) {
	// Specify that the link was visited.
	this->Github->LinkVisited = true;
	// Navigate to a URL.
	System::Diagnostics::Process::Start("https://github.com/AntonioRodriguezUFAM");
}
private: System::Void ImageToGray_Click(System::Object^ sender, System::EventArgs^ e) {
	// Image To Gray
	
	System::String^ file = Input_Image_Box->ImageLocation;
	std::string converted_xyz = msclr::interop::marshal_as< std::string >(file);
	int width, height, channels;
	const char* c = converted_xyz.c_str();
	//Open Image
	unsigned char* img = stbi_load(c, &width, &height, &channels, 4);
	
	double timeCPU=0,timeGPU = 0;
	int time = 0;

	// Check GPU enable
	if (GPU_ON->Checked) {
		useGPU GPU_obj;
		useGPU obj;
		time = obj.ImageToGrayGpu(img, width, height);
		//timeGPU = GPU_obj.ImageToGrayGpu(img, width, height);
		//timeGPU = GPU_obj.ImageToGreenGpu(img,width, height);
		
		GPUTimeBox->Text = "Tempo de Processamento - GPU: " + timeGPU.ToString() + " 탎";
	}
	// Check Stauts Devices CPU
	if (!GPU_ON->Checked) {
		useCPU CPU_obj;
		timeCPU=CPU_obj.ConvertImageToGrayCpu(img, width, height);
		CPUTimeBox->Text = "Tempo de Processamento - CPU:  " + timeCPU.ToString() + " 탎";
	}
	
	// Write Output Image
	stbi_write_png("images/output/ImageToGray.jpg", width, height, 4, img, 4 * width);
	Output_Image_Box_01->ImageLocation = "images/output/ImageToGray.jpg";
	// Free Image Memory
	stbi_image_free(img);
}
private: System::Void ImageToRed_Click(System::Object^ sender, System::EventArgs^ e) {
	// Image To Red

	System::String^ file = Input_Image_Box->ImageLocation;
	std::string converted_xyz = msclr::interop::marshal_as< std::string >(file);
	int width, height, channels;
	const char* c = converted_xyz.c_str();
	//Open Image
	unsigned char* img = stbi_load(c, &width, &height, &channels, 4);

	double timeCPU = 0, timeGPU = 0;

	// Check GPU enable
	if (GPU_ON->Checked) {
		useGPU GPU_obj;
		//timeGPU = GPU_obj.ImageToGrayGpu(img, width, height);
		GPUTimeBox->Text = "Tempo de Processamento - GPU: " + timeGPU.ToString() + " 탎";
	}
	// Check Stauts Devices CPU
	if (!GPU_ON->Checked) {
		useCPU CPU_obj;
		timeCPU = CPU_obj.ConvertImageToRedCPU(img, width, height);
		CPUTimeBox->Text = "Tempo de Processamento - CPU:  " + timeCPU.ToString() + " 탎";
	}

	// Write Output Image
	stbi_write_png("images/output/ImageToRed.jpg", width, height, 4, img, 4 * width);
	Output_Image_Box_01->ImageLocation = "images/output/ImageToRed.jpg";
	// Free Image Memory
	stbi_image_free(img);

}
private: System::Void ImageToGreen_Click(System::Object^ sender, System::EventArgs^ e) {

	// Image To Green

	System::String^ file = Input_Image_Box->ImageLocation;
	std::string converted_xyz = msclr::interop::marshal_as< std::string >(file);
	int width, height, channels;
	const char* c = converted_xyz.c_str();
	//Open Image
	unsigned char* img = stbi_load(c, &width, &height, &channels, 4);

	double timeCPU = 0, timeGPU = 0;

	// Check GPU enable
	if (GPU_ON->Checked) {
		useGPU GPU_obj;
		//timeGPU = GPU_obj.ImageToGrayGpu(img, width, height);
		GPUTimeBox->Text = "Tempo de Processamento - GPU: " + timeGPU.ToString() + " 탎";
	}
	// Check Stauts Devices CPU
	if (!GPU_ON->Checked) {
		useCPU CPU_obj;
		timeCPU = CPU_obj.ConvertImageToGreenCPU(img, width, height);
		CPUTimeBox->Text = "Tempo de Processamento - CPU:  " + timeCPU.ToString() + " 탎";
	}

	// Write Output Image
	stbi_write_png("images/output/ImageToGreen.jpg", width, height, 4, img, 4 * width);
	Output_Image_Box_01->ImageLocation = "images/output/ImageToGreen.jpg";
	// Free Image Memory
	stbi_image_free(img);

}
private: System::Void ImageToBlue_Click(System::Object^ sender, System::EventArgs^ e) {

	// Image To Blue

	System::String^ file = Input_Image_Box->ImageLocation;
	std::string converted_xyz = msclr::interop::marshal_as< std::string >(file);
	int width, height, channels;
	const char* c = converted_xyz.c_str();
	//Open Image
	unsigned char* img = stbi_load(c, &width, &height, &channels, 4);

	double timeCPU = 0, timeGPU = 0;

	// Check GPU enable
	if (GPU_ON->Checked) {
		useGPU GPU_obj;
		//timeGPU = GPU_obj.ImageToGrayGpu(img, width, height);
		GPUTimeBox->Text = "Tempo de Processamento - GPU: " + timeGPU.ToString() + " 탎";
	}
	// Check Stauts Devices CPU
	if (!GPU_ON->Checked) {
		useCPU CPU_obj;
		timeCPU = CPU_obj.ConvertImageToBlueCPU(img, width, height);
		CPUTimeBox->Text = "Tempo de Processamento - CPU:  " + timeCPU.ToString() + " 탎";
	}

	// Write Output Image
	stbi_write_png("images/output/ImageToBlue.jpg", width, height, 4, img, 4 * width);
	Output_Image_Box_01->ImageLocation = "images/output/ImageToBlue.jpg";
	// Free Image Memory
	stbi_image_free(img);

}
private: System::Void ImageToInv_Click(System::Object^ sender, System::EventArgs^ e) {

	// Image To Inverte

	System::String^ file = Input_Image_Box->ImageLocation;
	std::string converted_xyz = msclr::interop::marshal_as< std::string >(file);
	int width, height, channels;
	const char* c = converted_xyz.c_str();
	//Open Image
	unsigned char* img = stbi_load(c, &width, &height, &channels, 4);

	double timeCPU = 0, timeGPU = 0;

	// Check GPU enable
	if (GPU_ON->Checked) {
		useGPU GPU_obj;
		//timeGPU = GPU_obj.ImageToInvGpu(img, width, height);
		GPUTimeBox->Text = "Tempo de Processamento - GPU: " + timeGPU.ToString() + " 탎";
	}
	// Check Stauts Devices CPU
	if (!GPU_ON->Checked) {
		useCPU CPU_obj;
		timeCPU = CPU_obj.ConvertImageToRedCPU(img, width, height);
		CPUTimeBox->Text = "Tempo de Processamento - CPU:  " + timeCPU.ToString() + " 탎";
	}

	// Write Output Image
	stbi_write_png("images/output/ImageToInv.jpg", width, height, 4, img, 4 * width);
	Output_Image_Box_01->ImageLocation = "images/output/ImageToInv.jpg";
	// Free Image Memory
	stbi_image_free(img);

}
};
}
