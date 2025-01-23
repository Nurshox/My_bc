#include "../include/struct_func.h"

void add_elem(s_nums**num, char*string)
{
    s_nums*new = (s_nums*)malloc(sizeof(s_nums));
    new->num = (char*)calloc(_strlen(string)+1, sizeof(char));
    _strcpy(new->num, string);
    new->next=NULL;
    if((*num) == NULL)
        *num = new;
    else 
    {
        s_nums*head = *num;
        while(head->next!=NULL)
            head = head->next;
        head->next = new;
    }
}

int nums_count(s_nums*n)
{
    s_nums * head = n;
    int count=0;
    while(head!=NULL)
    {   
        if(is_digit(head->num[0])==1)
            count++;
        head = head->next;
    }
    return count;
}

void _free(s_nums*head)
{
 while (head != NULL) {
        s_nums* curr = head;
        head = head->next;
        free(curr->num); 
        free(curr);      
    }
}