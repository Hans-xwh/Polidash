#pragma once

#include "Figura.hpp"
#include "figuritasnpc.hpp"
#include "FiguraJugador.hpp"
#include "Controladora.hpp"

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

		PoliGame(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			//jugador = new Jugador(100, 100, t1);
			//testFig = new Figura(10, 10, 200, Shapes::HEXAGONO);
			//pruebita = new FiguritasNPC(10, 10, 100, true, 1);
			juego = new Juego();
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
		Juego* juego;
	private: System::Windows::Forms::ProgressBar^ progressBar1;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;









		   Dir teclapulsada;


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
			this->progressBar1 = (gcnew System::Windows::Forms::ProgressBar());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Interval = 33;
			this->timer1->Tick += gcnew System::EventHandler(this, &PoliGame::timer1_Tick);
			// 
			// progressBar1
			// 
			this->progressBar1->Location = System::Drawing::Point(1319, 687);
			this->progressBar1->Margin = System::Windows::Forms::Padding(4);
			this->progressBar1->Name = L"progressBar1";
			this->progressBar1->Size = System::Drawing::Size(355, 28);
			this->progressBar1->TabIndex = 0;
			this->progressBar1->Click += gcnew System::EventHandler(this, &PoliGame::progressBar1_Click);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(22, 692);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(112, 23);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Play Music";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &PoliGame::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(160, 692);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(112, 23);
			this->button2->TabIndex = 2;
			this->button2->Text = L"Stop Music";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &PoliGame::button2_Click);
			// 
			// PoliGame
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1703, 730);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->progressBar1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->KeyPreview = true;
			this->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->MaximizeBox = false;
			this->Name = L"PoliGame";
			this->Text = L"PoliDash: Game";
			this->Load += gcnew System::EventHandler(this, &PoliGame::PoliGame_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &PoliGame::PoliGame_KeyDown);
			this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &PoliGame::PoliGame_KeyUp);
			this->ResumeLayout(false);

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

		this->progressBar1->Value = juego->Update(bCanvas->Graphics);
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

		if (e->KeyCode == Keys::Up)		teclapulsada = Dir::ARRIBA;
		if (e->KeyCode == Keys::Down)	teclapulsada = Dir::ABAJO;
		if (e->KeyCode == Keys::Right)	teclapulsada = Dir::DERECHA;
		if (e->KeyCode == Keys::Left)	teclapulsada = Dir::IZQUIERDA;

		juego->KeyDown(teclapulsada);
	}

	private: System::Void PoliGame_KeyUp(System::Object^ sender, KeyEventArgs^ e) {
		if (e->KeyCode == Keys::Up || e->KeyCode == Keys::Down || e->KeyCode == Keys::Left || e->KeyCode == Keys::Right||
			e->KeyCode == Keys::W || e->KeyCode == Keys::S || e->KeyCode == Keys::A || e->KeyCode == Keys::D){
			juego->keyUp(NADA);
		}
	}
private: System::Void progressBar1_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	soniditoTime->PlayLooping();
}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	soniditoTime->Stop();
}
};
}


