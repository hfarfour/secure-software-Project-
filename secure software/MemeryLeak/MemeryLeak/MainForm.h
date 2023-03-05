#pragma once
#include<malloc.h>
#include<iostream>

namespace MemeryLeak {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void)
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
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ membutton;
	protected:

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->membutton = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// membutton
			// 
			this->membutton->Location = System::Drawing::Point(113, 111);
			this->membutton->Name = L"membutton";
			this->membutton->Size = System::Drawing::Size(100, 52);
			this->membutton->TabIndex = 0;
			this->membutton->Text = L"Use up some memory";
			this->membutton->UseVisualStyleBackColor = true;
			this->membutton->Click += gcnew System::EventHandler(this, &MainForm::membutton_Click);
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 261);
			this->Controls->Add(this->membutton);
			this->Name = L"MainForm";
			this->Text = L"MainForm";
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void membutton_Click(System::Object^ sender, System::EventArgs^ e)
	{
		long* p = (long*)malloc(1024 * 1024 * 100);
		if (p == NULL)
		{
			MessageBox::Show("out of memory butt!");
		}

	}
	};
}
