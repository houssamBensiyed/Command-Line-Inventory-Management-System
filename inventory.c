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

