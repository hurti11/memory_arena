/**
 * Project: Memory Arena Library
 * Brief: This is a simple C implementation of a memory arena.
 * Date: 28.10.2025
 * Author: Oskar Ambühl
 * Contact: oskar.ambuehl@gmail.com
 */

#include "arena.h"
#include <malloc.h>
#include <string.h>

Arena* createArena(unsigned long sizeInBytes) {
    Arena* arena = (Arena*)malloc(sizeof(Arena));

    if(arena == NULL) {
        return NULL;
    }

    arena->memory = malloc(sizeInBytes);
    arena->sizeInBytes = arena->memory == NULL ? 0 : sizeInBytes;
    arena->memoryOffset = 0;

    if(arena->memory != NULL) {
        memset(arena->memory, 0, sizeInBytes);
    }

    return arena;
}

void* allocFromArena(Arena** arena, unsigned long sizeInBytes) {
    if(arena == NULL || *arena == NULL || (*arena)->memory == NULL || (*arena)->memoryOffset + sizeInBytes > (*arena)->sizeInBytes) {
        return NULL;
    }

    void* ptr = (*arena)->memory + (*arena)->memoryOffset;
    (*arena)->memoryOffset += sizeInBytes;

    return ptr;
}

void freeArena(Arena** arena) {
    if(arena == NULL || (*arena) == NULL) {
        return;
    }

    if((*arena)->memory == NULL) {
        free(*arena);
        *arena = NULL;
        return;
    }

    free((*arena)->memory);
    (*arena)->memory = NULL;
    (*arena)->sizeInBytes = 0;
    (*arena)->memoryOffset = 0;

    free(*arena);
    *arena = NULL;
}
