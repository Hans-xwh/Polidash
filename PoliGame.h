#pragma once

#include "Figura.hpp"
#include "figuritasnpc.hpp"

namespace Polidash {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for PoliGame
	/// </summary>
	public ref class PoliGame : public System::Windows::Forms::Form
	{
	public:
		PoliGame(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//

			testFig = new Figura(10, 10, 100, Shapes::HEXAGONO);
			pruebita = new FiguritasNPC(10, 10, 100, true, 1);
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
		Figura* testFig;
		FiguritasNPC* pruebita;


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
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &PoliGame::timer1_Tick);
			// 
			// PoliGame
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(801, 453);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->Name = L"PoliGame";
			this->Text = L"PoliDash: Game";
			this->Load += gcnew System::EventHandler(this, &PoliGame::PoliGame_Load);
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
		bCanvas->Graphics->Clear(Color::White);	//Despues cambiar el fondo?

		//mover y dibujar
		pruebita->autoMove();
		pruebita->draw(bCanvas->Graphics);

		testFig->draw(bCanvas->Graphics);

		//Render
		bCanvas->Render(g);

		delete bCanvas;
		delete myBuffer;
		delete g;
	}
	private: System::Void PoliGame_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	};
}
