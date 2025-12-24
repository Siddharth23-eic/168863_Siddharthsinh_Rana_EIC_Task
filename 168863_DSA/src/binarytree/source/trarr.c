#include <stdio.h>
#include <stdint.h>
#include "BT_TASK.h"
#include "treearr.h"

void task1_treearr(void){
    int32_t n, val;
    
    treearr_init();
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for(int32_t i = 0; i < n; i++) {
        scanf("%d", &val);
        treearr_insert(val);
    }
}
