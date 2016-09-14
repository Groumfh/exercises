#include <gtest/gtest.h>
#include <array>


class Board
{
public:
	enum Corner{
		CornerTR,
		CornerTL,
		CornerBR,
		CornerBL,
	};

	typedef int Value;

	Board(Corner corner, Value value);
	void left();
	void right();
	void top();
	void bottom();
	Value getCorner(Corner corner);

private:
	std::array<std::array<Value, 5>, 5> board_;
};

Board::Board(Corner corner, Value value) {

}

void Board::left()
{
}
void Board::right()
{
}
void Board::top()
{
}
void Board::bottom()
{
}

Board::Value Board::getCorner(Corner corner)
{
	return 0;
}

TEST(ex10, init)
{
	{
		Board b(Board::CornerTR, 5);
		EXPECT_EQ(5, b.getCorner(Board::CornerTR));
		EXPECT_EQ(0, b.getCorner(Board::CornerTL));
		EXPECT_EQ(0, b.getCorner(Board::CornerBR));
		EXPECT_EQ(0, b.getCorner(Board::CornerBL));
	}
	{
		Board b(Board::CornerTL, 5);
		EXPECT_EQ(0, b.getCorner(Board::CornerTR));
		EXPECT_EQ(5, b.getCorner(Board::CornerTL));
		EXPECT_EQ(0, b.getCorner(Board::CornerBR));
		EXPECT_EQ(0, b.getCorner(Board::CornerBL));
	}
	{
		Board b(Board::CornerBR, 5);
		EXPECT_EQ(0, b.getCorner(Board::CornerTR));
		EXPECT_EQ(0, b.getCorner(Board::CornerTL));
		EXPECT_EQ(5, b.getCorner(Board::CornerBR));
		EXPECT_EQ(0, b.getCorner(Board::CornerBL));
	}
	{
		Board b(Board::CornerBL, 5);
		EXPECT_EQ(0, b.getCorner(Board::CornerTR));
		EXPECT_EQ(0, b.getCorner(Board::CornerTL));
		EXPECT_EQ(0, b.getCorner(Board::CornerBR));
		EXPECT_EQ(5, b.getCorner(Board::CornerBL));
	}
}

TEST(ex10, left)
{
	Board b(Board::CornerTR, 5);
	EXPECT_EQ(5, b.getCorner(Board::CornerTR));
	EXPECT_EQ(0, b.getCorner(Board::CornerTL));
	EXPECT_EQ(0, b.getCorner(Board::CornerBR));
	EXPECT_EQ(0, b.getCorner(Board::CornerBL));
	b.left();
	EXPECT_EQ(1, b.getCorner(Board::CornerTR));
	EXPECT_EQ(4, b.getCorner(Board::CornerTL));
	EXPECT_EQ(0, b.getCorner(Board::CornerBR));
	EXPECT_EQ(0, b.getCorner(Board::CornerBL));
}

TEST(ex10, left_force)
{
	Board b(Board::CornerTR, 5);
	b.left();
	EXPECT_EQ(1, b.getCorner(Board::CornerTR));
	EXPECT_EQ(4, b.getCorner(Board::CornerTL));
	EXPECT_EQ(0, b.getCorner(Board::CornerBR));
	EXPECT_EQ(0, b.getCorner(Board::CornerBL));
	b.left();
	EXPECT_EQ(0, b.getCorner(Board::CornerTR));
	EXPECT_EQ(5, b.getCorner(Board::CornerTL));
	EXPECT_EQ(0, b.getCorner(Board::CornerBR));
	EXPECT_EQ(0, b.getCorner(Board::CornerBL));
}

TEST(ex10, right_mix)
{
	Board b(Board::CornerTR, 5);
	b.left();
	EXPECT_EQ(1, b.getCorner(Board::CornerTR));
	EXPECT_EQ(4, b.getCorner(Board::CornerTL));
	EXPECT_EQ(0, b.getCorner(Board::CornerBR));
	EXPECT_EQ(0, b.getCorner(Board::CornerBL));
	b.right();
	EXPECT_EQ(4, b.getCorner(Board::CornerTR));
	EXPECT_EQ(1, b.getCorner(Board::CornerTL));
	EXPECT_EQ(0, b.getCorner(Board::CornerBR));
	EXPECT_EQ(0, b.getCorner(Board::CornerBL));
}

TEST(ex10, bottom_split)
{
	Board b(Board::CornerTR, 5);
	b.left();
	EXPECT_EQ(1, b.getCorner(Board::CornerTR));
	EXPECT_EQ(4, b.getCorner(Board::CornerTL));
	EXPECT_EQ(0, b.getCorner(Board::CornerBR));
	EXPECT_EQ(0, b.getCorner(Board::CornerBL));
	b.bottom();
	EXPECT_EQ(1, b.getCorner(Board::CornerTR));
	EXPECT_EQ(0, b.getCorner(Board::CornerTL));
	EXPECT_EQ(3, b.getCorner(Board::CornerBR));
	EXPECT_EQ(1, b.getCorner(Board::CornerBL));
}

TEST(ex10, top)
{
	Board b(Board::CornerTR, 5);
	b.left();
	b.bottom();
	EXPECT_EQ(1, b.getCorner(Board::CornerTR));
	EXPECT_EQ(0, b.getCorner(Board::CornerTL));
	EXPECT_EQ(3, b.getCorner(Board::CornerBR));
	EXPECT_EQ(1, b.getCorner(Board::CornerBL));
	b.top();
	EXPECT_EQ(3, b.getCorner(Board::CornerTR));
	EXPECT_EQ(1, b.getCorner(Board::CornerTL));
	EXPECT_EQ(1, b.getCorner(Board::CornerBR));
	EXPECT_EQ(0, b.getCorner(Board::CornerBL));
}

