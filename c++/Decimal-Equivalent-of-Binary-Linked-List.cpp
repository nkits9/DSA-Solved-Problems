long long unsigned int decimalValue(Node *head) {
    long long unsigned int ans = 0;
    while(head != NULL) {
        ans = ans << 1;
        ans = ans | head->data;
        ans = ans % MOD;
        head = head->next;
    }
    return ans % MOD;
}