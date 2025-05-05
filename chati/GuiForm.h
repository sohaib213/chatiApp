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
#include "ChatRoom.h"
#include "Contact.h"
#include "Story.h"
#include "AddContact.h"
#include "createChatRoomHandler.h"
#include "StoryStyleHelper.cpp"




using namespace std;
using namespace System::IO;
using namespace System::Drawing;
using namespace System;
using namespace System::Globalization;
//? Global maps for save and load from the files
unordered_map<string, User> users;
unordered_map<int, ChatRoom> chatRooms;
unordered_map<int, chati::Message> messages;
unordered_map<int, Contact> contacts;
unordered_map<int, Story> stories;
unordered_map<int, long long> Activity;
User *currentUser;
set<int> storiesIDTemp;
ChatRoom *currentChatRoom;
string currentContNum,currentContName;




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
		System::Collections::Generic::Dictionary<int, FlowLayoutPanel^>^ chatRoomsPanels = gcnew System::Collections::Generic::Dictionary<int, FlowLayoutPanel^>();
	    MessageHandler handler;
		private: System::Windows::Forms::Button^ singOutButton;


		createChatRoomHandler chatRoomHandler;
		String^ destinationPath;
		String^ selectedImagePath;
		String^ fileName = "User.png";

		String^ groupImageDestinationPath;
		String^ selectedGroupImagePath;
		String^ groupFileName = "default-group.png";	
	

		private: System::Windows::Forms::Panel^ addGroup;
		private: System::Windows::Forms::Label^ label6;
		private: System::Windows::Forms::CheckedListBox^ usersListBox;
		private: System::Windows::Forms::Label^ label8;
		private: System::Windows::Forms::TextBox^ groupNameTxt;
		private: System::Windows::Forms::Label^ label7;
		private: System::Windows::Forms::Button^ addBtn;
		private: System::Windows::Forms::Panel^ headerContainer;
		private: System::Windows::Forms::PictureBox^ chatPicture;
		private: System::Windows::Forms::Label^ chatName;
		private: System::Windows::Forms::Panel^ messagesFlowPanelsContainer;
	private: System::Windows::Forms::Panel^ SignINPnl;
	private: System::Windows::Forms::Panel^ panel1;


	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ passLbl;
	private: System::Windows::Forms::Label^ numLbl;
	private: System::Windows::Forms::TextBox^ passTxt;
	private: System::Windows::Forms::TextBox^ phoneTxt;
	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::Button^ button8;
	private: System::Windows::Forms::TextBox^ pasTxt;

	private: System::Windows::Forms::TextBox^ numTxt;

	private: System::Windows::Forms::TextBox^ lnTxt;

	private: System::Windows::Forms::TextBox^ fnTxt;

	private: System::Windows::Forms::Label^ label14;
	private: System::Windows::Forms::Label^ label13;
	private: System::Windows::Forms::Label^ label12;
	private: System::Windows::Forms::Label^ label11;
	private: System::Windows::Forms::Label^ label15;
	private: System::Windows::Forms::Button^ button10;
	private: System::Windows::Forms::Button^ button9;
	private: System::Windows::Forms::PictureBox^ pictureBox2;
	private: System::Windows::Forms::Button^ button12;

	private: System::Windows::Forms::Timer^ storyTimerTemp;
	private:System::Windows::Forms::ColorDialog^ colorDialog;
	private:System::Windows::Forms::FontDialog^ fontDialog;

	private: System::Windows::Forms::PictureBox^ signUpBackGround;
	private: System::Windows::Forms::PictureBox^ signinBackGround;
	private: System::Windows::Forms::Button^ groupImgBut;
	private: System::Windows::Forms::PictureBox^ groupImgPicBox;










		private: System::Windows::Forms::Button^ button7;

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

		protected:

		protected:









	private: System::Windows::Forms::Panel^ signUpPnl;







		



		//private: System::Windows::Forms::Label^ DateUserStoryLabel;
		//private: System::Windows::Forms::Label^ nameUserStoryLabel;


		private: System::Windows::Forms::Panel^ mainPanel;
		












		private: System::Windows::Forms::Panel^ navPanel;
		private: System::Windows::Forms::Button^ profileButton;
		private: System::Windows::Forms::Button^ statusButton;
		private: System::Windows::Forms::Button^ chatButton;
		private: System::Windows::Forms::Panel^ storyPanel;
		private: System::Windows::Forms::Panel^ profilePanel;
		private: System::Windows::Forms::Panel^ chatPnl;
		private: System::Windows::Forms::Panel^ currentCahtPanel;
		private: System::Windows::Forms::Panel^ chatsContainer;
		private: System::Windows::Forms::Panel^ footerContainer;







		private: System::Windows::Forms::Button^ sendButton;



		private: System::Windows::Forms::Label^ label1;
		private: System::Windows::Forms::FlowLayoutPanel^ contactsPanel;

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



		private: System::Windows::Forms::TextBox^ addContName_field;
		private: System::Windows::Forms::TextBox^ addContNum_field;
		private: System::Windows::Forms::Label^ label5;
		private: System::Windows::Forms::Label^ NameLabel;

		private: System::Windows::Forms::Label^ label3;
		private: System::Windows::Forms::Label^ label2;
		private: System::Windows::Forms::Button^ checkContact_btn;
		private: System::Windows::Forms::Button^ addContact_btn;
		private: System::Windows::Forms::Panel^ getStoryPanel;
		private: System::Windows::Forms::Panel^ profileUserInStoryPanel;
		private: System::Windows::Forms::PictureBox^ profileStoryPic;

		private: System::Windows::Forms::Label^ dateInStoryLabel;


		private: System::Windows::Forms::Label^ nameInStoryLabel;
		private: System::Windows::Forms::Panel^ bodyOfTheStoryPanel;
		private: System::Windows::Forms::Label^ bodyOfTheStoryLabel;
		private: System::Windows::Forms::Panel^ footerOfTheSroryPanel;
		private: System::Windows::Forms::Button^ viewerOfTheStoryBtn;
		private: System::Windows::Forms::Button^ cancelStoryBtn;
