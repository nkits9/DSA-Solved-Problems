int intersectPoint(Node* head1, Node* head2) {
    int a=0, b=0;
    Node *temp1 = head1;
    Node *temp2 = head2;
    while(temp1 != NULL) {
        temp1 = temp1->next;
        a++;
    }
    while(temp2 != NULL) {
        temp2 = temp2->next;
        b++;
    }
    
    while(a > b) {
        head1 = head1->next;
        a--;
    }    
    while(a < b) {
        head2 = head2->next;
        b--;
    }
    
    while(head1!=NULL && head2!=NULL && head1!=head2) {
        head1 = head1->next;
        head2 = head2->next;
    }
    
    if(head1==NULL || head2==NULL) 
        return -1;
    else 
        return head1->data;
    
}