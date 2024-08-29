#ifndef STEP_H
#define STEP_H

#include <stdbool.h>

// Define the Player struct
typedef struct {
    int balance; // The amount of money the player has
    char name[50]; // The player’s name
    int games_played; // The number of games the player has played
    int games_won; // The number of games the player has won
} Player;

// Define a structure for the ArrayList of arrays
typedef struct {
    int** data; // An array of pointers to other arrays
    int size; // How many arrays are currently in the list
    int capacity; // How many arrays the list can hold before needing to grow
    int array_size; // The size of each array in the list
} ArrayList;

// Linked List Node structure
typedef struct Node {
    int data; // The value stored in this node
    struct Node* next; // A pointer to the next node in the list
} Node;

// Function prototypes for Linked List
Node* create_node(int value);
void append_linked_list(Node** head, int value);
int get_linked_list(Node* head, int index);
int pop_front(Node** head);
int pop_back(Node** head);
void free_linked_list(Node* head);

// Function prototypes for ArrayList of arrays
ArrayList create_array_list(int capacity, int array_size);
void append_array_list(ArrayList* list, int* array);
int* get_array_list(ArrayList* list, int index);
void free_array_list(ArrayList* list);

// Function prototypes for other utilities
int random(int min, int max);
int roll_dice(int sides);
const char* flip_coin();
void calculate_payout(Player* player, int bet, bool win);
void display_game_state(Player* player);
bool manage_round(Player* player);
void setcolor(int color);
void wait(int seconds);
char* concat(const char* str1, const char* str2);
int strlength(const char* str);

// Global variable declarations
extern int global_int;
extern long global_long;
extern float global_float;
extern char* global_string;
extern char global_char;
extern char global_alpha;
extern bool global_bool;
extern char* global_time;
extern char* global_date;
extern char* global_datetime;

// Function declarations for global variables
int getint();
void setint(int value);
long getlong();
void setlong(long value);
float getfloat();
void setfloat(float value);
void setstring(char* value);
char get_char();
void set_char(char value);
char get_alpha();
void set_alpha(char value);
bool getbool();
void setbool(bool value);
char* getcurrenttime();
void setcurrenttime(char* value);
char* getdate();
void setdate(char* value);
char* getdatetime();
void setdatetime(char* value);
void printline(const char* text);
int menu_select(int num_options, const char* options[]);
void clear_screen();
char* to_uppercase(char* str);
char* to_lowercase(char* str);
void reset_player(Player* player);
void getstring(char* str);
void print_string_int_message(const char* message, const char* str, int value);
void print_two_ints_message(const char* message, int value1, int value2);
void print_string_message(const char* message, const char* value);
void print_int_message(const char* message, int value);
#endif // STEP_H
