#pragma once

#include "Figura.hpp"
#include "figuritasnpc.hpp"
#include "FiguraJugador.hpp"
#include "Controladora.hpp"

#include "Victoria.h"
#include "Derrota.h"

namespace Polidash {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Media;

	/// <summary>
	/// Summary for PoliGame
	/// </summary>
	public ref class PoliGame : public System::Windows::Forms::Form
	{
	public:
		SoundPlayer^ soniditoTime = gcnew SoundPlayer("Audio/TimeMachine.wav");

		PoliGame(bool autoM)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			//jugador = new Jugador(100, 100, t1);
			//testFig = new Figura(10, 10, 200, Shapes::HEXAGONO);
			//pruebita = new FiguritasNPC(10, 10, 100, true, 1);
			this->autoM = autoM;
			juego = new Juego();
			isMusicActiva = false;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~PoliGame()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Timer^ timer1;
	protected:
	private: System::ComponentModel::IContainer^ components;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		//Figura* testFig;
		//FiguritasNPC* pruebita;
		//Jugador* jugador;
		bool autoM;
		Juego* juego;


	private: System::Windows::Forms::Label^ label2;











		   Dir teclapulsada;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ lbl_lado;

	private: System::Windows::Forms::Label^ lbl_num;

	private: System::Windows::Forms::Label^ lbl_angulo;

	private: System::Windows::Forms::Label^ lbl_velocidad;
	private: System::Windows::Forms::Label^ label6;

		   static bool isMusicActiva;


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(PoliGame::typeid));
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->lbl_lado = (gcnew System::Windows::Forms::Label());
			this->lbl_num = (gcnew System::Windows::Forms::Label());
			this->lbl_angulo = (gcnew System::Windows::Forms::Label());
			this->lbl_velocidad = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Interval = 1;
			this->timer1->Tick += gcnew System::EventHandler(this, &PoliGame::timer1_Tick);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::SystemColors::Window;
			this->label2->Location = System::Drawing::Point(1005, 347);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(60, 13);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Velocidad: ";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::SystemColors::Window;
			this->label3->Location = System::Drawing::Point(1005, 194);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(39, 13);
			this->label3->TabIndex = 3;
			this->label3->Text = L"Lados:";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->BackColor = System::Drawing::SystemColors::Window;
			this->label4->Location = System::Drawing::Point(1005, 241);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(47, 13);
			this->label4->TabIndex = 4;
			this->label4->Text = L"Numero:";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->BackColor = System::Drawing::SystemColors::Window;
			this->label5->Location = System::Drawing::Point(1005, 289);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(75, 13);
			this->label5->TabIndex = 5;
			this->label5->Text = L"Sum. Angulos:";
			// 
			// lbl_lado
			// 
			this->lbl_lado->AutoSize = true;
			this->lbl_lado->BackColor = System::Drawing::SystemColors::Window;
			this->lbl_lado->Location = System::Drawing::Point(1112, 194);
			this->lbl_lado->Name = L"lbl_lado";
			this->lbl_lado->Size = System::Drawing::Size(21, 13);
			this->lbl_lado->TabIndex = 6;
			this->lbl_lado->Text = L"XX";
			// 
			// lbl_num
			// 
			this->lbl_num->AutoSize = true;
			this->lbl_num->BackColor = System::Drawing::SystemColors::Window;
			this->lbl_num->Location = System::Drawing::Point(1112, 241);
			this->lbl_num->Name = L"lbl_num";
			this->lbl_num->Size = System::Drawing::Size(21, 13);
			this->lbl_num->TabIndex = 7;
			this->lbl_num->Text = L"XX";
			// 
			// lbl_angulo
			// 
			this->lbl_angulo->AutoSize = true;
			this->lbl_angulo->BackColor = System::Drawing::SystemColors::Window;
			this->lbl_angulo->Location = System::Drawing::Point(1112, 289);
			this->lbl_angulo->Name = L"lbl_angulo";
			this->lbl_angulo->Size = System::Drawing::Size(21, 13);
			this->lbl_angulo->TabIndex = 8;
			this->lbl_angulo->Text = L"XX";
			// 
			// lbl_velocidad
			// 
			this->lbl_velocidad->AutoSize = true;
			this->lbl_velocidad->BackColor = System::Drawing::SystemColors::Window;
			this->lbl_velocidad->Location = System::Drawing::Point(1112, 347);
			this->lbl_velocidad->Name = L"lbl_velocidad";
			this->lbl_velocidad->Size = System::Drawing::Size(21, 13);
			this->lbl_velocidad->TabIndex = 9;
			this->lbl_velocidad->Text = L"XX";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->BackColor = System::Drawing::SystemColors::Window;
			this->label6->Location = System::Drawing::Point(998, 547);
			this->label6->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(246, 13);
			this->label6->TabIndex = 1;
			this->label6->Text = L"Pulsa Z para activar y C para desactivar la música.";
			this->label6->Click += gcnew System::EventHandler(this, &PoliGame::label1_Click);
			// 
			// PoliGame
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1277, 593);
			this->Controls->Add(this->lbl_velocidad);
			this->Controls->Add(this->lbl_angulo);
			this->Controls->Add(this->lbl_num);
			this->Controls->Add(this->lbl_lado);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label6);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->KeyPreview = true;
			this->Margin = System::Windows::Forms::Padding(2);
			this->MaximizeBox = false;
			this->Name = L"PoliGame";
			this->Text = L"PoliDash: Game";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &PoliGame::PoliGame_FormClosing);
			this->Load += gcnew System::EventHandler(this, &PoliGame::PoliGame_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &PoliGame::PoliGame_KeyDown);
			this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &PoliGame::PoliGame_KeyUp);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		//Crear graficos
		Graphics^ g = this->CreateGraphics();

		//Reservar memoria para el buffer}
		BufferedGraphicsContext^ myBuffer = BufferedGraphicsManager::Current;

		//Crear espacio canvas dentro del buffer
		BufferedGraphics^ bCanvas = myBuffer->Allocate(g, this->ClientRectangle);	//bCanvas = Buffered Canvas

		//Operaciones de dibujado aqui
		//bCanvas->Graphics->Clear(Color::White);	//El fondo se dibuja en DrawAll()

		//Comprobacion de victoria
		int result = juego->Update(bCanvas->Graphics);
		if (result == 1) {
			Victoria^ v = gcnew Victoria();
			this->timer1->Enabled = false;
			this->Hide();
			soniditoTime->Stop();
			v->ShowDialog();
			this->Close();
		}else if (result == 2) {
			Derrota^ d = gcnew Derrota();
			this->timer1->Enabled = false;
			this->Hide();
			soniditoTime->Stop();
			d->ShowDialog();
			this->Close();
		}


		juego->DrawAll(bCanvas->Graphics);

		//mover y dibujar
		/*
		pruebita->autoMove();
		pruebita->draw(bCanvas->Graphics);

		//jugador
		jugador->autoMove();
		jugador->draw(bCanvas->Graphics);

		testFig->draw(bCanvas->Graphics);
		*/

		//Render
		bCanvas->Render(g);

		delete bCanvas;
		delete myBuffer;
		delete g;
	}
	private: System::Void PoliGame_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void PoliGame_KeyDown(System::Object^ sender, KeyEventArgs^ e) {
		teclapulsada = Dir::NADA;

		if (!autoM && (e->KeyCode == Keys::Up || e->KeyCode == Keys::W))		teclapulsada = Dir::ARRIBA;
		if (!autoM && (e->KeyCode == Keys::Down || e->KeyCode == Keys::S))	teclapulsada = Dir::ABAJO;
		if (!autoM && (e->KeyCode == Keys::Right || e->KeyCode == Keys::D))	teclapulsada = Dir::DERECHA;
		if (!autoM && (e->KeyCode == Keys::Left || e->KeyCode == Keys::A))	teclapulsada = Dir::IZQUIERDA;

		juego->KeyDown(teclapulsada);


		if (e->KeyCode == Keys::Z) {
			if (!isMusicActiva) {
				soniditoTime->PlayLooping();
				isMusicActiva = true;
			}
		}
		if (e->KeyCode == Keys::C) {
			if (isMusicActiva) {
				soniditoTime->Stop();
				isMusicActiva = false;
			}
		}
	}

	private: System::Void PoliGame_KeyUp(System::Object^ sender, KeyEventArgs^ e) {
		if (e->KeyCode == Keys::Up || e->KeyCode == Keys::Down || e->KeyCode == Keys::Left || e->KeyCode == Keys::Right||
			e->KeyCode == Keys::W || e->KeyCode == Keys::S || e->KeyCode == Keys::A || e->KeyCode == Keys::D){
			juego->keyUp(NADA);
		}
	}
private: System::Void progressBar1_Click(System::Object^ sender, System::EventArgs^ e) {
}

private: System::Void PoliGame_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) {
	//Esto se llama cuando el form se cierra
	soniditoTime->Stop();
}
private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
}
};
}


