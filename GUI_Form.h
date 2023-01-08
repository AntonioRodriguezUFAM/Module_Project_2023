#pragma once

#include "Gpu.h"
#include "include/stb_image.h"
#include "include/stb_image_write.h"


//Load Images
#define STB_IMAGE_IMPLEMENTATION
// Write Images
#define STB_IMAGE_WRITE_IMPLEMENTATION


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
	private: System::Windows::Forms::Timer^ timer1;










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
			this->components = (gcnew System::ComponentModel::Container());
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
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Input_Image_Box))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Output_Image_Box_01))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Output_Image_Box_02))->BeginInit();
			this->SuspendLayout();
			// 
			// Load_image
			// 
			this->Load_image->Location = System::Drawing::Point(21, 8);
			this->Load_image->Name = L"Load_image";
			this->Load_image->Size = System::Drawing::Size(101, 32);
			this->Load_image->TabIndex = 0;
			this->Load_image->Text = L"Load_Image";
			this->Load_image->UseVisualStyleBackColor = true;
			this->Load_image->Click += gcnew System::EventHandler(this, &GUI_Form::Load_image_Click);
			// 
			// Exit
			// 
			this->Exit->Location = System::Drawing::Point(1443, 35);
			this->Exit->Name = L"Exit";
			this->Exit->Size = System::Drawing::Size(94, 32);
			this->Exit->TabIndex = 1;
			this->Exit->Text = L"Exit";
			this->Exit->UseVisualStyleBackColor = true;
			this->Exit->Click += gcnew System::EventHandler(this, &GUI_Form::Exit_Click);
			// 
			// Close_Image
			// 
			this->Close_Image->Location = System::Drawing::Point(21, 48);
			this->Close_Image->Name = L"Close_Image";
			this->Close_Image->Size = System::Drawing::Size(101, 32);
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
			// GUI_Form
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ControlDark;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(1555, 650);
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
};
}
