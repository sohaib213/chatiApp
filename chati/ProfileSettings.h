#pragma once
#include <string>
#include <msclr/marshal_cppstd.h>
#include "User.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace System::Drawing;
using namespace System::Collections::Generic;
using namespace std;

void editClick(ComboBox^ visibilityComboBox, Button^ submitVisibleButton) {
	if(!visibilityComboBox->Visible)
	{
		visibilityComboBox->Visible = true;
		submitVisibleButton->Visible = true;
	}
	else
	{
		visibilityComboBox->Visible = false;
		submitVisibleButton->Visible = false;
	}
}

void editClick(TextBox^ newNameTextBox, Button^ submitNameButton) {
	if(!newNameTextBox->Visible)
	{
		newNameTextBox->Visible = true;
		submitNameButton->Visible = true;
	}
	else
	{
		newNameTextBox->Visible = false;
		submitNameButton->Visible = false;
	}
}

void editClick(RichTextBox^ newAboutRichTextBox, Button^ submitNewAboutButton) {
	if (!newAboutRichTextBox->Visible)
	{
		newAboutRichTextBox->Visible = true;
		submitNewAboutButton->Visible = true;
	}
	else
	{
		newAboutRichTextBox->Visible = false;
		submitNewAboutButton->Visible = false;
	}
}

void changePhoto(PictureBox^ userPhotoPictureBox, String^ imagesFolder, User* currentUser) {
	OpenFileDialog^ openFileDialog = gcnew OpenFileDialog();
	openFileDialog->Title = "Select an image";
	openFileDialog->Filter = "Image Files|*.jpg;*.jpeg;*.png;*.bmp;*.gif";

	if (openFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{
		userPhotoPictureBox->Image = Image::FromFile(openFileDialog->FileName);
		String^ selectedImagePath = openFileDialog->FileName;
		String^ fileName = Path::GetFileName(selectedImagePath);


		String^ destinationPath = Path::Combine(imagesFolder, fileName);

		if (fileName != "User.png" && selectedImagePath != destinationPath)
			File::Copy(selectedImagePath, destinationPath, true);

		currentUser->setProfilePhoto(msclr::interop::marshal_as<std::string>(fileName));

	}
}


void submitVisibility(ComboBox^ visibilityComboBox, Button^ submitVisibleButton, Label^ visibleLabel, User* currentUser) {
	if (visibilityComboBox->SelectedItem != nullptr)
	{
		visibilityComboBox->Visible = false;
		submitVisibleButton->Visible = false;
		visibilityComboBox->Text = "";

		String^ selectedValue = visibilityComboBox->SelectedItem->ToString();
		string response = msclr::interop::marshal_as<string>(selectedValue);

		visibleLabel->Text = visibilityComboBox->SelectedItem->ToString();
		if (response == "True")
		{
			currentUser->setVisible(1);
		}
		else if (response == "False")
		{
			currentUser->setVisible(0);
		}
		else
			MessageBox::Show("Enter True Or False");
	}
	else
	{
		MessageBox::Show("Enter Value To Change");
	}
}

void changeName(TextBox^ newNameTextBox, Button^ submitNameButton, Label^ nameLabel, User* currentUser, int source) {
	if (newNameTextBox->Text != "")
	{
		string newName = msclr::interop::marshal_as<string>(newNameTextBox->Text);
		if(source == 1)
			currentUser->setFirstName(newName);
		else if(source == 2)
			currentUser->setLastName(newName);

		newNameTextBox->Visible = false;
		submitNameButton->Visible = false;
		newNameTextBox->Text = "";
		nameLabel->Text = gcnew System::String(newName.c_str());
	}
	else
	{
		if(source == 1)
			MessageBox::Show("Please Enter New First Name To Change");
		else if(source == 2)
			MessageBox::Show("Please Enter New Last Name To Change");

	}
}

void changeAbout(RichTextBox^ newAboutRichTextBox, Button^ submitNewAboutButton, Label^ aboutLabel, User* currentUser) {

	if (newAboutRichTextBox->Text != "")
	{
		string newAbout = msclr::interop::marshal_as<string>(newAboutRichTextBox->Text);
		currentUser->setAbout(newAbout);
		newAboutRichTextBox->Visible = false;
		submitNewAboutButton->Visible = false;
		newAboutRichTextBox->Text = "";
		aboutLabel->Text = gcnew System::String(newAbout.c_str());
	}
	else
	{
		MessageBox::Show("Please Enter New About To Change");
	}

}

void changePassword(TextBox^ newPasswordTextBox, Button^ submitPasswordButton, User* currentUser) {
	if (newPasswordTextBox->Text != "")
	{
		string newPassword = msclr::interop::marshal_as<string>(newPasswordTextBox->Text);
		currentUser->setPassword(newPassword);

		newPasswordTextBox->Visible = false;
		submitPasswordButton->Visible = false;
		newPasswordTextBox->Text = "";
	}
	else
	{
		MessageBox::Show("Please Enter New Password To Change");
	}
}