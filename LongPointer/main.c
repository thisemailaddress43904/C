#include <stdio.h>

/**
 * A node for a doubly linked list
 */
struct ListNode {
    void* content;
    struct ListNode* next;
    struct ListNode* prev;
} typedef ListNode;

ListNode CreateListNode(void* content) {
    ListNode node;
    node.content = content;
    node.next = NULL;
    node.prev = NULL;
    return node;
}

int Push(void* content, ListNode finalNode){
    ListNode newNode;
    newNode.content = content;
    newNode.next = nullptr;

    finalNode.next = &newNode;
    newNode.prev = &finalNode;
}
int Pop(void* poppedContent, ListNode *finalNode) {
    poppedContent = finalNode->content;

    finalNode->prev->next = nullptr;
    finalNode = nullptr;
}

int GetNoOfNodesAwayFromHead(ListNode* node) {
    int n = 0;
    while (node->next != nullptr) {
        n+=1;
        node = node->next;
    }
    return n;
}

int GetTailLength(ListNode* node) {
    int n = 0;
    while (node->prev != nullptr) {
        n+=1;
        node = node->prev;
    }
    return n;
}

int GetLength(ListNode* node) {
    return GetTailLength(node) + 1 + GetNoOfNodesAwayFromHead(node);
}

static int NoOfLongPointersAlive = 0;

struct LongPointer {
    void *itemBeingPointedTo;
    int NoOfThingsPointingToThisLongPointer;
} typedef LongPointer;



int main(void) {

    ListNode ln = CreateListNode("a");

    fprintf(stdout,"%s\n", ln.content);
    fprintf(stdout,"%d\n", GetLength(&ln));
    return 0;
}
