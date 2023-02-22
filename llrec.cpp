#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************

void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot)
{
	if(head == NULL) //base case: nullptr end
	{
		smaller = NULL;
		larger = NULL;
		return;
	}
	else
	{
		llpivot(head->next, smaller, larger, pivot); //recurse all the way to base case first
		if(head->val > pivot) //upon returning check larger
		{
			if(larger != NULL)
			{
				head->next = larger; //rearrange in list to large and smalls in reverse order
			}
			larger = head;
			head = NULL; //delete used in node
		}
		else //otherwise smaller
		{
			if(smaller != NULL)
			{
				head->next = smaller; //rearrange in list to larges and smalls in reverse order
			}
			smaller = head;
			head = NULL; //delete used in node
		}
	}
}

