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
#include "SearchChatrooms.h"
#include "ProfileSettings.h"
#include "StoryHandler.h"




using namespace std;
using namespace System::IO;
using namespace System::Drawing;
using namespace System;
using namespace System::Globalization;
using namespace System::Windows::Forms;
//? Global maps for save and load from the files
unordered_map<string, User> users;
unordered_map<int, ChatRoom> chatRooms;
unordered_map<int, chati::Message> messages;
unordered_map<int, Contact> contacts;
unordered_map<int, Story> stories;
unordered_map<int, long long> Activity;
User *currentUser, *otherUser;
set<int> storiesIDTemp;
ChatRoom *currentChatRoom;
string currentContNum,currentContName;
int storyIDOfBegin;

//int storiesShown=0;




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
	
		String^ projectRoot = Directory::GetParent(Application::StartupPath)->Parent->FullName;
		String^ imagesFolder = Path::Combine(projectRoot, "usersImages");

		List<Control^>^ buttons = gcnew List<Control^>();

		StoryHandler storyHandler;

		private: System::Windows::Forms::Panel^ addGroup;
		private: System::Windows::Forms::Label^ label6;
		private: System::Windows::Forms::CheckedListBox^ usersListBox;
		private: System::Windows::Forms::Label^ label8;
		private: System::Windows::Forms::TextBox^ groupNameTxt;
		private: System::Windows::Forms::Label^ label7;
		private: System::Windows::Forms::Button^ addBtn;





	private: System::Windows::Forms::Panel^ SignINPnl;


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
	private: System::Windows::Forms::ProgressBar^ storyProgressBar;
	private: System::Windows::Forms::Timer^ storyProgressBarTimer;
	private: System::Windows::Forms::Panel^ addMemberPnl;
	private: System::Windows::Forms::Button^ addMem;


	private: System::Windows::Forms::Button^ button11;
	private: System::Windows::Forms::TextBox^ memName;
	private: System::Windows::Forms::TextBox^ memPhone;


	private: System::Windows::Forms::Label^ memNumLbl;
	private: System::Windows::Forms::Label^ memNameLbl;
	private: System::Windows::Forms::Label^ label18;
	private: System::Windows::Forms::Panel^ contactsPanelContainer;
	private: System::Windows::Forms::FlowLayoutPanel^ contactsPanel;
	private: System::Windows::Forms::FlowLayoutPanel^ searchContactPanel;
	private: System::Windows::Forms::TextBox^ searchChatroom_field;











	private: System::Windows::Forms::Timer^ deleteStoryTimer;
	private: System::Windows::Forms::Panel^ currentCahtPanel;
	private: System::Windows::Forms::Panel^ chatsContainer;
	private: System::Windows::Forms::Panel^ messagesFlowPanelsContainer;
	private: System::Windows::Forms::Panel^ headerContainer;
	private: System::Windows::Forms::PictureBox^ addMemPicBox;
	private: System::Windows::Forms::Label^ chatName;
	private: System::Windows::Forms::PictureBox^ chatPicture;
	private: System::Windows::Forms::Panel^ footerContainer;
	private: System::Windows::Forms::RichTextBox^ textBox1;
	private: System::Windows::Forms::Button^ sendButton;
	private: System::Windows::Forms::PictureBox^ removeMemPicBox;
	private: System::Windows::Forms::Panel^ removeMemberPnl;
	private: System::Windows::Forms::Button^ removeBtn;
	private: System::Windows::Forms::CheckedListBox^ GroupMem;
	private: System::Windows::Forms::Label^ RemoveMem;
	private: System::Windows::Forms::Label^ addMemberLabel;
	private: System::Windows::Forms::Label^ removeMemberLabel;
	private: System::Windows::Forms::Label^ label19;
	private: System::Windows::Forms::Label^ label17;
	private: System::Windows::Forms::Label^ label16;
	private: System::Windows::Forms::Label^ label21;
	private: System::Windows::Forms::Label^ label20;
private: System::Windows::Forms::Button^ editVisibility;
private: System::Windows::Forms::Label^ visibleLabel;
private: System::Windows::Forms::Label^ label1;



private: System::Windows::Forms::Button^ submitVisibleButton;
private: System::Windows::Forms::ComboBox^ visibilityComboBox;
private: System::Windows::Forms::Button^ submitLastNameButton;

private: System::Windows::Forms::TextBox^ newLastNameTextBox;


private: System::Windows::Forms::Button^ editLastNameButton;
private: System::Windows::Forms::Label^ label23;
private: System::Windows::Forms::Button^ submitFirstNameButton;
private: System::Windows::Forms::TextBox^ newFirstNameTextBox;

private: System::Windows::Forms::Button^ editFirstNameButton;
private: System::Windows::Forms::Label^ label22;
private: System::Windows::Forms::Button^ submitPasswordButton;


private: System::Windows::Forms::TextBox^ newPasswordTextBox;

private: System::Windows::Forms::Button^ editPasswordButton;

private: System::Windows::Forms::Label^ label24;

private: System::Windows::Forms::Label^ lastNameLabel;
private: System::Windows::Forms::Label^ firstNameLabel;
private: System::Windows::Forms::Button^ submitNewAboutButton;
private: System::Windows::Forms::Button^ editAboutButton;






private: System::Windows::Forms::Label^ label26;

private: System::Windows::Forms::Label^ aboutLabel;
private: System::Windows::Forms::RichTextBox^ newAboutRichTextBox;
private: System::Windows::Forms::Button^ editPhotoButton;
private: System::Windows::Forms::PictureBox^ userPhotoPictureBox;
private: System::Windows::Forms::Label^ phoneNumberLabel;

private: System::Windows::Forms::Label^ label27;

private: System::Windows::Forms::Panel^ bodyOfTheStoryPanel;

private: System::Windows::Forms::RichTextBox^ bodyOfTheStoryLabel;
private: System::Windows::Forms::Button^ moreButton;


private: System::Windows::Forms::PictureBox^ pictureBox6;

private: System::Windows::Forms::PictureBox^ pictureBox4;
private: System::Windows::Forms::Panel^ contentPanelsHolder;


