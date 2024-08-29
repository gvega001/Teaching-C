#include "stepc.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include <stdbool.h>

// Linked List Functions
Node* create_node(int value) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (new_node != NULL) {
        new_node->data = value;
        new_node->next = NULL;
    }
    return new_node;
}

void append_linked_list(Node** head, int value) {
    Node* new_node = create_node(value);
    if (*head == NULL) {
        *head = new_node;
    } else {
        Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
}

int get_linked_list(Node* head, int index) {
    int count = 0;
    Node* current = head;
    while (current != NULL) {
        if (count == index) {
            return current->data;
        }
        count++;
        current = current->next;
    }
    return -1; // Index out of range
}

int pop_front(Node** head) {
    if (*head == NULL) {
        return -1; // List is empty
    }
    Node* temp = *head;
    int value = temp->data;
    *head = (*head)->next;
    free(temp);
    return value;
}

int pop_back(Node** head) {
    if (*head == NULL) {
        return -1; // List is empty
    }
    Node* current = *head;
    if (current->next == NULL) {
        int value = current->data;
        free(current);
        *head = NULL;
        return value;
    }
    while (current->next->next != NULL) {
        current = current->next;
    }
    int value = current->next->data;
    free(current->next);
    current->next = NULL;
    return value;
}

void free_linked_list(Node* head) {
    Node* current = head;
    Node* next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
}

// ArrayList Functions
ArrayList create_array_list(int capacity, int array_size) {
    ArrayList list;
    list.size = 0;
    list.capacity = capacity;
    list.array_size = array_size;
    list.data = (int**)malloc(capacity * sizeof(int*));
    for (int i = 0; i < capacity; i++) {
        list.data[i] = (int*)malloc(array_size * sizeof(int));
    }
    return list;
}

void append_array_list(ArrayList* list, int* array) {
    if (list->size >= list->capacity) {
        list->capacity *= 2;
        list->data = (int**)realloc(list->data, list->capacity * sizeof(int*));
    }
    list->data[list->size] = array;
    list->size++;
}

int* get_array_list(ArrayList* list, int index) {
    if (index >= 0 && index < list->size) {
        return list->data[index];
    }
    return NULL; // Index out of range
}

void free_array_list(ArrayList* list) {
    for (int i = 0; i < list->size; i++) {
        free(list->data[i]);
    }
    free(list->data);
}

// Utility Functions
int random(int min, int max) {
    return min + rand() % (max - min + 1);
}

int roll_dice(int sides) {
    return random(1, sides);
}

const char* flip_coin() {
    return random(0, 1) ? "Heads" : "Tails";
}

void calculate_payout(Player* player, int bet, bool win) {
    if (win) {
        player->balance += bet;
    } else {
        player->balance -= bet;
    }
}

void display_game_state(Player* player) {
    printf("Player: %s\n", player->name);
    printf("Balance: %d\n", player->balance);
    printf("Games Played: %d\n", player->games_played);
    printf("Games Won: %d\n", player->games_won);
}

bool manage_round(Player* player) {
    int bet = 10; // Example bet
    bool win = roll_dice(2) == 1; // Example win condition
    calculate_payout(player, bet, win);
    player->games_played++;
    if (win) {
        player->games_won++;
    }
    display_game_state(player);
    return win;
}

void setcolor(int color) {
    // Placeholder for setting console text color
}

void wait(int seconds) {
    sleep(seconds);
}

char* concat(const char* str1, const char* str2) {
    char* result = malloc(strlen(str1) + strlen(str2) + 1);
    strcpy(result, str1);
    strcat(result, str2);
    return result;
}

int strlength(const char* str) {
    return strlen(str);
}

char* get_current_time() {
    time_t t;
    time(&t);
    char* buffer = malloc(9); // HH:MM:SS + NULL
    strftime(buffer, 9, "%H:%M:%S", localtime(&t));
    return buffer;
}

void sleep_seconds(int seconds) {
    sleep(seconds);
}

void save_game_state(Player* player) {
    FILE* file = fopen("savegame.txt", "w");
    if (file) {
        fprintf(file, "%s %d %d %d\n", player->name, player->balance, player->games_played, player->games_won);
        fclose(file);
    }
}

bool load_game_state(Player* player) {
    FILE* file = fopen("savegame.txt", "r");
    if (file) {
        fscanf(file, "%s %d %d %d", player->name, &player->balance, &player->games_played, &player->games_won);
        fclose(file);
        return true;
    }
    return false;
}

// Global Variables
int global_int;
long global_long;
float global_float;
char* global_string = NULL;
char global_char;
char global_alpha;
bool global_bool;
char* global_time = NULL;
char* global_date = NULL;
char* global_datetime = NULL;

// Functions for global variables
int getint() {
    return global_int;
}

void setint(int value) {
    global_int = value;
}

long getlong() {
    return global_long;
}

void setlong(long value) {
    global_long = value;
}

float getfloat() {
    return global_float;
}

void setfloat(float value) {
    global_float = value;
}

void setstring(char* value) {
    if (global_string != NULL) {
        free(global_string);
    }
    global_string = strdup(value);
}

char get_char() {
    return global_char;
}

void set_char(char value) {
    global_char = value;
}

char get_alpha() {
    return global_alpha;
}

void set_alpha(char value) {
    global_alpha = value;
}

bool getbool() {
    return global_bool;
}

void setbool(bool value) {
    global_bool = value;
}

char* getcurrenttime() {
    return global_time;
}

void setcurrenttime(char* value) {
    if (global_time != NULL) {
        free(global_time);
    }
    global_time = strdup(value);
}

char* getdate() {
    return global_date;
}

void setdate(char* value) {
    if (global_date != NULL) {
        free(global_date);
    }
    global_date = strdup(value);
}

char* getdatetime() {
    return global_datetime;
}

void setdatetime(char* value) {
    if (global_datetime != NULL) {
        free(global_datetime);
    }
    global_datetime = strdup(value);
}

void printline(const char* text) {
    printf("%s\n", text);
}

int menu_select(int num_options, const char* options[]) {
    for (int i = 0; i < num_options; i++) {
        printf("%d. %s\n", i + 1, options[i]);
    }
    int choice;
    do {
        printf("Choose an option: ");
        scanf("%d", &choice);
    } while (choice < 1 || choice > num_options);
    return choice;
}

void clear_screen() {
    printf("\033[H\033[J"); // ANSI escape codes to clear the screen
}

char* to_uppercase(char* str) {
    for (char* p = str; *p != '\0'; p++) {
        *p = toupper(*p);
    }
    return str;
}

char* to_lowercase(char* str) {
    for (char* p = str; *p != '\0'; p++) {
        *p = tolower(*p);
    }
    return str;
}

void reset_player(Player* player) {
    player->balance = 0;
    player->games_played = 0;
    player->games_won = 0;
}

void print_int_message(const char* message, int value) {
    char buffer[100];
    sprintf(buffer, "%s %d", message, value);
    printline(buffer);
}
void print_string_message(const char* message, const char* value) {
    char buffer[100];
    sprintf(buffer, "%s %s", message, value);
    printline(buffer);
}
void print_two_ints_message(const char* message, int value1, int value2) {
    char buffer[100];
    sprintf(buffer, "%s %d: %d", message, value1, value2);
    printline(buffer);
}
void print_string_int_message(const char* message, const char* str, int value) {
    char buffer[100];
    sprintf(buffer, "%s %s has a balance of %d", message, str, value);
    printline(buffer);
}
