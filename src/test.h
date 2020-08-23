#pragma once

#include <stdio.h>

#define TEST_FAILED 1
#define TEST_OK 0
#define ASSERT(a, ...)                              \
    if (!a)                                         \
    {                                               \
        printf("assert failed: %s == FALSE\n", #a); \
        return TEST_FAILED;                         \
    }

#define ASSERT_EQ(a, b, ...)                         \
    if (a != b)                                      \
    {                                                \
        printf("assert failed: %s != %s\n", #a, #b); \
        return TEST_FAILED;                          \
    }

#define ASSERT_NEQ(a, b, ...)                        \
    if (a == b)                                      \
    {                                                \
        printf("assert failed: %s == %s\n", #a, #b); \
        return TEST_FAILED;                          \
    }

#define TEST_CASE(name, body)          \
    int name##_inner()                 \
    {                                  \
        do                             \
            body while (0);            \
        return TEST_OK;                \
    }                                  \
    void name()                        \
    {                                  \
        printf("START " #name "\n");   \
        if (name##_inner() == TEST_OK) \
        {                              \
            printf("OK\n");            \
        }                              \
        else                           \
        {                              \
            printf("KO\n");            \
        }                              \
    }

#define RUN_TEST(name) name();