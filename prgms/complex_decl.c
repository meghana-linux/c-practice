    /*
     * decode_decl.c
     *
     *  Created on: 31 Jan 2018
     *      Author: kiran.kumar
     */
     
     
    #include <stdio.h>
    #include <string.h>
    #include <ctype.h>
    #include <stdlib.h>
    #define MAXTOKENLEN 64
    #undef TEST
     
    #if defined TEST
    #define MAXTOKENS 100
     
    /*==============global variables========================*/
    //char mytoken[] = "char (*(*x())[]) ()";
	char mytoken[] = "const char *x[]";
    int i = 0;
    #endif
     
     
    /*==============structers and enums====================*/
    enum type_tag { IDENTIFIER, QUALIFIER, TYPE };
     
     typedef struct token {
         char type;
         char string[MAXTOKENLEN];
     }token;
     
    //normal linked list
     typedef struct node {
         token *data;
         struct node *next;
     }node;
     
     
    /*========function prototypes=============================*/
     node * new_node(token *data);
     void push(node **stack, token *data);
     token *pop(node **stack);
     int isEmpty(node *n);
     token *top(node *n);
     void classify_string(token *this);
     token *gettoken(void);
     void read_to_first_identifier(node **stack);
     void deal_with_arrays(token *this);
     void deal_with_function_args(token *this); 
     void deal_with_pointers(node **stack);
     void deal_with_declarator(node **stack, token *this);
     
     
     /*====================linked-list==========================*/
     
     
     node * new_node(token *data)
     {
         node * new = (node *)malloc(sizeof(struct node));
     
         if(!new) {
             printf("no memory\n");
             return new;
         }
         new->data = data;
         new->next = NULL;
         return new;
     }
    /*============================xxxx===========================*/
    /*============================stack=========================*/
     void push(node **stack, token *data)
     {
         node *temp = new_node(data);
         temp->next = *stack;
         *stack = temp;
     }
     
     token* pop(node **stack)
     {
         token *temp;
         if(isEmpty(*stack))
         {
             return NULL;
         }
     
         temp = (*stack)->data;
         (*stack) = (*stack)->next;
         return temp;
     }
     
     int isEmpty(node *n)
     {
         return(n == NULL);
     }
     
     token *top(node *n)
     {
         return n->data;
     }
     
    /*======================xxxx===============================*/
     
    //function to identify type and qualifier
     void classify_string(token *this)
     /* figure out the identifier type */
     {
         char *s = this->string;
         if (!strcmp(s,"const")) this->type = QUALIFIER;
         else
         if (!strcmp(s,"volatile")) this->type = QUALIFIER;
         else
         if (!strcmp(s,"void")) this->type = TYPE;
         else
         if (!strcmp(s,"char")) this->type =  TYPE;
         else
         if (!strcmp(s,"signed")) this->type = TYPE;
         else
         if (!strcmp(s,"unsigned")) this->type = TYPE;
         else
         if (!strcmp(s,"short")) this->type = TYPE;
         else
         if (!strcmp(s,"int")) this->type = TYPE;
         else
         if (!strcmp(s,"long")) this->type = TYPE;
         else
         if (!strcmp(s,"float")) this->type = TYPE;
         else
         if (!strcmp(s,"double")) this->type = TYPE;
         else
         if (!strcmp(s,"struct")) this->type = TYPE;
         else
         if (!strcmp(s,"union")) this->type = TYPE;
         else
         if (!strcmp(s,"enum")) this->type = TYPE;
         else
         this->type = IDENTIFIER;
     
         return;
     }
     
     
     //function to read input and return tokens
     token *gettoken(void) /* read next token into "this" */
     {
         token *this = (token*)malloc(sizeof(token));
         char *p = this->string;
     
    #if defined TEST
         /* read past any spaces */
         while ((*p = mytoken[i++]) == ' ' ) ;
    #else
         while ((*p = getchar()) == ' ' ) ;
    #endif
     
         if (isalnum(*p)) {
    #if defined TEST
             /* it starts with A-Z,0-9 read in identifier
    */
             while ( isalnum(*++p=mytoken[i++]) );
                   i--;
    #else
             while ( isalnum(*++p=getchar()) );
             ungetc(*p,stdin);
    #endif
             *p = '\0';
             classify_string(this);
         }
         else
         if (*p=='*') {
             strcpy(this->string,"pointer to");
             this->type = '*';
         }
         else
         {
             this->string[1]= '\0';
             this->type = *p;
         }
         return this;
     }
     
     /* The piece of code that understandeth all parsing.
    */
    void read_to_first_identifier(node **stack) {
        token *this = NULL;
         this = gettoken();
         while (this->type!=IDENTIFIER) {
             push(stack, this);
             this = gettoken();
         }
         printf("%s is ", this->string);
     }
     
     void deal_with_arrays(token *this) {
         while (this->type=='[') {
             printf("array ");
             this = gettoken(); /* a number or ']' */
             if (isdigit(this->string[0])) {
                 printf("0..%d ",atoi(this->string)-1);
                 this = gettoken(); /* read the ']' */
             }
             this = gettoken(); /* read next past the ']' */
             printf("of ");
         }
     }
     
     void deal_with_function_args(token *this) {
         while (this->type!=')') {
             this = gettoken();
         }
         this = gettoken();
        printf("function returning ");
     }
     
     void deal_with_pointers(node **stack) {
         token *temp;
        while ( ((token *)top(*stack))->type== '*' ) {
            temp = (token*)pop(stack);
            printf("%s ", temp->string );
            free(temp);
        }
     }
     
     void deal_with_declarator(node **stack, token *this) {
        /* deal with possible array/function following
    the identifier */
        switch (this->type) {
        case '[' : deal_with_arrays(this); break;
        case '(' : deal_with_function_args(this);
        }
     
        deal_with_pointers(stack);
     
        /* process tokens that we stacked while reading
    to identifier */
        while (!isEmpty(*stack)) {
            token *temp;
            if ( ((token *)top(*stack))->type== '(' ) {
                temp = (token*)pop(stack);
                free(temp);
                this = gettoken(); /* read past ')' */
                deal_with_declarator(stack, this);
            } else {
                temp = (token*)pop(stack);
                printf("%s ", temp->string );
                free(temp);
            }
        }
     }
     
     int main()
     {
         node *stack = NULL;
         token *this = NULL;
        /* put tokens on stack until we reach identifier
    */
        read_to_first_identifier(&stack);
        this = gettoken();
        deal_with_declarator(&stack, this);
        printf("\n");
        return 0;
     }
     
