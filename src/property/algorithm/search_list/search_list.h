#ifndef SEARCH_LIST_H
#define SEARCH_LIST_H

int array_min(int array[], size_t len);
int array_max(int array[], size_t len);

size_t array_min_index(int array[], size_t len);
size_t array_max_index(int array[], size_t len);

size_t array_bin_search(int array[], size_t len, int x);
size_t array_find(int array[], size_t len, int x);

void array_random_sorted_fill(int array[], size_t len);

#endif