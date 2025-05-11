//#include <iostream>
//#include <string>
//#include <unordered_map>
//#include "User.h"
//#include <System::Windows> 
//using namespace std;
//using namespace System::IO;
//using namespace System::Drawing;
//using namespace System;
//using namespace System::Globalization;
//
//static void loadStries(User* currentUser,string mobileNumber,unordered_map<string,User>users) {
//		//todo get the current user from the map
//		currentUser = &users[mobileNumber];
//		//todo get all the stories of the user and his freinds when sign in
//	
//		if (currentUser->getStoriesID().size() > 0) {
//			createUserStoryPanel(*currentUser);
//		}
//		map<string, string> friendsContacts = currentUser->getContactsPhones();
//		for (auto contact : friendsContacts) {
//			User freind = users.at(contact.first);
//			if (freind.getStoriesID().size() > 0) {
//				createUserStoryPanel(freind);
//			}
//		}
//}
//
//static void createUserStoryPanel(User& currentUser) {
//	//? Define the PictureBox for the user story image
//
//
//	//PictureBox^ pictureUserStoryPic = gcnew PictureBox();
//
//	////? Load the resources
//	//System::ComponentModel::ComponentResourceManager^ resources = gcnew System::ComponentModel::ComponentResourceManager(GuiForm::typeid);
//	//cli::array<System::Byte>^ imageBytes = (cli::safe_cast<cli::array<System::Byte>^>(resources->GetObject(L"user")));
//
//	////? Convert byte array to Image using MemoryStream
//	//MemoryStream^ ms = gcnew MemoryStream(imageBytes);
//	//pictureUserStoryPic->Image = System::Drawing::Image::FromStream(ms);
//
//	////? Set the SizeMode to Zoom for the image to be zoomed correctly and fit within the PictureBox
//	//pictureUserStoryPic->SizeMode = PictureBoxSizeMode::Zoom;
//	//pictureUserStoryPic->Dock = System::Windows::Forms::DockStyle::Left;
//	//pictureUserStoryPic->InitialImage = nullptr;
//	//pictureUserStoryPic->Location = System::Drawing::Point(0, 0);
//	//pictureUserStoryPic->Name = L"pictureUserStoryPic";
//	//pictureUserStoryPic->Size = System::Drawing::Size(99, 97); // Adjust size as needed
//	//pictureUserStoryPic->TabIndex = 0;
//	//pictureUserStoryPic->TabStop = false;
//
//
//	//? name story panel
//	Label^ nameUserStoryLabel = gcnew Label();
//// Add this include for Label and other Windows Forms components
//
//    using namespace System::Windows::Forms; // Add this namespace for Label and other Windows Forms components
//
//    Label^ nameUserStoryLabel = gcnew Label();
//	nameUserStoryLabel->AutoSize = true;
//	nameUserStoryLabel->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(45)),
//		static_cast<System::Int32>(static_cast<System::Byte>(45)), static_cast<System::Int32>(static_cast<System::Byte>(45)));
//	nameUserStoryLabel->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
//	nameUserStoryLabel->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
//		static_cast<System::Byte>(0)));
//	nameUserStoryLabel->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
//	nameUserStoryLabel->Location = System::Drawing::Point(116, 9);
//	nameUserStoryLabel->Name = L"nameUserStoryLabel";
//	nameUserStoryLabel->Size = System::Drawing::Size(101, 37);
//	nameUserStoryLabel->TabIndex = 1;
//	std::string fullName = currentUser.getFirstName() + " " + currentUser.getLastName();
//	nameUserStoryLabel->Text = gcnew System::String(fullName.c_str());
//
//
//	//? label dateStoryPanel
//	Label^ DateUserStoryLabel = gcnew Label();
//	DateUserStoryLabel->AutoSize = true;
//	DateUserStoryLabel->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(45)),
//		static_cast<System::Int32>(static_cast<System::Byte>(45)), static_cast<System::Int32>(static_cast<System::Byte>(45)));
//	DateUserStoryLabel->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
//	DateUserStoryLabel->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
//		static_cast<System::Byte>(0)));
//	DateUserStoryLabel->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
//	DateUserStoryLabel->Location = System::Drawing::Point(135, 64);
//	DateUserStoryLabel->Name = L"DateUserStoryLabel";
//	DateUserStoryLabel->Size = System::Drawing::Size(50, 24);
//	DateUserStoryLabel->TabIndex = 2;
//
//	set<int>CurrentUserStoriesID = currentUser.getStoriesID();
//	if (CurrentUserStoriesID.size() > 0) {
//		auto lastStoryIDite = --CurrentUserStoriesID.end();
//		int lastStoryID = *lastStoryIDite;
//		time_t publucshtime = stories[lastStoryID].getPublishTime();
//		string date = formatTimeToHHMM(publucshtime); //? format the date to string
//		DateUserStoryLabel->Text = gcnew String(date.c_str()); // Set the date format as needed
//	}
//	else {
//		DateUserStoryLabel->Text = DateTime::Now.ToString("HH-mm");
//
//	}
//
//
//
//	// Set the date format as needed
//
//	//? Set up the user story panel
//	Panel^ userStoryPanel = gcnew Panel();
//	userStoryPanel->Controls->Add(DateUserStoryLabel);
//	userStoryPanel->Controls->Add(nameUserStoryLabel);
//	//userStoryPanel->Controls->Add(pictureUserStoryPic);
//	userStoryPanel->Location = System::Drawing::Point(3, 3);
//	userStoryPanel->Name = L"userStoryPanel";
//	userStoryPanel->Size = System::Drawing::Size(1249, 97);
//	userStoryPanel->TabIndex = 0;
//	//? tag the user
//	userStoryPanel->Tag = gcnew System::String(currentUser.getMobileNumber().c_str());
//	//? Add click event handler to the user story panel
//	userStoryPanel->Click += gcnew System::EventHandler(this, &GuiForm::userStoryPanel_Click);
//
//	//? Add the user story panel to the main panel
//	this->allStoriesPanel->Controls->Add(userStoryPanel);
//}
