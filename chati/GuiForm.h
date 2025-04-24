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
#include "AddContact.cpp"
#include "ChatRoom.h"
#include "Contact.h"
#include "Story.h"


using namespace std;
using namespace System::IO;
//? Global maps for save and load from the files
map<string, User> users;
unordered_map<int, ChatRoom> chatRooms;
unordered_map<int, chati::Message> messages;
unordered_map<int, Contact> contacts;
unordered_map<int, Story> stories;
User *currentUser;
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
		private: System::Windows::Forms::Panel^ mainPanel;













		private: System::Windows::Forms::Panel^ navPanel;
		private: System::Windows::Forms::Button^ profileButton;
		private: System::Windows::Forms::Button^ statusButton;
		private: System::Windows::Forms::Button^ chatButton;
		private: System::Windows::Forms::Panel^ storyPanel;
		private: System::Windows::Forms::Panel^ profilePanel;
		private: System::Windows::Forms::Panel^ chatPnl;
		private: System::Windows::Forms::Panel^ currentCahtPanel;
		private: System::Windows::Forms::Panel^ panel2;
		private: System::Windows::Forms::FlowLayoutPanel^ messagesContainer;
		private: System::Windows::Forms::PictureBox^ pictureBox1;
		private: System::Windows::Forms::Panel^ panel1;
		private: System::Windows::Forms::Button^ sendButton;



		private: System::Windows::Forms::Label^ label1;
		private: System::Windows::Forms::FlowLayoutPanel^ chatRoomsPanel;
		private: System::Windows::Forms::FlowLayoutPanel^ allStoriesPanel;
		private: System::Windows::Forms::Panel^ stotyHeaderPanel;
		private: System::Windows::Forms::Button^ button2;




		private: System::Windows::Forms::Panel^ addStoryPanel;
		private: System::Windows::Forms::TextBox^ textStory;
		private: System::Windows::Forms::Button^ button3;



		private: System::Windows::Forms::ColorDialog^ colorDialog1;

		private: System::Windows::Forms::Button^ button4;

		private: System::Windows::Forms::Button^ button5;

		private: System::Windows::Forms::Button^ button6;




		private: System::Windows::Forms::RichTextBox^ textBox1;


		private: System::Windows::Forms::Button^ goToAddContact_btn;
		private: System::Windows::Forms::Panel^ addContactPanel;

		private: System::Windows::Forms::Button^ addContact_btn;
		private: System::Windows::Forms::Button^ checkContNum_btn;
		private: System::Windows::Forms::TextBox^ addContName_field;
		private: System::Windows::Forms::TextBox^ addContNum_field;
		private: System::Windows::Forms::Label^ label5;
		private: System::Windows::Forms::Label^ label4;
		private: System::Windows::Forms::Label^ label3;
		private: System::Windows::Forms::Label^ label2;






















	//private: System::Windows::Forms::Button^ button2;
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
			this->mainPanel = (gcnew System::Windows::Forms::Panel());
			this->chatPnl = (gcnew System::Windows::Forms::Panel());
			this->currentCahtPanel = (gcnew System::Windows::Forms::Panel());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->messagesContainer = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->textBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->sendButton = (gcnew System::Windows::Forms::Button());
			this->chatRoomsPanel = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->addContactPanel = (gcnew System::Windows::Forms::Panel());
			this->addContact_btn = (gcnew System::Windows::Forms::Button());
			this->checkContNum_btn = (gcnew System::Windows::Forms::Button());
			this->addContName_field = (gcnew System::Windows::Forms::TextBox());
			this->addContNum_field = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->storyPanel = (gcnew System::Windows::Forms::Panel());
			this->allStoriesPanel = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->stotyHeaderPanel = (gcnew System::Windows::Forms::Panel());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->navPanel = (gcnew System::Windows::Forms::Panel());
			this->goToAddContact_btn = (gcnew System::Windows::Forms::Button());
			this->statusButton = (gcnew System::Windows::Forms::Button());
			this->profileButton = (gcnew System::Windows::Forms::Button());
			this->chatButton = (gcnew System::Windows::Forms::Button());
			this->profilePanel = (gcnew System::Windows::Forms::Panel());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->addStoryPanel = (gcnew System::Windows::Forms::Panel());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->textStory = (gcnew System::Windows::Forms::TextBox());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->colorDialog1 = (gcnew System::Windows::Forms::ColorDialog());
			this->signUp_pnl->SuspendLayout();
			this->First_pnl->SuspendLayout();
			this->signIn_pnl->SuspendLayout();
			this->mainPanel->SuspendLayout();
			this->chatPnl->SuspendLayout();
			this->currentCahtPanel->SuspendLayout();
			this->panel2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->panel1->SuspendLayout();
			this->addContactPanel->SuspendLayout();
			this->storyPanel->SuspendLayout();
			this->stotyHeaderPanel->SuspendLayout();
			this->navPanel->SuspendLayout();
			this->profilePanel->SuspendLayout();
			this->addStoryPanel->SuspendLayout();
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
			this->signUp_pnl->Size = System::Drawing::Size(1904, 1041);
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
			this->First_pnl->Size = System::Drawing::Size(1904, 1041);
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
			this->signIn_pnl->Size = System::Drawing::Size(1904, 1041);
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
			// mainPanel
			// 
			this->mainPanel->BackColor = System::Drawing::Color::White;
			this->mainPanel->Controls->Add(this->addContactPanel);
			this->mainPanel->Controls->Add(this->chatPnl);
			this->mainPanel->Controls->Add(this->storyPanel);
			this->mainPanel->Controls->Add(this->navPanel);
			this->mainPanel->Controls->Add(this->profilePanel);
			this->mainPanel->Dock = System::Windows::Forms::DockStyle::Fill;
			this->mainPanel->Location = System::Drawing::Point(0, 0);
			this->mainPanel->Name = L"mainPanel";
			this->mainPanel->Size = System::Drawing::Size(1904, 1041);
			this->mainPanel->TabIndex = 3;
			// 
			// chatPnl
			// 
			this->chatPnl->Controls->Add(this->currentCahtPanel);
			this->chatPnl->Controls->Add(this->chatRoomsPanel);
			this->chatPnl->Dock = System::Windows::Forms::DockStyle::Fill;
			this->chatPnl->Location = System::Drawing::Point(87, 0);
			this->chatPnl->Name = L"chatPnl";
			this->chatPnl->Size = System::Drawing::Size(1817, 1041);
			this->chatPnl->TabIndex = 8;
			// 
			// currentCahtPanel
			// 
			this->currentCahtPanel->BackColor = System::Drawing::Color::RosyBrown;
			this->currentCahtPanel->Controls->Add(this->panel2);
			this->currentCahtPanel->Controls->Add(this->panel1);
			this->currentCahtPanel->Dock = System::Windows::Forms::DockStyle::Fill;
			this->currentCahtPanel->Location = System::Drawing::Point(338, 0);
			this->currentCahtPanel->Name = L"currentCahtPanel";
			this->currentCahtPanel->Size = System::Drawing::Size(1479, 1041);
			this->currentCahtPanel->TabIndex = 7;
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(45)), static_cast<System::Int32>(static_cast<System::Byte>(45)),
				static_cast<System::Int32>(static_cast<System::Byte>(45)));
			this->panel2->Controls->Add(this->messagesContainer);
			this->panel2->Controls->Add(this->pictureBox1);
			this->panel2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel2->Location = System::Drawing::Point(0, 0);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(1479, 995);
			this->panel2->TabIndex = 14;
			// 
			// messagesContainer
			// 
			this->messagesContainer->AutoScroll = true;
			this->messagesContainer->AutoSize = true;
			this->messagesContainer->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(60)),
				static_cast<System::Int32>(static_cast<System::Byte>(60)), static_cast<System::Int32>(static_cast<System::Byte>(60)));
			this->messagesContainer->Dock = System::Windows::Forms::DockStyle::Fill;
			this->messagesContainer->FlowDirection = System::Windows::Forms::FlowDirection::BottomUp;
			this->messagesContainer->Location = System::Drawing::Point(0, 0);
			this->messagesContainer->Name = L"messagesContainer";
			this->messagesContainer->Padding = System::Windows::Forms::Padding(2);
			this->messagesContainer->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->messagesContainer->Size = System::Drawing::Size(1479, 995);
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
			this->pictureBox1->Size = System::Drawing::Size(1479, 995);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 12;
			this->pictureBox1->TabStop = false;
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(50)), static_cast<System::Int32>(static_cast<System::Byte>(50)),
				static_cast<System::Int32>(static_cast<System::Byte>(50)));
			this->panel1->Controls->Add(this->textBox1);
			this->panel1->Controls->Add(this->sendButton);
			this->panel1->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->panel1->Location = System::Drawing::Point(0, 995);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(1479, 46);
			this->panel1->TabIndex = 13;
			// 
			// textBox1
			// 
			this->textBox1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox1->Location = System::Drawing::Point(0, 0);
			this->textBox1->MaxLength = 70;
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(1397, 46);
			this->textBox1->TabIndex = 0;
			this->textBox1->Text = L"";
			// 
			// sendButton
			// 
			this->sendButton->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"sendButton.BackgroundImage")));
			this->sendButton->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->sendButton->Cursor = System::Windows::Forms::Cursors::Hand;
			this->sendButton->Dock = System::Windows::Forms::DockStyle::Right;
			this->sendButton->FlatAppearance->BorderSize = 0;
			this->sendButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->sendButton->Location = System::Drawing::Point(1397, 0);
			this->sendButton->Name = L"sendButton";
			this->sendButton->Size = System::Drawing::Size(82, 46);
			this->sendButton->TabIndex = 3;
			this->sendButton->UseVisualStyleBackColor = true;
			this->sendButton->Click += gcnew System::EventHandler(this, &GuiForm::sendButton_Click);
			// 
			// chatRoomsPanel
			// 
			this->chatRoomsPanel->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(45)), static_cast<System::Int32>(static_cast<System::Byte>(45)),
				static_cast<System::Int32>(static_cast<System::Byte>(45)));
			this->chatRoomsPanel->Dock = System::Windows::Forms::DockStyle::Left;
			this->chatRoomsPanel->Location = System::Drawing::Point(0, 0);
			this->chatRoomsPanel->Name = L"chatRoomsPanel";
			this->chatRoomsPanel->Size = System::Drawing::Size(338, 1041);
			this->chatRoomsPanel->TabIndex = 2;
			// 
			// addContactPanel
			// 
			this->addContactPanel->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(45)), static_cast<System::Int32>(static_cast<System::Byte>(45)),
				static_cast<System::Int32>(static_cast<System::Byte>(45)));
			this->addContactPanel->Controls->Add(this->addContact_btn);
			this->addContactPanel->Controls->Add(this->checkContNum_btn);
			this->addContactPanel->Controls->Add(this->addContName_field);
			this->addContactPanel->Controls->Add(this->addContNum_field);
			this->addContactPanel->Controls->Add(this->label5);
			this->addContactPanel->Controls->Add(this->label4);
			this->addContactPanel->Controls->Add(this->label3);
			this->addContactPanel->Dock = System::Windows::Forms::DockStyle::Fill;
			this->addContactPanel->Location = System::Drawing::Point(87, 0);
			this->addContactPanel->Name = L"addContactPanel";
			this->addContactPanel->Size = System::Drawing::Size(1817, 1041);
			this->addContactPanel->TabIndex = 14;
			// 
			// addContact_btn
			// 
			this->addContact_btn->Location = System::Drawing::Point(840, 581);
			this->addContact_btn->Name = L"addContact_btn";
			this->addContact_btn->Size = System::Drawing::Size(75, 23);
			this->addContact_btn->TabIndex = 20;
			this->addContact_btn->Text = L"Add";
			this->addContact_btn->UseVisualStyleBackColor = true;
			// 
			// checkContNum_btn
			// 
			this->checkContNum_btn->Location = System::Drawing::Point(1029, 485);
			this->checkContNum_btn->Name = L"checkContNum_btn";
			this->checkContNum_btn->Size = System::Drawing::Size(75, 23);
			this->checkContNum_btn->TabIndex = 19;
			this->checkContNum_btn->Text = L"Check";
			this->checkContNum_btn->UseVisualStyleBackColor = true;
			// 
			// addContName_field
			// 
			this->addContName_field->Location = System::Drawing::Point(791, 516);
			this->addContName_field->Name = L"addContName_field";
			this->addContName_field->Size = System::Drawing::Size(215, 20);
			this->addContName_field->TabIndex = 18;
			// 
			// addContNum_field
			// 
			this->addContNum_field->Location = System::Drawing::Point(791, 485);
			this->addContNum_field->Name = L"addContNum_field";
			this->addContNum_field->Size = System::Drawing::Size(215, 20);
			this->addContNum_field->TabIndex = 17;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->Location = System::Drawing::Point(713, 485);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(59, 17);
			this->label5->TabIndex = 16;
			this->label5->Text = L"Phone:";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(713, 516);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(54, 17);
			this->label4->TabIndex = 15;
			this->label4->Text = L"Name:";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(836, 437);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(121, 24);
			this->label3->TabIndex = 14;
			this->label3->Text = L"Add contact";
			// 
			// storyPanel
			// 
			this->storyPanel->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(45)), static_cast<System::Int32>(static_cast<System::Byte>(45)),
				static_cast<System::Int32>(static_cast<System::Byte>(45)));
			this->storyPanel->Controls->Add(this->allStoriesPanel);
			this->storyPanel->Controls->Add(this->stotyHeaderPanel);
			this->storyPanel->Dock = System::Windows::Forms::DockStyle::Fill;
			this->storyPanel->Location = System::Drawing::Point(87, 0);
			this->storyPanel->Name = L"storyPanel";
			this->storyPanel->Size = System::Drawing::Size(1817, 1041);
			this->storyPanel->TabIndex = 11;
			// 
			// allStoriesPanel
			// 
			this->allStoriesPanel->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(45)), static_cast<System::Int32>(static_cast<System::Byte>(45)),
				static_cast<System::Int32>(static_cast<System::Byte>(45)));
			this->allStoriesPanel->Dock = System::Windows::Forms::DockStyle::Fill;
			this->allStoriesPanel->FlowDirection = System::Windows::Forms::FlowDirection::TopDown;
			this->allStoriesPanel->Location = System::Drawing::Point(0, 100);
			this->allStoriesPanel->Name = L"allStoriesPanel";
			this->allStoriesPanel->Size = System::Drawing::Size(1817, 941);
			this->allStoriesPanel->TabIndex = 1;
			// 
			// stotyHeaderPanel
			// 
			this->stotyHeaderPanel->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(60)), static_cast<System::Int32>(static_cast<System::Byte>(60)),
				static_cast<System::Int32>(static_cast<System::Byte>(60)));
			this->stotyHeaderPanel->Controls->Add(this->label2);
			this->stotyHeaderPanel->Controls->Add(this->button2);
			this->stotyHeaderPanel->Dock = System::Windows::Forms::DockStyle::Top;
			this->stotyHeaderPanel->Location = System::Drawing::Point(0, 0);
			this->stotyHeaderPanel->Name = L"stotyHeaderPanel";
			this->stotyHeaderPanel->Size = System::Drawing::Size(1817, 100);
			this->stotyHeaderPanel->TabIndex = 0;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 19.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->label2->Location = System::Drawing::Point(33, 34);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(98, 31);
			this->label2->TabIndex = 14;
			this->label2->Text = L"Status";
			// 
			// button2
			// 
			this->button2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->button2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button2.BackgroundImage")));
			this->button2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->button2->FlatAppearance->BorderSize = 0;
			this->button2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button2->Location = System::Drawing::Point(1683, 12);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 53);
			this->button2->TabIndex = 12;
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &GuiForm::button2_Click);
			// 
			// navPanel
			// 
			this->navPanel->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(65)), static_cast<System::Int32>(static_cast<System::Byte>(65)),
				static_cast<System::Int32>(static_cast<System::Byte>(65)));
			this->navPanel->Controls->Add(this->goToAddContact_btn);
			this->navPanel->Controls->Add(this->statusButton);
			this->navPanel->Controls->Add(this->profileButton);
			this->navPanel->Controls->Add(this->chatButton);
			this->navPanel->Dock = System::Windows::Forms::DockStyle::Left;
			this->navPanel->Location = System::Drawing::Point(0, 0);
			this->navPanel->Name = L"navPanel";
			this->navPanel->Size = System::Drawing::Size(87, 1041);
			this->navPanel->TabIndex = 5;
			// 
			// goToAddContact_btn
			// 
			this->goToAddContact_btn->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->goToAddContact_btn->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"goToAddContact_btn.BackgroundImage")));
			this->goToAddContact_btn->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->goToAddContact_btn->Cursor = System::Windows::Forms::Cursors::Hand;
			this->goToAddContact_btn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->goToAddContact_btn->Location = System::Drawing::Point(12, 830);
			this->goToAddContact_btn->Name = L"goToAddContact_btn";
			this->goToAddContact_btn->Size = System::Drawing::Size(63, 60);
			this->goToAddContact_btn->TabIndex = 3;
			this->goToAddContact_btn->UseVisualStyleBackColor = true;
			this->goToAddContact_btn->Click += gcnew System::EventHandler(this, &GuiForm::goToAddContact_btn_Click);
			// 
			// statusButton
			// 
			this->statusButton->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"statusButton.BackgroundImage")));
			this->statusButton->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->statusButton->Cursor = System::Windows::Forms::Cursors::Hand;
			this->statusButton->FlatAppearance->BorderSize = 0;
			this->statusButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->statusButton->Location = System::Drawing::Point(11, 150);
			this->statusButton->Name = L"statusButton";
			this->statusButton->Size = System::Drawing::Size(62, 63);
			this->statusButton->TabIndex = 1;
			this->statusButton->UseVisualStyleBackColor = true;
			this->statusButton->Click += gcnew System::EventHandler(this, &GuiForm::statusButton_Click);
			// 
			// profileButton
			// 
			this->profileButton->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->profileButton->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"profileButton.BackgroundImage")));
			this->profileButton->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->profileButton->Cursor = System::Windows::Forms::Cursors::Hand;
			this->profileButton->FlatAppearance->BorderSize = 0;
			this->profileButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->profileButton->Location = System::Drawing::Point(5, 951);
			this->profileButton->Name = L"profileButton";
			this->profileButton->Size = System::Drawing::Size(75, 63);
			this->profileButton->TabIndex = 2;
			this->profileButton->UseVisualStyleBackColor = true;
			this->profileButton->Click += gcnew System::EventHandler(this, &GuiForm::profileButton_Click);
			// 
			// chatButton
			// 
			this->chatButton->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"chatButton.BackgroundImage")));
			this->chatButton->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->chatButton->Cursor = System::Windows::Forms::Cursors::Hand;
			this->chatButton->FlatAppearance->BorderSize = 0;
			this->chatButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->chatButton->Location = System::Drawing::Point(12, 38);
			this->chatButton->Name = L"chatButton";
			this->chatButton->Size = System::Drawing::Size(61, 62);
			this->chatButton->TabIndex = 0;
			this->chatButton->UseVisualStyleBackColor = true;
			this->chatButton->Click += gcnew System::EventHandler(this, &GuiForm::chatButton_Click_1);
			// 
			// profilePanel
			// 
			this->profilePanel->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(45)), static_cast<System::Int32>(static_cast<System::Byte>(45)),
				static_cast<System::Int32>(static_cast<System::Byte>(45)));
			this->profilePanel->Controls->Add(this->label1);
			this->profilePanel->Dock = System::Windows::Forms::DockStyle::Fill;
			this->profilePanel->Location = System::Drawing::Point(0, 0);
			this->profilePanel->Name = L"profilePanel";
			this->profilePanel->Size = System::Drawing::Size(1904, 1041);
			this->profilePanel->TabIndex = 10;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(503, 316);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(167, 31);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Profile Panel";
			// 
			// addStoryPanel
			// 
			this->addStoryPanel->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(45)), static_cast<System::Int32>(static_cast<System::Byte>(45)),
				static_cast<System::Int32>(static_cast<System::Byte>(45)));
			this->addStoryPanel->Controls->Add(this->button6);
			this->addStoryPanel->Controls->Add(this->button5);
			this->addStoryPanel->Controls->Add(this->button4);
			this->addStoryPanel->Controls->Add(this->textStory);
			this->addStoryPanel->Controls->Add(this->button3);
			this->addStoryPanel->Dock = System::Windows::Forms::DockStyle::Fill;
			this->addStoryPanel->Location = System::Drawing::Point(0, 0);
			this->addStoryPanel->Name = L"addStoryPanel";
			this->addStoryPanel->Size = System::Drawing::Size(1904, 1041);
			this->addStoryPanel->TabIndex = 13;
			// 
			// button6
			// 
			this->button6->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->button6->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button6.BackgroundImage")));
			this->button6->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->button6->FlatAppearance->BorderSize = 0;
			this->button6->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button6->Location = System::Drawing::Point(1747, 12);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(56, 50);
			this->button6->TabIndex = 4;
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &GuiForm::button6_Click);
			// 
			// button5
			// 
			this->button5->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->button5->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button5.BackgroundImage")));
			this->button5->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->button5->FlatAppearance->BorderSize = 0;
			this->button5->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button5->Location = System::Drawing::Point(1836, 12);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(56, 50);
			this->button5->TabIndex = 3;
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &GuiForm::button5_Click);
			// 
			// button4
			// 
			this->button4->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->button4->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button4.BackgroundImage")));
			this->button4->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->button4->FlatAppearance->BorderSize = 0;
			this->button4->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button4->Location = System::Drawing::Point(1809, 979);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(49, 50);
			this->button4->TabIndex = 2;
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &GuiForm::button4_Click);
			// 
			// textStory
			// 
			this->textStory->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(45)), static_cast<System::Int32>(static_cast<System::Byte>(45)),
				static_cast<System::Int32>(static_cast<System::Byte>(45)));
			this->textStory->Font = (gcnew System::Drawing::Font(L"Sans Serif Collection", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textStory->Location = System::Drawing::Point(3, 81);
			this->textStory->Multiline = true;
			this->textStory->Name = L"textStory";
			this->textStory->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->textStory->Size = System::Drawing::Size(1321, 574);
			this->textStory->TabIndex = 1;
			// 
			// button3
			// 
			this->button3->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button3.BackgroundImage")));
			this->button3->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->button3->FlatAppearance->BorderSize = 0;
			this->button3->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button3->Location = System::Drawing::Point(25, 13);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(49, 50);
			this->button3->TabIndex = 0;
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &GuiForm::button3_Click);
			// 
			// colorDialog1
			// 
			this->colorDialog1->FullOpen = true;
			// 
			// GuiForm
			// 
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
			this->ClientSize = System::Drawing::Size(1904, 1041);
			this->Controls->Add(this->mainPanel);
			this->Controls->Add(this->signUp_pnl);
			this->Controls->Add(this->addStoryPanel);
			this->Controls->Add(this->signIn_pnl);
			this->Controls->Add(this->First_pnl);
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"GuiForm";
			this->Text = L"chatApp";
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &GuiForm::GuiForm_FormClosed);
			this->Load += gcnew System::EventHandler(this, &GuiForm::GuiForm_Load);
			this->signUp_pnl->ResumeLayout(false);
			this->signUp_pnl->PerformLayout();
			this->First_pnl->ResumeLayout(false);
			this->First_pnl->PerformLayout();
			this->signIn_pnl->ResumeLayout(false);
			this->signIn_pnl->PerformLayout();
			this->mainPanel->ResumeLayout(false);
			this->chatPnl->ResumeLayout(false);
			this->currentCahtPanel->ResumeLayout(false);
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->panel1->ResumeLayout(false);
			this->addContactPanel->ResumeLayout(false);
			this->addContactPanel->PerformLayout();
			this->storyPanel->ResumeLayout(false);
			this->stotyHeaderPanel->ResumeLayout(false);
			this->stotyHeaderPanel->PerformLayout();
			this->navPanel->ResumeLayout(false);
			this->profilePanel->ResumeLayout(false);
			this->profilePanel->PerformLayout();
			this->addStoryPanel->ResumeLayout(false);
			this->addStoryPanel->PerformLayout();
			this->ResumeLayout(false);

		}
		#pragma endregion


		private: System::Void GuiForm_Load(System::Object^ sender, System::EventArgs^ e) {
			loadFromFile(users, chatRooms, messages);
			cout << '1' << endl;

			//cout << "messages size: " << chatRooms[1].messagesID.size() << endl;
			//for (int i : chatRooms[1].messagesID) {
			//	cout << "messageID: " << i << endl;
			//}

			// will remove this later
			currentUser = &users["01067700658"];


			//currentChatRoom = new ChatRoom(1, true);
			//currentChatRoom->addUserID(currentUser->getUserID());
			//chatRooms[1] = *currentChatRoom;


			currentChatRoom = &chatRooms[1];



			//for(auto m: currentChatRoom->getMessagesID()){
			//	cout << "messageID from current chat: " << m << endl;
			//	cout << "text: " << messages[m].getText() << endl;
			//}
			//cout << endl;
			
			//for (auto m : messages) {

			//	cout << "messageID: " << m.first << " : " << m.second.getIsRead() << endl;
			//	cout << "Text : " << m.second.getText() << endl;
			//	//cout << "Sender ID: " << m.second.getSenderID() << endl;
			//	//cout << "date Sent: " << m.second.getDateSent() << endl;
			//	//cout << "Time Sent: " << m.second.getTimeSent() << endl << endl;
			//}


			handler.initializeChat(currentChatRoom, messagesContainer, messages, currentUser);


			//for (auto u : users) {
			//	cout << u.second.getUserID() << endl;
			//	cout << u.second.getFirstName() << endl;
			//	cout << u.second.getLastName() << endl;
			//	cout << u.second.getPassword() << endl;
			//	cout << u.second.getMobileNumber() << endl;
			//	for(auto &c: u.second.getContactsID()){
   //                 cout << "contact ID: " << c.first << endl;
			//	}
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
				currentUser = &users[mobileNumber];
				mainPanel->BringToFront();
			}
	
		}


		private: System::Void sendButton_Click(System::Object^ sender, System::EventArgs^ e) {
				handler.createMessageEvent(textBox1, messagesContainer, *currentUser);
		}
		private: System::Void textBox1_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
			if (e->KeyCode == Keys::Enter) 
				handler.createMessageEvent(textBox1, messagesContainer, *currentUser);
		}
			   
		private: System::Void GuiForm_FormClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e) {
			saveToFile(users, chatRooms, messages);
		}
		private: System::Void chatButton_Click(System::Object^ sender, System::EventArgs^ e) {

		}
		private: System::Void chatButton_Click_1(System::Object^ sender, System::EventArgs^ e) {
			chatPnl->BringToFront();
		}
		private: System::Void statusButton_Click(System::Object^ sender, System::EventArgs^ e) {
			storyPanel->BringToFront();
		}
		private: System::Void profileButton_Click(System::Object^ sender, System::EventArgs^ e) {
			profilePanel->BringToFront();
		}
		private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
			addStoryPanel->BringToFront();
		}
		private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
			addStoryPanel->BringToFront();
			mainPanel->BringToFront();
		}
		private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) {
			ColorDialog^ colorDialog = gcnew ColorDialog();
			colorDialog->AllowFullOpen = true;
			colorDialog->ShowHelp = true;
			colorDialog->Color = System::Drawing::Color::Black; //to initialze it with black
			if (colorDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK)
			{
				// Set the background color of the form to the selected color
				this->addStoryPanel->BackColor = colorDialog->Color;
				this->textStory->BackColor = colorDialog->Color;
			}
		}
		private: System::Void button6_Click(System::Object^ sender, System::EventArgs^ e) {
			FontDialog^ fontDialog = gcnew FontDialog();
			fontDialog->ShowColor = true;
			fontDialog->ShowEffects = true;
			fontDialog->Font = textStory->Font; // to initilze it with the current color
			if (fontDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK)
			{
				textStory->Font = fontDialog->Font;
				textStory->ForeColor = fontDialog->Color;
			}

		}
		private: System::Void createUserStoryPanel() {
			// Define the PictureBox for the user story image
			PictureBox^ pictureUserStoryPic = gcnew PictureBox();

			// Load the resources
			System::ComponentModel::ComponentResourceManager^ resources = gcnew System::ComponentModel::ComponentResourceManager(GuiForm::typeid);
			cli::array<System::Byte>^ imageBytes = (cli::safe_cast<cli::array<System::Byte>^>(resources->GetObject(L"profile-user")));

			// Convert byte array to Image using MemoryStream
			MemoryStream^ ms = gcnew MemoryStream(imageBytes);
			pictureUserStoryPic->Image = System::Drawing::Image::FromStream(ms);

			// Set the SizeMode to Zoom for the image to be zoomed correctly and fit within the PictureBox
			pictureUserStoryPic->SizeMode = PictureBoxSizeMode::Zoom;
			pictureUserStoryPic->Dock = System::Windows::Forms::DockStyle::Left;
			pictureUserStoryPic->InitialImage = nullptr;
			pictureUserStoryPic->Location = System::Drawing::Point(0, 0);
			pictureUserStoryPic->Name = L"pictureUserStoryPic";
			pictureUserStoryPic->Size = System::Drawing::Size(99, 97); // Adjust size as needed
			pictureUserStoryPic->TabIndex = 0;
			pictureUserStoryPic->TabStop = false;

			// Create other labels for name and date
			Label^ nameUserStoryLabel = gcnew Label();
			nameUserStoryLabel->AutoSize = true;
			nameUserStoryLabel->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(45)),
				static_cast<System::Int32>(static_cast<System::Byte>(45)), static_cast<System::Int32>(static_cast<System::Byte>(45)));
			nameUserStoryLabel->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			nameUserStoryLabel->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			nameUserStoryLabel->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			nameUserStoryLabel->Location = System::Drawing::Point(116, 9);
			nameUserStoryLabel->Name = L"nameUserStoryLabel";
			nameUserStoryLabel->Size = System::Drawing::Size(101, 37);
			nameUserStoryLabel->TabIndex = 1;
			std::string fullName = currentUser->getFirstName() + " " + currentUser->getLastName();
			nameUserStoryLabel->Text = gcnew System::String(fullName.c_str());



			Label^ DateUserStoryLabel = gcnew Label();
			DateUserStoryLabel->AutoSize = true;
			DateUserStoryLabel->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(45)),
				static_cast<System::Int32>(static_cast<System::Byte>(45)), static_cast<System::Int32>(static_cast<System::Byte>(45)));
			DateUserStoryLabel->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			DateUserStoryLabel->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			DateUserStoryLabel->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			DateUserStoryLabel->Location = System::Drawing::Point(135, 64);
			DateUserStoryLabel->Name = L"DateUserStoryLabel";
			DateUserStoryLabel->Size = System::Drawing::Size(50, 24);
			DateUserStoryLabel->TabIndex = 2;
			DateUserStoryLabel->Text = DateTime::Now.ToString("hh-mm tt"); // Set the date format as needed

			// Set up the user story panel
			Panel^ userStoryPanel = gcnew Panel();
			userStoryPanel->Controls->Add(DateUserStoryLabel);
			userStoryPanel->Controls->Add(nameUserStoryLabel);
			userStoryPanel->Controls->Add(pictureUserStoryPic);
			userStoryPanel->Location = System::Drawing::Point(3, 3);
			userStoryPanel->Name = L"userStoryPanel";
			userStoryPanel->Size = System::Drawing::Size(1249, 97);
			userStoryPanel->TabIndex = 0;

			// Add click event handler to the user story panel
			userStoryPanel->Click += gcnew System::EventHandler(this, &GuiForm::userStoryPanel_Click);

			// Add the user story panel to the main panel
			this->allStoriesPanel->Controls->Add(userStoryPanel);
		}



		private: System::Void userStoryPanel_Click(System::Object^ sender, System::EventArgs^ e) {
			// Handle the logic of the click event here
			MessageBox::Show("User Story Panel Clicked!");
			//? show the panel of the user story
		}
		private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
			createUserStoryPanel();
			addStoryPanel->BringToFront();
			mainPanel->BringToFront();
		}
			  

		private: System::Void checkContNum_btn_Click(System::Object^ sender, System::EventArgs^ e) {
			string contNum = msclr::interop::marshal_as<std::string>(addContNum_field->Text);
			if (checkContactExist(contNum, users)) {
				MessageBox::Show("This mobile number is already registered", "Sign up error");
			}
			else {
				addContName_field->Text = gcnew System::String(showCurrentName().c_str());
			}
		}

		private: System::Void addContact_btn_Click(System::Object^ sender, System::EventArgs^ e) {
			string contName = msclr::interop::marshal_as<std::string>(addContName_field->Text);
			addContact(*currentUser, contName);
		}
		private: System::Void goToAddContact_btn_Click(System::Object^ sender, System::EventArgs^ e) {
			addContactPanel->BringToFront();
		}
	};
}
