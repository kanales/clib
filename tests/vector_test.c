#define ITEM int
#include "vector.h"
#undef ITEM

#include "vector_test.h"

vector *vector_fixup()
{
    return vector_new();
}

START_TEST(test_vector_create)
{
    vector *vec = vector_fixup();
    ck_assert_uint_eq(vec->size, 0);
    ck_assert_ptr_ne(vec->data, NULL);
    ck_assert_uint_eq(vec->limit, 1);
}
END_TEST

START_TEST(test_vector_delete)
{
    vector *vec = vector_fixup();
    ck_assert(!vector_destroy(vec));
}
END_TEST

START_TEST(test_vector_push)
{
    vector *vec = vector_fixup();
    vector_push(vec, 5);
    ck_assert_uint_eq(vec->size, 1);
    ck_assert_int_eq(vec->data[0], 5);
}
END_TEST

START_TEST(test_vector_iterate)
{
    vector *vec = vector_fixup();
    for (int i = 0; i < 5; i++)
    {
        vector_push(vec, i);
    }

    int *it = vector_begin(vec);
    ck_assert_int_eq(*(it++), 0);
    ck_assert_int_eq(*(it++), 1);
    ck_assert_int_eq(*(it++), 2);
    ck_assert_int_eq(*(it++), 3);
    ck_assert_int_eq(*(it++), 4);
    vector_destroy(vec);
}
END_TEST

Suite *vector_suite()
{
    Suite *s = suite_create("vector");
    TCase *tc_core = tcase_create("Core");

    tcase_add_test(tc_core, test_vector_create);
    tcase_add_test(tc_core, test_vector_delete);
    tcase_add_test(tc_core, test_vector_push);
    tcase_add_test(tc_core, test_vector_iterate);

    suite_add_tcase(s, tc_core);
    return s;
}