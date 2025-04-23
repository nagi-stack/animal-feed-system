// main.c
#include <stdio.h>
#include <stdlib.h>
#include "feed.h"
#include "file_operations.h"

void displayMenu() {
    printf("\n--- Animal Feed Management System ---\n");
    printf("1. Add Feed Item\n");
    printf("2. Update Feed Item\n");
    printf("3. Delete Feed Item\n");
    printf("4. List Feed Items\n");
    printf("5. Exit\n");
}

int main() {
    const char *filename = "feeds.dat";
    int choice;
    FeedItem item;

    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        if (choice > 5) {
            printf("Invalid entry. Exiting the program with an error.\n"); //error handling incase the user inputs a choice more than 5.
            exit(EXIT_FAILURE);
        }

        switch (choice) {
            case 1: // Add Feed Item
                printf("Enter ID, Name of animal feed, Quantity(Kg), Price per Kg: ");
                scanf("%d %s %d %d", &item.id, item.name, &item.quantity, &item.price);
                addFeedItem(filename, item);
                printf("Feed item added successfully.\n");
                break;

            case 2: // Update Feed Item
                printf("Enter ID of item to update: ");
                scanf("%d", &item.id);
                printf("Enter new Name, Quantity, Price: ");
                scanf("%s %f %f", item.name, &item.quantity, &item.price);
                updateFeedItem(filename, item.id, item);
                printf("Feed item updated successfully.\n");
                break;

            case 3: // Delete Feed Item
                printf("Enter ID of item to delete: ");
                scanf("%d", &item.id);
                deleteFeedItem(filename, item.id);
                printf("Feed item deleted successfully.\n");
                break;

            case 4: // List Feed Items
                printf("Listing all feed items:\n");
                listFeedItems(filename);
                break;

            case 5: // Exit
                printf("Exiting the program.\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}
