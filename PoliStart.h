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
			this->SuspendLayout();
			// 
			// btn_player
			// 
			this->btn_player->Location = System::Drawing::Point(454, 241);
			this->btn_player->Name = L"btn_player";
			this->btn_player->Size = System::Drawing::Size(240, 88);
			this->btn_player->TabIndex = 0;
			this->btn_player->Text = L"JUGADOR";
			this->btn_player->UseVisualStyleBackColor = true;
			this->btn_player->Click += gcnew System::EventHandler(this, &PoliStart::btn_player_Click);
			// 
			// btn_auto
			// 
			this->btn_auto->Location = System::Drawing::Point(113, 241);
			this->btn_auto->Name = L"btn_auto";
			this->btn_auto->Size = System::Drawing::Size(240, 88);
			this->btn_auto->TabIndex = 1;
			this->btn_auto->Text = L"AUTOMATICO";
			this->btn_auto->UseVisualStyleBackColor = true;
			// 
			// PoliStart
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(807, 438);
			this->Controls->Add(this->btn_auto);
			this->Controls->Add(this->btn_player);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"PoliStart";
			this->Text = L"Polidash";
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void btn_player_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Hide();
		PoliGame^ game = gcnew PoliGame();
		game->ShowDialog();
		this->Close();
	}
	};
}
