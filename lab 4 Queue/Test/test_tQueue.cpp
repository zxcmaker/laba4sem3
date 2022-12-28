#include "gtest.h"
#include "Queue.h"

TEST(TVectorQueue, can_create_queue)
{
  ASSERT_NO_THROW(TVectorQueue<int> example());
}

TEST(TVectorQueue, can_copy_other_stack_and_have_different_address)
{
  TVectorQueue<int> a;
  a.Push(2);
  a.Push(7);
  a.Push(5);
  a.Pop();
  TVectorQueue<int> b(a);
  int tmp = b.Size();
  EXPECT_EQ(2, tmp);
  EXPECT_EQ(7, b.Pop());
  EXPECT_NE(&a, &b);
}

TEST(TVectorQueue, can_get_queueS_size_of_data)
{
  TVectorQueue<int> a;
  a.Push(2);
  a.Push(7);
  a.Push(5);
  a.Pop();
  EXPECT_EQ(2, a.Size());
}

TEST(TVectorQueue, can_check_is_empty_queue)
{
  TVectorQueue<int> a;
  EXPECT_EQ(0, a.Size());
  EXPECT_NE(false, a.isEmpty());
}

TEST(TVectorQueue, can_repack_queue)
{
  TVectorQueue<int> a;
  for (int i = 0; i < 10; i++)
    a.Push(i);
  for (int i = 0; i < 5; i++)
    a.Pop();
  a.repack();
  EXPECT_EQ(5, a.Size());
  EXPECT_EQ(5, a.Pop());
  EXPECT_EQ(6, a.Pop());
  EXPECT_EQ(7, a.Pop());
  EXPECT_EQ(8, a.Pop());
  EXPECT_EQ(9, a.Pop());
}

TEST(TVectorQueue, can_pop_queue)
{
  TVectorQueue<int> a;
  a.Push(2);
  a.Push(7);
  a.Push(5);
  int c = a.Pop();
  EXPECT_EQ(2, c);
  EXPECT_EQ(2, a.Size());
}

TEST(TVectorQueue, can_top_queue)
{
  TVectorQueue<int> a;
  a.Push(2);
  a.Push(7);
  a.Push(5);
  int c = a.Top();
  EXPECT_EQ(2, c);
  EXPECT_EQ(3, a.Size());
}