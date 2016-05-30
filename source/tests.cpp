#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include <cmath>
#include "list.hpp"


TEST_CASE (" empty test ", "[heute teste ich ob meine empty wirklich geht]")
{
	List<int> list1;
	REQUIRE(list1.empty()==true);
}

TEST_CASE (" size test ", "[heute teste ich ob meine size wirklich geht]")
{
	List<int> list2;
	REQUIRE(list2.size()==0);
}

TEST_CASE (" add an ele with push_front test ", "[heute teste ich ob meine pusch_front wirklich geht]")
{
	List<int> list3;
	list3.push_front(42);
	REQUIRE(42== list3.front());
}

int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}