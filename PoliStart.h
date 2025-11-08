#pragma once

#include "PoliGame.h"

namespace Polidash {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for PoliStart
	/// </summary>
	public ref class PoliStart : public System::Windows::Forms::Form
	{
	public:
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
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// btn_player
			// 
			this->btn_player->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btn_player.BackgroundImage")));
			this->btn_player->Font = (gcnew System::Drawing::Font(L"Wide Latin", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_player->ForeColor = System::Drawing::Color::Yellow;
			this->btn_player->Location = System::Drawing::Point(445, 221);
			this->btn_player->Name = L"btn_player";
			this->btn_player->Size = System::Drawing::Size(595, 142);
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
			this->btn_auto->Location = System::Drawing::Point(445, 393);
			this->btn_auto->Name = L"btn_auto";
			this->btn_auto->Size = System::Drawing::Size(595, 142);
			this->btn_auto->TabIndex = 1;
			this->btn_auto->Text = L"AUTOMATICO";
			this->btn_auto->UseVisualStyleBackColor = true;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Cursor = System::Windows::Forms::Cursors::Cross;
			this->label1->Font = (gcnew System::Drawing::Font(L"Broadway", 48, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::Yellow;
			this->label1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"label1.Image")));
			this->label1->ImageAlign = System::Drawing::ContentAlignment::BottomRight;
			this->label1->Location = System::Drawing::Point(535, 91);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(505, 91);
			this->label1->TabIndex = 2;
			this->label1->Text = L"/PoliDash\\";
			this->label1->Click += gcnew System::EventHandler(this, &PoliStart::label1_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.BackgroundImage")));
			this->pictureBox1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pictureBox1->Location = System::Drawing::Point(322, 60);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(195, 135);
			this->pictureBox1->TabIndex = 3;
			this->pictureBox1->TabStop = false;
			// 
			// PoliStart
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(1421, 766);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->btn_auto);
			this->Controls->Add(this->btn_player);
			this->ForeColor = System::Drawing::SystemColors::ControlText;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"PoliStart";
			this->Text = L"Polidash";
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
};
}
