#pragma once
#include "User.h"
#include <msclr/marshal_cppstd.h>
#include <stack>
#include<queue>
#include<deque>
#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include "Signing.cpp"
#include <map>
#include "SaveLoadFiles.cpp"
#include "MessageHandler.h"
#include <unordered_map>
#include "Message.h"


using namespace std;


map<string, User> users;
unordered_map<int, ChatRoom> chatRooms;
// Use the namespace explicitly to resolve ambiguity
unordered_map<int, chati::Message> messages;
User currentUser;
ChatRoom *currentChatRoom;


namespace chati {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std;



	/// <summary>
	/// Summary for GuiForm
	/// </summary>
	public ref class GuiForm : public System::Windows::Forms::Form
	{
		private: System::Windows::Forms::FlowLayoutPanel^ messagesContainer;
	    MessageHandler handler;


		public:
		GuiForm(void)
		{
			InitializeComponent();
		}

		protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~GuiForm()
		{
			if (components)
			{
				delete components;
			}
		}
		private: System::Windows::Forms::Panel^ signUp_pnl;
		protected:

		protected:
		private: System::Windows::Forms::Label^ FN_lbl;
		private: System::Windows::Forms::TextBox^ FN_textbox;
		private: System::Windows::Forms::Label^ LN_lbl;
		private: System::Windows::Forms::Label^ Pass_lbl;
		private: System::Windows::Forms::TextBox^ LN_textbox;
		private: System::Windows::Forms::TextBox^ Pass_textbox;
		private: System::Windows::Forms::Button^ submit_but;
		private: System::Windows::Forms::Label^ MN_lbl;
		private: System::Windows::Forms::TextBox^ MN_textbox;
		private: System::Windows::Forms::Panel^ First_pnl;
		private: System::Windows::Forms::Button^ signin_btn;
		private: System::Windows::Forms::Button^ signUp_btn;
		private: System::Windows::Forms::Label^ letsChat;
		private: System::Windows::Forms::Button^ button1;
		private: System::Windows::Forms::Label^ signUp_done;
		private: System::Windows::Forms::Panel^ signIn_pnl;
		private: System::Windows::Forms::TextBox^ Pass_txt;
		private: System::Windows::Forms::TextBox^ MN_txt;
		private: System::Windows::Forms::Label^ Pass_lbl2;
		private: System::Windows::Forms::Label^ MN_lbl2;
		private: System::Windows::Forms::Button^ back;
		private: System::Windows::Forms::Button^ sign;
		private: System::Windows::Forms::Panel^ chatPanel;
		private: System::Windows::Forms::Panel^ panel1;
		private: System::Windows::Forms::Button^ sendButton;
		private: System::Windows::Forms::TextBox^ textBox1;
		private: System::Windows::Forms::FlowLayoutPanel^ contactsPanel;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::Panel^ panel2;



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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(GuiForm::typeid));
			this->signUp_pnl = (gcnew System::Windows::Forms::Panel());
			this->signUp_done = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->FN_lbl = (gcnew System::Windows::Forms::Label());
			this->FN_textbox = (gcnew System::Windows::Forms::TextBox());
			this->LN_lbl = (gcnew System::Windows::Forms::Label());
			this->Pass_lbl = (gcnew System::Windows::Forms::Label());
			this->LN_textbox = (gcnew System::Windows::Forms::TextBox());
			this->Pass_textbox = (gcnew System::Windows::Forms::TextBox());
			this->submit_but = (gcnew System::Windows::Forms::Button());
			this->MN_lbl = (gcnew System::Windows::Forms::Label());
			this->MN_textbox = (gcnew System::Windows::Forms::TextBox());
			this->First_pnl = (gcnew System::Windows::Forms::Panel());
			this->signin_btn = (gcnew System::Windows::Forms::Button());
			this->signUp_btn = (gcnew System::Windows::Forms::Button());
			this->letsChat = (gcnew System::Windows::Forms::Label());
			this->signIn_pnl = (gcnew System::Windows::Forms::Panel());
			this->back = (gcnew System::Windows::Forms::Button());
			this->sign = (gcnew System::Windows::Forms::Button());
			this->Pass_txt = (gcnew System::Windows::Forms::TextBox());
			this->MN_txt = (gcnew System::Windows::Forms::TextBox());
			this->Pass_lbl2 = (gcnew System::Windows::Forms::Label());
			this->MN_lbl2 = (gcnew System::Windows::Forms::Label());
			this->chatPanel = (gcnew System::Windows::Forms::Panel());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->messagesContainer = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->sendButton = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->contactsPanel = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->signUp_pnl->SuspendLayout();
			this->First_pnl->SuspendLayout();
			this->signIn_pnl->SuspendLayout();
			this->chatPanel->SuspendLayout();
			this->panel2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// signUp_pnl
			// 
			this->signUp_pnl->Controls->Add(this->signUp_done);
			this->signUp_pnl->Controls->Add(this->button1);
			this->signUp_pnl->Controls->Add(this->FN_lbl);
			this->signUp_pnl->Controls->Add(this->FN_textbox);
			this->signUp_pnl->Controls->Add(this->LN_lbl);
			this->signUp_pnl->Controls->Add(this->Pass_lbl);
			this->signUp_pnl->Controls->Add(this->LN_textbox);
			this->signUp_pnl->Controls->Add(this->Pass_textbox);
			this->signUp_pnl->Controls->Add(this->submit_but);
			this->signUp_pnl->Controls->Add(this->MN_lbl);
			this->signUp_pnl->Controls->Add(this->MN_textbox);
			this->signUp_pnl->Dock = System::Windows::Forms::DockStyle::Fill;
			this->signUp_pnl->Location = System::Drawing::Point(0, 0);
			this->signUp_pnl->Margin = System::Windows::Forms::Padding(4);
			this->signUp_pnl->Name = L"signUp_pnl";
			this->signUp_pnl->Size = System::Drawing::Size(1280, 720);
			this->signUp_pnl->TabIndex = 9;
			// 
			// signUp_done
			// 
			this->signUp_done->AutoSize = true;
			this->signUp_done->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 26.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->signUp_done->ForeColor = System::Drawing::Color::Lime;
			this->signUp_done->Location = System::Drawing::Point(633, 76);
			this->signUp_done->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->signUp_done->Name = L"signUp_done";
			this->signUp_done->Size = System::Drawing::Size(331, 39);
			this->signUp_done->TabIndex = 19;
			this->signUp_done->Text = L"Signed up Correctly!";
			this->signUp_done->Visible = false;
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(401, 587);
			this->button1->Margin = System::Windows::Forms::Padding(4);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(200, 68);
			this->button1->TabIndex = 18;
			this->button1->Text = L"Back";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &GuiForm::button1_Click);
			// 
			// FN_lbl
			// 
			this->FN_lbl->AutoSize = true;
			this->FN_lbl->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->FN_lbl->Location = System::Drawing::Point(335, 219);
			this->FN_lbl->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->FN_lbl->Name = L"FN_lbl";
			this->FN_lbl->Size = System::Drawing::Size(104, 24);
			this->FN_lbl->TabIndex = 17;
			this->FN_lbl->Text = L"Fitst Name:";
			// 
			// FN_textbox
			// 
			this->FN_textbox->Location = System::Drawing::Point(559, 225);
			this->FN_textbox->Margin = System::Windows::Forms::Padding(4);
			this->FN_textbox->Name = L"FN_textbox";
			this->FN_textbox->Size = System::Drawing::Size(184, 20);
			this->FN_textbox->TabIndex = 16;
			// 
			// LN_lbl
			// 
			this->LN_lbl->AutoSize = true;
			this->LN_lbl->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->LN_lbl->Location = System::Drawing::Point(335, 284);
			this->LN_lbl->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->LN_lbl->Name = L"LN_lbl";
			this->LN_lbl->Size = System::Drawing::Size(104, 24);
			this->LN_lbl->TabIndex = 15;
			this->LN_lbl->Text = L"Last Name:";
			// 
			// Pass_lbl
			// 
			this->Pass_lbl->AutoSize = true;
			this->Pass_lbl->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Pass_lbl->Location = System::Drawing::Point(335, 364);
			this->Pass_lbl->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->Pass_lbl->Name = L"Pass_lbl";
			this->Pass_lbl->Size = System::Drawing::Size(97, 24);
			this->Pass_lbl->TabIndex = 14;
			this->Pass_lbl->Text = L"Password:";
			// 
			// LN_textbox
			// 
			this->LN_textbox->Location = System::Drawing::Point(559, 290);
			this->LN_textbox->Margin = System::Windows::Forms::Padding(4);
			this->LN_textbox->Name = L"LN_textbox";
			this->LN_textbox->Size = System::Drawing::Size(184, 20);
			this->LN_textbox->TabIndex = 13;
			// 
			// Pass_textbox
			// 
			this->Pass_textbox->Location = System::Drawing::Point(559, 369);
			this->Pass_textbox->Margin = System::Windows::Forms::Padding(4);
			this->Pass_textbox->Name = L"Pass_textbox";
			this->Pass_textbox->Size = System::Drawing::Size(184, 20);
			this->Pass_textbox->TabIndex = 12;
			// 
			// submit_but
			// 
			this->submit_but->BackColor = System::Drawing::Color::Lime;
			this->submit_but->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->submit_but->Location = System::Drawing::Point(1124, 587);
			this->submit_but->Margin = System::Windows::Forms::Padding(4);
			this->submit_but->Name = L"submit_but";
			this->submit_but->Size = System::Drawing::Size(200, 68);
			this->submit_but->TabIndex = 11;
			this->submit_but->Text = L"Submit";
			this->submit_but->UseVisualStyleBackColor = false;
			this->submit_but->Click += gcnew System::EventHandler(this, &GuiForm::submit_but_Click);
			// 
			// MN_lbl
			// 
			this->MN_lbl->AutoSize = true;
			this->MN_lbl->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->MN_lbl->Location = System::Drawing::Point(335, 447);
			this->MN_lbl->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->MN_lbl->Name = L"MN_lbl";
			this->MN_lbl->Size = System::Drawing::Size(148, 24);
			this->MN_lbl->TabIndex = 10;
			this->MN_lbl->Text = L"Mobile number: ";
			// 
			// MN_textbox
			// 
			this->MN_textbox->Location = System::Drawing::Point(559, 453);
			this->MN_textbox->Margin = System::Windows::Forms::Padding(4);
			this->MN_textbox->Name = L"MN_textbox";
			this->MN_textbox->Size = System::Drawing::Size(184, 20);
			this->MN_textbox->TabIndex = 9;
			// 
			// First_pnl
			// 
			this->First_pnl->Controls->Add(this->signin_btn);
			this->First_pnl->Controls->Add(this->signUp_btn);
			this->First_pnl->Controls->Add(this->letsChat);
			this->First_pnl->Dock = System::Windows::Forms::DockStyle::Fill;
			this->First_pnl->Location = System::Drawing::Point(0, 0);
			this->First_pnl->Margin = System::Windows::Forms::Padding(4);
			this->First_pnl->Name = L"First_pnl";
			this->First_pnl->Size = System::Drawing::Size(1280, 720);
			this->First_pnl->TabIndex = 10;
			// 
			// signin_btn
			// 
			this->signin_btn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->signin_btn->Location = System::Drawing::Point(782, 301);
			this->signin_btn->Margin = System::Windows::Forms::Padding(4);
			this->signin_btn->Name = L"signin_btn";
			this->signin_btn->Size = System::Drawing::Size(263, 117);
			this->signin_btn->TabIndex = 2;
			this->signin_btn->Text = L"Sign In";
			this->signin_btn->UseVisualStyleBackColor = true;
			this->signin_btn->Click += gcnew System::EventHandler(this, &GuiForm::signin_btn_Click);
			// 
			// signUp_btn
			// 
			this->signUp_btn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->signUp_btn->Location = System::Drawing::Point(298, 301);
			this->signUp_btn->Margin = System::Windows::Forms::Padding(4);
			this->signUp_btn->Name = L"signUp_btn";
			this->signUp_btn->Size = System::Drawing::Size(263, 117);
			this->signUp_btn->TabIndex = 1;
			this->signUp_btn->Text = L"Sign Up";
			this->signUp_btn->UseVisualStyleBackColor = true;
			this->signUp_btn->Click += gcnew System::EventHandler(this, &GuiForm::signUp_btn_Click);
			// 
			// letsChat
			// 
			this->letsChat->AutoSize = true;
			this->letsChat->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 36, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->letsChat->Location = System::Drawing::Point(514, 129);
			this->letsChat->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->letsChat->Name = L"letsChat";
			this->letsChat->Size = System::Drawing::Size(283, 55);
			this->letsChat->TabIndex = 0;
			this->letsChat->Text = L"Let\'s chat : )";
			// 
			// signIn_pnl
			// 
			this->signIn_pnl->Controls->Add(this->back);
			this->signIn_pnl->Controls->Add(this->sign);
			this->signIn_pnl->Controls->Add(this->Pass_txt);
			this->signIn_pnl->Controls->Add(this->MN_txt);
			this->signIn_pnl->Controls->Add(this->Pass_lbl2);
			this->signIn_pnl->Controls->Add(this->MN_lbl2);
			this->signIn_pnl->Dock = System::Windows::Forms::DockStyle::Fill;
			this->signIn_pnl->Location = System::Drawing::Point(0, 0);
			this->signIn_pnl->Margin = System::Windows::Forms::Padding(4);
			this->signIn_pnl->Name = L"signIn_pnl";
			this->signIn_pnl->Size = System::Drawing::Size(1280, 720);
			this->signIn_pnl->TabIndex = 11;
			// 
			// back
			// 
			this->back->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->back->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 21.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->back->Location = System::Drawing::Point(241, 521);
			this->back->Margin = System::Windows::Forms::Padding(4);
			this->back->Name = L"back";
			this->back->Size = System::Drawing::Size(285, 110);
			this->back->TabIndex = 5;
			this->back->Text = L"Back";
			this->back->UseVisualStyleBackColor = false;
			this->back->Click += gcnew System::EventHandler(this, &GuiForm::back_Click);
			// 
			// sign
			// 
			this->sign->BackColor = System::Drawing::Color::Lime;
			this->sign->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 21.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->sign->Location = System::Drawing::Point(886, 521);
			this->sign->Margin = System::Windows::Forms::Padding(4);
			this->sign->Name = L"sign";
			this->sign->Size = System::Drawing::Size(285, 110);
			this->sign->TabIndex = 4;
			this->sign->Text = L"Submit";
			this->sign->UseVisualStyleBackColor = false;
			this->sign->Click += gcnew System::EventHandler(this, &GuiForm::sign_Click);
			// 
			// Pass_txt
			// 
			this->Pass_txt->Location = System::Drawing::Point(650, 282);
			this->Pass_txt->Margin = System::Windows::Forms::Padding(4);
			this->Pass_txt->Name = L"Pass_txt";
			this->Pass_txt->Size = System::Drawing::Size(347, 20);
			this->Pass_txt->TabIndex = 3;
			// 
			// MN_txt
			// 
			this->MN_txt->Location = System::Drawing::Point(650, 191);
			this->MN_txt->Margin = System::Windows::Forms::Padding(4);
			this->MN_txt->Name = L"MN_txt";
			this->MN_txt->Size = System::Drawing::Size(347, 20);
			this->MN_txt->TabIndex = 2;
			// 
			// Pass_lbl2
			// 
			this->Pass_lbl2->AutoSize = true;
			this->Pass_lbl2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Pass_lbl2->Location = System::Drawing::Point(313, 271);
			this->Pass_lbl2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->Pass_lbl2->Name = L"Pass_lbl2";
			this->Pass_lbl2->Size = System::Drawing::Size(126, 29);
			this->Pass_lbl2->TabIndex = 1;
			this->Pass_lbl2->Text = L"Password:";
			// 
			// MN_lbl2
			// 
			this->MN_lbl2->AutoSize = true;
			this->MN_lbl2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->MN_lbl2->Location = System::Drawing::Point(313, 190);
			this->MN_lbl2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->MN_lbl2->Name = L"MN_lbl2";
			this->MN_lbl2->Size = System::Drawing::Size(186, 29);
			this->MN_lbl2->TabIndex = 0;
			this->MN_lbl2->Text = L"Mobile Number:";
			// 
			// chatPanel
			// 
			this->chatPanel->BackColor = System::Drawing::Color::White;
			this->chatPanel->Controls->Add(this->panel2);
			this->chatPanel->Controls->Add(this->panel1);
			this->chatPanel->Controls->Add(this->contactsPanel);
			this->chatPanel->Dock = System::Windows::Forms::DockStyle::Fill;
			this->chatPanel->Location = System::Drawing::Point(0, 0);
			this->chatPanel->Name = L"chatPanel";
			this->chatPanel->Size = System::Drawing::Size(1280, 720);
			this->chatPanel->TabIndex = 3;
			// 
			// panel2
			// 
			this->panel2->Controls->Add(this->messagesContainer);
			this->panel2->Controls->Add(this->pictureBox1);
			this->panel2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel2->Location = System::Drawing::Point(318, 0);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(962, 661);
			this->panel2->TabIndex = 0;
			// 
			// messagesContainer
			// 
			this->messagesContainer->AutoScroll = true;
			this->messagesContainer->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->messagesContainer->Dock = System::Windows::Forms::DockStyle::Fill;
			this->messagesContainer->FlowDirection = System::Windows::Forms::FlowDirection::BottomUp;
			this->messagesContainer->Location = System::Drawing::Point(0, 0);
			this->messagesContainer->Name = L"messagesContainer";
			this->messagesContainer->Padding = System::Windows::Forms::Padding(2);
			this->messagesContainer->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->messagesContainer->Size = System::Drawing::Size(962, 661);
			this->messagesContainer->TabIndex = 2;
			this->messagesContainer->WrapContents = false;
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->pictureBox1->ErrorImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.ErrorImage")));
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->InitialImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.InitialImage")));
			this->pictureBox1->Location = System::Drawing::Point(0, 0);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(962, 661);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 12;
			this->pictureBox1->TabStop = false;
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(60)), static_cast<System::Int32>(static_cast<System::Byte>(60)),
				static_cast<System::Int32>(static_cast<System::Byte>(60)));
			this->panel1->Controls->Add(this->sendButton);
			this->panel1->Controls->Add(this->textBox1);
			this->panel1->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->panel1->Location = System::Drawing::Point(318, 661);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(962, 59);
			this->panel1->TabIndex = 1;
			// 
			// sendButton
			// 
			this->sendButton->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Right));
			this->sendButton->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->sendButton->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"sendButton.BackgroundImage")));
			this->sendButton->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->sendButton->Cursor = System::Windows::Forms::Cursors::Hand;
			this->sendButton->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->sendButton->FlatAppearance->BorderSize = 0;
			this->sendButton->FlatAppearance->MouseDownBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(50)),
				static_cast<System::Int32>(static_cast<System::Byte>(50)), static_cast<System::Int32>(static_cast<System::Byte>(50)));
			this->sendButton->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->sendButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->sendButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->sendButton->Location = System::Drawing::Point(879, 3);
			this->sendButton->Margin = System::Windows::Forms::Padding(0);
			this->sendButton->Name = L"sendButton";
			this->sendButton->Size = System::Drawing::Size(51, 47);
			this->sendButton->TabIndex = 3;
			this->sendButton->UseVisualStyleBackColor = false;
			this->sendButton->Click += gcnew System::EventHandler(this, &GuiForm::sendButton_Click);
			// 
			// textBox1
			// 
			this->textBox1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left));
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox1->Location = System::Drawing::Point(6, 12);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(848, 35);
			this->textBox1->TabIndex = 2;
			this->textBox1->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &GuiForm::textBox1_KeyDown);
			// 
			// contactsPanel
			// 
			this->contactsPanel->BackColor = System::Drawing::Color::DimGray;
			this->contactsPanel->Dock = System::Windows::Forms::DockStyle::Left;
			this->contactsPanel->Location = System::Drawing::Point(0, 0);
			this->contactsPanel->Name = L"contactsPanel";
			this->contactsPanel->Size = System::Drawing::Size(318, 720);
			this->contactsPanel->TabIndex = 0;
			// 
			// GuiForm
			// 
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
			this->ClientSize = System::Drawing::Size(1280, 720);
			this->Controls->Add(this->chatPanel);
			this->Controls->Add(this->signUp_pnl);
			this->Controls->Add(this->signIn_pnl);
			this->Controls->Add(this->First_pnl);
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"GuiForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"GuiForm";
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &GuiForm::GuiForm_FormClosed);
			this->Load += gcnew System::EventHandler(this, &GuiForm::GuiForm_Load);
			this->signUp_pnl->ResumeLayout(false);
			this->signUp_pnl->PerformLayout();
			this->First_pnl->ResumeLayout(false);
			this->First_pnl->PerformLayout();
			this->signIn_pnl->ResumeLayout(false);
			this->signIn_pnl->PerformLayout();
			this->chatPanel->ResumeLayout(false);
			this->panel2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->ResumeLayout(false);

		}
		#pragma endregion


		private: System::Void GuiForm_Load(System::Object^ sender, System::EventArgs^ e) {
			loadFromFile(users, chatRooms, messages);
			cout << '1' << endl;
			//for(auto u : users) {
			//	cout << u.first << " : " << u.second.userID << endl;
			//	cout << u.second.firstName << endl;
			//	cout << u.second.lastName << endl;
			//	cout << u.second.password << endl;
			//	cout << u.second.mobileNumber << endl;
			//}

			//cout << "messages size: " << chatRooms[1].messagesID.size() << endl;
			//for (int i : chatRooms[1].messagesID) {
			//	cout << "messageID: " << i << endl;
			//}

			// will remove this later
			currentUser = users["01067700658"];


			//currentChatRoom = new ChatRoom(2, true);

			//currentChatRoom->usersID.push_back(currentUser.userID);

			//chatRooms[2] = *currentChatRoom;

			//cout << '3' << endl;

			currentChatRoom = &chatRooms[2];

			//for(auto c: chatRooms){
			//	cout << c.second.messagesID.size() << endl;
			//}



			handler.initializeChat(currentChatRoom, messagesContainer, messages, currentUser);
			//cout << '4' << endl;


			//for (auto m : messages) {
			//	cout << "messageID: " << m.first << " : " << m.second.isRead << endl;
			//	cout << "Text : " << m.second.text << endl;
			//	cout << "Sender ID: " << m.second.senderID << endl;
			//	cout << "date Sent: " << m.second.dateSent << endl;
			//	cout << "Time Sent: " << m.second.timeSent << endl << endl;
			//}

			//for (auto u : users) {
			//	cout << u.first << " : " << u.second.userID << endl;
			//	cout << u.second.firstName << endl;
			//	cout << u.second.lastName << endl;
			//	cout << u.second.password << endl;
			//	cout << u.second.mobileNumber << endl;
			//}
		}

		private: System::Void submit_but_Click(System::Object^ sender, System::EventArgs^ e) {
		
			signUp_done->Visible = false;

			if (MN_textbox->Text == "" || Pass_textbox->Text == "" || FN_textbox->Text == "" || LN_textbox->Text == "")
			{
				MessageBox::Show("Please fill all the fields","Infromation incompleted");
				return;
			}
			if (MN_textbox->Text->Length < 11 || MN_textbox->Text->Length > 11)
			{
				MessageBox::Show("Mobile number must be 11 digits","Invalid Mobile Number");
				return;
			}
			if (Pass_textbox->Text->Length < 6)
			{
				MessageBox::Show("Password must be at least 6 characters","Invalid Password");
				return;
			}
		
			string mobileNumber = msclr::interop::marshal_as<std::string>(MN_textbox->Text);
			string password = msclr::interop::marshal_as<std::string>(Pass_textbox->Text);
			string firstName = msclr::interop::marshal_as<std::string>(FN_textbox->Text);
			string lastName = msclr::interop::marshal_as<std::string>(LN_textbox->Text);

			if (checkUser(mobileNumber, users)) {
				MessageBox::Show("This mobile number is already registered", "Sign up error");
				return;
			}

			signUp(mobileNumber, password, firstName, lastName, users);
			signUp_done->Visible = true;
		}
		private: System::Void signUp_btn_Click(System::Object^ sender, System::EventArgs^ e) {
			signUp_pnl->BringToFront();
		}
		private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
			First_pnl->BringToFront();
		}
		private: System::Void signin_btn_Click(System::Object^ sender, System::EventArgs^ e) {
			signIn_pnl->BringToFront();
		}
		private: System::Void back_Click(System::Object^ sender, System::EventArgs^ e) {
			First_pnl->BringToFront();
		}
		private: System::Void sign_Click(System::Object^ sender, System::EventArgs^ e) {
			if (Pass_txt->Text->Length < 6)
			{
				MessageBox::Show("Password must be at least 6 characters", "Invalid Password");
				return;
			}
			if (MN_txt->Text == "")
			{
				MessageBox::Show("Please fill all the fields", "Infromation incompleted");
				return;
			}
			string mobileNumber = msclr::interop::marshal_as<std::string>(MN_txt->Text);
			string password = msclr::interop::marshal_as<std::string>(Pass_txt->Text);


			if (!checkSignIn(mobileNumber, password, users))
			{
				MessageBox::Show("Invalid mobile number or password", "Sign in error");
				return;
			}
			else {
				currentUser = users[mobileNumber];
				chatPanel->BringToFront();
			}
	
		}


		private: System::Void sendButton_Click(System::Object^ sender, System::EventArgs^ e) {
				handler.createMessageEvent(textBox1, messagesContainer, currentUser);
		}
		private: System::Void textBox1_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
			if (e->KeyCode == Keys::Enter) 
				handler.createMessageEvent(textBox1, messagesContainer, currentUser);
		}
			   
		private: System::Void GuiForm_FormClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e) {
			saveToFile(users, chatRooms, messages);
		}

	};
}
