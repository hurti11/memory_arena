/**
 * Project: Memory Arena Library
 * Brief: This is a simple C implementation of a memory arena.
 * Date: 28.10.2025
 * Author: Oskar Ambühl
 * Contact: oskar.ambuehl@gmail.com
 */

#ifndef ARENA_H
#define ARENA_H

/**
 * Struct Arena
 * brief\ Structure holding the properties of the arena. All the fields are handled by the libraries functions.
 */
typedef struct Arena {
    void* memory;
    unsigned long sizeInBytes;
    unsigned long memoryOffset;
} Arena;

/**
 * createArena
 * brief\ Allocates a new arena with the requested size. If the allocation fails, NULL is returned.
 */
Arena* createArena(unsigned long sizeInBytes);

/**
 * allocFromArena
 * brief\ Allocate memory from the arena. If the allocation fails, NULL is returned.
 */
void* allocFromArena(Arena** arena, unsigned long sizeInBytes);

/**
 * freeArena
 * brief\ Frees the arena and the memory it contains. NOTE: all memory allocated from an arena freed by this function becomes inalid.
 */
void freeArena(Arena** arena);

#endif // ARENA_H
