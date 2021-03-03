Given a linked list, return the node where the cycle begins. If there is no cycle, return null.

There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to. Note that pos is not passed as a parameter.

Notice that you should not modify the linked list.

Input: head = [3,2,0,-4], pos = 1
Output: tail connects to node index 1
Explanation: There is a cycle in the linked list, where tail connects to the second node.

ListNode* detectCycle(ListNode* head) {
		auto slow = head;
		auto fast = head;

		while (fast && fast->next) {
			slow = slow->next;
			fast = fast->next->next;
			if (slow == fast) break;
		}

		if (!fast || !fast->next) return NULL;

		slow = head;
		while (slow != fast) {
			slow = slow->next;
			fast = fast->next;
		}

		return slow;
	}