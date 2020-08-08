//
//  main.c
//  Scrambled String
//
//  Created by Giriraj Saigal on 08/08/20.
//  Copyright © 2020 Giriraj Saigal. All rights reserved.
//

#include <stdio.h>
#include "stdbool.h"

struct Node{
    char *str;
    struct Node *left;
    struct Node *right;
}*root;

bool ss(char *s, char* tr, int i, int j, struct Node *p)
{
    if(i >= j)
        return false;


    int k;
    struct Node *left;
    struct Node *right;

    for (k = i; k < j; k++) {

        left = (struct Node *)malloc(sizeof(struct Node));
        left->left = NULL;
        left->right = NULL;
        left->str = (char *)malloc((k-i+1) *sizeof(char));

        for(int q = i; q <= k; q++)
            left->str[q] = s[q];

        left->str[k-i+1] = '\0';

        p->left = left;

        right = (struct Node *)malloc(sizeof(struct Node));
        right->left = NULL;
        right->right = NULL;
        right->str = (char *)malloc((j-k) *sizeof(char));

        for(int q = k+1; q <= j; q++)
            right->str[q] = s[q];

        right->str[j-k] = '\0';

        p->right = right;


        ss(s,tr, i, k, p->left);
        ss(s,tr, k+1, j, p->right);
    }

    return true;

}

int main(int argc, const char * argv[]) {

    char *str1 = "great";
    char *target = "rgeat";

    int n = 0;

    for(int i = 0; str1[i] != '\0'; i++)
        n++;

    root = (struct Node *)malloc(sizeof(struct Node));

    root->str = str1;
    root->left = NULL;
    root->right = NULL;

    printf("%s & %s are srambled : %s\n", str1, target, ss(str1 ,target, 0, n-1, root)?"Yes":"No");


    return 0;
}
