// file_operations.h
#ifndef FILE_OPERATIONS_H
#define FILE_OPERATIONS_H

#include "feed.h"

void addFeedItem(const char *filename, FeedItem item);
void updateFeedItem(const char *filename, int id, FeedItem newItem);
void deleteFeedItem(const char *filename, int id);
void listFeedItems(const char *filename);

#endif // FILE_OPERATIONS_H
