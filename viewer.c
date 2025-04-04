// viewer.c
#include <stdio.h>
#include "feed.h"

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

int main() {
    const char *filename = "feeds.dat";
    printf("Listing all feed items from %s:\n", filename);
    listFeedItems(filename);
    return 0;
}