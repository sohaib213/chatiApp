#include "Message.h" // Include the Message header file to resolve the identifier "Message"
#include <unordered_map>
#include "User.h"


namespace chati {  
	class Node  
	{  
	public:  
		Node* next;  
		int value;  

		Node();  
		Node(int val);  
	};  

	class LinkedList  
	{  
		int count;  
		Node* head;  
		Node* tail;  
		Node* lastSeenMessage;  
	public:  
        #include <unordered_map>  
		LinkedList();  
		int Length();  
		int At(int);  
		void Delete(int);  
		void push_back(int);  
		void push_front(int);  
		void updateMessagesSeen(unordered_map<int, chati::Message>&, User*);
		bool empty() const;  

		Node* begin() const { return head; }  
		Node* end() const { return nullptr; }
		Node* lastMessageSeen() const { return lastSeenMessage; }

		~LinkedList(void);  
	};  
} // namespace chati
