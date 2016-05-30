#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include "vec2.hpp"
#include "mat2.hpp"
#include <cmath>
#include "circle.hpp"
#include "rectangle.hpp"


TEST_CASE (" vec2 ", "[kauderwelsch]")
{
	Vec2 v1;
	REQUIRE(v1.x == 0.0f);
	REQUIRE(v1.y == 0.0f);
	Vec2 v2{1.08f, 32.083f};
	REQUIRE(v2.x == 1.08f);
	REQUIRE(v2.y == 32.083f);
}

TEST_CASE (" vec2operator+=", "[kauderwelsch]")
{
	Vec2 v1{1.04f, 2.028f};
	Vec2 v2{1.08f, 32.083f};
	Vec2 v3{-1.0f,0.00f};
	v1+=v2;
	v2+=v3;
	REQUIRE(v2.x== Approx(0.08f));
	REQUIRE (v1.x == Approx(2.12f));
	REQUIRE (v1.y == Approx(34.111f));
}
TEST_CASE (" vec2operator-=", "[kauderwelsch]")
{
	Vec2 v1{1.04f, 2.028f};
	Vec2 v2{1.08f, 32.083f};
	v1-=v2;
	REQUIRE (v1.x == Approx(-0.04f));
	REQUIRE (v1.y == Approx(-30.055f));
}
TEST_CASE (" vec2operator*=", "[kauderwelsch]")
{
	Vec2 v1{1.04f, 2.028f};
	float v = 2.0f;
	v1*=v;
	REQUIRE (v1.x == Approx(2.08f));
	REQUIRE (v1.y == Approx(4.056f));
}
TEST_CASE (" vec2operator/=", "[kauderwelsch]")
{
	Vec2 v1{1.04f, 2.028f};
	float v = 2.0f;
	v1/=v;
	REQUIRE (v1.x == Approx(0.52f));
	REQUIRE (v1.y == Approx(1.014f));
}
TEST_CASE (" vec2operator+", "[kauderwelsch]")
{
	Vec2 v{3.00, 2.00};
	Vec2 u{4.00, 3.00};
	Vec2 w=v+u;
	REQUIRE (w.x == 7.00);
	REQUIRE (w.y == 5.00);
}
TEST_CASE (" vec2operator-", "[kauderwelsch]")
{
	Vec2 v{3.00, 2.00};
	Vec2 u{4.00, 3.00};
	Vec2 w=v-u;
	REQUIRE (w.x == -1.00);
	REQUIRE (w.y == -1.00);
}
TEST_CASE (" vec2operator*", "[kauderwelsch]")
{
	Vec2 v{3.00, 2.00};
	float s=3.0;
	Vec2 w=v*s;
	REQUIRE (w.x == 9.00);
	REQUIRE (w.y == 6.00);
}
TEST_CASE (" vec2operator/", "[kauderwelsch]")
{
	Vec2 v{3.00, 2.00};
	float s=2.0;
	Vec2 w=v/s;
	REQUIRE (w.x == Approx(1.50));
	REQUIRE (w.y == Approx(1.00));
}
TEST_CASE (" vec2operator**", "[kauderwelsch]")
{
	Vec2 v{3.00, 2.00};
	float s=2.0;
	Vec2 w=s*v;
	REQUIRE (w.x == Approx(6.00));
	REQUIRE (w.y == Approx(4.00));
}
TEST_CASE (" mat2 ", "[kauderwelsch]")
{
	mat2 m1;
	REQUIRE(m1.a_ == 1.0f);
	REQUIRE(m1.b_ == 0.0f);
	REQUIRE(m1.c_ == 0.0f);
	REQUIRE(m1.d_ == 1.0f);
	mat2 m2{1.0f,2.0f,3.0f,4.0f};
	REQUIRE(m2.a_ == 1.0f);
	REQUIRE(m2.b_ == 2.0f);
	REQUIRE(m2.c_ == 3.0f);
	REQUIRE(m2.d_ == 4.0f);
}
TEST_CASE (" mat2*= ", "[kauderwelsch]")
{
	mat2 m3{1.0f,2.0f,3.0f,4.0f};
	mat2 m4{2.0f,3.0f,3.0f,2.0f};
	m3*=m4;
	REQUIRE(m3.a_ == 8.0f);
	REQUIRE(m3.b_ == 7.0f);
	REQUIRE(m3.c_ == 18.0f);
	REQUIRE(m3.d_ == 17.0f);
}
TEST_CASE (" mat2nur* ", "[kauderwelsch]")
{
	mat2 m5{1.0f,2.0f,3.0f,4.0f};
	mat2 m6{2.0f,3.0f,3.0f,2.0f};
	mat2 m0=m5*m6;
	REQUIRE(m0.a_ == 8.0f);
	REQUIRE(m0.b_ == 7.0f);
	REQUIRE(m0.c_ == 18.0f);
	REQUIRE(m0.d_ == 17.0f);
}
TEST_CASE (" DETlef ", "[kauderwelsch]")
{
	mat2 m7{1.0f,2.0f,3.0f,4.0f};
	REQUIRE(m7.det() == -2.0f);
}
TEST_CASE (" mat*vec ", "[kauderwelsch]")
{
	mat2 ma{1.0f,2.0f,3.0f,4.0f};
	Vec2 va{2.0f,2.0f};
	Vec2 erg=ma*va;
	REQUIRE(erg.x == 6.0f);
	REQUIRE(erg.y == 14.0f);
}
TEST_CASE (" vec*mat ", "[kauderwelsch]")
{
	mat2 ma{1.0f,2.0f,3.0f,4.0f};
	Vec2 va{2.0f,2.0f};
	Vec2 erg=va*ma;
	REQUIRE(erg.x == 6.0f);
	REQUIRE(erg.y == 14.0f);
}
TEST_CASE (" inverse ", "[kauderwelsch]")
{
	mat2 ma{1.0f,2.0f,3.0f,4.0f};
	//mat2 inv{-2.0f,1.0f,1.5f,-0.5f};
	mat2 inv= inverse(ma);
	REQUIRE(inv.a_ == -2.0f);
	REQUIRE(inv.b_ ==1.0f);
	REQUIRE(inv.c_ ==1.5f);
	REQUIRE(inv.d_ == -0.5f);
}
TEST_CASE (" transpo ", "[kauderwelsch]")
{
	mat2 ma{1.0f,2.0f,3.0f,4.0f};
	//mat2 inv{-2.0f,1.0f,1.5f,-0.5f};
	mat2 trans= transpose(ma);
	REQUIRE(trans.a_ ==1.0f);
	REQUIRE(trans.b_ ==3.0f);
	REQUIRE(trans.c_ ==2.0f);
	REQUIRE(trans.d_ ==4.0f);
}
TEST_CASE (" phi ", "[kauderwelsch]")
{
	float phi = 1.0f;
	//float phineg= -2.0f;
	//mat2 mrm2neg=make_rotation_mat2(phineg);
	mat2 mrm2=make_rotation_mat2(phi);
	REQUIRE(mrm2.a_ ==Approx(0.540302f));
	REQUIRE(mrm2.b_ ==Approx(-0.841471f));
	REQUIRE(mrm2.c_ ==Approx(0.841471f));
	REQUIRE(mrm2.d_ ==Approx(0.540302f));

	/*REQUIRE(mrm2neg.a_ ==Approx(0.999390827f));
	REQUIRE(mrm2neg.b_ ==Approx(0.0348994967f));
	REQUIRE(mrm2neg.c_ ==Approx(-0.0348994967f));
	REQUIRE(mrm2neg.d_ ==Approx(0.999390827f));*/
}
TEST_CASE (" kreis ", "[kauderwelsch]")
{
	Circle c{};
	REQUIRE(c.area() ==Approx(31415.926535897));
	REQUIRE(c.circumrefence()==Approx(628.318530718));
	c.set_radius(2);
	REQUIRE(c.get_radius()==Approx(2));
	REQUIRE(c.area()==Approx(12.5663706144));
	Vec2 x{100,100};
	REQUIRE(c.isinside(x)==true);
	Vec2 x1{100,100};
	Circle c1{100,x1};
	REQUIRE(c1.area() ==Approx(31415.926535897));
	REQUIRE(c1.circumrefence()==Approx(628.318530718));
	c1.set_radius(2);
	REQUIRE(c1.get_radius()==Approx(2));
	REQUIRE(c1.area()==Approx(12.5663706144));
	REQUIRE(c1.isinside(x1)==true);
	

}
/*TEST_CASE (" rechteck ", "[kauderwelsch]")
{
	Rectangle r1{};
	REQUIRE(r1.area() ==Approx(2500));
	REQUIRE(r1.circumrefence()==Approx(200));
	REQUIRE(r1.get_a()==50);
	REQUIRE(r1.get_b()==50);
	Vec2 x1{50,50};
	REQUIRE(r1.isinside(x1)==true);

}*/
	
int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}