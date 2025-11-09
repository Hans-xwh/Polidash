#pragma once

#include "PoliGame.h"
#include "Victoria.h"
#include "Derrota.h"
#include "Instrucciones.h"

namespace Polidash {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Media;

	/// <summary>
	/// Summary for PoliStart
	/// </summary>
	public ref class PoliStart : public System::Windows::Forms::Form
	{
	public:

		SoundPlayer^ sonidito = gcnew SoundPlayer("Audio/TimeMachine.wav");

		PoliStart(void)
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
		~PoliStart()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ btn_player;
	private: System::Windows::Forms::Button^ btn_auto;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Button^ button5;




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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(PoliStart::typeid));
			this->btn_player = (gcnew System::Windows::Forms::Button());
			this->btn_auto = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// btn_player
			// 
			this->btn_player->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btn_player.BackgroundImage")));
			this->btn_player->Font = (gcnew System::Drawing::Font(L"Wide Latin", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_player->ForeColor = System::Drawing::Color::Yellow;
			this->btn_player->Location = System::Drawing::Point(605, 256);
			this->btn_player->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->btn_player->Name = L"btn_player";
			this->btn_player->Size = System::Drawing::Size(457, 103);
			this->btn_player->TabIndex = 0;
			this->btn_player->Text = L"JUGADOR";
			this->btn_player->UseVisualStyleBackColor = true;
			this->btn_player->Click += gcnew System::EventHandler(this, &PoliStart::btn_player_Click);
			// 
			// btn_auto
			// 
			this->btn_auto->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btn_auto.BackgroundImage")));
			this->btn_auto->Font = (gcnew System::Drawing::Font(L"Wide Latin", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_auto->ForeColor = System::Drawing::Color::Yellow;
			this->btn_auto->Location = System::Drawing::Point(605, 383);
			this->btn_auto->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->btn_auto->Name = L"btn_auto";
			this->btn_auto->Size = System::Drawing::Size(460, 99);
			this->btn_auto->TabIndex = 1;
			this->btn_auto->Text = L"AUTOMATICO";
			this->btn_auto->UseVisualStyleBackColor = true;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Cursor = System::Windows::Forms::Cursors::Cross;
			this->label1->Font = (gcnew System::Drawing::Font(L"Broadway", 58.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::Yellow;
			this->label1->ImageAlign = System::Drawing::ContentAlignment::BottomRight;
			this->label1->Location = System::Drawing::Point(511, 50);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(612, 110);
			this->label1->TabIndex = 2;
			this->label1->Text = L"/PoliDash\\";
			this->label1->Click += gcnew System::EventHandler(this, &PoliStart::label1_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::Color::Yellow;
			this->pictureBox1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.BackgroundImage")));
			this->pictureBox1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pictureBox1->Location = System::Drawing::Point(337, 50);
			this->pictureBox1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(195, 155);
			this->pictureBox1->TabIndex = 3;
			this->pictureBox1->TabStop = false;
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->button1->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->button1->Location = System::Drawing::Point(67, 222);
			this->button1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(235, 122);
			this->button1->TabIndex = 4;
			this->button1->Text = L"PRUEBAS PANTALLA L";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &PoliStart::button1_Click);
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->button2->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->button2->Location = System::Drawing::Point(67, 377);
			this->button2->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(235, 122);
			this->button2->TabIndex = 5;
			this->button2->Text = L"PRUEBAS PANTALLA W";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &PoliStart::button2_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Cursor = System::Windows::Forms::Cursors::Cross;
			this->label2->Font = (gcnew System::Drawing::Font(L"Broadway", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::Color::Yellow;
			this->label2->ImageAlign = System::Drawing::ContentAlignment::BottomRight;
			this->label2->Location = System::Drawing::Point(707, 179);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(251, 26);
			this->label2->TabIndex = 6;
			this->label2->Text = L"Elige una opción..";
			// 
			// button3
			// 
			this->button3->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button3.BackgroundImage")));
			this->button3->Font = (gcnew System::Drawing::Font(L"Wide Latin", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button3->ForeColor = System::Drawing::Color::Yellow;
			this->button3->Location = System::Drawing::Point(447, 515);
			this->button3->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(751, 45);
			this->button3->TabIndex = 7;
			this->button3->Text = L"INSTRUCCIONES";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &PoliStart::button3_Click);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(22, 568);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(120, 26);
			this->button4->TabIndex = 8;
			this->button4->Text = L"Play Music";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &PoliStart::button4_Click);
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(182, 568);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(120, 26);
			this->button5->TabIndex = 9;
			this->button5->Text = L"Stop Music";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &PoliStart::button5_Click);
			// 
			// PoliStart
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(1421, 606);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->btn_auto);
			this->Controls->Add(this->btn_player);
			this->ForeColor = System::Drawing::SystemColors::ControlText;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->MaximizeBox = false;
			this->Name = L"PoliStart";
			this->Text = L"PoliDash: Menu";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void btn_player_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Hide();
		PoliGame^ game = gcnew PoliGame();
		game->ShowDialog();
		this->Close();
	}
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Hide();
	Derrota^ game = gcnew Derrota();
	game->ShowDialog();
	this->Close();
}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Hide();
	Victoria^ game = gcnew Victoria();
	game->ShowDialog();
	this->Close();
}
private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Hide();
	Instrucciones^ game = gcnew Instrucciones();
	game->ShowDialog();
	this->Close();
}

private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
	sonidito->PlayLooping();
}
private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) {
	sonidito->Stop();
}
};
}
