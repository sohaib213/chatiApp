#pragma once
#include "User.h"
#include <msclr/marshal_cppstd.h>
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <unordered_map>
#include "Message.h"
#include "Story.h"
#include <sstream>
#include <iomanip>


using namespace System::Collections::Generic;
using namespace std;
using namespace System::IO;
using namespace System::Drawing;
using namespace System;
using namespace System::Globalization;
using namespace System::Windows::Forms;



public ref class StoryHandler {

public:

	User** currentUser;
	Button^ viewerOfTheStoryBtn;
	unordered_map<string, User>* users;
	Label^ nameInStoryLabel;
	unordered_map<int, Story>* stories;
	RichTextBox^ bodyOfTheStoryLabel;
	Label^ dateInStoryLabel;
	Panel^ bodyOfTheStoryPanel, ^ getStoryPanel, ^ addStoryPanel, ^ mainPanel, ^ storyPanel;
	ProgressBar^ storyProgressBar;
	Timer^ storyProgressBarTimer, ^ storyTimerTemp;
	set<int>* storiesIDTemp;
	TextBox^ textStory;
	FlowLayoutPanel^ allStoriesPanel;
	FontDialog^ fontDialog;
	ColorDialog^ colorDialog;
	String^ projectRoot = Directory::GetParent(Application::StartupPath)->Parent->FullName;
	String^ imagesFolder = Path::Combine(projectRoot, "usersImages");
	PictureBox^ profileStoryPic;


	void deleteStoriesAfterOneDay() {
		//! the current time to compare 
		time_t now = time(0);

		//! list of panels that will be deleted 
		System::Collections::Generic::List<Panel^>^ panelsToRemove = gcnew System::Collections::Generic::List<Panel^>();

		for (auto& user : *users) {
			set<int> storiesID = user.second.getStoriesID();
			for (auto& storyID : storiesID) {
				if (now - (*stories)[storyID].getPublishTime() > 120) { // 86400 seconds in a day
					user.second.removeStory(storyID);
					stories->erase(storyID);
					storiesIDTemp->erase(storyID);
				}
			}

			//! check if the user has no stories
			if (user.second.getStoriesID().size() == 0) {
				//! loop to collect the panel, but not remove directly
				for each (Control ^ control in allStoriesPanel->Controls) {
					Panel^ userStoryPanel = dynamic_cast<Panel^>(control);
					if (userStoryPanel != nullptr && userStoryPanel->Tag != nullptr) {
						System::String^ mobileStr = dynamic_cast<System::String^>(userStoryPanel->Tag);
						if (mobileStr != nullptr && mobileStr == gcnew System::String(user.second.getMobileNumber().c_str())) {
							panelsToRemove->Add(userStoryPanel);
							break;
						}
					}
				}
			}
		}

		//! remove panels safely after the loop
		for each (Panel ^ panel in panelsToRemove) {
			allStoriesPanel->Controls->Remove(panel);
		}
	}

	void storyTimerTemp_Tick() {
		//! First stop the progress bar timer to prevent any further updates
		storyProgressBarTimer->Stop();

		//? show the stories temporarily
		if (storiesIDTemp->size() > 0) {
			//! Reset progress bar
			storyProgressBar->Value = 0;

			auto begin = storiesIDTemp->begin();
			Story currentStory = (*stories)[*begin];
			currentStory.setViewsCounter((*currentUser)->getMobileNumber());
			(*stories)[currentStory.getStoryID()] = currentStory;

			//? initilize the label with the text of the story
			string textShown = currentStory.getStoryText();
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

			cout << "Color Of Story 1: " << currentStory.getColorHex() << endl;

			//! set the font and the color to the label
			bodyOfTheStoryLabel->BackColor = storyColorTemp;
			bodyOfTheStoryLabel->Font = fontStoryTemp;

			bool endsWithNewLine = bodyOfTheStoryLabel->Text->EndsWith("\n");
			if (!endsWithNewLine) {
				bodyOfTheStoryLabel->AppendText("\n");
			}

			bodyOfTheStoryLabel->SelectAll();
			bodyOfTheStoryLabel->SelectionBackColor = storyColorTemp;
			bodyOfTheStoryLabel->SelectionAlignment = System::Windows::Forms::HorizontalAlignment::Center;
			bodyOfTheStoryLabel->DeselectAll();


			//! Start the progress bar timer AFTER setting up the new story
			storyProgressBarTimer->Start();

			storiesIDTemp->erase(begin);
		}
		else {
			//! No more stories, clean up
			storyTimerTemp->Stop();
			storyProgressBar->Value = 0;
			storyProgressBarTimer->Stop();
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

	void viewerOfTheStoryBtn_Click() {
		//? stop the timers when he clik on the view button
		storyProgressBarTimer->Stop();
		storyTimerTemp->Stop();

		//? get the current story
		if (!storiesIDTemp->empty()) {
			auto begin = storiesIDTemp->begin();
			Story story = (*stories)[*begin];

			String^ storyCounterString = gcnew System::String(story.getViewsCounter().ToString());

			MessageBox::Show(storyCounterString, "Story Views", MessageBoxButtons::OK);
		}
		else {
			MessageBox::Show("0", "Story Views", MessageBoxButtons::OK);
		}

		storyProgressBarTimer->Start();
		storyTimerTemp->Start();
	}

	void button4_Click() {
		string textStoryString = msclr::interop::marshal_as<std::string>(textStory->Text);
		if (textStoryString == "") {
			MessageBox::Show("Please fill the story text", "Infromation incompleted");
			return;
		}
		cout << "the number of the stories: " << (*currentUser)->getStoriesID().size() << " for " << (*currentUser)->getFirstName() << endl;
		if ((*currentUser)->getStoriesID().size() == 0) {
			createUserStoryPanel(**currentUser);
		}
		createStory(**currentUser);
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

	void userStoryPanel_Click(System::Object^ sender, System::EventArgs^ e) {

		Button^ clickedPanel;
		System::String^ managedTypeName = sender->GetType()->Name;
		std::string s = msclr::interop::marshal_as<std::string>(managedTypeName);
		int chatRoomID;
		if (s == "Button")
		{
			clickedPanel = dynamic_cast<Button^>(sender);
		}
		else if (s == "Label") {
			Label^ label = dynamic_cast<Label^>(sender);
			clickedPanel = dynamic_cast<Button^>(label->Parent);
		}
		else if (s == "PictureBox") {
			PictureBox^ picture = dynamic_cast<PictureBox^>(sender);
			clickedPanel = dynamic_cast<Button^>(picture->Parent);
		}


		//Button^ clickedPanel = dynamic_cast<Button^>(sender);
		if (clickedPanel == nullptr) return;

		//? Get the mobile number from the Tag
		System::String^ mobileStr = dynamic_cast<System::String^>(clickedPanel->Tag);
		if (mobileStr == nullptr) return;

		std::string mobileNumber = msclr::interop::marshal_as<std::string>(mobileStr);
		//? make the viewer button invisible for the non-owner user
		if ((*currentUser)->getMobileNumber() != mobileNumber) {
			viewerOfTheStoryBtn->Visible = false;
		}
		else {
			viewerOfTheStoryBtn->Visible = true;
		}

		//? get the current user of the panel cliked
		User CurrentUser = (*users)[mobileNumber];

		//? get the all info of the user (name + stories)
		string name = CurrentUser.getFirstName() + " " + CurrentUser.getLastName();
		nameInStoryLabel->Text = gcnew System::String(name.c_str());
		*storiesIDTemp = CurrentUser.getStoriesID();


		// Make sure we have stories to show
		if ((*storiesIDTemp).size() == 0) {
			return;
		}

		//? get the first story
		//stories[*storiesIDTemp.begin()].setViewsCounter(currentUser->getMobileNumber());

		auto begin = (*storiesIDTemp).begin();
		Story currentStory = (*stories)[*begin];
		currentStory.setViewsCounter((*currentUser)->getMobileNumber());
		(*stories)[currentStory.getStoryID()] = currentStory;
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



		//? set the font and the color to the label
		bodyOfTheStoryLabel->Font = fontStoryTemp;
		bool endsWithNewLine = bodyOfTheStoryLabel->Text->EndsWith("\n");
		if (!endsWithNewLine) {
			bodyOfTheStoryLabel->AppendText("\n");
		}

		cout << "Color Of Story 2: " << currentStory.getColorHex() << endl;



		bodyOfTheStoryLabel->BackColor = storyColorTemp;
		bodyOfTheStoryLabel->SelectAll();
		bodyOfTheStoryLabel->SelectionBackColor = storyColorTemp;
		bodyOfTheStoryLabel->SelectionAlignment = System::Windows::Forms::HorizontalAlignment::Center;
		bodyOfTheStoryLabel->DeselectAll();

		
		String^ imagePath = Path::Combine(imagesFolder, gcnew String((*users)[mobileNumber].getProfilePhoto().c_str()));

		profileStoryPic->Image = Image::FromFile(imagePath);
		//? show the panel of the user story
		getStoryPanel->BringToFront();

		//? ProgressBar logic - ensure it's reset and started
		storyProgressBar->Value = 0;

		// Stop any existing timers first
		storyProgressBarTimer->Stop();
		storyTimerTemp->Stop();

		// Start the progress bar timer
		storyProgressBarTimer->Start();

		// Start the story timer
		storyTimerTemp->Start();

		//? erase the first story since we're showing it now
		storiesIDTemp->erase(begin);

	}

	void createUserStoryPanel(User& currentUser) {

		// Fix the problematic line
		PictureBox^ pictureUserStoryPic = gcnew PictureBox();

		//? Set the SizeMode to Zoom for the image to be zoomed correctly and fit within the PictureBox

		String^ imagePath = Path::Combine(imagesFolder, gcnew String(currentUser.getProfilePhoto().c_str()));

		pictureUserStoryPic->Image = Image::FromFile(imagePath);
		pictureUserStoryPic->SizeMode = PictureBoxSizeMode::Zoom;
		pictureUserStoryPic->Dock = System::Windows::Forms::DockStyle::Left;
		pictureUserStoryPic->InitialImage = nullptr;
		pictureUserStoryPic->Location = System::Drawing::Point(0, 0);
		pictureUserStoryPic->Name = L"pictureUserStoryPic";
		pictureUserStoryPic->Size = System::Drawing::Size(80, 80); // Adjust size as needed
		pictureUserStoryPic->BackColor = Color::Transparent;
		pictureUserStoryPic->TabIndex = 0;
		pictureUserStoryPic->TabStop = false;
		pictureUserStoryPic->MouseEnter += gcnew EventHandler(this, &StoryHandler::HoverEnter);
		pictureUserStoryPic->MouseLeave += gcnew EventHandler(this, &StoryHandler::HoverLeave);
		pictureUserStoryPic->Click += gcnew System::EventHandler(this, &StoryHandler::userStoryPanel_Click);


		//? name story panel
		Label^ nameUserStoryLabel = gcnew Label();
		nameUserStoryLabel->AutoSize = true;
		nameUserStoryLabel->BackColor = Color::Transparent;
		nameUserStoryLabel->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
		nameUserStoryLabel->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));
		nameUserStoryLabel->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
		nameUserStoryLabel->Location = System::Drawing::Point(116, 9);
		nameUserStoryLabel->Name = L"nameUserStoryLabel";
		nameUserStoryLabel->Size = System::Drawing::Size(101, 37);
		nameUserStoryLabel->TabIndex = 1;
		std::string fullName = currentUser.getFirstName() + " " + currentUser.getLastName();
		nameUserStoryLabel->Text = gcnew System::String(fullName.c_str());
		nameUserStoryLabel->MouseEnter += gcnew EventHandler(this, &StoryHandler::HoverEnter);
		nameUserStoryLabel->MouseLeave += gcnew EventHandler(this, &StoryHandler::HoverLeave);
		nameUserStoryLabel->Click += gcnew System::EventHandler(this, &StoryHandler::userStoryPanel_Click);


		//? label dateStoryPanel
		Label^ DateUserStoryLabel = gcnew Label();
		DateUserStoryLabel->AutoSize = true;
		DateUserStoryLabel->BackColor = Color::Transparent;
		DateUserStoryLabel->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
		DateUserStoryLabel->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));
		DateUserStoryLabel->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
		DateUserStoryLabel->Location = System::Drawing::Point(135, 64);
		DateUserStoryLabel->Name = L"DateUserStoryLabel";
		DateUserStoryLabel->Size = System::Drawing::Size(50, 24);
		DateUserStoryLabel->TabIndex = 2;
		DateUserStoryLabel->MouseEnter += gcnew EventHandler(this, &StoryHandler::HoverEnter);
		DateUserStoryLabel->MouseLeave += gcnew EventHandler(this, &StoryHandler::HoverLeave);
		DateUserStoryLabel->Click += gcnew System::EventHandler(this, &StoryHandler::userStoryPanel_Click);

		set<int>CurrentUserStoriesID = currentUser.getStoriesID();
		if (CurrentUserStoriesID.size() > 0) {
			auto lastStoryIDite = --CurrentUserStoriesID.end();
			int lastStoryID = *lastStoryIDite;
			time_t publucshtime = (*stories)[lastStoryID].getPublishTime();
			string date = formatTimeToHHMM(publucshtime); //? format the date to string
			DateUserStoryLabel->Text = gcnew String(date.c_str()); // Set the date format as needed
		}
		else {
			DateUserStoryLabel->Text = DateTime::Now.ToString("HH-mm");

		}



		// Set the date format as needed

		//? Set up the user story panel
		Button^ userStoryPanel = gcnew Button();
		userStoryPanel->Controls->Add(pictureUserStoryPic);
		userStoryPanel->Controls->Add(DateUserStoryLabel);
		userStoryPanel->Controls->Add(nameUserStoryLabel);
		userStoryPanel->Location = System::Drawing::Point(3, 3);
		userStoryPanel->Name = L"userStoryPanel";
		userStoryPanel->Size = System::Drawing::Size(400, 97);
		userStoryPanel->TabIndex = 0;
		userStoryPanel->BackColor = Color::FromArgb(60, 60, 60);
		userStoryPanel->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
		userStoryPanel->FlatAppearance->BorderSize = 1;
		userStoryPanel->TextAlign = ContentAlignment::MiddleLeft;
		userStoryPanel->FlatAppearance->MouseOverBackColor = Color::FromArgb(80, 80, 80);

		//? tag the user
		userStoryPanel->Tag = gcnew System::String(currentUser.getMobileNumber().c_str());
		//? Add click event handler to the user story panel
		userStoryPanel->Click += gcnew System::EventHandler(this, &StoryHandler::userStoryPanel_Click);

		//? Add the user story panel to the main panel
		allStoriesPanel->Controls->Add(userStoryPanel);
	}

	void createStory(User& currentUser) {
		// Create story 
		time_t publishTime = time(0);
		std::string textStoryString = msclr::interop::marshal_as<std::string>(textStory->Text);

		if (textStoryString == "") {
			MessageBox::Show("Please fill the story text", "Information Incomplete");
			return;
		}

		// Default font settings
		string fontName = "Arial";
		float fontSize = 24.0f;
		int fontStyleAsInt = 0;

		// Check if fontDialog is not null before accessing its properties
		if (fontDialog != nullptr && fontDialog->Font != nullptr) {
			fontName = msclr::interop::marshal_as<std::string>(fontDialog->Font->Name);
			fontSize = fontDialog->Font->Size;
			fontStyleAsInt = (int)fontDialog->Font->Style;
		}

		// Default color
		string colorHex = "#696969";

		// Check if colorDialog is not null and a color has been selected
		if (colorDialog != nullptr && colorDialog->Color.ToArgb() != 0) {
			cout << "Entered";
			colorHex = msclr::interop::marshal_as<std::string>(System::Drawing::ColorTranslator::ToHtml(colorDialog->Color));
		}
		cout << "COLOR HEX: " << colorHex << endl;

		// Create the story
		Story* story = new Story(textStoryString, publishTime, "", fontName, fontSize, fontStyleAsInt, colorHex);
		currentUser.addStoryID(story->getStoryID());
		//cout << "if the story added: " << bool(currentUser.addStoryID(story->getStoryID())) << endl;
		(*stories)[story->getStoryID()] = *story;
		//cout << "the storyID in the map: " << (*stories)[story->getStoryID()].getStoryID() << endl;
		//cout << "number of stories is: " << currentUser.getStoriesID().size() << endl << endl;
	}

	void HoverEnter(Object^ sender, EventArgs^ e)
	{
		System::String^ managedTypeName = sender->GetType()->Name;
		std::string s = msclr::interop::marshal_as<std::string>(managedTypeName);
		Button^ panelButton;
		int chatRoomID;
		if (s == "PictureBox")
		{
			PictureBox^ pictureBox = dynamic_cast<PictureBox^>(sender);
			panelButton = dynamic_cast<Button^>(pictureBox->Parent);

		}
		else if (s == "Label") {
			Label^ label = dynamic_cast<Label^>(sender);
			panelButton = dynamic_cast<Button^>(label->Parent);
		}

		if (panelButton != nullptr) {
			panelButton->BackColor = Color::FromArgb(80, 80, 80);
		}
	}

	void HoverLeave(Object^ sender, EventArgs^ e)
	{
		System::String^ managedTypeName = sender->GetType()->Name;
		std::string s = msclr::interop::marshal_as<std::string>(managedTypeName);
		Button^ panelButton;
		int chatRoomID;
		if (s == "PictureBox")
		{
			PictureBox^ pictureBox = dynamic_cast<PictureBox^>(sender);
			panelButton = dynamic_cast<Button^>(pictureBox->Parent);

		}
		else if (s == "Label") {
			Label^ label = dynamic_cast<Label^>(sender);
			panelButton = dynamic_cast<Button^>(label->Parent);
		}

		if (panelButton != nullptr) {
			panelButton->BackColor = Color::FromArgb(60, 60, 60);
		}
	}
};