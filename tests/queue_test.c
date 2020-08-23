#define ITEM int
#include "queue.h"
#undef ITEM

#include "queue_test.h"

queue *queue_fixup()
{
    return queue_new();
}
START_TEST(test_queue_create)
{
    queue *q = queue_fixup();
    ck_assert_int_eq(q->size, 0);
    ck_assert_ptr_ne(q->data, NULL);
    ck_assert_int_eq(q->head, 0);
    ck_assert_int_eq(q->tail, 0);
    queue_destroy(q);
}
END_TEST

START_TEST(test_queue_delete)
{
    queue *q = queue_fixup();
    ck_assert(!queue_destroy(q));
}
END_TEST

START_TEST(test_queue_push)
{
    queue *q = queue_fixup();
    queue_push(q, 5);
    ck_assert_uint_eq(q->size, 1);
    ck_assert_int_eq(q->data[0], 5);

    queue_destroy(q);
}
END_TEST

START_TEST(test_queue_pop)
{
    queue *q = queue_fixup();
    for (int i = 1; i < 5; i++)
    {
        queue_push(q, i);
    }

    ck_assert_int_eq(queue_pop(q), 1);
    ck_assert_int_eq(queue_pop(q), 2);
    ck_assert_int_eq(queue_pop(q), 3);
    ck_assert_int_eq(queue_pop(q), 4);
    queue_destroy(q);
}
END_TEST

START_TEST(test_queue_empty)
{
    queue *q = queue_fixup();
    ck_assert(queue_empty(q));
    queue_push(q, 1);
    ck_assert(!queue_empty(q));
    queue_destroy(q);
}
END_TEST

START_TEST(test_queue_size)
{
    queue *q = queue_fixup();
    ck_assert_uint_eq(queue_size(q), 0);
    queue_push(q, 1);
    ck_assert_uint_eq(queue_size(q), 1);
    queue_destroy(q);
}
END_TEST

Suite *queue_suite()
{
    Suite *s = suite_create("queue");
    TCase *tc_core = tcase_create("Core");

    tcase_add_test(tc_core, test_queue_create);
    tcase_add_test(tc_core, test_queue_delete);
    tcase_add_test(tc_core, test_queue_push);
    tcase_add_test(tc_core, test_queue_size);
    tcase_add_test(tc_core, test_queue_empty);
    tcase_add_test(tc_core, test_queue_pop);

    suite_add_tcase(s, tc_core);
    return s;
}
