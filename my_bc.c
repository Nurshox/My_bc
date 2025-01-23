#include "./include/struct_func.h"

void shunting_yard(s_nums**stc, char*string)
{
    s_nums*head = *stc;
    int len = _strlen(string);
    int k=0, top=-1;
    char*stack = (char*)calloc(10, sizeof(char));
    for(int i=0; i<len; i++)
    {
        if(string[i]==' ')
            continue;
        if(is_digit(string[i])==1)
        {
            char*tw = (char*)calloc(10, sizeof(char));
            k=0;
            while(is_digit(string[i])==1)
            {
                tw[k] = string[i];
                k++;
                i++;
            }
            add_elem(&head, tw);
            free(tw);
            i--;
        }
        else if(check_oper(string[i])==1)
        {
            while(top>=0 && check_oper(stack[top]) && oper_prec(string[i])<=oper_prec(stack[top]))
            {
                char c = stack[top--];
                char t[2] = {c, '\0'};
                add_elem(&head, t);
            }
            stack[++top] = string[i];
        }   
        else if (string[i] == '(') {
            stack[++top] = string[i];
        } else if (string[i] == ')') {
            while (top >= 0 && stack[top] != '(') {
                char c = stack[top--];
                char t[2] = {c, '\0'};
                add_elem(&head, t);
            }
            if (top >= 0 && stack[top] == '(') {
                top--;
            }
        }

    }
    while (top >= 0) {
        char c = stack[top--];
        char t[2] = {c, '\0'};
        add_elem(&head, t);
    }
    *stc = head;
    free(stack);
}



void basic_calc(s_nums* stc) {
    s_nums* head = stc;
    s_nums* prev = NULL;
    int num2, sum = 0, d = -1;
    char oper = '\0';
    int count = nums_count(stc);
    int* dig = (int*)calloc(count, sizeof(int));

    while (1) {
        if (head == NULL || check_oper(head->num[0]) != 1) {
            d++;
            dig[d] = my_atoi(head->num);
            prev = head;
        head = head->next;
        }
        else break;
    }
    head = prev;

    while (head->next != NULL) {
        if (sum == 0 && d >= 1) {
            num2 = dig[d];
            d--;
            sum = dig[d];
        }
        else if (check_oper(head->next->num[0]) && sum != 0 && d != 0) {
            d--;
            num2 = dig[d];
        } else if (is_digit(head->next->num[0])) {
            num2 = my_atoi(head->next->num);
            head = head->next;
        }

        if (check_oper(head->next->num[0]) == 1) {
            oper = head->next->num[0];
        }
        if (check_oper(oper) == 1) {
            sum = calculus_func(sum, num2, oper);
            oper = '\0';
        }

        head = head->next;
    }
    free(dig);
    printf("%d\n", sum);
}


int main(int argc, char**argv)
{
    if(argc>1)
    {
        if(handling_errors(argv[1])==1)
            return 1;
        else 
        {
            s_nums*s =NULL;
            shunting_yard(&s, argv[1]);
            basic_calc(s);
            _free(s);
        }
    }
    return 0;
}
