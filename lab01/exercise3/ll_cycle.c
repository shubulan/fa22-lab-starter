#include <stddef.h>
#include "ll_cycle.h"

int ll_has_cycle(node *head) {
    /* TODO: Implement ll_has_cycle */
    struct node* fast_p = head;
    struct node* slow_p = head;
    while (fast_p && fast_p->next) {
        fast_p = fast_p->next->next;
        slow_p = slow_p->next;
        if (fast_p == slow_p) return 1;
    }

    return 0;
}
