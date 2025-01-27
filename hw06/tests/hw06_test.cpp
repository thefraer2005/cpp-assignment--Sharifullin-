#include <hw06.h>
#include <gtest/gtest.h>

TEST(Hw06Tests, Test1)
{
    auto rows = 5, seats_per_row = 8;
    Hall hall = create_hall(1, rows, seats_per_row);
    Session session = create_session(1, "Die Hard", hall);

    auto avail_seats = get_available_seats(hall);
    auto expected_seats = rows * seats_per_row;
    EXPECT_EQ(expected_seats, avail_seats);
}
//
TEST(Hw06Tests, Test2)
{
  auto rows = 5, seats_per_row = 15;
  Hall hall = create_hall(1, rows, seats_per_row);
  Session session = create_session(1, "Die Hard", hall);

  auto reserved_seats = 2;
  reserve_seat(session, 1, 3);
  reserve_seat(session, 2, 5);

  auto avail_seats = get_available_seats(hall);
  auto expected_seats = rows * seats_per_row - reserved_seats;
  EXPECT_EQ(expected_seats, avail_seats);
}

TEST(Hw06Tests, Test3)
{
  auto rows = 3, seats_per_row = 5;
  Hall hall = create_hall(1, rows, seats_per_row);
  Session session = create_session(1, "Die Hard", hall);

  reserve_seat(session, 1, 3);
  cancel_reservation(session, 1, 3);

  auto avail_seats = get_available_seats(hall);
  auto expected_seats = rows * seats_per_row;
  EXPECT_EQ(expected_seats, avail_seats);
}

TEST(Hw06Tests, Test4)
{
  auto rows = 3, seats_per_row = 5;
  Hall hall = create_hall(1, rows, seats_per_row);
  Session session = create_session(1, "Die Hard", hall);

  reserve_seat(session, 1, 3);
  auto reserve_stat = reserve_seat(session, 1, 3);
  auto expected_stat = false;
  EXPECT_EQ(expected_stat, reserve_stat);
}

TEST(Hw06Tests, Test5) 
{
    auto rows = 3, seats_per_row = 3;
    Hall hall = create_hall(1, rows, seats_per_row);
    Session session = create_session(1, "Die Hard", hall);

    // Reserve all seats
    for (int row = 0; row < rows; ++row) {
      for (int seat_number = 0; seat_number < seats_per_row; ++seat_number) {
        EXPECT_TRUE(reserve_seat(session, row, seat_number));
      }
    }

    auto avail_seats = get_available_seats(hall);
    auto expected_seats = 0;
    EXPECT_EQ(expected_seats, avail_seats);
}

TEST(Hw06Tests, Test7) 
{
  auto rows = 3, seats_per_row = 3;
  Hall hall = create_hall(1, rows, seats_per_row);
  Session session = create_session(1, "Die Hard", hall);

  int row = 1, seat_number = 1;

  for (int i = 0; i < 5; ++i) {
    EXPECT_TRUE(reserve_seat(session, row, seat_number));
    EXPECT_TRUE(cancel_reservation(session, row, seat_number));
  }

  auto avail_seats = get_available_seats(hall);
  auto expected_seats = rows * seats_per_row;
  EXPECT_EQ(expected_seats, avail_seats);
}

TEST(Hw06Tests, Test8)
{
  auto rows = 3, seats_per_row = 3;
  Hall hall = create_hall(1, rows, seats_per_row);
  Session session = create_session(1, "Die Hard", hall);

  auto cancel_stat = cancel_reservation(session, 5, 5);
  auto expected_stat = false;
  EXPECT_EQ(expected_stat, cancel_stat);
}
TEST(Hw06Tests, Test9) 
{
  auto rows = 3, seats_per_row = 3;
  Hall hall = create_hall(1, rows, seats_per_row);
  Session session = create_session(1, "Die Hard", hall);

  for (int row = 0; row < rows; ++row) {
    for (int seat_number = 0; seat_number < seats_per_row; ++seat_number) {
      EXPECT_TRUE(reserve_seat(session, row, seat_number));
    }
  }

  auto avail_seats = get_available_seats(hall);
  EXPECT_EQ(0, avail_seats); 
}

TEST(Hw06Tests, Test10) 
{
  auto rows = 3, seats_per_row = 3;
  Hall hall = create_hall(1, rows, seats_per_row);
  Session session = create_session(1, "Die Hard", hall);

  int row = 1, seat_number = 1;

  EXPECT_TRUE(reserve_seat(session, row, seat_number));

  EXPECT_FALSE(reserve_seat(session, row, seat_number)); 
}

TEST(Hw06Tests, Test11) 
{
  auto rows = 3, seats_per_row = 3;
  Hall hall = create_hall(1, rows, seats_per_row);
  Session session = create_session(1, "Die Hard", hall);

  reserve_seat(session, 0, 0);
  reserve_seat(session, 1, 1);

  auto avail_seats = get_available_seats(hall);
  auto expected_seats = (rows * seats_per_row) - 2; 
  EXPECT_EQ(expected_seats, avail_seats);
}

TEST(Hw06Tests, Test12) 
{
  auto rows = 3, seats_per_row = 3;
  Hall hall = create_hall(1, rows, seats_per_row);
  Session session = create_session(1, "Die Hard", hall);

  auto cancel_stat_neg = cancel_reservation(session, -1, -1);
  EXPECT_FALSE(cancel_stat_neg);

  auto cancel_stat_out_of_bounds = cancel_reservation(session, rows + 1, seats_per_row + 1);
  EXPECT_FALSE(cancel_stat_out_of_bounds);
}
int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
     std::cout << "Запуск тестов..." << std::endl;
    return RUN_ALL_TESTS();
}
