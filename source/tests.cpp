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

TEST_CASE (" add an ele with push_back test ", "[heute teste ich ob meine pusch_back wirklich geht]")
{
	List<int> list3;
	list3.push_back(42);
	REQUIRE(42== list3.back());
}

TEST_CASE (" popping frontal", "[heute teste ich ob meine pop_front wirklich geht]")
{
	List<int> list3;
	list3.push_front(3);
	list3.push_front(2);
	list3.push_front(1);
	list3.push_back(4);
	list3.pop_front();
	REQUIRE(2== list3.front());
	REQUIRE(list3.size()==3);
	REQUIRE(list3.back()==4);
}
TEST_CASE (" popping von hinten", "[heute teste ich ob meine pop_back wirklich geht]")
{
	List<int> list3;
	list3.push_front(3);
	list3.push_front(2);
	list3.push_front(1);
	list3.push_back(4);
	list3.pop_back();
	REQUIRE(1== list3.front());
	REQUIRE(list3.size()==3);
	REQUIRE(list3.back()==3);
}

TEST_CASE (" should be empty after clearing ", "[ modifiers ]")
{
	List<int> list;
	list.push_front(1);
	list.push_front(2);
	list.push_front(3);
	list.push_front(4);
	list.clear();
	REQUIRE(list.empty()==true);
}
TEST_CASE (" should be an empty range after default construction ",
"[ iterators ]")
{
List <int> list;
auto b = list.begin();
auto e = list.end();
REQUIRE (b==e);
}
TEST_CASE (" provide acces to the first element with begin ", "[ iterators ]")
{
List<int> list ;
list.push_front(42);
REQUIRE(42==*list.begin());
}

TEST_CASE (" listenvergleicher ", "[ blabla ]")
{
List<int> list1,list2;
list1.push_front(1);
list2.push_front(1);
//list1==list2;
REQUIRE(list1==list2);
}

TEST_CASE (" copy constructor ", "[ constructor ]")
{
List<int> list;
list.push_front(1);
list.push_front(2);
list.push_front(3);
list.push_front(4);
List<int> list2{list};
REQUIRE(list==list2);
}

TEST_CASE (" reverse ", "[ constructor ]")
{
List<int> list;
list.push_front(1);
list.push_front(2);
list.push_front(3);
list.reverse();
List<int> list2;
list2.push_front(3);
list2.push_front(2);
list2.push_front(1);
REQUIRE(list==list2);
}


int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}