private: System::ComponentModel::IContainer^ components;



	//private: System::Windows::Forms::Button^ button2;
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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(GuiForm::typeid));
			this->signUpPnl = (gcnew System::Windows::Forms::Panel());
			this->button12 = (gcnew System::Windows::Forms::Button());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->button10 = (gcnew System::Windows::Forms::Button());
			this->button9 = (gcnew System::Windows::Forms::Button());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->pasTxt = (gcnew System::Windows::Forms::TextBox());
			this->numTxt = (gcnew System::Windows::Forms::TextBox());
			this->lnTxt = (gcnew System::Windows::Forms::TextBox());
			this->fnTxt = (gcnew System::Windows::Forms::TextBox());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->signUpBackGround = (gcnew System::Windows::Forms::PictureBox());
			this->passTxt = (gcnew System::Windows::Forms::TextBox());
			this->mainPanel = (gcnew System::Windows::Forms::Panel());
			this->storyPanel = (gcnew System::Windows::Forms::Panel());
			this->allStoriesPanel = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->stotyHeaderPanel = (gcnew System::Windows::Forms::Panel());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->chatPnl = (gcnew System::Windows::Forms::Panel());
			this->currentCahtPanel = (gcnew System::Windows::Forms::Panel());
			this->chatsContainer = (gcnew System::Windows::Forms::Panel());
			this->messagesFlowPanelsContainer = (gcnew System::Windows::Forms::Panel());
			this->headerContainer = (gcnew System::Windows::Forms::Panel());
			this->chatName = (gcnew System::Windows::Forms::Label());
			this->chatPicture = (gcnew System::Windows::Forms::PictureBox());
			this->footerContainer = (gcnew System::Windows::Forms::Panel());
			this->textBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->sendButton = (gcnew System::Windows::Forms::Button());
			this->contactsPanel = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->profilePanel = (gcnew System::Windows::Forms::Panel());
			this->singOutButton = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->addGroup = (gcnew System::Windows::Forms::Panel());
			this->groupImgBut = (gcnew System::Windows::Forms::Button());
			this->groupImgPicBox = (gcnew System::Windows::Forms::PictureBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->usersListBox = (gcnew System::Windows::Forms::CheckedListBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->groupNameTxt = (gcnew System::Windows::Forms::TextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->addBtn = (gcnew System::Windows::Forms::Button());
			this->addContactPanel = (gcnew System::Windows::Forms::Panel());
			this->addContact_btn = (gcnew System::Windows::Forms::Button());
			this->checkContact_btn = (gcnew System::Windows::Forms::Button());
			this->addContName_field = (gcnew System::Windows::Forms::TextBox());
			this->addContNum_field = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->NameLabel = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->navPanel = (gcnew System::Windows::Forms::Panel());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->chatButton = (gcnew System::Windows::Forms::Button());
			this->goToAddContact_btn = (gcnew System::Windows::Forms::Button());
			this->statusButton = (gcnew System::Windows::Forms::Button());
			this->profileButton = (gcnew System::Windows::Forms::Button());
			this->addStoryPanel = (gcnew System::Windows::Forms::Panel());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->textStory = (gcnew System::Windows::Forms::TextBox());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->colorDialog1 = (gcnew System::Windows::Forms::ColorDialog());
			this->getStoryPanel = (gcnew System::Windows::Forms::Panel());
			this->footerOfTheSroryPanel = (gcnew System::Windows::Forms::Panel());
			this->viewerOfTheStoryBtn = (gcnew System::Windows::Forms::Button());
			this->bodyOfTheStoryPanel = (gcnew System::Windows::Forms::Panel());
			this->bodyOfTheStoryLabel = (gcnew System::Windows::Forms::Label());
			this->profileUserInStoryPanel = (gcnew System::Windows::Forms::Panel());
			this->cancelStoryBtn = (gcnew System::Windows::Forms::Button());
			this->dateInStoryLabel = (gcnew System::Windows::Forms::Label());
			this->nameInStoryLabel = (gcnew System::Windows::Forms::Label());
			this->profileStoryPic = (gcnew System::Windows::Forms::PictureBox());
			this->SignINPnl = (gcnew System::Windows::Forms::Panel());
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->passLbl = (gcnew System::Windows::Forms::Label());
			this->numLbl = (gcnew System::Windows::Forms::Label());
			this->phoneTxt = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->storyTimerTemp = (gcnew System::Windows::Forms::Timer(this->components));
			this->signinBackGround = (gcnew System::Windows::Forms::PictureBox());
			this->signUpPnl->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->signUpBackGround))->BeginInit();
			this->mainPanel->SuspendLayout();
			this->storyPanel->SuspendLayout();
			this->stotyHeaderPanel->SuspendLayout();
			this->chatPnl->SuspendLayout();
			this->currentCahtPanel->SuspendLayout();
			this->chatsContainer->SuspendLayout();
			this->headerContainer->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chatPicture))->BeginInit();
			this->footerContainer->SuspendLayout();
			this->profilePanel->SuspendLayout();
			this->addGroup->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->groupImgPicBox))->BeginInit();
			this->addContactPanel->SuspendLayout();
			this->navPanel->SuspendLayout();
			this->addStoryPanel->SuspendLayout();
			this->getStoryPanel->SuspendLayout();
			this->footerOfTheSroryPanel->SuspendLayout();
			this->bodyOfTheStoryPanel->SuspendLayout();
			this->profileUserInStoryPanel->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->profileStoryPic))->BeginInit();
			this->SignINPnl->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->signinBackGround))->BeginInit();
			this->SuspendLayout();
			this->signUpPnl->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"signUpPnl.BackgroundImage")));
			this->signUpPnl->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->signUpPnl->Controls->Add(this->button12);
			this->signUpPnl->Controls->Add(this->pictureBox2);
			this->signUpPnl->Controls->Add(this->button10);
			this->signUpPnl->Controls->Add(this->button9);
			this->signUpPnl->Controls->Add(this->label15);
			this->signUpPnl->Controls->Add(this->pasTxt);
			this->signUpPnl->Controls->Add(this->numTxt);
			this->signUpPnl->Controls->Add(this->lnTxt);
			this->signUpPnl->Controls->Add(this->fnTxt);
			this->signUpPnl->Controls->Add(this->label14);
			this->signUpPnl->Controls->Add(this->label13);
			this->signUpPnl->Controls->Add(this->label12);
			this->signUpPnl->Controls->Add(this->label11);
			this->signUpPnl->Controls->Add(this->signUpBackGround);
			this->signUpPnl->Dock = System::Windows::Forms::DockStyle::Fill;
			this->signUpPnl->Location = System::Drawing::Point(0, 0);
			this->signUpPnl->Margin = System::Windows::Forms::Padding(4);
			this->signUpPnl->Name = L"signUpPnl";
			this->signUpPnl->Size = System::Drawing::Size(1904, 1041);
			this->signUpPnl->TabIndex = 10;
			this->button12->BackColor = System::Drawing::Color::Cyan;
			this->button12->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button12->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button12->Location = System::Drawing::Point(1396, 516);
			this->button12->Name = L"button12";
			this->button12->Size = System::Drawing::Size(100, 35);
			this->button12->TabIndex = 24;
			this->button12->Text = L"Select image";
			this->button12->UseVisualStyleBackColor = false;
			this->button12->Click += gcnew System::EventHandler(this, &GuiForm::button12_Click);
			this->pictureBox2->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.Image")));
			this->pictureBox2->Location = System::Drawing::Point(1375, 364);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(142, 133);
			this->pictureBox2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox2->TabIndex = 23;
			this->pictureBox2->TabStop = false;
			this->button10->BackColor = System::Drawing::Color::Cyan;
			this->button10->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button10->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button10->Location = System::Drawing::Point(425, 801);
			this->button10->Name = L"button10";
			this->button10->Size = System::Drawing::Size(206, 80);
			this->button10->TabIndex = 11;
			this->button10->Text = L"Sign In ";
			this->button10->UseVisualStyleBackColor = false;
			this->button10->Click += gcnew System::EventHandler(this, &GuiForm::button10_Click);
			this->button9->BackColor = System::Drawing::Color::Cyan;
			this->button9->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button9->Location = System::Drawing::Point(1375, 801);
			this->button9->Name = L"button9";
			this->button9->Size = System::Drawing::Size(206, 80);
			this->button9->TabIndex = 10;
			this->button9->Text = L"Sign Up →";
			this->button9->UseVisualStyleBackColor = false;
			this->button9->Click += gcnew System::EventHandler(this, &GuiForm::button9_Click);
			this->label15->AutoSize = true;
			this->label15->BackColor = System::Drawing::Color::Transparent;
			this->label15->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 36, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label15->Location = System::Drawing::Point(750, 199);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(521, 69);
			this->label15->TabIndex = 8;
			this->label15->Text = L"Sign Up with Chati";
			this->pasTxt->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->pasTxt->Location = System::Drawing::Point(951, 499);
			this->pasTxt->Name = L"pasTxt";
			this->pasTxt->PasswordChar = 42;
			this->pasTxt->Size = System::Drawing::Size(162, 37);
			this->pasTxt->TabIndex = 7;
			this->numTxt->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->numTxt->Location = System::Drawing::Point(951, 456);
			this->numTxt->Name = L"numTxt";
			this->numTxt->Size = System::Drawing::Size(162, 37);
			this->numTxt->TabIndex = 6;
			this->lnTxt->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lnTxt->Location = System::Drawing::Point(951, 414);
			this->lnTxt->Name = L"lnTxt";
			this->lnTxt->Size = System::Drawing::Size(162, 37);
			this->lnTxt->TabIndex = 5;
			this->fnTxt->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->fnTxt->Location = System::Drawing::Point(951, 372);
			this->fnTxt->Name = L"fnTxt";
			this->fnTxt->Size = System::Drawing::Size(162, 37);
			this->fnTxt->TabIndex = 4;
			this->label14->AutoSize = true;
			this->label14->BackColor = System::Drawing::Color::Transparent;
			this->label14->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label14->Location = System::Drawing::Point(717, 420);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(153, 31);
			this->label14->TabIndex = 3;
			this->label14->Text = L"Last Name:";
			this->label13->AutoSize = true;
			this->label13->BackColor = System::Drawing::Color::Transparent;
			this->label13->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label13->Location = System::Drawing::Point(717, 462);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(203, 31);
			this->label13->TabIndex = 2;
			this->label13->Text = L"Phone Number:";
			this->label12->AutoSize = true;
			this->label12->BackColor = System::Drawing::Color::Transparent;
			this->label12->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label12->Location = System::Drawing::Point(717, 502);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(142, 31);
			this->label12->TabIndex = 1;
			this->label12->Text = L"Password:";
			this->label11->AutoSize = true;
			this->label11->BackColor = System::Drawing::Color::Transparent;
			this->label11->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label11->Location = System::Drawing::Point(717, 375);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(155, 31);
			this->label11->TabIndex = 0;
			this->label11->Text = L"First Name:";
			this->signUpBackGround->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"signUpBackGround.BackgroundImage")));
			this->signUpBackGround->InitialImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"signUpBackGround.InitialImage")));
			this->signUpBackGround->Location = System::Drawing::Point(0, 0);
			this->signUpBackGround->Name = L"signUpBackGround";
			this->signUpBackGround->Size = System::Drawing::Size(1944, 1041);
			this->signUpBackGround->TabIndex = 25;
			this->signUpBackGround->TabStop = false;
			this->passTxt->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->passTxt->Location = System::Drawing::Point(937, 527);
			this->passTxt->Margin = System::Windows::Forms::Padding(4);
			this->passTxt->Name = L"passTxt";
			this->passTxt->PasswordChar = 42;
			this->passTxt->Size = System::Drawing::Size(156, 37);
			this->passTxt->TabIndex = 3;
			this->mainPanel->BackColor = System::Drawing::Color::White;
			this->mainPanel->Controls->Add(this->storyPanel);
			this->mainPanel->Controls->Add(this->chatPnl);
			this->mainPanel->Controls->Add(this->profilePanel);
			this->mainPanel->Controls->Add(this->addGroup);
			this->mainPanel->Controls->Add(this->addContactPanel);
			this->mainPanel->Controls->Add(this->navPanel);
			this->mainPanel->Dock = System::Windows::Forms::DockStyle::Fill;
			this->mainPanel->Location = System::Drawing::Point(0, 0);
			this->mainPanel->Name = L"mainPanel";
			this->mainPanel->Size = System::Drawing::Size(1904, 1041);
			this->mainPanel->TabIndex = 3;
			this->storyPanel->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(45)), static_cast<System::Int32>(static_cast<System::Byte>(45)),
				static_cast<System::Int32>(static_cast<System::Byte>(45)));
			this->storyPanel->Controls->Add(this->allStoriesPanel);
			this->storyPanel->Controls->Add(this->stotyHeaderPanel);
			this->storyPanel->Dock = System::Windows::Forms::DockStyle::Fill;
			this->storyPanel->Location = System::Drawing::Point(87, 0);
			this->storyPanel->Name = L"storyPanel";
			this->storyPanel->Size = System::Drawing::Size(1817, 1041);
			this->storyPanel->TabIndex = 11;
			this->allStoriesPanel->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(45)), static_cast<System::Int32>(static_cast<System::Byte>(45)),
				static_cast<System::Int32>(static_cast<System::Byte>(45)));
			this->allStoriesPanel->Dock = System::Windows::Forms::DockStyle::Fill;
			this->allStoriesPanel->FlowDirection = System::Windows::Forms::FlowDirection::TopDown;
			this->allStoriesPanel->Location = System::Drawing::Point(0, 100);
			this->allStoriesPanel->Name = L"allStoriesPanel";
			this->allStoriesPanel->Size = System::Drawing::Size(1817, 941);
			this->allStoriesPanel->TabIndex = 1;
			this->stotyHeaderPanel->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(60)), static_cast<System::Int32>(static_cast<System::Byte>(60)),
				static_cast<System::Int32>(static_cast<System::Byte>(60)));
			this->stotyHeaderPanel->Controls->Add(this->label2);
			this->stotyHeaderPanel->Controls->Add(this->button2);
			this->stotyHeaderPanel->Dock = System::Windows::Forms::DockStyle::Top;
			this->stotyHeaderPanel->Location = System::Drawing::Point(0, 0);
			this->stotyHeaderPanel->Name = L"stotyHeaderPanel";
			this->stotyHeaderPanel->Size = System::Drawing::Size(1817, 100);
			this->stotyHeaderPanel->TabIndex = 0;
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 19.8, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->label2->Location = System::Drawing::Point(33, 34);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(116, 38);
			this->label2->TabIndex = 14;
			this->label2->Text = L"Status";
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
			this->chatPnl->Controls->Add(this->currentCahtPanel);
			this->chatPnl->Controls->Add(this->contactsPanel);
			this->chatPnl->Dock = System::Windows::Forms::DockStyle::Fill;
			this->chatPnl->Location = System::Drawing::Point(87, 0);
			this->chatPnl->Name = L"chatPnl";
			this->chatPnl->Size = System::Drawing::Size(1817, 1041);
			this->chatPnl->TabIndex = 8;
			this->currentCahtPanel->BackColor = System::Drawing::Color::RosyBrown;
			this->currentCahtPanel->Controls->Add(this->chatsContainer);
			this->currentCahtPanel->Controls->Add(this->footerContainer);
			this->currentCahtPanel->Dock = System::Windows::Forms::DockStyle::Fill;
			this->currentCahtPanel->Location = System::Drawing::Point(338, 0);
			this->currentCahtPanel->Name = L"currentCahtPanel";
			this->currentCahtPanel->Size = System::Drawing::Size(1479, 1041);
			this->currentCahtPanel->TabIndex = 7;
			this->chatsContainer->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(60)), static_cast<System::Int32>(static_cast<System::Byte>(60)),
				static_cast<System::Int32>(static_cast<System::Byte>(60)));
			this->chatsContainer->Controls->Add(this->messagesFlowPanelsContainer);
			this->chatsContainer->Controls->Add(this->headerContainer);
			this->chatsContainer->Dock = System::Windows::Forms::DockStyle::Fill;
			this->chatsContainer->Location = System::Drawing::Point(0, 0);
			this->chatsContainer->Name = L"chatsContainer";
			this->chatsContainer->Size = System::Drawing::Size(1479, 995);
			this->chatsContainer->TabIndex = 14;
			this->messagesFlowPanelsContainer->Dock = System::Windows::Forms::DockStyle::Fill;
			this->messagesFlowPanelsContainer->Location = System::Drawing::Point(0, 100);
			this->messagesFlowPanelsContainer->Name = L"messagesFlowPanelsContainer";
			this->messagesFlowPanelsContainer->Size = System::Drawing::Size(1479, 895);
			this->messagesFlowPanelsContainer->TabIndex = 1;
			this->headerContainer->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(70)), static_cast<System::Int32>(static_cast<System::Byte>(70)),
				static_cast<System::Int32>(static_cast<System::Byte>(70)));
			this->headerContainer->Controls->Add(this->chatName);
			this->headerContainer->Controls->Add(this->chatPicture);
			this->headerContainer->Dock = System::Windows::Forms::DockStyle::Top;
			this->headerContainer->Location = System::Drawing::Point(0, 0);
			this->headerContainer->Name = L"headerContainer";
			this->headerContainer->Size = System::Drawing::Size(1479, 100);
			this->headerContainer->TabIndex = 0;
			this->chatName->AutoSize = true;
			this->chatName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->chatName->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->chatName->Location = System::Drawing::Point(167, 32);
			this->chatName->Name = L"chatName";
			this->chatName->Size = System::Drawing::Size(0, 36);
			this->chatName->TabIndex = 1;
			this->chatPicture->Location = System::Drawing::Point(6, 3);
			this->chatPicture->Name = L"chatPicture";
			this->chatPicture->Size = System::Drawing::Size(118, 96);
			this->chatPicture->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->chatPicture->TabIndex = 0;
			this->chatPicture->TabStop = false;
			this->footerContainer->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(50)), static_cast<System::Int32>(static_cast<System::Byte>(50)),
				static_cast<System::Int32>(static_cast<System::Byte>(50)));
			this->footerContainer->Controls->Add(this->textBox1);
			this->footerContainer->Controls->Add(this->sendButton);
			this->footerContainer->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->footerContainer->Location = System::Drawing::Point(0, 995);
			this->footerContainer->Name = L"footerContainer";
			this->footerContainer->Size = System::Drawing::Size(1479, 46);
			this->footerContainer->TabIndex = 13;
			this->footerContainer->Visible = false;
			this->textBox1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox1->Location = System::Drawing::Point(0, 0);
			this->textBox1->MaxLength = 70;
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(1397, 46);
			this->textBox1->TabIndex = 0;
			this->textBox1->Text = L"";
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
			this->contactsPanel->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(45)), static_cast<System::Int32>(static_cast<System::Byte>(45)),
				static_cast<System::Int32>(static_cast<System::Byte>(45)));
			this->contactsPanel->Dock = System::Windows::Forms::DockStyle::Left;
			this->contactsPanel->Location = System::Drawing::Point(0, 0);
			this->contactsPanel->Name = L"contactsPanel";
			this->contactsPanel->Size = System::Drawing::Size(338, 1041);
			this->contactsPanel->TabIndex = 2;
			this->profilePanel->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(45)), static_cast<System::Int32>(static_cast<System::Byte>(45)),
				static_cast<System::Int32>(static_cast<System::Byte>(45)));
			this->profilePanel->Controls->Add(this->singOutButton);
			this->profilePanel->Controls->Add(this->label1);
			this->profilePanel->Dock = System::Windows::Forms::DockStyle::Fill;
			this->profilePanel->Location = System::Drawing::Point(87, 0);
			this->profilePanel->Name = L"profilePanel";
			this->profilePanel->Size = System::Drawing::Size(1817, 1041);
			this->profilePanel->TabIndex = 10;
			this->singOutButton->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->singOutButton->Location = System::Drawing::Point(840, 410);
			this->singOutButton->Name = L"singOutButton";
			this->singOutButton->Size = System::Drawing::Size(212, 51);
			this->singOutButton->TabIndex = 1;
			this->singOutButton->Text = L"Sign out";
			this->singOutButton->UseVisualStyleBackColor = false;
			this->singOutButton->Click += gcnew System::EventHandler(this, &GuiForm::singOutButton_Click);
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(859, 290);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(211, 39);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Profile Panel";
			this->addGroup->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(45)), static_cast<System::Int32>(static_cast<System::Byte>(45)),
				static_cast<System::Int32>(static_cast<System::Byte>(45)));
			this->addGroup->Controls->Add(this->groupImgBut);
			this->addGroup->Controls->Add(this->groupImgPicBox);
			this->addGroup->Controls->Add(this->label6);
			this->addGroup->Controls->Add(this->usersListBox);
			this->addGroup->Controls->Add(this->label8);
			this->addGroup->Controls->Add(this->groupNameTxt);
			this->addGroup->Controls->Add(this->label7);
			this->addGroup->Controls->Add(this->addBtn);
			this->addGroup->Dock = System::Windows::Forms::DockStyle::Fill;
			this->addGroup->Location = System::Drawing::Point(87, 0);
			this->addGroup->Name = L"addGroup";
			this->addGroup->Size = System::Drawing::Size(1817, 1041);
			this->addGroup->TabIndex = 16;
			this->groupImgBut->BackColor = System::Drawing::Color::Cyan;
			this->groupImgBut->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->groupImgBut->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->groupImgBut->Location = System::Drawing::Point(1330, 533);
			this->groupImgBut->Name = L"groupImgBut";
			this->groupImgBut->Size = System::Drawing::Size(100, 35);
			this->groupImgBut->TabIndex = 25;
			this->groupImgBut->Text = L"Select image";
			this->groupImgBut->UseVisualStyleBackColor = false;
			this->groupImgBut->Click += gcnew System::EventHandler(this, &GuiForm::groupImgBut_Click);
			this->groupImgPicBox->BackColor = System::Drawing::Color::Transparent;
			this->groupImgPicBox->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"groupImgPicBox.Image")));
			this->groupImgPicBox->Location = System::Drawing::Point(1309, 378);
			this->groupImgPicBox->Name = L"groupImgPicBox";
			this->groupImgPicBox->Size = System::Drawing::Size(142, 133);
			this->groupImgPicBox->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->groupImgPicBox->TabIndex = 24;
			this->groupImgPicBox->TabStop = false;
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->ForeColor = System::Drawing::SystemColors::ActiveCaption;
			this->label6->Location = System::Drawing::Point(735, 635);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(371, 25);
			this->label6->TabIndex = 12;
			this->label6->Text = L"You don\'t have contacts yet\? Add contact";
			this->label6->Click += gcnew System::EventHandler(this, &GuiForm::label6_Click);
			this->usersListBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->usersListBox->FormattingEnabled = true;
			this->usersListBox->Location = System::Drawing::Point(725, 437);
			this->usersListBox->Name = L"usersListBox";
			this->usersListBox->Size = System::Drawing::Size(327, 164);
			this->usersListBox->TabIndex = 11;
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label8->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->label8->Location = System::Drawing::Point(720, 378);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(176, 31);
			this->label8->TabIndex = 10;
			this->label8->Text = L"Group Name:";
			this->groupNameTxt->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->groupNameTxt->Location = System::Drawing::Point(886, 369);
			this->groupNameTxt->Name = L"groupNameTxt";
			this->groupNameTxt->Size = System::Drawing::Size(166, 45);
			this->groupNameTxt->TabIndex = 9;
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label7->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->label7->Location = System::Drawing::Point(828, 321);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(162, 36);
			this->label7->TabIndex = 7;
			this->label7->Text = L"Add Group";
			this->addBtn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->addBtn->Location = System::Drawing::Point(811, 682);
			this->addBtn->Name = L"addBtn";
			this->addBtn->Size = System::Drawing::Size(147, 45);
			this->addBtn->TabIndex = 1;
			this->addBtn->Text = L"Create group";
			this->addBtn->UseVisualStyleBackColor = true;
			this->addBtn->Click += gcnew System::EventHandler(this, &GuiForm::addBtn_Click);
			this->addContactPanel->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(45)), static_cast<System::Int32>(static_cast<System::Byte>(45)),
				static_cast<System::Int32>(static_cast<System::Byte>(45)));
			this->addContactPanel->Controls->Add(this->addContact_btn);
			this->addContactPanel->Controls->Add(this->checkContact_btn);
			this->addContactPanel->Controls->Add(this->addContName_field);
			this->addContactPanel->Controls->Add(this->addContNum_field);
			this->addContactPanel->Controls->Add(this->label5);
			this->addContactPanel->Controls->Add(this->NameLabel);
			this->addContactPanel->Controls->Add(this->label3);
			this->addContactPanel->Dock = System::Windows::Forms::DockStyle::Fill;
			this->addContactPanel->Location = System::Drawing::Point(87, 0);
			this->addContactPanel->Name = L"addContactPanel";
			this->addContactPanel->Size = System::Drawing::Size(1817, 1041);
			this->addContactPanel->TabIndex = 14;
			this->addContact_btn->Location = System::Drawing::Point(865, 573);
			this->addContact_btn->Name = L"addContact_btn";
			this->addContact_btn->Size = System::Drawing::Size(75, 23);
			this->addContact_btn->TabIndex = 22;
			this->addContact_btn->Text = L"Add";
			this->addContact_btn->UseVisualStyleBackColor = true;
			this->addContact_btn->Visible = false;
			this->addContact_btn->Click += gcnew System::EventHandler(this, &GuiForm::addContact_btn_Click);
			this->checkContact_btn->Location = System::Drawing::Point(1028, 485);
			this->checkContact_btn->Name = L"checkContact_btn";
			this->checkContact_btn->Size = System::Drawing::Size(75, 23);
			this->checkContact_btn->TabIndex = 21;
			this->checkContact_btn->Text = L"Check";
			this->checkContact_btn->UseVisualStyleBackColor = true;
			this->checkContact_btn->Click += gcnew System::EventHandler(this, &GuiForm::checkContact_btn_Click);
			this->addContName_field->Location = System::Drawing::Point(791, 516);
			this->addContName_field->Name = L"addContName_field";
			this->addContName_field->Size = System::Drawing::Size(215, 22);
			this->addContName_field->TabIndex = 18;
			this->addContName_field->Visible = false;
			this->addContNum_field->Location = System::Drawing::Point(791, 485);
			this->addContNum_field->Name = L"addContNum_field";
			this->addContNum_field->Size = System::Drawing::Size(215, 22);
			this->addContNum_field->TabIndex = 17;
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->Location = System::Drawing::Point(713, 485);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(67, 20);
			this->label5->TabIndex = 16;
			this->label5->Text = L"Phone:";
			this->NameLabel->AutoSize = true;
			this->NameLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->NameLabel->Location = System::Drawing::Point(713, 516);
			this->NameLabel->Name = L"NameLabel";
			this->NameLabel->Size = System::Drawing::Size(63, 20);
			this->NameLabel->TabIndex = 15;
			this->NameLabel->Text = L"Name:";
			this->NameLabel->Visible = false;
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(836, 437);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(149, 29);
			this->label3->TabIndex = 14;
			this->label3->Text = L"Add contact";
			this->navPanel->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(65)), static_cast<System::Int32>(static_cast<System::Byte>(65)),
				static_cast<System::Int32>(static_cast<System::Byte>(65)));
			this->navPanel->Controls->Add(this->button7);
			this->navPanel->Controls->Add(this->chatButton);
			this->navPanel->Controls->Add(this->goToAddContact_btn);
			this->navPanel->Controls->Add(this->statusButton);
			this->navPanel->Controls->Add(this->profileButton);
			this->navPanel->Dock = System::Windows::Forms::DockStyle::Left;
			this->navPanel->Location = System::Drawing::Point(0, 0);
			this->navPanel->Name = L"navPanel";
			this->navPanel->Size = System::Drawing::Size(87, 1041);
			this->navPanel->TabIndex = 5;
			this->button7->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->button7->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button7.BackgroundImage")));
			this->button7->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->button7->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button7->FlatAppearance->BorderSize = 0;
			this->button7->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button7->Location = System::Drawing::Point(12, 714);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(63, 60);
			this->button7->TabIndex = 5;
			this->button7->UseVisualStyleBackColor = true;
			this->button7->Click += gcnew System::EventHandler(this, &GuiForm::button7_Click);
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
			this->goToAddContact_btn->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->goToAddContact_btn->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"goToAddContact_btn.BackgroundImage")));
			this->goToAddContact_btn->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->goToAddContact_btn->Cursor = System::Windows::Forms::Cursors::Hand;
			this->goToAddContact_btn->FlatAppearance->BorderSize = 0;
			this->goToAddContact_btn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->goToAddContact_btn->Location = System::Drawing::Point(12, 830);
			this->goToAddContact_btn->Name = L"goToAddContact_btn";
			this->goToAddContact_btn->Size = System::Drawing::Size(63, 60);
			this->goToAddContact_btn->TabIndex = 3;
			this->goToAddContact_btn->UseVisualStyleBackColor = true;
			this->goToAddContact_btn->Click += gcnew System::EventHandler(this, &GuiForm::goToAddContact_btn_Click);
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
			this->textStory->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(45)), static_cast<System::Int32>(static_cast<System::Byte>(45)),
				static_cast<System::Int32>(static_cast<System::Byte>(45)));
			this->textStory->Font = (gcnew System::Drawing::Font(L"Sans Serif Collection", 16.2, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textStory->Location = System::Drawing::Point(3, 81);
			this->textStory->Multiline = true;
			this->textStory->Name = L"textStory";
			this->textStory->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->textStory->Size = System::Drawing::Size(1901, 864);
			this->textStory->TabIndex = 1;
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
			this->colorDialog1->FullOpen = true;
			this->getStoryPanel->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(45)), static_cast<System::Int32>(static_cast<System::Byte>(45)),
				static_cast<System::Int32>(static_cast<System::Byte>(45)));
			this->getStoryPanel->Controls->Add(this->footerOfTheSroryPanel);
			this->getStoryPanel->Controls->Add(this->bodyOfTheStoryPanel);
			this->getStoryPanel->Controls->Add(this->profileUserInStoryPanel);
			this->getStoryPanel->Dock = System::Windows::Forms::DockStyle::Fill;
			this->getStoryPanel->Location = System::Drawing::Point(0, 0);
			this->getStoryPanel->Name = L"getStoryPanel";
			this->getStoryPanel->Size = System::Drawing::Size(1904, 1041);
			this->getStoryPanel->TabIndex = 14;
			this->footerOfTheSroryPanel->Controls->Add(this->viewerOfTheStoryBtn);
			this->footerOfTheSroryPanel->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->footerOfTheSroryPanel->Location = System::Drawing::Point(0, 951);
			this->footerOfTheSroryPanel->Name = L"footerOfTheSroryPanel";
			this->footerOfTheSroryPanel->Size = System::Drawing::Size(1904, 90);
			this->footerOfTheSroryPanel->TabIndex = 2;
			this->viewerOfTheStoryBtn->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->viewerOfTheStoryBtn->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"viewerOfTheStoryBtn.BackgroundImage")));
			this->viewerOfTheStoryBtn->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->viewerOfTheStoryBtn->FlatAppearance->BorderSize = 0;
			this->viewerOfTheStoryBtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->viewerOfTheStoryBtn->ForeColor = System::Drawing::Color::DarkCyan;
			this->viewerOfTheStoryBtn->Location = System::Drawing::Point(921, 28);
			this->viewerOfTheStoryBtn->Name = L"viewerOfTheStoryBtn";
			this->viewerOfTheStoryBtn->Size = System::Drawing::Size(93, 42);
			this->viewerOfTheStoryBtn->TabIndex = 0;
			this->viewerOfTheStoryBtn->UseVisualStyleBackColor = true;
			this->viewerOfTheStoryBtn->Click += gcnew System::EventHandler(this, &GuiForm::viewerOfTheStoryBtn_Click);
			this->bodyOfTheStoryPanel->Controls->Add(this->bodyOfTheStoryLabel);
			this->bodyOfTheStoryPanel->Dock = System::Windows::Forms::DockStyle::Fill;
			this->bodyOfTheStoryPanel->Location = System::Drawing::Point(0, 128);
			this->bodyOfTheStoryPanel->Name = L"bodyOfTheStoryPanel";
			this->bodyOfTheStoryPanel->Size = System::Drawing::Size(1904, 913);
			this->bodyOfTheStoryPanel->TabIndex = 1;
			this->bodyOfTheStoryLabel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->bodyOfTheStoryLabel->AutoSize = true;
			this->bodyOfTheStoryLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 19.8, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->bodyOfTheStoryLabel->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->bodyOfTheStoryLabel->Location = System::Drawing::Point(842, 292);
			this->bodyOfTheStoryLabel->Name = L"bodyOfTheStoryLabel";
			this->bodyOfTheStoryLabel->Size = System::Drawing::Size(0, 38);
			this->bodyOfTheStoryLabel->TabIndex = 1;
			this->profileUserInStoryPanel->Controls->Add(this->cancelStoryBtn);
			this->profileUserInStoryPanel->Controls->Add(this->dateInStoryLabel);
			this->profileUserInStoryPanel->Controls->Add(this->nameInStoryLabel);
			this->profileUserInStoryPanel->Controls->Add(this->profileStoryPic);
			this->profileUserInStoryPanel->Dock = System::Windows::Forms::DockStyle::Top;
			this->profileUserInStoryPanel->Location = System::Drawing::Point(0, 0);
			this->profileUserInStoryPanel->Name = L"profileUserInStoryPanel";
			this->profileUserInStoryPanel->Size = System::Drawing::Size(1904, 128);
			this->profileUserInStoryPanel->TabIndex = 0;
			this->cancelStoryBtn->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->cancelStoryBtn->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"cancelStoryBtn.BackgroundImage")));
			this->cancelStoryBtn->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->cancelStoryBtn->FlatAppearance->BorderSize = 0;
			this->cancelStoryBtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->cancelStoryBtn->ForeColor = System::Drawing::Color::DarkCyan;
			this->cancelStoryBtn->Location = System::Drawing::Point(1799, 13);
			this->cancelStoryBtn->Name = L"cancelStoryBtn";
			this->cancelStoryBtn->Size = System::Drawing::Size(93, 52);
			this->cancelStoryBtn->TabIndex = 1;
			this->cancelStoryBtn->UseVisualStyleBackColor = true;
			this->cancelStoryBtn->Click += gcnew System::EventHandler(this, &GuiForm::cancelStoryBtn_Click);
			this->dateInStoryLabel->AutoSize = true;
			this->dateInStoryLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Tai Le", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->dateInStoryLabel->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->dateInStoryLabel->Location = System::Drawing::Point(163, 81);
			this->dateInStoryLabel->Name = L"dateInStoryLabel";
			this->dateInStoryLabel->Size = System::Drawing::Size(53, 25);
			this->dateInStoryLabel->TabIndex = 2;
			this->dateInStoryLabel->Text = L"Date";
			this->nameInStoryLabel->AutoSize = true;
			this->nameInStoryLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 19.8, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->nameInStoryLabel->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->nameInStoryLabel->Location = System::Drawing::Point(140, 9);
			this->nameInStoryLabel->Name = L"nameInStoryLabel";
			this->nameInStoryLabel->Size = System::Drawing::Size(102, 38);
			this->nameInStoryLabel->TabIndex = 1;
			this->nameInStoryLabel->Text = L"name";
			this->profileStoryPic->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"profileStoryPic.BackgroundImage")));
			this->profileStoryPic->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->profileStoryPic->Dock = System::Windows::Forms::DockStyle::Left;
			this->profileStoryPic->Location = System::Drawing::Point(0, 0);
			this->profileStoryPic->Name = L"profileStoryPic";
			this->profileStoryPic->Size = System::Drawing::Size(99, 128);
			this->profileStoryPic->TabIndex = 0;
			this->profileStoryPic->TabStop = false;
			this->SignINPnl->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"SignINPnl.BackgroundImage")));
			this->SignINPnl->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->SignINPnl->Controls->Add(this->button8);
			this->SignINPnl->Controls->Add(this->label10);
			this->SignINPnl->Controls->Add(this->label9);
			this->SignINPnl->Controls->Add(this->passLbl);
			this->SignINPnl->Controls->Add(this->numLbl);
			this->SignINPnl->Controls->Add(this->passTxt);
			this->SignINPnl->Controls->Add(this->phoneTxt);
			this->SignINPnl->Controls->Add(this->label4);
			this->SignINPnl->Controls->Add(this->signinBackGround);
			this->SignINPnl->Dock = System::Windows::Forms::DockStyle::Fill;
			this->SignINPnl->Location = System::Drawing::Point(0, 0);
			this->SignINPnl->Margin = System::Windows::Forms::Padding(4);
			this->SignINPnl->Name = L"SignINPnl";
			this->SignINPnl->Size = System::Drawing::Size(1904, 1041);
			this->SignINPnl->TabIndex = 15;
			this->button8->BackColor = System::Drawing::Color::Cyan;
			this->button8->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button8->Location = System::Drawing::Point(1488, 830);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(206, 80);
			this->button8->TabIndex = 9;
			this->button8->Text = L"Sign In →";
			this->button8->UseVisualStyleBackColor = false;
			this->button8->Click += gcnew System::EventHandler(this, &GuiForm::button8_Click);
			this->label10->AutoSize = true;
			this->label10->BackColor = System::Drawing::Color::Transparent;
			this->label10->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25, System::Drawing::FontStyle::Underline, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label10->ForeColor = System::Drawing::Color::Turquoise;
			this->label10->Location = System::Drawing::Point(984, 587);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(77, 24);
			this->label10->TabIndex = 8;
			this->label10->Text = L"Sign Up";
			this->label10->Click += gcnew System::EventHandler(this, &GuiForm::label10_Click);
			this->label9->AutoSize = true;
			this->label9->BackColor = System::Drawing::Color::Transparent;
			this->label9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label9->ForeColor = System::Drawing::Color::Turquoise;
			this->label9->Location = System::Drawing::Point(800, 587);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(236, 24);
			this->label9->TabIndex = 7;
			this->label9->Text = L"Don\'t have an account yet\?";
			this->passLbl->AutoSize = true;
			this->passLbl->BackColor = System::Drawing::Color::Transparent;
			this->passLbl->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->passLbl->Location = System::Drawing::Point(750, 533);
			this->passLbl->Name = L"passLbl";
			this->passLbl->Size = System::Drawing::Size(142, 31);
			this->passLbl->TabIndex = 6;
			this->passLbl->Tag = L"";
			this->passLbl->Text = L"Password:";
			this->numLbl->AutoSize = true;
			this->numLbl->BackColor = System::Drawing::Color::Transparent;
			this->numLbl->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->numLbl->Location = System::Drawing::Point(717, 462);
			this->numLbl->Name = L"numLbl";
			this->numLbl->Size = System::Drawing::Size(203, 31);
			this->numLbl->TabIndex = 4;
			this->numLbl->Text = L"Phone Number:";
			this->phoneTxt->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->phoneTxt->Location = System::Drawing::Point(937, 459);
			this->phoneTxt->Name = L"phoneTxt";
			this->phoneTxt->Size = System::Drawing::Size(156, 37);
			this->phoneTxt->TabIndex = 2;
			this->label4->AutoSize = true;
			this->label4->BackColor = System::Drawing::Color::Transparent;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 36, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(737, 231);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(624, 69);
			this->label4->TabIndex = 1;
			this->label4->Text = L"Welcome to Chati App";
			this->storyTimerTemp->Interval = 3000;
			this->storyTimerTemp->Tick += gcnew System::EventHandler(this, &GuiForm::storyTimerTemp_Tick);
			this->signinBackGround->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"signinBackGround.BackgroundImage")));
			this->signinBackGround->InitialImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"signinBackGround.InitialImage")));
			this->signinBackGround->Location = System::Drawing::Point(0, 0);
			this->signinBackGround->Name = L"signinBackGround";
			this->signinBackGround->Size = System::Drawing::Size(1944, 1041);
			this->signinBackGround->TabIndex = 26;
			this->signinBackGround->TabStop = false;
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
			this->ClientSize = System::Drawing::Size(1904, 1041);
			this->Controls->Add(this->SignINPnl);
			this->Controls->Add(this->signUpPnl);
			this->Controls->Add(this->mainPanel);
			this->Controls->Add(this->getStoryPanel);
			this->Controls->Add(this->signUpPnl);
			this->Controls->Add(this->addStoryPanel);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->mainPanel);
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"GuiForm";
			this->Text = L"chatApp";
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &GuiForm::GuiForm_FormClosed);
			this->Load += gcnew System::EventHandler(this, &GuiForm::GuiForm_Load);
			this->signUpPnl->ResumeLayout(false);
			this->signUpPnl->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->signUpBackGround))->EndInit();
			this->mainPanel->ResumeLayout(false);
			this->storyPanel->ResumeLayout(false);
			this->stotyHeaderPanel->ResumeLayout(false);
			this->stotyHeaderPanel->PerformLayout();
			this->chatPnl->ResumeLayout(false);
			this->currentCahtPanel->ResumeLayout(false);
			this->chatsContainer->ResumeLayout(false);
			this->headerContainer->ResumeLayout(false);
			this->headerContainer->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chatPicture))->EndInit();
			this->footerContainer->ResumeLayout(false);
			this->profilePanel->ResumeLayout(false);
			this->profilePanel->PerformLayout();
			this->addGroup->ResumeLayout(false);
			this->addGroup->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->groupImgPicBox))->EndInit();
			this->addContactPanel->ResumeLayout(false);
			this->addContactPanel->PerformLayout();
			this->navPanel->ResumeLayout(false);
			this->addStoryPanel->ResumeLayout(false);
			this->addStoryPanel->PerformLayout();
			this->getStoryPanel->ResumeLayout(false);
			this->footerOfTheSroryPanel->ResumeLayout(false);
			this->bodyOfTheStoryPanel->ResumeLayout(false);
			this->bodyOfTheStoryPanel->PerformLayout();
			this->profileUserInStoryPanel->ResumeLayout(false);
			this->profileUserInStoryPanel->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->profileStoryPic))->EndInit();
			this->SignINPnl->ResumeLayout(false);
			this->SignINPnl->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->signinBackGround))->EndInit();
			this->ResumeLayout(false);

		}
		#pragma endregion


		private: System::Void GuiForm_Load(System::Object^ sender, System::EventArgs^ e) {
			
			loadFromFile(users, chatRooms, messages);

			//cout << "messages size: " << chatRooms[1].messagesID.size() << endl;
			//for (int i : chatRooms[1].messagesID) {
			//	cout << "messageID: " << i << endl;
			//}
			// will remove this later
			//sortChatRooms(*currentUser, Activity, chatRooms, contactsPanel);
			//currentChatRoom = new ChatRoom(1, true);
			//currentChatRoom->addUserPhone(currentUser->getMobileNumber());
			//chatRooms[1] = *currentChatRoom;

			//for(auto chatRoom: chatRooms){
			//	cout << "chatRoom ID: " << chatRoom.first << endl;

			//	for(auto userID: chatRoom.second.getUsersID()){
			//		cout << "userID: " << userID << endl;
			//	}

			//	LinkedList list1 = chatRoom.second.getMessagesID();

			//	for (Node* item = list1.begin(); item != list1.end(); item = item->next) {
			//		cout << "Message Text: " << messages[item->value].getText() << " ";
			//		cout << "Message ID: " << messages[item->value].getMessageID() << " ";

			//	}
			//	cout << endl;
			//}

			//for(auto m: currentChatRoom->getMessagesID()){
			//	cout << "messageID from current chat: " << m << endl;
			//	cout << "text: " << messages[m].getText() << endl;
			//}
			//cout << endl;
			//
			// 
			//for (auto m : messages) {
			//	cout << "messageID: " << m.first << " : " << m.second.getIsRead() << endl;
			//	cout << "Text : " << m.second.getText() << endl;
			//	cout << "Sender ID: " << m.second.getSenderPhone() << endl;
			//	cout << "date Sent: " << m.second.getDateSent() << endl;
			//}
			//for (auto ChatRoomID: currentUser->getChatRoomsID())
			//{
			//	addChatRoomPanel(users[chatRooms[ChatRoomID].getUsersID()[1]] );
			//}
			cout << "Users Number: " << users.size() << endl;
			for (auto u : users) {
				cout << u.second.getMobileNumber() << endl;
				cout << u.second.getFirstName() << endl;
				cout << u.second.getLastName() << endl;
				cout << u.second.getPassword() << endl;
				cout << u.second.getProfilePhoto() << endl;
				for(auto &c: u.second.getContactsPhones()){
                    cout << "contact ID: " << c.first << endl;
				}
				cout << endl;
			}


			//// clear the chat rooms and contacts of the users
			//for (auto &user : users)
			//{
			//	for(int chatRoomID : user.second.getChatRoomsID()) {
			//		user.second.removeChatRoomID(chatRoomID);
			//		cout << chatRoomID << endl;
			//	}

			//	for(auto contacID : user.second.getContactsPhones()) {
			//		user.second.removeContactPhone(contacID.first);
			//	}
			//}
			//messages.clear();
			//chatRooms.clear();


			chatRoomHandler.activity = &Activity;
			chatRoomHandler.chatRooms = &chatRooms;
			chatRoomHandler.messages = &messages;
			chatRoomHandler.currentChatRoom = &currentChatRoom;
			chatRoomHandler.currentUser = &currentUser;
			chatRoomHandler.messagesFlowPanelsContainer = messagesFlowPanelsContainer;
			chatRoomHandler.chatRoomsPanels = chatRoomsPanels;
			chatRoomHandler.footerContainer = footerContainer;
			chatRoomHandler.headerContainer = headerContainer;
			chatRoomHandler.users = &users;


			handler.globalMessages = &messages;
			handler.globalChatRoom = &currentChatRoom;
			handler.currentUser = currentUser;
			handler.messagesContainer = messagesFlowPanelsContainer;


			chatRoomHandler.messageHandler.globalMessages = &messages;
			chatRoomHandler.messageHandler.globalChatRoom = &currentChatRoom;
			chatRoomHandler.messageHandler.currentUser = currentUser;
			chatRoomHandler.messageHandler.messagesContainer = messagesFlowPanelsContainer;
		}

		private: System::Void button9_Click(System::Object^ sender, System::EventArgs^ e) {
		
			

			if (numTxt->Text == "" || pasTxt->Text == "" || fnTxt->Text == "" || lnTxt->Text == "")
			{
				MessageBox::Show("Please fill all the fields","Infromation incompleted");
				return;
			}
			if (numTxt->Text->Length < 11 || numTxt->Text->Length > 11)
			{
				MessageBox::Show("Mobile number must be 11 digits","Invalid Mobile Number");
				return;
			}
			if (pasTxt->Text->Length < 6)
			{
				MessageBox::Show("Password must be at least 6 characters","Invalid Password");
				return;
			}
		
			string mobileNumber = msclr::interop::marshal_as<string>(numTxt->Text);
			string password = msclr::interop::marshal_as<string>(pasTxt->Text);
			string firstName = msclr::interop::marshal_as<string>(fnTxt->Text);
			string lastName = msclr::interop::marshal_as<std::string>(lnTxt->Text);

			if (checkUser(mobileNumber, users)) {
				MessageBox::Show("This mobile number is already registered", "Sign up error");
				return;
			}


			string filename = msclr::interop::marshal_as<std::string>(fileName->ToString());
			if(filename != "User.png")
				File::Copy(selectedImagePath, destinationPath, true);

			signUp(mobileNumber, password, firstName, lastName, users, filename);

			MessageBox::Show("Signed Up successfully", "Signed Up");
			SignINPnl->BringToFront();
			pictureBox2->Image = nullptr;
		}
		
		
		private: System::Void button8_Click(System::Object^ sender, System::EventArgs^ e) {
			if (passTxt->Text->Length < 6)
			{
				MessageBox::Show("Password must be at least 6 characters", "Invalid Password");
				return;
			}
			if (phoneTxt->Text == "")
			{
				MessageBox::Show("Please fill all the fields", "Infromation incompleted");
				return;
			}
			string mobileNumber = msclr::interop::marshal_as<std::string>(phoneTxt->Text);
			string password = msclr::interop::marshal_as<std::string>(passTxt->Text);


			if (!checkSignIn(mobileNumber, password, users))
			{
				MessageBox::Show("Invalid mobile number or password", "Sign in error");
				return;
			}
			else {
				phoneTxt->Clear();
				passTxt->Clear();
				headerContainer->Visible = false;

				currentUser = &users[mobileNumber];

				if (currentUser->getStoriesID().size() > 0) {
					createUserStoryPanel();
				}

				messagesFlowPanelsContainer->Controls->Clear();
				contactsPanel->Controls->Clear();

				for(int chatRoom: currentUser->getChatRoomsID()){

					FlowLayoutPanel^ chatRoomPanel = chatRoomHandler.createChatRoomGUI(chatRoom, messagesFlowPanelsContainer);

					handler.initializeChat(&chatRooms[chatRoom], chatRoomPanel, messages, currentUser, Activity);

					if (chatRooms[chatRoom].getIsDual())
					{

						//string filename = msclr::interop::marshal_as<std::string>(fileName->ToString());
						/*if (filename != "User.png")
							File::Copy(selectedImagePath, destinationPath, true);*/

						if(chatRooms[chatRoom].getUsersID()[0] == currentUser->getMobileNumber())
							chatRoomHandler.addChatRoomPanel(currentUser->getContactsPhones()[chatRooms[chatRoom].getUsersID()[1]], chatRoom, contactsPanel);
						else
							chatRoomHandler.addChatRoomPanel(users[chatRooms[chatRoom].getUsersID()[0]].getFirstName() + ' ' + users[chatRooms[chatRoom].getUsersID()[0]].getLastName(), chatRoom, contactsPanel);

					}
					else {

						string groupName = chatRooms[chatRoom].getGroupName();
						chatRoomHandler.addChatRoomPanel(groupName, chatRoom, contactsPanel);
					}
				}

				sortChatRooms(*currentUser, Activity, chatRooms, contactsPanel, messages);
				mainPanel->BringToFront();
			}
	
		}


		private: System::Void sendButton_Click(System::Object^ sender, System::EventArgs^ e) {
			handler.createMessageEvent(textBox1, chatRoomsPanels[currentChatRoom->getChatRoomID()], currentUser, Activity, contactsPanel, chatRooms, currentChatRoom,messages);
		}
			   
		private: System::Void GuiForm_FormClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e) {
			/*stories.clear();
			currentUser->setStoriesID({});*/
			//users[currentUser->getMobileNumber()] = *currentUser;
			saveToFile(users, chatRooms, messages);
		}
			   //?/shehab
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
			colorDialog = gcnew ColorDialog();
			colorDialog->AllowFullOpen = true;
			colorDialog->ShowHelp = true;
			colorDialog->Color = System::Drawing::Color::Black; //to initialze it with black
			if (colorDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK)
			{
				//? Set the background color of the form to the selected color
				this->addStoryPanel->BackColor = colorDialog->Color;
				this->textStory->BackColor = colorDialog->Color;
			}
		}
		private: System::Void button6_Click(System::Object^ sender, System::EventArgs^ e) {
			fontDialog = gcnew FontDialog();
			fontDialog->ShowColor = true;
			fontDialog->ShowEffects = true;
			fontDialog->Font = textStory->Font; //? to initilze it with the current color
			if (fontDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK)
			{
				textStory->Font = fontDialog->Font;
				textStory->ForeColor = fontDialog->Color;
			}

		}
		private: System::Void createStory() {
			// Create story 
			time_t publishTime = time(0);
			std::string textStoryString = msclr::interop::marshal_as<std::string>(textStory->Text);

			if (textStoryString == "") {
				MessageBox::Show("Please fill the story text", "Information Incomplete");
				return;
			}

			// Default font settings
			string fontName = "Arial";
			float fontSize = 12.0f;
			int fontStyleAsInt = 0;

			// Check if fontDialog is not null before accessing its properties
			if (fontDialog != nullptr && fontDialog->Font != nullptr) {
				fontName = msclr::interop::marshal_as<std::string>(fontDialog->Font->Name);
				fontSize = fontDialog->Font->Size;
				fontStyleAsInt = (int)fontDialog->Font->Style;
			}

			// Default color
			string colorHex = "#2D2D2D";

			// Check if colorDialog is not null and a color has been selected
			if (colorDialog != nullptr && colorDialog->Color.ToArgb() != 0) {
				colorHex = msclr::interop::marshal_as<std::string>(System::Drawing::ColorTranslator::ToHtml(colorDialog->Color));
			}

			// Create the story
			Story* story = new Story(textStoryString, publishTime, "", fontName, fontSize, fontStyleAsInt, colorHex);
			currentUser->getStoriesID().insert(story->getStoryID());
			cout << "if the story added: " << bool(currentUser->addStoryID(story->getStoryID())) << endl;
			stories[story->getStoryID()] = *story;
			cout << "the storyID in the map: " << stories[story->getStoryID()].getStoryID() << endl;
			cout << "number of stories is: " << currentUser->getStoriesID().size() << endl << endl;
		}
		
		private: System::Void createUserStoryPanel() {
			//? Define the PictureBox for the user story image
			PictureBox^ pictureUserStoryPic = gcnew PictureBox();

			//? Load the resources
			System::ComponentModel::ComponentResourceManager^ resources = gcnew System::ComponentModel::ComponentResourceManager(GuiForm::typeid);
			cli::array<System::Byte>^ imageBytes = (cli::safe_cast<cli::array<System::Byte>^>(resources->GetObject(L"user")));

			//? Convert byte array to Image using MemoryStream
			MemoryStream^ ms = gcnew MemoryStream(imageBytes);
			pictureUserStoryPic->Image = System::Drawing::Image::FromStream(ms);

			//? Set the SizeMode to Zoom for the image to be zoomed correctly and fit within the PictureBox
			pictureUserStoryPic->SizeMode = PictureBoxSizeMode::Zoom;
			pictureUserStoryPic->Dock = System::Windows::Forms::DockStyle::Left;
			pictureUserStoryPic->InitialImage = nullptr;
			pictureUserStoryPic->Location = System::Drawing::Point(0, 0);
			pictureUserStoryPic->Name = L"pictureUserStoryPic";
			pictureUserStoryPic->Size = System::Drawing::Size(99, 97); // Adjust size as needed
			pictureUserStoryPic->TabIndex = 0;
			pictureUserStoryPic->TabStop = false;

			//? name story panel
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


			//? label dateStoryPanel
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
            DateUserStoryLabel->Text = gcnew String(DateTime::Now.ToString("hh:mm tt")); // Set the date format as needed
			// Set the date format as needed

			//? Set up the user story panel
			Panel^ userStoryPanel = gcnew Panel();
			userStoryPanel->Controls->Add(DateUserStoryLabel);
			userStoryPanel->Controls->Add(nameUserStoryLabel);
			userStoryPanel->Controls->Add(pictureUserStoryPic);
			userStoryPanel->Location = System::Drawing::Point(3, 3);
			userStoryPanel->Name = L"userStoryPanel";
			userStoryPanel->Size = System::Drawing::Size(1249, 97);
			userStoryPanel->TabIndex = 0;

			//? Add click event handler to the user story panel
			userStoryPanel->Click += gcnew System::EventHandler(this, &GuiForm::userStoryPanel_Click);

			//? Add the user story panel to the main panel
			this->allStoriesPanel->Controls->Add(userStoryPanel);
		}


			   //todo                      CURRENT POINT
		private: System::Void userStoryPanel_Click(System::Object^ sender, System::EventArgs^ e) {
			//? Handle the logic of the click event here
			// get the all info of the user (name + stories)
			string name= currentUser->getFirstName() + " " + currentUser->getLastName();
			nameInStoryLabel->Text = gcnew System::String(name.c_str());
			storiesIDTemp = currentUser->getStoriesID();
			//? delete the first story
			auto begin = storiesIDTemp.begin();
			Story currentStory = stories[*begin];
			//? get the story text
			string textShown = currentStory.getStoryText();
			bodyOfTheStoryLabel->Text = gcnew System::String(textShown.c_str());
			//? format the date to string
			string date = formatTimeToHHMM(currentStory.getPublishTime());
			dateInStoryLabel->Text = gcnew System::String(date.c_str());
			//? handle the color and the font
			System::String^ fontName = gcnew System::String(currentStory.getFontName().c_str());
			System::Drawing::Font^ fontStoryTemp = gcnew System::Drawing::Font(
				fontName,
				currentStory.getFontSize(),
				(System::Drawing::FontStyle)currentStory.getFontStyle()
			);

			Color storyColorTemp = ColorTranslator::FromHtml(gcnew System::String(currentStory.getColorHex().c_str()));
			//? load the font and the color
			\
			//? set the font and the color to the label
			bodyOfTheStoryPanel->BackColor = storyColorTemp;
			bodyOfTheStoryLabel->Font = fontStoryTemp;
			//? erase the first story
			storiesIDTemp.erase(begin);
			//? enable the timer
			storyTimerTemp->Enabled = true;


			//? Set the date format as needed

			getStoryPanel->BringToFront();
			//? show the panel of the user story
		}
			   //todo				END OF THE CURRENT POINT
		private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
			string textStoryString = msclr::interop::marshal_as<std::string>(textStory->Text);
			if (textStoryString =="") {
				MessageBox::Show("Please fill the story text", "Infromation incompleted");
				return;
			}
			cout << "the number of the stories: " << currentUser->getStoriesID().size()<<" for "<<currentUser->getFirstName() << endl;
			if (currentUser->getStoriesID().size()==0) {
				createUserStoryPanel();
			}
			createStory();
			addStoryPanel->BringToFront();
			mainPanel->BringToFront();
			//? update userStoryPanel->(Date)
			//time_t now = time(0);
			//tm localTime;
			//localtime_s(&localTime, &now);  // safer on Windows

			//char buffer[80];
			//strftime(buffer, sizeof(buffer), "%I-%M %p", &localTime);  // hh-mm tt format

			//DateUserStoryLabel->Text = gcnew String(buffer);
			//cout << "number of story valid: " << currentUser->getStoriesID().size()<<"for the current user"<<currentUser->getFirstName() << endl;
			
		}
			//?shehab/  
		private: System::Void checkContact_btn_Click(System::Object^ sender, System::EventArgs^ e) {
			string contNum = msclr::interop::marshal_as<std::string>(addContNum_field->Text);
			if (contNum.size() < 11) {
				MessageBox::Show("Invalid phone number", "Error");
			}
			else {

				// Check if the contact already exists

				if (checkUserExist(contNum, users, currentContName)) {
					currentContNum = contNum;

					NameLabel->Visible = true;
					addContName_field->Visible = true;
					addContact_btn->Visible = true;

					addContName_field->Text = gcnew System::String(currentContName.c_str());
				}
				else {
					MessageBox::Show("User does not exist", "Error");

				}
			}
			
		}

		private: System::Void addContact_btn_Click(System::Object^ sender, System::EventArgs^ e) {
			string contNum = msclr::interop::marshal_as<std::string>(addContNum_field->Text);
			addContName_field->Visible = false;
			addContact_btn->Visible = false;
			NameLabel->Visible = false;
			if (checkContactExist(contNum, *currentUser)) {
				MessageBox::Show("Contact already exists", "Error");
			}
			else {
				string groupFilename = msclr::interop::marshal_as<std::string>(groupFileName->ToString());
				if (groupFileName != "User.png")
					File::Copy(selectedImagePath, destinationPath, true);

				string contName = msclr::interop::marshal_as<std::string>(addContName_field->Text);
				chatRoomHandler.createRoom(currentContNum,contName,currentUser, addContName_field, addContNum_field, chatRooms, contactsPanel,Activity, messagesFlowPanelsContainer, users,groupFilename,messages);
				sortChatRooms(*currentUser, Activity, chatRooms, contactsPanel, messages);
			
			}
		}


		//? /shehab
		private: System::Void goToAddContact_btn_Click(System::Object^ sender, System::EventArgs^ e) {
			addContactPanel->BringToFront();
		}
	
		private: System::Void cancelStoryBtn_Click(System::Object^ sender, System::EventArgs^ e) {
			mainPanel->BringToFront();
			storyPanel->BringToFront();
		}
		private: System::Void viewerOfTheStoryBtn_Click(System::Object^ sender, System::EventArgs^ e) {
			MessageBox::Show("Viewer of the story button clicked!");
		}
		//?shehab/
		private: System::Void singOutButton_Click(System::Object^ sender, System::EventArgs^ e) {
			SignINPnl->BringToFront();
		}
		private: System::Void button12_Click(System::Object^ sender, System::EventArgs^ e) {
			OpenFileDialog^ openFileDialog = gcnew OpenFileDialog();
			openFileDialog->Title = "Select an image";
			openFileDialog->Filter = "Image Files|*.jpg;*.jpeg;*.png;*.bmp;*.gif";

            if (openFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK)
			{
				pictureBox2->Image = Image::FromFile(openFileDialog->FileName);
                selectedImagePath = openFileDialog->FileName;
				fileName = Path::GetFileName(selectedImagePath);

				String^ projectRoot = Directory::GetParent(Application::StartupPath)->Parent->FullName;
				String^ imagesFolder = Path::Combine(projectRoot, "usersImages");

				// Ensure the folder exists
				if (!Directory::Exists(imagesFolder))
					Directory::CreateDirectory(imagesFolder);

				// Create full destination path
				destinationPath = Path::Combine(imagesFolder, fileName);
			}
		}


		private: System::Void label6_Click(System::Object^ sender, System::EventArgs^ e) {
			addContactPanel->BringToFront();
		}

		private: System::Void groupImgBut_Click(System::Object^ sender, System::EventArgs^ e) {
			OpenFileDialog^ openFileDialog = gcnew OpenFileDialog();
			openFileDialog->Title = "Select an image";
			openFileDialog->Filter = "Image Files|*.jpg;*.jpeg;*.png;*.bmp;*.gif";

			if (openFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK)
			{
				groupImgPicBox->Image = Image::FromFile(openFileDialog->FileName);
				selectedGroupImagePath = openFileDialog->FileName;
				groupFileName = Path::GetFileName(selectedGroupImagePath);

				String^ projectRoot = Directory::GetParent(Application::StartupPath)->Parent->FullName;
				String^ imagesFolder = Path::Combine(projectRoot, "usersImages");

				if (!Directory::Exists(imagesFolder))
					Directory::CreateDirectory(imagesFolder);

				groupImageDestinationPath = Path::Combine(imagesFolder, groupFileName);

				File::Copy(selectedGroupImagePath, groupImageDestinationPath, true);
			}

		}

		private: System::Void addBtn_Click(System::Object^ sender, System::EventArgs^ e) {
			if (groupNameTxt->Text == "") {
				MessageBox::Show("Please enter group name", "Error");
			}
			else {
				string filename = msclr::interop::marshal_as<std::string>(groupFileName->ToString());
				if (filename != "default-group.png")
					File::Copy(selectedGroupImagePath, groupImageDestinationPath, true);
			
				string groupName = msclr::interop::marshal_as<std::string>(groupNameTxt->Text);
				groupNameTxt->Text = "";
				chatRoomHandler.createGroup(currentUser, chatRooms, messagesFlowPanelsContainer,
					usersListBox, users, contactsPanel, groupName, Activity,filename,messages);
				sortChatRooms(*currentUser, Activity, chatRooms, contactsPanel, messages);
			}
			groupImgPicBox->Image = nullptr;
		}
		private: System::Void button7_Click(System::Object^ sender, System::EventArgs^ e) {
			addGroup->BringToFront();
			usersListBox->Items->Clear();
			for (auto& contact : currentUser->getContactsPhones()) {
				String^ name = gcnew String(contact.second.c_str());
				String^ number = gcnew String(contact.first.c_str());
				usersListBox->Items->Add(number + " (" + name + ")");
			}
		}

		private: System::Void button10_Click(System::Object^ sender, System::EventArgs^ e) {
			SignINPnl->BringToFront();
		}
		private: System::Void label10_Click(System::Object^ sender, System::EventArgs^ e) {
			signUpPnl->BringToFront();
		}

		//? shehab
		private: System::Void storyTimerTemp_Tick(System::Object^ sender, System::EventArgs^ e) {
			//? show the stories temporarily
			if (storiesIDTemp.size() > 0) {
				auto begin = storiesIDTemp.begin();
				Story currentStory = stories[*begin];
				string textShown = currentStory.getStoryText();
				//? initilize the label with the text of the story
				bodyOfTheStoryLabel->Text = gcnew System::String(textShown.c_str());
				string date = formatTimeToHHMM(currentStory.getPublishTime());
				//? initilize the label with the date of the story
				dateInStoryLabel->Text = gcnew System::String(date.c_str());
				//? declare the font and the color we will use
				System::String^ fontName = gcnew System::String(currentStory.getFontName().c_str());
				System::Drawing::Font^ fontStoryTemp = gcnew System::Drawing::Font(
					fontName,
					currentStory.getFontSize(),
					(System::Drawing::FontStyle)currentStory.getFontStyle()
				);
             
				Color storyColorTemp = ColorTranslator::FromHtml(gcnew System::String(currentStory.getColorHex().c_str()));
				//? load the font and the color
				//StoryStyleHelper::LoadFontAndColor(currentStory.getFontName(), currentStory.getFontSize(), currentStory.getFontStyle(), currentStory.getColorHex(), font, storyColor);
				//? set the font and the color to the label
				bodyOfTheStoryPanel->BackColor = storyColorTemp;
				bodyOfTheStoryLabel->Font = fontStoryTemp;
		
				storiesIDTemp.erase(begin);
			}
			else {
				storyTimerTemp->Enabled=false;
				storyPanel->BringToFront();
				mainPanel->BringToFront();

			}
		}
		string formatTimeToHHMM(time_t t_time) {
			std::tm* timeInfo = std::localtime(&t_time); // تحويل time_t إلى tm
			std::ostringstream oss;
			oss << std::put_time(timeInfo, "%H-%M"); // تحويل إلى hh-mm
			return oss.str();
		}

			  
