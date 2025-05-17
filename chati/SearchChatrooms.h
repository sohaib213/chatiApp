#pragma once
#include <unordered_map>
#include <string>
#include <vector>
#include <algorithm>
#include "ChatRoom.h"
#include "createChatRoomHandler.h"

void updateChatPanel(List<Control^>^ buttons, FlowLayoutPanel^ chatRoomsPanel) {
    // Clear the chatRoomsPanel and add the matching buttons
    chatRoomsPanel->SuspendLayout();
    chatRoomsPanel->Controls->Clear();
    for each (Control ^ button in buttons) {
        chatRoomsPanel->Controls->Add(button);
    }
    chatRoomsPanel->ResumeLayout();
}


static void searchChatRooms(string chatName, FlowLayoutPanel^ chatRoomsPanel, List<Control^>^ allButtons) {

   List<Control^>^ buttons = gcnew List<Control^>();


   for (int i = 0; i < allButtons->Count; i++) {
       Button^ button = dynamic_cast<Button^>(allButtons[i]);
       if (button == nullptr) continue;

       Label^ label = dynamic_cast<Label^>(button->Controls[1]);
       if (label != nullptr) {

           string labelText = msclr::interop::marshal_as<std::string>(label->Text);
           int labelTextSize = labelText.size();

           int existCharacter = 0, index = 0;

           for (int j = 0; j < chatName.size(); j++) {
               while (index < labelText.size()) {
                   if (labelText[index] == chatName[j])
                   {
                       index++;
                       existCharacter++;
                       break;
                   }
                   else
                       index++;
               }
           }
           if (existCharacter == chatName.size()) {
               buttons->Add(button);
           }
       }
   }

   updateChatPanel(buttons, chatRoomsPanel);
}

