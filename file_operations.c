// file_operations.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "file_operations.h"

void addFeedItem(const char *filename, FeedItem item) {
    FILE *file = fopen(filename, "ab");
    if (!file) {
        perror("Failed to open file");
        return;
    }
    printf("Adding Feed Item: ID: %d, Name: %s, Quantity: %.2f, Price: %.2f\n", 
        item.id, item.name, item.quantity, item.price);
    fwrite(&item, sizeof(FeedItem), 1, file);
    fclose(file);
}

void updateFeedItem(const char *filename, int id, FeedItem newItem) {
    FILE *file = fopen(filename, "r+b");
    if (!file) {
        perror("Failed to open file");
        return;
    }
    
    FeedItem item;
    while (fread(&item, sizeof(FeedItem), 1, file)) {
        if (item.id == id) {
            fseek(file, -sizeof(FeedItem), SEEK_CUR);
            fwrite(&newItem, sizeof(FeedItem), 1, file);
            break;
        }
    }
    fclose(file);
}

void deleteFeedItem(const char *filename, int id) {
    FILE *file = fopen(filename, "r+b");
    if (!file) {
        perror("Failed to open file");
        return;
    }

    FILE *tempFile = fopen("temp.dat", "wb");
    if (!tempFile) {
        perror("Failed to open temporary file");
        fclose(file);
        return;
    }

    FeedItem item;
    while (fread(&item, sizeof(FeedItem), 1, file)) {
        if (item.id != id) {
            fwrite(&item, sizeof(FeedItem), 1, tempFile);
        }
    }

    fclose(file);
    fclose(tempFile);
    remove(filename);
    rename("temp.dat", filename);
}

void listFeedItems(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Failed to open file");
        return;
    }

    FeedItem item;
    while (fread(&item, sizeof(FeedItem), 1, file)) {
        printf("ID: %d, Name: %s, Quantity: %.2f, Price: %.2f\n", item.id, item.name, item.quantity, item.price);
    }
    fclose(file);
}