private: System::Void MyForm() {
	this->InitializeComponent();
}
private: System::Void InitializeComponent() {
	this->components = (gcnew System::ComponentModel::Container());
	System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(GuiForm::typeid));
	this->signUpPnl = (gcnew System::Windows::Forms::Panel());
	this->button12 = (gcnew System::Windows::Forms::Button());
	this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
	this->button10 = (gcnew System::Windows::Forms::Button());
	this->button9 = (gcnew System::Windows::Forms::Button());
	this->label15 = (gcnew System::Windows::Forms::Label());
	this->pasTxt = (gcnew System::Windows::Forms::TextBox());
	this->numTxt = (gcnew System::Windows::Forms::TextBox());
	this->lnTxt = (gcnew System::Windows::Forms::TextBox());
	this->fnTxt = (gcnew System::Windows::Forms::TextBox());
	this->label14 = (gcnew System::Windows::Forms::Label());
	this->label13 = (gcnew System::Windows::Forms::Label());
	this->label12 = (gcnew System::Windows::Forms::Label());
	this->label11 = (gcnew System::Windows::Forms::Label());
	this->signUpBackGround = (gcnew System::Windows::Forms::PictureBox());
	this->passTxt = (gcnew System::Windows::Forms::TextBox());
	this->mainPanel = (gcnew System::Windows::Forms::Panel());
	this->storyPanel = (gcnew System::Windows::Forms::Panel());
	this->allStoriesPanel = (gcnew System::Windows::Forms::FlowLayoutPanel());
	this->stotyHeaderPanel = (gcnew System::Windows::Forms::Panel());
	this->label2 = (gcnew System::Windows::Forms::Label());
	this->button2 = (gcnew System::Windows::Forms::Button());
	this->chatPnl = (gcnew System::Windows::Forms::Panel());
	this->currentCahtPanel = (gcnew System::Windows::Forms::Panel());
	this->chatsContainer = (gcnew System::Windows::Forms::Panel());
	this->messagesFlowPanelsContainer = (gcnew System::Windows::Forms::Panel());
	this->headerContainer = (gcnew System::Windows::Forms::Panel());
	this->chatName = (gcnew System::Windows::Forms::Label());
	this->chatPicture = (gcnew System::Windows::Forms::PictureBox());
	this->footerContainer = (gcnew System::Windows::Forms::Panel());
	this->textBox1 = (gcnew System::Windows::Forms::RichTextBox());
	this->sendButton = (gcnew System::Windows::Forms::Button());
	this->contactsPanel = (gcnew System::Windows::Forms::FlowLayoutPanel());
	this->profilePanel = (gcnew System::Windows::Forms::Panel());
	this->singOutButton = (gcnew System::Windows::Forms::Button());
	this->label1 = (gcnew System::Windows::Forms::Label());
	this->addGroup = (gcnew System::Windows::Forms::Panel());
	this->groupImgBut = (gcnew System::Windows::Forms::Button());
	this->groupImgPicBox = (gcnew System::Windows::Forms::PictureBox());
	this->label6 = (gcnew System::Windows::Forms::Label());
	this->usersListBox = (gcnew System::Windows::Forms::CheckedListBox());
	this->label8 = (gcnew System::Windows::Forms::Label());
	this->groupNameTxt = (gcnew System::Windows::Forms::TextBox());
	this->label7 = (gcnew System::Windows::Forms::Label());
	this->addBtn = (gcnew System::Windows::Forms::Button());
	this->addContactPanel = (gcnew System::Windows::Forms::Panel());
	this->addContact_btn = (gcnew System::Windows::Forms::Button());
	this->checkContact_btn = (gcnew System::Windows::Forms::Button());
	this->addContName_field = (gcnew System::Windows::Forms::TextBox());
	this->addContNum_field = (gcnew System::Windows::Forms::TextBox());
	this->label5 = (gcnew System::Windows::Forms::Label());
	this->NameLabel = (gcnew System::Windows::Forms::Label());
	this->label3 = (gcnew System::Windows::Forms::Label());
	this->navPanel = (gcnew System::Windows::Forms::Panel());
	this->button7 = (gcnew System::Windows::Forms::Button());
	this->chatButton = (gcnew System::Windows::Forms::Button());
	this->goToAddContact_btn = (gcnew System::Windows::Forms::Button());
	this->statusButton = (gcnew System::Windows::Forms::Button());
	this->profileButton = (gcnew System::Windows::Forms::Button());
	this->addStoryPanel = (gcnew System::Windows::Forms::Panel());
	this->button6 = (gcnew System::Windows::Forms::Button());
	this->button5 = (gcnew System::Windows::Forms::Button());
	this->button4 = (gcnew System::Windows::Forms::Button());
	this->textStory = (gcnew System::Windows::Forms::TextBox());
	this->button3 = (gcnew System::Windows::Forms::Button());
	this->colorDialog1 = (gcnew System::Windows::Forms::ColorDialog());
	this->getStoryPanel = (gcnew System::Windows::Forms::Panel());
	this->footerOfTheSroryPanel = (gcnew System::Windows::Forms::Panel());
	this->viewerOfTheStoryBtn = (gcnew System::Windows::Forms::Button());
	this->bodyOfTheStoryPanel = (gcnew System::Windows::Forms::Panel());
	this->bodyOfTheStoryLabel = (gcnew System::Windows::Forms::Label());
	this->profileUserInStoryPanel = (gcnew System::Windows::Forms::Panel());
	this->cancelStoryBtn = (gcnew System::Windows::Forms::Button());
	this->dateInStoryLabel = (gcnew System::Windows::Forms::Label());
	this->nameInStoryLabel = (gcnew System::Windows::Forms::Label());
	this->profileStoryPic = (gcnew System::Windows::Forms::PictureBox());
	this->SignINPnl = (gcnew System::Windows::Forms::Panel());
	this->button8 = (gcnew System::Windows::Forms::Button());
	this->label10 = (gcnew System::Windows::Forms::Label());
	this->label9 = (gcnew System::Windows::Forms::Label());
	this->passLbl = (gcnew System::Windows::Forms::Label());
	this->numLbl = (gcnew System::Windows::Forms::Label());
	this->phoneTxt = (gcnew System::Windows::Forms::TextBox());
	this->label4 = (gcnew System::Windows::Forms::Label());
	this->signinBackGround = (gcnew System::Windows::Forms::PictureBox());
	this->storyTimerTemp = (gcnew System::Windows::Forms::Timer(this->components));
	this->signUpPnl->SuspendLayout();
	(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
	(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->signUpBackGround))->BeginInit();
	this->mainPanel->SuspendLayout();
	this->storyPanel->SuspendLayout();
	this->stotyHeaderPanel->SuspendLayout();
	this->chatPnl->SuspendLayout();
	this->currentCahtPanel->SuspendLayout();
	this->chatsContainer->SuspendLayout();
	this->headerContainer->SuspendLayout();
	(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chatPicture))->BeginInit();
	this->footerContainer->SuspendLayout();
	this->profilePanel->SuspendLayout();
	this->addGroup->SuspendLayout();
	(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->groupImgPicBox))->BeginInit();
	this->addContactPanel->SuspendLayout();
	this->navPanel->SuspendLayout();
	this->addStoryPanel->SuspendLayout();
	this->getStoryPanel->SuspendLayout();
	this->footerOfTheSroryPanel->SuspendLayout();
	this->bodyOfTheStoryPanel->SuspendLayout();
	this->profileUserInStoryPanel->SuspendLayout();
	(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->profileStoryPic))->BeginInit();
	this->SignINPnl->SuspendLayout();
	(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->signinBackGround))->BeginInit();
	this->SuspendLayout();
	// 
	// signUpPnl
	// 
	this->signUpPnl->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
	this->signUpPnl->Controls->Add(this->button12);
	this->signUpPnl->Controls->Add(this->pictureBox2);
	this->signUpPnl->Controls->Add(this->button10);
	this->signUpPnl->Controls->Add(this->button9);
	this->signUpPnl->Controls->Add(this->label15);
	this->signUpPnl->Controls->Add(this->pasTxt);
	this->signUpPnl->Controls->Add(this->numTxt);
	this->signUpPnl->Controls->Add(this->lnTxt);
	this->signUpPnl->Controls->Add(this->fnTxt);
	this->signUpPnl->Controls->Add(this->label14);
	this->signUpPnl->Controls->Add(this->label13);
	this->signUpPnl->Controls->Add(this->label12);
	this->signUpPnl->Controls->Add(this->label11);
	this->signUpPnl->Controls->Add(this->signUpBackGround);
	this->signUpPnl->Dock = System::Windows::Forms::DockStyle::Fill;
	this->signUpPnl->Location = System::Drawing::Point(0, 0);
	this->signUpPnl->Margin = System::Windows::Forms::Padding(4);
	this->signUpPnl->Name = L"signUpPnl";
	this->signUpPnl->Size = System::Drawing::Size(1904, 1041);
	this->signUpPnl->TabIndex = 10;
	// 
	// button12
	// 
	this->button12->BackColor = System::Drawing::Color::Cyan;
	this->button12->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
	this->button12->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
		static_cast<System::Byte>(0)));
	this->button12->Location = System::Drawing::Point(1396, 516);
	this->button12->Name = L"button12";
	this->button12->Size = System::Drawing::Size(100, 35);
	this->button12->TabIndex = 24;
	this->button12->Text = L"Select image";
	this->button12->UseVisualStyleBackColor = false;
	this->button12->Click += gcnew System::EventHandler(this, &GuiForm::button12_Click);
	// 
	// pictureBox2
	// 
	this->pictureBox2->BackColor = System::Drawing::Color::Transparent;
	this->pictureBox2->Location = System::Drawing::Point(1375, 364);
	this->pictureBox2->Name = L"pictureBox2";
	this->pictureBox2->Size = System::Drawing::Size(142, 133);
	this->pictureBox2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
	this->pictureBox2->TabIndex = 23;
	this->pictureBox2->TabStop = false;
	// 
	// button10
	// 
	this->button10->BackColor = System::Drawing::Color::Cyan;
	this->button10->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
	this->button10->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
		static_cast<System::Byte>(0)));
	this->button10->Location = System::Drawing::Point(425, 801);
	this->button10->Name = L"button10";
	this->button10->Size = System::Drawing::Size(206, 80);
	this->button10->TabIndex = 11;
	this->button10->Text = L"Sign In ";
	this->button10->UseVisualStyleBackColor = false;
	this->button10->Click += gcnew System::EventHandler(this, &GuiForm::button10_Click);
	// 
	// button9
	// 
	this->button9->BackColor = System::Drawing::Color::Cyan;
	this->button9->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
	this->button9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
		static_cast<System::Byte>(0)));
	this->button9->Location = System::Drawing::Point(1375, 801);
	this->button9->Name = L"button9";
	this->button9->Size = System::Drawing::Size(206, 80);
	this->button9->TabIndex = 10;
	this->button9->Text = L"Sign Up →";
	this->button9->UseVisualStyleBackColor = false;
	this->button9->Click += gcnew System::EventHandler(this, &GuiForm::button9_Click);
	// 
	// label15
	// 
	this->label15->AutoSize = true;
	this->label15->BackColor = System::Drawing::Color::Transparent;
	this->label15->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 36, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
		static_cast<System::Byte>(0)));
	this->label15->Location = System::Drawing::Point(750, 199);
	this->label15->Name = L"label15";
	this->label15->Size = System::Drawing::Size(418, 55);
	this->label15->TabIndex = 8;
	this->label15->Text = L"Sign Up with Chati";
	// 
	// pasTxt
	// 
	this->pasTxt->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
		static_cast<System::Byte>(0)));
	this->pasTxt->Location = System::Drawing::Point(951, 499);
	this->pasTxt->Name = L"pasTxt";
	this->pasTxt->PasswordChar = '*';
	this->pasTxt->Size = System::Drawing::Size(162, 31);
	this->pasTxt->TabIndex = 7;
	// 
	// numTxt
	// 
	this->numTxt->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
		static_cast<System::Byte>(0)));
	this->numTxt->Location = System::Drawing::Point(951, 456);
	this->numTxt->Name = L"numTxt";
	this->numTxt->Size = System::Drawing::Size(162, 31);
	this->numTxt->TabIndex = 6;
	// 
	// lnTxt
	// 
	this->lnTxt->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
		static_cast<System::Byte>(0)));
	this->lnTxt->Location = System::Drawing::Point(951, 414);
	this->lnTxt->Name = L"lnTxt";
	this->lnTxt->Size = System::Drawing::Size(162, 31);
	this->lnTxt->TabIndex = 5;
	// 
	// fnTxt
	// 
	this->fnTxt->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
		static_cast<System::Byte>(0)));
	this->fnTxt->Location = System::Drawing::Point(951, 372);
	this->fnTxt->Name = L"fnTxt";
	this->fnTxt->Size = System::Drawing::Size(162, 31);
	this->fnTxt->TabIndex = 4;
	// 
	// label14
	// 
	this->label14->AutoSize = true;
	this->label14->BackColor = System::Drawing::Color::Transparent;
	this->label14->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
		static_cast<System::Byte>(0)));
	this->label14->Location = System::Drawing::Point(717, 420);
	this->label14->Name = L"label14";
	this->label14->Size = System::Drawing::Size(121, 25);
	this->label14->TabIndex = 3;
	this->label14->Text = L"Last Name:";
	// 
	// label13
	// 
	this->label13->AutoSize = true;
	this->label13->BackColor = System::Drawing::Color::Transparent;
	this->label13->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
		static_cast<System::Byte>(0)));
	this->label13->Location = System::Drawing::Point(717, 462);
	this->label13->Name = L"label13";
	this->label13->Size = System::Drawing::Size(161, 25);
	this->label13->TabIndex = 2;
	this->label13->Text = L"Phone Number:";
	// 
	// label12
	// 
	this->label12->AutoSize = true;
	this->label12->BackColor = System::Drawing::Color::Transparent;
	this->label12->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
		static_cast<System::Byte>(0)));
	this->label12->Location = System::Drawing::Point(717, 502);
	this->label12->Name = L"label12";
	this->label12->Size = System::Drawing::Size(112, 25);
	this->label12->TabIndex = 1;
	this->label12->Text = L"Password:";
	// 
	// label11
	// 
	this->label11->AutoSize = true;
	this->label11->BackColor = System::Drawing::Color::Transparent;
	this->label11->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
		static_cast<System::Byte>(0)));
	this->label11->Location = System::Drawing::Point(717, 375);
	this->label11->Name = L"label11";
	this->label11->Size = System::Drawing::Size(122, 25);
	this->label11->TabIndex = 0;
	this->label11->Text = L"First Name:";
	// 
	// signUpBackGround
	// 
	this->signUpBackGround->InitialImage = nullptr;
	this->signUpBackGround->Location = System::Drawing::Point(0, 0);
	this->signUpBackGround->Name = L"signUpBackGround";
	this->signUpBackGround->Size = System::Drawing::Size(1944, 1041);
	this->signUpBackGround->TabIndex = 25;
	this->signUpBackGround->TabStop = false;
	// 
	// passTxt
	// 
	this->passTxt->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
		static_cast<System::Byte>(0)));
	this->passTxt->Location = System::Drawing::Point(937, 527);
	this->passTxt->Margin = System::Windows::Forms::Padding(4);
	this->passTxt->Name = L"passTxt";
	this->passTxt->PasswordChar = '*';
	this->passTxt->Size = System::Drawing::Size(156, 31);
	this->passTxt->TabIndex = 3;
	// 
	// mainPanel
	// 
	this->mainPanel->BackColor = System::Drawing::Color::White;
	this->mainPanel->Controls->Add(this->storyPanel);
	this->mainPanel->Controls->Add(this->chatPnl);
	this->mainPanel->Controls->Add(this->profilePanel);
	this->mainPanel->Controls->Add(this->addGroup);
	this->mainPanel->Controls->Add(this->addContactPanel);
	this->mainPanel->Controls->Add(this->navPanel);
	this->mainPanel->Dock = System::Windows::Forms::DockStyle::Fill;
	this->mainPanel->Location = System::Drawing::Point(0, 0);
	this->mainPanel->Name = L"mainPanel";
	this->mainPanel->Size = System::Drawing::Size(1904, 1041);
	this->mainPanel->TabIndex = 3;
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
	// chatPnl
	// 
	this->chatPnl->Controls->Add(this->currentCahtPanel);
	this->chatPnl->Controls->Add(this->contactsPanel);
	this->chatPnl->Dock = System::Windows::Forms::DockStyle::Fill;
	this->chatPnl->Location = System::Drawing::Point(87, 0);
	this->chatPnl->Name = L"chatPnl";
	this->chatPnl->Size = System::Drawing::Size(1817, 1041);
	this->chatPnl->TabIndex = 8;
	// 
	// currentCahtPanel
	// 
	this->currentCahtPanel->BackColor = System::Drawing::Color::RosyBrown;
	this->currentCahtPanel->Controls->Add(this->chatsContainer);
	this->currentCahtPanel->Controls->Add(this->footerContainer);
	this->currentCahtPanel->Dock = System::Windows::Forms::DockStyle::Fill;
	this->currentCahtPanel->Location = System::Drawing::Point(338, 0);
	this->currentCahtPanel->Name = L"currentCahtPanel";
	this->currentCahtPanel->Size = System::Drawing::Size(1479, 1041);
	this->currentCahtPanel->TabIndex = 7;
	// 
	// chatsContainer
	// 
	this->chatsContainer->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(60)), static_cast<System::Int32>(static_cast<System::Byte>(60)),
		static_cast<System::Int32>(static_cast<System::Byte>(60)));
	this->chatsContainer->Controls->Add(this->messagesFlowPanelsContainer);
	this->chatsContainer->Controls->Add(this->headerContainer);
	this->chatsContainer->Dock = System::Windows::Forms::DockStyle::Fill;
	this->chatsContainer->Location = System::Drawing::Point(0, 0);
	this->chatsContainer->Name = L"chatsContainer";
	this->chatsContainer->Size = System::Drawing::Size(1479, 995);
	this->chatsContainer->TabIndex = 14;
	// 
	// messagesFlowPanelsContainer
	// 
	this->messagesFlowPanelsContainer->Dock = System::Windows::Forms::DockStyle::Fill;
	this->messagesFlowPanelsContainer->Location = System::Drawing::Point(0, 100);
	this->messagesFlowPanelsContainer->Name = L"messagesFlowPanelsContainer";
	this->messagesFlowPanelsContainer->Size = System::Drawing::Size(1479, 895);
	this->messagesFlowPanelsContainer->TabIndex = 1;
	// 
	// headerContainer
	// 
	this->headerContainer->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(70)), static_cast<System::Int32>(static_cast<System::Byte>(70)),
		static_cast<System::Int32>(static_cast<System::Byte>(70)));
	this->headerContainer->Controls->Add(this->chatName);
	this->headerContainer->Controls->Add(this->chatPicture);
	this->headerContainer->Dock = System::Windows::Forms::DockStyle::Top;
	this->headerContainer->Location = System::Drawing::Point(0, 0);
	this->headerContainer->Name = L"headerContainer";
	this->headerContainer->Size = System::Drawing::Size(1479, 100);
	this->headerContainer->TabIndex = 0;
	// 
	// chatName
	// 
	this->chatName->AutoSize = true;
	this->chatName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
		static_cast<System::Byte>(0)));
	this->chatName->ForeColor = System::Drawing::SystemColors::ButtonFace;
	this->chatName->Location = System::Drawing::Point(167, 32);
	this->chatName->Name = L"chatName";
	this->chatName->Size = System::Drawing::Size(0, 29);
	this->chatName->TabIndex = 1;
	// 
	// chatPicture
	// 
	this->chatPicture->Location = System::Drawing::Point(6, 3);
	this->chatPicture->Name = L"chatPicture";
	this->chatPicture->Size = System::Drawing::Size(118, 96);
	this->chatPicture->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
	this->chatPicture->TabIndex = 0;
	this->chatPicture->TabStop = false;
	// 
	// footerContainer
	// 
	this->footerContainer->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(50)), static_cast<System::Int32>(static_cast<System::Byte>(50)),
		static_cast<System::Int32>(static_cast<System::Byte>(50)));
	this->footerContainer->Controls->Add(this->textBox1);
	this->footerContainer->Controls->Add(this->sendButton);
	this->footerContainer->Dock = System::Windows::Forms::DockStyle::Bottom;
	this->footerContainer->Location = System::Drawing::Point(0, 995);
	this->footerContainer->Name = L"footerContainer";
	this->footerContainer->Size = System::Drawing::Size(1479, 46);
	this->footerContainer->TabIndex = 13;
	this->footerContainer->Visible = false;
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
	// contactsPanel
	// 
	this->contactsPanel->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(45)), static_cast<System::Int32>(static_cast<System::Byte>(45)),
		static_cast<System::Int32>(static_cast<System::Byte>(45)));
	this->contactsPanel->Dock = System::Windows::Forms::DockStyle::Left;
	this->contactsPanel->Location = System::Drawing::Point(0, 0);
	this->contactsPanel->Name = L"contactsPanel";
	this->contactsPanel->Size = System::Drawing::Size(338, 1041);
	this->contactsPanel->TabIndex = 2;
	// 
	// profilePanel
	// 
	this->profilePanel->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(45)), static_cast<System::Int32>(static_cast<System::Byte>(45)),
		static_cast<System::Int32>(static_cast<System::Byte>(45)));
	this->profilePanel->Controls->Add(this->singOutButton);
	this->profilePanel->Controls->Add(this->label1);
	this->profilePanel->Dock = System::Windows::Forms::DockStyle::Fill;
	this->profilePanel->Location = System::Drawing::Point(87, 0);
	this->profilePanel->Name = L"profilePanel";
	this->profilePanel->Size = System::Drawing::Size(1817, 1041);
	this->profilePanel->TabIndex = 10;
	// 
	// singOutButton
	// 
	this->singOutButton->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
		static_cast<System::Int32>(static_cast<System::Byte>(255)));
	this->singOutButton->Location = System::Drawing::Point(840, 410);
	this->singOutButton->Name = L"singOutButton";
	this->singOutButton->Size = System::Drawing::Size(212, 51);
	this->singOutButton->TabIndex = 1;
	this->singOutButton->Text = L"Sign out";
	this->singOutButton->UseVisualStyleBackColor = false;
	this->singOutButton->Click += gcnew System::EventHandler(this, &GuiForm::singOutButton_Click);
	// 
	// label1
	// 
	this->label1->AutoSize = true;
	this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
		static_cast<System::Byte>(0)));
	this->label1->Location = System::Drawing::Point(859, 290);
	this->label1->Name = L"label1";
	this->label1->Size = System::Drawing::Size(167, 31);
	this->label1->TabIndex = 0;
	this->label1->Text = L"Profile Panel";
	// 
	// addGroup
	// 
	this->addGroup->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(45)), static_cast<System::Int32>(static_cast<System::Byte>(45)),
		static_cast<System::Int32>(static_cast<System::Byte>(45)));
	this->addGroup->Controls->Add(this->groupImgBut);
	this->addGroup->Controls->Add(this->groupImgPicBox);
	this->addGroup->Controls->Add(this->label6);
	this->addGroup->Controls->Add(this->usersListBox);
	this->addGroup->Controls->Add(this->label8);
	this->addGroup->Controls->Add(this->groupNameTxt);
	this->addGroup->Controls->Add(this->label7);
	this->addGroup->Controls->Add(this->addBtn);
	this->addGroup->Dock = System::Windows::Forms::DockStyle::Fill;
	this->addGroup->Location = System::Drawing::Point(87, 0);
	this->addGroup->Name = L"addGroup";
	this->addGroup->Size = System::Drawing::Size(1817, 1041);
	this->addGroup->TabIndex = 16;
	// 
	// groupImgBut
	// 
	this->groupImgBut->BackColor = System::Drawing::Color::Cyan;
	this->groupImgBut->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
	this->groupImgBut->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
		static_cast<System::Byte>(0)));
	this->groupImgBut->Location = System::Drawing::Point(1330, 533);
	this->groupImgBut->Name = L"groupImgBut";
	this->groupImgBut->Size = System::Drawing::Size(100, 35);
	this->groupImgBut->TabIndex = 25;
	this->groupImgBut->Text = L"Select image";
	this->groupImgBut->UseVisualStyleBackColor = false;
	this->groupImgBut->Click += gcnew System::EventHandler(this, &GuiForm::groupImgBut_Click);
	// 
	// groupImgPicBox
	// 
	this->groupImgPicBox->BackColor = System::Drawing::Color::Transparent;
	this->groupImgPicBox->Location = System::Drawing::Point(1309, 378);
	this->groupImgPicBox->Name = L"groupImgPicBox";
	this->groupImgPicBox->Size = System::Drawing::Size(142, 133);
	this->groupImgPicBox->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
	this->groupImgPicBox->TabIndex = 24;
	this->groupImgPicBox->TabStop = false;
	// 
	// label6
	// 
	this->label6->AutoSize = true;
	this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
		static_cast<System::Byte>(0)));
	this->label6->ForeColor = System::Drawing::SystemColors::ActiveCaption;
	this->label6->Location = System::Drawing::Point(735, 635);
	this->label6->Name = L"label6";
	this->label6->Size = System::Drawing::Size(304, 20);
	this->label6->TabIndex = 12;
	this->label6->Text = L"You don\'t have contacts yet\? Add contact";
	this->label6->Click += gcnew System::EventHandler(this, &GuiForm::label6_Click);
	// 
	// usersListBox
	// 
	this->usersListBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
		static_cast<System::Byte>(0)));
	this->usersListBox->FormattingEnabled = true;
	this->usersListBox->Location = System::Drawing::Point(725, 437);
	this->usersListBox->Name = L"usersListBox";
	this->usersListBox->Size = System::Drawing::Size(327, 160);
	this->usersListBox->TabIndex = 11;
	// 
	// label8
	// 
	this->label8->AutoSize = true;
	this->label8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
		static_cast<System::Byte>(0)));
	this->label8->ForeColor = System::Drawing::SystemColors::ControlLightLight;
	this->label8->Location = System::Drawing::Point(720, 378);
	this->label8->Name = L"label8";
	this->label8->Size = System::Drawing::Size(139, 25);
	this->label8->TabIndex = 10;
	this->label8->Text = L"Group Name:";
	// 
	// groupNameTxt
	// 
	this->groupNameTxt->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
		static_cast<System::Byte>(0)));
	this->groupNameTxt->Location = System::Drawing::Point(886, 369);
	this->groupNameTxt->Name = L"groupNameTxt";
	this->groupNameTxt->Size = System::Drawing::Size(166, 38);
	this->groupNameTxt->TabIndex = 9;
	// 
	// label7
	// 
	this->label7->AutoSize = true;
	this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
		static_cast<System::Byte>(0)));
	this->label7->ForeColor = System::Drawing::SystemColors::ControlLightLight;
	this->label7->Location = System::Drawing::Point(828, 321);
	this->label7->Name = L"label7";
	this->label7->Size = System::Drawing::Size(129, 29);
	this->label7->TabIndex = 7;
	this->label7->Text = L"Add Group";
	// 
	// addBtn
	// 
	this->addBtn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
		static_cast<System::Byte>(0)));
	this->addBtn->Location = System::Drawing::Point(811, 682);
	this->addBtn->Name = L"addBtn";
	this->addBtn->Size = System::Drawing::Size(147, 45);
	this->addBtn->TabIndex = 1;
	this->addBtn->Text = L"Create group";
	this->addBtn->UseVisualStyleBackColor = true;
	this->addBtn->Click += gcnew System::EventHandler(this, &GuiForm::addBtn_Click);
	// 
	// addContactPanel
	// 
	this->addContactPanel->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(45)), static_cast<System::Int32>(static_cast<System::Byte>(45)),
		static_cast<System::Int32>(static_cast<System::Byte>(45)));
	this->addContactPanel->Controls->Add(this->addContact_btn);
	this->addContactPanel->Controls->Add(this->checkContact_btn);
	this->addContactPanel->Controls->Add(this->addContName_field);
	this->addContactPanel->Controls->Add(this->addContNum_field);
	this->addContactPanel->Controls->Add(this->label5);
	this->addContactPanel->Controls->Add(this->NameLabel);
	this->addContactPanel->Controls->Add(this->label3);
	this->addContactPanel->Dock = System::Windows::Forms::DockStyle::Fill;
	this->addContactPanel->Location = System::Drawing::Point(87, 0);
	this->addContactPanel->Name = L"addContactPanel";
	this->addContactPanel->Size = System::Drawing::Size(1817, 1041);
	this->addContactPanel->TabIndex = 14;
	// 
	// addContact_btn
	// 
	this->addContact_btn->Location = System::Drawing::Point(865, 573);
	this->addContact_btn->Name = L"addContact_btn";
	this->addContact_btn->Size = System::Drawing::Size(75, 23);
	this->addContact_btn->TabIndex = 22;
	this->addContact_btn->Text = L"Add";
	this->addContact_btn->UseVisualStyleBackColor = true;
	this->addContact_btn->Visible = false;
	this->addContact_btn->Click += gcnew System::EventHandler(this, &GuiForm::addContact_btn_Click);
	// 
	// checkContact_btn
	// 
	this->checkContact_btn->Location = System::Drawing::Point(1028, 485);
	this->checkContact_btn->Name = L"checkContact_btn";
	this->checkContact_btn->Size = System::Drawing::Size(75, 23);
	this->checkContact_btn->TabIndex = 21;
	this->checkContact_btn->Text = L"Check";
	this->checkContact_btn->UseVisualStyleBackColor = true;
	this->checkContact_btn->Click += gcnew System::EventHandler(this, &GuiForm::checkContact_btn_Click);
	// 
	// addContName_field
	// 
	this->addContName_field->Location = System::Drawing::Point(791, 516);
	this->addContName_field->Name = L"addContName_field";
	this->addContName_field->Size = System::Drawing::Size(215, 22);
	this->addContName_field->TabIndex = 18;
	this->addContName_field->Visible = false;
	// 
	// addContNum_field
	// 
	this->addContNum_field->Location = System::Drawing::Point(791, 485);
	this->addContNum_field->Name = L"addContNum_field";
	this->addContNum_field->Size = System::Drawing::Size(215, 22);
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
	// NameLabel
	// 
	this->NameLabel->AutoSize = true;
	this->NameLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
		static_cast<System::Byte>(0)));
	this->NameLabel->Location = System::Drawing::Point(713, 516);
	this->NameLabel->Name = L"NameLabel";
	this->NameLabel->Size = System::Drawing::Size(54, 17);
	this->NameLabel->TabIndex = 15;
	this->NameLabel->Text = L"Name:";
	this->NameLabel->Visible = false;
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
	// navPanel
	// 
	this->navPanel->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(65)), static_cast<System::Int32>(static_cast<System::Byte>(65)),
		static_cast<System::Int32>(static_cast<System::Byte>(65)));
	this->navPanel->Controls->Add(this->button7);
	this->navPanel->Controls->Add(this->chatButton);
	this->navPanel->Controls->Add(this->goToAddContact_btn);
	this->navPanel->Controls->Add(this->statusButton);
	this->navPanel->Controls->Add(this->profileButton);
	this->navPanel->Dock = System::Windows::Forms::DockStyle::Left;
	this->navPanel->Location = System::Drawing::Point(0, 0);
	this->navPanel->Name = L"navPanel";
	this->navPanel->Size = System::Drawing::Size(87, 1041);
	this->navPanel->TabIndex = 5;
	// 
	// button7
	// 
	this->button7->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
	this->button7->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
	this->button7->Cursor = System::Windows::Forms::Cursors::Hand;
	this->button7->FlatAppearance->BorderSize = 0;
	this->button7->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
	this->button7->Location = System::Drawing::Point(12, 714);
	this->button7->Name = L"button7";
	this->button7->Size = System::Drawing::Size(63, 60);
	this->button7->TabIndex = 5;
	this->button7->UseVisualStyleBackColor = true;
	this->button7->Click += gcnew System::EventHandler(this, &GuiForm::button7_Click);
	// 
	// chatButton
	// 
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
	// goToAddContact_btn
	// 
	this->goToAddContact_btn->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
	this->goToAddContact_btn->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
	this->goToAddContact_btn->Cursor = System::Windows::Forms::Cursors::Hand;
	this->goToAddContact_btn->FlatAppearance->BorderSize = 0;
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
	this->textStory->Size = System::Drawing::Size(1901, 864);
	this->textStory->TabIndex = 1;
	// 
	// button3
	// 
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
	// getStoryPanel
	// 
	this->getStoryPanel->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(45)), static_cast<System::Int32>(static_cast<System::Byte>(45)),
		static_cast<System::Int32>(static_cast<System::Byte>(45)));
	this->getStoryPanel->Controls->Add(this->footerOfTheSroryPanel);
	this->getStoryPanel->Controls->Add(this->bodyOfTheStoryPanel);
	this->getStoryPanel->Controls->Add(this->profileUserInStoryPanel);
	this->getStoryPanel->Dock = System::Windows::Forms::DockStyle::Fill;
	this->getStoryPanel->Location = System::Drawing::Point(0, 0);
	this->getStoryPanel->Name = L"getStoryPanel";
	this->getStoryPanel->Size = System::Drawing::Size(1904, 1041);
	this->getStoryPanel->TabIndex = 14;
	// 
	// footerOfTheSroryPanel
	// 
	this->footerOfTheSroryPanel->Controls->Add(this->viewerOfTheStoryBtn);
	this->footerOfTheSroryPanel->Dock = System::Windows::Forms::DockStyle::Bottom;
	this->footerOfTheSroryPanel->Location = System::Drawing::Point(0, 951);
	this->footerOfTheSroryPanel->Name = L"footerOfTheSroryPanel";
	this->footerOfTheSroryPanel->Size = System::Drawing::Size(1904, 90);
	this->footerOfTheSroryPanel->TabIndex = 2;
	// 
	// viewerOfTheStoryBtn
	// 
	this->viewerOfTheStoryBtn->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
		| System::Windows::Forms::AnchorStyles::Left)
		| System::Windows::Forms::AnchorStyles::Right));
	this->viewerOfTheStoryBtn->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"viewerOfTheStoryBtn.BackgroundImage")));
	this->viewerOfTheStoryBtn->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
	this->viewerOfTheStoryBtn->FlatAppearance->BorderSize = 0;
	this->viewerOfTheStoryBtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
	this->viewerOfTheStoryBtn->ForeColor = System::Drawing::Color::DarkCyan;
	this->viewerOfTheStoryBtn->Location = System::Drawing::Point(921, 28);
	this->viewerOfTheStoryBtn->Name = L"viewerOfTheStoryBtn";
	this->viewerOfTheStoryBtn->Size = System::Drawing::Size(93, 42);
	this->viewerOfTheStoryBtn->TabIndex = 0;
	this->viewerOfTheStoryBtn->UseVisualStyleBackColor = true;
	this->viewerOfTheStoryBtn->Click += gcnew System::EventHandler(this, &GuiForm::viewerOfTheStoryBtn_Click);
	// 
	// bodyOfTheStoryPanel
	// 
	this->bodyOfTheStoryPanel->Controls->Add(this->bodyOfTheStoryLabel);
	this->bodyOfTheStoryPanel->Dock = System::Windows::Forms::DockStyle::Fill;
	this->bodyOfTheStoryPanel->Location = System::Drawing::Point(0, 128);
	this->bodyOfTheStoryPanel->Name = L"bodyOfTheStoryPanel";
	this->bodyOfTheStoryPanel->Size = System::Drawing::Size(1904, 913);
	this->bodyOfTheStoryPanel->TabIndex = 1;
	// 
	// bodyOfTheStoryLabel
	// 
	this->bodyOfTheStoryLabel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
		| System::Windows::Forms::AnchorStyles::Left)
		| System::Windows::Forms::AnchorStyles::Right));
	this->bodyOfTheStoryLabel->AutoSize = true;
	this->bodyOfTheStoryLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 19.8F, System::Drawing::FontStyle::Bold,
		System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
	this->bodyOfTheStoryLabel->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
	this->bodyOfTheStoryLabel->Location = System::Drawing::Point(842, 292);
	this->bodyOfTheStoryLabel->Name = L"bodyOfTheStoryLabel";
	this->bodyOfTheStoryLabel->Size = System::Drawing::Size(0, 31);
	this->bodyOfTheStoryLabel->TabIndex = 1;
	// 
	// profileUserInStoryPanel
	// 
	this->profileUserInStoryPanel->Controls->Add(this->cancelStoryBtn);
	this->profileUserInStoryPanel->Controls->Add(this->dateInStoryLabel);
	this->profileUserInStoryPanel->Controls->Add(this->nameInStoryLabel);
	this->profileUserInStoryPanel->Controls->Add(this->profileStoryPic);
	this->profileUserInStoryPanel->Dock = System::Windows::Forms::DockStyle::Top;
	this->profileUserInStoryPanel->Location = System::Drawing::Point(0, 0);
	this->profileUserInStoryPanel->Name = L"profileUserInStoryPanel";
	this->profileUserInStoryPanel->Size = System::Drawing::Size(1904, 128);
	this->profileUserInStoryPanel->TabIndex = 0;
	// 
	// cancelStoryBtn
	// 
	this->cancelStoryBtn->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
	this->cancelStoryBtn->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
	this->cancelStoryBtn->FlatAppearance->BorderSize = 0;
	this->cancelStoryBtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
	this->cancelStoryBtn->ForeColor = System::Drawing::Color::DarkCyan;
	this->cancelStoryBtn->Location = System::Drawing::Point(1799, 13);
	this->cancelStoryBtn->Name = L"cancelStoryBtn";
	this->cancelStoryBtn->Size = System::Drawing::Size(93, 52);
	this->cancelStoryBtn->TabIndex = 1;
	this->cancelStoryBtn->UseVisualStyleBackColor = true;
	this->cancelStoryBtn->Click += gcnew System::EventHandler(this, &GuiForm::cancelStoryBtn_Click);
	// 
	// dateInStoryLabel
	// 
	this->dateInStoryLabel->AutoSize = true;
	this->dateInStoryLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Tai Le", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
		static_cast<System::Byte>(0)));
	this->dateInStoryLabel->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
	this->dateInStoryLabel->Location = System::Drawing::Point(163, 81);
	this->dateInStoryLabel->Name = L"dateInStoryLabel";
	this->dateInStoryLabel->Size = System::Drawing::Size(42, 21);
	this->dateInStoryLabel->TabIndex = 2;
	this->dateInStoryLabel->Text = L"Date";
	// 
	// nameInStoryLabel
	// 
	this->nameInStoryLabel->AutoSize = true;
	this->nameInStoryLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 19.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
		static_cast<System::Byte>(0)));
	this->nameInStoryLabel->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
	this->nameInStoryLabel->Location = System::Drawing::Point(140, 9);
	this->nameInStoryLabel->Name = L"nameInStoryLabel";
	this->nameInStoryLabel->Size = System::Drawing::Size(85, 31);
	this->nameInStoryLabel->TabIndex = 1;
	this->nameInStoryLabel->Text = L"name";
	// 
	// profileStoryPic
	// 
	this->profileStoryPic->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
	this->profileStoryPic->Dock = System::Windows::Forms::DockStyle::Left;
	this->profileStoryPic->Location = System::Drawing::Point(0, 0);
	this->profileStoryPic->Name = L"profileStoryPic";
	this->profileStoryPic->Size = System::Drawing::Size(99, 128);
	this->profileStoryPic->TabIndex = 0;
	this->profileStoryPic->TabStop = false;
	// 
	// SignINPnl
	// 
	this->SignINPnl->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
	this->SignINPnl->Controls->Add(this->button8);
	this->SignINPnl->Controls->Add(this->label10);
	this->SignINPnl->Controls->Add(this->label9);
	this->SignINPnl->Controls->Add(this->passLbl);
	this->SignINPnl->Controls->Add(this->numLbl);
	this->SignINPnl->Controls->Add(this->passTxt);
	this->SignINPnl->Controls->Add(this->phoneTxt);
	this->SignINPnl->Controls->Add(this->label4);
	this->SignINPnl->Controls->Add(this->signinBackGround);
	this->SignINPnl->Dock = System::Windows::Forms::DockStyle::Fill;
	this->SignINPnl->Location = System::Drawing::Point(0, 0);
	this->SignINPnl->Margin = System::Windows::Forms::Padding(4);
	this->SignINPnl->Name = L"SignINPnl";
	this->SignINPnl->Size = System::Drawing::Size(1904, 1041);
	this->SignINPnl->TabIndex = 15;
	// 
	// button8
	// 
	this->button8->BackColor = System::Drawing::Color::Cyan;
	this->button8->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
	this->button8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
		static_cast<System::Byte>(0)));
	this->button8->Location = System::Drawing::Point(1488, 830);
	this->button8->Name = L"button8";
	this->button8->Size = System::Drawing::Size(206, 80);
	this->button8->TabIndex = 9;
	this->button8->Text = L"Sign In →";
	this->button8->UseVisualStyleBackColor = false;
	this->button8->Click += gcnew System::EventHandler(this, &GuiForm::button8_Click);
	// 
	// label10
	// 
	this->label10->AutoSize = true;
	this->label10->BackColor = System::Drawing::Color::Transparent;
	this->label10->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Underline, System::Drawing::GraphicsUnit::Point,
		static_cast<System::Byte>(0)));
	this->label10->ForeColor = System::Drawing::Color::Turquoise;
	this->label10->Location = System::Drawing::Point(984, 587);
	this->label10->Name = L"label10";
	this->label10->Size = System::Drawing::Size(60, 18);
	this->label10->TabIndex = 8;
	this->label10->Text = L"Sign Up";
	this->label10->Click += gcnew System::EventHandler(this, &GuiForm::label10_Click);
	// 
	// label9
	// 
	this->label9->AutoSize = true;
	this->label9->BackColor = System::Drawing::Color::Transparent;
	this->label9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
		static_cast<System::Byte>(0)));
	this->label9->ForeColor = System::Drawing::Color::Turquoise;
	this->label9->Location = System::Drawing::Point(800, 587);
	this->label9->Name = L"label9";
	this->label9->Size = System::Drawing::Size(186, 18);
	this->label9->TabIndex = 7;
	this->label9->Text = L"Don\'t have an account yet\?";
	// 
	// passLbl
	// 
	this->passLbl->AutoSize = true;
	this->passLbl->BackColor = System::Drawing::Color::Transparent;
	this->passLbl->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
		static_cast<System::Byte>(0)));
	this->passLbl->Location = System::Drawing::Point(750, 533);
	this->passLbl->Name = L"passLbl";
	this->passLbl->Size = System::Drawing::Size(112, 25);
	this->passLbl->TabIndex = 6;
	this->passLbl->Tag = L"";
	this->passLbl->Text = L"Password:";
	// 
	// numLbl
	// 
	this->numLbl->AutoSize = true;
	this->numLbl->BackColor = System::Drawing::Color::Transparent;
	this->numLbl->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
		static_cast<System::Byte>(0)));
	this->numLbl->Location = System::Drawing::Point(717, 462);
	this->numLbl->Name = L"numLbl";
	this->numLbl->Size = System::Drawing::Size(161, 25);
	this->numLbl->TabIndex = 4;
	this->numLbl->Text = L"Phone Number:";
	// 
	// phoneTxt
	// 
	this->phoneTxt->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
		static_cast<System::Byte>(0)));
	this->phoneTxt->Location = System::Drawing::Point(937, 459);
	this->phoneTxt->Name = L"phoneTxt";
	this->phoneTxt->Size = System::Drawing::Size(156, 31);
	this->phoneTxt->TabIndex = 2;
	// 
	// label4
	// 
	this->label4->AutoSize = true;
	this->label4->BackColor = System::Drawing::Color::Transparent;
	this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 36, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
		static_cast<System::Byte>(0)));
	this->label4->Location = System::Drawing::Point(737, 231);
	this->label4->Name = L"label4";
	this->label4->Size = System::Drawing::Size(501, 55);
	this->label4->TabIndex = 1;
	this->label4->Text = L"Welcome to Chati App";
	// 
	// signinBackGround
	// 
	this->signinBackGround->InitialImage = nullptr;
	this->signinBackGround->Location = System::Drawing::Point(105, 9);
	this->signinBackGround->Name = L"signinBackGround";
	this->signinBackGround->Size = System::Drawing::Size(1944, 1041);
	this->signinBackGround->TabIndex = 26;
	this->signinBackGround->TabStop = false;
	// 
	// storyTimerTemp
	// 
	this->storyTimerTemp->Interval = 3000;
	this->storyTimerTemp->Tick += gcnew System::EventHandler(this, &GuiForm::storyTimerTemp_Tick);
	// 
	// GuiForm
	// 
	this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
	this->ClientSize = System::Drawing::Size(1904, 1041);
	this->Controls->Add(this->getStoryPanel);
	this->Controls->Add(this->SignINPnl);
	this->Controls->Add(this->signUpPnl);
	this->Controls->Add(this->addStoryPanel);
	this->Controls->Add(this->mainPanel);
	this->Margin = System::Windows::Forms::Padding(4);
	this->Name = L"GuiForm";
	this->Text = L"chatApp";
	this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &GuiForm::GuiForm_FormClosed);
	this->Load += gcnew System::EventHandler(this, &GuiForm::GuiForm_Load);
	this->signUpPnl->ResumeLayout(false);
	this->signUpPnl->PerformLayout();
	(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
	(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->signUpBackGround))->EndInit();
	this->mainPanel->ResumeLayout(false);
	this->storyPanel->ResumeLayout(false);
	this->stotyHeaderPanel->ResumeLayout(false);
	this->stotyHeaderPanel->PerformLayout();
	this->chatPnl->ResumeLayout(false);
	this->currentCahtPanel->ResumeLayout(false);
	this->chatsContainer->ResumeLayout(false);
	this->headerContainer->ResumeLayout(false);
	this->headerContainer->PerformLayout();
	(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chatPicture))->EndInit();
	this->footerContainer->ResumeLayout(false);
	this->profilePanel->ResumeLayout(false);
	this->profilePanel->PerformLayout();
	this->addGroup->ResumeLayout(false);
	this->addGroup->PerformLayout();
	(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->groupImgPicBox))->EndInit();
	this->addContactPanel->ResumeLayout(false);
	this->addContactPanel->PerformLayout();
	this->navPanel->ResumeLayout(false);
	this->addStoryPanel->ResumeLayout(false);
	this->addStoryPanel->PerformLayout();
	this->getStoryPanel->ResumeLayout(false);
	this->footerOfTheSroryPanel->ResumeLayout(false);
	this->bodyOfTheStoryPanel->ResumeLayout(false);
	this->bodyOfTheStoryPanel->PerformLayout();
	this->profileUserInStoryPanel->ResumeLayout(false);
	this->profileUserInStoryPanel->PerformLayout();
	(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->profileStoryPic))->EndInit();
	this->SignINPnl->ResumeLayout(false);
	this->SignINPnl->PerformLayout();
	(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->signinBackGround))->EndInit();
	this->ResumeLayout(false);

}
	private: System::Void GuiForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}
};

	
};

