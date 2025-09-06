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

int main() {
    Item inventory[MAX_INVENTORY_SIZE];
    int current_item_count = 0;
    int choice = 0;

    printf("Welcome to the Inventory Management System! \n");

    do {
        display_menu();
        printf("\nEnter you choice: ");
        scanf("%d", &choice);
        clear_input_buffer();

        switch (choice) {
            case 1:
                add_item(inventory, &current_item_count);
                break;
            case 2:
                display_inventory(inventory, current_item_count);
                break;
            case 3: {
                char search_name[100];
                printf("Enter the name of the item to search for: ");
                fgets(search_name, sizeof(search_name), stdin);
                search_name[strcspn(search_name, "\n")] = 0;

                Item* found_item = find_item_by_name(inventory, current_item_count, search_name);

                if (found_item != NULL) {
                    printf("\n----- Item Found ------\n");
                    display_single_item(found_item);
                } else {
                    printf("Item '%s' not found in inventory.\n", search_name);
                }
                break;
            }
            case 4:
                printf("Exiting program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}
