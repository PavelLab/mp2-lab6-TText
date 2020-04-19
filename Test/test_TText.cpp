#include "gtest.h"

#include "../mp2-lab6-test/TText.h"

TTextMem TTextLink::MemHeader;
TText txt;

TEST(TStack, can_read_text)
{
	TTextLink::IntMemSystem(100);
	ASSERT_NO_THROW(txt.Read("1.txt"));
}

TEST(TStack, can_write_text)
{
	ASSERT_NO_THROW(txt.Write("2.txt"));
}

TEST(TStack, can_change_line)
{
	txt.Reset(); txt.SetLine("1");
	EXPECT_EQ(txt.GetLine(), "1");
}

TEST(TStack, can_add_DownLine)
{	
	txt.Reset(); txt.InsDownLine("2");
	txt.GoDownLink();
	EXPECT_EQ(txt.GetLine(), "2");
}

TEST(TStack, can_push_an_element_and_clear_memory)
{
	txt.Reset(); txt.GoDownLink(); txt.GoNextLink(); txt.SetLine("3");
	txt.Reset(); txt.DelDown(); TTextLink::MemCleaner(txt); txt.Reset(); txt.GoDownLink();
	EXPECT_EQ(txt.GetLine(), "3");
}
