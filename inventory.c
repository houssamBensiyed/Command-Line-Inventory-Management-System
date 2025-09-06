#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_INVENTORY_SIZE 100

typedef enum {
    ELECTRONICS,
    BOOKS,
    CLOTHING,
    GROCERIES
} ItemCategory;

typedef union {
    long sku;
    char serialNumber[20];
} ItemID;

typedef struct InventoryItem {
    ItemID id;
    char id_type;
    char name[100];
    unsigned int quantity;
    double price;
    ItemCategory category;

} Item;

void display_menu(void);

void add_item(Item* inventory, int* count);

void display_single_item(const Item* item);

void display_inventory(const Item* inventory, int count);

Item* find_item_by_name(const Item* inventory, int count, const char* name);

const char* get_category_string(ItemCategory category);

void clear_input_buffer(void);


