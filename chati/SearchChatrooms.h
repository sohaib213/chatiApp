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

static void searchChatRooms(string chatname, FlowLayoutPanel^ chatRoomsPanel, List<Control^>^ allButtons) {

   List<Control^>^ buttons = gcnew List<Control^>();

   for each (Button ^ button in allButtons) {

       
        Label^ label = dynamic_cast<Label^>(button->Controls[1]);
        if (label != nullptr) {
            bool exist = true;
            for (int i = 0; i < chatname.size(); i++) {
                String^ chatChar = gcnew String(chatname.substr(i, 1).c_str());
                if (!label->Text->Contains(chatChar)) {
                    exist = false;
                    break;
                }
            }
            if (exist) {
                buttons->Add(button);
            }
            break;
        }
   }
   updateChatPanel(buttons, chatRoomsPanel);
   cout << "changed" << endl;
}