private: System::Windows::Forms::PictureBox^ pictureBox1;
private: System::Windows::Forms::PictureBox^ pictureBox5;
private: System::Windows::Forms::PictureBox^ pictureBox3;












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
			this->chatPnl = (gcnew System::Windows::Forms::Panel());
			this->currentCahtPanel = (gcnew System::Windows::Forms::Panel());
			this->chatsContainer = (gcnew System::Windows::Forms::Panel());
			this->messagesFlowPanelsContainer = (gcnew System::Windows::Forms::Panel());
			this->headerContainer = (gcnew System::Windows::Forms::Panel());
			this->removeMemberLabel = (gcnew System::Windows::Forms::Label());
			this->addMemberLabel = (gcnew System::Windows::Forms::Label());
			this->removeMemPicBox = (gcnew System::Windows::Forms::PictureBox());
			this->addMemPicBox = (gcnew System::Windows::Forms::PictureBox());
			this->chatName = (gcnew System::Windows::Forms::Label());
			this->chatPicture = (gcnew System::Windows::Forms::PictureBox());
			this->footerContainer = (gcnew System::Windows::Forms::Panel());
			this->textBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->sendButton = (gcnew System::Windows::Forms::Button());
			this->contactsPanelContainer = (gcnew System::Windows::Forms::Panel());
			this->contactsPanel = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->searchContactPanel = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->searchChatroom_field = (gcnew System::Windows::Forms::TextBox());
			this->contentPanelsHolder = (gcnew System::Windows::Forms::Panel());
			this->addMemberPnl = (gcnew System::Windows::Forms::Panel());
			this->addMem = (gcnew System::Windows::Forms::Button());
			this->button11 = (gcnew System::Windows::Forms::Button());
			this->memName = (gcnew System::Windows::Forms::TextBox());
			this->memPhone = (gcnew System::Windows::Forms::TextBox());
			this->memNumLbl = (gcnew System::Windows::Forms::Label());
			this->memNameLbl = (gcnew System::Windows::Forms::Label());
			this->label18 = (gcnew System::Windows::Forms::Label());
			this->pictureBox4 = (gcnew System::Windows::Forms::PictureBox());
			this->addContactPanel = (gcnew System::Windows::Forms::Panel());
			this->addContact_btn = (gcnew System::Windows::Forms::Button());
			this->checkContact_btn = (gcnew System::Windows::Forms::Button());
			this->addContName_field = (gcnew System::Windows::Forms::TextBox());
			this->addContNum_field = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->NameLabel = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->pictureBox3 = (gcnew System::Windows::Forms::PictureBox());
			this->profilePanel = (gcnew System::Windows::Forms::Panel());
			this->phoneNumberLabel = (gcnew System::Windows::Forms::Label());
			this->label27 = (gcnew System::Windows::Forms::Label());
			this->editPhotoButton = (gcnew System::Windows::Forms::Button());
			this->userPhotoPictureBox = (gcnew System::Windows::Forms::PictureBox());
			this->newAboutRichTextBox = (gcnew System::Windows::Forms::RichTextBox());
			this->aboutLabel = (gcnew System::Windows::Forms::Label());
			this->submitNewAboutButton = (gcnew System::Windows::Forms::Button());
			this->editAboutButton = (gcnew System::Windows::Forms::Button());
			this->label26 = (gcnew System::Windows::Forms::Label());
			this->lastNameLabel = (gcnew System::Windows::Forms::Label());
			this->firstNameLabel = (gcnew System::Windows::Forms::Label());
			this->submitPasswordButton = (gcnew System::Windows::Forms::Button());
			this->newPasswordTextBox = (gcnew System::Windows::Forms::TextBox());
			this->editPasswordButton = (gcnew System::Windows::Forms::Button());
			this->label24 = (gcnew System::Windows::Forms::Label());
			this->submitLastNameButton = (gcnew System::Windows::Forms::Button());
			this->newLastNameTextBox = (gcnew System::Windows::Forms::TextBox());
			this->editLastNameButton = (gcnew System::Windows::Forms::Button());
			this->label23 = (gcnew System::Windows::Forms::Label());
			this->submitFirstNameButton = (gcnew System::Windows::Forms::Button());
			this->newFirstNameTextBox = (gcnew System::Windows::Forms::TextBox());
			this->editFirstNameButton = (gcnew System::Windows::Forms::Button());
			this->label22 = (gcnew System::Windows::Forms::Label());
			this->visibilityComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->submitVisibleButton = (gcnew System::Windows::Forms::Button());
			this->editVisibility = (gcnew System::Windows::Forms::Button());
			this->visibleLabel = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->singOutButton = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->removeMemberPnl = (gcnew System::Windows::Forms::Panel());
			this->RemoveMem = (gcnew System::Windows::Forms::Label());
			this->removeBtn = (gcnew System::Windows::Forms::Button());
			this->GroupMem = (gcnew System::Windows::Forms::CheckedListBox());
			this->pictureBox6 = (gcnew System::Windows::Forms::PictureBox());
			this->addGroup = (gcnew System::Windows::Forms::Panel());
			this->groupImgBut = (gcnew System::Windows::Forms::Button());
			this->groupImgPicBox = (gcnew System::Windows::Forms::PictureBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->usersListBox = (gcnew System::Windows::Forms::CheckedListBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->groupNameTxt = (gcnew System::Windows::Forms::TextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->addBtn = (gcnew System::Windows::Forms::Button());
			this->pictureBox5 = (gcnew System::Windows::Forms::PictureBox());
			this->navPanel = (gcnew System::Windows::Forms::Panel());
			this->label21 = (gcnew System::Windows::Forms::Label());
			this->label20 = (gcnew System::Windows::Forms::Label());
			this->label19 = (gcnew System::Windows::Forms::Label());
			this->label17 = (gcnew System::Windows::Forms::Label());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->chatButton = (gcnew System::Windows::Forms::Button());
			this->goToAddContact_btn = (gcnew System::Windows::Forms::Button());
			this->statusButton = (gcnew System::Windows::Forms::Button());
			this->profileButton = (gcnew System::Windows::Forms::Button());
			this->storyPanel = (gcnew System::Windows::Forms::Panel());
			this->allStoriesPanel = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->stotyHeaderPanel = (gcnew System::Windows::Forms::Panel());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->addStoryPanel = (gcnew System::Windows::Forms::Panel());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->textStory = (gcnew System::Windows::Forms::TextBox());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->colorDialog1 = (gcnew System::Windows::Forms::ColorDialog());
			this->getStoryPanel = (gcnew System::Windows::Forms::Panel());
			this->bodyOfTheStoryPanel = (gcnew System::Windows::Forms::Panel());
			this->bodyOfTheStoryLabel = (gcnew System::Windows::Forms::RichTextBox());
			this->footerOfTheSroryPanel = (gcnew System::Windows::Forms::Panel());
			this->viewerOfTheStoryBtn = (gcnew System::Windows::Forms::Button());
			this->profileUserInStoryPanel = (gcnew System::Windows::Forms::Panel());
			this->moreButton = (gcnew System::Windows::Forms::Button());
			this->storyProgressBar = (gcnew System::Windows::Forms::ProgressBar());
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
			this->storyProgressBarTimer = (gcnew System::Windows::Forms::Timer(this->components));
			this->deleteStoryTimer = (gcnew System::Windows::Forms::Timer(this->components));
			this->signUpPnl->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->signUpBackGround))->BeginInit();
			this->mainPanel->SuspendLayout();
			this->chatPnl->SuspendLayout();
			this->currentCahtPanel->SuspendLayout();
			this->chatsContainer->SuspendLayout();
			this->headerContainer->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->removeMemPicBox))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->addMemPicBox))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chatPicture))->BeginInit();
			this->footerContainer->SuspendLayout();
			this->contactsPanelContainer->SuspendLayout();
			this->searchContactPanel->SuspendLayout();
			this->contentPanelsHolder->SuspendLayout();
			this->addMemberPnl->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->BeginInit();
			this->addContactPanel->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->BeginInit();
			this->profilePanel->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->userPhotoPictureBox))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->removeMemberPnl->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox6))->BeginInit();
			this->addGroup->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->groupImgPicBox))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox5))->BeginInit();
			this->navPanel->SuspendLayout();
			this->storyPanel->SuspendLayout();
			this->stotyHeaderPanel->SuspendLayout();
			this->addStoryPanel->SuspendLayout();
			this->getStoryPanel->SuspendLayout();
			this->bodyOfTheStoryPanel->SuspendLayout();
			this->footerOfTheSroryPanel->SuspendLayout();
			this->profileUserInStoryPanel->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->profileStoryPic))->BeginInit();
			this->SignINPnl->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->signinBackGround))->BeginInit();
			this->SuspendLayout();
			// 
			// signUpPnl
			// 
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
			// 
			// button12
			// 
			this->button12->BackColor = System::Drawing::Color::Cyan;
			this->button12->Cursor = System::Windows::Forms::Cursors::Hand;
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
			this->pictureBox2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.Image")));
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
			this->button10->Cursor = System::Windows::Forms::Cursors::Hand;
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
			this->button9->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button9->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button9->Location = System::Drawing::Point(1375, 801);
			this->button9->Name = L"button9";
			this->button9->Size = System::Drawing::Size(206, 80);
			this->button9->TabIndex = 10;
			this->button9->Text = L"Sign Up →";
			this->button9->UseVisualStyleBackColor = false;
			this->button9->Click += gcnew System::EventHandler(this, &GuiForm::signUpButton_Click);
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
			this->signUpBackGround->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"signUpBackGround.Image")));
			this->signUpBackGround->InitialImage = nullptr;
			this->signUpBackGround->Location = System::Drawing::Point(0, 0);
			this->signUpBackGround->Name = L"signUpBackGround";
			this->signUpBackGround->Size = System::Drawing::Size(1944, 1041);
			this->signUpBackGround->TabIndex = 25;
			this->signUpBackGround->TabStop = false;
			// 
			// passTxt
			// 
			this->passTxt->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->passTxt->Location = System::Drawing::Point(937, 527);
			this->passTxt->Margin = System::Windows::Forms::Padding(4);
			this->passTxt->Name = L"passTxt";
			this->passTxt->PasswordChar = '*';
			this->passTxt->Size = System::Drawing::Size(176, 35);
			this->passTxt->TabIndex = 3;
			// 
			// mainPanel
			// 
			this->mainPanel->BackColor = System::Drawing::Color::White;
			this->mainPanel->Controls->Add(this->chatPnl);
			this->mainPanel->Controls->Add(this->contentPanelsHolder);
			this->mainPanel->Controls->Add(this->navPanel);
			this->mainPanel->Controls->Add(this->storyPanel);
			this->mainPanel->Dock = System::Windows::Forms::DockStyle::Fill;
			this->mainPanel->Location = System::Drawing::Point(0, 0);
			this->mainPanel->Name = L"mainPanel";
			this->mainPanel->Size = System::Drawing::Size(1904, 1041);
			this->mainPanel->TabIndex = 3;
			// 
			// chatPnl
			// 
			this->chatPnl->AllowDrop = true;
			this->chatPnl->Controls->Add(this->currentCahtPanel);
			this->chatPnl->Controls->Add(this->contactsPanelContainer);
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
			this->currentCahtPanel->Location = System::Drawing::Point(332, 0);
			this->currentCahtPanel->Name = L"currentCahtPanel";
			this->currentCahtPanel->Size = System::Drawing::Size(1485, 1041);
			this->currentCahtPanel->TabIndex = 10;
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
			this->chatsContainer->Size = System::Drawing::Size(1485, 995);
			this->chatsContainer->TabIndex = 14;
			// 
			// messagesFlowPanelsContainer
			// 
			this->messagesFlowPanelsContainer->Dock = System::Windows::Forms::DockStyle::Fill;
			this->messagesFlowPanelsContainer->Location = System::Drawing::Point(0, 102);
			this->messagesFlowPanelsContainer->Name = L"messagesFlowPanelsContainer";
			this->messagesFlowPanelsContainer->Size = System::Drawing::Size(1485, 893);
			this->messagesFlowPanelsContainer->TabIndex = 1;
			// 
			// headerContainer
			// 
			this->headerContainer->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(70)), static_cast<System::Int32>(static_cast<System::Byte>(70)),
				static_cast<System::Int32>(static_cast<System::Byte>(70)));
			this->headerContainer->Controls->Add(this->removeMemberLabel);
			this->headerContainer->Controls->Add(this->addMemberLabel);
			this->headerContainer->Controls->Add(this->removeMemPicBox);
			this->headerContainer->Controls->Add(this->addMemPicBox);
			this->headerContainer->Controls->Add(this->chatName);
			this->headerContainer->Controls->Add(this->chatPicture);
			this->headerContainer->Dock = System::Windows::Forms::DockStyle::Top;
			this->headerContainer->Location = System::Drawing::Point(0, 0);
			this->headerContainer->Name = L"headerContainer";
			this->headerContainer->Size = System::Drawing::Size(1485, 102);
			this->headerContainer->TabIndex = 0;
			// 
			// removeMemberLabel
			// 
			this->removeMemberLabel->AutoSize = true;
			this->removeMemberLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->removeMemberLabel->ForeColor = System::Drawing::Color::White;
			this->removeMemberLabel->Location = System::Drawing::Point(973, 32);
			this->removeMemberLabel->Name = L"removeMemberLabel";
			this->removeMemberLabel->Size = System::Drawing::Size(175, 25);
			this->removeMemberLabel->TabIndex = 5;
			this->removeMemberLabel->Text = L"Remove Member";
			// 
			// addMemberLabel
			// 
			this->addMemberLabel->AutoSize = true;
			this->addMemberLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->addMemberLabel->ForeColor = System::Drawing::Color::White;
			this->addMemberLabel->Location = System::Drawing::Point(1321, 32);
			this->addMemberLabel->Name = L"addMemberLabel";
			this->addMemberLabel->Size = System::Drawing::Size(134, 25);
			this->addMemberLabel->TabIndex = 4;
			this->addMemberLabel->Text = L"Add Member";
			// 
			// removeMemPicBox
			// 
			this->removeMemPicBox->Cursor = System::Windows::Forms::Cursors::Hand;
			this->removeMemPicBox->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"removeMemPicBox.Image")));
			this->removeMemPicBox->Location = System::Drawing::Point(900, 12);
			this->removeMemPicBox->Name = L"removeMemPicBox";
			this->removeMemPicBox->Size = System::Drawing::Size(65, 68);
			this->removeMemPicBox->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->removeMemPicBox->TabIndex = 3;
			this->removeMemPicBox->TabStop = false;
			this->removeMemPicBox->Click += gcnew System::EventHandler(this, &GuiForm::removeMemPicBox_Click);
			// 
			// addMemPicBox
			// 
			this->addMemPicBox->Cursor = System::Windows::Forms::Cursors::Hand;
			this->addMemPicBox->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"addMemPicBox.Image")));
			this->addMemPicBox->Location = System::Drawing::Point(1250, 12);
			this->addMemPicBox->Name = L"addMemPicBox";
			this->addMemPicBox->Size = System::Drawing::Size(65, 68);
			this->addMemPicBox->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->addMemPicBox->TabIndex = 2;
			this->addMemPicBox->TabStop = false;
			this->addMemPicBox->Click += gcnew System::EventHandler(this, &GuiForm::addMemPicBox_Click);
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
			this->footerContainer->Size = System::Drawing::Size(1485, 46);
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
			this->textBox1->Size = System::Drawing::Size(1403, 46);
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
			this->sendButton->Location = System::Drawing::Point(1403, 0);
			this->sendButton->Name = L"sendButton";
			this->sendButton->Size = System::Drawing::Size(82, 46);
			this->sendButton->TabIndex = 3;
			this->sendButton->UseVisualStyleBackColor = true;
			this->sendButton->Click += gcnew System::EventHandler(this, &GuiForm::sendButton_Click);
			// 
			// contactsPanelContainer
			// 
			this->contactsPanelContainer->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(50)),
				static_cast<System::Int32>(static_cast<System::Byte>(50)), static_cast<System::Int32>(static_cast<System::Byte>(50)));
			this->contactsPanelContainer->Controls->Add(this->contactsPanel);
			this->contactsPanelContainer->Controls->Add(this->searchContactPanel);
			this->contactsPanelContainer->Dock = System::Windows::Forms::DockStyle::Left;
			this->contactsPanelContainer->Location = System::Drawing::Point(0, 0);
			this->contactsPanelContainer->Name = L"contactsPanelContainer";
			this->contactsPanelContainer->Size = System::Drawing::Size(332, 1041);
			this->contactsPanelContainer->TabIndex = 8;
			// 
			// contactsPanel
			// 
			this->contactsPanel->Location = System::Drawing::Point(3, 32);
			this->contactsPanel->Name = L"contactsPanel";
			this->contactsPanel->Size = System::Drawing::Size(326, 1006);
			this->contactsPanel->TabIndex = 1;
			// 
			// searchContactPanel
			// 
			this->searchContactPanel->Controls->Add(this->searchChatroom_field);
			this->searchContactPanel->Location = System::Drawing::Point(3, 3);
			this->searchContactPanel->Name = L"searchContactPanel";
			this->searchContactPanel->Size = System::Drawing::Size(329, 28);
			this->searchContactPanel->TabIndex = 0;
			// 
			// searchChatroom_field
			// 
			this->searchChatroom_field->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->searchChatroom_field->Location = System::Drawing::Point(3, 3);
			this->searchChatroom_field->Name = L"searchChatroom_field";
			this->searchChatroom_field->Size = System::Drawing::Size(320, 29);
			this->searchChatroom_field->TabIndex = 0;
			this->searchChatroom_field->TextChanged += gcnew System::EventHandler(this, &GuiForm::searchChatroom_field_TextChanged);
			// 
			// contentPanelsHolder
			// 
			this->contentPanelsHolder->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"contentPanelsHolder.BackgroundImage")));
			this->contentPanelsHolder->Controls->Add(this->addMemberPnl);
			this->contentPanelsHolder->Controls->Add(this->addContactPanel);
			this->contentPanelsHolder->Controls->Add(this->profilePanel);
			this->contentPanelsHolder->Controls->Add(this->removeMemberPnl);
			this->contentPanelsHolder->Controls->Add(this->addGroup);
			this->contentPanelsHolder->Dock = System::Windows::Forms::DockStyle::Fill;
			this->contentPanelsHolder->Location = System::Drawing::Point(87, 0);
			this->contentPanelsHolder->Name = L"contentPanelsHolder";
			this->contentPanelsHolder->Size = System::Drawing::Size(1817, 1041);
			this->contentPanelsHolder->TabIndex = 6;
			// 
			// addMemberPnl
			// 
			this->addMemberPnl->BackColor = System::Drawing::Color::Transparent;
			this->addMemberPnl->Controls->Add(this->addMem);
			this->addMemberPnl->Controls->Add(this->button11);
			this->addMemberPnl->Controls->Add(this->memName);
			this->addMemberPnl->Controls->Add(this->memPhone);
			this->addMemberPnl->Controls->Add(this->memNumLbl);
			this->addMemberPnl->Controls->Add(this->memNameLbl);
			this->addMemberPnl->Controls->Add(this->label18);
			this->addMemberPnl->Controls->Add(this->pictureBox4);
			this->addMemberPnl->Dock = System::Windows::Forms::DockStyle::Fill;
			this->addMemberPnl->Location = System::Drawing::Point(0, 0);
			this->addMemberPnl->Name = L"addMemberPnl";
			this->addMemberPnl->Size = System::Drawing::Size(1817, 1041);
			this->addMemberPnl->TabIndex = 17;
			// 
			// addMem
			// 
			this->addMem->Cursor = System::Windows::Forms::Cursors::Hand;
			this->addMem->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->addMem->Location = System::Drawing::Point(946, 608);
			this->addMem->Name = L"addMem";
			this->addMem->Size = System::Drawing::Size(75, 36);
			this->addMem->TabIndex = 22;
			this->addMem->Text = L"Add";
			this->addMem->UseVisualStyleBackColor = true;
			this->addMem->Visible = false;
			this->addMem->Click += gcnew System::EventHandler(this, &GuiForm::addMem_Click_1);
			// 
			// button11
			// 
			this->button11->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button11->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button11->Location = System::Drawing::Point(1100, 481);
			this->button11->Name = L"button11";
			this->button11->Size = System::Drawing::Size(87, 31);
			this->button11->TabIndex = 21;
			this->button11->Text = L"Check";
			this->button11->UseVisualStyleBackColor = true;
			this->button11->Click += gcnew System::EventHandler(this, &GuiForm::button11_Click);
			// 
			// memName
			// 
			this->memName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->memName->Location = System::Drawing::Point(866, 535);
			this->memName->Name = L"memName";
			this->memName->Size = System::Drawing::Size(215, 31);
			this->memName->TabIndex = 18;
			this->memName->Visible = false;
			// 
			// memPhone
			// 
			this->memPhone->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->memPhone->Location = System::Drawing::Point(866, 480);
			this->memPhone->Name = L"memPhone";
			this->memPhone->Size = System::Drawing::Size(215, 31);
			this->memPhone->TabIndex = 17;
			// 
			// memNumLbl
			// 
			this->memNumLbl->AutoSize = true;
			this->memNumLbl->BackColor = System::Drawing::Color::Transparent;
			this->memNumLbl->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->memNumLbl->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->memNumLbl->Location = System::Drawing::Point(748, 483);
			this->memNumLbl->Name = L"memNumLbl";
			this->memNumLbl->Size = System::Drawing::Size(86, 25);
			this->memNumLbl->TabIndex = 16;
			this->memNumLbl->Text = L"Phone:";
			// 
			// memNameLbl
			// 
			this->memNameLbl->AutoSize = true;
			this->memNameLbl->BackColor = System::Drawing::Color::Transparent;
			this->memNameLbl->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->memNameLbl->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->memNameLbl->Location = System::Drawing::Point(752, 534);
			this->memNameLbl->Name = L"memNameLbl";
			this->memNameLbl->Size = System::Drawing::Size(79, 25);
			this->memNameLbl->TabIndex = 15;
			this->memNameLbl->Text = L"Name:";
			this->memNameLbl->Visible = false;
			// 
			// label18
			// 
			this->label18->AutoSize = true;
			this->label18->BackColor = System::Drawing::Color::Transparent;
			this->label18->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label18->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->label18->Location = System::Drawing::Point(880, 406);
			this->label18->Name = L"label18";
			this->label18->Size = System::Drawing::Size(177, 31);
			this->label18->TabIndex = 14;
			this->label18->Text = L"Add member";
			// 
			// pictureBox4
			// 
			this->pictureBox4->Dock = System::Windows::Forms::DockStyle::Fill;
			this->pictureBox4->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox4.Image")));
			this->pictureBox4->Location = System::Drawing::Point(0, 0);
			this->pictureBox4->Name = L"pictureBox4";
			this->pictureBox4->Size = System::Drawing::Size(1817, 1041);
			this->pictureBox4->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox4->TabIndex = 34;
			this->pictureBox4->TabStop = false;
			// 
			// addContactPanel
			// 
			this->addContactPanel->BackColor = System::Drawing::Color::Transparent;
			this->addContactPanel->Controls->Add(this->addContact_btn);
			this->addContactPanel->Controls->Add(this->checkContact_btn);
			this->addContactPanel->Controls->Add(this->addContName_field);
			this->addContactPanel->Controls->Add(this->addContNum_field);
			this->addContactPanel->Controls->Add(this->label5);
			this->addContactPanel->Controls->Add(this->NameLabel);
			this->addContactPanel->Controls->Add(this->label3);
			this->addContactPanel->Controls->Add(this->pictureBox3);
			this->addContactPanel->Dock = System::Windows::Forms::DockStyle::Fill;
			this->addContactPanel->Location = System::Drawing::Point(0, 0);
			this->addContactPanel->Name = L"addContactPanel";
			this->addContactPanel->Size = System::Drawing::Size(1817, 1041);
			this->addContactPanel->TabIndex = 14;
			// 
			// addContact_btn
			// 
			this->addContact_btn->Cursor = System::Windows::Forms::Cursors::Hand;
			this->addContact_btn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->addContact_btn->Location = System::Drawing::Point(850, 635);
			this->addContact_btn->Name = L"addContact_btn";
			this->addContact_btn->Size = System::Drawing::Size(90, 32);
			this->addContact_btn->TabIndex = 22;
			this->addContact_btn->Text = L"Add";
			this->addContact_btn->UseVisualStyleBackColor = true;
			this->addContact_btn->Visible = false;
			this->addContact_btn->Click += gcnew System::EventHandler(this, &GuiForm::addContact_btn_Click);
			// 
			// checkContact_btn
			// 
			this->checkContact_btn->Cursor = System::Windows::Forms::Cursors::Hand;
			this->checkContact_btn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->checkContact_btn->Location = System::Drawing::Point(1078, 481);
			this->checkContact_btn->Name = L"checkContact_btn";
			this->checkContact_btn->Size = System::Drawing::Size(80, 31);
			this->checkContact_btn->TabIndex = 21;
			this->checkContact_btn->Text = L"Check";
			this->checkContact_btn->UseVisualStyleBackColor = true;
			this->checkContact_btn->Click += gcnew System::EventHandler(this, &GuiForm::checkContact_btn_Click);
			// 
			// addContName_field
			// 
			this->addContName_field->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->addContName_field->Location = System::Drawing::Point(791, 551);
			this->addContName_field->Name = L"addContName_field";
			this->addContName_field->Size = System::Drawing::Size(215, 31);
			this->addContName_field->TabIndex = 18;
			this->addContName_field->Visible = false;
			// 
			// addContNum_field
			// 
			this->addContNum_field->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->addContNum_field->Location = System::Drawing::Point(791, 480);
			this->addContNum_field->Name = L"addContNum_field";
			this->addContNum_field->Size = System::Drawing::Size(215, 31);
			this->addContNum_field->TabIndex = 17;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->BackColor = System::Drawing::Color::Transparent;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->label5->Location = System::Drawing::Point(698, 488);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(77, 24);
			this->label5->TabIndex = 16;
			this->label5->Text = L"Phone:";
			// 
			// NameLabel
			// 
			this->NameLabel->AutoSize = true;
			this->NameLabel->BackColor = System::Drawing::Color::Transparent;
			this->NameLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->NameLabel->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->NameLabel->Location = System::Drawing::Point(697, 549);
			this->NameLabel->Name = L"NameLabel";
			this->NameLabel->Size = System::Drawing::Size(79, 25);
			this->NameLabel->TabIndex = 15;
			this->NameLabel->Text = L"Name:";
			this->NameLabel->Visible = false;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::Color::Transparent;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->label3->Location = System::Drawing::Point(807, 414);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(169, 31);
			this->label3->TabIndex = 14;
			this->label3->Text = L"Add contact";
			// 
			// pictureBox3
			// 
			this->pictureBox3->Dock = System::Windows::Forms::DockStyle::Fill;
			this->pictureBox3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox3.Image")));
			this->pictureBox3->Location = System::Drawing::Point(0, 0);
			this->pictureBox3->Name = L"pictureBox3";
			this->pictureBox3->Size = System::Drawing::Size(1817, 1041);
			this->pictureBox3->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox3->TabIndex = 34;
			this->pictureBox3->TabStop = false;
			// 
			// profilePanel
			// 
			this->profilePanel->BackColor = System::Drawing::Color::Transparent;
			this->profilePanel->Controls->Add(this->phoneNumberLabel);
			this->profilePanel->Controls->Add(this->label27);
			this->profilePanel->Controls->Add(this->editPhotoButton);
			this->profilePanel->Controls->Add(this->userPhotoPictureBox);
			this->profilePanel->Controls->Add(this->newAboutRichTextBox);
			this->profilePanel->Controls->Add(this->aboutLabel);
			this->profilePanel->Controls->Add(this->submitNewAboutButton);
			this->profilePanel->Controls->Add(this->editAboutButton);
			this->profilePanel->Controls->Add(this->label26);
			this->profilePanel->Controls->Add(this->lastNameLabel);
			this->profilePanel->Controls->Add(this->firstNameLabel);
			this->profilePanel->Controls->Add(this->submitPasswordButton);
			this->profilePanel->Controls->Add(this->newPasswordTextBox);
			this->profilePanel->Controls->Add(this->editPasswordButton);
			this->profilePanel->Controls->Add(this->label24);
			this->profilePanel->Controls->Add(this->submitLastNameButton);
			this->profilePanel->Controls->Add(this->newLastNameTextBox);
			this->profilePanel->Controls->Add(this->editLastNameButton);
			this->profilePanel->Controls->Add(this->label23);
			this->profilePanel->Controls->Add(this->submitFirstNameButton);
			this->profilePanel->Controls->Add(this->newFirstNameTextBox);
			this->profilePanel->Controls->Add(this->editFirstNameButton);
			this->profilePanel->Controls->Add(this->label22);
			this->profilePanel->Controls->Add(this->visibilityComboBox);
			this->profilePanel->Controls->Add(this->submitVisibleButton);
			this->profilePanel->Controls->Add(this->editVisibility);
			this->profilePanel->Controls->Add(this->visibleLabel);
			this->profilePanel->Controls->Add(this->label1);
			this->profilePanel->Controls->Add(this->singOutButton);
			this->profilePanel->Controls->Add(this->pictureBox1);
			this->profilePanel->Dock = System::Windows::Forms::DockStyle::Fill;
			this->profilePanel->ForeColor = System::Drawing::Color::Blue;
			this->profilePanel->Location = System::Drawing::Point(0, 0);
			this->profilePanel->Name = L"profilePanel";
			this->profilePanel->Size = System::Drawing::Size(1817, 1041);
			this->profilePanel->TabIndex = 10;
			// 
			// phoneNumberLabel
			// 
			this->phoneNumberLabel->AutoSize = true;
			this->phoneNumberLabel->BackColor = System::Drawing::Color::Transparent;
			this->phoneNumberLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->phoneNumberLabel->ForeColor = System::Drawing::Color::Cyan;
			this->phoneNumberLabel->Location = System::Drawing::Point(495, 309);
			this->phoneNumberLabel->Name = L"phoneNumberLabel";
			this->phoneNumberLabel->Size = System::Drawing::Size(0, 31);
			this->phoneNumberLabel->TabIndex = 32;
			// 
			// label27
			// 
			this->label27->AutoSize = true;
			this->label27->BackColor = System::Drawing::Color::Transparent;
			this->label27->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label27->ForeColor = System::Drawing::Color::White;
			this->label27->Location = System::Drawing::Point(286, 309);
			this->label27->Name = L"label27";
			this->label27->Size = System::Drawing::Size(203, 31);
			this->label27->TabIndex = 31;
			this->label27->Text = L"Phone Number:";
			// 
			// editPhotoButton
			// 
			this->editPhotoButton->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->editPhotoButton->Cursor = System::Windows::Forms::Cursors::Hand;
			this->editPhotoButton->FlatAppearance->BorderSize = 0;
			this->editPhotoButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->editPhotoButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->editPhotoButton->ForeColor = System::Drawing::Color::White;
			this->editPhotoButton->Location = System::Drawing::Point(866, 178);
			this->editPhotoButton->Name = L"editPhotoButton";
			this->editPhotoButton->Size = System::Drawing::Size(59, 30);
			this->editPhotoButton->TabIndex = 30;
			this->editPhotoButton->Text = L"Edit";
			this->editPhotoButton->UseVisualStyleBackColor = false;
			this->editPhotoButton->Click += gcnew System::EventHandler(this, &GuiForm::editPhotoButton_Click);
			// 
			// userPhotoPictureBox
			// 
			this->userPhotoPictureBox->BackColor = System::Drawing::Color::Transparent;
			this->userPhotoPictureBox->Location = System::Drawing::Point(536, 115);
			this->userPhotoPictureBox->Name = L"userPhotoPictureBox";
			this->userPhotoPictureBox->Size = System::Drawing::Size(187, 157);
			this->userPhotoPictureBox->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->userPhotoPictureBox->TabIndex = 29;
			this->userPhotoPictureBox->TabStop = false;
			// 
			// newAboutRichTextBox
			// 
			this->newAboutRichTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->newAboutRichTextBox->Location = System::Drawing::Point(783, 768);
			this->newAboutRichTextBox->Name = L"newAboutRichTextBox";
			this->newAboutRichTextBox->Size = System::Drawing::Size(384, 92);
			this->newAboutRichTextBox->TabIndex = 28;
			this->newAboutRichTextBox->Text = L"";
			this->newAboutRichTextBox->Visible = false;
			// 
			// aboutLabel
			// 
			this->aboutLabel->AutoSize = true;
			this->aboutLabel->BackColor = System::Drawing::Color::Transparent;
			this->aboutLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->aboutLabel->ForeColor = System::Drawing::Color::Cyan;
			this->aboutLabel->Location = System::Drawing::Point(402, 783);
			this->aboutLabel->Name = L"aboutLabel";
			this->aboutLabel->Size = System::Drawing::Size(0, 31);
			this->aboutLabel->TabIndex = 27;
			// 
			// submitNewAboutButton
			// 
			this->submitNewAboutButton->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->submitNewAboutButton->Cursor = System::Windows::Forms::Cursors::Hand;
			this->submitNewAboutButton->FlatAppearance->BorderSize = 0;
			this->submitNewAboutButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->submitNewAboutButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->submitNewAboutButton->ForeColor = System::Drawing::Color::White;
			this->submitNewAboutButton->Location = System::Drawing::Point(1173, 783);
			this->submitNewAboutButton->Name = L"submitNewAboutButton";
			this->submitNewAboutButton->Size = System::Drawing::Size(81, 31);
			this->submitNewAboutButton->TabIndex = 26;
			this->submitNewAboutButton->Text = L"Submit";
			this->submitNewAboutButton->UseVisualStyleBackColor = false;
			this->submitNewAboutButton->Visible = false;
			this->submitNewAboutButton->Click += gcnew System::EventHandler(this, &GuiForm::submitNewAboutButton_Click);
			// 
			// editAboutButton
			// 
			this->editAboutButton->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->editAboutButton->Cursor = System::Windows::Forms::Cursors::Hand;
			this->editAboutButton->FlatAppearance->BorderSize = 0;
			this->editAboutButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->editAboutButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->editAboutButton->ForeColor = System::Drawing::Color::White;
			this->editAboutButton->Location = System::Drawing::Point(715, 787);
			this->editAboutButton->Name = L"editAboutButton";
			this->editAboutButton->Size = System::Drawing::Size(59, 30);
			this->editAboutButton->TabIndex = 24;
			this->editAboutButton->Text = L"Edit";
			this->editAboutButton->UseVisualStyleBackColor = false;
			this->editAboutButton->Click += gcnew System::EventHandler(this, &GuiForm::editAboutButton_Click);
			// 
			// label26
			// 
			this->label26->AutoSize = true;
			this->label26->BackColor = System::Drawing::Color::Transparent;
			this->label26->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label26->ForeColor = System::Drawing::Color::White;
			this->label26->Location = System::Drawing::Point(286, 780);
			this->label26->Name = L"label26";
			this->label26->Size = System::Drawing::Size(100, 31);
			this->label26->TabIndex = 23;
			this->label26->Text = L"About :";
			// 
			// lastNameLabel
			// 
			this->lastNameLabel->AutoSize = true;
			this->lastNameLabel->BackColor = System::Drawing::Color::Transparent;
			this->lastNameLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lastNameLabel->ForeColor = System::Drawing::Color::Cyan;
			this->lastNameLabel->Location = System::Drawing::Point(454, 595);
			this->lastNameLabel->Name = L"lastNameLabel";
			this->lastNameLabel->Size = System::Drawing::Size(0, 31);
			this->lastNameLabel->TabIndex = 21;
			// 
			// firstNameLabel
			// 
			this->firstNameLabel->AutoSize = true;
			this->firstNameLabel->BackColor = System::Drawing::Color::Transparent;
			this->firstNameLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->firstNameLabel->ForeColor = System::Drawing::Color::Cyan;
			this->firstNameLabel->Location = System::Drawing::Point(454, 500);
			this->firstNameLabel->Name = L"firstNameLabel";
			this->firstNameLabel->Size = System::Drawing::Size(0, 31);
			this->firstNameLabel->TabIndex = 20;
			// 
			// submitPasswordButton
			// 
			this->submitPasswordButton->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->submitPasswordButton->Cursor = System::Windows::Forms::Cursors::Hand;
			this->submitPasswordButton->FlatAppearance->BorderSize = 0;
			this->submitPasswordButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->submitPasswordButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->submitPasswordButton->ForeColor = System::Drawing::Color::White;
			this->submitPasswordButton->Location = System::Drawing::Point(1173, 692);
			this->submitPasswordButton->Name = L"submitPasswordButton";
			this->submitPasswordButton->Size = System::Drawing::Size(81, 31);
			this->submitPasswordButton->TabIndex = 19;
			this->submitPasswordButton->Text = L"Submit";
			this->submitPasswordButton->UseVisualStyleBackColor = false;
			this->submitPasswordButton->Visible = false;
			this->submitPasswordButton->Click += gcnew System::EventHandler(this, &GuiForm::submitPasswordButton_Click);
			// 
			// newPasswordTextBox
			// 
			this->newPasswordTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->newPasswordTextBox->Location = System::Drawing::Point(886, 689);
			this->newPasswordTextBox->Name = L"newPasswordTextBox";
			this->newPasswordTextBox->Size = System::Drawing::Size(166, 35);
			this->newPasswordTextBox->TabIndex = 18;
			this->newPasswordTextBox->Visible = false;
			// 
			// editPasswordButton
			// 
			this->editPasswordButton->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->editPasswordButton->Cursor = System::Windows::Forms::Cursors::Hand;
			this->editPasswordButton->FlatAppearance->BorderSize = 0;
			this->editPasswordButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->editPasswordButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->editPasswordButton->ForeColor = System::Drawing::Color::White;
			this->editPasswordButton->Location = System::Drawing::Point(714, 693);
			this->editPasswordButton->Name = L"editPasswordButton";
			this->editPasswordButton->Size = System::Drawing::Size(59, 30);
			this->editPasswordButton->TabIndex = 17;
			this->editPasswordButton->Text = L"Edit";
			this->editPasswordButton->UseVisualStyleBackColor = false;
			this->editPasswordButton->Click += gcnew System::EventHandler(this, &GuiForm::editPasswordButton_Click);
			// 
			// label24
			// 
			this->label24->AutoSize = true;
			this->label24->BackColor = System::Drawing::Color::Transparent;
			this->label24->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label24->ForeColor = System::Drawing::Color::White;
			this->label24->Location = System::Drawing::Point(286, 689);
			this->label24->Name = L"label24";
			this->label24->Size = System::Drawing::Size(141, 31);
			this->label24->TabIndex = 16;
			this->label24->Text = L"Password ";
			// 
			// submitLastNameButton
			// 
			this->submitLastNameButton->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->submitLastNameButton->Cursor = System::Windows::Forms::Cursors::Hand;
			this->submitLastNameButton->FlatAppearance->BorderSize = 0;
			this->submitLastNameButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->submitLastNameButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->submitLastNameButton->ForeColor = System::Drawing::Color::White;
			this->submitLastNameButton->Location = System::Drawing::Point(1173, 599);
			this->submitLastNameButton->Name = L"submitLastNameButton";
			this->submitLastNameButton->Size = System::Drawing::Size(81, 31);
			this->submitLastNameButton->TabIndex = 15;
			this->submitLastNameButton->Text = L"Submit";
			this->submitLastNameButton->UseVisualStyleBackColor = false;
			this->submitLastNameButton->Visible = false;
			this->submitLastNameButton->Click += gcnew System::EventHandler(this, &GuiForm::submitLastNameButton_Click);
			// 
			// newLastNameTextBox
			// 
			this->newLastNameTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->newLastNameTextBox->Location = System::Drawing::Point(886, 596);
			this->newLastNameTextBox->Name = L"newLastNameTextBox";
			this->newLastNameTextBox->Size = System::Drawing::Size(166, 35);
			this->newLastNameTextBox->TabIndex = 14;
			this->newLastNameTextBox->Visible = false;
			// 
			// editLastNameButton
			// 
			this->editLastNameButton->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->editLastNameButton->Cursor = System::Windows::Forms::Cursors::Hand;
			this->editLastNameButton->FlatAppearance->BorderSize = 0;
			this->editLastNameButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->editLastNameButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->editLastNameButton->ForeColor = System::Drawing::Color::White;
			this->editLastNameButton->Location = System::Drawing::Point(714, 600);
			this->editLastNameButton->Name = L"editLastNameButton";
			this->editLastNameButton->Size = System::Drawing::Size(59, 30);
			this->editLastNameButton->TabIndex = 13;
			this->editLastNameButton->Text = L"Edit";
			this->editLastNameButton->UseVisualStyleBackColor = false;
			this->editLastNameButton->Click += gcnew System::EventHandler(this, &GuiForm::editLastNameButton_Click);
			// 
			// label23
			// 
			this->label23->AutoSize = true;
			this->label23->BackColor = System::Drawing::Color::Transparent;
			this->label23->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label23->ForeColor = System::Drawing::Color::White;
			this->label23->Location = System::Drawing::Point(286, 596);
			this->label23->Name = L"label23";
			this->label23->Size = System::Drawing::Size(160, 31);
			this->label23->TabIndex = 12;
			this->label23->Text = L"Last Name :";
			// 
			// submitFirstNameButton
			// 
			this->submitFirstNameButton->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->submitFirstNameButton->Cursor = System::Windows::Forms::Cursors::Hand;
			this->submitFirstNameButton->FlatAppearance->BorderSize = 0;
			this->submitFirstNameButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->submitFirstNameButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->submitFirstNameButton->ForeColor = System::Drawing::Color::White;
			this->submitFirstNameButton->Location = System::Drawing::Point(1173, 500);
			this->submitFirstNameButton->Name = L"submitFirstNameButton";
			this->submitFirstNameButton->Size = System::Drawing::Size(81, 31);
			this->submitFirstNameButton->TabIndex = 11;
			this->submitFirstNameButton->Text = L"Submit";
			this->submitFirstNameButton->UseVisualStyleBackColor = false;
			this->submitFirstNameButton->Visible = false;
			this->submitFirstNameButton->Click += gcnew System::EventHandler(this, &GuiForm::submitFirstNameButton_Click);
			// 
			// newFirstNameTextBox
			// 
			this->newFirstNameTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->newFirstNameTextBox->Location = System::Drawing::Point(886, 497);
			this->newFirstNameTextBox->Name = L"newFirstNameTextBox";
			this->newFirstNameTextBox->Size = System::Drawing::Size(166, 35);
			this->newFirstNameTextBox->TabIndex = 10;
			this->newFirstNameTextBox->Visible = false;
			// 
			// editFirstNameButton
			// 
			this->editFirstNameButton->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->editFirstNameButton->Cursor = System::Windows::Forms::Cursors::Hand;
			this->editFirstNameButton->FlatAppearance->BorderSize = 0;
			this->editFirstNameButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->editFirstNameButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->editFirstNameButton->ForeColor = System::Drawing::Color::White;
			this->editFirstNameButton->Location = System::Drawing::Point(714, 501);
			this->editFirstNameButton->Name = L"editFirstNameButton";
			this->editFirstNameButton->Size = System::Drawing::Size(59, 30);
			this->editFirstNameButton->TabIndex = 9;
			this->editFirstNameButton->Text = L"Edit";
			this->editFirstNameButton->UseVisualStyleBackColor = false;
			this->editFirstNameButton->Click += gcnew System::EventHandler(this, &GuiForm::editFirstNameButton_Click);
			// 
			// label22
			// 
			this->label22->AutoSize = true;
			this->label22->BackColor = System::Drawing::Color::Transparent;
			this->label22->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label22->ForeColor = System::Drawing::Color::White;
			this->label22->Location = System::Drawing::Point(286, 497);
			this->label22->Name = L"label22";
			this->label22->Size = System::Drawing::Size(162, 31);
			this->label22->TabIndex = 8;
			this->label22->Text = L"First Name :";
			// 
			// visibilityComboBox
			// 
			this->visibilityComboBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->visibilityComboBox->FormattingEnabled = true;
			this->visibilityComboBox->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"True", L"False" });
			this->visibilityComboBox->Location = System::Drawing::Point(886, 393);
			this->visibilityComboBox->Name = L"visibilityComboBox";
			this->visibilityComboBox->Size = System::Drawing::Size(162, 33);
			this->visibilityComboBox->TabIndex = 7;
			this->visibilityComboBox->Visible = false;
			// 
			// submitVisibleButton
			// 
			this->submitVisibleButton->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->submitVisibleButton->Cursor = System::Windows::Forms::Cursors::Hand;
			this->submitVisibleButton->FlatAppearance->BorderSize = 0;
			this->submitVisibleButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->submitVisibleButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->submitVisibleButton->ForeColor = System::Drawing::Color::White;
			this->submitVisibleButton->Location = System::Drawing::Point(1173, 396);
			this->submitVisibleButton->Name = L"submitVisibleButton";
			this->submitVisibleButton->Size = System::Drawing::Size(81, 31);
			this->submitVisibleButton->TabIndex = 6;
			this->submitVisibleButton->Text = L"Submit";
			this->submitVisibleButton->UseVisualStyleBackColor = false;
			this->submitVisibleButton->Visible = false;
			this->submitVisibleButton->Click += gcnew System::EventHandler(this, &GuiForm::submitVisibleButton_Click);
			// 
			// editVisibility
			// 
			this->editVisibility->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->editVisibility->Cursor = System::Windows::Forms::Cursors::Hand;
			this->editVisibility->FlatAppearance->BorderSize = 0;
			this->editVisibility->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->editVisibility->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->editVisibility->ForeColor = System::Drawing::Color::White;
			this->editVisibility->Location = System::Drawing::Point(714, 394);
			this->editVisibility->Name = L"editVisibility";
			this->editVisibility->Size = System::Drawing::Size(59, 30);
			this->editVisibility->TabIndex = 4;
			this->editVisibility->Text = L"Edit";
			this->editVisibility->UseVisualStyleBackColor = false;
			this->editVisibility->Click += gcnew System::EventHandler(this, &GuiForm::editVisibility_Click);
			// 
			// visibleLabel
			// 
			this->visibleLabel->AutoSize = true;
			this->visibleLabel->BackColor = System::Drawing::Color::Transparent;
			this->visibleLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->visibleLabel->ForeColor = System::Drawing::Color::Cyan;
			this->visibleLabel->Location = System::Drawing::Point(392, 392);
			this->visibleLabel->Name = L"visibleLabel";
			this->visibleLabel->Size = System::Drawing::Size(0, 31);
			this->visibleLabel->TabIndex = 3;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::White;
			this->label1->Location = System::Drawing::Point(286, 392);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(109, 31);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Visible :";
			// 
			// singOutButton
			// 
			this->singOutButton->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->singOutButton->BackColor = System::Drawing::Color::DodgerBlue;
			this->singOutButton->Cursor = System::Windows::Forms::Cursors::Hand;
			this->singOutButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->singOutButton->ForeColor = System::Drawing::Color::Black;
			this->singOutButton->Location = System::Drawing::Point(374, 911);
			this->singOutButton->Name = L"singOutButton";
			this->singOutButton->Size = System::Drawing::Size(144, 51);
			this->singOutButton->TabIndex = 1;
			this->singOutButton->Text = L"Sign out";
			this->singOutButton->UseVisualStyleBackColor = false;
			this->singOutButton->Click += gcnew System::EventHandler(this, &GuiForm::singOutButton_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(0, 0);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(1817, 1041);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 33;
			this->pictureBox1->TabStop = false;
			// 
			// removeMemberPnl
			// 
			this->removeMemberPnl->BackColor = System::Drawing::Color::Transparent;
			this->removeMemberPnl->Controls->Add(this->RemoveMem);
			this->removeMemberPnl->Controls->Add(this->removeBtn);
			this->removeMemberPnl->Controls->Add(this->GroupMem);
			this->removeMemberPnl->Controls->Add(this->pictureBox6);
			this->removeMemberPnl->Dock = System::Windows::Forms::DockStyle::Fill;
			this->removeMemberPnl->Location = System::Drawing::Point(0, 0);
			this->removeMemberPnl->Name = L"removeMemberPnl";
			this->removeMemberPnl->Size = System::Drawing::Size(1817, 1041);
			this->removeMemberPnl->TabIndex = 18;
			// 
			// RemoveMem
			// 
			this->RemoveMem->AutoSize = true;
			this->RemoveMem->BackColor = System::Drawing::Color::Transparent;
			this->RemoveMem->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 27.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->RemoveMem->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->RemoveMem->Location = System::Drawing::Point(740, 309);
			this->RemoveMem->Name = L"RemoveMem";
			this->RemoveMem->Size = System::Drawing::Size(332, 42);
			this->RemoveMem->TabIndex = 14;
			this->RemoveMem->Text = L"Removing Member";
			// 
			// removeBtn
			// 
			this->removeBtn->BackColor = System::Drawing::Color::Red;
			this->removeBtn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->removeBtn->ForeColor = System::Drawing::Color::White;
			this->removeBtn->Location = System::Drawing::Point(813, 635);
			this->removeBtn->Name = L"removeBtn";
			this->removeBtn->Size = System::Drawing::Size(193, 55);
			this->removeBtn->TabIndex = 13;
			this->removeBtn->Text = L"Remove Member";
			this->removeBtn->UseVisualStyleBackColor = false;
			this->removeBtn->Click += gcnew System::EventHandler(this, &GuiForm::removeBtn_Click);
			// 
			// GroupMem
			// 
			this->GroupMem->BackColor = System::Drawing::SystemColors::Window;
			this->GroupMem->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->GroupMem->FormattingEnabled = true;
			this->GroupMem->Location = System::Drawing::Point(725, 467);
			this->GroupMem->Name = L"GroupMem";
			this->GroupMem->Size = System::Drawing::Size(392, 82);
			this->GroupMem->TabIndex = 12;
			// 
			// pictureBox6
			// 
			this->pictureBox6->Dock = System::Windows::Forms::DockStyle::Fill;
			this->pictureBox6->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox6.Image")));
			this->pictureBox6->Location = System::Drawing::Point(0, 0);
			this->pictureBox6->Name = L"pictureBox6";
			this->pictureBox6->Size = System::Drawing::Size(1817, 1041);
			this->pictureBox6->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox6->TabIndex = 34;
			this->pictureBox6->TabStop = false;
			// 
			// addGroup
			// 
			this->addGroup->BackColor = System::Drawing::Color::Transparent;
			this->addGroup->Controls->Add(this->groupImgBut);
			this->addGroup->Controls->Add(this->groupImgPicBox);
			this->addGroup->Controls->Add(this->label6);
			this->addGroup->Controls->Add(this->usersListBox);
			this->addGroup->Controls->Add(this->label8);
			this->addGroup->Controls->Add(this->groupNameTxt);
			this->addGroup->Controls->Add(this->label7);
			this->addGroup->Controls->Add(this->addBtn);
			this->addGroup->Controls->Add(this->pictureBox5);
			this->addGroup->Dock = System::Windows::Forms::DockStyle::Fill;
			this->addGroup->Location = System::Drawing::Point(0, 0);
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
			this->groupImgPicBox->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"groupImgPicBox.Image")));
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
			this->label6->BackColor = System::Drawing::Color::Transparent;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->ForeColor = System::Drawing::Color::Blue;
			this->label6->Location = System::Drawing::Point(735, 603);
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
			this->usersListBox->Size = System::Drawing::Size(356, 82);
			this->usersListBox->TabIndex = 11;
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->BackColor = System::Drawing::Color::Transparent;
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
			this->label7->BackColor = System::Drawing::Color::Transparent;
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
			// pictureBox5
			// 
			this->pictureBox5->Dock = System::Windows::Forms::DockStyle::Fill;
			this->pictureBox5->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox5.Image")));
			this->pictureBox5->Location = System::Drawing::Point(0, 0);
			this->pictureBox5->Name = L"pictureBox5";
			this->pictureBox5->Size = System::Drawing::Size(1817, 1041);
			this->pictureBox5->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox5->TabIndex = 34;
			this->pictureBox5->TabStop = false;
			// 
			// navPanel
			// 
			this->navPanel->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(65)), static_cast<System::Int32>(static_cast<System::Byte>(65)),
				static_cast<System::Int32>(static_cast<System::Byte>(65)));
			this->navPanel->Controls->Add(this->label21);
			this->navPanel->Controls->Add(this->label20);
			this->navPanel->Controls->Add(this->label19);
			this->navPanel->Controls->Add(this->label17);
			this->navPanel->Controls->Add(this->label16);
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
			// label21
			// 
			this->label21->AutoSize = true;
			this->label21->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label21->ForeColor = System::Drawing::Color::White;
			this->label21->Location = System::Drawing::Point(14, 234);
			this->label21->Name = L"label21";
			this->label21->Size = System::Drawing::Size(59, 20);
			this->label21->TabIndex = 10;
			this->label21->Text = L"Stories";
			// 
			// label20
			// 
			this->label20->AutoSize = true;
			this->label20->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label20->ForeColor = System::Drawing::Color::White;
			this->label20->Location = System::Drawing::Point(21, 108);
			this->label20->Name = L"label20";
			this->label20->Size = System::Drawing::Size(43, 20);
			this->label20->TabIndex = 9;
			this->label20->Text = L"Chat";
			// 
			// label19
			// 
			this->label19->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->label19->AutoSize = true;
			this->label19->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label19->ForeColor = System::Drawing::Color::White;
			this->label19->Location = System::Drawing::Point(1, 965);
			this->label19->Name = L"label19";
			this->label19->Size = System::Drawing::Size(87, 15);
			this->label19->TabIndex = 8;
			this->label19->Text = L"Profile settings";
			// 
			// label17
			// 
			this->label17->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->label17->AutoSize = true;
			this->label17->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label17->ForeColor = System::Drawing::Color::White;
			this->label17->Location = System::Drawing::Point(2, 825);
			this->label17->Name = L"label17";
			this->label17->Size = System::Drawing::Size(80, 16);
			this->label17->TabIndex = 7;
			this->label17->Text = L"Add Contact";
			// 
			// label16
			// 
			this->label16->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->label16->AutoSize = true;
			this->label16->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label16->ForeColor = System::Drawing::Color::White;
			this->label16->Location = System::Drawing::Point(2, 674);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(83, 16);
			this->label16->TabIndex = 6;
			this->label16->Text = L"create group";
			// 
			// button7
			// 
			this->button7->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->button7->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button7.BackgroundImage")));
			this->button7->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->button7->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button7->FlatAppearance->BorderSize = 0;
			this->button7->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button7->Location = System::Drawing::Point(10, 623);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(63, 60);
			this->button7->TabIndex = 5;
			this->button7->UseVisualStyleBackColor = true;
			this->button7->Click += gcnew System::EventHandler(this, &GuiForm::button7_Click);
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
			// goToAddContact_btn
			// 
			this->goToAddContact_btn->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->goToAddContact_btn->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"goToAddContact_btn.BackgroundImage")));
			this->goToAddContact_btn->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->goToAddContact_btn->Cursor = System::Windows::Forms::Cursors::Hand;
			this->goToAddContact_btn->FlatAppearance->BorderSize = 0;
			this->goToAddContact_btn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->goToAddContact_btn->Location = System::Drawing::Point(12, 757);
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
			this->statusButton->Location = System::Drawing::Point(11, 164);
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
			this->profileButton->Location = System::Drawing::Point(6, 899);
			this->profileButton->Name = L"profileButton";
			this->profileButton->Size = System::Drawing::Size(75, 63);
			this->profileButton->TabIndex = 2;
			this->profileButton->UseVisualStyleBackColor = true;
			this->profileButton->Click += gcnew System::EventHandler(this, &GuiForm::profileButton_Click);
			// 
			// storyPanel
			// 
			this->storyPanel->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(45)), static_cast<System::Int32>(static_cast<System::Byte>(45)),
				static_cast<System::Int32>(static_cast<System::Byte>(45)));
			this->storyPanel->Controls->Add(this->allStoriesPanel);
			this->storyPanel->Controls->Add(this->stotyHeaderPanel);
			this->storyPanel->Dock = System::Windows::Forms::DockStyle::Fill;
			this->storyPanel->Location = System::Drawing::Point(0, 0);
			this->storyPanel->Name = L"storyPanel";
			this->storyPanel->Size = System::Drawing::Size(1904, 1041);
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
			this->allStoriesPanel->Size = System::Drawing::Size(1904, 941);
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
			this->stotyHeaderPanel->Size = System::Drawing::Size(1904, 100);
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
			this->button2->Location = System::Drawing::Point(1770, 12);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 53);
			this->button2->TabIndex = 12;
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &GuiForm::button2_Click);
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
			this->addStoryPanel->Cursor = System::Windows::Forms::Cursors::Hand;
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
			this->button6->Location = System::Drawing::Point(1615, 13);
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
			this->button5->Location = System::Drawing::Point(1789, 15);
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
			this->button4->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button4->FlatAppearance->BorderSize = 0;
			this->button4->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button4->Location = System::Drawing::Point(1798, 957);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(64, 64);
			this->button4->TabIndex = 2;
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &GuiForm::button4_Click);
			// 
			// textStory
			// 
			this->textStory->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->textStory->BackColor = System::Drawing::Color::DimGray;
			this->textStory->Font = (gcnew System::Drawing::Font(L"Sans Serif Collection", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textStory->Location = System::Drawing::Point(3, 81);
			this->textStory->Multiline = true;
			this->textStory->Name = L"textStory";
			this->textStory->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->textStory->Size = System::Drawing::Size(1901, 864);
			this->textStory->TabIndex = 1;
			this->textStory->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
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
			// getStoryPanel
			// 
			this->getStoryPanel->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(45)), static_cast<System::Int32>(static_cast<System::Byte>(45)),
				static_cast<System::Int32>(static_cast<System::Byte>(45)));
			this->getStoryPanel->Controls->Add(this->bodyOfTheStoryPanel);
			this->getStoryPanel->Controls->Add(this->footerOfTheSroryPanel);
			this->getStoryPanel->Controls->Add(this->profileUserInStoryPanel);
			this->getStoryPanel->Dock = System::Windows::Forms::DockStyle::Fill;
			this->getStoryPanel->Location = System::Drawing::Point(0, 0);
			this->getStoryPanel->Name = L"getStoryPanel";
			this->getStoryPanel->Size = System::Drawing::Size(1904, 1041);
			this->getStoryPanel->TabIndex = 14;
			// 
			// bodyOfTheStoryPanel
			// 
			this->bodyOfTheStoryPanel->Controls->Add(this->bodyOfTheStoryLabel);
			this->bodyOfTheStoryPanel->Dock = System::Windows::Forms::DockStyle::Fill;
			this->bodyOfTheStoryPanel->Location = System::Drawing::Point(0, 128);
			this->bodyOfTheStoryPanel->Name = L"bodyOfTheStoryPanel";
			this->bodyOfTheStoryPanel->Size = System::Drawing::Size(1904, 823);
			this->bodyOfTheStoryPanel->TabIndex = 1;
			// 
			// bodyOfTheStoryLabel
			// 
			this->bodyOfTheStoryLabel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->bodyOfTheStoryLabel->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(45)),
				static_cast<System::Int32>(static_cast<System::Byte>(45)), static_cast<System::Int32>(static_cast<System::Byte>(45)));
			this->bodyOfTheStoryLabel->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->bodyOfTheStoryLabel->Cursor = System::Windows::Forms::Cursors::IBeam;
			this->bodyOfTheStoryLabel->Location = System::Drawing::Point(0, 0);
			this->bodyOfTheStoryLabel->Name = L"bodyOfTheStoryLabel";
			this->bodyOfTheStoryLabel->ReadOnly = true;
			this->bodyOfTheStoryLabel->ScrollBars = System::Windows::Forms::RichTextBoxScrollBars::Vertical;
			this->bodyOfTheStoryLabel->Size = System::Drawing::Size(1904, 823);
			this->bodyOfTheStoryLabel->TabIndex = 3;
			this->bodyOfTheStoryLabel->Text = L"";
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
			this->viewerOfTheStoryBtn->Location = System::Drawing::Point(952, 28);
			this->viewerOfTheStoryBtn->Name = L"viewerOfTheStoryBtn";
			this->viewerOfTheStoryBtn->Size = System::Drawing::Size(93, 42);
			this->viewerOfTheStoryBtn->TabIndex = 0;
			this->viewerOfTheStoryBtn->UseVisualStyleBackColor = true;
			this->viewerOfTheStoryBtn->Click += gcnew System::EventHandler(this, &GuiForm::viewerOfTheStoryBtn_Click);
			// 
			// profileUserInStoryPanel
			// 
			this->profileUserInStoryPanel->Controls->Add(this->moreButton);
			this->profileUserInStoryPanel->Controls->Add(this->storyProgressBar);
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
			// moreButton
			// 
			this->moreButton->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->moreButton->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"moreButton.BackgroundImage")));
			this->moreButton->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->moreButton->FlatAppearance->BorderSize = 0;
			this->moreButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->moreButton->ForeColor = System::Drawing::Color::DarkCyan;
			this->moreButton->Location = System::Drawing::Point(1799, 61);
			this->moreButton->Name = L"moreButton";
			this->moreButton->Size = System::Drawing::Size(93, 52);
			this->moreButton->TabIndex = 4;
			this->moreButton->UseVisualStyleBackColor = true;
			this->moreButton->Click += gcnew System::EventHandler(this, &GuiForm::moreButton_Click);
			// 
			// storyProgressBar
			// 
			this->storyProgressBar->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->storyProgressBar->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(45)), static_cast<System::Int32>(static_cast<System::Byte>(45)),
				static_cast<System::Int32>(static_cast<System::Byte>(45)));
			this->storyProgressBar->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->storyProgressBar->Location = System::Drawing::Point(529, 115);
			this->storyProgressBar->Name = L"storyProgressBar";
			this->storyProgressBar->Size = System::Drawing::Size(610, 10);
			this->storyProgressBar->Step = 1;
			this->storyProgressBar->Style = System::Windows::Forms::ProgressBarStyle::Continuous;
			this->storyProgressBar->TabIndex = 3;
			// 
			// cancelStoryBtn
			// 
			this->cancelStoryBtn->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->cancelStoryBtn->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"cancelStoryBtn.BackgroundImage")));
			this->cancelStoryBtn->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->cancelStoryBtn->FlatAppearance->BorderSize = 0;
			this->cancelStoryBtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->cancelStoryBtn->ForeColor = System::Drawing::Color::DarkCyan;
			this->cancelStoryBtn->Location = System::Drawing::Point(1799, 3);
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
			this->profileStoryPic->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"profileStoryPic.BackgroundImage")));
			this->profileStoryPic->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->profileStoryPic->Dock = System::Windows::Forms::DockStyle::Left;
			this->profileStoryPic->Location = System::Drawing::Point(0, 0);
			this->profileStoryPic->Name = L"profileStoryPic";
			this->profileStoryPic->Size = System::Drawing::Size(99, 128);
			this->profileStoryPic->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->profileStoryPic->TabIndex = 0;
			this->profileStoryPic->TabStop = false;
			// 
			// SignINPnl
			// 
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
			// 
			// button8
			// 
			this->button8->BackColor = System::Drawing::Color::Cyan;
			this->button8->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button8->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button8->Location = System::Drawing::Point(1488, 830);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(206, 80);
			this->button8->TabIndex = 9;
			this->button8->Text = L"Sign In →";
			this->button8->UseVisualStyleBackColor = false;
			this->button8->Click += gcnew System::EventHandler(this, &GuiForm::signInButton_Click);
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->BackColor = System::Drawing::Color::Transparent;
			this->label10->Cursor = System::Windows::Forms::Cursors::Hand;
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
			this->numLbl->Location = System::Drawing::Point(727, 462);
			this->numLbl->Name = L"numLbl";
			this->numLbl->Size = System::Drawing::Size(161, 25);
			this->numLbl->TabIndex = 4;
			this->numLbl->Text = L"Phone Number:";
			// 
			// phoneTxt
			// 
			this->phoneTxt->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->phoneTxt->Location = System::Drawing::Point(937, 459);
			this->phoneTxt->Name = L"phoneTxt";
			this->phoneTxt->Size = System::Drawing::Size(176, 38);
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
			this->signinBackGround->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"signinBackGround.Image")));
			this->signinBackGround->InitialImage = nullptr;
			this->signinBackGround->Location = System::Drawing::Point(0, 0);
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
			// storyProgressBarTimer
			// 
			this->storyProgressBarTimer->Interval = 16;
			this->storyProgressBarTimer->Tick += gcnew System::EventHandler(this, &GuiForm::storyProgressBarTimer_Tick);
			// 
			// deleteStoryTimer
			// 
			this->deleteStoryTimer->Interval = 30000;
			this->deleteStoryTimer->Tick += gcnew System::EventHandler(this, &GuiForm::deleteStoryTimer_Tick);
			// 
			// GuiForm
			// 
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
			this->ClientSize = System::Drawing::Size(1904, 1041);
			this->Controls->Add(this->SignINPnl);
			this->Controls->Add(this->getStoryPanel);
			this->Controls->Add(this->addStoryPanel);
			this->Controls->Add(this->mainPanel);
			this->Controls->Add(this->signUpPnl);
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
			this->chatPnl->ResumeLayout(false);
			this->currentCahtPanel->ResumeLayout(false);
			this->chatsContainer->ResumeLayout(false);
			this->headerContainer->ResumeLayout(false);
			this->headerContainer->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->removeMemPicBox))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->addMemPicBox))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chatPicture))->EndInit();
			this->footerContainer->ResumeLayout(false);
			this->contactsPanelContainer->ResumeLayout(false);
			this->searchContactPanel->ResumeLayout(false);
			this->searchContactPanel->PerformLayout();
			this->contentPanelsHolder->ResumeLayout(false);
			this->addMemberPnl->ResumeLayout(false);
			this->addMemberPnl->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->EndInit();
			this->addContactPanel->ResumeLayout(false);
			this->addContactPanel->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->EndInit();
			this->profilePanel->ResumeLayout(false);
			this->profilePanel->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->userPhotoPictureBox))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->removeMemberPnl->ResumeLayout(false);
			this->removeMemberPnl->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox6))->EndInit();
			this->addGroup->ResumeLayout(false);
			this->addGroup->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->groupImgPicBox))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox5))->EndInit();
			this->navPanel->ResumeLayout(false);
			this->navPanel->PerformLayout();
			this->storyPanel->ResumeLayout(false);
			this->stotyHeaderPanel->ResumeLayout(false);
			this->stotyHeaderPanel->PerformLayout();
			this->addStoryPanel->ResumeLayout(false);
			this->addStoryPanel->PerformLayout();
			this->getStoryPanel->ResumeLayout(false);
			this->bodyOfTheStoryPanel->ResumeLayout(false);
			this->footerOfTheSroryPanel->ResumeLayout(false);
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
			
			loadFromFile(users, chatRooms, messages,stories,contacts);


			//for (auto m : messages) {
			//	cout << "Message ID: " << m.first << endl;
			//	cout << "Message Text: " << m.second.getText() << endl;
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
			//cout << "Users Number: " << users.size() << endl;
			for (auto u : users) {
				cout << u.second.getMobileNumber() << endl;
				cout << u.second.getFirstName() << endl;
				cout << u.second.getLastName() << endl;
				cout << u.second.getPassword() << endl;
				cout << u.second.getProfilePhoto() << endl;
				cout << u.second.getVisible() << endl;
				for(auto &c: u.second.getContactsPhones()){
                    cout << "contact ID: " << c.first << endl;
				}
				cout << endl;
			}

		
			// clear the chat rooms and contacts of the users
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
			//users.clear();
			//stories.clear();

			//messages.clear();
			//for (auto &chat : chatRooms) {
			//	chat.second.clearMessages();
			//}
			//users.clear();


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
			chatRoomHandler.otherUser = &otherUser;
			chatRoomHandler.buttons = buttons;


			handler.globalMessages = &messages;
			handler.globalChatRoom = &currentChatRoom;
			handler.currentUser = &currentUser;
			handler.messagesContainer = messagesFlowPanelsContainer;
			handler.users = &users;
			handler.otherUser = &otherUser;



			chatRoomHandler.messageHandler.globalMessages = &messages;
			chatRoomHandler.messageHandler.globalChatRoom = &currentChatRoom;
			chatRoomHandler.messageHandler.currentUser = &currentUser;
			chatRoomHandler.messageHandler.messagesContainer = messagesFlowPanelsContainer;
			chatRoomHandler.messageHandler.users = &users;
			chatRoomHandler.messageHandler.otherUser = &otherUser;


			storyHandler.currentUser = &currentUser;
			storyHandler.viewerOfTheStoryBtn = viewerOfTheStoryBtn;
			storyHandler.users = &users;
			storyHandler.nameInStoryLabel = nameInStoryLabel;
			storyHandler.storiesIDTemp = &storiesIDTemp;
			storyHandler.stories = &stories;
			storyHandler.bodyOfTheStoryLabel = bodyOfTheStoryLabel;
			storyHandler.dateInStoryLabel = dateInStoryLabel;
			storyHandler.bodyOfTheStoryLabel = bodyOfTheStoryLabel;
			storyHandler.getStoryPanel = getStoryPanel;
			storyHandler.addStoryPanel = addStoryPanel;
			storyHandler.mainPanel = mainPanel;
			storyHandler.storyProgressBar = storyProgressBar;
			storyHandler.storyProgressBarTimer = storyProgressBarTimer;
			storyHandler.storyTimerTemp = storyTimerTemp;
			storyHandler.storiesIDTemp = &storiesIDTemp;
			storyHandler.textStory = textStory;
			storyHandler.allStoriesPanel = allStoriesPanel;
			storyHandler.fontDialog = fontDialog;
			storyHandler.colorDialog = colorDialog;
			storyHandler.storyPanel = storyPanel;
			storyHandler.bodyOfTheStoryPanel = bodyOfTheStoryPanel;
			storyHandler.profileStoryPic = profileStoryPic;
			storyHandler.moreButton = moreButton;

			//users.clear();
			//chatRooms.clear();
			//stories.clear();
			//messages.clear();
			//chatRooms.clear();

		}

		private: System::Void signUpButton_Click(System::Object^ sender, System::EventArgs^ e) {		
			

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
			if(filename != "User.png" && selectedImagePath != destinationPath)
				File::Copy(selectedImagePath, destinationPath, true);

			signUp(mobileNumber, password, firstName, lastName, users, filename);

			MessageBox::Show("Signed Up successfully", "Signed Up");

			String^ defalutImagePath = Path::Combine(imagesFolder, "User.png");


			SignINPnl->BringToFront();
			pictureBox2->Image = Image::FromFile(defalutImagePath);
			fileName = "User.png";
			fnTxt->Clear();
			lnTxt->Clear();
			pasTxt->Clear();
			numTxt->Clear();
		}
		
		//todo signin button
		private: System::Void signInButton_Click(System::Object^ sender, System::EventArgs^ e) {
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
				//? the current user
				currentUser = &users[mobileNumber];
				cout << "the current user phone is " << currentUser->getMobileNumber()<<endl;
				//? delete the stories expired after one day
				deleteStoriesAfterOneDay();
				deleteStoryTimer->Start();

				//? load the stories 
				loadStories(mobileNumber);
				
				messagesFlowPanelsContainer->Controls->Clear();
				contactsPanel->Controls->Clear();
				buttons->Clear();

				for(int chatRoom: currentUser->getChatRoomsID()){

					FlowLayoutPanel^ chatRoomPanel = chatRoomHandler.createChatRoomGUI(chatRoom, messagesFlowPanelsContainer);

					bool currentUserIsFirst = 0;
					if (chatRooms[chatRoom].getUsersID()[0] == currentUser->getMobileNumber()) {
						currentUserIsFirst = 1;
					}

					if (chatRooms[chatRoom].getIsDual())
					{
						if (currentUserIsFirst) {
							otherUser = &users[chatRooms[chatRoom].getUsersID()[1]];
						}else
							otherUser = &users[chatRooms[chatRoom].getUsersID()[0]];

					}

					handler.initializeChat(&chatRooms[chatRoom], chatRoomPanel, messages, currentUser, Activity, &users);

					if (chatRooms[chatRoom].getIsDual())
					{

						//string filename = msclr::interop::marshal_as<std::string>(fileName->ToString());
						/*if (filename != "User.png")
							File::Copy(selectedImagePath, destinationPath, true);*/

						if(currentUserIsFirst)
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
				if (currentUser->getVisible())
					visibleLabel->Text = "True";
				else
					visibleLabel->Text = "False";

                firstNameLabel->Text = gcnew System::String(currentUser->getFirstName().c_str());
				lastNameLabel->Text = gcnew System::String(currentUser->getLastName().c_str());
				aboutLabel->Text = gcnew System::String(currentUser->getAbout().c_str());
				phoneNumberLabel->Text = gcnew System::String(currentUser->getMobileNumber().c_str());

				String^ destinationPath = Path::Combine(imagesFolder, gcnew String(currentUser->getProfilePhoto().c_str()));
				userPhotoPictureBox->Image = Image::FromFile(destinationPath);
			}
	
		}


		private: System::Void sendButton_Click(System::Object^ sender, System::EventArgs^ e) {
			handler.createMessageEvent(textBox1, chatRoomsPanels[currentChatRoom->getChatRoomID()], currentUser, Activity, contactsPanel, chatRooms, currentChatRoom, messages, &users);
		}
			   
		private: System::Void GuiForm_FormClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e) {
		
			/*users.clear();
			chatRooms.clear();
			messages.clear();
			contacts.clear();
			stories.clear();*/

			saveToFile(users, chatRooms, messages,stories,contacts);
		}
			   //?/shehab
		private: System::Void chatButton_Click(System::Object^ sender, System::EventArgs^ e) {

		}
		private: System::Void chatButton_Click_1(System::Object^ sender, System::EventArgs^ e) {
			chatPnl->BringToFront();
		}
		private: System::Void statusButton_Click(System::Object^ sender, System::EventArgs^ e) {
			deleteStoriesAfterOneDay();
			storyPanel->BringToFront();
		}
		private: System::Void profileButton_Click(System::Object^ sender, System::EventArgs^ e) {
			contentPanelsHolder->BringToFront();
			profilePanel->BringToFront();
		}
		private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
			addStoryPanel->BringToFront();
			textStory->Clear();
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
				//this->addStoryPanel->BackColor = colorDialog->Color;
				this->textStory->BackColor = colorDialog->Color;
			}
			storyHandler.colorDialog = colorDialog;
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
			storyHandler.fontDialog = fontDialog;


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
				//if (groupFileName != "User.png")
				//	File::Copy(selectedImagePath, destinationPath, true);

				string contName = msclr::interop::marshal_as<std::string>(addContName_field->Text);
				chatRoomHandler.createRoom(currentContNum,contName,currentUser, addContName_field, addContNum_field, chatRooms, contactsPanel,Activity, messagesFlowPanelsContainer, users,groupFilename,messages);
				sortChatRooms(*currentUser, Activity, chatRooms, contactsPanel, messages);
			
			}
		}


		//? /shehab
		private: System::Void goToAddContact_btn_Click(System::Object^ sender, System::EventArgs^ e) {
			contentPanelsHolder->BringToFront();
			addContactPanel->BringToFront();
		}
	
		private: System::Void cancelStoryBtn_Click(System::Object^ sender, System::EventArgs^ e) {
			mainPanel->BringToFront();
			storyPanel->BringToFront();
		}

		
		//?shehab/
		private: System::Void singOutButton_Click(System::Object^ sender, System::EventArgs^ e) {
			allStoriesPanel->Controls->Clear();
			SignINPnl->BringToFront();
			chatPnl->BringToFront();
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


				if (!Directory::Exists(imagesFolder))
					Directory::CreateDirectory(imagesFolder);

				groupImageDestinationPath = Path::Combine(imagesFolder, groupFileName);

				if(selectedGroupImagePath != groupImageDestinationPath)
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
			contentPanelsHolder->BringToFront();
			usersListBox->Items->Clear();
			for (auto& contact : currentUser->getContactsPhones()) {
				String^ name = gcnew String(contact.second.c_str());
				String^ number = gcnew String(contact.first.c_str());
				usersListBox->Items->Add(number + " (" + name + ")");
			}
		}

		private: System::Void button10_Click(System::Object^ sender, System::EventArgs^ e) {
			SignINPnl->BringToFront();
			fnTxt->Clear();
			lnTxt->Clear();
			pasTxt->Clear();
			numTxt->Clear();
		}
		private: System::Void label10_Click(System::Object^ sender, System::EventArgs^ e) {
			signUpPnl->BringToFront();
		}

	/*private: System::Void progressBar1_Click(System::Object^ sender, System::EventArgs^ e) {
	}*/

		private: System::Void button11_Click(System::Object^ sender, System::EventArgs^ e) {
			string memNum = msclr::interop::marshal_as<std::string>(memPhone->Text);
			if (memNum.size() < 11 || memNum.size() > 11) {
				MessageBox::Show("Phone number must be 11 digits", "Error");
			}
			else {
				// Check if the contact already exists
				if (checkUserExist(memNum, users, currentContName)) {

					currentContNum = memNum;
					memNameLbl->Visible = true;
					memName->Visible = true;
					addMem->Visible = true;
					memName->Text = gcnew System::String(currentContName.c_str());
				}
				else {
					MessageBox::Show("User does not exist", "Error");
				}
			}
		}
		private: System::Void addMem_Click_1(System::Object^ sender, System::EventArgs^ e) {
			string contNum = msclr::interop::marshal_as<std::string>(memPhone->Text);
			memNameLbl->Visible = false;
			memName->Visible = false;
			addMem->Visible = false;
			if (checkMemberExist(contNum, currentChatRoom)) {
				MessageBox::Show("This user is already a member", "Error");
			}
			else {
				string groupFilename = msclr::interop::marshal_as<std::string>(groupFileName->ToString());
				chatRoomHandler.addMember(currentChatRoom->getChatRoomID(), contNum, users, chatRooms);
				MessageBox::Show("Member added successfully", "Success");
				chatPnl->BringToFront();
			}

		}
        
		private: System::Void addMemPicBox_Click(System::Object^ sender, System::EventArgs^ e) {
			contentPanelsHolder->BringToFront();
			addMemberPnl->BringToFront();
		}


		private: System::Void removeMemPicBox_Click(System::Object^ sender, System::EventArgs^ e) {
			contentPanelsHolder->BringToFront();
			removeMemberPnl->BringToFront();
			GroupMem->Items->Clear();
			for (auto& members : currentChatRoom->getUsersID()) {
				if (members == currentUser->getMobileNumber())
					continue;
				String^ number = gcnew String(members.c_str());
				string name0 = users[members].getFirstName() + " " + users[members].getLastName();
				String^ name = gcnew String(name0.c_str());
				GroupMem->Items->Add(number + " (" + name + ")");
			}
		}

		private: System::Void removeBtn_Click(System::Object^ sender, System::EventArgs^ e) {
			//check if user did not check anythibg in listbox
			if (GroupMem->SelectedItems->Count == 0) {
				MessageBox::Show("Please select a member to remove", "Error");
				return;
			}
			else {
				chatRoomHandler.removeMember(currentChatRoom->getChatRoomID(), users, chatRooms,GroupMem);
				chatPnl->BringToFront();
			}
		}

		private: System::Void editVisibility_Click(System::Object^ sender, System::EventArgs^ e) {
			editClick(visibilityComboBox, submitVisibleButton);
		}
        private: System::Void submitVisibleButton_Click(System::Object^ sender, System::EventArgs^ e) {
			submitVisibility(visibilityComboBox, submitVisibleButton, visibleLabel, currentUser);
        }

		private: System::Void editFirstNameButton_Click(System::Object^ sender, System::EventArgs^ e) {
			editClick(newFirstNameTextBox, submitFirstNameButton);
		}
		private: System::Void submitFirstNameButton_Click(System::Object^ sender, System::EventArgs^ e) {
			changeName(newFirstNameTextBox, submitFirstNameButton, firstNameLabel, currentUser, 1);
		}

		private: System::Void editLastNameButton_Click(System::Object^ sender, System::EventArgs^ e) {
			editClick(newLastNameTextBox, submitLastNameButton);
		}
		private: System::Void submitLastNameButton_Click(System::Object^ sender, System::EventArgs^ e) {
			changeName(newLastNameTextBox, submitLastNameButton, lastNameLabel, currentUser, 2);
		}

		private: System::Void editPasswordButton_Click(System::Object^ sender, System::EventArgs^ e) {
			editClick(newPasswordTextBox, submitPasswordButton);
		}
		private: System::Void submitPasswordButton_Click(System::Object^ sender, System::EventArgs^ e) {
			changePassword(newPasswordTextBox, submitPasswordButton, currentUser);
		}

		private: System::Void editAboutButton_Click(System::Object^ sender, System::EventArgs^ e) {
			editClick(newAboutRichTextBox, submitNewAboutButton);
		}
		private: System::Void submitNewAboutButton_Click(System::Object^ sender, System::EventArgs^ e) {
			changeAbout(newAboutRichTextBox, submitNewAboutButton, aboutLabel, currentUser);
		}

		private: System::Void editPhotoButton_Click(System::Object^ sender, System::EventArgs^ e) {
			changePhoto(userPhotoPictureBox, imagesFolder, currentUser);
		};
		
		private: System::Void searchChatroom_field_TextChanged(System::Object^ sender, System::EventArgs^ e) {
			string searchText = msclr::interop::marshal_as<std::string>(searchChatroom_field->Text);
			if (searchText == "") {
				updateChatPanel(buttons, contactsPanel);
			}
			else {
				searchChatRooms(searchText, contactsPanel,buttons);
			}
			sortChatRooms(*currentUser, Activity, chatRooms, contactsPanel, messages);
		}





		//todo timer call the delete function every 0.5 mintues to achive the live delete
		private: System::Void deleteStoryTimer_Tick(System::Object^ sender, System::EventArgs^ e) {
			deleteStoriesAfterOneDay();
		}

		//todo load the storiis
		private:System::Void loadStories(string mobileNumber) {

			//! get all the stories of the user and his freinds when sign in
			
			if (currentUser->getStoriesID().size() > 0) {
				createUserStoryPanel(*currentUser);
			}
			unordered_map<string, string> friendsContacts = currentUser->getContactsPhones();
			for (auto contact : friendsContacts) {
				User freind = users.at(contact.first);
				auto ContactsOfTheUserFreind = freind.getContactsPhones();
				if (ContactsOfTheUserFreind.find(currentUser->getMobileNumber()) != ContactsOfTheUserFreind.end()) { //? that means that iam in the freind contact too
					if (freind.getStoriesID().size() > 0) {
						createUserStoryPanel(freind);
					}
				}

			}
			
		}





	 // ----------------------------------shehab functions-----------------------------------------------------
		//todo delete stories after 24 hours but now 2 min for test
		void deleteStoriesAfterOneDay() {
			storyHandler.deleteStoriesAfterOneDay();
		}

		//todo story progess bar
		private: System::Void storyProgressBarTimer_Tick(System::Object^ sender, System::EventArgs^ e) {
			//! Increment the progress bar
			if (storyProgressBar->Value < storyProgressBar->Maximum) {
				storyProgressBar->Value += 1;
			}
		}
		  
		//todo story timer to loop on the all stories
		private: System::Void storyTimerTemp_Tick(System::Object^ sender, System::EventArgs^ e) {
			storyHandler.storyTimerTemp_Tick();
		}

		//todo Convert the time_t as seconds to (hh-mm)
		string formatTimeToHHMM(time_t t_time) {
			return storyHandler.formatTimeToHHMM(t_time);
		}

		//todo  viewer of the story
		private: System::Void viewerOfTheStoryBtn_Click(System::Object^ sender, System::EventArgs^ e) {
			storyHandler.viewerOfTheStoryBtn_Click();

		}

		//todo create story in gui  
		private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {

			storyHandler.button4_Click();
		}

		//todo click on the story panel to show stories 
		private: System::Void userStoryPanel_Click(System::Object^ sender, System::EventArgs^ e) {

			storyHandler.userStoryPanel_Click(sender, e);
			
		}

		//todo create story panle
		private: System::Void createUserStoryPanel(User& currentUser) {

			storyHandler.createUserStoryPanel(currentUser);
		}

		//todo create story
		private: System::Void createStory(User& currentUser) {
			
			storyHandler.createStory(currentUser);
		}

		private: System::Void moreButton_Click(System::Object^ sender, System::EventArgs^ e) {
			storyHandler.moreButton_Click();
		}
			   //todo load the storiis
		//private:System::Void loadStories(string mobileNumber) {

		//	storyHandler.loadStories(mobileNumber);

		//}
};

};

